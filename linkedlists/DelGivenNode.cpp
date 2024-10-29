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

void deleteNode(Node* node){
    node->data = node->next->data;
    node->next = node->next->next;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    deleteNode(head->next);

    while(head!=NULL){
        cout<<head->data<<endl;
        head = head->next;
    }
    return 0;
}