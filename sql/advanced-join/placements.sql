/*
Write a query to output the names of those students whose best friends got offered a higher salary than them. Names must be ordered by the salary amount offered to the best friends. It is guaranteed that no two students got same salary offer.
*/

select s1.name
from students s1
join packages p1 on s1.id = p1.id
join friends f on s1.id = f.id
join students s2 on f.friend_id = s2.id
join packages p2 on s2.id = p2.id
where p2.salary > p1.salary
order by p2.salary;


