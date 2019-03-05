with s as (
    select submission_date, count(distinct hacker_id) as unique_hackers
    from (
        select submission_date, hacker_id
        from submissions
        start with submission_date = '2016-03-01'
        connect by hacker_id = prior hacker_id 
        and submission_date = prior submission_date + 1
    )
    group by submission_date
    order by 1
),
c as (
    select hacker_id, submission_date, count(1) as quantity
    from submissions
    group by hacker_id, submission_date    
),
m as (
    select submission_date, quantity, min(hacker_id) hacker_id
    from c 
    where (submission_date, quantity) in (
        select submission_date, max(quantity)
        from c
        group by submission_date             
    )
    group by submission_date, quantity
)
select submission_date, unique_hackers, hacker_id, name
from s
join m using (submission_date)
join hackers using (hacker_id)
order by submission_date;
