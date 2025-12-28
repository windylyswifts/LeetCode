int countNegatives(int** grid, int gridSize, int* gridColSize) {
    int result = 0;
    for(int i = 0; i < gridSize; i++){
        for(int j = (*gridColSize) - 1; j > -1; j--){
            if(grid[i][j] < 0) result++;
            else break;
        }
    }
    return result;
}