int lengthOfLastWord(char* s) {
    int sizeS = strlen(s), found = 0, result = 0;
    for(int i = (sizeS - 1); i != -1; i--){
        if(s[i] != ' ') result++;
        else{
            if(result == 0)continue;
            else break;
        }
    }
    return result;
}