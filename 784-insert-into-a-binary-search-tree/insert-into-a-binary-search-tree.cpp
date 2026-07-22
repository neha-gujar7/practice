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
    TreeNode* insertIntoBST(TreeNode* root, int data) {
        TreeNode* p=root;
        if(p==NULL) return new TreeNode(data); 
        while(true){
            if(p->val <= data){
                if(p->right != NULL)  p=p->right;
                else {
                    p->right=new TreeNode(data);
                    break;
                }
            }
            else{    
                if(p->left != NULL)  p=p->left;
                else {
                    p->left=new TreeNode(data);
                    break;
                }
            
            }
        }
        return root;
    }
};