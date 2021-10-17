/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
     int depth=0;
     int depthl=0,depthr=0;
     if(root==NULL)
     {
         return 0;
     }
     if(root->left==NULL&&root->right==NULL)
     {
         
         return 1;
     }
    if(root->left==NULL)
    {
        return maxDepth(root->right)+1;
    }
    if(root->right==NULL)
    {
        return maxDepth(root->left)+1;
    }
    depthl=maxDepth(root->left)+1;
    depthr=maxDepth(root->right)+1;
     if(depthl>depthr)
     {
         return depthl;
     }
     else{
         return depthr;
     }
}
