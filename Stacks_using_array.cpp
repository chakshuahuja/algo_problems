#include<iostream>
#include<stdlib.h>
int top = -1;
int N = 10;
void push(int stack[], int element) {
  if(top != N-1) {
    stack[++top] = element;
  }
  else {
    std::cout << "Stack overflow";
  }
}
int pop(int stack[]) {
  if(top == -1) {
    std::cout << "Stack underflow"; 
    return -1;
  }
  else
    return stack[top--];
}
void print(int stack[]) {
  std::cout << "From top to bottom:" << std::endl;
  for(int i = top; i >= 0; i--)
    std::cout << stack[i] << std::endl;
}
int main() {
  int stack[10];
  char c;
  do {
    std::cout << "1. PUSH 2. POP";
    std::cout << "Enter your choice : ";
    int choice;
    std::cin >> choice;
    if(choice == 1) {
      std::cout << "Enter the element to be pushed : ";
      int ele;
      std::cin >> ele;
      push(stack, ele);
    }
    else if(choice == 2) {
      pop(stack);
    } 
    std::cout << "Current state of stack :";
    std::cout << "Top : " << top << " ";
    print(stack);
    std::cout << "Do you want to continue ?";
    std::cin >> c;
  }while(c != 'n');
  return 0;
}
