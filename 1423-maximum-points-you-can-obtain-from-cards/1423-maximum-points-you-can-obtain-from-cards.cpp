class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lsum = 0;
        int rsum = 0;
        for(int i=0;i<k;i++){
            lsum += cardPoints[i];
        }

        int sum = lsum + rsum;
        int max_sum = sum;

        int l = k-1;
        int r = n-1;

        while(l >= 0){
            lsum -= cardPoints[l];
            rsum += cardPoints[r];

            sum = lsum + rsum;

            if(max_sum < sum) max_sum = sum;

            l--;
            r--;
        }

        return max_sum;
    }
};