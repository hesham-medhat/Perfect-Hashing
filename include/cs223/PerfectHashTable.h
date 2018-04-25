#ifndef CS223_PERFECTHASHTABLE_H
#define CS223_PERFECTHASHTABLE_H

#include <set>

namespace cs223 {
    class PerfectHashTable {
        public:
            PerfectHashTable(const std::set<int>& keys);
            virtual bool exists(const int& key) const = 0;
    };
}

#endif