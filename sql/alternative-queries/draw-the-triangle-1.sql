/*
Enter your query here.
Please append a semicolon ";" at the end of the query and enter your query in a single line to avoid error.
*/
select trim(replace(lpad('*', 20-level+1, '*'), '*', '* ')) from dual connect by level <= 20;
