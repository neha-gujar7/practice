// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int x) {
        // Code here
        int flr=-1;
        while(root!=nullptr){
            if(root->data==x) {
                flr=root->data;
                return flr;
            }
            else if(root->data<x){
                flr=root->data;              
                root=root->right;
            }
            else {
                root=root->left;
            }
        }
        return flr;
    }
};