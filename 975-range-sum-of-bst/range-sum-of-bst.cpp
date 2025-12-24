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
    int f(TreeNode* root, int low, int high,int& ans){
        if(root==NULL) return 0;
        if(root->val <= high  && root->val >=low) {
            ans+=root->val;
        }
        f(root->left,low,high,ans);
        f(root->right,low,high,ans);

        return ans;

    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans=0;
        return f(root, low, high, ans);
        // return ans;
    }
};