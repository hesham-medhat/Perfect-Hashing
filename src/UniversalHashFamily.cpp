//
// Created by H on 4/20/18.
//

#include <math.h>
#include <random>
#include "UniversalHashFamily.h"

namespace cs223 {
    std::random_device UniversalHashFamily::rd;
    std::mt19937_64 UniversalHashFamily::rng(rd());

    UniversalHashFamily::UniversalHashFamily(int sizeBits, int keyBits) {
        this->sizeBits = sizeBits;
        this->keyBits = keyBits;
        array = new int[sizeBits];

        for (int i = 0; i < sizeBits; i++) {
            int randomInt = random_int(0, (int) pow(2, keyBits) - 1);
            array[i] = randomInt;
        }
    }

    UniversalHashFamily::~UniversalHashFamily() {
        delete[] array;
    }

    int UniversalHashFamily::hash(int key) {
        int hash = 0;

        for (int i = 0; i < sizeBits; i++) {
            int value = 0;
            for (int j = 0; j < keyBits; j++) {
                value += (array[i] >> j & 1) * (key >> j & 1);
            }

            value %= 2;
            hash = hash << 1;
            hash |= value;
        }
        return hash;
    }

    int UniversalHashFamily::getSizeBits() {
        return this->sizeBits;
    }

    int UniversalHashFamily::getKeyBits() {
        return this->keyBits;
    }


    int UniversalHashFamily::random_int(int initial, int last) {
        std::uniform_int_distribution<int> distribution(initial, last);
        return distribution(rng);  // Use rng as a generator
    }

}
