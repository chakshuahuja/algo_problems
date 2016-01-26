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

#Implementing Graph Traversal DFS Iterative
visited_iterative = []
for i in range(no_of_nodes):
    visited_iterative.append(False)

def DFSIterative(G, s):
    S = [] #Stack
    S.append(s)
    visited_iterative[s] = True
    while len(S):
        v = S[-1]
        print v+1
        S.pop()
        for w in G[v]:
            if not visited_iterative[w]:
                S.append(w)
                visited_iterative[w] = True

print 'DFS Traversal in the graph (Iterative):'
DFSIterative(adj_list, 0)
