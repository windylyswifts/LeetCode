int minDeletionSize(char** strs, int strsSize) {
    int result = 0;
    int length = strlen(strs[0]);
    for(int i = 0; i < length; i++){
        for(int j = 0; j < strsSize - 1; j++){
            if(strs[j][i] > strs[j+1][i]){
                result++;
                break;
            }
        }
    }

    return result;
}