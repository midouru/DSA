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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddhead = new ListNode(0);
        ListNode* evenhead = new ListNode(0);
        int len = 0;
        ListNode* temp = head;
        ListNode* odd = oddhead;
        ListNode* even = evenhead;
        while(temp){
           len++;
           temp = temp->next;
        }
        temp = head;
        for(int i = 1;i<=len;i++){
            ListNode* next = temp->next;
            temp->next = NULL;
             if(i%2 != 0){
                odd->next = temp;
                odd = odd->next;
                temp = next;
            }
            else{
                even->next = temp;
                even = even->next;
                temp = next;
            }
            
        }
        temp = oddhead;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = evenhead->next;
        return oddhead->next;

    }
};