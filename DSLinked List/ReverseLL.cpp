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


void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* Reverse(Node* head) {
    Node*current = head;
    Node* prev = NULL;
    while(current != NULL) {
        Node* n = current;
        current->next = prev;
        prev = current;
        current =n;
    }
    return prev;
}
//T(o(n))
//S(o(1))

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

    Node* Rev = Reverse(head);
    PrintList(rev);

}
