/**
 * P182PROH - https://www.spoj.com/PTIT/problems/P182PROH
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<string.h>

void plus(char* a) {
    int hour = (a[0] - 48) * 10 + (a[1] - 48);
    hour += 12;
    printf("%d", hour);
}

int main() {
    char hours[20]; scanf("%s", hours);
    if (hours[strlen(hours) - 2] == 'A') {
        if (hours[0] == '1' && hours[1] == '2') {
            printf("00");
            for (unsigned i = 2; i < strlen(hours) - 2; ++i) printf("%c", hours[i]);
        } else
            for (unsigned i = 0; i < strlen(hours) - 2; ++i) printf("%c", hours[i]);
    }
    else {
        if (hours[0] == '1' && hours[1] == '2') {
            printf("12");
            for (unsigned i = 2; i < strlen(hours) - 2; ++i) printf("%c", hours[i]);
        } else {
            char hour[3] = {hours[0], hours[1]};
            plus(hour);
            for (unsigned i = 2; i < strlen(hours) - 2; ++i) printf("%c", hours[i]);
        }
    }
    return 0;
}
