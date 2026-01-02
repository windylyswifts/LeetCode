/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** buildArray(int* target, int targetSize, int n, int* returnSize) {
    char **result = malloc(n * 2 * sizeof(char*));
    int streak = 0; 
    int indexResult = 0;
    for(int i = 1; i <= n; i++) {
        if(i == target[streak]) {
            result[indexResult] = "Push";
            indexResult++;
            streak++;
        } else {
            result[indexResult] = "Push";
            indexResult++;
            result[indexResult] = "Pop";
            indexResult++;
        }
        
        if(streak == targetSize) break;
    }
    
    *returnSize = indexResult;
    return result;
}