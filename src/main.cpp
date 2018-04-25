//
// Created by hesham on 4/20/18.
//

#include "LowLevelHashTable.h"
#include "UniversalHashFamily.h"
#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <set>

void checkTable(cs223::LowLevelHashTable table) {
    for (int i = 0; i < table.size; i++) {
        std::cout << i << (table.existsAtIndex(i) ? " exists" : " doesn't exist") << std::endl;
    }
}

int main() {
    std::ifstream file;

    std::string paths[] = {"../testCases/keys1001000.txt",
                           "../testCases/keys10001000.txt",
                           "../testCases/keys100001000000.txt",
                           "../testCases/keys10000001000000.txt"};


    for(const std::string &path : paths) {
        std::cout << path << std::endl;
        file.open(path);
        std::set<int> keys;
        int value;
        int dup = 0;
        file >> value;
        if (file) {
            keys.insert(value);
            char separator;
            while (file >> separator >> value && separator == ',') {
                if (!keys.insert(value).second) {
                    dup ++;
                }
            }
        }
        file.close();
        std::cout << "Safy: " << keys.size() << std::endl << "Duplicates: " << dup << std::endl << keys.size() + dup << std::endl;

    }



    // TODO main function implementation.

    // TESTING LowLevelHashTable
//
//    cs223::UniversalHashFamily hasher(1, sizeof(int)*8);
//    cs223::LowLevelHashTable table(hasher, 2);
//
//    // std::cout << 13 << " hashed to " << hasher.hash(13) << std::endl;
//    table.insertKey(13);
//
//    // std::cout << 5 << " hashed to " << hasher.hash(5) << std::endl;
//    table.insertKey(5);
//
//    checkTable(table);
//
//    // std::cout << 1000 << " hashed to " << hasher.hash(1000) << std::endl;
//    std::cout << "Inserting 1000" << std::endl;
//    if (table.insertKey(1000)) {
//        // std::cout << "collision at 1000!" << std::endl;
//    }
//
//    // std::cout << 57 << " hashed to " << hasher.hash(57) << std::endl;
//    if (table.insertKey(57)) {
//        // std::cout << "collision at 57!" << std::endl;
//    }
//
//    // std::cout << 37 << " hashed to " << hasher.hash(37) << std::endl;
//    if (table.insertKey(37)) {
//        // std::cout << "collision at 37!" << std::endl;
//    }
//
//    checkTable(table);

//    int keys[] = {0, 4, 23, 89, 156, 1024, 2768, 3900, 111111, 23001249};
//    cs223::UniversalHashFamily hasher(4, sizeof(int)*8);
//    cs223::LowLevelHashTable table(hasher, keys, 10);

    return 0;
}
