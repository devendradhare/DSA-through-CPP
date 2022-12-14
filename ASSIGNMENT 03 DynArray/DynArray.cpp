//                          Assignment-3: Dynamic Arrays

class DynArray
{
private:
    int capacity;        // 1.  Define a class DynArray to implement dynamic array data structure with member
    int last_index = -1; //     variables to store capacity of array, last index of the last filled block of the array and
    int *ptr;            //     a pointer to hold the address of the first block of the dynamically created array.

public:
    DynArray(int Array_size);                             // 2.  In question 1, define a parameterised constructor to create an array of specified size.
    void doubleArray();                                   // 3.  In question 1, define a method doubleArray() to increase the size of the array by double of its size.
    void halfArray();                                     // 4.  In question 1, define a method halfArray() to decrease the size of the array by half of its size.
    int get_capacity() { return capacity; }               // 5.  In question 1, define a method which returns the current capacity of the array.
    bool is_empty() { return last_index == -1; }          // 6.  In question 1, add a method to check whether an array is empty or not by returning True or False.
    void append(int);                                     // 7.  In question 1, define a method to append a new element in the array
    void insert(int, int);                                // 8.  In question 1, define a method to insert a new element at specified index
    void edit(int, int);                                  // 9.  In question 1, define a method to edit an element at specified index.
    void delete_elm(int);                                 // 10. In question 1, define a method to delete an element at specified index.
    bool is_full() { return last_index + 1 == capacity; } // 11. In question 1, define a method to check if the array is full by returning true or false.
    int get_element(int);                                 // 12. In question 1, define a method to get element at specified index.
    int total_element() { return last_index + 1; }        // 13. In question 1, define a method to count number of elements present in the array.
    ~DynArray();                                          // 14. In question 1, define a destructor to deallocate the memory of array.
    int find(int);                                        // 15. In question 1, define a method to find an element in the array. Return index if the element found, otherwise return -1 .
    void show_Array();
};
DynArray::DynArray(int Array_size)
{
    ptr = new int[Array_size];
    capacity = Array_size;
}
void DynArray::doubleArray()
{
    int *newPtr = new int[capacity *= 2];
    for (int i = 0; i < capacity; i++)
        newPtr[i] = ptr[i];
    delete[] ptr;
    ptr = newPtr;
}
void DynArray::halfArray()
{
    int *newPtr = new int[capacity /= 2];
    for (int i = 0; i < capacity; i++)
        newPtr[i] = ptr[i];
    delete[] ptr;
    ptr = newPtr;
}
void DynArray::append(int element)
{
    if (last_index == capacity - 1)
        doubleArray();
    ptr[++last_index] = element;
}
void DynArray::show_Array()
{
    std::cout << "\n";
    for (int i = 0; i <= last_index; i++)
        std::cout << " " << ptr[i];
    std::cout << "\t\t capacity = " << capacity;
    std::cout << " last index = " << last_index;
}
void DynArray::insert(int index, int element)
{
    if (last_index == capacity - 1)
        doubleArray();
    if (index < 0)
    {
        std::cout << "\n<insert : Invalid index>";
        return;
    }
    if (index > last_index)
        append(element);
    for (int i = last_index; i >= index; i--)
        ptr[i + 1] = ptr[i];
    last_index++;
    ptr[index] = element;
}
void DynArray::edit(int index, int element)
{
    if (index > last_index || index < 0)
        std::cout << "\n<edit : Invalid index>";
    else
        ptr[index] = element;
}
void DynArray::delete_elm(int index)
{
    if (index < 0 || index > last_index)
    {
        std::cout << "\n<delete_elm : Invalid index>";
        return;
    }
    for (int i = index; i < last_index; i++)
    {
        ptr[i] = ptr[i + 1];
    }
    last_index--;
    if (last_index + 1 == capacity / 2 && capacity > 1)
        halfArray();
}
int DynArray::get_element(int index)
{
    if (index < 0 || index > last_index)
    {
        std::cout << "\n<get element : Invalid index>";
        return 0;
    }
    return ptr[index];
}
int DynArray::find(int element)
{
    for (int i = 0; i <= last_index; i++)
        if (ptr[i] == element)
            return i;
    return -1;
}
DynArray::~DynArray()
{
    delete[] ptr;
}