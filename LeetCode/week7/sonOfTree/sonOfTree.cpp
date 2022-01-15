class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B)  {

        return (A != NULL && B != NULL) && (recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
    }
    bool recur(TreeNode* A, TreeNode* B) {
        if(B == NULL) return true;
        if(A == NULL || A->val != B->val) return false;
        return recur(A->left, B->left) && recur(A->right, B->right);
    }


    
};
