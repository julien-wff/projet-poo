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
    city            VARCHAR(63),
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


-- Tables population

INSERT INTO [management].[address_types] (name)
VALUES ('billing'),
       ('delivering'),
       ('staff')
