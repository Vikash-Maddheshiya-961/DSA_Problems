class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
         // Step 1: Find the maximum value in nums
        int max_val = *max_element(nums.begin(), nums.end());
        
        // Step 2: Compute frequency map of elements
        vector<long long> count(max_val + 1, 0);
        for (int num : nums) {
            count[num]++;
        }
        
        // Step 3: Count how many elements are multiples of each number `i`
        vector<long long> multiples(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            for (int j = i; j <= max_val; j += i) {
                multiples[i] += count[j];
            }
        }
        
        // Step 4: Calculate total pairs where GCD is a multiple of `i`
        // Then subtract overlapping multiples using a reverse sieve (inclusion-exclusion)
        vector<long long> gcd_pairs(max_val + 1, 0);
        for (int i = max_val; i >= 1; --i) {
            long long total_elements_divisible = multiples[i];
            // Total pairs formed by these elements
            long long pairs = total_elements_divisible * (total_elements_divisible - 1) / 2;
            
            // Subtract pairs that have a strictly larger common divisor (multiples of i)
            for (int j = 2 * i; j <= max_val; j += i) {
                pairs -= gcd_pairs[j];
            }
            gcd_pairs[i] = pairs;
        }
        
        // Step 5: Construct the running prefix sum array of GCD counts
        vector<long long> prefix_sums(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            prefix_sums[i] = prefix_sums[i - 1] + gcd_pairs[i];
        }
        
        // Step 6: Process each query using binary search (upper_bound)
        vector<int> ans;
        ans.reserve(queries.size());
        for (long long q : queries) {
            // Find the first GCD index where cumulative pair count is strictly greater than q
            auto it = upper_bound(prefix_sums.begin(), prefix_sums.end(), q);
            ans.push_back(distance(prefix_sums.begin(), it));
        }
        
        return ans;
    }
};