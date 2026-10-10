class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        
        int n = nums1.size();
        int k = k1 + k2;

        vector<int> diff(n);
        int maxDiff = 0;
        long long totalDiff = 0;

        // Calculate absolute differences
        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
            totalDiff += diff[i];
        }

        // If we can eliminate all differences
        if (k >= totalDiff)
            return 0;

        // Frequency of each difference
        vector<int> freq(maxDiff + 1, 0);

        for (int d : diff) {
            freq[d]++;
        }

        // Reduce largest differences first
        for (int d = maxDiff; d > 0 && k > 0; d--) {

            if (freq[d] == 0)
                continue;

            // Number of differences we can reduce
            int reduce = min(freq[d], k);

            freq[d] -= reduce;
            freq[d - 1] += reduce;

            k -= reduce;
        }

        // Calculate final sum of squared differences
        long long ans = 0;

        for (int d = 1; d <= maxDiff; d++) {
            ans += 1LL * d * d * freq[d];
        }

        return ans;
    }
};