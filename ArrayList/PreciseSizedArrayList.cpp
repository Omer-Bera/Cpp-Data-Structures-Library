#include "PreciseSizedArrayList.h"
#include <iostream> // For printList and simulateJourney


#ifdef USE_STUDENT_CONSTRUCTOR_IMPL
/**
 * Constructor: Initializes an empty list.
 */
PreciseSizedArrayList::PreciseSizedArrayList()
{
    // YOUR CODE GOES HERE
    size = 0;
    data = nullptr;
}

#endif


#ifdef USE_STUDENT_DESTRUCTOR_IMPL
/**
 * Destructor: Frees (deletes) all dynamically allocated memory.
 */
PreciseSizedArrayList::~PreciseSizedArrayList()
{
    // YOUR CODE GOES HERE
    delete[] data;    
}
#endif


#ifdef USE_STUDENT_ADD_IMPL
/**
 * Don't forget to dynamically reallocate a new array of size (size + 1) and finally update the size variable.
 */
void PreciseSizedArrayList::add(int index, int value)
{
    // YOUR CODE GOES HERE
    int newSize = size + 1;

    if (index < 0)
        if (index < -1*newSize)
            return;
        else
            index += newSize;
    else if (index >= newSize)
        return;
    int *newArr = new int[newSize];
    for(int i = 0; i < index; ++i)
        newArr[i] = data[i];
    newArr[index] = value;
    for(int i = index; i < size; ++i)
        newArr[i+1] = data[i];
    delete [] data;
    data = newArr;
    size = newSize;
} 
#endif


#ifdef USE_STUDENT_REMOVE_IMPL
/**
 * Don't forget to dynamically reallocate a new array of size (size - 1), copy/shift the remaining elements, and finally update the size variable.
 */
void PreciseSizedArrayList::remove(int index)
{
    // YOUR CODE GOES HERE
    if(size == 0)
        return;

    int newSize = size-1;

    if (newSize == 0) {
    delete[] data;
    data = nullptr;
    size = 0;
    return;
}
    if (index < 0)
        if (index < -1*size)
            return;
        else
            index += size;
    else if (index >= size)
        return;
    int *newArr = new int[newSize];
    for(int i = 0; i < index; i++)
        newArr[i] = data[i];
    for(int i = index; i < newSize; i++)
        newArr[i] = data[i+1];
    delete [] data;
    data = newArr;
    size = newSize;
}
#endif


#ifdef USE_STUDENT_CHANGE_IMPL
/**
 * Changes the value at a specific index.
 */
void PreciseSizedArrayList::changeValue(int index, int new_value)
{
    // YOUR CODE GOES HERE
    if(size == 0)
        return;
    if (index < 0)
        if (index < -1*size)
            return;
        else
            index += size;
    else if (index >= size)
        return;
    data[index] = new_value;
}
#endif


#ifdef USE_STUDENT_REVERSE_IMPL
/**
 * Reverses the elements of the list.
 */
void PreciseSizedArrayList::reverse()
{
    // YOUR CODE GOES HERE
    int pivot = size/2;
        for(int i = 0; i < pivot; i++){
            int j = size-(1+i);
            data[i] = data[i] + data[j];
            data[j] = data[i] - data[j];
            data[i] = data[i] - data[j];
        }
}
#endif


#ifdef USE_STUDENT_AVERAGE_IMPL
/**
 * Calculates the average of all values in the list.
 * Returns the average as a double, or 0.0 if the list is empty.
 */
double PreciseSizedArrayList::getAverageValue() const
{
    // YOUR CODE GOES HERE
    if(size == 0)
        return 0.0;
    long long sum = 0;
    for(int i = 0; i < size; i++)
        sum += data[i];
    return (double)sum/(double)size;
}
#endif


#ifdef USE_STUDENT_JOURNEY_IMPL
/**
 * Simulates a "journey" by stepping through the array.
 * Example Output:
Step 0: A1 at 0, A2 at 0
Step 1: A1 at 1, A2 at 2
Step 2: A1 at 2, A2 at 4
Step 3: A1 at 3, A2 at 0
Step 4: A1 at 4, A2 at 2
Step 5: A1 at 5, A2 at 4
Step 6: A1 at 0, A2 at 0
 */
void PreciseSizedArrayList::simulateJourney(int step_one, int step_two) const
{
    // YOUR CODE GOES HERE
    if (size == 0) {
        std::cout << "List is empty." << std::endl;
        return;
    }
    int p_a1 = 0;
    int p_a2 = 0;
    int *p1 = &p_a1;
    int *p2 = &p_a2;
    int step = 0;
    auto output = [p1,p2](int step_n){
        std::cout << "Step " << step_n << ": A1 at " << *p1 << ", A2 at " << *p2 << std::endl;
    };
    output(step);
    do{
        p_a1 = (p_a1 + step_one) % size;
        p_a2 = (p_a2 + step_two) % size;
        output(++step);
    } while(p_a1 != p_a2);
    
}

#endif


#ifdef USE_STUDENT_PRINT_IMPL
/**
 * Prints the entire list to the console.
 * Example:
Index: 0, Value: 42
Index: 1, Value: 30
Index: 2, Value: 20
Index: 3, Value: 15
Index: 4, Value: 10
 */
void PreciseSizedArrayList::printList() const
{
    // YOUR CODE GOES HERE
    for(int i = 0; i < size; i++)
        std::cout<<"Index: " << i << ", Value: " << data[i] << std::endl;
}

#endif