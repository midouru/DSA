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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smalldummy = new ListNode(0);
        ListNode* smalltail =  smalldummy;
        ListNode* largedummy = new ListNode(0);
        ListNode* largetail = largedummy;
        ListNode* temp = head;
        while(temp){
            if(temp->val<x){
                smalltail->next = temp;
                smalltail = temp;
            }
            else{
                largetail->next = temp;
                largetail = temp;
            }
            temp = temp->next;
        }

        smalltail->next = largedummy->next;
        largetail->next = NULL;
        
        return smalldummy->next;
    }
};