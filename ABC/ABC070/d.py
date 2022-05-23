from sys import  stdin
import heapq

n = int(input())

edge = [[] for i in range(n)]

for i in range(n-1):
    a, b, c = [int(x) for x in stdin.readline().rstrip().split()]
    a -= 1
    b -= 1
    edge[a].append([b, c])
    edge[b].append([a, c])

q, k = [int(x) for x in stdin.readline().rstrip().split()]
k -= 1
p_q = [(0, k)]
heapq.heapify(p_q)
distance = [1000000000000000000] * n

while len(p_q) != 0:
    cost, v = heapq.heappop(p_q)
    if distance[v] < cost:
        continue
    distance[v] = cost
    for u, u_cost in edge[v]:
        if distance[u] > cost + u_cost:
            heapq.heappush(p_q, (cost + u_cost, u))
            distance[u] = cost + u_cost


while q:
    q -= 1
    x, y = [int(x) for x in stdin.readline().rstrip().split()]
    x -= 1
    y -= 1
    print(distance[x] + distance[y])

