arr = [5, 6, 1, 2, 6, 9, 2, 5]
n = len(arr)
# stack should be non increasing at end (opposite of what u want)
stack = []
ngr = [-1] * (n)
for i in range(n):
    # change inequality sign according to variant of problem
    while stack and arr[stack[-1]] < arr[i]: ngr[stack.pop()] = i
    stack.append(i)
print(ngr)