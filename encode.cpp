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
  char ch;
  int arSize=0;
  string filename = "input.txt";
  ifstream input(filename);
  int freqArray[2][127];
  while(input.get(ch)){
    int asciiNum=0;
    int flag = 0;
    //input.get(ch);
    asciiNum = (int)ch;
    for(int i = 0;i<arSize;i++){
      if(asciiNum==freqArray[0][i]){
	flag =1;
	freqArray[1][i] = freqArray[1][i]+1;
      }
    }
    if(flag == 0){
      freqArray[0][arSize]=asciiNum;
      freqArray[1][arSize]=1;
      arSize++;
    }
  }

  int temp,temp2;
  for(int i = 0; i < arSize-1; i++){
    for(int j = 0; j < arSize-1; j++){
      if(freqArray[0][j+1] > freqArray[0][i]){
	//swap them
	temp = freqArray[0][j+1];
	temp2 = freqArray[1][j+1];
	freqArray[0][j+1] = freqArray[0][i];
	freqArray[0][i] = temp;
	freqArray[1][j+1] = freqArray[1][i];
        freqArray[1][i] = temp2;

      }
    }
  }

  for(int i = 0;i<arSize-2;i++){
    temp = freqArray[0][i+1];
    temp2 = freqArray[1][i+1];
    freqArray[0][i+1] = freqArray[0][i];
    freqArray[0][i] = temp;
    freqArray[1][i+1] = freqArray[1][i];
    freqArray[1][i] = temp2;
  }
  for(int i = 0;i<arSize-1;i++){
    char ascChar = (char)freqArray[0][i];
    cout<<ascChar<<":"<<freqArray[1][i]<<endl;

  }
int charNum = arSize-1;


  return EXIT_SUCCESS;
} // main

