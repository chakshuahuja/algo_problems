#include<iostream>
#include<algorithm>
bool compare(char a, char b) {
  if((int)a < (int)b)
    return true;
  else
    return false;
}
int main() {
  std::cout << "Enter the two strings : ";
  std::string s1, s2;
  std::cin >> s1 >> s2;
  sort(s1.begin(), s1.end(), compare);
  sort(s2.begin(), s2.end(), compare);
  if(s1 == s2)
    std::cout << "Yes";
  else
    std::cout << "No";
  return 0;
}
