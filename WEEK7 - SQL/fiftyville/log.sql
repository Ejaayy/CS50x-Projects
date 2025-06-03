-- Keep a log of any SQL queries you execute as you solve the mystery.

--WHAT I KNOW:
--All you know is that the theft took place on
--July 28, 2023 and that it took place on Humphrey Street.

--CRIMES THAT HAPPENED ON SAID DATE
SELECT *
FROM crime_scene_reports
WHERE year = 2023 AND month = 7 AND day = 28
  AND street = 'Humphrey Street';

--INFO Gathered:
--id   year  month  day  street           description
-----  ----  -----  ---  ---------------  ------------------------------------------------------------
--295  2023  7      28   Humphrey Street  Theft of the CS50 duck took place at 10:15am at the Humphrey
--                                         Street bakery. Interviews were conducted today with three w
--                                        itnesses who were present at the time – each of their interv
--                                        iew transcripts mentions the bakery.
--
--297  2023  7      28   Humphrey Street  Littering took place at 16:36. No known witnesses.

--CHECKING of interviews
SELECT * FROM interviews
WHERE year = 2023 AND month = 7 AND day = 28;

--| 161 | Ruth    | 2023 | 7     | 28  | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
--| 162 | Eugene  | 2023 | 7     | 28  | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
--| 163 | Raymond | 2023 | 7     | 28  | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |

---- Checking Of Cars that left the bakery between 10:15 and 10:25
SELECT * FROM bakery_security_logs
WHERE year = 2023 AND month = 7 AND day = 28
  AND hour = 10 AND minute BETWEEN 15 AND 25
  AND activity = 'exit';
--+-----+------+-------+-----+------+--------+----------+---------------+
--| id  | year | month | day | hour | minute | activity | license_plate |
--+-----+------+-------+-----+------+--------+----------+---------------+
--| 260 | 2023 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
--| 261 | 2023 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
--| 262 | 2023 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
--| 263 | 2023 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
--| 264 | 2023 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
--| 265 | 2023 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
--| 266 | 2023 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
--| 267 | 2023 | 7     | 28  | 10   | 23     | exit     | 0NTHK55       |
--+-----+------+-------+-----+------+--------+----------+---------------+

--Check ATM transactions at Leggett Street
SELECT * FROM atm_transactions
WHERE year = 2023 AND month = 7 AND day = 28
  AND atm_location = 'Leggett Street';

--+-----+----------------+------+-------+-----+----------------+------------------+--------+
-- id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
--+-----+----------------+------+-------+-----+----------------+------------------+--------+
--| 246 | 28500762       | 2023 | 7     | 28  | Leggett Street | withdraw         | 48     |
--| 264 | 28296815       | 2023 | 7     | 28  | Leggett Street | withdraw         | 20     |
--| 266 | 76054385       | 2023 | 7     | 28  | Leggett Street | withdraw         | 60     |
--| 267 | 49610011       | 2023 | 7     | 28  | Leggett Street | withdraw         | 50     |
--| 269 | 16153065       | 2023 | 7     | 28  | Leggett Street | withdraw         | 80     |
--| 275 | 86363979       | 2023 | 7     | 28  | Leggett Street | deposit          | 10     |
--| 288 | 25506511       | 2023 | 7     | 28  | Leggett Street | withdraw         | 20     |
--| 313 | 81061156       | 2023 | 7     | 28  | Leggett Street | withdraw         | 30     |
--| 336 | 26013199       | 2023 | 7     | 28  | Leggett Street | withdraw         | 35     |
--+-----+----------------+------+-------+-----+----------------+------------------+--------+

-- Phone calls on the day under 60 seconds
SELECT * FROM phone_calls
WHERE year = 2023 AND month = 7 AND day = 28
  AND duration < 60;
--+-----+----------------+----------------+------+-------+-----+----------+
--| id  |     caller     |    receiver    | year | month | day | duration |
--+-----+----------------+----------------+------+-------+-----+----------+
--| 221 | (130) 555-0289 | (996) 555-8899 | 2023 | 7     | 28  | 51       |
--| 224 | (499) 555-9472 | (892) 555-8872 | 2023 | 7     | 28  | 36       |
--| 233 | (367) 555-5533 | (375) 555-8161 | 2023 | 7     | 28  | 45       |
--| 251 | (499) 555-9472 | (717) 555-1342 | 2023 | 7     | 28  | 50       |
--| 254 | (286) 555-6063 | (676) 555-6554 | 2023 | 7     | 28  | 43       |
--| 255 | (770) 555-1861 | (725) 555-3243 | 2023 | 7     | 28  | 49       |
--| 261 | (031) 555-6622 | (910) 555-3251 | 2023 | 7     | 28  | 38       |
--| 279 | (826) 555-1652 | (066) 555-9701 | 2023 | 7     | 28  | 55       |
--| 281 | (338) 555-6650 | (704) 555-2131 | 2023 | 7     | 28  | 54       |
--+-----+----------------+----------------+------+-------+-----+----------+

