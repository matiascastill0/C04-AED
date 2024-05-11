#include <iostream>
using namespace std;

class MyCircularDeque {
private:
    int *arr;
    int front, rear, size, capacity;

public:
    MyCircularDeque(int k) {
        capacity = k;
        arr = new int[k];
        front = -1;
        rear = 0;
        size = 0;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else if (front == 0) {
            front = capacity - 1;
        } else {
            front--;
        }
        arr[front] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else if (rear == capacity - 1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = value;
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            if (front == capacity - 1) {
                front = 0;
            } else {
                front++;
            }
        }
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (rear == 0) {
            rear = capacity - 1;
        } else {
            rear--;
        }
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

int main() {
    MyCircularDeque* obj = new MyCircularDeque(3);
    cout << obj->insertLast(1) << endl; // todo true
    cout << obj->insertLast(2) << endl; // todo true
    cout << obj->insertFront(3)<<endl; // todo   true
    cout << obj->insertFront(4)<<endl; // todo    false
    cout << obj->getRear()<<endl; // todo     retorna 2
    cout<<obj->isFull()<<endl; // todo retorna true
    cout<<obj->deleteLast()<<endl; // todo retorna true
    cout << obj->insertFront(4)<<endl; // todo     true
    cout << obj->getFront()<<endl; // todo     true


    return 0;
}