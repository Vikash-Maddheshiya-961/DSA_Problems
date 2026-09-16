class Solution {
public:
    int getnext(int n){
        int totalsum = 0;
        while(n > 0){
            int digit = n % 10;
            totalsum += digit * digit;
            n /= 10;
        }
        return totalsum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = getnext(n);

        while(fast!=1 && slow!=fast){
            slow = getnext(slow);
            fast = getnext(getnext(fast));
        }

        return fast == 1;
    }
};