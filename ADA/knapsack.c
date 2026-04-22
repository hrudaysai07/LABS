#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Structure for an item
struct Item {
    int weight;
    int profit;
    float ratio;
};

// Function to swap two items
void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

// Sort items by profit/weight ratio (descending) - Bubble Sort
void sortItems(struct Item arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].ratio < arr[j + 1].ratio) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Fractional Knapsack function
float fractionalKnapsack(struct Item arr[], int n, int capacity) {
    float totalProfit = 0.0;

    for (int i = 0; i < n; i++) {
        if (capacity >= arr[i].weight) {
            // Take full item
            capacity -= arr[i].weight;
            totalProfit += arr[i].profit;
        } else {
            // Take fraction
            totalProfit += arr[i].profit * ((float)capacity / arr[i].weight);
            break;
        }
    }

    return totalProfit;
}

int main() {
    int n, capacity;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item arr[n];

    for (int i = 0; i < n; i++) {
        printf("Enter weight and profit for item %d: ", i + 1);
        scanf("%d %d", &arr[i].weight, &arr[i].profit);
        arr[i].ratio = (float)arr[i].profit / arr[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    start = clock(); // Start timer
    // Sort items by ratio
    sortItems(arr, n);

    float maxProfit = fractionalKnapsack(arr, n, capacity);
    end = clock(); // End timer
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("Maximum profit = %.2f\n", maxProfit);

    printf("CPU time used: %f seconds\n", cpu_time_used);

    return 0;
}
