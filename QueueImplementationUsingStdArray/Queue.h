#include <array>
#include <stdexcept>

template <typename T, int Size>
class Queue {
private:
    std::array<T, Size> arr;
    int front, end, count;

public:
    Queue() : front(0), end(-1), count(0) {}

    void enqueue(T value) {
        if (count == Size) throw std::overflow_error("Queue is full");
        end = (end + 1) % Size;
        arr[end] = value;
        count++;
    }

    T dequeue() {
        if (count == 0) throw std::underflow_error("Queue is empty");
        T value = arr[front];
        front = (front + 1) % Size;
        count--;
        return value;
    }

    T peek() {
        if (count == 0) throw std::underflow_error("Queue is empty");
        return arr[front];
    }

    bool isEmpty() {
        return count == 0;
    }

    int size() {
        return count;
    }
};

