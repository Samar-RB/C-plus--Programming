#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <stdexcept>
#include <initializer_list>

// Custom dynamic array implementation
template<typename T>
class Vector {
private:
    T *data_;
    size_t size_;
    size_t capacity_;
    void grow(size_t min_capacity);
public:
    Vector(); // Default constructor
    Vector(const Vector &other); // Copy constructor
    Vector &operator=(const Vector &other); // Assignment operator
    ~Vector(); // Destructor

    void push_back(const T &value); // Add element
    void pop_back(); // Remove last element
    size_t size() const; // Get size
    bool empty() const; // Check if empty

    T &operator[](size_t index); // Access element
    const T &operator[](size_t index) const; // Access element (const)

    void clear(); // Remove all elements
};



#endif
