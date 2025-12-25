#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2){
    ListNode dummy(0);          
    ListNode* temp = &dummy;
    while (l1!=nullptr && l2!=nullptr) {    
        if (l1->val<=l2->val){
            temp->next=l1;
            l1=l1->next;
        }else{
            temp->next=l2;
            l2=l2->next;
        }
        temp=temp->next;
    }
    if (l1!=nullptr){
        temp->next=l1;
    }       else{
        temp->next=l2;
    }  
    return dummy.next;
}