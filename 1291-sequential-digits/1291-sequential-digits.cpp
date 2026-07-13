class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string num1 = to_string(low);
        string num2 = to_string(high);
        int len1 = num1.length();
        int len2 = num2.length();
        string str = "123456789";
        vector<int> ans;
        for(int i=len1; i<=len2; i++){
            for(int j=0; j<=9-i; j++){
                string temp = str.substr(j,i);
                int val = stoi(temp);
                if(val < low) continue;
                if(val > high) break;
                ans.push_back(val);
            }
        }
        return ans;
    }
};