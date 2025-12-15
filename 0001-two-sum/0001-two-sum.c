/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    
    int *result = malloc(2 * sizeof(int));
    for(int i = 0; i < numsSize - 1; i++){
        for(int j = i; j < numsSize - 1; j++){
            if(nums[i] + nums[j+1] == target){
                result[0] = i;
                result[1] = j+1;
            }
        }
    }
    *returnSize = 2;
    return result;
}