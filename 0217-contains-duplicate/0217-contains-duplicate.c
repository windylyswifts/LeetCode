bool containsDuplicate(int* nums, int numsSize) {
    int *checklist = nums, streak = 0;
    for(int i = 0; i < numsSize; i++){
        for(int j = 0; j < numsSize;j++){
            if(checklist[i] == nums[j]) streak++;
        }
        if(streak > 1) return true;
        else streak = 0;
    }
    return false;
}