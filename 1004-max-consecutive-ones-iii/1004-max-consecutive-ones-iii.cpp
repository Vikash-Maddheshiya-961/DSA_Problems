class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 0){
            int i=0;
            int len;
            int max_len = 0;
            while(i<n && nums[i]!=1) i++;
            int j = i;
            while(j<n){
                if(nums[j] == 1) j++;
                else{
                    len = j-i;
                    max_len = max(max_len,len);
                    while(j<n && nums[j]!=1) j++;
                    i = j;
                }
            }
            len = j-i;
            max_len = max(max_len,len);
            return max_len;
        }
        int i=0;
        int j=0;
        int flips = 0;
        int len;
        int max_len = INT_MIN;
        queue<int> q;
        while(j<n){
            if(nums[j] == 1){
                j++;
            }else{
                if(flips < k){
                    q.push(j);
                    flips++;
                    j++;
                }
                else{
                    len = j-i;
                    max_len = max(max_len,len);
                    i = q.front()+1;
                    q.pop();
                    flips--;
                }
            }
        }
        len = j-i;
        max_len = max(max_len,len);
        return max_len;
    }
};