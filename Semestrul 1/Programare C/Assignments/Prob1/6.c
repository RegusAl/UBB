// 6. Given the natural number h and m, that represent the current time expressed in
// hours and minutes, compute the time after x hours and y minutes.

#include <stdio.h>

int main() {
    int h, m;
    printf("Current hour: ");
    scanf("%d", &h);
    printf("Current minute: ");
    scanf("%d", &m);

    int x, y;
    printf("X: ");
    scanf("%d", &x);
    printf("Y: ");
    scanf("%d", &y);

    // 
    h += x;
    m += y;
    while(m>=60) {
        m -= 60;
        h++;
    }
    while(h>=24) {
        h -= 24;
    }

    printf("After %d hours and %d minutes the time will be: %d:%d \n", x, y, h, m);
    return 0;
}