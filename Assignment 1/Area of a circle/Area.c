#include <stdio.h>
#include <stdlib.h>

int main()
{
  double area;
 const double pi= 3.142;
  double r;

  printf("Input radius\n");
  scanf("%lf",&r) ;
  area= pi*r*r;
  printf("The are is %lf",area) ;

    return 0;
}
