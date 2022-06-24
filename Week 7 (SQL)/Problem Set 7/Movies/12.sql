SELECT movies.title FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN people on people.id = stars.person_id
WHERE people.name = "Johnny Depp" AND movies.title IN
(
SELECT movies.title FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN people on people.id = stars.person_id
WHERE people.name = "Helena Bonham Carter");