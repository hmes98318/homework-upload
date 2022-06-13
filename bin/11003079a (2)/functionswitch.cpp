#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>

using namespace std;


int partialsum(vector<int>, int);

int main(void)
{
   srand((unsigned)time(NULL));
   vector<int> myvector;


   for(int i = 0; i < 30; i++){
      myvector.push_back(rand()%100+1);
   }


   cout << "f=1 partialsum= " << partialsum(myvector, 1) << endl;
   cout << "f=2 partialsum= " << partialsum(myvector, 2) << endl;
   cout << "f=3 partialsum= " << partialsum(myvector, 3) << endl;
   cout << "f=4 partialsum= " << partialsum(myvector, 4) << endl;
   cout << "f=5 partialsum= " << partialsum(myvector, 5) << endl;
   return 0;
}

int partialsum(vector<int> myvect, int f)
{
   int sum = 0;
   int k = 0;
   int i = 0;

   switch (f)
   {
   case 1:
      for (int val : myvect)
      {
         if (val % 2 == 1)
            sum += val;
      }
      break;
   case 2:
      for (int val : myvect)
      {
         if (val % 2 == 0)
            sum += val;
      }
      break;

   case 3:
      k = 0;
      while (i < myvect.size())
      {
         sum += myvect[i];
         i = k++ * 3;
      }
      break;
   case 4:
      do
      {
         sum += myvect[i];
         i = k++*3+1;
      } while (i < myvect.size());

      break;
   case 5:
      for (k = 0; k < myvect.size(); k=k*3+2)
      {
         sum += myvect[k];
      }
      break;
   }
   return sum;
}
