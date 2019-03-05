select 
    o.contest_id, 
    o.hacker_id, 
    o.name, 
    sum(s.total_submissions),
    sum(s.total_accepted_submissions),
    sum(v.total_views),
    sum(v.total_unique_views)
from contests o
join colleges l on o.contest_id = l.contest_id
join challenges c on l.college_id = c.college_id
left join ( select 
                challenge_id, 
                sum(total_submissions) as total_submissions, 
                sum(total_accepted_submissions) as total_accepted_submissions
            from submission_stats 
            group by challenge_id ) s 
on s.challenge_id = c.challenge_id
left join ( select 
                challenge_id,
                sum(total_views) as total_views,
                sum(total_unique_views) as total_unique_views 
            from view_stats 
            group by challenge_id ) v
on v.challenge_id = c.challenge_id
group by o.contest_id, o.hacker_id, o.name
having sum(s.total_submissions) <> 0 
or sum(s.total_accepted_submissions) <> 0
or sum(v.total_views) <> 0
or sum(v.total_unique_views) <> 0
order by o.contest_id;

