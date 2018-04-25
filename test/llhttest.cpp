#include <iostream>
#include <LowLevelHashTable.h>
using namespace std;
using namespace cs223;

int main()
{
    size_t size;
    cout << "Number of keys: ";
    cin >> size;
    
    int keys[size];
    cout << "Keys:" << endl;
    for (size_t i = 0; i < size; ++i)
    {
        cout << i << ") ";
        cin >> keys[i];
    }
    cout << endl;

    // TODO complete LowLevelHashTable test

    return 0;
}
