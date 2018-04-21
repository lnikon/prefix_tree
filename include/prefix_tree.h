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

    /*std::pair<Trie::Node*, bool>*/ Trie::Node* insert(std::string key, int value);
    std::pair<Trie::Node*, bool> find(std::string key);

private:
    std::unique_ptr<Node> m_root = std::make_unique<Node>();
};

/*std::pair<Trie::Node*, bool>*/
Trie::Node* Trie::insert(std::string key, int value)
{
  // Indicates the depth of the letter of word
  size_t i = 0;
  Node *pNode = m_root.get();

  while(i < key.length())
  {
    // Check if key[i] exists in m_children of the pNode
    if(pNode->m_children.count(key[i]) != 0)
    {
      // If it does, just re-assign our pNode to the node at this key
        pNode = pNode->m_children.at(key[i]).get();
      // As we find one letter of our key in the trie,
      // don't forget to increment the i
      i++;
    }
    else
    {
      break;
    }
  }

  // Time to build other part of our word
  // starting from last node that we used
  while(i < key.length())
  {
    pNode->m_children[key[i]] = std::make_unique<Trie::Node>();
    pNode = pNode->m_children[key[i]].get();
    i++;
  }

  pNode->value = value;

  // Refactor this part
//  return std::pair<Trie::Node *, bool>(pNode, true);
  return pNode;
}

std::pair<Trie::Node*, bool> Trie::find(std::string key)
{
  size_t i = 0;
  Node *pNode = m_root.get();
  bool exist = true;

  while(i < key.length())
  {
    // Check if key[i] exists in m_children of the pNode
    if(pNode->m_children.count(key[i]) != 0)
    {
      // If it does, just re-assign our pNode to the node at this key
        pNode = pNode->m_children.at(key[i]).get();
      // As we find one letter of our key in the trie,
      // don't forget to increment the i
      i++;
    }
    else
    {
      pNode = nullptr;
      exist = false;
      break;
    }
  }

  return std::pair<Trie::Node *, bool>(pNode, exist);
}
