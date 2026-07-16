class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int n = s.length();
        int value = mp[s[n-1]];
        int prev = mp[s[n-1]];
        for(int i=n-2;i>=0;i--){
            int curr = mp[s[i]];
            if(curr < prev) value -= curr;
            else value += curr;
            prev = curr;
        }
        return value;
    }
};