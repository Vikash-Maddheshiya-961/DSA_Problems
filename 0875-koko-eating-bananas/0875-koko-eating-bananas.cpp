class Solution {
public:
    bool check(vector<int>& piles,int mid,int hour){
        int h = 0;
        int n = piles.size();
        for(int i=0; i<n; i++){
            h += (piles[i] + mid - 1)/mid;

            if(h > hour) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int max = piles[0];
        for(int i=1; i<n; i++){
            if(max < piles[i]) max = piles[i];
        }
        int lo = 1;
        int hi = max;
        int k = -1;
        while(lo <= hi){
            int mid = lo + (hi-lo) / 2;
            if(check(piles,mid,h)){
                k = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return k;
    }
};