select d.name, p.name, s.name, a.name
from
(select level as pos from dual connect by level <= (select max(count(1)) as max_rows from occupations group by occupation)) x,
(select rank() over (order by name) as pos, name from occupations where occupation = 'Doctor' order by name) d,
(select rank() over (order by name) as pos, name from occupations where occupation = 'Professor' order by name) p,
(select rank() over (order by name) as pos, name from occupations where occupation = 'Singer' order by name) s,
(select rank() over (order by name) as pos, name from occupations where occupation = 'Actor' order by name) a
where x.pos = d.pos(+)
  and x.pos = p.pos(+)
  and x.pos = s.pos(+)
  and x.pos = a.pos(+);

