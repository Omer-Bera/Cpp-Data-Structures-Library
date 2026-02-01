#include "PreciseSizedArrayList.h"
#include <iostream> // For printList
#include <iomanip>  // For printList

#ifdef USE_STUDENT_CONSTRUCTOR_IMPL
/**
 * Constructor: Initializes an empty list.
 * (QUIZ QUESTION 1)
 */
PreciseSizedArrayList::PreciseSizedArrayList()
{
    // YOUR CODE GOES HERE
    size = 0;
    data = nullptr;
}

#endif

#ifdef USE_STUDENT_REMOVE_IMPL 

/**
 * Removes the element at the specified value (first occurrence).
 * (QUIZ QUESTION 2)
 */
void PreciseSizedArrayList::removeByValue(int value)
{
    // YOUR CODE GOES HERE
    if(size != 0)
        for(int i = 0; i <size; ++i)
            if(data[i] == value){
                removeByIndex(i);
                break;
            }
                

}
#endif

#ifdef USE_STUDENT_HARMONIC_AVG_IMPL

/**
 * Calculates the harmonic average of all values in the list.
 * (QUIZ QUESTION 3)
 */
double PreciseSizedArrayList::getHarmonicAverage() const
{
    // YOUR CODE GOES HERE
    if(size == 0)
        return 0.0; // Placeholder

    for(int i = 0; i < size; ++i)
        if(data[i] == 0)
            return 0.0;

    double S = 0.0;

    for(int i = 0; i<size; i++)
        S += 1.0/data[i];
    return (double)size/S;


    
}

#endif

/**
 * Destructor: Frees (deletes) all dynamically allocated memory.
 * (PROVIDED)
 */
PreciseSizedArrayList::~PreciseSizedArrayList()
{
    delete[] data;
}

/**
 * Inserts a value at a specified index, reallocating the array.
 * (PROVIDED)
 */
void PreciseSizedArrayList::add(int index, int value)
{
    int resolved_index = index;
    // Handle negative indexing
    if (index < 0) resolved_index = size + index + 1;
    // Handle appending
    if (index == -1 || index == size) resolved_index = size;

    // Bounds check
    if (resolved_index < 0 || resolved_index > size) {
        return; // No effect if out of bounds
    }

    // Allocate new array
    int new_size = size + 1;
    int* new_data = new int[new_size];

    // Copy elements before the insertion point
    for (int i = 0; i < resolved_index; ++i) {
        new_data[i] = data[i];
    }
    
    // Insert new value
    new_data[resolved_index] = value;
    
    // Copy elements after the insertion point
    for (int i = resolved_index; i < size; ++i) {
        new_data[i + 1] = data[i];
    }

    // Deallocate old array, update pointers and size
    delete[] data;
    data = new_data;
    size = new_size;
}

/**
 * Removes the element at the specified index, reallocating the array.
 * (PROVIDED - Helper for removeByValue)
 */
void PreciseSizedArrayList::removeByIndex(int index)
{
    // Bounds check
    if (index < 0 || index >= size) {
        return; // No effect if out of bounds
    }

    int new_size = size - 1;

    // Handle case: removing the last element
    if (new_size == 0) {
        delete[] data;
        data = nullptr;
        size = 0;
        return;
    }

    // Allocate new array
    int* new_data = new int[new_size];
    
    // Copy elements before the removal point
    for (int i = 0; i < index; ++i) {
        new_data[i] = data[i];
    }
    
    // Copy elements after the removal point
    for (int i = index; i < new_size; ++i) {
        new_data[i] = data[i + 1];
    }

    // Deallocate old array, update pointers and size
    delete[] data;
    data = new_data;
    size = new_size;
}


/**
 * Changes the value at a specific index.
 * (PROVIDED)
 */
void PreciseSizedArrayList::changeValue(int index, int new_value)
{
    int resolved_index = index;
    if (index < 0) resolved_index = size + index; // e.g., -1 becomes size - 1

    // Check bounds
    if (resolved_index >= 0 && resolved_index < size) {
        data[resolved_index] = new_value;
    }
}

/**
 * Reverses the elements of the list in-place.
 * (PROVIDED)
 */
void PreciseSizedArrayList::reverse()
{
    int left = 0;
    int right = size - 1;
    while (left < right) {
        // Swap elements
        int temp = data[left];
        data[left] = data[right];
        data[right] = temp;
        // Move pointers
        left++;
        right--;
    }
}


/**
 * Prints the entire list to the console.
 * (PROVIDED)
 */
void PreciseSizedArrayList::printList() const
{
    for (int i = 0; i < size; ++i) {
        std::cout << "Index: " << i << ", Value: " << data[i] << std::endl;
    }
    std::cout << std::endl; // New line after printing
}