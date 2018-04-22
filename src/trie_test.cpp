#include "trie_test.h"
#include "prefix_tree.h"

#include <random>
#include <memory>

TRIE_TEST::TRIE_TEST()
{

}

std::vector<Trie::Node *> TRIE_TEST::TRIE_INSERT(Trie &trie, size_t insertions_count)
{
  std::vector<Trie::Node *> nodes;
  nodes.reserve(insertions_count);

  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(1,99);

  std::vector<std::string> keys;
  keys.reserve(insertions_count);

  for(size_t i = 0; i < insertions_count; i++)
  {
    keys.push_back(std::to_string(distribution(generator)));
  }

  for(size_t i = 0; i < insertions_count; i++)
  {
    nodes.push_back(trie.insert(keys[i], static_cast<int>(i * 100000)));
  }

  return nodes;
}

std::pair<Trie::Node *, bool> TRIE_TEST::TRIE_FIND(Trie &trie, std::string key)
{

  return std::pair<Trie::Node *, bool>(std::make_unique<Trie::Node>().get(), true);
}
