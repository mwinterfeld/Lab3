#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "timing.h"

using namespace std;

int main()
{
  string io_text = "./io_text ";
  string io_hdf = "./io_hdf ";
  string python_matrix = "python generate_matrix.py";

  string test_size[7] = {"10", "50", "100", "500", "1000", "2000", "5000"};

  // Run io_text and io_hdf for the test array dimensions
  for(int i = 0; i < 7; i++)
    {
      string N = test_size[i];
      double start, stop;
      system((python_matrix + " -m " + N + " -n " + N + " -f matrix." + N + "." + N).c_str());
      
      get_walltime(&start);
      system((io_text + "matrix." + N + "." + N).c_str());
      get_walltime(&stop);

      cout << stop - start << endl;
      
	    
    }

 // ofstream out("scaling.csv");  
  
  return 0;
}
