using namespace std;
#pragma once

template <typename T>
class DynamicArray {
private:
    T*  data;
    int count;
    int capacity;

    void resize() {
        capacity    = capacity * 2;
        T* newData  = new T[capacity];
        for (int i = 0; i < count; i++)
            newData[i] = data[i];
        delete[] data;
        data = newData;
    }

public:
    
    DynamicArray(int initialCapacity = 8)
        : count(0), capacity(initialCapacity) {
        data = new T[capacity];
    }

    ~DynamicArray() { delete[] data; }

    
    DynamicArray(const DynamicArray& other) : count(other.count), capacity(other.capacity) {
        data = new T[capacity];
        for (int i = 0; i < count; i++)
            data[i] = other.data[i];
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) return *this;
        delete[] data;
        count    = other.count;
        capacity = other.capacity;
        data     = new T[capacity];
        for (int i = 0; i < count; i++)
            data[i] = other.data[i];
        return *this;
    }

    
    void pushBack(const T& value) {
        if (count == capacity) resize();
        data[count++] = value;
    }

    
    T& operator[](int index)             { return data[index]; }
    const T& operator[](int index) const { return data[index]; }

    
    int  size()    const { return count; }
    bool isEmpty() const { return count == 0; }

    
    void clear() { count = 0; }

    
    
    
    
    
    template <typename Comparator>
    void sortDescending(Comparator comparator) {
        for (int i = 0; i < count - 1; i++) {
            int bestIdx = i;
            for (int j = i + 1; j < count; j++) {
                if (comparator(data[j], data[bestIdx]))
                    bestIdx = j;
            }
            if (bestIdx != i) {
                T tmp        = data[i];
                data[i]      = data[bestIdx];
                data[bestIdx]= tmp;
            }
        }
    }
};
