/*
 * Practical No: 1
 * AIM: Write menu-based program
 * a) Write a program to store roll numbers of student in array who attended a training
 *    program in random order. Write a function for searching whether a particular student
 *    attended a training program or not, using Linear search.
 * b) Write a program to store roll numbers of student array who attended training
 *    programs in sorted order. Write a function for searching whether a particular student
 *    attended a training program or not, using Binary search.
 */

#include <stdio.h>

#define MAX 100

int linearSearch(int a[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int a[], int n, int key)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int a[MAX], n, i, choice, key, result;
    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Linear Search (Random Order)\n");
        printf("2. Binary Search (Sorted Order)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number of students: ");
            scanf("%d", &n);
            if (n < 1 || n > MAX)
            {
                printf("Invalid number of students!\n");
                break;
            }
            printf("Enter roll numbers in random order:\n");
            for (i = 0; i < n; i++)
                scanf("%d", &a[i]);

            printf("Enter roll number to search: ");
            scanf("%d", &key);

            result = linearSearch(a, n, key);
            if (result != -1)
                printf("Student attended the training program.\n");
            else
                printf("Student did not attend the training program.\n");
            break;

        case 2:
            printf("Enter number of students: ");
            scanf("%d", &n);
            if (n < 1 || n > MAX)
            {
                printf("Invalid number of students!\n");
                break;
            }
            printf("Enter roll numbers in sorted ascending order:\n");
            for (i = 0; i < n; i++)
                scanf("%d", &a[i]);

            printf("Enter roll number to search: ");
            scanf("%d", &key);

            result = binarySearch(a, n, key);
            if (result != -1)
                printf("Student attended the training program.\n");
            else
                printf("Student did not attend the training program.\n");
            break;

        case 3:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
