#pragma once

#include <unordered_map>
#include <utility>
#include <string>
#include <memory>
#include <iostream>

template <class T>
class Trie
{
public:
  struct Node
  {
    std::unordered_map<char, std::unique_ptr<Node>> m_children;
    T value {0};
    Node(): m_children() {}
  };

  Trie::Node* insert(std::string key, T value);
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

template <class T>
typename Trie<T>::Node* Trie<T>::insert(std::string key, T value)
{
    size_t i = 0;
    Node *pNode = m_root.get();

    while(i < key.length())
    {
        if(pNode->m_children.count(key[i]) == 0)
        {
            m_nodeCounter++;
            pNode->m_children[key[i]] = std::make_unique<Trie::Node>();
        }
        pNode = pNode->m_children[key[i]].get();
        i++;
    }
    pNode->value = value;

    return pNode;
}

template <class T>
std::pair<typename Trie<T>::Node*, bool> Trie<T>::find(std::string key)
{
    size_t i = 0;
    Node *pNode = m_root.get();
    bool exist = true;

    while(i < key.length())
    {
        if(pNode->m_children.count(key[i]) != 0)
        {
            pNode = pNode->m_children.at(key[i]).get();
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

template <class T>
void Trie<T>::traverse()
{
    traverse(m_root.get());
}

template <class T>
void Trie<T>::traverse(typename Trie<T>::Node *node)
{
    if(node == nullptr)
    {
        return;
    }

    for(size_t i = 0; i < node->m_children.size(); i++)
    {
        traverse(node->m_children[i].get());
        visit(node->m_children[i].get());
    }
}

template <class T>
void Trie<T>::visit(typename Trie<T>::Node *node)
{
    if(node && node->value)
    {
        std::cout << node->value << '\n';
    }
}
