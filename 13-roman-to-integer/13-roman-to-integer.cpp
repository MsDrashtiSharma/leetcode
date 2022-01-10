class Solution {
public:
    int romanToInt(string s) {
       
       map<char,int>m;
       m.insert({'I',1});
       m.insert({'V', 5});
       m.insert({'X',10});
        m.insert({'L',50});
       m.insert({'C',100});
       m.insert({'D',500});
       m.insert({'M',1000});
             int b=s.length()-1;
            int result=m[s[b]];
        cout<<result;
            for(int i=s.length()-2;i>=0;i-- )
            {
                if(m[s[i]]<m[s[i+1]])
                    result=result-m[s[i]];
                else
                     result=result+m[s[i]];
            }
        return result;
    }
};