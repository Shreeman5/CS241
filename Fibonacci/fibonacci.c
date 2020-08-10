#include <stdio.h>


int main()
{
  /*long num = 0;*/
  int a = 0;
  int c = 0;
  int dum = 2;
  int rack[50];
  printf("\n");
  printf("Warning: Please enter a number between 0 and 47 inclusive\n");
  printf("because fibonacci sequence starts at the 0th term.\n");
  printf("Also, my code will produce a result quickly until\n");
  printf("the 40th term, about 10-20 seconds to get terms 41-47\n");
  printf("and more than 10-30 seconds(could be 100s, could be 1000s etc.)\n");
  printf("to get past the 47th term.\n");
  printf("\nPlease enter the number: ");
  while((c = getchar()) != '\n')
  {
    if (c == '-')
    {
      printf("Please follow instructions next time.\n");
      return 2;
    }
    a = (10 * a) + (c - '0');
  }
  if (a > 47)
  {
    printf("Please follow instructions next time.\n");
    return 1;
  }
  rack[0] = 0;
  rack[1] = 1;
  while(dum < 50)
  {
    rack[dum] = rack[dum - 1] + rack[dum - 2];
    dum++;
  }
  /*num =(long) getValue(a);*/
  printf("Here is the %d(st/nd/th) number: %d.\n", a, rack[a - 1]);
  printf("\n");
  return 0;
}

/*int getValue(int a)
{
  if (a == 1)
  {
    return 0;
  }
  else if (a == 2)
  {
    return 1;
  }
  else
  {
    return getValue(a - 1) + getValue(a - 2);
  }   
  }*/
