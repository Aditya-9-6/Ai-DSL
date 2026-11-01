/*
 * Practical No: 9
 * AIM: There are flight paths between cities. If there is a flight between city A and city B then
 * there is an edge between the cities. The cost of the edge can be the time that flight takes
 * to reach city B from A or the amount of fuel used for the journey. Represent this as a
 * graph. The node can be represented by the airport name or name of the city. Use
 * adjacency list representation of the graph or use adjacency matrix representation of the
 * graph. Check whether the graph is connected or not.
 */

#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
char city[MAX][30];
int n;

void addFlight()
{
    int u, v, cost;
    printf("Enter source city number (0 to %d): ", n - 1);
    scanf("%d", &u);
    printf("Enter destination city number (0 to %d): ", n - 1);
    scanf("%d", &v);

    if (u < 0 || u >= n || v < 0 || v >= n || u == v)
    {
        printf("Invalid city numbers!\n");
        return;
    }
    printf("Enter flight cost (time/fuel): ");
    scanf("%d", &cost);
    if (cost <= 0)
    {
        printf("Cost must be positive!\n");
        return;
    }
    graph[u][v] = cost;
    graph[v][u] = cost;
    printf("Flight path added successfully.\n");
}

void displayGraph()
{
    int i, j;
    printf("\nAdjacency Matrix:\n\t");
    for (i = 0; i < n; i++)
        printf("%s\t", city[i]);
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\t", city[i]);
        for (j = 0; j < n; j++)
            printf("%d\t", graph[i][j]);
        printf("\n");
    }
}

void DFS(int v)
{
    int i;
    visited[v] = 1;
    for (i = 0; i < n; i++)
    {
        if (graph[v][i] != 0 && !visited[i])
            DFS(i);
    }
}

void checkConnected()
{
    int i;
    for (i = 0; i < n; i++)
        visited[i] = 0;

    DFS(0);

    for (i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printf("Graph is NOT connected.\n");
            return;
        }
    }
    printf("Graph is connected.\n");
}

int main()
{
    int i, j, choice;
    printf("Enter number of cities (1-%d): ", MAX);
    scanf("%d", &n);
    if (n < 1 || n > MAX)
    {
        printf("Invalid number of cities!\n");
        return 0;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter city name %d: ", i);
        scanf(" %29s", city[i]);
    }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            graph[i][j] = 0;

    do
    {
        printf("\n===== FLIGHT PATH MENU =====\n");
        printf("1. Add Flight Path\n");
        printf("2. Display Graph\n");
        printf("3. Check Connectivity\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addFlight();
            break;
        case 2:
            displayGraph();
            break;
        case 3:
            checkConnected();
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
