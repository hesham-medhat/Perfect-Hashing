#ifndef CS223_LOWLEVELHASHTABLE_H
#define CS223_LOWLEVELHASHTABLE_H

#include "HashTable.h"
#include <utility>

namespace cs223 {
    class LowLevelHashTable : public HashTable {
    public:
        LowLevelHashTable(UniversalHashFamily uhf, int keys[], int n);
        ~LowLevelHashTable();

        bool existsAtIndex(int index);
        bool exists(int key) override;
        void deleteKey(int key) override;
        bool insertKey(int key) override;
    private:

        std::pair<bool, int> * data;// <ValueExists?, Value>
    };
}

#endif
