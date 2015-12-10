#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <chrono>
#include "util.h"

using namespace std;

int linear_search(vector<int> v, int value)
{
   for (int i = 0; i < v.size(); i++)
   {
      if (v[i] == value)
         return i;
   }
   return -1;
}


int main()
{
   rand_seed();
   vector<int> v(20);



   for (int i = 0; i < v.size(); i++)
      v[i] = rand_int(1, 100);



   print(v);
   cout << "Enter number to search for: ";
   int n;
   cin >> n;

   std::chrono::high_resolution_clock::time_point t_start =
           std::chrono::high_resolution_clock::now();

   int j = linear_search(v, n);

   std::chrono::high_resolution_clock::time_point t_end =
           std::chrono::high_resolution_clock::now();

   cout << "Found in position " << j << "\n";
   cout << std::chrono::duration_cast<std::chrono::nanoseconds>(t_end - t_start).count() << endl;

   return 0;
}