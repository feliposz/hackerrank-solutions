if __name__ == '__main__':
    n = int(raw_input())
    arr = map(int, raw_input().split())

m = max(arr)
m2 = max(filter(lambda x: x != m, arr))

print m2

