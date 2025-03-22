package user

import (
	"context"
	"fmt"

	"github.com/example/transactions/txs"
	"github.com/jackc/pgx/v5/pgxpool"
)

func NewRepository(pool *pgxpool.Pool) *Repository {
	return &Repository{
		db: pool,
	}
}

// NOTE: Repository contains database pool, since that we can use pool methods
type Repository struct {
	db *pgxpool.Pool
}

func (r *Repository) GetUserName(ctx context.Context, userID int64) (string, error) {
	querier := txs.GetQuerier(ctx, r.db)

	row, err := querier.Query(ctx, "SELECT name FROM users WHERE id = $1", userID)
	if err != nil {
		return "", fmt.Errorf("failed to get user name: %w", err)
	}

	var name string

	if err := row.Scan(&name); err != nil {
		return "", fmt.Errorf("failed to scan user name: %w", err)
	}

	return name, nil
}
