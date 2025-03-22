package main

import (
	"context"
	"errors"
	"fmt"
	"log"
	"sync"
	"time"

	"github.com/jackc/pgx/v5"
)

func main() {
	dsn := "postgres://postgres:password@localhost:5432/postgres?sslmode=disable"

	connConfig, err := pgx.ParseConfig(dsn)
	if err != nil {
		log.Fatalf("Unable to parse config: %v\n", err)
	}

	ctx := context.Background()

	conn, err := pgx.ConnectConfig(ctx, connConfig)
	if err != nil {
		log.Fatalf("Unable to connect to database: %v\n", err)
	}

	defer func() { _ = conn.Close(ctx) }()

	if err := conn.Ping(ctx); err != nil {
		log.Fatalf("Unable to ping database: %v\n", err)
	}

	if err := scanRow(ctx, 3, conn); err != nil {
		log.Fatalf("Unable to scan row: %v\n", err)
	}

	scanParallel(ctx, conn)
}

func scanRow(ctx context.Context, id int, conn *pgx.Conn) (err error) {
	tx, err := conn.Begin(ctx)
	if err != nil {
		return fmt.Errorf("Unable to begin transaction: %w", err)
	}

	defer func() {
		if p := recover(); p != nil || err != nil {
			err = errors.Join(err, tx.Rollback(ctx))
		}
	}()

	row := conn.QueryRow(ctx, "SELECT status, created_at FROM users WHERE id = $1", id)

	var (
		status    string
		createdAt time.Time
	)

	if err := row.Scan(&status, &createdAt); err != nil {
		return fmt.Errorf("Unable to scan row: %w", err)
	}

	log.Println(id, status, createdAt)

	return tx.Commit(ctx)
}

func scanParallel(ctx context.Context, conn *pgx.Conn) {
	wg := sync.WaitGroup{}
	wg.Add(3)

	for i := 3; i < 6; i++ {
		go func(id int) {
			defer wg.Done()

			if err := scanRow(ctx, id, conn); err != nil {
				log.Fatalf("Unable to scan row: %v\n", err)
			}
		}(i)
	}

	wg.Wait()
}
