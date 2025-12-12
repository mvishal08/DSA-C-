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

int length(Node *head){
    int count = 0;
    while(head){
        count++;
        head = head->next;
    }
    return count;
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

int targetF(Node *head, int i) {

    int index = 0;
    while (head != NULL) {
        if (index == i) {
            return head->data;
        }
        head = head->next;
        index++;
    }
    return -1;
}

Node* Insertati(Node *head, int i, int data) {

    int n = length(head);
    if (i<0 ) {
        return head;
    }
    if (i==0) {

        Node *newNode = new Node(data);
        newNode->next = head;
        return newNode;
    }
    Node * copyHead = head;
    int count = 1;
    while(count<=i-1 && head!=NULL){
        head = head->next;
        count++;
    }
    if (head != NULL) {
        Node *newNode = new Node(data);
        newNode->next = head->next;
        head->next = newNode;
    }
    return copyHead;
}
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
//Memory leak and no memort leak
Node* deletei(Node* head, int i) {
    int n = length(head);
    if (i<0 ) {
        return head;
    }
    /*if (i==0) {
        return head->next;(Memory leak)
    }*/
    if(i==0 && head){
        Node* newHead = head->next;
        head->next = NULL;
        delete head;
        return newHead;
    }

    Node * copyHead = head;
    int count = 1;
    while(count<=i-1 && head!=NULL){
        head = head->next;
        count++;
    }
    if (head && head->next != NULL) {
        //head->next = head->next->next;(memory leak)
        Node *temp = head->next;
        head->next = head->next->next;
        temp->next=NULL;
        delete temp;
        return head;
    }
    return copyHead;
}

int main() {


    Node* head = takeInput();
    int i;
    cin >> i;
    int data;
    cin >> data;
    head = deletei(head, i);
    printList(head);
}
