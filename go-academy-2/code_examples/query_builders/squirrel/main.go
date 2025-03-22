package main

import "github.com/Masterminds/squirrel"

func buildComplexQuery() (string, []any, error) {
	return squirrel.Select("u.id, u.name, COUNT(u.id) as order_count").
		From("users u").
		LeftJoin("orders o ON u.id = o.user_id").
		Where(squirrel.Eq{"u.active": true}).
		GroupBy("u.id", "u.name").
		Having("COUNT(u.id) > ?", 5).
		OrderBy("order_count DESC").
		Limit(10).
		ToSql()
}
