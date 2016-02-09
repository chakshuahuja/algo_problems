#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

std::vector< std::vector<int> > create_graph(std::string C[], int n) {
  std::vector< std::vector<int> > g(n, std::vector<int>(n));
  for(int i = 0; i < n; i++) {
    std::istringstream is(C[i]);
    int a;
    while(is >> a) {
      g[i][a] = 1;
      g[a][i] = 1;
    }    
  }
  return g;
}
bool dfs(int v, int c, int n, std::vector<int>& visited, std::vector< std::vector<int> > g) {
  visited[v] = c;
  for(int i = 0; i < n; i++) {
    if(g[v][i]) {
      if(visited[i] != -1 && visited[i] == c)
	return false;
      if(visited[i] == -1 && !dfs(i, 1-c, n, visited, g))
	return false;
    }
  }
  return true;
}
int calculate_components(std::vector< std::vector<int> > g, int n) {
  std::vector<int> visited(n, -1);
  int k = 0;
  for(int i = 0; i < n; i++) {
    if(visited[i] == -1) {
      if(!dfs(i, 0, n, visited, g))
	return -1;
      k++;
    }
  }
  return k;
}
int main() {
  std::string C[] = {"1 4","2","3","0",""};
  int n = sizeof(C) / sizeof(C[0]);

  std::vector< std::vector<int> > graph = create_graph(C, n);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      std::cout << graph[i][j] << " ";
    }
    std::cout << std::endl;
  }
  int no_of_components = calculate_components(graph, n);
  if(no_of_components == -1)
    std::cout << -1;
  else
    std::cout << pow(2, no_of_components);
  return 0;

}
