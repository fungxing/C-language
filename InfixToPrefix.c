#include <stdio.h>
#include <string.h>
#define STACKSIZE 100

struct stack
{
  int items[STACKSIZE];
  int top;
} ;
struct stack s;

void push(char n)      
{
  if (s.top < STACKSIZE - 1) 
  {
    s.items[++s.top] = n;
  }
  else{
    printf("isFull");
  }
}

char pop()        
{
  char n ;
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

int priority(char symbol){
    if(symbol == '+' || symbol == '-'){         
        return 1;
    }
    else if(symbol == '*' || symbol == '/'){
        return 2;
    }
    else{
        return 0;
    }
}

int main()  
{
    s.top = -1;
    char input[100] = {'\0'};
    char output[100] = {'\0'}; //make a array to save the value up and down
    int output_i = -1;
    scanf("%s", input);
    int length =strlen(input) ;

    int i;
    for (i = length - 1; i >= 0; i --) {   //get the  input[] from back
      if ('0' <= input[i] && input[i] <= '9') {   //make sure the "number" be sort in the output
        output[++ output_i] = input[i]; 
      }
      else {  //others must be symbol,and then just let them comparison the priority first,and ,second,decide to pop() || push in the array"output" 
        while(s.top > -1 && priority(s.items[s.top])>priority(input[i])){  //use while because we cant always clean the other symbol if them is processed by forLoop
          output[++ output_i] = pop();
        }
        push(input[i]);
      }
    }


    while (s.top != -1){ //let the value pop()in the array"input"
      output[++ output_i] = pop();
    }

    while (output_i > -1) { 
      printf("%c", output[output_i --]);
    }
    return 0;
}
