#include <iostream>
struct AdjListNode {
  int dest, weight;
  AdjListNode* next;
};
struct AdjList {
  AdjListNode* head;
};
class Graph {
public:
  int V;
  AdjList* array;
  Graph(int V) {
    this->V = V;
    array = new AdjList[V];
  }
  AdjListNode* newAdjListNode(int dest, int weight) {
    AdjListNode* node = new AdjListNode;
    node->dest = dest;
    node->weight = weight;
    node->next = NULL;
    return node;
  }
  void addEdge(int src, int dest, int weight) {
    AdjListNode* node = newAdjListNode(src, weight);
    node->next = array[dest].head;
    array[dest].head = node;
    node = newAdjListNode(dest, weight);
    node->next = array[src].head;
    array[src].head = node;
  }
  void printGraph() {
    for(int i = 0; i < V; i++) {
      AdjListNode* p = array[i].head;
      std::cout << i << "->";
      while(p) {
	std::cout << p->dest << "(" << p->weight << ")" << "->";
	p = p->next;
      }
      std::cout << "NULL" << std::endl;
    }
  }
};
int main() {
  Graph g(5);
  g.addEdge(0, 1, 1);
  g.addEdge(0, 4, 2);
  g.addEdge(1, 2, 3);
  g.addEdge(1, 3, 4);
  g.addEdge(1, 4, 5);
  g.addEdge(2, 3, 5);
  g.addEdge(3, 4, 6);
  g.printGraph();
}
