// Integrantes:
// 202120533 - Aldair Seminario Sanchez
// 202210081 - Matias Castillo Quincho
// 202220226 - Renzo Felix Aponte
// 202220354 - Jefri Vargas Fernandez


#include <iostream>
#include <queue>
#include <stack>
#include <utility>

// Ejercicio 1: Implementación de una pila utilizando dos colas
class MyStack {
private:
    std::queue<int> q1;
    std::queue<int> q2;

public:
    MyStack() {}

    void push(int x) {
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop() {
        if (empty()) return -1; // Pila vacía
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }

    int top() {
        if (empty()) return -1; // Pila vacía
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

void ejecutarEjercicio1() {
    MyStack* myStack = new MyStack();
    myStack->push(1);
    myStack->push(2);
    std::cout << myStack->top() << std::endl;    // Retorna 2
    std::cout << myStack->pop() << std::endl;    // Retorna 2
    std::cout << myStack->empty() << std::endl;  // Retorna 0
    delete myStack;
}

// Ejercicio 2: Implementación de un deque circular
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

void ejecutarEjercicio2() {
    MyCircularDeque* obj = new MyCircularDeque(3);
    std::cout << obj->insertLast(1) << std::endl;   // true
    std::cout << obj->insertLast(2) << std::endl;   // true
    std::cout << obj->insertFront(3) << std::endl;  // true
    std::cout << obj->insertFront(4) << std::endl;  // false
    std::cout << obj->getRear() << std::endl;       // 2
    std::cout << obj->isFull() << std::endl;        // true
    std::cout << obj->deleteLast() << std::endl;    // true
    std::cout << obj->insertFront(4) << std::endl;  // true
    std::cout << obj->getFront() << std::endl;      // 4
    delete obj;
}

// Ejercicio 3: Implementación de una pila con seguimiento de mínimos
class MinStack {
private:
    std::stack<std::pair<int, int>> s;

public:
    MinStack() {}

    void push(int val) {
        if (s.empty() || s.top().second >= val) {
            s.push(std::make_pair(val, val));
        } else {
            s.push(std::make_pair(val, s.top().second));
        }
    }

    void pop() {
        if (!s.empty()) {
            s.pop();
        }
    }

    int top() {
        if (!s.empty()) {
            return s.top().first;
        }
        return -1;
    }

    int getMin() {
        if (!s.empty()) {
            return s.top().second;
        }
        return -1;
    }
};

void ejecutarEjercicio3() {
    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    std::cout << minStack->getMin() << std::endl;  // -3
    minStack->pop();
    std::cout << minStack->top() << std::endl;    // 0
    std::cout << minStack->getMin() << std::endl; // -2
    delete minStack;
}

// Función principal para seleccionar ejercicio
int main() {
    int opcion;
    std::cout << "Selecciona el ejercicio a ejecutar (1, 2 o 3): ";
    std::cin >> opcion;

    switch (opcion) {
        case 1:
            ejecutarEjercicio1();
            break;
        case 2:
            ejecutarEjercicio2();
            break;
        case 3:
            ejecutarEjercicio3();
            break;
        default:
            std::cout << "Opción no válida." << std::endl;
            break;
    }

    return 0;
}
