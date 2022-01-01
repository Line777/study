class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
           return helper(preorder,inorder);
    }
    TreeNode* helper(vector<int>&pre,vector<int>&in)
    {
            if(pre.size()==0)
            {
                return NULL;
            }
            if(in.size()==0)
            {
                return NULL;
            }
             TreeNode*root=new TreeNode;
             root->val=pre[0];
             int inSize=in.size();
             
             int pos;
             for(int i=0;i<inSize;i++)
             {
                 if(pre[0]==in[i])
                 {
                     pos=i;
                 }
             }

             pre.erase(pre.begin(),pre.begin()+1);
             vector<int> left={in.begin(),in.begin()+pos-1};
               root->left=helper(pre,left);
             if(pos+1==inSize)
             {
                 root->right=NULL; 
             }
             else{
             vector<int>right={in.begin()+pos+1,in.end()};
             root->right=helper(pre,right);
             }
           
           
            return root;
     }
};
