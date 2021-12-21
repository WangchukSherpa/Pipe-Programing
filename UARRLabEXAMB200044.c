#include<stdio.h>
#include<stdlib.h>
int n,top=-1,item,stack[10];
#define max 10//*item is a variable to store data while push operation.Top for every stack at innitial stage is equal to -1*. max no of element we can enter into stack*//
void push(){  //stack push operation.//
    if(top>=(max-1)) printf("STACK OVERFLOW\n");
    else{    //*before pushing we first increment the value of top  and than put item*//
        printf("ENTER ELEMENT FOR STACK : ");
        scanf("%d",&item);
        top++;
        stack[top]=item;
    }
}
void pop(){
    if (top==-1) printf("STACK UNDERFLOW\n");
  else {
      item=stack[top];// storing element of top
      top--;          // decrement top
      printf("DELEATED ITEM IS : %d\n",item);// deleted item
  }
}
void dis(){
    if(top==-1) printf("STACK UNDERFLOW\n");
    else{
    printf("STACK IS : \n");
    for(int i=top;i>=0;i--){
        printf("%d\n",stack[i]);
    }

  }
}
void pali()

{

   int num[5],rev[5],i,t;

   for(i=0,t=top;t>=0;i++,t--)

       num[i]=rev[t]=s[t];

   for(i=0;i<=top;i++)

       if(num[i]!=rev[i])

       break;

   if(i==top+1)

       printf("\nIt is a palindrome");

   else

       printf("\nIt is not a palindrome");

}
int main(){
    int choice,loop;


    do{int i;
     printf("ENTER CHOICE||  1.PUSH 2.POP 3.DISPLAY 4.\n");
     scanf("%d",&choice);//scan choice from user


        switch(choice){ // switch case to choose an operation
            case 1:
            printf("ENTER THE NUMBER OF DATA YOU WANT TO STORE : ");
            scanf("%d",&n);
            for(i=0;i<n;i++) push();
            break;
            case 2:
            pop();
            break;
            case 3:
            dis();
            break;
            case 4:
            pali();
            break;
            default: printf("YOU Have ENTER A WRONG OPTION");

        }
       printf("ENTER 1 IF YOU WANT TO CONTINUE \nENTER 0 IF U WANT TO EXIT\n ");
       scanf("%d",&loop);
    }while(loop!=0);
    return 0;
}
