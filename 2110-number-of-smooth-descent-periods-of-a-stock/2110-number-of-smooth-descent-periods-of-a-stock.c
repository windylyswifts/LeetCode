long long getDescentPeriods(int* prices, int pricesSize) {
    long long result = 0, count = 1;
    for(int i = 0; i < pricesSize; i++){
        if(i == 0 ){
            result += count;
            continue;
        }

        if(prices[i] == prices[i-1] - 1){
            count++;
        }
        else{
            count = 1;
        }
        result += count;

    }
    return result;
}