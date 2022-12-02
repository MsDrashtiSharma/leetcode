class Solution {
public:
    int longestPalindrome(string s) {
    
        sort(s.begin(),s.end());
        int count=0;
        for(int i=1;i<s.size();)
        {
            if(s[i]==s[i-1])
            {
                count+=2;
                i+=2;
            }
            else
            {
                i++;
            }
        }
    // return count;
    // }
    if(count<s.size())
        return count+1;
    
    return count;
    }
};

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
// sort(s.begin(), s.end());
// 	int count=0;
// 	for(int i=1;i<s.size();){
// 		if(s[i]==s[i-1]){
// 			count+=2;
// 			i+=2;
// 		}
// 		else i++;
// 	}

// 	if(count<s.size()) return count+1;
// return count;













