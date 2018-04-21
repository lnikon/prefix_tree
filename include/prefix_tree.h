#pragma once

#include <vector>
#include <string>
#include <memory>

class Trie
{
  public:
    class Node
    {
        std::vector<char> m_children();
        int value = 0;
    };

    Trie();
    std::unique_ptr<Node> insert(std::string key, int value);
    std::unique_ptr<Node> find(std::string key);

};
