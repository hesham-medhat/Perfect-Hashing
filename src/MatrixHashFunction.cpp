//
// Created by H on 4/20/18.
//

#include <MatrixHashFunction.h>

namespace cs223 {
    std::random_device MatrixHashFunction::rd;
    std::mt19937 MatrixHashFunction::gen(MatrixHashFunction::rd());
    std::uniform_int_distribution<int> MatrixHashFunction::dis;

    MatrixHashFunction::MatrixHashFunction(const size_t& size)
    {
        size_t indexLength = getIndexLength(size);
        this->size = 1 << indexLength;

        for (size_t i = 0; i < indexLength; ++i)
        {
            matrix.push_back(randomInt());
        }
    }

    size_t MatrixHashFunction::getActualSize() const
    {
        return size;
    }

    int MatrixHashFunction::hash(const int& key) const
    {
        int hash = 0;

        for (const auto& row : matrix)
        {
            hash <<= 1;
            unsigned int value = row & key;
            while (value) {
                hash ^= value & 1;
                value >>= 1;
            }
        }

        return hash;
    }

    size_t MatrixHashFunction::getIndexLength(int size)
    {
        size_t length = 0;

        if ((size - 1) & size) // Not a power of two?
        {
            length = 1;
        }

        while (size >>= 1)
        {
            length += 1;
        }

        return length;
    }

    int MatrixHashFunction::randomInt()
    {
        return dis(gen);
    }
}
