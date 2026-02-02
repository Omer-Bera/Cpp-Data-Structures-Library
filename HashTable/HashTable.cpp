#include "HashTable.h"
#include <cmath>

// --- Constructor ---
HashTable::HashTable(CollisionStrategy strategy, int initialSize) {
    // YOUR CODE HERE
    this->currentSize = 0;
    this->strategy = strategy;
    this->tableSize = initialSize;
    if (strategy == SEPARATE_CHAINING)
    {
        buckets.resize(tableSize);
    }
    else
    {
        table.resize(tableSize);
    }
}

// --- Helpers ---
bool HashTable::isPrime(int n) {
    // YOUR CODE HERE

    if (n < 2)
        return false;
    if (n <= 3)
        return true;
    if (n % 6 != 1 && n % 6 != 5)
        return false;
    unsigned int u = static_cast<int>(std::sqrt(n));
    bool result = true;

    for (int i = 5; i <= u; i += 6)
    {
        if (0 == n % i || 0 == n % (i + 2))
            return false;
    }
    return result;
}

int HashTable::getNextPrime(int n) {
    // YOUR CODE HERE
    if(n<2) return 2;
    if(n % 2 == 0) n++;
    while(!HashTable::isPrime(n)) n = n +2;
    return n;
}

int HashTable::performHash(std::string key) {
// YOUR CODE HERE
    unsigned int hash = 0;
    int M = tableSize;
    unsigned int base = 1;
    for(size_t i = 0; i < key.length(); i++ ){
        hash += key[i] * (base);
        base = base * 33;
    }
    return hash % M;
}

int HashTable::performHash2(std::string key) {
// YOUR CODE HERE
    int P = tableSize - 1;
    int M = tableSize;
    if (P > 2) while (!isPrime(P)) P--;
    unsigned hash = 0;
    unsigned base = 1;
    for (size_t i = 0; i < key.length(); i++){
        hash += key[i] * base;
        base *= 33;
    }
    hash %= P;
    hash = (P - hash) % M;
    return hash;
}

// --- Operations ---
void HashTable::insert(std::string key, int value) {
    // YOUR CODE HERE
    if (strategy == SEPARATE_CHAINING){
        bool found = false;
        int hash = performHash(key);
        for(size_t i = 0; i < buckets[hash].size(); i++){
            if (key == buckets[hash][i].key){
                buckets[hash][i].value = value;
                found = true;
                break;
            }
        }
        if(found == false){
            buckets[hash].push_back(HashEntry(key, value, OCCUPIED));
            currentSize++;
        }

    }
    else{
        int h1 = performHash(key);

        int h2 = (strategy == DOUBLE) ? performHash2(key) : 0;

        int i = 0;
        bool placed = false;

        while (i < tableSize)
        {
            int index;

            if (strategy == LINEAR)
            {
                index = (h1 + i) % tableSize;
            }
            else if (strategy == QUADRATIC)
            {
                index = (h1 + i * i) % tableSize;
            }
            else
            {
                index = (h1 + i * h2) % tableSize;
            }

            if (table[index].status == OCCUPIED && table[index].key == key)
            {
                table[index].value = value;
                placed = true;
                break;
            }

            if (table[index].status == EMPTY || table[index].status == DELETED)
            {
                table[index] = HashEntry(key, value, OCCUPIED);
                currentSize++;
                placed = true;
                break;
            }

            i++;
        }
    }


    double loadFactor = static_cast<double>(currentSize) / tableSize;
    if (loadFactor > 0.5)
    {
        resizeTable();
    }
}

