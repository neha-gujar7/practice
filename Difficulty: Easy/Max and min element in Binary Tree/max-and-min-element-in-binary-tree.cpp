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
    int mini = INT_MAX, maxi = INT_MIN; 
  
    void f(Node *root) {
        if(root == NULL) return;

        mini = min(mini, root->data);  
        maxi = max(maxi, root->data);  

        f(root->left);
        f(root->right);
    }

    int findMax(Node *root) {
        mini = INT_MAX;  
        maxi = INT_MIN;
        f(root);
        return maxi;
    }

    int findMin(Node *root) {
        mini = INT_MAX;   
        maxi = INT_MIN;
        f(root);
        return mini;
    }
};
