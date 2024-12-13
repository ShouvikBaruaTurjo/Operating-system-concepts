#include <stdio.h>
#include <limits.h> // For INT_MAX

// Function to allocate memory to blocks as per Best Fit algorithm
void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n]; // Array to store block ID allocated to each process

    // Initially, no block is assigned to any process
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Allocate each process to the best-fit block
    for (int i = 0; i < n; i++) {
        int bestIndex = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIndex == -1 || blockSize[j] < blockSize[bestIndex]) {
                    bestIndex = j;
                }
            }
        }

        // If a suitable block was found, allocate it
        if (bestIndex != -1) {
            allocation[i] = bestIndex;
            blockSize[bestIndex] -= processSize[i];
        }
    }

    // Display results
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf(" %d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

// Driver code
int main() {
    int m, n;

    // Input the number of memory blocks
    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);

    int blockSize[m];
    printf("Enter the sizes of the memory blocks:\n");
    for (int i = 0; i < m; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processSize[n];
    printf("Enter the sizes of the processes:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    // Call the Best Fit function
    bestFit(blockSize, m, processSize, n);

    return 0;
}
