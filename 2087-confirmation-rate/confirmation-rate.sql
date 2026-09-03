# Write your MySQL query statement below
select a.user_id,
ROUND(
        IFNULL(AVG(d.action = 'confirmed'), 0), 
        2
    ) AS confirmation_rate
from Signups a left join
Confirmations d on  a.user_id=d.user_id
group by a.user_id
;