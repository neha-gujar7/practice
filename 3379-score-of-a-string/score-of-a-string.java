class Solution {
    public int scoreOfString(String s) {
        int sum=0;
        char[] st=s.toCharArray();
        for(int i=0;i<s.length()-1;i++){
            int x1=(int) st[i];
            int x2=(int)st[i+1];
            sum+=(int) Math.abs(x1-x2);
        }
        return sum;
    }
}