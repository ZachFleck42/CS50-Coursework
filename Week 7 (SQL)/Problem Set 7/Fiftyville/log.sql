-- 1. Found crime scene report from the specified location and date
SELECT year, description FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND street = "Chamberlin Street";
    -- CLUES: Theft took place at 10:15am at the courthouse


-- 2. Read the transcripts of witness accounts mentioned in the crime scene report
SELECT name, transcript FROM interviews
WHERE month = 7 AND day = 28
AND transcript LIKE "%courthouse%";
    -- CLUES: Thief drove car from courthouse parking lot "within ten minutes of the theft"
    --      : Thief withrdrew money from an ATM on Fifer Street that morning
    --      : Thief called someone (ACCOMPLICE) and talked for less than a minute as they left the courthouse
    --      : Thief told accomplice to purchase tickets for "the earliest flight out of Fiftyville tomorrow"


-- 3. Checked ATM transactions on Fifer Street on day of crime
SELECT people.name FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
WHERE bank_accounts.account_number IN
(
    SELECT account_number FROM atm_transactions
    WHERE month = 7 AND day = 28
    AND atm_location = "Fifer Street"
    AND transaction_type = "withdraw"
)
ORDER BY people.name ASC;
    -- SUSPECTS: Bobby, Danielle, Elizabeth, Ernest, Madison, Roy, Russell, Victoria


-- 4. Checked courthouse security logs for specified time
SELECT people.name FROM people
JOIN courthouse_security_logs ON courthouse_security_logs.license_plate = people.license_plate
WHERE courthouse_security_logs.month = 7 AND courthouse_security_logs.day = 28 AND courthouse_security_logs.hour = 10 AND courthouse_security_logs.minute > 15 AND courthouse_security_logs.minute < 25
ORDER BY people.name ASC;
    -- SUSPECTS: Amber, Danielle, Elizabeth, Ernest, Evelyn, Patrick, Roger, Russell


-- 5. Checked phone call records for specified time and duration
SELECT people.name FROM people
WHERE people.phone_number IN
(
    SELECT caller FROM phone_calls
    WHERE month = 7 AND day = 28
    AND duration < 60
)
ORDER BY people.name ASC;
    -- CALLERS:   Evelyn, Bobby, Roger, Victoria, Madison, Russell,    Evelyn, Ernest,   Kimberly
    -- RECEIVERS: James,  Larry, Anna,  Jack,     Melissa, Jacqueline, Philip, Berthold, Doris


-- 6. Checked for which flight suspect might have taken
SELECT airports.full_name, airports.city FROM airports
JOIN flights ON flights.destination_airport_id = airports.id
WHERE flights.month = 7 AND flights.day = 29
ORDER BY flights.hour ASC LIMIT 1;
    -- CLUES: Thief escaped to London


-- 7. Get passenger manifest for the flight to London
SELECT people.name FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
JOIN flights ON flights.id = passengers.flight_id
WHERE flights.id IN
(
    SELECT flights.id FROM flights
    WHERE flights.month = 7 AND flights.day = 29
    ORDER BY flights.hour ASC LIMIT 1
)
ORDER BY people.name ASC;
    -- SUSPECTS: Bobby, Danielle, Doris, Edward, Ernest, Evelyn, Madison, Roger


-- 8. Put the pieces together and deduce who the criminal must be
SELECT people.name FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN courthouse_security_logs ON courthouse_security_logs.license_plate = people.license_plate
JOIN passengers ON passengers.passport_number = people.passport_number
JOIN flights ON flights.id = passengers.flight_id
WHERE courthouse_security_logs.month = 7 AND courthouse_security_logs.day = 28 AND courthouse_security_logs.hour = 10 AND courthouse_security_logs.minute > 15 AND courthouse_security_logs.minute < 25
AND bank_accounts.account_number IN
(
    SELECT account_number FROM atm_transactions
    WHERE month = 7 AND day = 28
    AND atm_location = "Fifer Street"
    AND transaction_type = "withdraw"
)
AND people.phone_number IN
(
    SELECT caller FROM phone_calls
    WHERE month = 7 AND day = 28
    AND duration < 60
)
AND flights.id IN
(
    SELECT flights.id FROM flights
    WHERE flights.month = 7 AND flights.day = 29
    ORDER BY flights.hour ASC LIMIT 1
);