/*
Julia just finished conducting a coding contest, and she needs your help assembling the leaderboard! Write a query to print the respective hacker_id and name of hackers who achieved full scores for more than one challenge. Order your output in descending order by the total number of challenges in which the hacker earned a full score. If more than one hacker received full scores in same number of challenges, then sort them by ascending hacker_id.
*/

select h.hacker_id, h.name
from hackers h
join submissions s on h.hacker_id = s.hacker_id
join challenges c on c.challenge_id = s.challenge_id 
join difficulty d on d.difficulty_level = c.difficulty_level
where s.score = d.score 
group by h.hacker_id, h.name
having count(1) > 1
order by count(1) desc, h.hacker_id;
