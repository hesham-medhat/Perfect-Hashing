#include <utility>
#include <set>
#include "HighLevelHashTable.h"

namespace cs223 {
    HighLevelHashTable::HighLevelHashTable(UniversalHashFamily& uhf, int keys[], int n)
            : HashTable(uhf, keys, n) {
        size = (int) pow(2, ceil(log(n)/log(2)));     //nearest larger power of 2
        data = new LowLevelHashTable* [size];

        std::set<int> *collisions = new std::set<int>[size];
        for (int i = 0; i < n; i++) {       // classify keys according to their hash values in the high level table
            int hashValue = hasher->hash(keys[i]);
            collisions[hashValue].insert(keys[i]);
        }


        for (int i = 0; i < size; i++) {        // process for creating low level tables
            std::set<int> lowLevelKeys = collisions[i];
            int lowLevelN = lowLevelKeys.size();
            int lowLevelSize = (int) pow(pow(2, ceil(log(lowLevelN)/log(2))), 2);   //square nearest larger power of 2
            UniversalHashFamily *lowLevelHasher;

            bool lowLevelCollision = true;
            while (lowLevelCollision) {     //create low level hashers till no collision occurs
                lowLevelCollision = false;
                lowLevelHasher = new UniversalHashFamily(getSizeBits(lowLevelSize), sizeof(int)*8);
                std::set<int> lowerHashValues;

                for (std::set<int>::iterator it = lowLevelKeys.begin(); it != lowLevelKeys.end(); ++it) {
                    int key = *it;
                    if (!lowerHashValues.insert(key).second) {      // if hash value is already in the set
                        lowLevelCollision = true;
                        delete lowLevelHasher;
                        break;
                    }
                }
            }

            int lowLevelKeysArray[lowLevelKeys.size()];
            int j = 0;
            for (std::set<int>::iterator it = lowLevelKeys.begin(); it != lowLevelKeys.end(); ++it, ++j) {
                lowLevelKeysArray[j] = *it;
            }
            data[i] = new LowLevelHashTable(*lowLevelHasher, lowLevelKeysArray, lowLevelN);
        }
    }

    HighLevelHashTable::~HighLevelHashTable() {
        for (size_t i = 0; i < size; ++i) {
            delete data[i];
        }

        delete[] data;
    }

    size_t HighLevelHashTable::getSizeBits(int size) {
        size_t sizeBits = 0;
        if ((size - 1) & size) { // not power of 2?
            sizeBits = 1;
        }
        while (size >>= 1) {
            sizeBits += 1;
        }
        return sizeBits;
    }

    bool HighLevelHashTable::insertKey(int key) {
        int index = hasher->hash(key);
        return data[index]->insertKey(key);
    }

    bool HighLevelHashTable::exists(int key) {
        int index = hasher->hash(key);
        return data[index]->exists(key);
    }

    void HighLevelHashTable::deleteKey(int key) {
        int index = hasher->hash(key);
        data[index]->deleteKey(key);
    }

}
