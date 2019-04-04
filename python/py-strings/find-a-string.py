def count_substring(string, sub_string):
    count = 0
    while True:
        pos = string.find(sub_string)
        if pos == -1:
            break
        count += 1
        string = string[pos+1:]
    return count


