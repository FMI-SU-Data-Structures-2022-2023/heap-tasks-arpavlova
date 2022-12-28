#ifndef WEEK7_HEAP_H
#include <cassert>
size_t const MAX = 100;
template <class T>
class Heap {
private:
    T* array = nullptr;
    size_t size = 0;
    size_t MAXSIZE = MAX;

private:

    void clear()
    {
        delete array;
        array = nullptr;
        size = 0;
    }
   const size_t leftChildINdex(size_t index) const
    {
        return 2 * index + 1;
    }
    const size_t rightChildIndex(size_t index) const
    {
        return 2 * index + 2;
    }

    const int parentIndex(size_t index) const
    {
        if(index > 0)
          return (index - 1) / 2;

        return -1;
    }
    void heapifyUp(size_t i, size_t largest)
    {
        if (i < 0) { return; }
        size_t left = leftChildINdex(i);
        size_t right = rightChildIndex(i);

        if (left < size && array[left] > array[i])
        {
            largest = left;
        }
        else { largest = i; }
        if (right < size && array[right] > array[largest])
        {
            largest = right;
        }

        if (largest != i)
        {
            T buff(array[i]);
            array[i] = array[largest];
            array[largest] = buff;
        }
        int next = --i;
        heapifyUp(next, next);
    }

    void heapifyDown(int i, size_t smallest)
    {
        if (i < 0) { return; }
        size_t left = leftChildINdex(i);
        size_t right = rightChildIndex(i);

        if (left < size && array[left] < array[i])
        {
            smallest = left;
        }
        else { smallest = i; }
        if (right < size && array[right] < array[smallest])
        {
            smallest = right;
        }

        if (smallest != i)
        {
            T buff(array[i]);
            array[i] = array[smallest];
            array[smallest] = buff;
        }
        int next = --i;
        heapifyDown(next, next);
    }
public:
    Heap() = default;
    const T& getTop() const
    {
        if (size)
            return array[0];
        else
            throw std::out_of_range("no present elements");
    }
    void insert(T key) 
    {
        if (!array)
        {
            array = new T[MAX];
        }
        if (size + 1 > MAXSIZE)
        {
            MAXSIZE *= 2;
            T* buff = new T[MAXSIZE];
            for (size_t i = 0; i < size; i++)
                buff[i] = array[i];
            delete array;
            array = buff;
        }
        array[size] = key;
        ++size;
        int pos = (size-2)/2;
        heapifyDown(pos, pos);
    };
    void removeTop() 
    {
        if (size)
        {
            T buff(array[size - 1]);
            array[size-1] = array[0];
            array[0] = buff;
            size--;
            int pos = (size - 2) / 2;
            heapifyDown(pos, pos);
        }
        else
            throw std::out_of_range("no present elements");

    };
    bool isEmpty() 
    {
        return !size;
    };
    Heap& operator=(const Heap<T>& other)
    {
        clear();
        size_t otherSize = other.size;
        array = new T[otherSize];
        for (size_t i = 0; i < otherSize; ++i)
        {
            array[i] = other.array[i];
        }
        size = otherSize;

    }
    ~Heap() 
    {
        clear();
    };
};

#define WEEK7_HEAP_H

#endif //WEEK7_HEAP_H
