-- write a SQL query to list the titles of all movies in which both Bradley Cooper and Jennifer Lawrence starred

SELECT title
FROM movies
WHERE id IN
(
    SELECT movie_id
    FROM stars
    WHERE person_id =
    (
        SELECT id
        FROM people
        WHERE name = "Bradley Cooper"
    )
    OR person_id =
    (
        SELECT id
        FROM people
        WHERE name = "Jennifer Lawrence"
    )
    GROUP BY movie_id
    HAVING count(*) > 1
)




