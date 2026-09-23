/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k==0)
        {return head;}
        ListNode* tail=head;
        int N=1;
        while(tail->next!=NULL){
            N++;
            tail=tail->next;
        }
        tail->next=head;
        k=k%N;
        if(k==0){
            tail->next=NULL;
            return head;
        }
        ListNode* newtail=head;
        for(int i=0;i<(N-k-1);i++){
            newtail=newtail->next;
        }
        ListNode* newhead=newtail->next;
        newtail->next=NULL;
        return newhead;

    }
};