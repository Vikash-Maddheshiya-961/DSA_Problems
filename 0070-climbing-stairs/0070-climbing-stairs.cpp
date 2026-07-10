class Solution {
public:
    long long total_ways(int n,vector<long long>& ways){
        if(n==1) return 1;
        if(n==2) return 2;
        if(ways[n] !=0 ) return ways[n];
        ways[n] = total_ways(n-1,ways) + total_ways(n-2,ways);
        return ways[n];
    }
    int climbStairs(int n) {
        vector<long long> ways(n+1,0);
        return (int)total_ways(n,ways);
    }
};