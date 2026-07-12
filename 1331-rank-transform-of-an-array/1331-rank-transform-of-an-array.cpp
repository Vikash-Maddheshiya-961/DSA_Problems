class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++){
            temp.push_back({arr[i],i});
        }
        sort(temp.begin(),temp.end());
        vector<int> ans(n);
        int prev = INT_MIN;
        int count = 0;
        for(auto p:temp){
            int curr = p.first;
            if(prev!=curr){
                ans[p.second] = count + 1;
                prev = curr;
                count++;
            }else{
                ans[p.second] = count;
            }
        }
        return ans;
    }
};