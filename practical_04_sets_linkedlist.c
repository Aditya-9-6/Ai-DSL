/*
 * Practical No: 4
 * AIM: Second year Computer Engineering class, set A of students like Vanilla Ice-cream
 * and set B of students like butterscotch ice-cream. Write a program to store two sets
 * using a linked list. Compute and display:
 * a) Set of students who like both vanilla and butterscotch
 * b) Set of students who like either vanilla or butterscotch or not both
 * c) Number of students who like neither vanilla nor butterscotch
 */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int roll;
    struct Node *next;
};

typedef struct Node Node;

Node *insert(Node *head, int roll)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->roll == roll)
        {
            printf("Duplicate roll number ignored.\n");
            return head;
        }
        temp = temp->next;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return head;
    }
    newNode->roll = roll;
    newNode->next = head;
    return newNode;
}

int search(Node *head, int roll)
{
    while (head != NULL)
    {
        if (head->roll == roll)
            return 1;
        head = head->next;
    }
    return 0;
}

void display(Node *head)
{
    if (head == NULL)
    {
        printf("Empty set");
        return;
    }
    while (head != NULL)
    {
        printf("%d ", head->roll);
        head = head->next;
    }
}

int count(Node *head)
{
    int c = 0;
    while (head != NULL)
    {
        c++;
        head = head->next;
    }
    return c;
}

void intersection(Node *A, Node *B)
{
    Node *temp = A;
    printf("Students who like both flavours: ");
    while (temp != NULL)
    {
        if (search(B, temp->roll))
            printf("%d ", temp->roll);
        temp = temp->next;
    }
    printf("\n");
}

void symmetricDifference(Node *A, Node *B)
{
    Node *temp;
    printf("Students who like either flavour, but not both: ");
    temp = A;
    while (temp != NULL)
    {
        if (!search(B, temp->roll))
            printf("%d ", temp->roll);
        temp = temp->next;
    }
    temp = B;
    while (temp != NULL)
    {
        if (!search(A, temp->roll))
            printf("%d ", temp->roll);
        temp = temp->next;
    }
    printf("\n");
}

void neither(Node *A, Node *B, int total)
{
    int unionCount = 0;
    Node *temp = A;
    while (temp != NULL)
    {
        unionCount++;
        temp = temp->next;
    }
    temp = B;
    while (temp != NULL)
    {
        if (!search(A, temp->roll))
            unionCount++;
        temp = temp->next;
    }
    printf("Number of students who like neither: %d\n", total - unionCount);
}

void freeList(Node *head)
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    Node *A = NULL, *B = NULL;
    int choice, roll, n, i, total;

    printf("Enter total number of students in class: ");
    scanf("%d", &total);
    if (total < 0)
    {
        printf("Invalid number of students.\n");
        return 0;
    }

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Add student to Vanilla set (A)\n");
        printf("2. Add student to Butterscotch set (B)\n");
        printf("3. Display both sets\n");
        printf("4. Students who like both flavours\n");
        printf("5. Students who like either flavour, but not both\n");
        printf("6. Count students who like neither flavour\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("How many students like Vanilla? ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                printf("Enter roll number: ");
                scanf("%d", &roll);
                if (roll < 1 || roll > total)
                    printf("Invalid roll number.\n");
                else
                    A = insert(A, roll);
            }
            break;

        case 2:
            printf("How many students like Butterscotch? ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                printf("Enter roll number: ");
                scanf("%d", &roll);
                if (roll < 1 || roll > total)
                    printf("Invalid roll number.\n");
                else
                    B = insert(B, roll);
            }
            break;

        case 3:
            printf("Vanilla set A: ");
            display(A);
            printf("\nButterscotch set B: ");
            display(B);
            printf("\n");
            break;

        case 4:
            intersection(A, B);
            break;

        case 5:
            symmetricDifference(A, B);
            break;

        case 6:
            neither(A, B, total);
            break;

        case 7:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 7);

    freeList(A);
    freeList(B);
    return 0;
}
