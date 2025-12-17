/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {

    int *checklist = calloc(numsSize+1, sizeof(int));
    checklist[0]++;
    int *temp = malloc(numsSize * sizeof(int));
    int storage = 1;

    for(int i = 0; i < numsSize ; i++){
        int val = nums[i];
        checklist[val]++;
    }
    for(int i = 0; i <= numsSize; i++){
        if(checklist[i] == 2)
            temp[0] =  i;
        if(checklist[i] == 0)
            temp[1] = i;
    }  

    free(checklist);
    *returnSize = 2;
    return temp;
}