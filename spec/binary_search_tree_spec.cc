#include <iostream>

#include <ccspec/core.h>
#include <ccspec/expectation.h>
#include <ccspec/matchers.h>

#include "binary_search_tree.h"

using std::cout;
using std::ostringstream;
using ccspec::core::Reporter;
using ccspec::core::after;
using ccspec::core::before;
using ccspec::core::describe;
using ccspec::core::formatters::DocumentationFormatter;
using ccspec::core::it;
using ccspec::matchers::be;
using ccspec::matchers::be_falsey;
using ccspec::matchers::be_truthy;
using ccspec::matchers::eq;
using ccspec::expect;

BinarySearchTree* bst;

auto bst_spec = describe("BinarySearchTree", [] {
  describe("#add", [] {
    it("returns back the instance", [] {
      BinarySearchTree bst;
      BinarySearchTree& bst2 = bst.add(5);
      expect(bst2).to(be(bst));
    });

    it("can build an arbitrary tree", [] {
      BinarySearchTree bst;
      bst.add(3).add(4).add(5).add(0).add(2).add(1);
      ostringstream oss;
      oss << bst;
      expect(oss.str()).to(eq(
          "    5\n"
          "  4\n"
          "3\n"
          "    2\n"
          "      1\n"
          "  0\n"
          ""));
    });
  });

  describe("#search", [] {
    before("each", [] {
      bst = new BinarySearchTree();
      bst->add(3).add(1).add(5).add(0).add(2).add(4);
    });

    after("each", [] {
      delete bst;
    });

    it("returns true if the given element is at root", [] {
      expect(bst->search(3)).to(be_truthy);
    });

    it("returns true if the given element is the min element", [] {
      expect(bst->search(0)).to(be_truthy);
    });

    it("returns true if the given element is the max element", [] {
      expect(bst->search(5)).to(be_truthy);
    });

    it("returns true if the given element is in the tree", [] {
      expect(bst->search(2)).to(be_truthy);
    });

    it("returns true if the given element is not in the tree", [] {
      expect(bst->search(42)).to(be_falsey);
    });
  });
});

int main() {
  DocumentationFormatter formatter(cout);
  Reporter reporter(&formatter);
  bool succeeded = bst_spec->run(reporter);
  delete bst_spec;
  return !succeeded;
}
