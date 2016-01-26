no_of_nodes = int(raw_input())
no_of_edges = int(raw_input())

#Implementing the adjacency matrix
adj_matrix = []
for i in range(no_of_nodes):
    adj_matrix.append([])
for i in range(no_of_nodes):
    for j in range(no_of_nodes):
        adj_matrix[i].append(0)

for i in range(no_of_edges):
    x, y = map(int, raw_input().split())
    adj_matrix[x][y] = 1

print 'Adjacency matrix of the graph :'
print adj_matrix
