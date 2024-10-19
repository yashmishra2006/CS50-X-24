SELECT name FROM people WHERE id IN(
    SELECT DISTINCT people.id FROM people
    JOIN stars on people.id = stars.person_id
    JOIN movies on stars.movie_id = movies.id
    WHERE movies.year = '2004' ORDER BY people.birth DESC, name);
