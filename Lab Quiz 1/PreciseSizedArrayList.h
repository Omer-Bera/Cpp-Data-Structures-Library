// PreciseSizedArrayList.h
#ifndef PRECISE_SIZED_ARRAY_LIST_H
#define PRECISE_SIZED_ARRAY_LIST_H

class PreciseSizedArrayList {
public:
    // Made public for this quiz
    int* data;
    int size;

    // --- Functions you MUST implement ---
    PreciseSizedArrayList();
    void removeByValue(int value);
    double getHarmonicAverage() const;
    
    // --- Functions provided to you ---
    ~PreciseSizedArrayList();
    void add(int index, int value);
    void removeByIndex(int index);
    void changeValue(int index, int new_value);
    void reverse();
    void printList() const;
};

#endif