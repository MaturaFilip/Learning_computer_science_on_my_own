SELECT AVG("energy") AS "avg_energy_drake" FROM songs
WHERE artist_id = (
    SELECT id FROM artists
    WHERE name = 'Drake'
);
