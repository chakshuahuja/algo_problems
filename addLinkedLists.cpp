#include <iostream>
using namespace std;

class LinkedListNode{
public:
  int val;
  LinkedListNode *next;

  LinkedListNode(int node_value) {
    val = node_value;
    next = NULL;
  }
};
void printList(LinkedListNode* head) {
  while(head) {
    std::cout << head->val;
    std::cout << "->";
    head = head->next;
  }
  std::cout << "NULL";
}
LinkedListNode* pushFront(LinkedListNode* head, int data) {
  LinkedListNode* orignal_head = head;
  head = new LinkedListNode(data);
  head->next = orignal_head;
  return head;
}
LinkedListNode* reverseList(LinkedListNode* list) {
    if(list == NULL)
      return NULL;
    LinkedListNode* revList = NULL;
    while(list) { 
      revList = pushFront(revList, list->val);
      list = list->next;
    }
    return revList;
}
LinkedListNode* finalList(LinkedListNode* head) {
  int carry = 0;
  LinkedListNode* initial_head = head;
  while(head) {
    int initial_val = head->val + carry;
    head->val = (head->val + carry) % 10;
    carry = initial_val / 10;
    if(head->next)
      head = head->next;
    else {
      if(carry)
	head->next = new LinkedListNode(carry);
      head = head->next;
    }
  }
  return initial_head;
}
LinkedListNode* 
addLinkedLists(LinkedListNode* _list1, 
               LinkedListNode* _list2, 
               LinkedListNode* _list3) {
  LinkedListNode* revList1 = reverseList(_list1);
  LinkedListNode* revList2 = reverseList(_list2);
  LinkedListNode* revList3 = reverseList(_list3);
  LinkedListNode* addedList = new LinkedListNode(revList1->val + revList2->val + revList3->val);
  LinkedListNode* ref = addedList;
  while(revList1->next || revList2->next || revList3->next) {
    if(revList1->next)
      revList1 = revList1->next;
    else
      revList1->val = 0;;
    if(revList2->next)
      revList2 = revList2->next;
    else
      revList2->val = 0;
    if(revList3->next)
      revList3 = revList3->next;
    else
      revList3->val = 0;
    ref->next = new LinkedListNode(revList1->val + revList2->val + revList3->val);
    ref = ref->next;
  }
  addedList = finalList(addedList);
  return reverseList(addedList);
}

/********************************************************/
/* You shouldn't see anything below this, just write the damn
   function above and that's it
*/
LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head,
                                                   int val) {
  if(head == NULL) {
    head = new LinkedListNode(val);
  }
  else {
    LinkedListNode *end = head;
    while (end->next != NULL) {
      end = end->next;
    }
    LinkedListNode *node = new LinkedListNode(val);
    end->next = node;
  }
  return head;
}

int main() {
  LinkedListNode* res;
    
  int __list1_size;
  int __list1_item;
  LinkedListNode* __list1 = NULL;
  cin >> __list1_size;
  int __list1_i;
  for(__list1_i = 0; __list1_i < __list1_size; __list1_i++) { 
    cin >> __list1_item;
    __list1 = _insert_node_into_singlylinkedlist(__list1, __list1_item);
  }
    
    
  int __list2_size;
  int __list2_item;
  LinkedListNode* __list2 = NULL;
  cin >> __list2_size;
  int __list2_i;
  for(__list2_i = 0; __list2_i < __list2_size; __list2_i++) { 
    cin >> __list2_item;
    __list2 = _insert_node_into_singlylinkedlist(__list2, __list2_item);
  }
    
    
  int __list3_size;
  int __list3_item;
  LinkedListNode* __list3 = NULL;
  cin >> __list3_size;
  int __list3_i;
  for(__list3_i = 0; __list3_i < __list3_size; __list3_i++) { 
    cin >> __list3_item;
    __list3 = _insert_node_into_singlylinkedlist(__list3, __list3_item);
  }
  res = addLinkedLists(__list1, __list2, __list3);
  printList(res);
  return 0;
}


