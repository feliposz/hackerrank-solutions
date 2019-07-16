# Enter your code here. Read input from STDIN. Print output to STDOUT

m = int(raw_input())
m_list = map(int, raw_input().split())
n = int(raw_input())
n_list = map(int, raw_input().split())

m_set = set(m_list)
n_set = set(n_list)

union = m_set.union(n_set)
inter = m_set.intersection(n_set)
diff = union.difference(inter)

for d in sorted(diff):
    print d

