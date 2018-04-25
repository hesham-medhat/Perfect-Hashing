#ifndef CS223_HIGHLEVELHASHTABLE_H
#define CS223_HIGHLEVELHASHTABLE_H

#include <LowLevelHashTable.h>

namespace cs223 {
    class HighLevelHashTable : public PerfectHashTable {
        public:
            HighLevelHashTable(const std::set<int>& keys);
            bool exists(const int& key) const;
        private:
            MatrixHashFunction hashFn;
            std::vector<LowLevelHashTable> table;
    };
}

#endif
