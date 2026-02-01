#include "HashTable.h"

#ifdef USE_STUDENT_INSERT_IMPL

// --- TASK 2 ---
void HashTable::insert(std::string key, int value)
{
    // YOUR CODE GOES HERE
    int hash = performHash(key);
    if(table[hash].status == EMPTY || table[hash].status == DELETED){
        table[hash].value = value;
        table[hash].key = key;
        table[hash].status = OCCUPIED;
        currentSize++;
        return;        
    }
    else{
        int CurrentIdx = hash;
        while(table[CurrentIdx].status == OCCUPIED){
            int Idxnext = (CurrentIdx + 1) % tableSize;
            if(table[Idxnext].status == EMPTY || table[Idxnext].status == DELETED){
                table[Idxnext].value = value;
                table[Idxnext].key = key;
                table[Idxnext].status = OCCUPIED;
                currentSize++;
                return;        
            }
            CurrentIdx++;
        }
    }
}

#endif