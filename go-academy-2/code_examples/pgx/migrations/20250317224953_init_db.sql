-- +goose Up
-- +goose StatementBegin
begin;

CREATE TABLE IF NOT EXISTS example (
  id BIGINT PRIMARY KEY GENERATED ALWAYS AS IDENTITY,
  status TEXT NOT NULL DEFAULT 'new',
  created_at TIMESTAMPTZ NOT NULL DEFAULT NOW(),
);

INSERT INTO example (status, created_at)
VALUES
    ('disabled', NOW()-'5days'::interval),
    ('handled', NOW()-'4days'::interval),
    ('done', NOW()-'3days'::interval),
    ('deleted', NOW()-'2days'::interval),
    ('completed', NOW()-'1days'::interval),
    ('disabled', NOW());

end;

-- +goose StatementEnd

-- +goose Down
-- +goose StatementBegin
DROP TABLE IF EXISTS example;
-- +goose StatementEnd
