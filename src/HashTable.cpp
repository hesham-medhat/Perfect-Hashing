//
// Created by H on 4/20/18.
//

#include "HashTable.h"
#include "UniversalHashFamily.h"

namespace cs223 {
    HashTable::HashTable(UniversalHashFamily & uhf, int keys[], int n) {
        hasher = &uhf;
    }
}
