#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

template <typename T>
T add(T &i, T &j)
{
   return i + j;
}
// int, long long, float, double, long double, string

int add(int, int);
long long add(long long, long long);
float add(float, float);
double add(double, double);
long double add(long double, long double);
string add(string, string);

int main(void)
{
   int x_int = 10, y_int = 20;
   long long x_2long = 9220000000000000000, y_2long = 3372036854775807;
   float x_float = 1.5, y_float = 2.2;
   double x_double = 2.3, y_double = 3.5;
   long double x_long_double = 3.33, y_long_double = 4.44;
   string x_string = "Hello ", y_string = "World!";

   cout << x_int << " + " << y_int << " = " << add(x_int, y_int) << endl;
   cout << x_2long << " + " << y_2long << " = " << add(x_2long, y_2long) << endl;
   cout << x_float << " + " << y_float << " = " << add(x_float, y_float) << endl;
   cout << x_double << " + " << y_double << " = " << add(x_double, y_double) << endl;
   cout << x_long_double << " + " << y_long_double << " = " << add(x_long_double, y_long_double) << endl;
   cout << x_string << " + " << y_string << " = " << add(x_string, y_string) << endl;
   // system("pause");
   return 0;
}

int add(int i, int j)
{
   return i + j;
}
long long add(long long i, long long j)
{
   return i + j;
}
float add(float i, float j)
{
   return i + j;
}
double add(double i, double j)
{
   return i + j;
}
long double add(long double i, long double j)
{
   return i + j;
}
string add(string i, string j)
{
   return i + j;
}