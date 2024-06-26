/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) { return leftRight(root->left,root->right); }
    bool leftRight(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) {
            return true;
        } else if (left == NULL || right == NULL) {
            return false;
        }
        if (left->val == right->val) {
            return leftRight(left->left, right->right) &&
                   leftRight(left->right, right->left);
        } else {
            return false;
        }
    }
};