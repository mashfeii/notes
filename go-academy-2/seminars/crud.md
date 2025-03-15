---
id: crud
aliases: []
tags: []
---

# CRUD

Basic operations such as: Create, Read, Update, Delete.

Here is how CRUD is implemented in classic RESTful APIs:

- **Create**:
  - `POST /uesrs` - create a new user
- **Read**:
  - `GET /users/1` - read user with ID 1
  - `GET /users` - read all users
- **Update**:
  - `PUT /users/1` - update user with ID 1
  - `PATCH /users/1` - partially update user with ID 1
- **Delete**:
  - `DELETE /users/1` - delete user with ID 1

## CRUD in Databases

- **Create (`INSERT`)**:
  - Adding new rows to a table.
  - Using of `RETURNING` to get new row's ID.
  - Auto-incrementing fields or UUID as identifiers.
- **Read (`SELECT`)**:
  - Simple and complex queries.
  - Using indexes (`PRIMARY KEY`, `UNIQUE`, `INDEX`) to speed up queries.
  - Filterring (`WHERE`, `ORDER BY`, `LIMIT`, `OFFSET`).
- **Update (`UPDATE`)**:
  - Updating rows with `SET`.
  - Using of `RETURNING` to get updated rows.
  - `UPDATE` impact on performance (immutable columns, indexes updating).
- **Delete (`DELETE`)**:
  - Physical delete (`DELETE`) and logical delete (`is_deleted=true`).
  - Cascading delete (`DELETE ON CASCADE`: deleting related rows).

## CRUD Optimization

- Indexes and their impact
  - Indexes speed up `SELECT` queries but slow down `INSERT`, `UPDATE`, `DELETE`.
  - __Indexes types__: `B-tree`, `Hash`, `GIN`, `GiST`, `SP-GiST`, `BRIN`.
- Pagination in CRUD
  - `OFFSET`/`LIMIT` (simple, but slow for large amount of data).
  - __Keyset pagination__ (on `id` or `created_at`).
  - __Window functions__ (`ROW_NUMBER`, `RANK`, `DENSE_RANK`).
- Caching in CRUD
  - __Redis/Memcached__ for storing frequently accessed data.
  - When to use caching: only on `READ` or `WRITE` as well?
- Sharding and replication in large CRUD systems
  - __Sharding__: horizontal partitioning of data (by users).
  - __Replication__: creating multiple copies of data (`read-replic` for `SELECT` separation).
