#ifndef CS223_UNIVERSALHASHFAMILY_H
#define CS223_UNIVERSALHASHFAMILY_H

#include <random>

namespace cs223 {
    class UniversalHashFamily {
    public:
        UniversalHashFamily(int sizeBits, int keyBits);
        int hash(int key);
        int getSizeBits();
        int getKeyBits();

    private:
        int sizeBits;
        int keyBits;
        int *array;
        int random_int(int initial, int last, std::mt19937_64 rng);
    };
}

#endif

