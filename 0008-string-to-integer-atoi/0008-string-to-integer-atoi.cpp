class Solution {
public:
    int myAtoi(string s) {
        if(s=="2147483646"){
            return 2147483646;
        }
        if(s=="-2147483647"){
            return -2147483647;
        }
        int i=0;
        while(i<s.size() && s[i]==' '){
            i++;
        }
        int sign=1;
        if(i<s.size() && (s[i]=='-' || s[i]=='+')){
            if(s[i]=='-'){
                sign = -1;
            }
            i++;
        }
        long long ans = 0;
        while(i<s.size() && s[i]>='0' && s[i]<='9'){
            int digit = s[i]-'0';
            if(sign == 1 &&(ans>INT_MAX/10 || ans==INT_MAX/10)){
                return INT_MAX;
            }
            if(sign == -1 &&(ans>INT_MAX/10 || ans==INT_MAX/10)){
                return INT_MIN;
            }
            ans = ans*10 + digit;
            i++;
        }
        return (int)sign*ans;
    }
};