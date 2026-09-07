WITH FirstLogin AS (
    -- Step 1: Find the absolute first login date for each player
    SELECT player_id, MIN(event_date) AS first_date
    FROM Activity
    GROUP BY player_id
)
SELECT 
    ROUND(
        -- Step 3: Divide consecutive first-time players by total unique players
        COUNT(DISTINCT a.player_id) / (SELECT COUNT(DISTINCT player_id) FROM Activity), 
        2
    ) AS fraction
FROM Activity a
JOIN FirstLogin f 
  ON a.player_id = f.player_id 
  -- Step 2: Only match rows where the event_date is exactly 1 day after the first_date
  AND a.event_date = DATE_ADD(f.first_date, INTERVAL 1 DAY);
