class Solution {
public:
    double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
        //merge two array;
        int i=0;
        int j=0;
        vector<int> res;
        while(i<num1.size()&&j<num2.size()){
            if(num1[i]<=num2[j]){
                res.push_back(num1[i]);
                i++;
            }else{
                res.push_back(num2[j]);
                j++;
            }
        }
        while(i<num1.size()){
            res.push_back(num1[i]);
            i++;
        }
        while(j<num2.size()){
            res.push_back(num2[j]);
            j++;
        }
        int n = res.size();
        if(n%2!=0){
            return res[n/2];
        }
        float mid = (res[(n/2)-1] + res[n/2])/2.0;
        return mid;
    }
};