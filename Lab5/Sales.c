#include <stdio.h>
#include <stdlib.h>

// Function to calculate the average of an array
double calculateAverage(double array[], int length) {
    double sum = 0.0;
    for (int i = 0; i < length; i++) {
        sum += array[i];
    }
    return sum / length;
}

// Function to generate the six-month moving averages
void generateMovingAverages(double sales[], int numMonths) {
    printf("Six-Month Moving Average Report:\n");
    for (int i = 0; i < numMonths - 5; i++) {
        double average = 0.0;
        for (int j = i; j < i + 6; j++) {
            average += sales[j];
        }
        average /= 6;
        printf("%d - %d $%.2lf\n", i + 1, i + 6, average);
    }
}

int main() {
    const char* months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    int numMonths = 12;
    double sales[12];
    double minSales = 1e9; // Initialize to a large value
    double maxSales = -1e9; // Initialize to a small value
    double totalSales = 0.0;

    printf("Monthly sales report for 2022:\n");
    for (int i = 0; i < numMonths; i++) {
        scanf("%lf", &sales[i]);
        totalSales += sales[i];

        if (sales[i] < minSales) {
            minSales = sales[i];
        }

        if (sales[i] > maxSales) {
            maxSales = sales[i];
        }

        printf("%s $%.2lf\n", months[i], sales[i]);
    }

    printf("Sales summary:\n");
    printf("Minimum sales: $%.2lf (%s)\n", minSales, months[minSales]);
    printf("Maximum sales: $%.2lf (%s)\n", maxSales, months[maxSales]);
    printf("Average sales: $%.2lf\n", totalSales / numMonths);

    generateMovingAverages(sales, numMonths);

    printf("Sales Report (Highest to Lowest):\n");
    for (int i = 0; i < numMonths; i++) {
        int maxIndex = 0;
        for (int j = 0; j < numMonths; j++) {
            if (sales[j] > sales[maxIndex]) {
                maxIndex = j;
            }
        }
        printf("%s $%.2lf\n", months[maxIndex], sales[maxIndex]);
        sales[maxIndex] = -1e9; // Set to a small value to exclude it in the next iteration
    }

    return 0;
}
