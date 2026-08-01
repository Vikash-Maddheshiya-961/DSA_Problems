class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n = satisfaction.size();
        vector<int> suffix(n);
        suffix[n-1] = satisfaction[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i] = suffix[i+1] + satisfaction[i];
        }
        int idx = -1;
        for(int i=0;i<n;i++){
            if(suffix[i] >= 0){
                idx = i;
                break;
            }
        }
        if(idx == -1) return 0;
        int x = 1;
        int max_sum = 0;
        for(int i=idx;i<n;i++){
            max_sum += x * satisfaction[i];
            x++;
        }
        return max_sum;
    }
};