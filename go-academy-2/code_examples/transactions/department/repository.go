package department

import (
	"context"
	"fmt"

	"github.com/example/transactions/txs"
	"github.com/jackc/pgx/v5/pgxpool"
)

type Repository struct {
	db *pgxpool.Pool
}

func NewRepository(pool *pgxpool.Pool) *Repository {
	return &Repository{
		db: pool,
	}
}

func (r *Repository) AddUser(ctx context.Context, userID int64, userName string) error {
	querier := txs.GetQuerier(ctx, r.db)

	_, err := querier.Exec(ctx, "INSERT INTO departments (id, name) VALUES ($1, $2)", userID, userName)
	if err != nil {
		return fmt.Errorf("departments add user: %w", err)
	}

	return nil
}
