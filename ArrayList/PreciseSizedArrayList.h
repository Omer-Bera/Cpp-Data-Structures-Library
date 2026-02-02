// PreciseSizedArrayList.h
#ifndef PRECISE_SIZED_ARRAY_LIST_H
#define PRECISE_SIZED_ARRAY_LIST_H

class PreciseSizedArrayList {
    private:
        int size;
        int* data;
    public:
        PreciseSizedArrayList();
        ~PreciseSizedArrayList();
        void add(int index, int value);
        void remove(int index);
        void changeValue(int index, int new_value);
        void reverse();
        double getAverageValue() const;
        void simulateJourney(int step_one, int step_two) const;
        void printList() const;
};
#endif