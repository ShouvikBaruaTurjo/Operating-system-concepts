#include<stdio.h>

// Function to allocate memory to blocks as per First Fit algorithm with fixed-size partitions
void firstFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n]; // Array to store block ID allocated to each process

    // Initially, no block is assigned to any process
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Allocate each process to the first suitable block (fixed-size partition)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Check if block is large enough and not yet allocated
            if (blockSize[j] >= processSize[i] && blockSize[j] != -1) {
                // Allocate block j to the ith process
                allocation[i] = j;

                // Mark the block as occupied (set size to -1)
                blockSize[j] = -1;  // Block is now allocated

                break; // Move to the next process
            }
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
int main()
{
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

    // Call the First Fit function with fixed-size partitions
    firstFit(blockSize, m, processSize, n);

    return 0;
}
