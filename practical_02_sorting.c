/*
 * Practical No: 2
 * AIM: Write a program to store the first-year percentage of students in an array.
 * Write function for sorting array of floating-point numbers in ascending order using:
 * - Selection Sort
 * - Bubble sort
 * and display top five scores.
 */

#include <stdio.h>

#define MAX 100

void selectionSort(float a[], int n)
{
    int i, j, min;
    float temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void bubbleSort(float a[], int n)
{
    int i, j;
    float temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void displayTopFive(float a[], int n)
{
    int i, count = 0;
    printf("\nTop scores in descending order:\n");
    for (i = n - 1; i >= 0 && count < 5; i--)
    {
        printf("%.2f%%\n", a[i]);
        count++;
    }
}

int main()
{
    float a[MAX];
    int n, i, choice;

    printf("Enter number of students (1-100): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of students!\n");
        return 0;
    }

    printf("Enter first-year percentages:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &a[i]);
        if (a[i] < 0 || a[i] > 100)
        {
            printf("Invalid percentage! Enter values from 0 to 100.\n");
            return 0;
        }
    }

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Selection Sort\n");
        printf("2. Bubble Sort\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            selectionSort(a, n);
            printf("Array sorted using Selection Sort.\n");
            displayTopFive(a, n);
            break;

        case 2:
            bubbleSort(a, n);
            printf("Array sorted using Bubble Sort.\n");
            displayTopFive(a, n);
            break;

        case 3:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 3);

    return 0;
}
