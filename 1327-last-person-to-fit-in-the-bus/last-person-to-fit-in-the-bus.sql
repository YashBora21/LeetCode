# Write your MySQL query statement below
with cte as
(
    select person_id,person_name,turn, 
    case when sum(weight) over(order by turn) <= 1000  then 1 else 0 end as fit
    from Queue
)
select person_name from cte where fit=1 order by turn desc limit 1;