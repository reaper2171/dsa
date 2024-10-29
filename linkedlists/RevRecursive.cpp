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

Node* revLL(Node* head){
    cout<<"After reversing the linked list, we get:-"<<endl;
    if(head == NULL || head->next == NULL)
        return head;
    Node* newHead = revLL(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
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
    head = revLL(head);

    while(head!=NULL){
        cout<<head->data<<"     ";
        head = head->next;
    }
    cout<<endl;
    return 0;
}