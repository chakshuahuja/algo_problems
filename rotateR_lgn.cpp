#include<iostream>
int binarySearch(int a[], int low, int high) {
  int mid;
  while(low <= high) {
    mid = (low+high) / 2;
    std::cout << mid;
    if(((mid == 0) || (a[mid] < a[mid-1])) && (a[mid] < a[mid+1])) 
	return mid;
    else if(((mid == low) && (a[mid] > a[high])) || (a[mid] > a[mid+1]))  
      return mid+1;
    else if((a[mid] > a[mid-1]) && (a[mid] > a[low]))
      low = mid + 1;
    else 
      high = mid - 1;
  }
}
int rotatedBy(int arr[],int n) {
  int k = binarySearch(arr, 0, n-1);
  return (n-k) % n;
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
