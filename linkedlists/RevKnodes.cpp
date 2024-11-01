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

Node* getKthNode(Node* temp, int k){
    Node* t = temp;
    int cnt = 0;
    while(t!=NULL){
        cnt++;
        if(cnt==k)
            return t;
        t = t->next;
    }
    return NULL;
}

Node* rev(Node* temp){
    Node *t = temp, *prev = NULL;
    while(t!=NULL){
        Node* front = t->next;
        t->next = prev;
        prev = t;
        t = front;
    }
    return prev;
}

Node* revKnodes(Node* head, int k){
    Node *temp = head, *prevLast = NULL;
    while(temp!=NULL){
        Node* kthNode = getKthNode(temp, k);
        if(kthNode == NULL){
            if(prevLast != NULL)
                prevLast->next = temp;
            break;
        }
        Node* nextNode = kthNode->next;
        kthNode->next = NULL;
        rev(temp);
        if(temp == head)
            head = kthNode;
        else
            prevLast->next = kthNode;
        prevLast = temp;
        temp = nextNode;
    }
    return head;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next->next->next->next = new Node(10);

    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"     ";
        temp = temp->next;
    }

    cout<<endl<<"after revKnodes"<<endl;
    head = revKnodes(head, 3);

    while(head!=NULL){
        cout<<head->data<<"     ";
        head = head->next;
    }
    cout<<endl;
    
    return 0;
}