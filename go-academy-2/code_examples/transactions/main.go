package main

import (
	"context"
	"fmt"

	"github.com/example/transactions/department"
	"github.com/example/transactions/txs"
	"github.com/example/transactions/user"
	"github.com/jackc/pgx/v5/pgxpool"
)

type Transactor interface {
	WithTransaction(ctx context.Context, txFunc func(ctx context.Context) error) (err error)
}

type UserRepository interface {
	GetUserName(ctx context.Context, userID int64) (string, error)
}

type DepartmentRepository interface {
	AddUser(ctx context.Context, userID int64, userName string) error
}

type App struct {
	transactor     Transactor
	userRepo       UserRepository
	departmentRepo DepartmentRepository
}

func (app *App) AddUserToDepartment(ctx context.Context, userID int64) error {
	return app.transactor.WithTransaction(
		ctx,
		func(ctxTx context.Context) error {
			name, err := app.userRepo.GetUserName(ctxTx, userID)
			if err != nil {
				return fmt.Errorf("get user (user name): %w", err)
			}

			return app.departmentRepo.AddUser(ctxTx, userID, name)
		},
	)
}

func NewApp(transactor Transactor, userRepo UserRepository, departmentRepo DepartmentRepository) *App {
	return &App{
		transactor:     transactor,
		userRepo:       userRepo,
		departmentRepo: departmentRepo,
	}
}

func main() {
	pool := &pgxpool.Pool{}

	tx := txs.NewTxBeginner(pool)
	userRepo := user.NewRepository(pool)
	departmentRepo := department.NewRepository(pool)

	app := NewApp(tx, userRepo, departmentRepo)

	ctx := context.Background()
	if err := app.AddUserToDepartment(ctx, 1); err != nil {
		fmt.Println(err)
	}
}
