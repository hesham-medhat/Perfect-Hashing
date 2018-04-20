//
// Created by H on 4/20/18.
//

#include "UniversalHashFamily.h"

namespace cs223 {
    UniversalHashFamily::UniversalHashFamily(int size) {
        this->size = size;
    }
    int UniversalHashFamily::hash(int key) {
        return key % size;
    }
    int UniversalHashFamily::getSize() {
        return this->size;
    }
}