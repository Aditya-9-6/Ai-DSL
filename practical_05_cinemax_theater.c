/*
 * Practical No: 5
 * AIM: The ticket booking system of Cinemax theater has to be implemented.
 * There are 10 rows and 7 seats in each row. Doubly linked list has to be
 * maintained to keep track of free seats in rows. Assume some random booking
 * to start with. Use an array to store pointers (Head pointer) to each row.
 * On demand:
 * a) The list of available seats is to be displayed
 * b) The seats are to be booked
 * c) The booking can be cancelled.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define SEATS 7

struct Node
{
    int seatNo;
    struct Node *prev;
    struct Node *next;
};

typedef struct Node Node;

Node *head[ROWS];

int isAvailable(int row, int seat)
{
    Node *temp = head[row];
    while (temp != NULL)
    {
        if (temp->seatNo == seat)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void insertSeat(int row, int seat)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->seatNo = seat;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head[row] == NULL)
    {
        head[row] = newNode;
    }
    else
    {
        Node *temp = head[row];
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void bookSeat(int row, int seat)
{
    Node *temp = head[row];
    while (temp != NULL && temp->seatNo != seat)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Seat is already booked or invalid!\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head[row] = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Seat booked successfully! Row %d, Seat %d\n", row + 1, seat);
}

void cancelBooking(int row, int seat)
{
    if (isAvailable(row, seat))
    {
        printf("This seat is already free!\n");
        return;
    }
    insertSeat(row, seat);
    printf("Booking cancelled! Row %d, Seat %d is now free.\n", row + 1, seat);
}

void displaySeats()
{
    int i;
    Node *temp;
    printf("\n--- AVAILABLE SEATS ---\n");
    for (i = 0; i < ROWS; i++)
    {
        printf("Row %d: ", i + 1);
        temp = head[i];
        if (temp == NULL)
            printf("No seats available");
        while (temp != NULL)
        {
            printf("%d ", temp->seatNo);
            temp = temp->next;
        }
        printf("\n");
    }
}

void initialize()
{
    int i, j, row, seat;
    int booked[ROWS][SEATS] = {0};

    for (i = 0; i < ROWS; i++)
        head[i] = NULL;

    srand((unsigned int)time(NULL));
    for (i = 0; i < 5; i++)
    {
        row = rand() % ROWS;
        seat = rand() % SEATS;
        booked[row][seat] = 1;
    }

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < SEATS; j++)
        {
            if (!booked[i][j])
                insertSeat(i, j + 1);
        }
    }
    printf("Theater initialized with 5 random bookings.\n");
}

void freeAll()
{
    int i;
    Node *temp, *nextNode;
    for (i = 0; i < ROWS; i++)
    {
        temp = head[i];
        while (temp != NULL)
        {
            nextNode = temp->next;
            free(temp);
            temp = nextNode;
        }
        head[i] = NULL;
    }
}

int main()
{
    int choice, row, seat;
    initialize();

    do
    {
        printf("\n===== CINEMAX THEATER =====\n");
        printf("1. Display Available Seats\n");
        printf("2. Book a Seat\n");
        printf("3. Cancel Booking\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displaySeats();
            break;

        case 2:
            printf("Enter row number (1-10): ");
            scanf("%d", &row);
            printf("Enter seat number (1-7): ");
            scanf("%d", &seat);
            if (row < 1 || row > ROWS || seat < 1 || seat > SEATS)
            {
                printf("Invalid row or seat number!\n");
            }
            else
            {
                bookSeat(row - 1, seat);
            }
            break;

        case 3:
            printf("Enter row number (1-10): ");
            scanf("%d", &row);
            printf("Enter seat number (1-7): ");
            scanf("%d", &seat);
            if (row < 1 || row > ROWS || seat < 1 || seat > SEATS)
            {
                printf("Invalid row or seat number!\n");
            }
            else
            {
                cancelBooking(row - 1, seat);
            }
            break;

        case 4:
            printf("Thank you for using Cinemax!\n");
            break;

        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    freeAll();
    return 0;
}
