class Solution {
public:
    int factorial(int n){
        if(n == 0 || n==1) return 1;
        return n*factorial(n-1);
    }
    string solve(string str,string ans,int k){
        int n = str.length();
        if(n == 1){
            ans += str;
            return ans;
        }
        int fact = factorial(n-1);
        cout << fact << " ";
        int idx = k / fact;
        k = k%fact;
        if(k%fact == 0) {
            idx--;
            k = fact;
        }
        char ch = str[idx];
        string left = str.substr(0,idx);
        string right = str.substr(idx+1);
        return solve(left+right,ans+ch,k);
    }
    string getPermutation(int n, int k) {
        string str;
        for(int i=1;i<=n;i++){
            str += to_string(i);
        }
        return solve(str,"",k);
    }
};