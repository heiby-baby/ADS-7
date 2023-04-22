// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct Node {
    T value;
    Node* next;
  };
  Node* head;

 public:
  TPQueue() : head(nullptr) {}
  void push(T);
  int pop();
};

struct SYM {
  char ch;
  int prior;
};

template<typename T>
void TPQueue<T>::push(T val) {
  Node* newNode = new Node;
  newNode->next = nullptr;
  newNode->value = val;
  if (!head) {
    head = newNode;
    return;
  }
  if (val.prior > head->value.prior) {
    newNode->next = head;
    head = newNode;
    return;
  }
  Node* temp = head;
  while (temp->next && val.prior <= temp->next->value.prior) temp = temp->next;
  newNode->next = temp->next;
  temp->next = newNode;
}

template<typename T>
int TPQueue<T>::pop() {
  if (!head) {
    cout << "Очередь пуста!" << endl;
    return -1;
  }
  int data = head->value.ch;
  Node* temp = head;
  head = head->next;
  delete temp;
  return data;
}

#endif  // INCLUDE_TPQUEUE_H_
