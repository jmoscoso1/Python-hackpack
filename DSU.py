import sys
input = sys.stdin.readline

# Disjoint sets with path compression
# and rank heuristic
n, m = map(int, input().split())

p = [i for i in range(n+1)] 
r = [1] * (n + 1)

def get(a):
    if p[a] != a:
        p[a] = get(p[a])
    return p[a]
 
def union(a, b):
    a = get(a)
    b = get(b)
    if a == b:
        return False
    if r[a] == r[b]:
        r[a] += 1
    if r[a] > r[b]:
        p[b] = a
    else:
        p[a] = b
    return True


