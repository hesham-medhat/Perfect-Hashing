//
// Created by hesham on 4/20/18.
//

#include "LowLevelHashTable.h"
#include "UniversalHashFamily.h"
#include "HashTable.h"
#include <iostream>

void checkTable(cs223::LowLevelHashTable table) {
    for (int i = 0; i < table.size; i++) {
        std::cout << i << (table.existsAtIndex(i) ? " exists" : " doesn't exist") << std::endl;
    }
}

int main() {
    // TODO main function implementation.

    // TESTING LowLevelHashTable

    cs223::UniversalHashFamily hasher(1, sizeof(int)*8);
    cs223::LowLevelHashTable table(hasher, 2);

    // std::cout << 13 << " hashed to " << hasher.hash(13) << std::endl;
    table.insertKey(13);

    // std::cout << 5 << " hashed to " << hasher.hash(5) << std::endl;
    table.insertKey(5);

    checkTable(table);

    // std::cout << 1000 << " hashed to " << hasher.hash(1000) << std::endl;
    std::cout << "Inserting 1000" << std::endl;
    if (table.insertKey(1000)) {
        // std::cout << "collision at 1000!" << std::endl;
    }

    // std::cout << 57 << " hashed to " << hasher.hash(57) << std::endl;
    if (table.insertKey(57)) {
        // std::cout << "collision at 57!" << std::endl;
    }

    // std::cout << 37 << " hashed to " << hasher.hash(37) << std::endl;
    if (table.insertKey(37)) {
        // std::cout << "collision at 37!" << std::endl;
    }

    checkTable(table);

    return 0;
}
