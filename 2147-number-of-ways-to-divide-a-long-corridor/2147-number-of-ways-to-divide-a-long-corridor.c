int numberOfWays(char* corridor) {
    long long mod = 1e9 + 7;
    long long ways = 1;
    int seat_count = 0;
    int last_seat_index = -1;

    for (int i = 0; corridor[i] != '\0'; i++) {
        if (corridor[i] == 'S') {
            seat_count++;

            if (seat_count > 2 && seat_count % 2 != 0) {
                int gap_length = i - last_seat_index;
                ways = (ways * gap_length) % mod;
            }

            last_seat_index = i;
        }
    }

    if (seat_count == 0 || seat_count % 2 != 0) {
        return 0;
    }

    return (int)ways;
}