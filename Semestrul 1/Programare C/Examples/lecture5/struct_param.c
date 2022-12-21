#include <stdio.h>

struct point{
    int x;
    int y;
};
void display(struct point p){
  printf("The x coordinate for the point: %d\n",p.x);
  printf("The y coordinate for the point: %d\n",p.y);
}

int main(){
    struct point pct;
    printf("Enter x value: ");
    scanf("%d",&pct.x);
    printf("Enter y value:");
    scanf("%d",&pct.y);
    display(pct); 
    return 0;
}

