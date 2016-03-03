#include <iostream>
struct node {
  int info;
  node* link;
};
class Stack {
public:
  node* top;
  Stack() {
    top = NULL;
  }
  void push(int ele) {
    node* tp = new node;
    tp->info = ele;
    tp->link = top;
    top = tp;
  }
  void pop() {
    node* tp = top;
    top = top->link;
    delete tp;
  }
  void traversal() {
    node* p = top;
    while(p) {
      std::cout << p->info << " ";
      p = p->link;
    }
  }
};
int main() {
  Stack s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.traversal();
  s.push(4);
  s.pop();
  s.push(5);
  s.traversal();
}
