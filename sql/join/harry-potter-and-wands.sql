/*
Hermione decides the best way to choose is by determining the minimum number of gold galleons needed to buy each non-evil wand of high power and age. Write a query to print the id, age, coins_needed, and power of the wands that Ron's interested in, sorted in order of descending power. If more than one wand has same power, sort the result in order of descending age.
*/

select id, age, coins_needed, power
from wands
join wands_property using (code)
join
(
    select age, power, min(coins_needed) as coins_needed
    from wands 
    join wands_property using (code)
    where is_evil = 0
    group by age, power
) x
using (age, power, coins_needed)
order by power desc, age desc, coins_needed;

