/*
Enter your query here.
Please append a semicolon ";" at the end of the query and enter your query in a single line to avoid error.
*/
select distinct a.x, a.y
from functions a
join functions b on a.x = b.y and a.y = b.x
where a.rowid <> b.rowid
  and a.x <= b.x
order by a.x, a.y;
