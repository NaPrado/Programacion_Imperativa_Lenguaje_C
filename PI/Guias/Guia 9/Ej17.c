#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include <stdio.h>
#include <assert.h>


#include <ctype.h>

int bienformado(const char * s) {
  if ( *s == 0)
    return 0;
  int aux = bienformado(s+1);
  if ( isdigit(*s) ) {
    if ( aux==0)
      return *s - '0';
    return -1;
  }
  // si es una letra. Si aux es cero o negativo, seguira siendo negativo
  if ( isalpha(*s))
    return aux - 1;
  // no es digito ni letra
  return -1;
}
int main(void) {
 char * zero[]={"abcd4a10bb2", "", "0000", "a1", "abc3", "0a1"};

  char * not_zero[] ={ "a", "1", "a2", "abc2", "abc4", "abc33", "0123", "2aa", "$1", "@@2", "abcd22", "@@"};

  for(int i=0; i < sizeof(zero)/sizeof(zero[0]);i++) {
    printf("%s\n", zero[i]);
    assert(bienformado(zero[i])==0);
  }    

  for(int i=0; i < sizeof(not_zero)/sizeof(not_zero[0]);i++) {
    printf("%s\n", not_zero[i]);
    assert(bienformado(not_zero[i]) !=0);
 }

  puts("OK!");
  return 0;
}

