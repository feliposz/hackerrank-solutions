students = []
for _ in range(int(raw_input())):
    name = raw_input()
    score = float(raw_input())
    students.append([name, score])

grades = map(lambda p: p[1], students)
min1 = min(grades)
min2 = min(filter(lambda x: x != min1, grades))
students = map(lambda p: p[0], filter(lambda p: p[1] == min2, students))
print '\n'.join(sorted(students))

