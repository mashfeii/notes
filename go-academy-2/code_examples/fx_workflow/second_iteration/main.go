package main

import (
	"net/http"

	"go.uber.org/fx"
	"go.uber.org/fx/fxevent"
	"go.uber.org/zap"
)

func main() {
	appOptions := fx.Options(
		fx.Provide(NewConfig),
		fx.Provide(NewLogger),
		fx.Provide(NewEchoHandler),
		fx.Provide(NewMux),
		fx.Provide(NewServer),
		fx.Invoke(func(*http.Server) {}),
		fx.WithLogger(func(log *zap.Logger) fxevent.Logger {
			return &fxevent.ZapLogger{Logger: log}
		}),
	)

	fx.New(appOptions).Run()
}
