class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        int ceil=-1;
        
        while(root!=nullptr){
            if(root->data==x){
                ceil=root->data;
                return ceil;
            }
            if(root->data>x){
                ceil=root->data;
                root=root->left;
            }
            else root=root->right;
        }
        return ceil;
    }
};
