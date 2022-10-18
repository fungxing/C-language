#include <stdio.h>
#include <string.h>
#define STACKSIZE 100

struct stack
{
  float items[STACKSIZE];
  int top;
}  ;
struct stack s;

void push(float n)      
{
  if (s.top < STACKSIZE - 1) 
  {
    s.items[++s.top] = n;
  }
  else{
    printf("isFull");
  }
}

float pop()        
{
  float n ;
  if (s.top >= 0)
  {
    n = s.items[s.top--];
    return n ;
  }
  else
  {
    printf("isEmpty");
    return -1;
  }
}

float calculate(float pop1, float pop2, char op)
{
  if (op == '+')
    return pop2 + pop1;
  else if (op == '*')
    return pop2 * pop1; 
  else if (op == '-')
    return pop2 - pop1;
  else
    return pop2 / pop1;
}

float evaluate(char input[])
{
  int length = strlen(input);
  float pop1;
  float pop2;
  char temp;

  for (int i = 0; i < length; ++i)
  {
    temp = input[i];
    if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
    {
      pop1 = pop();
      pop2 = pop();
      push(calculate(pop1, pop2, temp));
    }
    else if (temp >= '0' && temp <= '9')
      push(temp - '0');
  }

  return pop();
}

int main()
{
  s.top = -1;
  char input[100];
  scanf("%s", input);

  printf("%.2f", evaluate(input));
  return 0;
}
