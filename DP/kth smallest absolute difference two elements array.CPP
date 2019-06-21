 Input  : a[] = {1, 2, 3, 4}
         k = 3
Output : 1
The possible absolute differences are :
{1, 2, 3, 1, 2, 1}.
The 3rd smallest value among these is 1.

Input : n = 2
        a[] = {10, 10}
        k = 1
Output : 0


int smallestDistancePair(vector<int>& nums, int k) {
        auto n = nums.size();        
        vector<int> differences;
        differences.reserve(n * (n+1) / 2);
        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                differences.push_back(abs(nums[j] - nums[i]));
            }
        }
        nth_element(begin(differences), begin(differences) + (k-1), end(differences));
        return differences[k-1];
    }
