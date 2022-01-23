class Solution {
    private:
    vector<int> ans;
public:
    int kthLargest(TreeNode* root, int k) {
          
           dfs(root);
           int length=ans.size();
           return ans[length-k];
    }
    void dfs(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        else
        {
            dfs(root->left);
            ans.push_back(root->val);
            dfs(root->right);
        }
    }
};
