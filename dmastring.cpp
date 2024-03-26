#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int numStrings;

    // Get the number of strings from the user
    printf("Enter the number of strings: ");
    scanf("%d", &numStrings);

    // Allocate memory for an array of strings
    char **stringArray = (char **)malloc(numStrings * sizeof(char *));

    // Input strings
    for (int i = 0; i < numStrings; i++) {
        char buffer[100]; // Assuming a maximum string length of 99 characters
        printf("Enter string %d: ", i + 1);
        scanf("%s", buffer);

        // Allocate memory for the current string and copy it
        stringArray[i] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(stringArray[i], buffer);
    }

    // Display the entered strings
    printf("\nEntered strings:\n");
    for (int i = 0; i < numStrings; i++) {
        printf("String %d: %s\n", i + 1, stringArray[i]);
    }

    // Free the allocated memory for each string
    for (int i = 0; i < numStrings; i++) {
        free(stringArray[i]);
    }

    // Free the memory for the array of strings
    free(stringArray);

    return 0;
}
