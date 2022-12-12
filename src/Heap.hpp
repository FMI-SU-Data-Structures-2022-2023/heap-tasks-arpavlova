#ifndef WEEK7_HEAP_H

template <class T>
class Heap {
private:
    T* array;
public:
    const T& getTop() {
        return -1;
    }
    void insert(T key) {};
    void removeTop() {};
    bool isEmpty() {
        return false;
    };
    Heap& operator=(const Heap<T>& other) = delete;
    ~Heap() {};
};

#define WEEK7_HEAP_H

#endif //WEEK7_HEAP_H
