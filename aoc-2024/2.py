# bounds = [1,2,3]

# with open("input2.txt") as f:
#     data = f.read().splitlines()
#     ans = 0
#     for line in data:
#         levels = list(map(int, line.split()))
#         if len(levels) == 1:
#             ans += 1
#             continue
#         neg = 1
#         if(levels[0] - levels[1] == 0):
#             continue
#         elif(levels[0] - levels[1] < 0):
#             neg = -1
#         else:
#             neg = 1
#         safe = True
#         for i in range(len(levels)-1):
#             if neg*(levels[i] - levels[i+1]) not in bounds:
#                 safe = False
#                 break
#         if not safe:
#             continue
#         else:
#             ans += 1

#     print(ans)
import copy

bounds = [1,2,3]

def check_report_1(levels):
    for i in range(len(levels)-1):
        if levels[i] - levels[i+1] not in bounds:
            return False
    return True

def check_report_2(levels):
    case1 = copy.deepcopy(levels)
    case2 = copy.deepcopy(levels)
    for i in range(len(levels)-1):
        if levels[i] - levels[i+1] <= 0 or levels[i] - levels[i+1] not in bounds:
            case1.pop(i)
            case2.pop(i+1)
            break
    if check_report_1(case1) or check_report_1(case2):
        return True
    else:
        return False
            

with open("input2.txt") as f:
    data = f.read().splitlines()
    print(len(data))
    ans = 0
    for line in data:
        levels = list(map(int, line.split()))
        bruh = copy.deepcopy(levels)
        bruh2 = copy.deepcopy(levels)
        bruh.reverse()
        if check_report_2(bruh2) or check_report_2(bruh):
            ans += 1
        else:
            print(levels)
    print(ans)
            