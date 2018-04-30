#include <iostream>
#include <string>
#include "prefix_tree.h"
#include "trie_test.h"

int main()
{
  Trie trie;

  trie.insert("anna", 19);
  trie.insert("anahit", 20);

  std::cout << "Nodes count: "
            << trie.getNodeCounter() << '\n';
  trie.traverse();

  //  TRIE_TEST trie_test;

  //  size_t count = 1000;
  //  auto nodes = trie_test.TRIE_INSERT(trie, count);

  //  for(const auto &node : nodes)
  //  {
  //    std::cout << node->value << ' ';
  //  }
  //  std::cout << '\n';

  return 0;
}
