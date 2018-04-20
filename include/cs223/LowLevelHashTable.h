#ifndef CS223_LOWLEVELHASHTABLE_H
#define CS223_LOWLEVELHASHTABLE_H

#include "HashTable.h"
#include <utility>

namespace cs223 {
    class LowLevelHashTable : public HashTable {
    public:
        LowLevelHashTable(UniversalHashFamily uhf);

        bool exists(int key);
        void deleteKey(int key);
        bool insertKey(int key);
    private:

        std::pair<bool, int> * data;// <ValueExists?, Value>
    };
}

#endif
