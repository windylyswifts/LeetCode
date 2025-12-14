int countPartitions(int* nums, int numsSize) {
    int count = 0, left = 0, right = 0, sum;
    for(int i = 0; i < numsSize - 1; i++){
        //solving for right
        for(int j = i; j < numsSize - 1; j++){
            right += nums[j+1];
        }
        left += nums[i];
        sum = left - right;
        if(sum % 2 == 0)
            count++;
        right = 0;
    }
    return count;
}