-- Keep a log of any SQL queries you execute as you solve the mystery.
-- .schema;
-- CREATE TABLE crime_scene_reports (
--     id INTEGER,
--     year INTEGER,
--     month INTEGER,
--     day INTEGER,
--     street TEXT,
--     description TEXT,
--     PRIMARY KEY(id)
-- );
-- CREATE TABLE interviews (
--     id INTEGER,
--     name TEXT,
--     year INTEGER,
--     month INTEGER,
--     day INTEGER,
--     transcript TEXT,
--     PRIMARY KEY(id)
-- );
-- CREATE TABLE atm_transactions (
--     id INTEGER,
--     account_number INTEGER,
--     year INTEGER,
--     month INTEGER,
--     day INTEGER,
--     atm_location TEXT,
--     transaction_type TEXT,
--     amount INTEGER,
--     PRIMARY KEY(id)
-- );
-- CREATE TABLE bank_accounts (
--     account_number INTEGER,
--     person_id INTEGER,
--     creation_year INTEGER,
--     FOREIGN KEY(person_id) REFERENCES people(id)
-- );
-- CREATE TABLE airports (
--     id INTEGER,
--     abbreviation TEXT,
--     full_name TEXT,
--     city TEXT,
--     PRIMARY KEY(id)
-- );
-- CREATE TABLE flights (
--     id INTEGER,
--     origin_airport_id INTEGER,
--     destination_airport_id INTEGER,
--     year INTEGER,
--     month INTEGER,
--     day INTEGER,
--     hour INTEGER,
--     minute INTEGER,
--     PRIMARY KEY(id),
--     FOREIGN KEY(origin_airport_id) REFERENCES airports(id),
--     FOREIGN KEY(destination_airport_id) REFERENCES airports(id)
-- );
-- CREATE TABLE passengers (
--     flight_id INTEGER,
--     passport_number INTEGER,
--     seat TEXT,
--     FOREIGN KEY(flight_id) REFERENCES flights(id)
-- );
-- CREATE TABLE phone_calls (
--     id INTEGER,
--     caller TEXT,
--     receiver TEXT,
--     year INTEGER,
--     month INTEGER,
--     day INTEGER,
--     duration INTEGER,
--     PRIMARY KEY(id)
-- );
-- CREATE TABLE people (
--     id INTEGER,
--     name TEXT,
--     phone_number TEXT,
--     passport_number INTEGER,
--     license_plate TEXT,
--     PRIMARY KEY(id)
-- );
-- CREATE TABLE bakery_security_logs (
--     id INTEGER,
--     year INTEGER,
--     month INTEGER,
--     day INTEGER,
--     hour INTEGER,
--     minute INTEGER,
--     activity TEXT,
--     license_plate TEXT,
--     PRIMARY KEY(id)
-- );
SELECT
    *
FROM
    crime_scene_reports
WHERE
    YEAR = 2023
    AND MONTH = 7
    AND DAY = 28
    AND description LIKE "%duck%";

-- +-----+------+-------+-----+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
-- | id  | year | month | day |     street      |                                                                                                       description                                                                                                        |
-- +-----+------+-------+-----+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
-- | 295 | 2023 | 7     | 28  | Humphrey Street | Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |
-- +-----+------+-------+-----+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
SELECT
    *
FROM
    interviews
WHERE
    YEAR = 2023
    AND MONTH = 7
    AND DAY = 28
    AND transcript LIKE "%bakery%";

-- +-----+---------+------+-------+-----+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
-- | id  |  name   | year | month | day |                                                                                                                                                     transcript                                                                                                                                                      |
-- +-----+---------+------+-------+-----+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
-- | 161 | Ruth    | 2023 | 7     | 28  | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
-- | 162 | Eugene  | 2023 | 7     | 28  | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
-- | 163 | Raymond | 2023 | 7     | 28  | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |
-- +-----+---------+------+-------+-----+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
SELECT
    license_plate
FROM
    bakery_security_logs
WHERE
    activity = "exit"
    AND YEAR = 2023
    AND MONTH = 7
    AND HOUR = 10
    AND MINUTE BETWEEN 15 AND 25;

-- +---------------+
-- | license_plate |
-- +---------------+
-- | 11J91FW       |
-- | 5P2BI95       |
-- | PF37ZVK       |
-- | 94KL13X       |
-- | 6P58WS2       |
-- | 4328GD8       |
-- | G412CB7       |
-- | 1M92998       |
-- | L93JTIZ       |
-- | XE95071       |
-- | 322W7JE       |
-- | 0NTHK55       |
-- | IH61GO8       |
-- | 8P9NEU9       |
-- +---------------+
SELECT
    account_number
FROM
    atm_transactions
WHERE
    YEAR = 2023
    AND MONTH = 7
    AND DAY = 28
    AND atm_location = "Leggett Street"
    AND transaction_type = "withdraw";

-- +----------------+
-- | account_number |
-- +----------------+
-- | 28500762       |
-- | 28296815       |
-- | 76054385       |
-- | 49610011       |
-- | 16153065       |
-- | 25506511       |
-- | 81061156       |
-- | 26013199       |
-- +----------------+
SELECT
    *
FROM
    people
    JOIN bank_accounts ON bank_accounts.person_id = people.id
