#pragma once

#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <string>
#include <memory>
#include <iostream>

class Trie
{
public:
  struct Node
  {
    std::map<char, std::unique_ptr<Node>> m_children;
    int value = 0;
    Node(): m_children() {}
  };

  Trie::Node* insert(std::string key, int value);
  std::pair<Trie::Node*, bool> find(std::string key);

private:
  std::unique_ptr<Node> m_root = std::make_unique<Node>();
};
