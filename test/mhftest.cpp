#include <iostream>
#include <MatrixHashFunction.h>
using namespace std;
using namespace cs223;

bool hasCollisions(
        MatrixHashFunction& mhf,
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

    cout << "Will construct a matrix hash function of dimensions "
        << sizeBits << " x " << keyBits << endl;
    cout << "(Table size: " << tableSize << ")" << endl << endl;

    constexpr size_t maxRetries = 256;
    size_t retries = maxRetries;
    MatrixHashFunction mhf(size);
    while (hasCollisions(mhf, tableSize, count, keys) && retries--)
    {
        mhf = MatrixHashFunction(size);
    }

    if (hasCollisions(mhf, tableSize, count, keys))
    {
        cout << "Could not find a hash function with no collisions" << endl;
    }
    else
    {
        cout << "Gotcha! (" << maxRetries - retries << " retries)" << endl;
        for (const auto& key : keys)
        {
            cout << key << "\thashed to\t" << mhf.hash(key) << endl;
        }
    }

    return 0;
}

bool hasCollisions(
    MatrixHashFunction& mhf,
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
        if (exists[mhf.hash(keys[i])])
        {
            return true;
        }
        exists[mhf.hash(keys[i])] = true;
    }

    return false;
}
