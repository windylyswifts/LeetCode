bool isSubsequence(char* s, char* t) {
    if (strlen(s) == 0) return true; 
    int SCounter = 0, tCounter = 0;
    while(t[tCounter] != '\0') {
        if(s[SCounter] == t[tCounter]) {
            SCounter++;
        }
        if(s[SCounter] == '\0') return true;
        tCounter++;
    }    
    return false;
}