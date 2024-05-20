class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int max = piles[piles.size() - 1];
        if (h == piles.size()) {
            return max;
        }
        if (piles.size() == 1) {
            return ((piles[0] / h) + ((piles[0] % h == 0) ? 0 : 1));
        }
        int l = 1, r = max;
        int minK = max;
        long long  count = 0;
        while (r >= l) {
            int k = (l + r) / 2;
            count = 0;
            for (int i = 0; i < piles.size(); i++) {
                count += piles[i] / k;
                if (piles[i] % k != 0) {
                    count++;
                }
            }
            if (count <= h) {
                r = k - 1;
                minK = k;
            } else {
                l = k + 1;
            }
        }
        return minK;
    }
};