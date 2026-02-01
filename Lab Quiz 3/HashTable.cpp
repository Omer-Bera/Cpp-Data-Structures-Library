#include "HashTable.h"

// --- PRE-IMPLEMENTED (DO NOT CHANGE) ---
// The following functions are provided to you implicitly.
// You do not need to paste them, but you can use them.

// --- HELPERS (GIVEN) ---
bool HashTable::isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int HashTable::getNextPrime(int n) {
    if (n <= 1) return 2;
    while (!isPrime(n)) {
        n++;
    }
    return n;
}

HashTable::HashTable(int size) {
    tableSize = size;
    currentSize = 0;
    table.resize(tableSize);
}
void HashTable::printTable() {
    std::cout << "Size: " << tableSize << std::endl;
    for (int i = 0; i < tableSize; i++) {
        if (table[i].status == OCCUPIED)
            std::cout << i << ": " << table[i].key << " (" << table[i].value << ")" << std::endl;
    }
}