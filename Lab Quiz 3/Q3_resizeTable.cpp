#include "HashTable.h"

#ifdef USE_STUDENT_RESIZE_IMPL

// --- TASK 3 ---
void HashTable::resizeTable()
{
    // YOUR CODE GOES HERE
        std::vector<HashEntry> oldTable = table;

        int oldSize = tableSize;
        tableSize = getNextPrime(2*oldSize);
        //std::cout<<"Debugging tablesize = "<< tableSize << std::endl;
        table.resize(tableSize);
        for(size_t i = 0; i < tableSize; i++){
            table[i].key = "";
            table[i].value = 0;
            table[i].status = EMPTY;
        }
        std::vector<HashEntry> table;

        for(size_t i = 0; i<tableSize; i++){
            if(oldTable[i].status == OCCUPIED){
                insert(oldTable[i].key, oldTable[i].value);
            }
        }

}

#endif
