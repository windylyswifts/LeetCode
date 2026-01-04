bool isAnagram(char* s, char* t) {
    if (strlen(s) != strlen(t)) return false;
    int counter[26] = {0}; 
    for(int i = 0; s[i] != '\0'; i++) {
        counter[s[i] - 'a']++;
        counter[t[i] - 'a']--; 
    }
    for(int i = 0; i < 26; i++) {
        if(counter[i] != 0) return false;
    }

    return true;
}