#include "l1_list.hpp"
#include <iostream>

Node *l1_list::walk_to_last_elem() {
  if (head == nullptr) {
    return nullptr;
  }
  Node *res = head;
  while (res->next != nullptr) {
    res = res->next;
  }
  return res;
}

void l1_list::add_node(int new_val) {
  if (head == nullptr) {
    head = new Node{new_val, nullptr};
    return;
  }
  Node *res = walk_to_last_elem();
  res->next = new Node{new_val, nullptr};
}

void l1_list::delete_element(int val) {
  Node *prev, *cur;
  while (head != nullptr && head->val == val) {
    prev = head->next;
    delete head;
    head = prev;
  }

  if (head == nullptr) {
    return;
  }

  cur = head->next;
  prev = head;
  while (cur != nullptr) {
    if (cur->val == val) {
      // std::cout << "found elem!" << std::endl;
      prev->next = cur->next;
      delete cur;
      cur = prev->next;
    } else {
      prev = cur;
      cur = cur->next;
    }
  }
}

void l1_list::print_list() {
  Node *cur = head;
  if (cur == nullptr) {
    std::cout << "Linked list is empty" << std::endl;
  }
  while (cur != nullptr) {
    std::cout << cur->val << ' ';
    cur = cur->next;
  }
  std::cout << std::endl;
}

l1_list::~l1_list() {
  if (head == nullptr) {
    return;
  }
  Node *prev, *cur;
  cur = head->next;
  prev = head;
  while(cur != nullptr) {
    delete prev;
    prev = cur;
    cur = cur->next;
  }
  delete prev;
}
