class Solution {
public:
    long long mod = 1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int len = s.length();
        int m = queries.size();
        vector<int> ans;
        vector<long long> pre_sum(len+1,0);
        vector<long long> dig_count(len+1,0);
        vector<long long> conct(len+1,0);
        for(int i=0;i<len;i++){
            long long val = s[i] - '0';
            if(val == 0){
                dig_count[i+1] = dig_count[i];
                conct[i+1] = conct[i];
            }else{
                dig_count[i+1] = dig_count[i] + 1;
                conct[i+1] = (conct[i]*10 + val) % mod;
            }
            pre_sum[i+1] = (pre_sum[i] + val)%mod;
        }
        vector<long long> pow(len+1);
        pow[0] = 1;
        for(int i=1;i<len;i++){
            pow[i] = (pow[i-1]*10)%mod;
        }
        for(int i=0;i<m;i++){
            int lo = queries[i][0];
            int hi = queries[i][1];
            long long sum = (pre_sum[hi+1] - pre_sum[lo] + mod) % mod;
            long long nzd = dig_count[hi+1] - dig_count[lo];
            long long val = ((conct[hi+1] - (conct[lo]*pow[nzd]) % mod + mod) % mod);
            long long product = ((val*sum)%mod);
            ans.push_back((int)product);
        }
        return ans;
    }
};