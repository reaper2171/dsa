#include <bits/stdc++.h>
using namespace std;

Node* copyRandomList(Node* head) {
    Node* temp = head;
    while(temp!=NULL){
        Node* newNode = new Node(temp->val);
        Node* front = temp->next;
        temp->next = newNode;
        newNode->next = front;
        temp = front;
    }
    temp = head;
    while(temp!=NULL){
        if(temp->random == NULL)
            temp->next->random = NULL;
        else
            temp->next->random =temp->random->next;
        temp = temp->next->next;
    }
    Node* dummy = new Node(-1), *res = dummy;
    temp = head;
    while(temp!=NULL){
        res->next = temp->next;
        temp->next = temp->next->next;
        res = res->next;
        temp = temp->next;
    }
    return dummy->next;
}