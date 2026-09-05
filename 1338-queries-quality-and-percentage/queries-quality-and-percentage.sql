# Write your MySQL query statement below
select query_name,round(sum(rating/position)/count(*),2) as quality,
    ROUND(SUM(IF(rating < 3, 1, 0)) * 100.0 / COUNT(*),2) as poor_query_percentage
from
Queries
where query_name is not null
group by query_name;
; 