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
    else if(head->next->next == NULL){
        Node* temp = head;
        head = head->next;
        head->next = temp;
        return head;
    }
    else{
        Node *temp = head, *prev = NULL;
        while(temp != NULL){
            Node* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
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