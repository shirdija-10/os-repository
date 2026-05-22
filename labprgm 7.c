#include <stdio.h>

int main() {
    int pages[50], frames[10];
    int num_pages, num_frames;
    int i, j, k;
    printf("1BF24CS320");
    printf("Enter number of pages: ");
    scanf("%d", &num_pages);

    printf("Enter page reference string:\n");
    for(i = 0; i < num_pages; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &num_frames);

    // ================= FIFO =================
    int fifo_frames[10];
    int fifo_faults = 0;
    int next = 0;

    for(i = 0; i < num_frames; i++)
        fifo_frames[i] = -1;

    printf("\n--- FIFO Page Replacement ---\n");

    for(i = 0; i < num_pages; i++) {

        int found = 0;

        for(j = 0; j < num_frames; j++) {
            if(fifo_frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(found == 0) {
            fifo_frames[next] = pages[i];
            next = (next + 1) % num_frames;
            fifo_faults++;
        }

        printf("Page %d -> [", pages[i]);

        for(j = 0; j < num_frames; j++) {
            if(fifo_frames[j] != -1)
                printf("%d ", fifo_frames[j]);
        }

        printf("]\n");
    }

    printf("Total Page Faults (FIFO): %d\n", fifo_faults);


    // ================= LRU =================
    int lru_frames[10], time[10];
    int lru_faults = 0;
    int counter = 0;

    for(i = 0; i < num_frames; i++) {
        lru_frames[i] = -1;
        time[i] = 0;
    }

    printf("\n--- LRU Page Replacement ---\n");

    for(i = 0; i < num_pages; i++) {

        int found = 0;

        for(j = 0; j < num_frames; j++) {

            if(lru_frames[j] == pages[i]) {
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }

        if(found == 0) {

            int empty = -1;

            for(j = 0; j < num_frames; j++) {
                if(lru_frames[j] == -1) {
                    empty = j;
                    break;
                }
            }

            if(empty != -1) {
                counter++;
                lru_frames[empty] = pages[i];
                time[empty] = counter;
            }
            else {

                int lru = 0;

                for(j = 1; j < num_frames; j++) {
                    if(time[j] < time[lru]) {
                        lru = j;
                    }
                }

                counter++;
                lru_frames[lru] = pages[i];
                time[lru] = counter;
            }

            lru_faults++;
        }

        printf("Page %d -> [", pages[i]);

        for(j = 0; j < num_frames; j++) {
            if(lru_frames[j] != -1)
                printf("%d ", lru_frames[j]);
        }

        printf("]\n");
    }

    printf("Total Page Faults (LRU): %d\n", lru_faults);


    // ================= OPTIMAL =================
    int opt_frames[10];
    int opt_faults = 0;

    for(i = 0; i < num_frames; i++)
        opt_frames[i] = -1;

    printf("\n--- Optimal Page Replacement ---\n");

    for(i = 0; i < num_pages; i++) {

        int found = 0;

        for(j = 0; j < num_frames; j++) {
            if(opt_frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(found == 0) {

            int empty = -1;

            for(j = 0; j < num_frames; j++) {
                if(opt_frames[j] == -1) {
                    empty = j;
                    break;
                }
            }

            if(empty != -1) {
                opt_frames[empty] = pages[i];
            }
            else {

                int farthest = -1;
                int replace_index = -1;

                for(j = 0; j < num_frames; j++) {

                    int next_use = -1;

                    for(k = i + 1; k < num_pages; k++) {
                        if(opt_frames[j] == pages[k]) {
                            next_use = k;
                            break;
                        }
                    }

                    if(next_use == -1) {
                        replace_index = j;
                        break;
                    }

                    if(next_use > farthest) {
                        farthest = next_use;
                        replace_index = j;
                    }
                }

                opt_frames[replace_index] = pages[i];
            }

            opt_faults++;
        }

        printf("Page %d -> [", pages[i]);

        for(j = 0; j < num_frames; j++) {
            if(opt_frames[j] != -1)
                printf("%d ", opt_frames[j]);
        }

        printf("]\n");
    }

    printf("Total Page Faults (Optimal): %d\n", opt_faults);

    return 0;
}
