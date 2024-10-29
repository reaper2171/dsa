#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node* findMiddle(Node* head){
    cout<<"finding middle of the linkedlist"<<endl;
    Node *slow = head, *fast=head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"     ";
        temp = temp->next;
    }

    cout<<endl;
    Node* middle = findMiddle(head);
    cout<<middle->data<<endl;
    // while(head!=NULL){
    //     cout<<head->data<<"     ";
    //     head = head->next;
    // }
    // cout<<endl;
    return 0;
}