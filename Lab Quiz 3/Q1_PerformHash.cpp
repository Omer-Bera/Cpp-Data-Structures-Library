#include "HashTable.h"

#ifdef USE_STUDENT_HASH_IMPL

// --- TASK 1 ---
int HashTable::performHash(std::string key)
{
    // YOUR CODE GOES HERE
    int M = tableSize;
    int hash = 0;
    unsigned int base = 1;
    for(size_t i = 0; i < key.length(); i++){
        hash += base*(key[i]);
        base *= 33;
    }

    return hash % tableSize;
}

#endif