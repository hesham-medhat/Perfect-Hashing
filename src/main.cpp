//
// Created by hesham on 4/20/18.
//

#include "LowLevelHashTable.h"
#include "UniversalHashFamily.h"
#include "HashTable.h"
#include <iostream>

namespace cs223 {

    void checkTable(LowLevelHashTable table) {
        for (int i = 0; i < table.size; i++) {
            std::cout << i << (table.exists(i) ? " exists" : " doesn't exist") << std::endl;
        }
    }

    int main() {
        //TODO: main function implementation.

        //TESTING LowLevelHashTable

        UniversalHashFamily hasher(10);
        LowLevelHashTable table(hasher);
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
}