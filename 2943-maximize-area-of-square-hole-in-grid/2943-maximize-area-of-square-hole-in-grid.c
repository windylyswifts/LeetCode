int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int maxGap(int* arr, int n) {
    qsort(arr, n, sizeof(int), cmp);
    int best = 1, cur = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i-1] + 1) cur++;
        else cur = 1;
        if (cur > best) best = cur;
    }
    return best + 1;
}

int maximizeSquareHoleArea(int n, int m, int* hBars, int hSize, int* vBars, int vSize) {
    int h = maxGap(hBars, hSize);
    int v = maxGap(vBars, vSize);
    int side = h < v ? h : v;
    return side * side;
}