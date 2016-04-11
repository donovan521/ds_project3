#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <fcntl.h>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

void nope_out(const string & name) {
  perror(name.c_str());
  exit(EXIT_FAILURE);
} // nope_out


int main(const int argc, const char * argv []) {

  if (argc != 2) {
    cout << "Usage: " << argv[0] << " FILE" << endl;
    exit(0);
  } // if
  string filename = argv[1];
  ifstream input(filename);


  return EXIT_SUCCESS;
} // main

