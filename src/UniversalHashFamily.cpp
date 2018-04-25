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
        int bound = (1 << (keyBits - 1)) - 1; // largest value

        for (int i = 0; i < sizeBits; i++) {
            int randomInt = random_int(-bound - 1, bound);
            array[i] = randomInt;
        }
    }

    UniversalHashFamily::~UniversalHashFamily() {
        delete[] array;
    }

    int UniversalHashFamily::hash(int key) {
        int hash = 0;

        for (int i = 0; i < sizeBits; i++) {
            hash <<= 1;
            int value = array[i] & key;
            while (value) {
                hash ^= value & 1;
                value >>= 1;
            }
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
