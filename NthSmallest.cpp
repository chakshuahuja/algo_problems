//To find the Nth Smallest element in a Binary Tree
#include <iostream>
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
void formVec(Node* root, std::vector<int>& vec, int count = 0) {
  if(!root) 
    return;
  formVec(root->child[0], vec, count);
  vec.push_back(root->data);
  formVec(root->child[1], vec, count);
}
std::vector<int> formVec(Node* root) {
  std::vector<int> vec;
  formVec(root, vec);
  return vec;
}
int main ()
{
  Node* root = new Node(2,
                        new Node(7,
				 new Node(2),
				 new Node(6,
					  new Node(5),
					  new Node(11)
					  )
				 ),
                        new Node(5,
				 NULL,
				 new Node(9,
					  new Node(4)
					  )
				 )
                        );
  int n;
  std::cin >> n;
  std::vector<int> vec = formVec(root);
  std::sort(vec.begin(), vec.end());
  std::cout << vec[n-1];
  
  return 0;
}
