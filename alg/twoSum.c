int findNext(int *nums, int numsSize, int firstIndex, int target)
{
    for (int i = 0; i < numsSize; i++) {
        if (firstIndex != i && ((nums[firstIndex] + nums[i]) == target)) {
            return i;
        }
    }

    return -1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * Analysis: For array of size n, the complexity is n * n = quadratic
 */
int* twoSum(int *nums, int numsSize, int target, int returnSize)
{
    int *result = malloc(2 * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        int nextIndex = findNext(nums, numsSize, i, target);
        if (nextIndex != -1) {
            result[0] = i;
            result[1] = nextIndex;
            return result;
        }
    }

    return result;
}
