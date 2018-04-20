#ifndef CS223_UNIVERSALHASHFAMILY_H
#define CS223_UNIVERSALHASHFAMILY_H

namespace cs223 {
    class UniversalHashFamily {
    public:
        UniversalHashFamily(int size);
        int hash(int key);
        int getSize();

    private:
        int size;
    };
}

#endif

