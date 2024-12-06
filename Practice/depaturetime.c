#include <stdio.h>

int main(void) {
    int user_time_hour, user_time_min, formatted_time_hour;

    //Prompt user
    printf("To find cloest depature and arrival time\nEnter your time 24 hour format(hh:mm): ");
    scanf("%d:%d", &user_time_hour, &user_time_min);

    
    if (user_time_hour > 12 && user_time_hour < 24) {
        formatted_time_hour = user_time_hour % 12;

    
    } else if (user_time_hour > 0 && user_time_hour <= 12) {
        formatted_time_hour = user_time_hour;

    
    } else if ( user_time_hour == 00) {
        formatted_time_hour = 12;

   
    } else {
        printf("Please use correct format!!!!\n ");
    }

  if (user_time_hour >= 21 && user_time_hour < 24 || user_time_hour >=0 && user_time_hour <=7) {
    printf("Closet departure time: 8:00 a.m, arrival: 10:16 a.m");
  } else if (user_time_hour >= 8 && user_time_hour <=9){
    if (formatted_time_hour == 8 && user_time_min == 00){
        printf("You entered an departure time, next depature time: 9:43 a.m, arival: 11:52 a.m");
    } else if (formatted_time_hour == 8 && user_time_min > 00){
        printf("Closet departure time: 9:43 a.m, arrival: 11:52 a.m");
    } else if (formatted_time_hour == 9 && user_time_min == 43) {
        printf("You entered an departure time, next depature time: 11:19 a.m, arival: 1:31 p.m");
        } else if (formatted_time_hour == 9 && user_time_min < 43) {
        printf("Closet departure time: 9:43 a.m, arrival: 11:52 a.m");    
    } else if (formatted_time_hour == 9 && user_time_min > 43 ) {
        printf("Closet departure time: 11:19 a.m, arrival: 1:31 p.m");
    }
  } else if (user_time_hour >= 9 && user_time_hour <=11) {
    if(formatted_time_hour == 11 && user_time_min == 19) {
        printf("You entered an departure time, next depature time: 12:47 p.m, arival: 3:00 p.m");
    } else if (formatted_time_hour == 11 && user_time_min < 19) {
        printf("Closet departure time: 11:19 a.m, arrival: 1:31 p.m");
    } else if (formatted_time_hour == 11 && user_time_min > 19) {
        printf("Closet departure time: 12:47 p.m, arrival: 3:00 p.m");
    }     
    } else if (user_time_hour >=11 && user_time_hour <= 12) {
         if (formatted_time_hour == 12 && user_time_min == 47) {
            printf("You entered an departure time, next depature time: 2:00 p.m, arival: 4:08 p.m");
        } else if (formatted_time_hour == 12 && user_time_min < 47) {
            printf("Closet departure time: 12:47 p.m, arrival: 3:00 p.m");
        } else if (formatted_time_hour == 12 &&  user_time_min > 47) {
            printf("Closet departure time: 2:00 p.m, arrival: 4:08 p.m");
        }
    } else if (user_time_hour >=12 && user_time_hour <= 14){
        if (formatted_time_hour == 2 && user_time_min == 00){
            printf("You entered an departure time, next depature time: 3:45 p.m, arival: 5:55 p.m");
        } else if (formatted_time_hour == 2 && user_time_min > 00) {
            printf("Closet departure time: 3:45 p.m, arrival: 5:55 p.m");
        } else {
            printf("Closet departure time: 2:00 p.m, arrival: 4:08 p.m");
        }
    } else if (user_time_hour >= 14 && user_time_hour <= 15) {
        if (formatted_time_hour == 3 && user_time_min == 45){
            printf("You entered an departure time, next depature time: 7:00 p.m, arival: 9:20 p.m");
        } else if (formatted_time_hour == 3 && user_time_min > 45) {
            printf("Closet departure time: 7:00 p.m, arrival: 9:20 p.m");
        } else if (formatted_time_hour == 3 && user_time_min < 45) {
             printf("Closet departure time: 3:45 p.m, arrival: 5:55 p.m");
            }
    } else if (user_time_hour >= 13 && user_time_hour <= 19) {
        if (formatted_time_hour == 7 && user_time_min == 00){
            printf("You entered an departure time, next depature time: 9:45 p.m, arival: 11:58 p.m");
        } else if(formatted_time_hour == 7 && user_time_hour > 00 ) {
            printf("Closet departure time: 9:45 p.m, arrival: 11:58 p.m");
           
        } else {
            printf("Closet departure time: 7:00 p.m, arrival: 9:20 p.m");
        }
    } else if (user_time_hour >= 19 && user_time_hour <= 21) {
        if(formatted_time_hour == 9 && user_time_min == 45){
            printf("You entered an departure time, next depature time is Tommarrow : 8:00 a.m, arival: 10:16 a.m");
        } else if (formatted_time_hour == 9 && user_time_min < 45) {
            printf("Closet departure time: 7:00 p.m, arrival: 9:20 p.m");
            
        } else if (formatted_time_hour == 9 && user_time_min < 45) {
             printf("Closet departure time Tommarrrow : 8:00 a.m, arrival: 10:16 a.m");
        }
    }
    return 0;
}