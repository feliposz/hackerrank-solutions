cube = lambda x: x*x*x

def fibonacci(n):
    result = []
    p, q = 0, 1
    for _ in range(n):
        result.append(p)
        p, q = q, p + q
    return result


