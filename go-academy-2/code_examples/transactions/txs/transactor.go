package txs

import (
	"context"
	"errors"
	"fmt"

	"github.com/jackc/pgx/v5"
	"github.com/jackc/pgx/v5/pgconn"
	"github.com/jackc/pgx/v5/pgxpool"
)

// NOTE: querier copies pgx (database) methods
type Querier interface {
	SendBatch(ctx context.Context, b *pgx.Batch) pgx.BatchResults
	Exec(ctx context.Context, sql string, arguments ...any) (commandTag pgconn.CommandTag, err error)
	Query(ctx context.Context, sql string, arguments ...any) (rows pgx.Rows, err error)
	QueryRow(ctx context.Context, sql string, arguments ...any) pgx.Row
}

type txKey struct{}

func injectTx(ctx context.Context, tx pgx.Tx) context.Context {
	return context.WithValue(ctx, txKey{}, tx)
}

// NOTE: may return querier from transaction or default one (pool or connection)
func GetQuerier(ctx context.Context, defaultQuerier Querier) Querier {
	if tx, ok := ctx.Value(txKey{}).(pgx.Tx); ok {
		return tx
	}

	return defaultQuerier
}

type TxBeginner struct {
	db *pgxpool.Pool
}

func NewTxBeginner(db *pgxpool.Pool) *TxBeginner {
	return &TxBeginner{
		db: db,
	}
}

// NOTE: begin transaction, execute transaction body -> error ? rollback, else commit
func (r *TxBeginner) WithTransaction(ctx context.Context, txFunc func(ctx context.Context) error) (err error) {
	tx, err := r.db.Begin(ctx)
	if err != nil {
		return fmt.Errorf("begin transaction: %w", err)
	}

	defer func() {
		if err != nil {
			err = errors.Join(err, tx.Rollback(ctx))
		}
	}()

	if err := txFunc(injectTx(ctx, tx)); err != nil {
		return nil
	}

	return tx.Commit(ctx)
}
