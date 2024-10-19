SELECT DISTINCT name FROM people WHERE id IN
(SELECT person_id FROM directors
JOIN ratings on directors.movie_id = ratings.movie_id
WHERE rating >= 9.0);
