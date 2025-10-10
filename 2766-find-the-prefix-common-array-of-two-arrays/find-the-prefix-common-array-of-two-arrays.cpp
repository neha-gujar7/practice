class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();

        vector<int> a(n+1,0),res(n);
        
        int c=0;
        for(int i=0;i<n;i++){
            a[A[i]]++;
            
            if(a[A[i]]==2) c++;
            a[B[i]]++;
            if(a[B[i]]==2) c++;
            res[i]=c;
        }
        return res;
    }
};