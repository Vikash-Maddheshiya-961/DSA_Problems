class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int max_len = 1;

        // Handle special case for 1s
        if (freq.count(1)) {
            int count1 = freq[1];
            // The subset length must be odd
            if (count1 % 2 == 0) {
                max_len = max(max_len, count1 - 1);
            } else {
                max_len = max(max_len, count1);
            }
        }

        // Iterate through each number as a potential base x
        for (auto& [val, count] : freq) {
            if (val == 1) continue;

            long long current = val;
            int current_len = 0;

            // Build the sequence x, x^2, x^4, ...
            while (freq.count(current) && freq[current] >= 2) {
                current_len += 2;
                
                // Prevent overflow when squaring
                if (current > 100000) { 
                    current = current * current;
                    break; 
                }
                current = current * current;
            }

            // Check if a peak element exists (frequency exactly 1 or we broke early)
            if (freq.count(current) && freq[current] >= 1) {
                current_len += 1;
            } else {
                // If the next power doesn't exist or we overshot, the last element 
                // counted must act as the peak (subtract 1 to make it a single peak)
                current_len -= 1;
            }

            max_len = max(max_len, current_len);
        }

        return max_len;
    }
};