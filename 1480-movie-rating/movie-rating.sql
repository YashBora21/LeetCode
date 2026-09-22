(
    SELECT a.name AS results
    FROM Users a 
    JOIN MovieRating b ON a.user_id = b.user_id
    GROUP BY a.user_id, a.name
    ORDER BY COUNT(b.movie_id) DESC, a.name ASC
    LIMIT 1
)
UNION ALL
(
    SELECT m.title AS results
    FROM Movies m 
    JOIN MovieRating b ON m.movie_id = b.movie_id
    WHERE b.created_at >= '2020-02-01' AND b.created_at < '2020-03-01'
    GROUP BY m.movie_id, m.title
    ORDER BY AVG(b.rating) DESC, m.title ASC
    LIMIT 1
);