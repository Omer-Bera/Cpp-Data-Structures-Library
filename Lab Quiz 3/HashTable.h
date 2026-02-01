#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <vector>
#include <iostream>

enum EntryStatus { EMPTY, OCCUPIED, DELETED };

struct HashEntry {
    std::string key;
    int value;
    EntryStatus status;
    HashEntry(std::string k = "", int v = 0, EntryStatus s = EMPTY) 
        : key(k), value(v), status(s) {}
};

class HashTable {
public:
    // For Open Addressing
    std::vector<HashEntry> table;
    

    int currentSize;
    int tableSize;

    HashTable(int initialSize = 11);
    void insert(std::string key, int value);
    void printTable();
    
    // Helpers
    int performHash(std::string key);
    int getNextPrime(int n);
    bool isPrime(int n);
    void resizeTable();
};
#endif