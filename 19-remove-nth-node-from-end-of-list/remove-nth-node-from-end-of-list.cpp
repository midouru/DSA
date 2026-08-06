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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int m = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            m++;
        }

        if(n == m){
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        temp = head;

        for(int i = 1;i<(m-n);i++){
            temp = temp->next;
        }

        ListNode* temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;

        return head;
    }
};