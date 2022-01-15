class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr) return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool rev = false;
        while(!q.empty()){
            int node_num = q.size();
            vector<int> cur_level(node_num);
            for(int i=0;i<node_num;++i){
                auto cur = q.front(); q.pop();
                if(cur->left!=nullptr) q.push(cur->left);
                if(cur->right!=nullptr) q.push(cur->right);
                cur_level[rev?node_num-1-i:i] = cur->val;
            }
            rev = !rev;
            ans.push_back(cur_level);
        }
        return ans;
    }
};
