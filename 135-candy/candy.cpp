class Solution {
public:
    int candy(vector<int>& ratings) {
        // from this 48/49 test cases passed
        vector<int> a(ratings.size());
        vector<int> b(ratings.size());

        //for left traversal
        a[0]=1;
        for(int i=1;i<ratings.size();i++){
            
            if(ratings[i]>ratings[i-1]){
                a[i]=a[i-1]+1;
            }
            else {
                a[i]=1;
            }
            // a.push_back(a[i]);
        }
        
        b[ratings.size()-1]=1;
        for(int i=ratings.size()-2;i>=0;i--){

            if(ratings[i]>ratings[i+1]){
                b[i]=b[i+1]+1;
                
            }
            else {
                // b.push_back(b[0]+1);
                b[i]=1;
            }
            // b.push_back(1);
        }
        int sum=0;
        for(int i=0;i<ratings.size();i++){
            sum=sum+max(a[i],b[i]);
        }
       
        return sum;
    }
};