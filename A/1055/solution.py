from collections import deque

s = int(input().split()[1]) - 1
a = input().split()
b = input().split()
n = len(a)

adj = [[] for _ in range(n)]

for i in range(n):
    if a[i] == '1':
        for j in range(i):
            if a[j] == '1':
                adj[j].append(i)

for i in range(n - 1, 0, -1):
    if b[i] == '1':
        for j in range(n - 1, i, -1):
            if b[j] == '1':
                adj[j].append(i)

visited = [False] * n
queue = deque([0])

while queue:
    curr = queue.popleft()
    if visited[curr]:
        continue
    visited[curr] = True
    for neighbor in adj[curr]:
        if not visited[neighbor]:
            queue.append(neighbor)

print("YES" if visited[s] else "NO")
