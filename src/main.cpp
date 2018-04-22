#include <iostream>
#include <string>
#include "prefix_tree.h"
#include "trie_test.h"

int main()
{
  Trie trie;
  TRIE_TEST trie_test;

  size_t count = 1000;
  auto nodes = trie_test.TRIE_INSERT(trie, count);

  for(const auto &node : nodes)
  {
    std::cout << node->value << ' ';
  }
  std::cout << '\n';

  return 0;
}
