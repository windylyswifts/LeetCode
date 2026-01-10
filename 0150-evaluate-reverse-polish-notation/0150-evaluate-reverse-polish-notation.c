int evalRPN(char** tokens, int tokensSize) {
    int top = -1;
    int *stack = malloc(tokensSize * sizeof(int));
    for(int i = 0; i < tokensSize; i++){
        char *t = tokens[i];
        if (strlen(t) > 1 || (t[0] >= '0' && t[0] <= '9')) {
            top++;
            stack[top] = atoi(t);
        } else {
            switch(t[0]){
                case '+': { 
                    int b = stack[top--]; 
                    int a = stack[top--]; 
                    stack[++top] = a + b;
                    break;
                }
                case '-': {
                    int rightSide = stack[top--]; 
                    int leftSide = stack[top--];  
                    stack[++top] = leftSide - rightSide; 
                    break;
                }
                case '/': {
                    int rightSide = stack[top--]; 
                    int leftSide = stack[top--];  
                    stack[++top] = leftSide / rightSide; 
                    break;
                }
                case '*': {
                    int b = stack[top--]; 
                    int a = stack[top--]; 
                    stack[++top] = a * b;
                    break;
                }
                default:
                    break;
            }
        }
    }
    return stack[top];
}