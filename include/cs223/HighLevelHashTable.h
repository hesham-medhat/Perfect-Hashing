#ifndef CS223_HIGHLEVELHASHTABLE_H
#define CS223_HIGHLEVELHASHTABLE_H

#include "HashTable.h"

namespace cs223 {
    class HighLevelHashTable : public HashTable {
    public:
        HighLevelHashTable(UniversalHashFamily &uhf);

        bool exists(int key) override;
        void deleteKey(int key) override;
        bool insertKey(int key) override;
    };
}

#endif

public:
