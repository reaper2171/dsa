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
    if(h1 == NULL || h2 == NULL)
        return NULL;
    Node *t1 = h1, *t2 = h2;
    while(t1!=t2){
        t1 = (t1 == NULL) ? h2 : t1->next;
        t2 = (t2 == NULL) ? h1 : t2->next;
    }
    return t1;
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