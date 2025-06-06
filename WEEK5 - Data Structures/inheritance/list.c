#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    string phrase;
    struct node *next;
}
node;

#define LIST_SIZE 2

//function prototypes
bool unload(node *list);
void visualizer(node *list);

int main(void)
{
    node *list = NULL;

    // Add items to list
    for (int i = 0; i < LIST_SIZE; i++)
    {
        string phrase = get_string("Enter a new phrase: ");

        // TODO: add phrase to new node in list

        node *n = malloc(sizeof(node)); //make a node n to store the new node

        if (n==NULL)
        {
            return 1; //checks for valid allocation of memory for safety
        }

        n->phrase = phrase; //store the phrase inside the new node
        n->next = NULL; //because nothing to store in that yet

        n->next = list; //connect next node to list (currently NULL)
        list = n; //Change list to address of n to update


        // Visualize list after adding a node.
        visualizer(list);
    }

    // Free all memory used
    if (!unload(list))
    {
        printf("Error freeing the list.\n");
        return 1;
    }

    printf("Freed the list.\n");
    return 0;
}

bool unload(node *list)
{
    // TODO: Free all allocated nodes

    node *ptr = list->next;
    free(list);
    list = ptr;
    ptr = list->next;
    free(list);

 /*     while (ptr != NULL){
        ptr = list;
        free(list);
        list = ptr;
    }
*/
    return true;
}

void visualizer(node *list)
{
    printf("\n+-- List Visualizer --+\n\n");
    while (list != NULL)
    {
        printf("Location %p\nPhrase: \"%s\"\nNext: %p\n\n", list, list->phrase, list->next);
        list = list->next;
    }
    printf("+---------------------+\n\n");
}
