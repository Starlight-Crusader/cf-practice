def dfs(u: int, visited: list, max_depth: list, depth: int = 0):
    max_depth[0] = max(depth, max_depth[0])
    visited[u] = True
    for v in al[u]:
        dfs(v, visited, max_depth, depth + 1)

n = int(input())

al = [[] for _ in range(n)]
root = [True for _ in range(n)]

for i in range(n):
    p = int(input())

    if p != -1:
        p -= 1
        al[p].append(i)
        root[i] = False

max_depth = [-1]
visited = [False for _ in range(n)]

while True:
    all_visited = True
    u = None
    for i in range(n):
        if not visited[i] and root[i]:
            u = i
            all_visited = False
            break

    if all_visited:
        break

    dfs(u, visited, max_depth)

print(max_depth[0] + 1)
