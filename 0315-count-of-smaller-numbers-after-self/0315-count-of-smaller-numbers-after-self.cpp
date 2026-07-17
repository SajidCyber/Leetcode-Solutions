#include <vector>
#include <numeric>

class Solution {
public:
    std::vector<int> countSmaller(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> counts(n, 0);
        std::vector<int> indices(n);
        std::iota(indices.begin(), indices.end(), 0);
        
        std::vector<int> temp(n);
        mergeSort(nums, indices, temp, counts, 0, n - 1);
        
        return counts;
    }

private:
    void mergeSort(const std::vector<int>& nums, std::vector<int>& indices, std::vector<int>& temp, std::vector<int>& counts, int left, int right) {
        if (left >= right) return;
        
        int mid = left + (right - left) / 2;
        mergeSort(nums, indices, temp, counts, left, mid);
        mergeSort(nums, indices, temp, counts, mid + 1, right);
        
        merge(nums, indices, temp, counts, left, mid, right);
    }

    void merge(const std::vector<int>& nums, std::vector<int>& indices, std::vector<int>& temp, std::vector<int>& counts, int left, int mid, int right) {
        int i = left;
        int j = mid + 1;
        int k = left;
        int right_less_count = 0;

        while (i <= mid && j <= right) {
            if (nums[indices[j]] < nums[indices[i]]) {
                right_less_count++;
                temp[k++] = indices[j++];
            } else {
                counts[indices[i]] += right_less_count;
                temp[k++] = indices[i++];
            }
        }

        while (i <= mid) {
            counts[indices[i]] += right_less_count;
            temp[k++] = indices[i++];
        }

        while (j <= right) {
            temp[k++] = indices[j++];
        }

        for (i = left; i <= right; i++) {
            indices[i] = temp[i];
        }
    }
};