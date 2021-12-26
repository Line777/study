/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> flag;
        ListNode* pos=headA;
        while(pos)
        {
            flag.insert(pos);
            pos=pos->next;
        } 
        ListNode* pos2 =headB;
        while(pos2)
        {
         if(flag.find(pos2)!=flag.end())
         {
             return pos2;
         }
         pos2=pos2->next;  
        }
        return NULL;
    }
};
