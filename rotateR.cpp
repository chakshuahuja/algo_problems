//Care needs to be taken that the input is correct else a special check can be included for that
//Calculate the number of times sorted array is rotated by. 
//O(n) complexity
#include<iostream>
int rotatedBy(int arr[], int n) {
  int i;
  for(i = 0; i < n-1; i++) {
    if(arr[i+1] < arr[i])
      break;
  }
  return n-i-1;
}
int main() {
  int n;
  std::cout << "Enter the length of array :";
  std::cin >> n;
  int arr[n];
  std::cout << "Enter the array :";
  for(int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  std::cout << "The given array was rotated " << rotatedBy(arr, n) << " times";
  std::cout << std::endl;
}
