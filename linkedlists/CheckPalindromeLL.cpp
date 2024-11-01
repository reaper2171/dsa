#include <bits/stdc++.h>
using namespace std;

ListNode* reverseLL(ListNode* head){
        ListNode *temp = head, *prev = NULL;
        while(temp!=NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

bool isPalindrome(ListNode* head) {
    if(head == NULL || head->next == NULL)
        return true;
    ListNode *slow = head, *fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* newHead = reverseLL(slow->next);

    ListNode *first = head, *second = newHead;
    while(second!=NULL){
        if(first->val != second->val){
            reverseLL(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLL(newHead);
    return true;
}