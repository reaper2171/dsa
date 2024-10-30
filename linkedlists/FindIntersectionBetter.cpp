#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

Node* findPOI(Node* h1, Node* h2){
    Node *t1 = h1, *t2 = h2;
    int n1=0, n2=0;
    while(t1!=NULL){
        n1++;
        t1=t1->next;
    }
    while(t2!=NULL){
        n2++;
        t2=t2->next;
    }
    Node *head1=NULL, *head2=NULL;
    int diff=abs(n1-n2);
    if(n1>n2){
        head1 = h2;
        head2 = h1;
    }
    else{
        head1 = h1;
        head2 = h2;
    }
    t1 = head1, t2 = head2;
    while(diff--)
        t2 = t2->next;

    while(t1!=NULL){
        if(t1 == t2)
            return t1;
        t1=t1->next;
        t2=t2->next;
    }
    return NULL;
}




int main(){
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);

    Node* head2 = new Node(5);
    head2->next = head1->next->next;

    cout<<"LL1 is"<<endl;
    Node *t1=head1, *t2=head2;
    while(t1!=NULL){
        cout<<t1->data<<"    ";
        t1=t1->next;
    }
    cout<<"LL2 is"<<endl;
    while(t2!=NULL){
        cout<<t2->data<<"    ";
        t2=t2->next;
    }
    Node* res = findPOI(head1, head2);
    cout<<endl<<res->data<<endl;
    return 0;
}