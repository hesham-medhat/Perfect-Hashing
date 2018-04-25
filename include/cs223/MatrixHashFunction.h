#ifndef CS223_MATRIXHASHFUNCTION_H
#define CS223_MATRIXHASHFUNCTION_H

#include <random>
#include <vector>

namespace cs223 {
    class MatrixHashFunction {
        public:
            MatrixHashFunction(const size_t& size);
            size_t getActualSize() const;
            int hash(const int& key) const;
        private:
            size_t size;
            std::vector<int> matrix;
            static std::random_device rd;
            static std::mt19937 gen;
            static std::uniform_int_distribution<int> dis;
            static int random_int();
        };
}

#endif

