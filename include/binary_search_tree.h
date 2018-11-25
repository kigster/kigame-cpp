#ifndef INCLUDE_CCSPEC_EXAMPLE_BINARY_SEARCH_TREE_H_
#define INCLUDE_CCSPEC_EXAMPLE_BINARY_SEARCH_TREE_H_

#include <ostream>

class BinarySearchTree {
 public:
  BinarySearchTree();
  virtual ~BinarySearchTree();

  BinarySearchTree& add(int elem);
  bool search(int elem) const;

 private:
  struct Node {
    int elem_;
    Node* left_;
    Node* right_;

    Node(int elem, Node* left, Node* right);
    ~Node();
  };

  BinarySearchTree& add(int elem, Node**);
  bool search(int elem, Node*) const;
  std::ostream& output(std::ostream&, Node*, int level) const;

  Node* root_;

  friend std::ostream& operator <<(std::ostream&, const BinarySearchTree&);
};

std::ostream& operator <<(std::ostream&, const BinarySearchTree&);

#endif  // INCLUDE_CCSPEC_EXAMPLE_BINARY_SEARCH_TREE_H_
