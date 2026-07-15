class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string str = countAndSay(n-1);
        string ztr;
        ztr.push_back(str[0]);
        int count = 1;
        char prev = str[0];
        for(int i=1;i<str.size();i++){
            char curr = str[i];
            if(prev == curr){
                count++;
            }
            else{
                char temp = ztr[ztr.length()-1];
                ztr.pop_back();
                ztr.push_back(char(count+48)); 
                ztr.push_back(temp);
                ztr.push_back(curr);
                count = 1;
                prev = curr;
            }
        }
        char temp = ztr[ztr.length()-1];
        ztr.pop_back();
        ztr.push_back(char(count+48)); 
        ztr.push_back(temp);
        return ztr;
    }
};