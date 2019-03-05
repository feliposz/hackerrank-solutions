/*
Enter your query here.
Please append a semicolon ";" at the end of the query and enter your query in a single line to avoid error.
*/
select listagg(n, '&') within group (order by n)
from (
    select a.n
    from 
        (select level n from dual connect by level <= 1000) a
        cross join
        (select level n from dual connect by level <= 1000) b
    where mod(a.n, b.n) = 0
      and a.n > 1
      and b.n > 1
      and a.n >= b.n
    group by a.n
    having count(1) = 1
);
