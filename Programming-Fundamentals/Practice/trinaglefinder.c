# include <stdio.h>

int main (void) {
    float side_1, side_2, side_3;
    printf("Enter the three sides of trinagle: ");
    scanf("%d%d%d", &side_1, &side_2, &side_3);
    if (side_1 == side_2) {
        if(side_1 == side_3){ 
        printf("It is an eqlatural trinagle");
        } else if (side_1 != side_3) {
             printf("It is an iscosacles trinagle");
        }
    } else if (side_2 == side_3 && side_2 != side_1 ){
        printf("It is an iscosacles trinagle");

    } else if (side_1 != side_2){
        if (side_1==side_3){
            printf("It is an iscosacles trinagle");
        } else {
            printf("it is an scalne trinagle");
        }
        
    }
    return 0;
}