class Solution {
public:
    int numberOfSubstrings(string s) {
        // Using sliding window
        int n = s.length();
        int right = 0, left = 0;
        vector<int> freq(3,0);
        int total = 0;

        while(right < n){
            char rightChar = s[right];
            freq[rightChar - 'a']++;

            while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0){
                total += n-right;

                char leftChar = s[left];
                freq[leftChar - 'a']--;
                left++;
            }
            right ++;
        }
        return total;
    }
};