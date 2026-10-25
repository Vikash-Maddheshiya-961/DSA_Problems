class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0;
        int odd = 0;

        for(int i=0; i<=9; i++){
            if(n & (1 << i)){
                if(i%2 == 0) even++;
                else odd++;
            }
        }

        return {even,odd};
    }
};