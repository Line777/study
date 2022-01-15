class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
       vector<int> ans;
       if(root==NULL)
       {
           return ans;
       }
       queue<TreeNode*> treeNode;
       treeNode.push(root);
       while(!treeNode.empty())
       {
              TreeNode* p=treeNode.front();
              if(p->left!=NULL)
              {
                  treeNode.push(p->left);
              }
              if(p->right!=NULL)
              {
                  treeNode.push(p->right);
              }
              ans.push_back(p->val);
              treeNode.pop();
       }
       return ans;
    }
};
