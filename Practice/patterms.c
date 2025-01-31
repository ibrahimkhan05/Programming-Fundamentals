#include <stdio.h>

void simpleTriangle();
void fullTrinagle();
void diomand();
void invertedDiomand();
void rectnagle();

void rectnagle() {
    printf("\n");
  for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 15; j++) {
            if (i != 1 && i != 5) {
                if (j == 1 || j == 15) {
                    printf("*");
                     } else {
                        printf(" ");
                     }
            } else {
                printf("*");

            }         
        }
        printf("\n");
      }
}
void invertedDiomand() {
     int spaces = 0;
    int choice = 5;
    for (int i = 1; i <= 10; i++) {
        if (i <= 5) {
            for(int l = 1; l <= spaces; l++) {
            printf(" ");
        }
        for (int k = 1; k <= choice; k++) {
            printf("*");

        }
        for (int m = 1; m < choice; m++) {
            printf("*"); 
        }
        spaces++;
        choice--;
        printf("\n");
             

        } else {
            choice++;
            
            for(int l = 1; l < spaces; l++) {
            printf(" ");
        }
        for (int k = 1; k <= choice; k++) {
            printf("*");

        }
        for (int m = 1; m < choice; m++) {
            printf("*"); 
        }
        spaces--;
        
        printf("\n");
             
        }
       
    }

}

void diomand() {
    int spaces = 5;
    int choice = 5;
    for (int i = 1; i <= 10; i++) {
        if (i <= choice) {
             for(int l = 1; l < spaces; l++) {
            printf(" ");
        }
        for (int k = 1; k <= i; k++) {
            printf("*");

        }
        for (int m = 1; m < i; m++) {
            printf("*"); 
        }
        spaces--;
        printf("\n");

        } else {
             for(int l = 1; l <= spaces; l++) {
            printf(" ");
        }
        for (int k = 1; k <= choice; k++) {
            printf("*");

        }
        for (int m = 1; m < choice; m++) {
            printf("*"); 
        }
        spaces++;
        choice--;
        printf("\n");
        }
       
    }
}
void simpleTriangle(){
 for(int i = 1; i <= 5; i++) {
    for (int j = 1; j <= i; j++) {
        printf("*");
    }
    printf("\n");
 }
}

void fullTrinagle() {
    int spaces = 4;
   for  (int i = 1; i <= 5; i++) {
    for(int l = 1 ; l <= spaces; l++) {
        printf(" ");
    }
    for(int j = 1; j <= i; j++) {
            printf("*");
        }
    for (int k = 1; k <= i-1; k++) {
            printf("*");
        }
        
        spaces--;
        printf("\n");
    }
}
int main () {
    simpleTriangle();
    fullTrinagle();
    printf("*******************\n");
    diomand();
    invertedDiomand();
    rectnagle();
    return 0;
}