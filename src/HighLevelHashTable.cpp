#include <utility>
#include <set>
#include "HighLevelHashTable.h"

namespace cs223 {
    HighLevelHashTable::HighLevelHashTable(const std::set<int>& keys) : hashFn(MatrixHashFunction(keys.size()))
    {

        std::set<int> *collisions = new std::set<int>[hashFn.getActualSize()];

        // classify keys according to their hash values in the high level table
        for (std::set<int>::iterator it = keys.begin(); it != keys.end(); ++it) {
            int key = *it;
            int hashValue = hashFn.hash(key);
            collisions[hashValue].insert(key);
        }

        // process for creating low level tables
        for (int i = 0; i < hashFn.getActualSize(); i++) {
            std::set<int> lowLevelKeys = collisions[i];
            table.push_back(*(new LowLevelHashTable(lowLevelKeys)));
        }
    }

    HighLevelHashTable::~HighLevelHashTable() {
        for (size_t i = 0; i < hashFn.getActualSize(); ++i) {
        }
    }

    bool HighLevelHashTable::exists(const int &key) const {
        return table[hashFn.hash(key)].exists(key);
    }

}
