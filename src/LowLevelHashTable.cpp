//
// Created by H on 4/20/18.
//

#include <utility>
#include <stdexcept>
#include "LowLevelHashTable.h"
#include "UniversalHashFamily.h"

namespace cs223 {
    LowLevelHashTable::LowLevelHashTable(UniversalHashFamily uhf, int keys[], int n)
            : HashTable(uhf, keys, n) {
        size = (int) pow(pow(2, ceil(log(n)/log(2))), 2);     //nearest larger power of 2
        data = new std::pair<bool, int> [size];
        for (int i = 0; i < size; i++) {
            data[i].first = false;
        }

        for (int i = 0; i < n; i++) {
            if (!insertKey(keys[i])) {
                throw std::invalid_argument("Collision occured!");
            }
        }
    }

    LowLevelHashTable::~LowLevelHashTable() {
        delete[] data;
    }

    bool LowLevelHashTable::insertKey(int key) {
        int index = hasher->hash(key);
        data[index].second = key;
        if (data[index].first) {
            return false;// Collision occurred
        } else {
            data[index].first = true;
            return true;
        }
    }

    bool LowLevelHashTable::existsAtIndex(int index) {
        return data[index].first;
    }

    bool LowLevelHashTable::exists(int key) {
        int index = hasher->hash(key);
        return data[index].first;
    }

    void LowLevelHashTable::deleteKey(int key) {
        int index = hasher->hash(key);
        data[index].first = false;
    }

}
