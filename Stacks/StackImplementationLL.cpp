#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T data) {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Stack {
    Node<T>* head;
    int size;

public:
    Stack() {
        head = NULL;
        size = 0;
    }

    // Destructor to avoid memory leak
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void push(T ele) {
        Node<T>* n = new Node<T>(ele);
        n->next = head;
        head = n;
        size++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow, Cannot pop." << endl;
            return;
        }

        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    T top() const {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return T();   // default value of type T
        }
        return head->data;
    }
};

int main() {
    Stack<int> s;

    cout << "Pushing elements" << endl;
    s.push(5);
    s.push(15);
    s.push(25);

    cout << "Top element: " << s.top() << endl;
    cout << "Stack size: " << s.getSize() << endl;

    s.pop();
    cout << "Top after pop: " << s.top() << endl;

    s.pop();
    s.pop();
    s.pop();  // underflow case

    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
