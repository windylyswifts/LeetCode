int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int streak = 0, highestStreak = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] != 0){
            streak++;
            if(streak >= highestStreak)
                highestStreak = streak;
        }
        else{
            if(streak >= highestStreak)
                highestStreak = streak;
            streak = 0;
        }
    }

    return highestStreak;
}