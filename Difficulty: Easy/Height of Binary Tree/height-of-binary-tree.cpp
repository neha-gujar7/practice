/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  int dfs(Node* root){
      if(root==NULL) return 0;
      
      int left=dfs(root->left);
      int right=dfs(root->right);
      return  1+max(left,right);
  }
    int height(Node* root) {
        // code here
        
        return dfs(root)-1;
        
    }
};