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

Node* addTwoNums(Node* num1, Node* num2){
    Node* res = new Node(0);
    Node* temp = res;
    Node *n1=num1, *n2 = num2;
    int carry = 0;
    while(n1!=NULL || n2!=NULL){
        int sum = carry;
        if(n1){
            sum += n1->data;
            n1 = n1->next;
        }
        if(n2){
            sum+= n2->data;
            n2 = n2->next;
        }
        Node* newNode = new Node(sum%10);
        carry = sum/10;
        temp->next = newNode;
        temp = temp->next;
    }
    if(carry){
        Node* newNode = new Node(carry);
        temp->next = newNode;
    }
    return res->next;
}


int main(){
    Node* num1 = new Node(3);
    num1->next = new Node(4);
    num1->next->next = new Node(8);
    num1->next->next->next = new Node(8);

    Node* num2 = new Node(5);
    num2->next = new Node(7);
    num2->next->next = new Node(9);

    Node* res = addTwoNums(num1, num2);
    while(res!=NULL){
        cout<<res->data;
        res = res->next;
    }
    return 0;
}