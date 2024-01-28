#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int birthyear;
    int birthmonth;
    int birthday;
    int choice;

    printf("\x1b[33m[0] Quit\n");  
    printf("\x1b[32m[1] Calendar\n");  
    printf("\x1b[34m[2] Age\n");  
    printf("-----------------------------\n");
    printf("\x1b[36mEnter your option: \x1b[0m");  
    scanf("%d", &choice);

    if (choice == 0) {
        system("cls");
        printf("\x1b[33mBye!\x1b[0m\n"); 
    } 
    else if (choice == 1) {
        system("cls");
        printf("\x1b[32mThis part is not built yet\x1b[0m\n");  
    } 
    else if (choice == 2) {
        system("cls");
        printf("\x1b[34mEnter your birthdate plz : \x1b[0m");  
        scanf("%d %d %d", &birthyear, &birthmonth, &birthday);
        time_t currentTime;
        time(&currentTime);

        struct tm birthDate = {0};
        birthDate.tm_year = birthyear - 1900;
        birthDate.tm_mon = birthmonth - 1; 
        birthDate.tm_mday = birthday;

        time_t birthTime = mktime(&birthDate);
        double seconds = difftime(currentTime, birthTime);

        int livedyears = seconds / (60 * 60 * 24 * 365.25);
        int livedmonths = (seconds - (livedyears * 60 * 60 * 24 * 365.25)) / (60 * 60 * 24 * 30); 
        int liveddays = (seconds - (livedyears * 60 * 60 * 24 * 365.25) - (livedmonths * 60 * 60 * 24 * 30)) / (60 * 60 * 24);

        printf("\x1b[34m\nYou have lived %d years, %d months, and %d days\x1b[0m\n", livedyears, livedmonths, liveddays);

        struct tm *birthDateStruct = localtime(&birthTime);
        char *dayOfWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        printf("\x1b[34m\n You were born on a %s\x1b[0m\n", dayOfWeek[birthDateStruct->tm_wday]);

        int daysPassed = (365.25*livedyears)+(30*livedmonths)+liveddays;
        printf("\x1b[34m\nDays passed since your birth: %d\x1b[0m\n", daysPassed);

        printf("\x1b[1;31;47mYou're getting old, live a little buddy\x1b[0m\n");
    } 
    else {
        system("cls");
        printf("\x1b[31mInvalid input. Please select a valid option.\x1b[0m\n"); 
    }

    return 0;
}
