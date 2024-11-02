#include <bits/stdc++.h>
using namespace std;

ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL || head->next == NULL)
        return head;
    ListNode* tail = head;
    int len = 1;
    while(tail->next!=NULL){
        len++;
        tail = tail->next;
    }
    k = k%len;
    if(k == 0)
        return head;
    tail->next = head;
    ListNode* temp = head;
    for(int i = 1; i<len-k; i++){
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;
    return head;
}