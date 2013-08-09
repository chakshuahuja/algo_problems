#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;
void printSpiral(const vector<string> &v) {
    size_t
      sr = 0, //starting row
      er = v.size(), // ending row
      sc = 0, // starting col
      ec = v[0].size(); // ending col
    // These variables define a box
    // we will print the outer box and
    // then update the variable to redifine the inner
    // box until the box size is zero
    while (sr < er && sc < ec) {
      // print the first row of the box
      std::cout << string(v[sr].begin() + sc, v[sr].begin() + ec);
      // update the box's upper boundry
      sr++;
      // now print the last column
      for (size_t i = sr; i < er; i++) {
	std::cout << v[i][ec-1];
      }
      // now update the box's right boundry
      ec--; 
      if(sr < er) {
	std::cout<< string(v[er-1].rbegin() + (v[er-1].size() - ec), v[er-1].rend() - sc);
        // Now we update the box's lower boundry
	er--;
      }
      if(sc < ec) {
        // Print the first column, the left boundry, in reverse
	for (size_t i = er-1; i >= sr; i--) {
	  std::cout << v[i][sc];
	}
	sc++;
      }
    }

}
int main() {
  vector<string> v;
  string s;
  while (std::cin >> s) v.push_back(s);
  printSpiral(v);
  std::cout << std::endl;
}
