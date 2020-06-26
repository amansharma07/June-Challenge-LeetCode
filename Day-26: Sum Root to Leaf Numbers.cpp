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
    int res;
    void check(TreeNode *root, int s)
    {
        if(root==NULL)
            return;
        if(root->left ==NULL && root->right == NULL)
        {
            s=s*10+root->val;
            res+=s;
            return;
        }
        s=s*10+root->val;
        check(root->left,s);
        check(root->right,s);
        s=(s-root->val)/10;
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
            return 0;
        res=0;
        check(root,0);
        return res;
    }
};
