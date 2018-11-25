#include "binary_search_tree.h"

using std::endl;
using std::ostream;

BinarySearchTree::BinarySearchTree() : root_(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
  delete root_;
}

BinarySearchTree& BinarySearchTree::add(int elem) {
  return add(elem, &root_);
}

bool BinarySearchTree::search(int elem) const {
  return search(elem, root_);
}

BinarySearchTree& BinarySearchTree::add(int elem, Node** pnode) {
  Node* node = *pnode;
  if (node == nullptr) {
    *pnode = new Node(elem, nullptr, nullptr);
    return *this;
  } else if (node->elem_ < elem) {
    return add(elem, &(node->right_));
  } else {
    return add(elem, &(node->left_));
  }
}

bool BinarySearchTree::search(int elem, Node* node) const {
  if (node == nullptr) {
    return false;
  }

  if (node->elem_ < elem) {
    return search(elem, node->right_);
  } else if (node->elem_ > elem) {
    return search(elem, node->left_);
  } else {
    return true;
  }
}

ostream& BinarySearchTree::output(ostream& stream, Node* node, int level) const {
  if (node == nullptr) {
    return stream;
  }
  output(stream, node->right_, level + 1);
  for (int i = 0; i < level; ++i) {
    stream << "  ";
  }
  stream << node->elem_ << endl;
  output(stream, node->left_, level + 1);

  return stream;
}

BinarySearchTree::Node::Node(int elem, Node* left, Node* right)
    : elem_(elem), left_(left), right_(right) {}

BinarySearchTree::Node::~Node() {
  delete left_;
  delete right_;
}

ostream& operator <<(ostream& stream, const BinarySearchTree& tree) {
  return tree.output(stream, tree.root_, 0);
};
