//{ Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String S = read.readLine();

            Solution ob = new Solution();
            System.out.println(ob.findMaxLen(S));
        }
    }
}


// } Driver Code Ends


//User function Template for Java
class Solution {
    static int findMaxLen(String s) {
   if(s==null || s.length()<2){
            return 0;
        }

        Stack<Integer> st =new Stack<>();

        for(int i=0;i<s.length();i++){
            if(s.charAt(i) == '('){
                st.push(i);
            } 
            else{
                
            if(!st.empty() && s.charAt(st.peek()) == '('){
                    
                st.pop();
                } 
                
                else {
                   
                    st.push(i);
                }
            }
        }

        int max = 0;
        int end = s.length();   

        while(!st.empty()){
            int ele  = st.pop();
            max = Math.max(max, end - ele - 1);
            end = ele;
        }

        return Math.max(end, max);    
    }
};