#Finding shortest path between all pair of vertices; for graph with positive or negative edge weights(but no negative cycles). Time complexity O(|V|^3) Space complexity theta(|V|^2)
no_of_nodes = int(raw_input())
no_of_edges = int(raw_input())

weights = []
for i in range(no_of_nodes):
    weights.append([])
    
for i in range(no_of_nodes):
    for j in range(no_of_nodes):
        weights[i].append(0)
print 'Nodes;', no_of_nodes
print 'Edges:', no_of_edges
print weights
for i in range(no_of_edges):
    x, y, z = map(int, raw_input().split())
    weights[x][y] = z

#Implementing Floyd Warshall Algorithm
visited = []
for i in range(no_of_nodes):
    visited.append(False)

def FloydWarshall():
    dist = []
    for i in range(no_of_nodes):
        dist.append([])
        
    for i in range(no_of_nodes):
        for j in range(no_of_nodes):
            dist[i].append(float('inf'))
    for i in range(no_of_nodes):
        dist[i][i] = 0
    print dist
    for x in range(no_of_nodes):
        for y in range(no_of_nodes):
            if weights[x][y]:
                dist[x][y] = weights[x][y]
    print dist
    for k in range(no_of_nodes):
        for i in range(no_of_nodes):
            for j in range(no_of_nodes):
                if dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
    print dist

print 'Floyd Warshall Algorithm:'
FloydWarshall()
