

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    int *result = malloc(numsSize * sizeof(int));
    int temp = 0;   
    for(int i = 0; i < n ;i++){
        result[temp] = nums[i];
        result[temp+1] = nums[i+n];
        temp+=2;
    }
    *returnSize = numsSize;
    return result;
}