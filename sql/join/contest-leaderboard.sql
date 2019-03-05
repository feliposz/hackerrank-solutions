/*
Enter your query here.
Please append a semicolon ";" at the end of the query and enter your query in a single line to avoid error.
*/
select hacker_id, name, sum(score) score
from (
    select hacker_id, name, challenge_id, max(score) score
    from hackers
    join submissions using (hacker_id)
    group by hacker_id, name, challenge_id
)
group by hacker_id, name
having sum(score) > 0
order by score desc, hacker_id;
