class Solution {
public:
    string reverseWords(string s) {
        s.push_back(' ');
        string res;
        int n = s.length();
        int i=0, j=0;
        while(i<n && j<=n){
            if(s[i] == ' '){
                i++;
                j++;
            }
            else if(s[i]!=' ' && s[j]!=' '){
                j++;
            }
            else if(s[i]!=' ' && s[j] == ' '){
                reverse(s.begin()+i,s.begin()+j);
                res = res + s.substr(i,j-i)+ ' ';
                j++;
                i = j;
            }
        }
        res.pop_back();
        reverse(res.begin(),res.end());
        return res;
    }
};