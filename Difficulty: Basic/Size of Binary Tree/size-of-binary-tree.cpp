class Solution {
  public:
    int f(Node* node, int& sum){
        if(node == NULL) {
            return 0;
        }
        int l = f(node->left, sum);
        int r = f(node->right, sum);
        sum = 1 + l + r;  
        return sum;        
    }

    int getSize(Node* node) {
        int sum = 0;
        f(node, sum);
        return sum;
    }
};
