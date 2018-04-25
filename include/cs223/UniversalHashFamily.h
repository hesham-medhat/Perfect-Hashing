#ifndef CS223_UNIVERSALHASHFAMILY_H
#define CS223_UNIVERSALHASHFAMILY_H

#include <random>

namespace cs223 {
    class UniversalHashFamily {
    public:
        UniversalHashFamily(int sizeBits, int keyBits);
        ~UniversalHashFamily();
        int hash(int key);
        int getSizeBits();
        int getKeyBits();

    private:
        int sizeBits;
        int keyBits;
        int *array;
        static std::random_device rd;  // Random device engine, usually based on /dev/random on UNIX-like systems
        static std::mt19937_64 rng; // Initialize Mersennes' twister using rd to generate the seed
        int random_int(int initial, int last);
    };


}

#endif

