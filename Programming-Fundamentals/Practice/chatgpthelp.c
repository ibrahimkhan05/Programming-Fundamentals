#include <stdio.h>
#include <stdlib.h>

// Define the structure
struct studentData {
    char student_name[50];
    int student_semester;
    char student_grade;
    float student_cgpa;
};

int main() {
    // Create an instance of the structure and fill it with data
    struct studentData student = {
        "John Doe",
        3,
        'A',
        3.85
    };

    // Open the file in binary write mode
    FILE *file = fopen("studentData.bin", "wb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Write the structure to the file in one go
    if (fwrite(&student, sizeof(struct studentData), 1, file) != 1) {
        perror("Error writing to file");
        fclose(file);
        return 1;
    }

    printf("Data saved to file successfully.\n");

    // Close the file
    fclose(file);ff
    return 0;
}
