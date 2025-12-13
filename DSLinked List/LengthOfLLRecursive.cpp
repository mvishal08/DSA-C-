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
//Recursive
int length(Node *head){
    if (head == NULL) {
        return 0;
    }
    int smallAns = length(head->next);
    return smallAns+1;
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
    int i;
    cin >> i;
    int data;
    cin >> data;

}