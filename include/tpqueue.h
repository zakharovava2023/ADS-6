// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
private:
    T* arr;
    int first, last, count;

public:
    TPQueue();
    ~TPQueue();
    bool isEmpty() const;
    bool isFull() const;
    void push(const T&);
    const T& pop();
};
template <typename T, int size>
TPQueue<T, size>::TPQueue() : first(0), last(0), count(0) {
        arr = new T[size];
    }
template <typename T, int size>
TPQueue<T, size>::~TPQueue() {
        delete[] arr;
    }
template <typename T, int size>
bool TPQueue<T, size>::isEmpty()const {
        return 0 == count;
    }
template <typename T, int size>
bool TPQueue<T, size>::isFull() const {
        return count == size;
    }
template <typename T, int size>
void TPQueue<T, size>::push(const T& value) {
        if (isFull()) {
            throw std::string("Full!");
        }
        int cur = first;
        while (cur != last && value.prior <= arr[cur].prior) {
            cur = (++cur) % size;
        }
        for (int i = last; i != cur; i = (size + i - 1) % size) {
            arr[i] = arr[(size + i - 1) % size];
        }
        count++;
        last = (last + 1) % size;
        arr[cur] = value;
    }
template <typename T, int size>
const T& TPQueue<T, size>::pop() {
        if (isEmpty()) {
            throw std::string("Empty!");
        }
        count--;
        return arr[(first++) % size];
    }
struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
