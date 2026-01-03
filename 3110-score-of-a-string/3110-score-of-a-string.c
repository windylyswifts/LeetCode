int scoreOfString(char* s) {
    int sizeS = strlen(s);
    int result = 0;
    for(int i = 0; i < sizeS - 1; i++){
        result += abs(s[i] - s[i+1]);
    }
    return result;
}