bool HashTable::search(std::string key, int &outValue){
    // YOUR CODE HERE

    if (strategy == SEPARATE_CHAINING)
    {
        int hashIndex = performHash(key);

        for (size_t i = 0; i < buckets[hashIndex].size(); i++)
        {
            if (buckets[hashIndex][i].key == key)
            {
                outValue = buckets[hashIndex][i].value;
                return true;
            }
        }
    }
    else
    {
        int primaryHash = performHash(key);
        int secondaryHash = (strategy == DOUBLE) ? performHash2(key) : 0;
        int attempt = 0;

        while (attempt < tableSize)
        {
            int probeIndex;

            if (strategy == LINEAR)
            {
                probeIndex = (primaryHash + attempt) % tableSize;
            }
            else if (strategy == QUADRATIC)
            {
                probeIndex = (primaryHash + attempt * attempt) % tableSize;
            }
            else
            {
                probeIndex = (primaryHash + attempt * secondaryHash) % tableSize;
            }

            if (table[probeIndex].status == EMPTY)
            {
                return false;
            }

            if (table[probeIndex].status == OCCUPIED && table[probeIndex].key == key)
            {
                outValue = table[probeIndex].value;
                return true;
            }

            attempt++;
        }
    }

    return false;
}

void HashTable::remove(std::string key) {
    // YOUR CODE HERE
    if (strategy == SEPARATE_CHAINING)
    {
        int bucketIndex = performHash(key);

        for (auto iterator = buckets[bucketIndex].begin(); iterator != buckets[bucketIndex].end(); ++iterator)
        {
            if (iterator->key == key)
            {
                buckets[bucketIndex].erase(iterator);
                currentSize--;
                return;
            }
        }
    }
    else
    {
        int primaryHash = performHash(key);
        int secondaryHash = (strategy == DOUBLE) ? performHash2(key) : 0;
        int probeCount = 0;
        while (probeCount < tableSize)
        {
            int currentIndex;
            if (strategy == LINEAR)
            {
                currentIndex = (primaryHash + probeCount) % tableSize;
            }
            else if (strategy == QUADRATIC)
            {
                currentIndex = (primaryHash + probeCount * probeCount) % tableSize;
            }
            else
            {
                currentIndex = (primaryHash + probeCount * secondaryHash) % tableSize;
            }
            if (table[currentIndex].status == EMPTY)
            {
                return;
            }
            if (table[currentIndex].status == OCCUPIED && table[currentIndex].key == key)
            {
                table[currentIndex].status = DELETED;
                currentSize--;
                return;
            }
            probeCount++;
        }
    }
    
}

void HashTable::resizeTable() {
    // YOUR CODE HERE
    int previousSize = tableSize;
    std::vector<HashEntry> previousTable = table;
    std::vector<std::vector<HashEntry>> previousBuckets = buckets;
    tableSize = getNextPrime(2 * previousSize);
    currentSize = 0;
    if (strategy == SEPARATE_CHAINING)
    {
        buckets.clear();
        buckets.resize(tableSize);
    }
    else
    {
        table.assign(tableSize, HashEntry());
    }
    if (strategy == SEPARATE_CHAINING)
    {
        for (int bucketIndex = 0; bucketIndex < previousSize; ++bucketIndex)
        {
            for (auto &entry : previousBuckets[bucketIndex])
            {
                insert(entry.key, entry.value);
            }
        }
    }
    else
    {
        for (int tableIndex = 0; tableIndex < previousSize; ++tableIndex)
        {
            if (previousTable[tableIndex].status == OCCUPIED)
            {
                insert(previousTable[tableIndex].key, previousTable[tableIndex].value);
            }
        }
    }
}

void HashTable::printTable() {
    std::cout << "Size: " << tableSize << std::endl;
    
    if (strategy == SEPARATE_CHAINING) {
        for (int i = 0; i < tableSize; i++) {
            if (!buckets[i].empty()) {
                std::cout << i << ": ";
                for (const auto& entry : buckets[i]) {
                    std::cout << "[" << entry.key << ":" << entry.value << "] -> ";
                }
                std::cout << "NULL" << std::endl;
            }
        }
    } else {
        // Open Addressing Print
        for (int i = 0; i < tableSize; i++) {
            if (table[i].status == OCCUPIED)
                std::cout << i << ": " << table[i].key << " (" << table[i].value << ")" << std::endl;
            else if (table[i].status == DELETED)
                std::cout << i << ": DELETED" << std::endl;
        }
    }
}