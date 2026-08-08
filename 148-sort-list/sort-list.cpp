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
    pair<ListNode*, ListNode*> split(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = NULL;

        return{head, slow};
    }
    ListNode* merge(ListNode* list1, ListNode* list2) {
        if(list1 == NULL || list2 == NULL){
            return list1 == NULL ? list2 : list1;
        }
        if(list1->val<=list2->val){
            list1->next = merge(list1->next,list2);
            return list1;
        }
        else{
            list2->next = merge(list1,list2->next);
            return list2;
        }
    }
    ListNode* sortList(ListNode* head) {
        

        if(!head || !head->next) return head;

        auto[left, right] = split(head);

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);

    }
};