-- Match license plates to people
SELECT name, phone_number, license_plate, passport_number
FROM people
WHERE license_plate IN (
  '5P2BI95','94KL13X','6P58WS2','4328GD8',
  'G412CB7','L93JTIZ','322W7JE','0NTHK55'
);

--+---------+----------------+---------------+-----------------+
--|  name   |  phone_number  | license_plate | passport_number |
-----------+----------------+---------------+-----------------+
--| Vanessa | (725) 555-4692 | 5P2BI95       | 2963008352      |
--| Barry   | (301) 555-4174 | 6P58WS2       | 7526138472      |
--| Iman    | (829) 555-5269 | L93JTIZ       | 7049073643      |
--| Sofia   | (130) 555-0289 | G412CB7       | 1695452385      |
--| Luca    | (389) 555-5198 | 4328GD8       | 8496433585      |
--| Diana   | (770) 555-1861 | 322W7JE       | 3592750733      |
--| Kelsey  | (499) 555-9472 | 0NTHK55       | 8294398571      |
--| Bruce   | (367) 555-5533 | 94KL13X       | 5773159633      |
--+---------+----------------+---------------+-----------------+

--Match ATM account numbers to people
SELECT people.name, people.phone_number, people.license_plate, bank_accounts.account_number
FROM bank_accounts
JOIN people ON bank_accounts.person_id = people.id
WHERE bank_accounts.account_number IN (28500762,28296815,76054385,49610011,16153065,25506511,81061156,26013199);

--+---------+----------------+---------------+----------------+
--|  name   |  phone_number  | license_plate | account_number |
--+---------+----------------+---------------+----------------+
--| Bruce   | (367) 555-5533 | 94KL13X       | 49610011       |
--| Diana   | (770) 555-1861 | 322W7JE       | 26013199       |
--| Brooke  | (122) 555-4581 | QX4YZN3       | 16153065       |
--| Kenny   | (826) 555-1652 | 30G67EN       | 28296815       |
--| Iman    | (829) 555-5269 | L93JTIZ       | 25506511       |
--| Luca    | (389) 555-5198 | 4328GD8       | 28500762       |
--| Taylor  | (286) 555-6063 | 1106N58       | 76054385       |
--| Benista | (338) 555-6650 | 8X428L0       | 81061156       |
--+---------+----------------+---------------+----------------+

sqlite> SELECT p.name, p.phone_number, p.license_plate, ba.account_number
   ...> FROM people p
   ...> JOIN bank_accounts ba ON p.id = ba.person_id
   ...> WHERE p.license_plate IN ('5P2BI95','94KL13X','6P58WS2','4328GD8','G412CB7','L93JTIZ','322W7JE','0NTHK55')
   ...>   AND ba.account_number IN (28500762,28296815,76054385,49610011,16153065,25506511,81061156,26013199)
   ...>   AND p.phone_number IN (
   ...>     '(130) 555-0289', '(499) 555-9472', '(367) 555-5533',
   ...>     '(770) 555-1861' -- caller numbers from phone calls < 60s
   ...>   );

+-------+----------------+---------------+----------------+
| name  |  phone_number  | license_plate | account_number |
+-------+----------------+---------------+----------------+
| Bruce | (367) 555-5533 | 94KL13X       | 49610011       |
| Diana | (770) 555-1861 | 322W7JE       | 26013199       |
+-------+----------------+---------------+----------------+

--ATM transactions for Bruce and Diana

SELECT *
   ...> FROM atm_transactions
   ...> WHERE year = 2023 AND month = 7 AND day = 28
   ...>   AND account_number IN (49610011, 26013199);
+-----+----------------+------+-------+-----+----------------+------------------+--------+
| id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
+-----+----------------+------+-------+-----+----------------+------------------+--------+
| 267 | 49610011       | 2023 | 7     | 28  | Leggett Street | withdraw         | 50     |
| 336 | 26013199       | 2023 | 7     | 28  | Leggett Street | withdraw         | 35     |
+-----+----------------+------+-------+-----+----------------+------------------+--------+



