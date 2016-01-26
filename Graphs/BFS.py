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

#Implementing the Queue and basic operations
class Queue:
    def __init__(self):
        self.items = []
    def enqueue(self, item):
        self.items.insert(0, item)
    def dequeue(self):
        return self.items.pop()
    def isEmpty(self):
        return self.items == []
    def size(self):
        return len(self.items)

#Implementing the Graph Traversal BFS
visited = []
for i in range(no_of_nodes):
    visited.append(False)

def BFS(G, s):
    Q = Queue()
    Q.enqueue(s)
    visited[s] = True
    while Q.size():
        v = Q.dequeue()
        print v
        for w in G[v]:
            if not visited[w]:
                Q.enqueue(w)
                visited[w] = True


BFS(adj_list, 0)
    
