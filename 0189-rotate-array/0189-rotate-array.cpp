class Solution {
public:
    void reverse(vector<int>& v,int i,int j){
        while(i<j){
            v[i] = v[i]+v[j];
            v[j] = v[i]-v[j];
            v[i] = v[i]-v[j];
            i++;
            j--;
        }
        return;
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
        return;
    }
};