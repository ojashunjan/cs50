SELECT COUNT(movie_id) FROM ratings
WHERE movie_id = id.movies
AND rating = 10.0;
