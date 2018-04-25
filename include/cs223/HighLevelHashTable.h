#ifndef CS223_HIGHLEVELHASHTABLE_H
#define CS223_HIGHLEVELHASHTABLE_H

#include "LowLevelHashTable.h"

namespace cs223 {
    class HighLevelHashTable : public HashTable {
    public:
        HighLevelHashTable(UniversalHashFamily &uhf, int size);

        bool exists(int key) override;
        void deleteKey(int key) override;
        bool insertKey(int key) override;
    private:
        LowLevelHashTable** data;
        static size_t getSizeBits(int size);
    };
}

#endif
