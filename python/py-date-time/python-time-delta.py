from datetime import datetime, timedelta

t = int(input())
fmt = '%a %d %b %Y %H:%M:%S %z'

for _ in range(t):
    t1 = datetime.strptime(input(), fmt)
    t2 = datetime.strptime(input(), fmt)
    td = t1 - t2
    print(abs(int(td.total_seconds())))

