

def person_lister(f):
    def inner(people):
        return map(f, sorted(people, key=lambda p: int(p[2])))
    return inner


