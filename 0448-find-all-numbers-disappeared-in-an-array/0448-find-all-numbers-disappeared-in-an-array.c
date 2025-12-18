/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int storage[numsSize];
    int counter = 0;

    int *checklist = calloc(numsSize+1, sizeof(int));
    checklist[0] = 1;

    for(int i = 0; i < numsSize; i++){
        int val = nums[i];
        checklist[val]++;
    }
    for(int i = 0; i <= numsSize; i++){
        if(checklist[i] == 0){
            storage[counter] = i;
            counter++; 
        }
    }
    int *result = malloc(counter * sizeof(int));
    for(int i = 0; i < counter; i++){
        result[i] = storage[i];
    }
    *returnSize = counter;
    free(checklist);
    return result;
}