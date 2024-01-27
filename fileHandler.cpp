#include <stdio.h>

// Define the structure for a student record
struct Student {
    char name[50];
    int marks;
};

int main() {
    // Open the input file for reading
    FILE *inputFile = fopen("students.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Open a temporary file for writing
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        perror("Error opening temporary file");
        fclose(inputFile);
        return 1;
    }

    // Read records from the input file, filter, and write to the temporary file
    struct Student student;
    while (fscanf(inputFile, "%49s %d", student.name, &student.marks) == 2) {
        if (student.marks >= 250) {
            fprintf(tempFile, "%s %d\n", student.name, student.marks);
        }
    }

    // Close both files
    fclose(inputFile);
    fclose(tempFile);

    //Remove the original file
    if (remove("students.txt") != 0) {
        perror("Error deleting original file");
        return 1;
    }

    //Rename the temporary file to the original file
    if (rename("temp.txt", "students.txt") != 0) {
        perror("Error renaming temporary file");
        return 1;
    }

    printf("Records with marks less than 250 have been deleted.\n");

    return 0;
}
