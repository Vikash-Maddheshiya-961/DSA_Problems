class Solution {
public:
    int numberOfSubstrings(string s) {
        // Using sliding window
        int n = s.length();
        int left = 0, right = 0;
        vector<int> freq(3,0);
        int total = 0;

        while(right<n){
            char curr = s[right];
            freq[curr - 'a']++;
            while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0){
                total += n-right;

                char leftchar = s[left];
                freq[leftchar - 'a']--;
                left++ ;
            }
            right++;
        }
        return total;
    }
};