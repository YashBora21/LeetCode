# Write your MySQL query statement below
select a.id
from Weather a
join Weather b on datediff(a.recordDate,b.recordDate)=1
WHERE a.temperature > b.temperature;
