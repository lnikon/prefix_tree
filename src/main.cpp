#include <iostream>
#include <string>
#include "prefix_tree.h"
#include "trie_test.h"

int main()
{
  Trie trie;
//  TRIE_TEST trie_test;

//  size_t count = 1000;
//  auto nodes = trie_test.TRIE_INSERT(trie, count);

//  for(const auto &node : nodes)
//  {
//    std::cout << node->value << ' ';
//  }
//  std::cout << '\n';

  trie.insert("annn", 2);
  trie.insert("n", 1);
//  trie.insert("n", 7);
//  trie.insert("a", 9);
  trie.insert("bbbb", -3);
  trie.insert("g", -12);
//  trie.insert("a", 14);
//  trie.insert("n", 19);

  std::cout << "Nodes count: "
            << trie.getNodeCounter() << '\n';
  trie.traverse();

  return 0;
}
