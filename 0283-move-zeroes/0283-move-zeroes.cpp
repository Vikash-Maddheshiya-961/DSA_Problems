class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n = arr.size();
        int i=0,j=1;
        while(i<n && j<n){
            if(arr[i] == 0 && arr[j] != 0){
                if(i<j)swap(arr[i],arr[j]);
                else j++;
            }
            else if(arr[i]!=0) i++;
            else if(arr[j]==0) j++;
        }
        return;
    }
};