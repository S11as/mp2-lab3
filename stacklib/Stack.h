//
// Created by Kirill on 10/18/2020.
//

#ifndef STACKLIB_STACK_H
#define STACKLIB_STACK_H

#include <stdexcept>

template <class T>
class TStack {
protected:
    T** arr;
    int size = 1;
    int front = -1;
public:
    TStack(int size=1);
    TStack(const TStack<T>& stack);
    ~TStack();

    TStack<T>& operator=(const TStack<T>& stack);
    void push(T item);
    T pop();
    bool is_empty();
    bool is_full();
    T get_max();
    T get_least();
};

template<class T>
TStack<T>::TStack(int size) {
    if(size <= 0)
        throw std::range_error("Wrong stack size");
    this->size = size;
    this->arr = new T*[size];
    for (int i = 0; i < this->size; ++i) {
        this->arr[i] = 0;
    }
}

template<class T>
TStack<T>::TStack(const TStack<T> &stack) {
    if(this->size != stack.size){
        delete[] this->arr;
        this->size = stack.size;
        this->arr = new T*[stack.size];
    }
    this->front = stack.front;
    for (int i = 0; i < this->size; ++i) {
        this->arr[i] = new T(*stack.arr[i]);
    }
}

template<class T>
TStack<T>& TStack<T>::operator=(const TStack<T> &stack) {
    if(this == &stack)
        return *this;
    this->size = stack.size;
    delete[] this->arr;
    this->arr = new T*[stack.size];
    this->front = stack.front;
}

template<class T>
void TStack<T>::push(T item) {
    if(this->is_full()){
        throw std::overflow_error("Stack overflow");
    }
    this->front++;
    this->arr[this->front] = new T(item);
}

template<class T>
T TStack<T>::pop() {
    if(this->is_empty()){
        throw std::overflow_error("Stack is empty. Cant pop any value");
    }
    T res = *this->arr[this->front];
    delete arr[this->front];
    arr[this->front] = 0;
    this->front--;
    return res;
}

template<class T>
TStack<T>::~TStack() {
    delete [] this->arr;
    this->arr = nullptr;
}

template<class T>
bool TStack<T>::is_empty() {
    return this->front == -1;
}

template<class T>
bool TStack<T>::is_full() {
    return this->front+1 == this->size;
}

template<class T>
T TStack<T>::get_max() {
    if(this->is_empty())
        throw std::range_error("Stack is empty");

    T max = *this->arr[0];
    for (int i = 1; i < this->size; ++i) {
        T elem = *this->arr[i];
        if(elem>max)
            max = elem;
    }
    return max;
}

template<class T>
T TStack<T>::get_least() {
    if(this->is_empty())
        throw std::range_error("Stack is empty");

    T least = *this->arr[0];
    for (int i = 1; i < this->size; ++i) {
        T elem = *this->arr[i];
        if(elem<least)
            least = elem;
    }
    return least;
}


#endif //STACKLIB_STACK_H
