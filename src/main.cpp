//
// Created by hesham on 4/20/18.
//

#include <iostream>
#include <fstream>
#include <set>
#include <HighLevelHashTable.h>

int main() {
    std::ifstream file;

    std::string paths[] = {"../testCases/keys1001000.txt",
                           "../testCases/keys10001000.txt",
                           "../testCases/keys100001000000.txt",
                           "../testCases/keys10000001000000.txt"};


    for(const std::string &path : paths) {
        std::cout << path << std::endl;
        file.open(path);
        std::set<int> keys;     // keys are read into this set
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

        cs223::HighLevelHashTable llht(keys);
        for (std::set<int>::iterator it = keys.begin(); it != keys.end(); ++it) {
            int key = *it;
            if (!llht.exists(key))
            {
                std::cout << "Key " << key << " missing!" << std::endl;
            }
        }
    }

    return 0;
}
