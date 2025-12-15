#include <bits/stdc++.h>
using namespace std;
//using array
class Stack {
    int* arr;
    int nextIndex;
    int capacity;

public:
    Stack(int cap = 10) {
        capacity = cap;
        arr = new int[capacity];
        nextIndex = 0;
    }

    int size() {
        return nextIndex;
    }

    bool isEmpty() {
        return nextIndex == 0;
    }

    void push(int val) {
        //dynamic stack
        if (nextIndex == capacity) {
            int *newArr = new int[2*capacity];
            for(int i=0;i<capacity;i++){
                newArr[i] = arr[i];
            }
            delete []arr;
            arr = newArr;
            capacity = 2*capacity;

        }
        arr[nextIndex++] = val;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow\n";
            return;
        }
        nextIndex--;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[nextIndex - 1];
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.top() << endl;   // 30
    s.pop();
    cout << s.top() << endl;   // 20

    cout << s.size() << endl;  // 2

    return 0;
}
