#include<iostream>
#include<vector>
#include<algorithm>
class Node {
public :
  int data;
  std::vector<Node*> child;
  Node(int val, Node* left = NULL, Node* right = NULL) : data(val) {
    child.push_back(left);
    child.push_back(right);
  }
};
int maxLevel(Node* root) {
  if(!root) {
    return -1;
  }
  return std::max(maxLevel(root->child[0]), maxLevel(root->child[1])) + 1;
}
int diameter(Node* root) {
  if(!root) {
    return -1;
  }
  return std::max(
		  std::max(diameter(root->child[0]), diameter(root->child[1])),
		  1 + maxLevel(root->child[0]) + 1 + maxLevel(root->child[1])  + 1
		  ); 
}
int main () {
  Node* root = new Node(1,
                        new Node(2,
                                 new Node(5,
					  new Node(7),
					  new Node(8,
						   new Node(9,
							    new Node(10),
							    new Node(11)
							    )
						   )
					  ),
                                 new Node(6,
                                          NULL,
                                          new Node(12,
						   new Node(13),
						   new Node(14,
							    NULL,
							    new Node(15)
							    )
						   )
					  )
				 ),
                        new Node(3,
                                 NULL,
                                 new Node(4)
				 )
                        );
  int length = diameter(root);
  std::cout << length;
  return 0;
}
