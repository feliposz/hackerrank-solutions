/*
Enter your query here.
Please append a semicolon ";" at the end of the query and enter your query in a single line to avoid error.
*/
select x || ' ' || y 
from 
    ( select round(max(salary*months)) x from employee ), 
    ( select count(*) y from employee where salary*months = (select max(salary*months) from employee));
