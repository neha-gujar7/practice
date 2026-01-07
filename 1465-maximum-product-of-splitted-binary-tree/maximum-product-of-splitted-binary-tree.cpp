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
    // tc sc on o1
    long long totsum = 0;
    long long maxipd = 0;
    static const int MOD = 1e9 + 7;
    long long dfs(TreeNode* root) {
        if (!root)
            return 0;

        long long lt = dfs(root->left);
        long long rt = dfs(root->right);

        long long cursum = root->val + lt + rt;

        maxipd = max(maxipd, (totsum - cursum) * cursum);
        return cursum;
    }
    int maxProduct(TreeNode* root) {
        totsum = dfs(root);
        dfs(root);
        return maxipd%MOD;
    }
};

/// having tc sc on on
// class Solution {
// public:
//     int maxProduct(TreeNode* root) {
//         if (!root)
//             return 0;
//         int ts = 0;

//         long long ans = 0;
//         static const int MOD = 1e9 + 7;
//         vector<long long> res;
//         ts = preorder(root, res, ts);

//         for (long  long i : res) {
//             long long cur = (ts - i) * i;
//             ans = max(ans, cur);
//         }
//         return ans % MOD;

//     }

//     long long preorder(TreeNode* root, vector<long long>& res , int& ts) {
//         if (root == NULL)
//             return 0;

//         long long lt = preorder(root->left, res, ts); // LEFT
//         long long rt = preorder(root->right, res, ts);
//         long long cur = root->val + lt + rt;
//         res.push_back(cur);

//         return cur;
//     }
// };