/*
Enter your query here.
Please append a semicolon ";" at the end of the query and enter your query in a single line to avoid error.
*/
select city from station where regexp_like(city, '^[aeiou].*[aeiou]$', 'i');
