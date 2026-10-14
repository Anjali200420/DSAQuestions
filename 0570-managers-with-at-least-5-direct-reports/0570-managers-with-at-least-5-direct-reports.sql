# Write your MySQL query statement below
SELECT 
    e1.name
FROM Employee e1
WHERE id IN(
    SELECT managerId FROM Employee e2 GROUP BY managerId HAVING COUNT(*) >= 5
)