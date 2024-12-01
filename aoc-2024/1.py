# Part 1
# with open("input.txt") as f:
#     data = f.read().splitlines()
#     nums1 = []
#     nums2 = []
#     for line in data:
#         num1, num2 = map(int, line.split())
#         nums1.append(num1)
#         nums2.append(num2)
#     print(sum([abs(num1-num2) for num1, num2 in zip(nums1, nums2)]))

# Part 2
# with open("input.txt") as f:
#     data = f.read().splitlines()
#     nums1 = {}
#     nums2 = {}
#     for line in data:
#         num1, num2 = map(int, line.split())
#         nums1[num1] = nums1.get(num1, 0) + 1
#         nums2[num2] = nums2.get(num2, 0) + 1
#     print(sum([num * nums2[num] for num in nums1.keys() if num in nums2.keys()]))
    