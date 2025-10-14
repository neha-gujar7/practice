/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  void inorder(Node* root,int l,int r, int& sum) {
    if (root == NULL)
        return;
    
    inorder(root->left,l,r,sum);
    if(root->data>=l && root->data<=r){
        sum+=root->data;
    }
    inorder(root->right,l,r,sum);
}

  
    int nodeSum(Node* root, int l, int r) {
        int sum=0;
        inorder(root,l,r,sum);
        // code here
        return sum;
    }
};
