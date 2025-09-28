class Solution {
  public:
    void printTillN(int n) {
        // code here
        if(n<1) return ;
       
        
        printTillN(n-1);
         cout<<n<<" ";
    }
};