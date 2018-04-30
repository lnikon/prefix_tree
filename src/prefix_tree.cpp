#include "prefix_tree.h"

Trie::Node* Trie::insert(std::string key, int value)
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

std::pair<Trie::Node*, bool> Trie::find(std::string key)
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

void Trie::traverse()
{
    traverse(m_root.get());
}

void Trie::traverse(Trie::Node *node)
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

void Trie::visit(Trie::Node *node)
{
    if(node && node->value)
    {
        std::cout << node->value << '\n';
    }
}
