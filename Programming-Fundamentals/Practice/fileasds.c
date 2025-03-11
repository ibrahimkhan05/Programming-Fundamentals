#include <stdio.h>
#include <stdlib.h>

int main() {
    
    char *sourceFilename = "source_image.jpg";  // Change to your source image file
    char *destFilename = "copied_image.jpg";    // Destination file name

    // Open the source image file in binary read mode
    FILE *fp = fopen(sourceFilename, "rb");
    if (fp == NULL) {
        printf("Error opening source file.\n");
        return 1;

    }

    // Open/Create the destination image file in binary write mode
    FILE *fp2 = fopen(destFilename, "wb");
    if (fp2 == NULL) {
        printf("Error creating/opening destination file.\n");
        fclose(fp);
        return 1;
    }

    // Buffer to hold the file data
    char buffer[1024];
    char bytesRead[1024];

    // Copy file content
    while ((fread(buffer, 1, sizeof(buffer), fp))) {
        fwrite(buffer, 1, sizeof(buffer), fp2);
    }

    // Close both files
    fclose(fp);
    fclose(fp2);

    printf("Image copied successfully!\n");

    return 0;
}
