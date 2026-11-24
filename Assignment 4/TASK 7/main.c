#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int head = 0;
int count = 0;

void insertSample(int value) {
    buffer[head] = value;
    head = (head + 1) % BUFFER_SIZE;

    if (count < BUFFER_SIZE) {
        count++;
    }
}

void printSamples() {
    int start, i;

    if (count < BUFFER_SIZE) {
        start = 0;
    } else {
        start = head;
    }

    printf("Stored samples (oldest to newest): ");
    for (i = 0; i < count; i++) {
        printf("%d ", buffer[(start + i) % BUFFER_SIZE]);
    }
    printf("\n");
}

int main() {
    int n, i, value;

    printf("How many sensor readings will you enter? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter reading %d: ", i + 1);
        scanf("%d", &value);
        insertSample(value);
    }

    printSamples();

    return 0;
}
