#ifndef CS223_LOWLEVELHASHTABLE_H
#define CS223_LOWLEVELHASHTABLE_H

#include <utility>
#include <vector>
#include <PerfectHashTable.h>
#include <MatrixHashFunction.h>

namespace cs223 {
    class LowLevelHashTable : public PerfectHashTable {
        public:
            LowLevelHashTable(const std::set<int>& keys);

            bool exists(const int& key) const;
            bool insertKey(int key);
            void deleteKey(int key);

            ~LowLevelHashTable();
        private:
            MatrixHashFunction* hashFn;
            std::vector<std::pair<bool, int>>* table; // <(exists?), (key)>

            void buildTable(const std::set<int>& keys);
    };
}

#endif
