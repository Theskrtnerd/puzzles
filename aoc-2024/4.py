# word_to_find = "XMAS"
# adjMat = []
# DIRS = [[0, 1], [0, -1], [1, 0], [-1, 0], [1, 1], [-1, -1], [1, -1], [-1, 1]]
# ans = 0
# with open("input4.txt") as f:
#     lines = f.readlines()
#     for line in lines:
#         adjMat.append(list(line.strip()))
#     for i, row in enumerate(adjMat):
#         for j, cell in enumerate(row):
#             if cell == word_to_find[0]:
#                 for dir in DIRS:
#                     found = True
#                     for k in range(1, len(word_to_find)):
#                         ni, nj = i + dir[0] * k, j + dir[1] * k
#                         if ni < 0 or ni >= len(adjMat) or nj < 0 or nj >= len(adjMat[0]) or adjMat[ni][nj] != word_to_find[k]:
#                             found = False
#                             break
#                     if found:
#                         ans +=1 
#     print(ans)


word_to_find = "XMAS"
adjMat = []
DIRS = [[[1, 1], [-1, -1]], [[1, -1], [-1, 1]]]
ans = 0
with open("input4.txt") as f:
    lines = f.readlines()
    for line in lines:
        adjMat.append(list(line.strip()))
    for i, row in enumerate(adjMat):
        for j, cell in enumerate(row):
            if cell == "A":
                found = True
                for dir in DIRS:
                    rem = ""
                    for k in range(2):
                        ni, nj = i + dir[k][0], j + dir[k][1]
                        if ni >= 0 and ni < len(adjMat) and nj >= 0 and nj < len(adjMat[0]):
                            rem += adjMat[ni][nj]
                    rem = sorted(rem)
                    rem = ''.join(rem)
                    if rem != "MS":
                        found = False
                        break
                if found:
                    ans += 1
                        
    print(ans)