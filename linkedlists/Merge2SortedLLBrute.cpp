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

Node* mergeLL(Node* h1, Node* h2){
    Node* res = new Node(0);
    Node* temp = res;
    Node *t1=h1, *t2=h2;
    while(t1!=NULL && t2!=NULL){
        if(t1->data < t2->data){
            temp->next = new Node(t1->data);
            temp=temp->next;
            t1=t1->next;
        }
        else{
            temp->next = new Node(t2->data);
            temp=temp->next;
            t2=t2->next;
        }
    }
    while(t1!=NULL){
        temp->next = new Node(t1->data);
        temp=temp->next;
        t1=t1->next;
    }
    while(t2!=NULL){
        temp->next = new Node(t2->data);
        temp=temp->next;
        t2=t2->next;
    }
    return res->next;
}

int main(){
    Node* head1 = new Node(3);
    head1->next = new Node(4);
    head1->next->next = new Node(8);
    head1->next->next->next = new Node(10);

    Node* head2 = new Node(5);
    head2->next = new Node(7);
    head2->next->next = new Node(9);

    Node* merged = mergeLL(head1, head2);

    while(merged!=NULL){
        cout<<merged->data<<"      ";
        merged=merged->next;
    }
    return 0;
}