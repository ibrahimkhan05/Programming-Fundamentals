#include <stdio.h>

int main() {
    char *myfile = "binary.bin";
    FILE *fp = fopen(myfile, "wb");
    int arr[] = {2, 4, 8, 10};
    int items_written = fwrite(arr, sizeof(int), 5,fp);
    int arr2[10];
    fclose(fp);
    int i = 0;
    fp = fopen(myfile, "rb");
    while(fread(&arr2[i], sizeof(int), 1, fp )) {
        printf("%d ", arr2[i]);
        i++;
    }

}