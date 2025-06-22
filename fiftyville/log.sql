-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT * FROM crime_scene_reports
WHERE year = 2024 AND month = 7 AND day = 28
AND street = 'Humphrey Street';


SELECT * FROM interviews
WHERE year = 2024 AND month = 7 AND day = 28;

SELECT * FROM flights
JOIN airports ON flights.origin_airport_id = airports.id
WHERE airports.city = 'Fiftyville'
AND year = 2024 AND month = 7 AND day = 28;

SELECT people.name, people.passport_number, people.phone_number, people.license_plate
FROM passengers
JOIN people ON passengers.passport_number = people.passport_number
WHERE flight_id = 6;

SELECT city
FROM airports
WHERE id = [airport_id];
