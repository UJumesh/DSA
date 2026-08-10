# DSA
Day 5

# Intuition
LC 70 3Sum closest:

We have three possible values: `0`, `1`, and `2`.

We can maintain three regions:

* `0` → should be placed on the left
* `1` → should remain in the middle
* `2` → should be placed on the right

I use three pointers:

* `left` → position where the next `0` should go
* `i` → current element being checked
* `right` → position where the next `2` should go

The important observation is that when we swap a `2` with `nums[right]`, the element coming from the right is **not processed yet**. Therefore, we do **not** increment `i` in that case.

# Approach

1. Initialize:

   * `left = 0`
   * `i = 0`
   * `right = n - 1`

2. Traverse while `i <= right`.

3. If `nums[i] == 0`:

   * Swap it with `nums[left]`.
   * Move both `left` and `i`.

4. If `nums[i] == 1`:

   * It is already in the correct middle region.
   * Simply increment `i`.

5. If `nums[i] == 2`:

   * Swap it with `nums[right]`.
   * Decrease `right`.
   * Do **not** increment `i`, because the new element at index `i` still needs to be checked.

This sorts the array in a single traversal without using an extra array.

# Complexity

* **Time complexity:** `O(n)`
* **Space complexity:** `O(1)`

# Code

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int left = 0;
        int right = n - 1;

        for(int i = 0; i <= right;) {

            if(nums[i] == 0) {
                swap(nums[i], nums[left]);
                left++;
                i++;
            }

            else if(nums[i] == 2) {
                swap(nums[i], nums[right]);
                right--;
            }

            else {
                i++;
            }
        }
    }
};
```
