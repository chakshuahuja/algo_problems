no_of_nodes = int(raw_input())
no_of_edges = int(raw_input())

#Implementing the adjacency list
adj_list = {}
for i in range(no_of_nodes):
    adj_list[i] = []

for i in range(no_of_edges):
    x, y = map(int, raw_input().split())
    adj_list[x].append(y)
    adj_list[y].append(x)

#Implementing Graph Traversal DFS Recursive
visited_recursive = []
for i in range(no_of_nodes):
    visited_recursive.append(False)
def DFSRecursive(G, s):
    visited_recursive[s] = True
    for w in G[s]:
        if not visited_recursive[w]:
            DFSRecursive(G, w)

#Finding the number of components using DFS
def noOfComponents(G):
    no_of_components = 0
    for i in range(no_of_nodes):
        if not visited_recursive[i]:
            DFSRecursive(G, i)
            no_of_components += 1
    return no_of_components

print 'Number of components in the graph:'
print noOfComponents(adj_list)

