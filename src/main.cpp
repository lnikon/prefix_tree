#include <iostream>
#include <string>
#include "prefix_tree.h"

int main()
{
  Trie<int> trie;

  trie.insert("anna", 19);
  trie.insert("anahit", 20);
  trie.insert("nikol", 102);

  std::cout << "Nodes count: "
            << trie.getNodeCounter() << '\n';
  trie.traverse();

  return 0;
}
