no_of_nodes = int(raw_input())
no_of_edges = int(raw_input())

#Implementing the adjacency list
adj_list = {}
for i in range(no_of_nodes):
    adj_list[i] = []

print adj_list
for i in range(no_of_edges):
    x, y = map(int, raw_input().split())
    adj_list[x].append(y)

print 'Adjacency list of the graph :'
print adj_list
