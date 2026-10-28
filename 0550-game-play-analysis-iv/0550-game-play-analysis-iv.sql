# Write your MySQL query statement below
WITH first_login AS (
    SELECT 
        player_id,
        MIN(event_date) AS first_date
    FROM activity
    GROUP BY player_id
)
SELECT
    ROUND(COUNT(
        CASE WHEN DATEDIFF(a.event_date, f.first_date) = 1 THEN 1 END
    ) / (SELECT COUNT(DISTINCT f.player_id)), 2) AS fraction
FROM Activity a
LEFT JOIN first_login f
ON a.player_id = f.player_id;