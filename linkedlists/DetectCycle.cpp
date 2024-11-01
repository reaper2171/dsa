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

bool detectCycle(Node* head){
    if(head == NULL || head->next == NULL)
        return false;
    Node *slow = head, *fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow)
            return true;
    }
    return false;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next;

    detectCycle ? cout<<"Cycle is there": cout<<"Cycle not present";
    return 0;
}