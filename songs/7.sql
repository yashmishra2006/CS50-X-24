SELECT AVG(energy) FROM songs WHERE artist_id is
(SELECT id FROM artists WHERE name = 'Drake');
