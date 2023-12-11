#define _CRT_SECURE_NO_WARNINGS
/*
Duy Mai
12/10/2023
Today we are going to code out final project setting up Arrays and Sorting according to their last name
in alphabetical order for the first part*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX_PERSONS 20
#define MAX_NAME_LENGTH 50

int compareLastNames(const void* a, const void* b);

int main() {
    char names[MAX_PERSONS][MAX_NAME_LENGTH * 2]; // Two-dimensional array for names (last name, first name)
    int ages[MAX_PERSONS];
    int numPeople = 0;

    // Input data using a sentinel loop
    printf("Enter names and ages. To stop, enter 'stop' for the last name.\n");

    while (numPeople < MAX_PERSONS) {
        printf("Last Name: ");
        scanf("%s", names[numPeople]);

        // Check for the sentinel value to stop input
        if (strcmp(names[numPeople], "stop") == 0) {
            break;
        }

        printf("First Name: ");
        scanf("%s", names[numPeople] + MAX_NAME_LENGTH);

        printf("Age: ");
        scanf("%d", &ages[numPeople]);

        numPeople++;
    }

    // Sort the array based on last names
    qsort(names, numPeople, sizeof(names[0]), compareLastNames);

    // Print the sorted results
    printf("\nSorted Results:\n");
    for (int i = 0; i < numPeople; ++i) {
        printf("%s, %s, Age: %d\n", names[i] + MAX_NAME_LENGTH, names[i], ages[i]);
    }

    return 0;
}

// we put our functions and what it do at the end
int compareLastNames(const void* a, const void* b)
{
    return strcmp(((char(*)[MAX_NAME_LENGTH])a)[1], ((char(*)[MAX_NAME_LENGTH])b)[1]);
}
