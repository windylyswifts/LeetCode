#define MAX(a, b) ((a) > (b) ? (a) : (b))
int largestRectangleArea(int* heights, int heightsSize) {
    int* stack = (int*)malloc(sizeof(int) * (heightsSize + 1));
    int top = -1; 
    int maxArea = 0;    
    stack[++top] = -1;

    for (int i = 0; i < heightsSize; i++) {
        while (top > 0 && heights[stack[top]] >= heights[i]) {
            int height = heights[stack[top]];
            top--; 
            int width = i - stack[top] - 1;
            maxArea = MAX(maxArea, height * width);
        }
        stack[++top] = i; 
    }

    while (top > 0) {
        int height = heights[stack[top]];
        top--;
        int width = heightsSize - stack[top] - 1;
        maxArea = MAX(maxArea, height * width);
    }

    free(stack);
    return maxArea;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0) return 0;
    
    int cols = matrixColSize[0];
    int* heights = (int*)calloc(cols, sizeof(int)); 
    int maxArea = 0;

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1') {
                heights[j] += 1;
            } else {
                heights[j] = 0;
            }
        }
        
        int currentArea = largestRectangleArea(heights, cols);
        maxArea = MAX(maxArea, currentArea);
    }

    free(heights);
    return maxArea;
}