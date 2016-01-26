no_of_nodes = int(raw_input())
no_of_edges = int(raw_input())

#Implementing the adjacency list
edges = {}
for i in range(no_of_nodes):
    edges[i] = []

for i in range(no_of_edges):
    x, y, z = map(int, raw_input().split())
    edges[x].append((y,z))
    edges[y].append((x,z))

print edges
#Implementing the Queue and basic operations
class DoubleEndedQueue:
    def __init__(self):
        self.items = []
    def push_back(self, item):
        self.items.insert(0, item)
    def push_front(self, item):
        self.items.append(item)
    def dequeue(self):
        return self.items.pop()
    def isEmpty(self):
        return self.items == []
    def size(self):
        return len(self.items)

#Implementing the 0-1BFS and finding minimum cost for traversal between nodes
distance = []
for i in range(no_of_nodes):
    distance.append(999)

def BFS(edges, s):
    Q = DoubleEndedQueue()
    Q.push_back(s)
    distance[s] = 0
    while Q.size():
        v = Q.dequeue()
        for i in range(len(edges[v])):
            if distance[edges[v][i][0]] > distance[v] + edges[v][i][1]:
                distance[edges[v][i][0]] = distance[v] + edges[v][i][1]
                if not edges[v][i][1]:
                    Q.push_front(edges[v][i][0])
                else:
                    Q.push_back(edges[v][i][0])

BFS(edges, 0)
print distance
    
