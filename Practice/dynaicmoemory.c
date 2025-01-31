#include <stdio.h>
#include <stdlib.h>
int *dynamicMeomory();
int *dynamicMeomory() {
    int *mynumber = (int *)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        *(mynumber + i) = i;
    }
    return mynumber;

}
int main (void) {
    int *location;//ibrahim josis is bc in his family 
    location = dynamicMeomory();
    for (int i = 0; i < 5; i++) {
        printf("Your number %d\n", location[i]);
    }
    char name = '0';
    free(location);
    printf("%c", name);
    return 0;
}