int minimumBoxes(int* apple, int appleSize, int* capacity, int capacitySize) {
    int sumofAp = 0;
    int counter = 0;
    for(int i = 0; i < appleSize; i++){
        sumofAp += apple[i];
    }
    int *usedCap = calloc(capacitySize, sizeof(int));
    while (sumofAp > 0) {
        int highestval = -1;
        int bestIndex = -1;
        for(int j = 0; j < capacitySize; j++){
            if(usedCap[j] == 0 && capacity[j] > highestval){
                highestval = capacity[j];
                bestIndex = j;
            }
        }
        if(bestIndex == -1) break; 
        usedCap[bestIndex] = 1; 
        sumofAp -= highestval;
        counter++;
    }

    free(usedCap); 
    return counter;
}