#include <stdio.h>
#include <stdlib.h>

int main()
{
    float weight,bmi,h;
    int height;
    printf("enter a weight and height: ");
    scanf("%f%d",&weight,&height);
    h=height*0.01;
    bmi=weight/(h*h);
    printf("%f",bmi);
    return 0;
}
