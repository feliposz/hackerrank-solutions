/*
Enter your query here.
Please append a semicolon ";" at the end of the query and enter your query in a single line to avoid error.
*/
select a.n, case when a.p is null then 'Root' when count(b.n) = 0 then 'Leaf' else 'Inner' end from bst a left join bst b on b.p = a.n group by a.n, a.p order by a.n;
