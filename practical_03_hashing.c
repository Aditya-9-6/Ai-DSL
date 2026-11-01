/*
 * Practical No: 3
 * AIM: Consider the telephone book database of N clients. Make use of a hash table
 * implementation to quickly look up a client's telephone number. Make use of linear
 * probing, double hashing and quadratic collision handling techniques.
 */

#include <stdio.h>
#include <string.h>

#define SIZE 101

struct Client
{
    char name[50];
    char phone[15];
    int occupied;
};

struct Client hashTable[SIZE];

int hash1(char name[])
{
    int sum = 0, i;
    for (i = 0; name[i] != '\0'; i++)
        sum = (sum + name[i]) % SIZE;
    return sum;
}

int hash2(char name[])
{
    int sum = 0, i;
    for (i = 0; name[i] != '\0'; i++)
        sum = (sum + name[i]) % (SIZE - 1);
    return 1 + sum % (SIZE - 1);
}

void insert(int method)
{
    char name[50], phone[15];
    int index, h, step, i;

    printf("Enter client name: ");
    scanf(" %49[^\n]", name);
    printf("Enter telephone number: ");
    scanf("%14s", phone);

    h = hash1(name);
    step = hash2(name);

    for (i = 0; i < SIZE; i++)
    {
        if (method == 1)
            index = (h + i) % SIZE;
        else if (method == 2)
            index = (h + i * i) % SIZE;
        else
            index = (h + i * step) % SIZE;

        if (!hashTable[index].occupied)
        {
            strcpy(hashTable[index].name, name);
            strcpy(hashTable[index].phone, phone);
            hashTable[index].occupied = 1;
            printf("Client inserted successfully at index %d.\n", index);
            return;
        }
        if (strcmp(hashTable[index].name, name) == 0)
        {
            strcpy(hashTable[index].phone, phone);
            printf("Client already exists. Phone number updated.\n");
            return;
        }
    }
    printf("Hash table is full or no available slot was found.\n");
}

void search(int method)
{
    char name[50];
    int index, h, step, i;

    printf("Enter client name to search: ");
    scanf(" %49[^\n]", name);

    h = hash1(name);
    step = hash2(name);

    for (i = 0; i < SIZE; i++)
    {
        if (method == 1)
            index = (h + i) % SIZE;
        else if (method == 2)
            index = (h + i * i) % SIZE;
        else
            index = (h + i * step) % SIZE;

        if (!hashTable[index].occupied)
        {
            printf("Client not found.\n");
            return;
        }
        if (strcmp(hashTable[index].name, name) == 0)
        {
            printf("Client Name: %s\n", hashTable[index].name);
            printf("Telephone Number: %s\n", hashTable[index].phone);
            return;
        }
    }
    printf("Client not found.\n");
}

void display()
{
    int i;
    printf("\n--- Telephone Book ---\n");
    for (i = 0; i < SIZE; i++)
    {
        if (hashTable[i].occupied)
        {
            printf("Index %d: %s - %s\n", i, hashTable[i].name, hashTable[i].phone);
        }
    }
}

int main()
{
    int choice, method, i;
    for (i = 0; i < SIZE; i++)
        hashTable[i].occupied = 0;

    printf("Choose Collision Handling Technique:\n");
    printf("1. Linear Probing\n");
    printf("2. Quadratic Probing\n");
    printf("3. Double Hashing\n");
    printf("Enter choice: ");
    scanf("%d", &method);

    if (method < 1 || method > 3)
    {
        printf("Invalid technique!\n");
        return 0;
    }

    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Insert Client\n");
        printf("2. Search Telephone Number\n");
        printf("3. Display Telephone Book\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert(method);
            break;
        case 2:
            search(method);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
