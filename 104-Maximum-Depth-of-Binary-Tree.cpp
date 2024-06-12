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
    int maxDepth(TreeNode* root) {
        int max = 0;
        if(root==NULL){
            return max;
        }
        max++;
        int maxRight=maxDepth(root->right);
        int maxLeft=maxDepth(root->left);
        if(maxRight>=maxLeft){
            max+=maxRight;
        }else{
            max+=maxLeft;
        }
        return max;
    }
};