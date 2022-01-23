class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
            vector<vector<int>> ans;
            vector<int>pos;
            backtrace(root,target,pos,ans);
            return ans;
    }
    void backtrace(TreeNode *root,int target,vector<int>&pos,vector<vector<int>>&ans)
    {
        
           if(root==NULL)
           {return;}

            if(root->left==NULL&&root->right==NULL)
            {
                int num=0;
                for(int i=0;i<pos.size();i++)
                {
                    num=num+pos[i];
                }
                if(num==target)
                {
                    ans.push_back(pos);
                }
            }
            else
            {
                pos.push_back( root->val );
                backtrace(root->left,target,pos,ans);
                pos.pop_back();
                backtrace(root->right,target,pos,ans);    
            }
    }
};
