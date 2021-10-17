/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool help(struct TreeNode* p,struct TreeNode*q)
{if (!p && !q) return true;
        if (!p || !q) return false;
    
return p->val == q->val &&help(p->left, q->right) && help(p->right, q->left);
}
 


bool isSymmetric(struct TreeNode* root){
        if(root==NULL)
        {
            return true;
        }
      return  help(root,root);

}
