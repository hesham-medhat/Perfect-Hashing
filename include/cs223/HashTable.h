#ifndef CS223_HASHTABLE_H
#define CS223_HASHTABLE_H

#include "UniversalHashFamily.h"

namespace cs223 {
    class HashTable {
    public:
        HashTable(UniversalHashFamily & uhf, int keys[], int n);

        int size;

        virtual bool exists(int key) = 0;
        virtual void deleteKey(int key) = 0;
        virtual bool insertKey(int key) = 0;

    protected:
        UniversalHashFamily* hasher;
    };
}

#endif
