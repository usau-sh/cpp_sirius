#ifndef L1_LIST_HPP_
#define L1_LIST_HPP_

struct Node {
  int val;
  Node *next;
};

class l1_list {
  Node *head = nullptr;
  Node *walk_to_last_elem();

public:
  void add_node(int new_val);
  void print_list();
  void delete_element(int val);

  ~l1_list();
};

#endif