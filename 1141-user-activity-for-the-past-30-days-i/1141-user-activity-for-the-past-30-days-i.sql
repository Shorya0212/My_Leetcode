# Write your MySQL query statement below
select activity_date as day,count(distinct user_id) as active_users from activity 
where DATE_SUB('2019-07-27',interval 30 day)<activity_date and activity_date<='2019-07-27' group by activity_date;