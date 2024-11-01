#include <bits/stdc++.h>
using namespace std;

Node* merge2LL(Node* list1, Node* list2){
        Node *dummy = new Node(-1);
        Node *res = dummy;
        Node *t1 = list1, *t2 = list2;
        while(t1 != NULL && t2 != NULL){
            if(t1->data < t2->data){
                res->bottom = t1;
                res = res->bottom;
                t1 = t1->bottom;
            }
            else{
                res->bottom = t2;
                res = res->bottom;
                t2 = t2->bottom; 
            }
        }
        if(t1 != NULL)
            res->bottom = t1;
        else if(t2 != NULL)
            res->bottom = t2;
        return dummy->bottom;
    }
    
    Node *flatten(Node *root) {
        if(root == NULL || root->next == NULL)
            return root;
        Node* merged = flatten(root->next);
        return merge2LLs(root, merged);
    }