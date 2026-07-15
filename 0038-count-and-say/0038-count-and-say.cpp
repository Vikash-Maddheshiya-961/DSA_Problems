class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string str = countAndSay(n-1);
        string ztr;
        int count = 1;
        char prev = str[0];
        for(int i=1;i<str.length();i++){
            char curr = str[i];
            if(prev == curr){
                count++;
            }
            else{
                ztr.push_back(char(count+48)); 
                ztr.push_back(prev);
                count = 1;
                prev = curr;
            }
        }
        ztr.push_back(char(count+48)); 
        ztr.push_back(prev);
        return ztr;
    }
};