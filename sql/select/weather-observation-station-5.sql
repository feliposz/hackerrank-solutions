/*
Enter your query here.
Please append a semicolon ";" at the end of the query and enter your query in a single line to avoid error.
*/
select min(city), min(length(city)) from station where length(city) = ( select min(length(city)) from station )
union all
select min(city), max(length(city)) from station where length(city) = ( select max(length(city)) from station );
