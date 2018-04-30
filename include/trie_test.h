#ifndef TRIE_TEST_H
#define TRIE_TEST_H

#include <string>
#include <vector>
#include <cstddef>  // for size_t

#include "prefix_tree.h"

class TRIE_TEST
{
public:
  TRIE_TEST();

  std::vector<Trie::Node *>     TRIE_INSERT(Trie &trie, size_t insertions_count);
  std::pair<Trie::Node *, bool> TRIE_FIND(Trie &trie, std::string key);
};

#endif // TRIE_TEST_H
