class Solution {
    public static void  swap(char[] arr, int i, int j){
        char temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    public boolean isPalindrome(String s) {
        char[] st=s.toCharArray();
        String m = ""; 
        for(char it:st){
            if(Character.isLetterOrDigit(it)){
                // m.concat(it); ->this method is wrong
                m = m.concat(String.valueOf(Character.toLowerCase(it)));
                // m = m.concat(String.valueOf(Character.toLowerCase(it)));

            }

        }
        char[] n=m.toCharArray();
        for(int i=0;i<m.length()/2;i++){
            swap(n,i,n.length-1-i);
        }
        // if(n.compareTo(m)){
        //      return true;
        //  }
        //  else{
        //     return false;
        //  }
        String reversed = new String(n);
        return m.equals(reversed); 
        }
}