#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int caseNumber = 1;
    while (1) {
        int N, Q;
        scanf("%d %d", &N, &Q);

        if (N == 0 && Q == 0) break;

        int marbles[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &marbles[i]);
        }

        qsort(marbles, N, sizeof(int), compare);

        printf("CASE# %d:\n", caseNumber++);

        for (int i = 0; i < Q; i++) {
            int query;
            scanf("%d", &query);

            int left = 0, right = N - 1, position = -1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (marbles[mid] == query) {
                    position = mid;
                    right = mid - 1;
                } else if (marbles[mid] < query) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            if (position != -1) {
                printf("%d found at %d\n", query, position + 1);
            } else {
                printf("%d not found\n", query);
            }
        }
    }

    return 0;
}
