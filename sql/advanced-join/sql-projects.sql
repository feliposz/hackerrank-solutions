select min(start_date), max(end_date)
from (
    select 
        start_date,
        end_date,
        sum(grouping) over 
            (ORDER BY start_date ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW) as groupnum
    from (
        select 
            start_date, 
            end_date, 
            case when lag(end_date, 1, null) over (order by start_date) = start_date then 0 else 1 end as grouping
        from projects
        order by start_date
    )
)
group by groupnum
order by max(end_date) - min(start_date), min(start_date);

