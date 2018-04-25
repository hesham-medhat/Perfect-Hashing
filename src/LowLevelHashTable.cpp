//
// Created by H on 4/20/18.
//

#include <utility>
#include "LowLevelHashTable.h"
#include "UniversalHashFamily.h"

namespace cs223 {
    LowLevelHashTable::LowLevelHashTable(UniversalHashFamily uhf, int size)
            : HashTable(uhf, size) {
        data = new std::pair<bool, int> [size];
        for (int i = 0; i < size; i++) {
            data[i].first = false;
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

    bool LowLevelHashTable::exists(int key) {
        int index = hasher->hash(key);
        return data[index].first;
    }

    void LowLevelHashTable::deleteKey(int key) {
        int index = hasher->hash(key);
        data[index].first = false;
    }

}
