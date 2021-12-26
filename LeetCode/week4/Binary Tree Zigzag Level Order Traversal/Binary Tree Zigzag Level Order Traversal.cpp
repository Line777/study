/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       
        vector<vector<int>> result; 
        if(!root)
        {
            return result;
        }
        bool flag=true;
        queue<TreeNode*> node;
        node.push(root);
        while(!node.empty())
        {
            int length=node.size();
            deque<int> nodeAns;
           
            for(int i=0;i<length;i++)
            {
              TreeNode* nowNode=node.front();
              node.pop();
            if(flag)
            {
               nodeAns.push_back(nowNode->val);
            }
            else
            {
                nodeAns.push_front(nowNode->val);
            }
            if(nowNode->left)
            {
                    node.push(nowNode->left);
            }
             if(nowNode->right)
            {
                    node.push(nowNode->right);
            }
             } 
             result.push_back(vector<int>{nodeAns.begin(),nodeAns.end()});
             flag=!flag;

    }
    return result;}
};
