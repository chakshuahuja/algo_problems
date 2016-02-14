#Finding shortest path from source vertex to all other vertices; Does not work for graph with negative edge weights because of keeping open and closed nodes set separately. Time complexity O(|V|^2), using min priority queue in O(|E| + |V|log|V|); fastest algorithm for single source shortest path algorithm
no_of_nodes = int(raw_input())
no_of_edges = int(raw_input())

weights = []
for i in range(no_of_nodes):
    weights.append([])
    
for i in range(no_of_nodes):
    for j in range(no_of_nodes):
        weights[i].append(0)
for i in range(no_of_edges):
    x, y, z = map(int, raw_input().split())
    weights[x][y] = z
    weights[y][x] = z

def minDistance(dist, Q):
    minimum = float('inf')
    min_index = -1
    for i in range(no_of_nodes):
        if not Q[i] and dist[i] <= minimum:
            minimum = dist[i]
            min_index = i
    return min_index

#Implementing Dijkstra Algorithm
def Dijkstra(s):
    dist = []
    prev = []
    Q = []
    for i in range(no_of_nodes):
        dist.append(float('inf'))
        prev.append(-1)
        Q.append(False)

    dist[s] = 0
    while False in Q:
        u = minDistance(dist, Q)
        Q[u] = True
        for v in range(no_of_nodes):
            if weights[u][v]:
                val = dist[u] + weights[u][v]
                if val < dist[v]:
                    dist[v] = val
                    prev[v] = u
    print dist, prev
        
print 'Dijkstra Algorithm:'
Dijkstra(0)
