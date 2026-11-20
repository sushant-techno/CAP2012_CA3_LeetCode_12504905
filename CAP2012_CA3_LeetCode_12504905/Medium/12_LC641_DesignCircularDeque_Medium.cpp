// LeetCode 641 - Design Circular Deque
class MyCircularDeque {
    vector<int> data;
    int frontIndex, count, capacity;

public:
    MyCircularDeque(int k)
        : data(k), frontIndex(0), count(0), capacity(k) {}

    bool insertFront(int value) {
        if (isFull()) return false;
        frontIndex = (frontIndex - 1 + capacity) % capacity;
        data[frontIndex] = value;
        count++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        int rearIndex = (frontIndex + count) % capacity;
        data[rearIndex] = value;
        count++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        frontIndex = (frontIndex + 1) % capacity;
        count--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        count--;
        return true;
    }

    int getFront() {
        return isEmpty() ? -1 : data[frontIndex];
    }

    int getRear() {
        if (isEmpty()) return -1;
        int rearIndex = (frontIndex + count - 1) % capacity;
        return data[rearIndex];
    }

    bool isEmpty() { return count == 0; }
    bool isFull() { return count == capacity; }
};
