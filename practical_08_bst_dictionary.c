/*
 * Practical No: 8
 * AIM: A Dictionary stores keywords and its meanings. Provide facility for adding new keywords,
 * deleting keywords, updating values of any entry. Provide a facility to display whole data
 * sorted in ascending/ Descending order. Also find how many maximum comparisons may
 * require for finding any keyword. Use Binary Search Tree for implementation.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char keyword[50];
    char meaning[200];
    struct Node *left, *right;
};

typedef struct Node Node;

Node *createNode(char key[], char meaning[])
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    strcpy(newNode->keyword, key);
    strcpy(newNode->meaning, meaning);
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, char key[], char meaning[])
{
    int cmp;
    if (root == NULL)
        return createNode(key, meaning);

    cmp = strcmp(key, root->keyword);
    if (cmp < 0)
        root->left = insert(root->left, key, meaning);
    else if (cmp > 0)
        root->right = insert(root->right, key, meaning);
    else
        printf("Keyword already exists!\n");

    return root;
}

Node *search(Node *root, char key[], int *comparisons)
{
    while (root != NULL)
    {
        (*comparisons)++;
        int cmp = strcmp(key, root->keyword);
        if (cmp == 0)
            return root;
        else if (cmp < 0)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

Node *findMin(Node *root)
{
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}

Node *deleteNode(Node *root, char key[])
{
    int cmp;
    Node *temp;
    if (root == NULL)
        return NULL;

    cmp = strcmp(key, root->keyword);
    if (cmp < 0)
        root->left = deleteNode(root->left, key);
    else if (cmp > 0)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
        temp = findMin(root->right);
        strcpy(root->keyword, temp->keyword);
        strcpy(root->meaning, temp->meaning);
        root->right = deleteNode(root->right, temp->keyword);
    }
    return root;
}

void updateMeaning(Node *root)
{
    char key[50], meaning[200];
    int comparisons = 0;
    printf("Enter keyword to update: ");
    scanf(" %49[^\n]", key);
    Node *temp = search(root, key, &comparisons);
    if (temp == NULL)
    {
        printf("Keyword not found!\n");
        return;
    }
    printf("Enter new meaning: ");
    scanf(" %199[^\n]", meaning);
    strcpy(temp->meaning, meaning);
    printf("Meaning updated successfully.\n");
}

void ascending(Node *root)
{
    if (root != NULL)
    {
        ascending(root->left);
        printf("%s : %s\n", root->keyword, root->meaning);
        ascending(root->right);
    }
}

void descending(Node *root)
{
    if (root != NULL)
    {
        descending(root->right);
        printf("%s : %s\n", root->keyword, root->meaning);
        descending(root->left);
    }
}

int height(Node *root)
{
    int leftHeight, rightHeight;
    if (root == NULL)
        return 0;
    leftHeight = height(root->left);
    rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

void freeTree(Node *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main()
{
    Node *root = NULL, *temp;
    char key[50], meaning[200];
    int choice, comparisons;

    do
    {
        printf("\n===== DICTIONARY MENU =====\n");
        printf("1. Add Keyword\n");
        printf("2. Delete Keyword\n");
        printf("3. Update Meaning\n");
        printf("4. Search Keyword\n");
        printf("5. Display Ascending Order\n");
        printf("6. Display Descending Order\n");
        printf("7. Maximum Comparisons\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter keyword: ");
            scanf(" %49[^\n]", key);
            printf("Enter meaning: ");
            scanf(" %199[^\n]", meaning);
            int dummy = 0;
            temp = search(root, key, &dummy);
            if (temp != NULL)
                printf("Keyword already exists!\n");
            else
            {
                root = insert(root, key, meaning);
                printf("Keyword added successfully.\n");
            }
            break;

        case 2:
            printf("Enter keyword to delete: ");
            scanf(" %49[^\n]", key);
            comparisons = 0;
            temp = search(root, key, &comparisons);
            if (temp == NULL)
                printf("Keyword not found!\n");
            else
            {
                root = deleteNode(root, key);
                printf("Keyword deleted successfully.\n");
            }
            break;

        case 3:
            updateMeaning(root);
            break;

        case 4:
            printf("Enter keyword to search: ");
            scanf(" %49[^\n]", key);
            comparisons = 0;
            temp = search(root, key, &comparisons);
            if (temp != NULL)
            {
                printf("Meaning: %s\n", temp->meaning);
                printf("Comparisons: %d\n", comparisons);
            }
            else
            {
                printf("Keyword not found!\n");
                printf("Comparisons: %d\n", comparisons);
            }
            break;

        case 5:
            printf("\nDictionary in Ascending Order:\n");
            ascending(root);
            break;

        case 6:
            printf("\nDictionary in Descending Order:\n");
            descending(root);
            break;

        case 7:
            printf("Maximum comparisons for a successful search: %d\n", height(root));
            printf("Maximum comparisons for an unsuccessful search: at most %d\n", height(root) + 1);
            break;

        case 8:
            printf("Exiting Dictionary...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 8);

    freeTree(root);
    return 0;
}
