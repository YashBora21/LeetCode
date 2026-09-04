# Write your MySQL query statement below
select b.contest_id,round((count(a.user_id)/(select count(*) from Users))*100,2) as percentage 
from Users a
join Register b 
on a.user_id=b.user_id
group by contest_id
order by percentage desc,contest_id  asc
;