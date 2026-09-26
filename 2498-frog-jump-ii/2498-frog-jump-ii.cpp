class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        if(n == 2) return stones[1];

        int min_cost = 0;

        for(int i=0;i<n-2;i++){
            min_cost = max(min_cost,stones[i+2]-stones[i]);
        }

        return min_cost;
    }
};