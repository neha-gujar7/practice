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
    int maxLevelSum(TreeNode* root) {
int anslvl=1,lvl=1;
        if (!root)
            return 0;

        int maxi = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int qsz = q.size();
            int sum = 0;
            for (int i = 0; i < qsz; i++) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                
            }
            if(sum>maxi){
maxi =  sum;
anslvl=lvl;
            }
            lvl++;
            

            // sum=0;
        }
        return anslvl;
    }
};