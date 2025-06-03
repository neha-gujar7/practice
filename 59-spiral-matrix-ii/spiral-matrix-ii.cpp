class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // int m=matrix.size();
        // int n=matrix[0].size();
        int left =0,right=n-1;
        int top=0,bottom=n-1;

        vector<vector<int>> v(n, vector<int>(n, 0));
        int cn=1;

        while(left<=right && top<=bottom){
            for(int i=left;i<=right;i++){ // we dont need to check as it is at top only
                v[top][i]=cn;
                cn++;
            }
            top++;

            for(int i=top;i<=bottom;i++){  // already it is checking
                v[i][right]=cn;
                cn++;
            }
            right--;
        
            if(top<=bottom){
            for(int i=right;i>=left;i--){ // we have to check for top bottom
                v[bottom][i]=cn;
                cn++;
            }
            bottom--;
            }
            

            if(left<=right){
            for(int i=bottom;i>=top;i--){ //we have to for left right
                // v.push_back(matrix[i][left]);
                v[i][left]=cn;
                cn++;
            }
            left++;
            }
        }
        return v;
        
    }
};