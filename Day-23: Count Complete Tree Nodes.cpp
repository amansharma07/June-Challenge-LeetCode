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
    int c;
    void inorder(TreeNode* root){
        if(root==NULL)
            return;
        inorder(root->left);
        c++;
        inorder(root->right);
    }
    int countNodes(TreeNode* root) {
        c=0;
        inorder(root);
        return c;
    }
};
