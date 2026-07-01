class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int n = strs.size();
        int max = INT_MIN;
        for(auto str:strs){
            bool flag = false;
            for(int j=0;j<str.size();j++){
                if('a' <= str[j] && str[j] <= 'z' || 'A' <= str[j] && str[j] <= 'Z'){
                    flag = true;
                    break;
                }
            }
            int n;
            if(flag == true){
                n = str.size();
            }else{
                n = stoi(str);
            }
            if(max < n) max = n;
        }
        return max;
    }
};