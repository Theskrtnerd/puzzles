import re

def get_sum_1(my_text: str) -> int:
    pattern = re.compile(r"mul\((\d{1,3}),(\d{1,3})\)")
    matches = pattern.findall(my_text)
    total_sum = sum(int(x) * int(y) for x, y in matches)
    return total_sum

with open("input3.txt") as f:
    line = f.readlines()
    cal_str = ''.join(line)
    donts = cal_str.split("don't()")
    total_sum = 0
    total_sum += get_sum_1(donts[0])
    for term in donts[1:]:
        second_term = ''.join(term.split("do()")[1:])
        total_sum += get_sum_1(second_term)
    #print(get_sum_1(cal_str))
    print(total_sum)
    