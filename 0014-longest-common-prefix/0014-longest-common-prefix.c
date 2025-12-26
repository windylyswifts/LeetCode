char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return ""; 
    
    int sizeChar = strlen(strs[0]); 
    int error = 0;
    int length = 0; 
    
    char *result = malloc((sizeChar + 1) * sizeof(char));
    
    for(int i = 0; i < sizeChar; i++){
        for(int j = 0; j < strsSize - 1; j++){
            if(strs[j][i] != strs[j+1][i]) {
                error = 1; 
                break; 
            }
        }
        
        if(error) break; 
        
        result[i] = strs[0][i];
        length++; 
    }
    
    // FIX 3: Add the Null Terminator at the end!
    result[length] = '\0';
    
    return result;
}