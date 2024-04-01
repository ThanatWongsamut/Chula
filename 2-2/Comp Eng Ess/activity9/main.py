def I(): return [*map(int, input().split())]


INF = 9e9

n = int(input())
t = I()
d = [[INF, INF, INF] for _ in range(n+1)]
e = [[] for _ in range(n+1)]

for i in range(1, n+1):
    k, *l = I()
    e[i] = l

for i in range(3):
    q = []
    d[t[i]][i] = 0
    q.append(t[i])

    while q:
        now = q.pop(0)
        for j in e[now]:
            if d[j][i] > d[now][i] + 1:
                d[j][i] = d[now][i] + 1
                q.append(j)

ans = INF

for i in range(1, n+1):
    if d[i][0] == INF or d[i][1] == INF or d[i][2] == INF:
        continue
    ans = min(ans, max([d[i][0], d[i][1], d[i][2]]))

print(ans)

"""
5
1 3 5
1 2
2 1 3
2 2 4
2 3 5
1 4
"""

"""
10
2 5 10
2 2 4
1 3
1 1
1 5
1 6
1 7
1 8
1 9
1 4
2 8 9
"""
