#Linear ordering of vertices in Directed Acyclic Graph
no_of_nodes = int(raw_input())
no_of_edges = int(raw_input())

#Implementing the adjacency list
adj_list = {}
for i in range(no_of_nodes):
    adj_list[i] = []

for i in range(no_of_edges):
    x, y = map(int, raw_input().split())
    adj_list[x].append(y)

visited = []
for i in range(no_of_nodes):
    visited.append(False)

S = []
#Implementing Graph Topological Sort
def TopologicalSortUtil(G, s):
    visited[s] = True
    for w in G[s]:
        if not visited[w]:
            TopologicalSortUtil(G, w)
    S.append(s)

def TopologicalSort(G):
    for i in range(no_of_nodes):
        if not visited[i]:
            TopologicalSortUtil(G, i)

#Time complexity same as DFS O(V+E)
print 'Topological sort in the graph:'
TopologicalSort(adj_list)
for i in range(len(S)):
    print S.pop(),
