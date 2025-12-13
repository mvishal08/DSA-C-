#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

//Recursion
bool findElement(Node *head, int data) {
    if (head == NULL) {
        return false;
    }
    if (head->data == data) {
        return true;
    }
    return findElement(head->next, data);
}

Node* takeInput() {

    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1) {
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}


int main() {


    Node* head = takeInput();

    int data;
    cin >> data;

    if (findElement(head, data)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

}