#ifndef CS223_HASHTABLE_H
#define CS223_HASHTABLE_H

#include "UniversalHashFamily.h"

namespace cs223 {
    class HashTable {
    public:
        HashTable(UniversalHashFamily & uhf);

        int size;

        bool exists(int key);
        void deleteKey(int key);
        bool insertKey(int key);

    protected:
        UniversalHashFamily* hasher;
    };
}

#endif
