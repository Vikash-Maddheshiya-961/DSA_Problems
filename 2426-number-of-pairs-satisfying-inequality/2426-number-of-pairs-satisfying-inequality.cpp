void merge(long long lo,long long mid,long long hi,vector<long long>& nums,long long& k,long long& cnt){
    vector<long long> temp;
    long long i = lo;
    long long j = mid + 1;

    while(j <= hi){
        while(i <= mid && nums[i] <= nums[j] + k){
            i++;
        }
        cnt += (i-lo);
        j++;
    }

    i = lo;
    j = mid + 1;
    while(i <= mid && j <= hi){
        if(nums[i] < nums[j]){
            temp.push_back(nums[i]);
            i++;
        }
        else{
            temp.push_back(nums[j]);
            j++;
        }
    }

    while(i <= mid){
        temp.push_back(nums[i]);
        i++;
    }

    while(j <= hi){
        temp.push_back(nums[j]);
        j++;
    }

    long long l = 0;
    for(long long idx = lo;idx<=hi; idx++){
        nums[idx] = temp[l++];
    }

    return;
}
void mergeSort(long long lo,long long hi,vector<long long>& nums,long long& k,long long& cnt){
    if(lo >= hi) return;

    long long mid = lo + (hi - lo) / 2;

    mergeSort(lo,mid,nums,k,cnt);
    mergeSort(mid+1,hi,nums,k,cnt);

    merge(lo,mid,hi,nums,k,cnt);

    return;
}
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<long long> nums(n);
        for(int i=0;i<n;i++){
            nums[i] = nums1[i] - nums2[i];
        }

        long long k = diff;
        long long cnt = 0;
        mergeSort(0,n-1,nums,k,cnt);

        return cnt;
    }
};