# x - k*(d + 1) = y - k

n = int(input())

for _ in range(n):
    r, b, d = [int(v) for v in input().split()]
    x = max(r, b)
    y = min(r, b)

    if d == 0:
        print("YES" if r == b else "NO")
        continue

    k = (x-y) / d

    if k <= y:
        print("YES")
    else:
        print("NO")
