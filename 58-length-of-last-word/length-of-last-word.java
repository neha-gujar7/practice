class Solution {
    public int lengthOfLastWord(String s) {
        char[] st=s.toCharArray();
        int n=st.length;
        int count=0;
        
        for(int i=n-1;i>=0;i--){
            if(st[i]==' ') count++;
            else break;
            // else m+=st.cancat(valueOf(st[i]));  
        }
        int c=0;
        for(int i=n-1-count;i>=0;i--){
            if(st[i]==' ') break;
            else c++;
        }
        return c;
    }
}