#include <stdio.h>
void main{
  char choice;
  printf("Enter a character ");
  scanf("%c"&choice);
  if((choice=='a')||(choice=='e')||(choice=='i')||(choice=='o')||(choice=='u')||(choice=='A')||(choice=='E')||(choice=='I')||(choice=='O')||(choice=='U'))
{
  printf("%c is a vovel",choice);
}
else printf("%c is a consonent ",choice);
}
