typedef struct {
    double start;
    double end;
} Segment;

int compareDoubles(const void* a, const void* b) {
    double arg1 = *(const double*)a;
    double arg2 = *(const double*)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int compareSegments(const void* a, const void* b) {
    Segment* arg1 = (Segment*)a;
    Segment* arg2 = (Segment*)b;
    if (arg1->start < arg2->start) return -1;
    if (arg1->start > arg2->start) return 1;
    return 0;
}

double separateSquares(int** squares, int squaresSize, int* squaresColSize) {
    if (squaresSize == 0) return 0.0;

    int maxEvents = 2 * squaresSize;
    double* y_coords = (double*)malloc(maxEvents * sizeof(double));
    if (!y_coords) return 0.0; 

    int countY = 0;
    for (int i = 0; i < squaresSize; i++) {
        double y = (double)squares[i][1];
        double l = (double)squares[i][2];
        y_coords[countY++] = y;
        y_coords[countY++] = y + l;
    }

    qsort(y_coords, countY, sizeof(double), compareDoubles);

    int uniqueCount = 0;
    for (int i = 0; i < countY; i++) {
        if (i == 0 || y_coords[i] > y_coords[i - 1] + 1e-9) {
            y_coords[uniqueCount++] = y_coords[i];
        }
    }

    Segment* activeSegments = (Segment*)malloc(squaresSize * sizeof(Segment));
    double* widths = (double*)malloc((uniqueCount - 1) * sizeof(double));
    double totalArea = 0.0;

    for (int i = 0; i < uniqueCount - 1; i++) {
        double yBottom = y_coords[i];
        double yTop = y_coords[i + 1];
        double midY = (yBottom + yTop) / 2.0;
        int segCount = 0;

        for (int j = 0; j < squaresSize; j++) {
            double sqY = (double)squares[j][1];
            double sqL = (double)squares[j][2];
            double sqTop = sqY + sqL;

            if (sqY <= midY && sqTop >= midY) {
                activeSegments[segCount].start = (double)squares[j][0];
                activeSegments[segCount].end = (double)squares[j][0] + sqL;
                segCount++;
            }
        }

        double currentWidth = 0.0;
        if (segCount > 0) {
            qsort(activeSegments, segCount, sizeof(Segment), compareSegments);

            double currentStart = activeSegments[0].start;
            double currentEnd = activeSegments[0].end;

            for (int k = 1; k < segCount; k++) {
                if (activeSegments[k].start < currentEnd) {
                    if (activeSegments[k].end > currentEnd) {
                        currentEnd = activeSegments[k].end;
                    }
                } else {
                    currentWidth += (currentEnd - currentStart);
                    currentStart = activeSegments[k].start;
                    currentEnd = activeSegments[k].end;
                }
            }
            currentWidth += (currentEnd - currentStart);
        }

        widths[i] = currentWidth;
        totalArea += currentWidth * (yTop - yBottom);
    }

    double targetArea = totalArea / 2.0;
    double currentArea = 0.0;
    double resultY = y_coords[uniqueCount - 1]; 

    for (int i = 0; i < uniqueCount - 1; i++) {
        double stripHeight = y_coords[i + 1] - y_coords[i];
        double stripArea = widths[i] * stripHeight;

        if (currentArea + stripArea >= targetArea) {
            double neededArea = targetArea - currentArea;
            if (widths[i] > 1e-9) {
                resultY = y_coords[i] + (neededArea / widths[i]);
            } else {
                resultY = y_coords[i];
            }
            break;
        }
        currentArea += stripArea;
    }

    free(y_coords);
    free(activeSegments);
    free(widths);

    return resultY;
}