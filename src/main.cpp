//
// Created by hesham on 4/20/18.
//

#include "LowLevelHashTable.h"
#include "UniversalHashFamily.h"
#include "HashTable.h"
#include <iostream>

void checkTable(cs223::LowLevelHashTable table) {
    for (int i = 0; i < table.size; i++) {
        std::cout << i << (table.exists(i) ? " exists" : " doesn't exist") << std::endl;
    }
}

int main() {
    //TODO: main function implementation.

    //TESTING LowLevelHashTable

    cs223::UniversalHashFamily hasher(1, 1);
    cs223::LowLevelHashTable table(hasher, 2);
    table.insertKey(13);
    table.insertKey(5);
    checkTable(table);

    if (table.insertKey(1000)) {
        std::cout << "collision at 1000!" << std::endl;
    }

    if (table.insertKey(57)) {
        std::cout << "collision at 57!" << std::endl;
    }
    if (table.insertKey(37)) {
        std::cout << "collision at 37!" << std::endl;
    }

    checkTable(table);



    return 0;
}