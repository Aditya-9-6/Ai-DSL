/*
 * Practical No: 7
 * AIM: Queues are frequently used in computer programming, and a typical example is the
 * creation of a job queue by an operating system. If the operating system does not use
 * priorities, then the jobs are processed in the order they enter the system. Write C program
 * for simulating job queue. Write functions to add job and delete job from the queue.
 */

#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void addJob()
{
    int job;
    if (rear == MAX - 1)
    {
        printf("Job Queue is Full!\n");
        return;
    }
    printf("Enter Job ID: ");
    scanf("%d", &job);
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = job;
    printf("Job %d added to the queue.\n", job);
}

void deleteJob()
{
    if (front == -1 || front > rear)
    {
        printf("Job Queue is Empty!\n");
        return;
    }
    printf("Job %d is being processed and deleted.\n", queue[front]);
    front++;
    if (front > rear)
    {
        front = rear = -1;
    }
}

void displayQueue()
{
    int i;
    if (front == -1)
    {
        printf("Job Queue is Empty!\n");
        return;
    }
    printf("Jobs waiting in the queue: ");
    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main()
{
    int choice;
    do
    {
        printf("\n--- JOB QUEUE MENU ---\n");
        printf("1. Add Job\n");
        printf("2. Delete Job / Process Job\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addJob();
            break;
        case 2:
            deleteJob();
            break;
        case 3:
            displayQueue();
            break;
        case 4:
            printf("Exiting Job Queue System.\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