WHERE
    account_number IN (
        SELECT
            account_number
        FROM
            atm_transactions
        WHERE
            YEAR = 2023
            AND MONTH = 7
            AND DAY = 28
            AND atm_location = "Leggett Street"
            AND transaction_type = "withdraw"
    )
    AND license_plate IN (
        SELECT
            license_plate
        FROM
            bakery_security_logs
        WHERE
            activity = "exit"
            AND YEAR = 2023
            AND MONTH = 7
            AND HOUR = 10
            AND MINUTE BETWEEN 15 AND 25
    )
    AND phone_number IN (
        SELECT
            caller
        FROM
            phone_calls
        WHERE
            YEAR = 2023
            AND MONTH = 7
            AND DAY = 28
            AND duration < 60
    )
    AND passport_number IN (
        SELECT
            passport_number
        FROM
            passengers
        WHERE
            flight_id IN (
                SELECT
                    id
                FROM
                    flights
                WHERE
                    YEAR = 2023
                    AND MONTH = 7
                    AND DAY = 29
                    AND origin_airport_id IN (
                        SELECT
                            id
                        FROM
                            airports
                        WHERE
                            city = "Fiftyville"
                    )
                ORDER BY
                    HOUR
                LIMIT
                    1
            )
    );

-- +--------+-------+----------------+-----------------+---------------+----------------+-----------+---------------+
-- |   id   | name  |  phone_number  | passport_number | license_plate | account_number | person_id | creation_year |
-- +--------+-------+----------------+-----------------+---------------+----------------+-----------+---------------+
-- | 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X       | 49610011       | 686048    | 2010          |
-- +--------+-------+----------------+-----------------+---------------+----------------+-----------+---------------+
SELECT
    *
FROM
    people
WHERE
    phone_number IN (
        SELECT
            receiver
        FROM
            phone_calls
        WHERE
            YEAR = 2023
            AND MONTH = 7
            AND DAY = 28
            AND duration < 60
            AND caller = (
                SELECT
                    caller
                FROM
                    phone_calls
                WHERE
                    YEAR = 2023
                    AND MONTH = 7
                    AND DAY = 28
                    AND duration < 60
                    AND caller = (
                        SELECT
                            phone_number
                        FROM
                            people
                            JOIN bank_accounts ON bank_accounts.person_id = people.id
                        WHERE
                            account_number IN (
                                SELECT
                                    account_number
                                FROM
                                    atm_transactions
                                WHERE
                                    YEAR = 2023
                                    AND MONTH = 7
                                    AND DAY = 28
                                    AND atm_location = "Leggett Street"
                                    AND transaction_type = "withdraw"
                            )
                            AND license_plate IN (
                                SELECT
                                    license_plate
                                FROM
                                    bakery_security_logs
                                WHERE
                                    activity = "exit"
                                    AND YEAR = 2023
                                    AND MONTH = 7
                                    AND HOUR = 10
                                    AND MINUTE BETWEEN 15 AND 25
                            )
                            AND phone_number IN (
                                SELECT
                                    caller
                                FROM
                                    phone_calls
                                WHERE
                                    YEAR = 2023
                                    AND MONTH = 7
                                    AND DAY = 28
                                    AND duration < 60
                            )
                            AND passport_number IN (
                                SELECT
                                    passport_number
                                FROM
                                    passengers
                                WHERE
                                    flight_id IN (
                                        SELECT
                                            id
                                        FROM
                                            flights
                                        WHERE
                                            YEAR = 2023
                                            AND MONTH = 7
                                            AND DAY = 29
                                            AND origin_airport_id IN (
                                                SELECT
                                                    id
                                                FROM
                                                    airports
                                                WHERE
                                                    city = "Fiftyville"
                                            )
                                        ORDER BY
                                            HOUR
                                        LIMIT
                                            1
                                    )
                            )
                    )
            )
    );

-- +--------+-------+----------------+-----------------+---------------+
-- |   id   | name  |  phone_number  | passport_number | license_plate |
-- +--------+-------+----------------+-----------------+---------------+
-- | 864400 | Robin | (375) 555-8161 | NULL            | 4V16VO0       |
-- +--------+-------+----------------+-----------------+---------------+
SELECT
    city
FROM
    airports
WHERE
    id = (
        SELECT
            destination_airport_id
        FROM
            flights
        WHERE
            id = (
                SELECT
                    flight_id
                FROM
                    passengers
                WHERE
                    passport_number = (
                        SELECT
                            passport_number
                        FROM
                            people
                            JOIN bank_accounts ON bank_accounts.person_id = people.id
                        WHERE
                            account_number IN (
                                SELECT
                                    account_number
                                FROM
                                    atm_transactions
                                WHERE
                                    YEAR = 2023
                                    AND MONTH = 7
                                    AND DAY = 28
                                    AND atm_location = "Leggett Street"
                                    AND transaction_type = "withdraw"
                            )
                            AND license_plate IN (
                                SELECT
                                    license_plate
                                FROM
                                    bakery_security_logs
                                WHERE
                                    activity = "exit"
                                    AND YEAR = 2023
                                    AND MONTH = 7
                                    AND HOUR = 10
                                    AND MINUTE BETWEEN 15 AND 25
                            )
                            AND phone_number IN (
                                SELECT
                                    caller
                                FROM
                                    phone_calls
                                WHERE
                                    YEAR = 2023
                                    AND MONTH = 7
                                    AND DAY = 28
                                    AND duration < 60
                            )
                            AND passport_number IN (
                                SELECT
                                    passport_number
                                FROM
                                    passengers
                                WHERE
                                    flight_id IN (
                                        SELECT
                                            id
                                        FROM
                                            flights
                                        WHERE
                                            YEAR = 2023
                                            AND MONTH = 7
                                            AND DAY = 29
                                            AND origin_airport_id IN (
                                                SELECT
                                                    id
                                                FROM
                                                    airports
                                                WHERE
                                                    city = "Fiftyville"
                                            )
                                        ORDER BY
                                            HOUR
                                        LIMIT
                                            1
                                    )
                            )
                    )
            )
    );

-- +---------------+
-- |     city      |
-- +---------------+
-- | New York City |
-- +---------------+
