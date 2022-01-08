/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
        {
            return head;
        }
        map<Node*,Node*> ansmap;
        Node * now=head;
        Node* ans=new Node(now->val);
        ansmap[now]=ans;
        now=now->next;
        Node* pos=ans;
        while(now!=NULL)
        {
           Node* cur=new Node(now->val);
            pos->next=cur;
            ansmap[now]=cur;
            pos=pos->next;
            now=now->next;
        }
        Node* k=ans;
        while(head!=NULL)
        {
            k->random=ansmap[head->random];
            k=k->next;
            head=head->next;
        }
        
        return ans;

    }
};
