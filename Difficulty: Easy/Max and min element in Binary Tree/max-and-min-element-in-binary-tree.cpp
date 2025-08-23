/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    int findMax(Node *root) {
        // code here
        if(root==nullptr) return INT_MIN;
        
        int lefti=findMax(root->left);
        int righti=findMax(root->right);
        
        int temp=root->data;
        if(lefti>temp) temp=lefti;
        if(righti>temp) temp=righti;
        return temp;
        
    }

    int findMin(Node *root) {
        
        if(root==nullptr) return INT_MAX;
        
        int lefti=findMin(root->left);
        int righti=findMin(root->right);
        
        int temp=root->data;
        if(lefti<temp) temp=lefti;
        if(righti<temp) temp=righti;
        return temp;
        // code here
    }
};