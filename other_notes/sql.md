---
id: sql
aliases: []
tags: []
---

# Common SQL things

<!--toc:start-->

- [Common SQL things](#common-sql-things)
  - [CRUD](#crud) - [Constains](#constains) - [Selection](#selection)
  <!--toc:end-->

There are two types of databases based on the underlying language: SQL and noSQL

SQL-typed are similar to each other with different syntax and language support. (SQLite, PostgreSQL)

NoSQL-typed databases differ from each other. (MongoDB)

## CRUD

Create → Insert, Read → Select, Update → Update, Delete → Delete

### Constains

We can add different constains to the fields on table creation: `PRIMARY KEY`, `NOT NULL`, `UNIQUE`

Also, to create foreign key relationship, we can add `FOREIGN KEY (primary_key) REFERENCES other_table(primary_key)` to the field.

### Selection

To select data, we can use `WHERE` and combine with different operators:

- Logical comparison: `=`, `!=`, `>`, `<`, `>=`, `<=`
- Logical operators: `AND`, `OR`, `NOT`
- Logical functions: `IN`, `NOT IN`, `BETWEEN`, `NOT BETWEEN`
- Logical conditions: `IS NULL`, `IS NOT NULL`, `IS TRUE`, `IS NOT TRUE`
- Conditions with wildcards: `LIKE`, `NOT LIKE`, `ILIKE`, `NOT ILIKE`

Also, we can add condition on number of rows: `LIMIT`, `OFFSET`, they must be after `ORDER BY`

### Sorting

We can sort data by using `ORDER BY` and `ASC` and `DESC`

### Grouping

We can group data by using `GROUP BY` and `HAVING` after

```sql
SELECT user_id, COUNT(*) AS count
FROM users
GROUP BY user_id
HAVING COUNT(*) > 1
LIMIT 10;
```

### Integrated Functions

Also, we can use `COUNT`, `SUM`, `AVG`, `MIN`, `MAX` on raw data to compute some statistics.

```sql
SELECT product_id, SUM(price), AVG(price), MIN(price), MAX(price)
FROM products
GROUP BY product_id;
```

### Subqueries

To select data from another table, we can use subqueries:

```sql
SELECT *
FROM products
WHERE product_id IN (
    SELECT product_id
    FROM orders
    WHERE order_id = 1
);
```

## Joins

We can join tables using `INNER JOIN`, `LEFT JOIN`, `RIGHT JOIN`, `FULL JOIN`.
It is simple just join two tables together.

```sql
SELECT *
FROM users
INNER JOIN orders
ON users.id = orders.user_id;
```

All the `WHERE`, `GROUP BY` or other statements can be used after joining to select appropriate results.

## Normalization

We have several normalization levels:

- 1NF: usually use of `PRIMARY KEY`
- 2NF: you should not have any redundant fields, create separate one if needed
- 3NF: One table per entity, one table per attribute, and one table per relationship
- BCNF: One table per entity, one table per attribute, one table per relationship, and one table per functional dependency

It helps to understand the relationships between tables, reduce the redundancy, and improve the performance.

## Rules of Thumb for Database Design

1. Every table should have a unique primary key.
2. 90% of time, the primary key will be an auto-incrementing integer (`id`).
3. Avoid duplicate data.
4. Avoid storing data completely dependent on other data. Instead, compute it on the fly.
5. Keep schema simple. De-normalize only in case of speed issues.
