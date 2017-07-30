#include <iostream>

using namespace std;


int func1()
{
    return 1;
}

int main() {
   short int i;           // a signed short integer
   short unsigned int j;  // an unsigned short integer

   j = 33000;
   i = j;
   cout << i << " " << j;

   return 0;
}
