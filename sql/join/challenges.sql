with r as (
    select hacker_id, name, count(1) challenges_created
    from hackers
    join challenges using (hacker_id)
    group by hacker_id, name
)
select *
from r
where challenges_created not in 
( 
    select challenges_created from r group by challenges_created having count(1) > 1 
    minus
    select max(challenges_created) from r
)
order by challenges_created desc, hacker_id;

