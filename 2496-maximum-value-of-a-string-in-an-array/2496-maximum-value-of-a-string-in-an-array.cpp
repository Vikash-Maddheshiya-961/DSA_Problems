class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int n = strs.size();
        vector<int> num(n);
        for(auto str:strs){
            bool flag = false;
            for(int j=0;j<str.size();j++){
                if('a' <= str[j] && str[j] <= 'z' || 'A' <= str[j] && str[j] <= 'Z'){
                    flag = true;
                    break;
                }
            }
            if(flag == true){
                num.push_back(str.size());
            }else{
                num.push_back(stoi(str));
            }
        }
        int max = num[0];
        for(auto val: num){
            if(max < val) max = val;
        }
        return max;
    }
};