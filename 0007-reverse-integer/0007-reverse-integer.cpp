class Solution {
public:
    int reverse(int x) {
       int rev = 0;
       int max = INT_MAX;
       int min = INT_MIN;
       while(x!=0){
        int digit = x%10;
        if(rev >max/10 || rev<min/10){
            return 0;
        }else if(rev == max/10 || rev==min/10){
            if(digit>max%10 && digit<min%10){
                return 0;
            }else{
                rev = rev*10+digit;
            }
        }else{
            rev = rev*10+digit;
        }
        x = x/10;
       }
       return rev;
    }
};