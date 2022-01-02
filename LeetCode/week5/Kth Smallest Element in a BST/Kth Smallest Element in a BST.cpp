class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>Tree;
       helper(root,Tree);
       return Tree[k-1];

    }
    void helper(TreeNode* root,vector<int>&tree)
    {
             if(!root)
             {
                return ;
             }
             helper(root->left,tree);
             tree.push_back(root->val);
             helper(root->right,tree);

    }
};
