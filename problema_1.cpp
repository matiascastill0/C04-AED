#include <queue>
#include "iostream"
using namespace  std;
class MyStack {
private:
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {
    }

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
int main() {
    MyStack *myStack = new MyStack();
    myStack->push(1);
    myStack->push(2);
    cout<<myStack->top()<<endl;// todo retorna 2
    cout<<myStack->pop()<<endl; // todo retorna 2
    cout<<myStack->empty()<<endl;//  todo  retornara 0
}