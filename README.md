# DSA
Day 5 — LC 75-sort Colors:

# Intuition
LC 75-sort Colors:

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
# Day 4 — 3Sum Closest

## Problem

**LeetCode: 16. 3Sum Closest**

Given an integer array `nums` and an integer `target`, find three integers in `nums` such that their sum is closest to `target`.

Return the sum of the three integers.

---

## Intuition

The main idea is to sort the array first.

After sorting, I fix one element `nums[i]` and use two pointers:

* `left = i + 1`
* `right = n - 1`

For every pair `nums[left]` and `nums[right]`, I calculate the current three-number sum.

Then I compare its distance from the target with the best answer found so far.

The important part is:

```cpp
abs(current - target)
```

This gives the distance between the current sum and the target.

If the current sum is closer to the target, I update `res`.

---

## Approach

1. Sort the array.
2. Initialize `res` with the sum of the first three elements.
3. Fix `nums[i]` one by one.
4. Use two pointers:

   * `left = i + 1`
   * `right = n - 1`
5. Calculate:

   ```cpp
   current = nums[i] + nums[left] + nums[right];
   ```
6. If `current` is closer to `target` than `res`, update `res`.
7. If the current pair sum is smaller than the required sum:

   ```cpp
   left++;
   ```
8. Otherwise:

   ```cpp
   right--;
   ```
9. If the exact target is found, return immediately.

---

## Complexity

* **Time Complexity:** `O(n²)`
* **Space Complexity:** `O(1)` extra space, excluding the sorting implementation.

---

## Code

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int n = nums.size();

        int res = nums[0] + nums[1] + nums[2];

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 2; i++) {

            int left = i + 1;
            int right = n - 1;

            int sum = target - nums[i];

            while(left < right) {

                int s = nums[left] + nums[right];

                int current = nums[i] + s;

                if(abs(current - target) < abs(res - target)) {
                    res = current;
                }

                if(s == sum) {
                    return current;
                }

                if(s < sum) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }


        return res;
    }
};
```

---

## Key Learning

### Closest Sum Pattern

For closest-value problems, think about the **difference from the target**:

```cpp
abs(current - target)
```

The smaller the difference, the better the answer.

### Two-Pointer Pattern

Because the array is sorted:

* If the sum is too small → move `left` forward.
* If the sum is too large → move `right` backward.

This reduces the search from `O(n³)` brute force to `O(n²)`.

