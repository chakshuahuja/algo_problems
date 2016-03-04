//Checking if string s2 can be obtained from s1 by doing some rotations.
#include<iostream>
int main() {
  std::cout << "Enter the two strings : ";
  std::string s1, s2;
  std::cin >> s1 >> s2;
  std::string s1s1 = s1 + s1;
  std::cout << s1s1;
  std::cout << "Checking for the rotation : ";
  if(s1.length() == s2.length()) {
    if(s1s1.find(s2) != std::string::npos)
      std::cout << "Yes";
    else std::cout << "No";
  }
  else 
    std::cout << "No";
  return 0;
}
