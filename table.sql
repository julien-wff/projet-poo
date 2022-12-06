-- Tables creation

CREATE TABLE [management].[persons]
(
    id        INT IDENTITY
        CONSTRAINT persons_pk
            PRIMARY KEY,
    firstname VARCHAR(63),
    lastname  VARCHAR(63),
)
GO

CREATE TABLE [management].[cities]
(
    id      INT IDENTITY
        CONSTRAINT cities_pk
            PRIMARY KEY,
    name    VARCHAR(63),
    zipcode INT,
)

CREATE TABLE [management].[address_types]
(
    id   INT IDENTITY
        CONSTRAINT address_types_pk
            PRIMARY KEY,
    name VARCHAR(63),
)

CREATE TABLE [management].[addresses]
(
    id              INT IDENTITY
        CONSTRAINT addresses_pk
            PRIMARY KEY,
    person_id       INT
        CONSTRAINT addresses_persons_fk
            REFERENCES [management].[persons] (id),
    city_id         INT
        CONSTRAINT addresses_cities_fk
            REFERENCES [management].[cities] (id),
    address_type_id INT
        CONSTRAINT addresses_address_types_fk
            REFERENCES [management].[address_types] (id),
    street          VARCHAR(63),
)

CREATE TABLE [management].[staffs]
(
    id            INT IDENTITY
        CONSTRAINT staffs_pk
            PRIMARY KEY,
    person_id     INT
        CONSTRAINT staffs_persons_fk
            REFERENCES [management].[persons] (id),
    supervisor_id INT
        CONSTRAINT staffs_staffs_fk
            REFERENCES [management].[staffs] (id),
    hire_date     DATE,
)

CREATE TABLE [management].[clients]
(
    id         INT IDENTITY
        CONSTRAINT clients_pk
            PRIMARY KEY,
    person_id  INT
        CONSTRAINT clients_persons_fk
            REFERENCES [management].[persons] (id),
    birth_date DATE,
)

CREATE TABLE [management].[orders]
(
    reference     VARCHAR(16)
        CONSTRAINT orders_pk
            PRIMARY KEY,
    client_id     INT
        CONSTRAINT orders_clients_fk
            REFERENCES [management].[clients] (id),
    delivery_date DATE,
    creation_date DATE,
)

CREATE TABLE [management].[payment_modes]
(
    id   INT IDENTITY
        CONSTRAINT payment_modes_pk
            PRIMARY KEY,
    name VARCHAR(63),
)

CREATE TABLE [management].[payments]
(
    id              INT IDENTITY
        CONSTRAINT payments_pk
            PRIMARY KEY,
    payment_mode_id INT
        CONSTRAINT payments_payment_modes_fk
            REFERENCES [management].[payment_modes] (id),
    order_reference VARCHAR(16)
        CONSTRAINT payments_orders_fk
            REFERENCES [management].[orders] (reference),
    expected_date   DATE,
    payment_date    DATE,
    amount          FLOAT,
)

CREATE TABLE [management].[articles]
(
    reference INT IDENTITY
        CONSTRAINT articles_pk
            PRIMARY KEY,
    name      VARCHAR(63),
    stock     INT,
    max_stock INT,
    vat       FLOAT,
    price     FLOAT,
    buy_price FLOAT,
)

CREATE TABLE [management].[article_variants]
(
    id                      INT IDENTITY
        CONSTRAINT article_variants_pk
            PRIMARY KEY,
    articles_reference      INT
        CONSTRAINT article_variants_articles_fk
            REFERENCES [management].[articles] (reference),
    reduction_value         FLOAT,
    reduction_product_count INT,
    color                   VARCHAR(31),
)

CREATE TABLE [management].[order_items]
(
    article_variant_id INT
        CONSTRAINT order_items_article_variants_fk
            REFERENCES [management].[article_variants] (id),
    order_reference    VARCHAR(16)
        CONSTRAINT order_items_orders_fk
            REFERENCES [management].[orders] (reference),
    price              FLOAT,
    vat                FLOAT,
    reduction_value    FLOAT,
    item_count         INT,
)

-- Tables population

INSERT INTO [management].[address_types] (name)
VALUES ('billing'),
       ('delivering'),
       ('staff')

INSERT INTO [management].[payment_modes] (name)
VALUES ('Carte bancaire'),
       ('Chèque'),
       ('Espèces'),
       ('Virement'),
       ('Paypal')

-- Accounts

CREATE LOGIN Julien WITH PASSWORD = '' GO
CREATE USER Julien FOR LOGIN Julien GO
GRANT SELECT ON SCHEMA ::management TO Julien GO
GRANT INSERT ON SCHEMA ::management TO Julien GO
GRANT UPDATE ON SCHEMA ::management TO Julien GO
GRANT DELETE ON SCHEMA ::management TO Julien GO

CREATE LOGIN Romain WITH PASSWORD = '' GO
CREATE USER Romain FOR LOGIN Romain GO
GRANT SELECT ON SCHEMA ::management TO Romain GO
GRANT INSERT ON SCHEMA ::management TO Romain GO
GRANT UPDATE ON SCHEMA ::management TO Romain GO
GRANT DELETE ON SCHEMA ::management TO Romain GO

CREATE LOGIN Antonin WITH PASSWORD = '' GO
CREATE USER Antonin FOR LOGIN Antonin GO
GRANT SELECT ON SCHEMA ::management TO Antonin GO
GRANT INSERT ON SCHEMA ::management TO Antonin GO
GRANT UPDATE ON SCHEMA ::management TO Antonin GO
GRANT DELETE ON SCHEMA ::management TO Antonin GO
