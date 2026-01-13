typedef struct {
    int y;
    int weight; 
} Event;

int compareEvents(const void* a, const void* b) {
    Event* e1 = (Event*)a;
    Event* e2 = (Event*)b;
    
    if (e1->y != e2->y) {
        return (e1->y < e2->y) ? -1 : 1;
    }
    return (e1->weight < e2->weight) ? -1 : 1;
}

double separateSquares(int** squares, int squaresSize, int* squaresColSize) {
    int numEvents = squaresSize * 2;
    Event* events = (Event*)malloc(numEvents * sizeof(Event));
    
    int idx = 0;
    for (int i = 0; i < squaresSize; i++) {
        int y = squares[i][1];
        int l = squares[i][2];
        
        events[idx].y = y;
        events[idx].weight = l;
        idx++;
        
        events[idx].y = y + l;
        events[idx].weight = -l;
        idx++;
    }
    
    qsort(events, numEvents, sizeof(Event), compareEvents);
    
    double total = 0;
    double curr = 0; 
    double pv = 0;   
    
    for (int i = 0; i < numEvents; i++) {
        double y = (double)events[i].y;
        double width = (double)events[i].weight;
        
        total += curr * (y - pv);
        curr += width;
        pv = y;
    }
    
    double half_area = total / 2.0;
    curr = 0;
    pv = 0;
    total = 0; 
    for (int i = 0; i < numEvents; i++) {
        double y = (double)events[i].y;
        double width = (double)events[i].weight;
        
        double next_area = total + curr * (y - pv);
        
        if (next_area >= half_area) {
            double result = pv + (half_area - total) / curr;
            free(events); 
            return result;
        }
        
        total = next_area;
        curr += width;
        pv = y;
    }
    
    free(events);
    return pv;
}