/*
Given the table schemas below, write a query to print the company_code, founder name, total number of lead managers, total number of senior managers, total number of managers, and total number of employees. Order your output by ascending company_code.
*/

select
    c.company_code,
    c.founder,
    ( select count(distinct lead_manager_code) from lead_manager l where c.company_code = l.company_code),
    ( select count(distinct senior_manager_code) from senior_manager s where c.company_code = s.company_code),
    ( select count(distinct manager_code) from manager m where c.company_code = m.company_code),
    ( select count(distinct employee_code) from employee e where c.company_code = e.company_code)
from company c
order by c.company_code;

