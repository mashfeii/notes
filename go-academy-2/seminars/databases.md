---
id: databases
aliases: []
tags: []
---

# Work with Databases in Go Applications

## `jackc/pgx` - Popular PostgreSQL Driver

The main entities are 2 interfaces for single connection and pool of connections: `pgx.Conn` and `pgxpool.Pool` respectively.

The ideal approach to work with it is to use `context` and transfer transaction through it.

## Query Builders

The main idea is to delegate the query building to a separate package. This way, you can easily switch between different
databases and create safe, complex queries.

### `Masterminds/squirrel`

Flexible interface using method chaining, contains fewer abstractions and methods, but still very easy to start with

### `doug-martin/goqu`

More complex and powerful, but also more verbose. It has a lot of features and can be used for complex queries.
