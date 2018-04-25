//
// Created by H on 4/20/18.
//

#include <utility>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "LowLevelHashTable.h"
#include "MatrixHashFunction.h"

namespace cs223 {
    LowLevelHashTable::LowLevelHashTable(const std::set<int>& keys)
    {
        size_t tempSize = keys.size();
        tempSize *= tempSize;
        trials = 0;
        if (!keys.empty()) {
            int tableSize = 1;
            while (tableSize < tempSize) {
                tableSize *= 2;
            }
            table = new std::vector<std::pair<bool, int>>(tableSize);
            for (auto item : *table) {
                item.first = false;
            }
            buildTable(keys);
        }
    }

    void LowLevelHashTable::buildTable(const std::set<int>& keys) {
        if (++trials > 1) {
            std::cout << "Trial #" << trials << std::endl;
        }
        hashFn = new MatrixHashFunction(keys.size()*keys.size());
        for (auto key : keys) {
            if (!insertKey(key)) {

                for (auto keyDestroyer : keys) {
                    deleteKey(keyDestroyer);
                    if (keyDestroyer == key) {
                        deleteKey(keyDestroyer);
                        break;
                    }
                }

                /* Alternative more costly way of destroying
                for (auto item : *table) {
                    item.second = false;
                }*/

                buildTable(keys);// Expected depth of two.
            }
        }
    }

    bool LowLevelHashTable::exists(const int& key) const {
        int index = hashFn->hash(key);
        if (table->at(index).first) {
            return key == table->at(index).second;
        } else {
            return false;
        }

    }

    LowLevelHashTable::~LowLevelHashTable() {
    }

    bool LowLevelHashTable::insertKey(int key) {
        int index = hashFn->hash(key);
        table->at(index).second = key;
        if (table->at(index).first) {
            return false;// Collision occurred
        } else {
            table->at(index).first = true;
            return true;
        }
    }

    void LowLevelHashTable::deleteKey(int key) {
        int index = hashFn->hash(key);
        table->at(index).first = false;
    }

}
