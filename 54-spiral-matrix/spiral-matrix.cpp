class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int left =0,right=n-1;
        int top=0,bottom=m-1;

        vector<int> v;

        while(left<=right && top<=bottom){
            for(int i=left;i<=right;i++){ // we dont need to check as it is at top only
                v.push_back(matrix[top][i]);
            }
            top++;

            for(int i=top;i<=bottom;i++){  // already it is checking
                v.push_back(matrix[i][right]);
            }
            right--;
        
            if(top<=bottom){
            for(int i=right;i>=left;i--){ // we have to check for top bottom
                v.push_back(matrix[bottom][i]);
            }
            bottom--;
            }
            

            if(left<=right){
            for(int i=bottom;i>=top;i--){ //we have to for left right
                v.push_back(matrix[i][left]);
            }
            left++;
            }
        }
        return v;
    }
};