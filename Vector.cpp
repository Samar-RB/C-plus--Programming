#include "Vector.h"
#include <algorithm>
#include "Card.h"

// Grow the vector to at least min_capacity
template<typename T>
void Vector<T>::grow(size_t min_capacity) {
    size_t new_cap = (capacity_ == 0) ? 1 : capacity_ + (capacity_ / 2) + 1;
    if (new_cap < min_capacity) new_cap = min_capacity;
    T *new_data = new T[new_cap];
    for (size_t i = 0; i < size_; ++i)
        new_data[i] = data_[i];
    delete[] data_;
    data_ = new_data;
    capacity_ = new_cap;
}

// Default constructor
template<typename T>
Vector<T>::Vector() : data_(nullptr), size_(0), capacity_(0) {}

// Copy constructor
template<typename T>
Vector<T>::Vector(const Vector &other)
    : data_(nullptr), size_(0), capacity_(0) {
    if (other.size_ > 0) {
        data_ = new T[other.capacity_];
        capacity_ = other.capacity_;
        size_ = other.size_;
        for (size_t i = 0; i < size_; ++i)
            data_[i] = other.data_[i];
    }
}

// Assignment operator
template<typename T>
Vector<T> &Vector<T>::operator=(const Vector &other) {
    if (this == &other)
        return *this;
    delete[] data_;
    data_ = nullptr;
    size_ = 0;
    capacity_ = 0;
    if (other.size_ > 0) {
        data_ = new T[other.capacity_];
        capacity_ = other.capacity_;
        size_ = other.size_;
        for (size_t i = 0; i < size_; ++i)
            data_[i] = other.data_[i];
    }
    return *this;
}

// Destructor
template<typename T>
Vector<T>::~Vector() {
    delete[] data_;
}

// Add element to end
template<typename T>
void Vector<T>::push_back(const T &value) {
    if (size_ + 1 > capacity_)
        grow(size_ + 1);
    data_[size_++] = value;
}

// Remove last element
template<typename T>
void Vector<T>::pop_back() {
    if (size_ == 0)
        return;
    --size_;
}

// Get size
template<typename T>
size_t Vector<T>::size() const { return size_; }

// Check if empty
template<typename T>
bool Vector<T>::empty() const { return size_ == 0; }

// Access element
template<typename T>
T &Vector<T>::operator[](size_t index) {
    // No exception: return first element if out of bounds
    if (index >= size_ || size_ == 0)
        return data_[0];
    return data_[index];
}

// Access element (const)
template<typename T>
const T &Vector<T>::operator[](size_t index) const {
    // No exception: return first element if out of bounds
    if (index >= size_ || size_ == 0)
        return data_[0];
    return data_[index];
}

// Remove all elements
template<typename T>
void Vector<T>::clear() {
    size_ = 0;
}

// Explicit instantiation for Card
template class Vector<Card>;
