class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        int prev = 0;
        int curr = 1;

        for(int i=2;i<=n;i++){
            int nxt = prev + curr;
            prev = curr;
            curr = nxt;
        }

        return curr;
    }
};