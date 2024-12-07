#include <iostream>
using namespace std;

template <class T>
class vector {
    T *arr;
    int size;
    int capacity;

public:
    // Constructor
    vector(int initialCapacity = 10) {
        arr = new T[initialCapacity];
        size = 0;
        capacity = initialCapacity;
    }

    // Copy Constructor
    vector(const vector& other) {
        arr = new T[other.capacity];
        size = other.size;
        capacity = other.capacity;
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    // Move Constructor
    vector(vector&& other) {
        arr = other.arr;
        size = other.size;
        capacity = other.capacity;
        other.arr = nullptr;
    }

    // Destructor
    ~vector() {
        delete[] arr;
    }

    // Assignment Operator
    vector& operator=(const vector& other) {
        if (this != &other) {
            delete[] arr;
            arr = new T[other.capacity];
            size = other.size;
            capacity = other.capacity;
            for (int i = 0; i < size; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    // Move Assignment Operator
    vector& operator=(vector&& other) {
        if (this != &other) {
            delete[] arr;
            arr = other.arr;
            size = other.size;
            capacity = other.capacity;
            other.arr = nullptr;
        }
        return *this;
    }

    // Add element to the end of the vector
    void push_back(const T& element) {
        if (size == capacity) {
            capacity *= 2;
            T* temp = new T[capacity];
            for (int i = 0; i < size; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
        }
        arr[size++] = element;
    }

    // Get element at index
    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    // Get size of the vector
    int getSize() const {
        return size;
    }

    // Get capacity of the vector
    int getCapacity() const {
        return capacity;
    }
};

int main() {
    vector<int> myVec1;
    vector<float> myVec2;

    myVec1.push_back(10);
    myVec1.push_back(20);
    myVec1.push_back(30);

    myVec2.push_back(10.5f);
    myVec2.push_back(20.5f);
    myVec2.push_back(30.5f);

    std::cout << "Size of myVec1: " << myVec1.getSize() << std::endl;
    std::cout << "Capacity of myVec1: " << myVec1.getCapacity() << std::endl;

    std::cout << "Size of myVec2: " << myVec2.getSize() << std::endl;
    std::cout << "Capacity of myVec2: " << myVec2.getCapacity() << std::endl;

    return 0;
}