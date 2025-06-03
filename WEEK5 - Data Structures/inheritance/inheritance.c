#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Each person has two parents and two alleles
typedef struct person
{
    struct person *parents[2]; // Array to store pointers to two parents
    char alleles[2]; // Two alleles (blood type genes), e.g., A, B, O
} person;

const int GENERATIONS = 3; // Number of generations to create
const int INDENT_LENGTH = 4; // Indentation length for printing family tree

person *create_family(int generations); // Function to create a family tree
void print_family(person *p, int generation); // Function to print family tree
void free_family(person *p); // Function to free allocated memory for family
char random_allele(); // Function to randomly choose a blood type allele

int main(void)
{
    // Seed random number generator to get different results each time
    srand(time(0));

    // Create a new family with three generations
    person *p = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(p, 0);

    // Free allocated memory to avoid memory leaks
    free_family(p);
}

// Create a new individual with `generations` number of generations
person *create_family(int generations)
{
    // Allocate memory for a new person
    person *newPerson = malloc(sizeof(person));

    // Check if memory allocation was successful
    if (newPerson == NULL)
    {
        printf("Error Allocating Memory for Person");
        return NULL;
    }

    // If there are generations left to create, recursively create parents
    if (generations > 1)
    {
        // Create two new parents by recursively calling create_family
        person *parent0 = create_family(generations - 1);
        person *parent1 = create_family(generations - 1);

        // Set parent pointers for current person
        newPerson->parents[0] = parent0;
        newPerson->parents[1] = parent1;

        // Randomly assign current person's alleles based on the alleles of their parents
        // Each allele comes from one of the parents
        newPerson->alleles[0] = parent0->alleles[rand() % 2]; // Randomly choose from parent's alleles
        newPerson->alleles[1] = parent1->alleles[rand() % 2]; // Randomly choose from parent's alleles
    }
    // If there are no generations left to create (base case)
    else
    {
        // Set parent pointers to NULL (no parents in the base case)
        newPerson->parents[0] = NULL;
        newPerson->parents[1] = NULL;

        // Randomly assign alleles (base case where the individual has no parents)
        newPerson->alleles[0] = random_allele();
        newPerson->alleles[1] = random_allele();
    }

    // Return the newly created person
    return newPerson;
}

// Free `p` and all ancestors of `p` to avoid memory leaks
void free_family(person *p)
{
    // Base case: if person is NULL, do nothing
    if (p == NULL)
    {
        return;
    }

    // Recursively free parents first (if any)
    free_family(p->parents[0]);
    free_family(p->parents[1]);

    // Free current person
    free(p);
}

// Print each family member and their alleles (blood types)
void print_family(person *p, int generation)
{
    // Base case: if person is NULL, stop recursion
    if (p == NULL)
    {
        return;
    }

    // Print indentation for better visualization of family tree
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print the current person and their blood type (based on alleles)
    if (generation == 0)
    {
        printf("Child (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else if (generation == 1)
    {
        printf("Parent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else
    {
        for (int i = 0; i < generation - 2; i++)
        {
            printf("Great-");
        }
        printf("Grandparent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }

    // Recursively print parents of current person (next generation)
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Randomly chooses a blood type allele (A, B, or O)
char random_allele()
{
    int r = rand() % 3; // Random number between 0 and 2
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}
