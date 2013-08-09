#include<iostream>
#include<vector>
typedef std::vector< std::vector<int> >::iterator MatrixIter;
typedef std::vector<int>::iterator RowIter;
void print(std::vector<std::vector<int> > vec) {
  for(MatrixIter iter = vec.begin(); iter != vec.end(); ++iter) {
    for(RowIter it = iter->begin(); it != iter->end(); ++it) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
  }
}
int main() {
  int n;
  std::cin >> n;
  //METHOD 1: Basic method without declaring the size of the vector(Dynamic allocation)
  std::vector< std::vector<int> > vec;
  for(int i = 0; i < n; i++) {
    std::vector<int> row;
    for(int j = 0; j < n; j++) {
      int k;
      std::cin >> k;
      row.push_back(k);
    }
    vec.push_back(row);
  }
  print(vec);
  //METHOD 2: Specifying what will be the size of the vector(vector of vectors) that will be formed
  std::vector< std::vector<int> > v(n);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      int e;
      std::cin >> e;
      v[i].push_back(e);
    }
  }
  print(v);
  //METHOD 3:Initializing the vector with some default value and then taking the input
  std::vector< std::vector<int> > vd(n, std::vector<int>(n));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      int e;
      std::cin >> e;
      vd[i][j] = e;
    }
  }
  print(vd);
  //METHOD 4: Initializing with some default value and  Using iterators to take the input
  std::vector< std::vector<int> > vi(n, std::vector<int>(n));
  for(MatrixIter iter = vi.begin(); iter != vi.end(); ++iter) {
    for(RowIter it = iter->begin(); it != iter->end(); ++it) {
      int k;
      std::cin >> k;
      *it = k;
    }
  }
  print(vi);
  return 0;
}
