#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* dummy = new Node(0);
    Node* curr = dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;

        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        curr->next = new Node(sum % 10);
        curr = curr->next;
    }

    Node* result = dummy->next;
    delete dummy;
    return result;
}

Node* createList(const vector<int>& v) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int x : v) {
        Node* node = new Node(x);
        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << '\n';
}

void deleteList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    vector<int> v1 = {1, 0, 2};
    vector<int> v2 = {9, 9};

    Node* l1 = createList(v1);
    Node* l2 = createList(v2);

    Node* result = addTwoNumbers(l1, l2);

    printList(result);

    deleteList(l1);
    deleteList(l2);
    deleteList(result);

    return 0;
}
