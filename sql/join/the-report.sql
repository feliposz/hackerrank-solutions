select (case when grade >= 8 then name else null end) name, grade, marks from students join grades on marks between grades.min_mark and grades.max_mark order by grade desc, name, marks;
