#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  string io_test = "./io_text ";
  string io_hdf = "./io_hdf ";
  string python_matrix = "python generate_matrix.py";

  string test_size[7] = {"10", "50", "100", "500", "1000", "2000", "5000"};

  // Run io_text for the test array dimensions
  for(int i = 0; i < 7; i++)
    {
      string N = test_size[i];
      system((python_matrix + " -m " + N + " -n " + N + " -f matrix." + N + "." + N).c_str());
      /* FILE* output = popen((, "r");
      char buffer[128];
      std::string result = "";
      while(!feof(output)) {
	    if(fgets(buffer, 128, output) != NULL)
    		result += buffer;
	    }
	results[i-1] = result; */
    }

 // ofstream out("scaling.csv");  
  
  return 0;
}
