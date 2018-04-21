#include <iostream>
#include <string>
#include "prefix_tree.h"

int main()
{
  Trie trie;

  // Insert
  auto node = trie.insert(std::string("async"), 4);
  std::cout << "value: " << node.first->value;
  for(const auto& ch : node.first->m_children)
  {
    std::cout << "child: " << ch.first;
  }
  std::cout << "\n";

  // Find
  auto foundAS = trie.find("as");
  if(foundAS.second)
  {
    std::cout << "Found ""as""\n";
  }
  else
  {
    std::cout << "Doesn't found ""as""\n";
  }

  auto foundDEB = trie.find("deb");
  if(foundDEB.second)
  {
    std::cout << "Found ""deb""\n";
  }
  else
  {
    std::cout << "Doesn't found ""deb""\n";
  }
  return 0;
}
