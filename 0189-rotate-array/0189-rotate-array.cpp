class Solution {
public:
    void reverse_part(vector<int>& arr,int i, int j){
        while(i<j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
        return;
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse_part(nums,0,n-1);
        reverse_part(nums,0,k-1);
        reverse_part(nums,k,n-1);
        return;
    }
};