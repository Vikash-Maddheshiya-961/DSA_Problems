class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        for(int i=digits.size()-1;i>=0;i--){
            res.push_back(digits[i]);
        }
        bool check = false;
        for(int i=0;i<res.size();i++){
            if(res[i]==9){
                res[i] = 0;
                check = true;
            }else{
                if(check == true){
                    res[i]++;
                    check = false;
                }else{
                    res[i]++;
                }
                break;
            }
        }
        if(check == true){
            res.push_back(1);
        }
        vector<int> res1;
        for(int i=res.size()-1;i>=0;i--){
            res1.push_back(res[i]);
        }
        return res1;
    }
};