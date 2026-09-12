# Write your MySQL query statement below
with cte as
(select id,num,lead(num,1) over (order by id) as nextnum,lag(num,1)  over (order by id) as prevnum from Logs)
select distinct  num as ConsecutiveNums from cte where num=nextnum and num=prevnum;