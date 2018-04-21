//
// Created by H on 4/20/18.
//

#include <math.h>
#include <random>
#include "UniversalHashFamily.h"

namespace cs223 {
    UniversalHashFamily::UniversalHashFamily(int sizeBits, int keyBits) {
        this->sizeBits = sizeBits;
        this->keyBits = keyBits;
        array = new int[sizeBits];

        std::random_device random_device;  // Random device engine
        std::mt19937_64 rng(random_device()); // Initialize Mersennes' twister using randomDevice to generate the seed
        for (int i = 0; i < sizeBits; i++) {
            array[i] = random_int(0, (int) pow(2, keyBits) - 1, rng);
        }
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


    int random_int(int initial, int last, std::mt19937_64 rng) {
        std::uniform_int_distribution<int> distribution(initial, last);
        return distribution(rng);  // Use rng as a generator
    }
}