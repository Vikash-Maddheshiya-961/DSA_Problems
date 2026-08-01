class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n = satisfaction.size();
        int s = -1;
        for(int i=0;i<n;i++){
            if(satisfaction[i] >= 0){
                s = i;
                break;
            }
        }
        cout << s <<" ";
        if(s == -1) return 0;
        int max1 = 0;
        for(int i=s;i<n;i++){
            max1 += (i-s+1)*satisfaction[i];
        }
        cout << max1 <<" ";
        if(s == 0) return max1;
        while(s>0){
            s = s - 1;
            int max2 = 0;
            for(int i=s;i<n;i++){
                max2 += (i-s+1)*satisfaction[i];
            }
            if(max2 > max1) max1 = max2;
            else break;
        }
        return max1;
    }
};