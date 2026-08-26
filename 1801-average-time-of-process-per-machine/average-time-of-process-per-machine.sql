# Write your MySQL query statement below
select machine_id,round(avg(tt),3) as processing_time
from(select  a.machine_id,a.process_id,a.timestamp-b.timestamp as tt from Activity a join Activity b on a.process_id=b.process_id and a.machine_id=b.machine_id where a.activity_type="end" and b.activity_type="start"
)
 Activity
group by  machine_id;