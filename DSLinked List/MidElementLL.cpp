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


//slow and fast pointer
Node* findMid(Node* head) {
    Node* slow = head;
    Node* fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    //even
    if (fast!= NULL) {
        return slow->next;
    }
    //odd
    return slow; // odd
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

    Node* midElement = findMid(head);
    cout << midElement->data << endl;

}