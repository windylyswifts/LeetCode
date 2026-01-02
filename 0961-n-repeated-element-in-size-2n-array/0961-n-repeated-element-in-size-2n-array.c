int repeatedNTimes(int* nums, int numsSize) {
    int result, streak = 0;
    for(int i = 0; i< numsSize;i++){
        int temp = nums[i];
        for(int j = 0;j < numsSize; j++){
            if(temp == nums[j]) streak++;
        }
        if(streak > 1){
            result = nums[i];
            break;
        }else streak = 0;
    }
    return result;
}