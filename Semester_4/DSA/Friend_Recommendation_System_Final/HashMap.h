#pragma once
#include "LinkedList.h"

using namespace std;

template <typename K, typename V>
class HashMap {
public:
    
    struct KeyValue {
        K key;
        V value;
        KeyValue() {}
        KeyValue(const K& k, const V& v) : key(k), value(v) {}
        
        bool operator==(const KeyValue& other) const { return key == other.key; }
    };

private:
    LinkedList<KeyValue>* buckets;   
    int   bucketCount;
    int   itemCount;

    
    
    int hashKey(int key) const {
        
        unsigned int uk = (unsigned int)key;
        return (int)((uk * 2654435761u) % (unsigned int)bucketCount);
    }

    
    int hashKey(const string& key) const {
        
        unsigned long hash = 5381;
        for (char c : key)
            hash = ((hash << 5) + hash) + (unsigned char)c;
        return (int)(hash % (unsigned int)bucketCount);
    }

    
    template <typename AnyK>
    int hashKey(const AnyK& key) const {
        return 0;
    }

    
    
    void rehash() {
        int   oldCount   = bucketCount;
        bucketCount      = bucketCount * 2;
        LinkedList<KeyValue>* newBuckets = new LinkedList<KeyValue>[bucketCount];

        for (int i = 0; i < oldCount; i++) {
            typename LinkedList<KeyValue>::Node* cur = buckets[i].getHead();
            while (cur) {
                int idx = hashKey(cur->data.key);
                newBuckets[idx].pushBack(cur->data);
                cur = cur->next;
            }
        }

        delete[] buckets;
        buckets = newBuckets;
    }

public:
    
    HashMap(int initialBuckets = 16) : bucketCount(initialBuckets), itemCount(0) {
        buckets = new LinkedList<KeyValue>[bucketCount];
    }

    ~HashMap() { delete[] buckets; }

    
    HashMap(const HashMap& other) : bucketCount(other.bucketCount), itemCount(0) {
        buckets = new LinkedList<KeyValue>[bucketCount];
        for (int i = 0; i < bucketCount; i++)
            buckets[i] = other.buckets[i];
        itemCount = other.itemCount;
    }

    HashMap& operator=(const HashMap& other) {
        if (this == &other) return *this;
        delete[] buckets;
        bucketCount = other.bucketCount;
        itemCount   = 0;
        buckets     = new LinkedList<KeyValue>[bucketCount];
        for (int i = 0; i < bucketCount; i++)
            buckets[i] = other.buckets[i];
        itemCount = other.itemCount;
        return *this;
    }

    
    
    
    void insert(const K& key, const V& value) {
        
        if (itemCount > 0 && (float)itemCount / bucketCount >= 0.75f)
            rehash();

        int idx = hashKey(key);
        typename LinkedList<KeyValue>::Node* cur = buckets[idx].getHead();
        while (cur) {
            if (cur->data.key == key) {
                cur->data.value = value;   
                return;
            }
            cur = cur->next;
        }
        
        buckets[idx].pushBack(KeyValue(key, value));
        itemCount++;
    }

    
    
    V* get(const K& key) {
        int idx = hashKey(key);
        typename LinkedList<KeyValue>::Node* cur = buckets[idx].getHead();
        while (cur) {
            if (cur->data.key == key) return &cur->data.value;
            cur = cur->next;
        }
        return nullptr;
    }

    const V* get(const K& key) const {
        int idx = hashKey(key);
        typename LinkedList<KeyValue>::Node* cur = buckets[idx].getHead();
        while (cur) {
            if (cur->data.key == key) return &cur->data.value;
            cur = cur->next;
        }
        return nullptr;
    }

    
    
    bool contains(const K& key) const {
        return get(key) != nullptr;
    }

    
    V& operator[](const K& key) {
        if (!contains(key)) insert(key, V());
        return *get(key);
    }

    
    
    bool remove(const K& key) {
        int idx = hashKey(key);
        typename LinkedList<KeyValue>::Node* cur = buckets[idx].getHead();
        while (cur) {
            if (cur->data.key == key) {
                buckets[idx].remove(cur->data);
                itemCount--;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    
    int  size()    const { return itemCount; }
    bool isEmpty() const { return itemCount == 0; }

    
    
    
    
    void getAllEntries(KeyValue** out, int& outCount) const {
        outCount = 0;
        for (int i = 0; i < bucketCount; i++) {
            typename LinkedList<KeyValue>::Node* cur = buckets[i].getHead();
            while (cur) {
                out[outCount++] = &cur->data;
                cur = cur->next;
            }
        }
    }

    int getBucketCount() const { return bucketCount; }

    
    LinkedList<KeyValue>* getBuckets() const { return buckets; }
};
