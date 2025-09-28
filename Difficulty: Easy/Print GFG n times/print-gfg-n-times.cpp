class Solution {
  public:
    void printGfg(int N) {
        // Code here
        if(N<1) return ;
        cout << "GFG" << " ";
        printGfg(N-1);
    }
};
