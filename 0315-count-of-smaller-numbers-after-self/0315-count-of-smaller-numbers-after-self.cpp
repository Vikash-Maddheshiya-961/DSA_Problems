void merge(int lo,int mid,int hi,vector<pair<int,int>>& nums,vector<int>& cnt){
    vector<pair<int,int>> temp;
    int i = lo;
    int j = mid+1;

    int right_smaller_cnt = 0;

    while(i <= mid && j <= hi){
        if(nums[i].first > nums[j].first){
            right_smaller_cnt++;
            temp.push_back({nums[j]});
            j++;
        }
        else{
            cnt[nums[i].second] += right_smaller_cnt;
            temp.push_back({nums[i]});
            i++;
        }
    }

    while(i <= mid){
        cnt[nums[i].second] += right_smaller_cnt;
        temp.push_back({nums[i]});
        i++;
    }

    while(j <= hi){
        temp.push_back({nums[j]});
        j++;
    }

    int k=0;
    for(int idx = lo;idx <= hi;idx++){
        nums[idx] = temp[k++];
    }

    return;
}
void mergeSort(int lo,int hi,vector<pair<int,int>>& nums,vector<int>& cnt){
    if(lo >= hi) return;

    int mid = lo + (hi-lo)/2;
    mergeSort(lo,mid,nums,cnt);
    mergeSort(mid+1,hi,nums,cnt);

    merge(lo,mid,hi,nums,cnt);

    return;
}
class Solution {
public:
    vector<int> countSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> nums(n);

        for(int i=0;i<n;i++){
            nums[i] = {arr[i],i};
        }

        vector<int> cnt(n,0);

        mergeSort(0,n-1,nums,cnt);

        return cnt;
    }
};