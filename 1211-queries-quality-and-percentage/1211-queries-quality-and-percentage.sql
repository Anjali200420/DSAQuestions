# Write your MySQL query statement below
SELECT 
    query_name,
    ROUND(AVG(poorQueryPercentageHelper), 2) AS quality,
    ROUND(SUM(qualityHelper) * 100 / COUNT(*), 2) AS poor_query_percentage
FROM (
    SELECT 
        query_name,
        CASE WHEN rating < 3 THEN 1 
        ELSE 0 END AS qualityHelper,
        rating / position AS poorQueryPercentageHelper 
    FROM Queries
) q
GROUP BY query_name;