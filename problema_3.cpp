#include <stack>
#include "iostream"
using namespace std;

class MinStack {
private:
    stack<pair<int, int>> s;

public:

    MinStack() {}


    void push(int val) {

        if (s.empty() || s.top().second >= val) {
            s.push(make_pair(val, val));
        } else {

            s.push(make_pair(val, s.top().second));
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
int main() {
    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    cout<<minStack->getMin()<<endl; // todo  return -3
    minStack->pop();
    cout<<minStack->top()<<endl; // todo  return 0
   cout<< minStack->getMin()<<endl; //  todo return -2
}