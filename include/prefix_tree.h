#pragma once

#include <algorithm>
#include <vector>
#include <unordered_map>
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
    std::unordered_map<char, std::unique_ptr<Node>> m_children;
    int value {0};
    Node(): m_children() {}
  };

  Trie::Node* insert(std::string key, int value);
  std::pair<Trie::Node*, bool> find(std::string key);
  void traverse();

  inline auto getNodeCounter()
  {
    return m_nodeCounter;
  }

private:
  std::unique_ptr<Node> m_root {std::make_unique<Node>()};
  size_t m_nodeCounter {0};

  void traverse(Node *node);
  void visit(Node *node);

};
