class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
        {
            return NULL;
        }
        queue<Node*> node;
        node.push(root);
        int size;
        while(!node.empty())
        {
            size=node.size();
            for(int i=0;i<size;i++)
            {
                Node* now=node.front();
                node.pop();
                if(now->left)
                {
                    node.push(now->left);
                }
                 if(now->right)
                {
                    node.push(now->right);
                }
                if(i==size-1)
                {
                    now->next=NULL;
                }
                else
                {
                    now->next=node.front();
                }

            }
        }
        return root;
    }
};
