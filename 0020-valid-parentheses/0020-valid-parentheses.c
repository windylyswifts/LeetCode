bool isValid(char* s) {
    int n = strlen(s);
    char stack[n]; 
    int top = -1; 

    for(int i = 0; i < n; i++) {
        char current = s[i];

        if (current == '(' || current == '{' || current == '[') {
            top++;
            stack[top] = current;
        } 

        else {
            if(top == -1) return 0;
            char open = stack[top];
            char close = s[i];
            if(open == '(' && close == ')') top--;
            else if(open == '{' && close == '}') top--;
            else if(open == '[' && close == ']') top--;
            else return 0;
        }
    }

    if(top == -1) return 1;
    else return 0;
}