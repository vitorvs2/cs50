SELECT avg(energy) as "avg energy on drake's songs"
FROM songs
WHERE artist_id =
(
    SELECT id
    FROM artists
    WHERE name = "Drake"
);
