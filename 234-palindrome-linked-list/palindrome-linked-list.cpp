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
    ListNode* reverseLL(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr){
            ListNode* newNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newNext;

        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next){
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
        }
        ListNode* secondhalf = reverseLL(slow);
        ListNode* firsthalf = head;
        while(secondhalf){
            if(firsthalf->val!=secondhalf->val){
                return false;
            }
            firsthalf = firsthalf->next;
            secondhalf = secondhalf->next;
        }
        return true;
    }
};