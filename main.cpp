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

int timesran = 0;
long long totaltime = 0;
long long min_time = 10000;
long long max_time;

int main() {
   for (int i = 0; i < 10000; i++){
      rand_seed();
      vector<int> v(20);

      for (int i = 0; i < v.size(); i++)
         v[i] = rand_int(1, 100);

      print(v);
//      cout << "Enter number to search for: ";
      int n;

      n = v.back();

      std::chrono::high_resolution_clock::time_point t_start =
              std::chrono::high_resolution_clock::now();

      int j = linear_search(v, n);

      std::chrono::high_resolution_clock::time_point t_end =
              std::chrono::high_resolution_clock::now();

//      cout << "Found in position " << j << "\n";
      timesran++;
      long long time_this_run = std::chrono::duration_cast<std::chrono::nanoseconds>(t_end - t_start).count();
      totaltime += time_this_run;
      if (time_this_run < min_time){
         min_time = time_this_run;
      }
      if (time_this_run > max_time){
         max_time = time_this_run;
      }
   }
   cout << "Times ran: " << timesran << endl;
   cout << "Average time ran: " << totaltime / timesran << endl;
   cout << "Minimum time:" << min_time << endl;
   cout << "Maximum time: " << max_time << endl;

   return 0;
}