#include <iostream>
#include <UniversalHashFamily.h>
using namespace std;
using namespace cs223;

bool hasCollisions(
        UniversalHashFamily& uhf,
        const size_t& size,
        const size_t& count,
        const int keys[]);

int main()
{
    size_t count;
    cout << "Number of keys: ";
    cin >> count;

    int keys[count];
    cout << "Keys:" << endl;
    for (size_t i = 0; i < count; ++i)
    {
        cout << i + 1 << ") ";
        cin >> keys[i];
    }
    cout << endl;

    size_t size = count * count;
    size_t sizeBits = ceil(log(size)/log(2));
    size_t tableSize = 1u << sizeBits;
    size_t keyBits = sizeof(int) * 8;

    cout << "Will construct a hash function matrix of dimensions "
        << sizeBits << " x " << keyBits << endl;
    cout << "(Table size: " << tableSize << ")" << endl << endl;

    constexpr size_t maxRetries = 256;
    size_t retries = maxRetries;
    UniversalHashFamily uhf(sizeBits, keyBits);
    while (hasCollisions(uhf, tableSize, count, keys) && retries--)
    {
        uhf = UniversalHashFamily(sizeBits, keyBits);
    }

    if (hasCollisions(uhf, tableSize, count, keys))
    {
        cout << "Could not find a hash function with no collisions" << endl;
    }
    else
    {
        cout << "Gotcha! (" << maxRetries - retries << " retries)" << endl;
        for (const auto& key : keys)
        {
            cout << key << "\thashed to\t" << uhf.hash(key) << endl;
        }
    }

    return 0;
}

bool hasCollisions(
    UniversalHashFamily& uhf,
    const size_t& size,
    const size_t& count,
    const int keys[])
{
    bool exists[size];
    for (auto& val : exists)
    {
        val = false;
    }

    for (size_t i = 0; i < count; ++i)
    {
        if (exists[uhf.hash(keys[i])])
        {
            return true;
        }
        exists[uhf.hash(keys[i])] = true;
    }

    return false;
}
