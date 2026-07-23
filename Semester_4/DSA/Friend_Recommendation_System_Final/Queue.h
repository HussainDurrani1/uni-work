using namespace std;
#pragma once

template <typename T>
class Queue {
private:
    T*   data;       
    int  frontIdx;   
    int  backIdx;    
    int  count;      
    int  capacity;   

    
    void resize() {
        int   newCap  = capacity * 2;
        T*    newData = new T[newCap];

        
        for (int i = 0; i < count; i++) {
            newData[i] = data[(frontIdx + i) % capacity];
        }

        delete[] data;
        data     = newData;
        frontIdx = 0;
        backIdx  = count;
        capacity = newCap;
    }

public:
    
    Queue(int initialCapacity = 16)
        : frontIdx(0), backIdx(0), count(0), capacity(initialCapacity) {
        data = new T[capacity];
    }

    ~Queue() { delete[] data; }

    
    Queue(const Queue&)            = delete;
    Queue& operator=(const Queue&) = delete;

    
    bool isEmpty() const { return count == 0; }
    int  size()    const { return count; }

    
    void enqueue(const T& value) {
        if (count == capacity) resize();
        data[backIdx] = value;
        backIdx       = (backIdx + 1) % capacity;
        count++;
    }

    
    void dequeue() {
        if (isEmpty()) return;   
        frontIdx = (frontIdx + 1) % capacity;
        count--;
    }

    
    T& front() {
        return data[frontIdx];
    }

    const T& front() const {
        return data[frontIdx];
    }
};
