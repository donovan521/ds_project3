#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <fcntl.h>
#include <fstream>
#include <queue>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "node.h"

#define MAX_CHARS 128

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



  //after getting freq
  //make sorted array // queue
  Node sortedQ[MAX_CHARS];
  queue<Node> toHuff;

  //for each char we have push onto Q
  for(int i = 0; i < charNum;i++){
    Node temp;
    temp.character = (char)freqArray[0][i];
    temp.frequency = freqArray[1][i];
    temp.leftChild = nullptr;
    temp.rightChild = nullptr;
    temp.parent = nullptr;
    sortedQ[i] = temp;
  }


  //sort
  Node temp01;
  for(int i = 0; i < charNum - 1; i++){
    for(int j = 0; j < charNum - i - 1; j++){
      if(sortedQ[j].frequency > sortedQ[j + 1].frequency){
    //swap them
    temp01 = sortedQ[j];
    sortedQ[j] = sortedQ[j+1];
    sortedQ[j+1] = temp01;
      }
    }
  }

  //push each element of array onto queue (biggest 1st)
  for (int i = 0; i < charNum;  i++){
      toHuff.push(sortedQ[i]);
  }

  //make huffman tree
  //when you make new node it replaces the two children

  for(int i = 1; i < charNum; i++){
      Node * z = new Node;
      Node x;
      int qOrigSize = toHuff.size(); //debug
      cout << "mainQ size is: " << qOrigSize<< endl;
      x = toHuff.front();

      toHuff.pop();
      int xpos;
      for (int d = 0; d < charNum; d++){ //find Node in array that matches
            if( x.frequency == sortedQ[d].frequency) {
                xpos = d;
            }
      }

      z->leftChild = &(sortedQ[xpos]);
 //no segfaultn till here
      Node y;

      y = toHuff.front();

      toHuff.pop();
      int ypos;

      for (int d = 0; d < charNum; d++){ //find Node in array that matches
            if( y.frequency == sortedQ[d].frequency) {
                ypos = d;
            }
      }

      z->rightChild = &(sortedQ[ypos]);
      z->frequency = x.frequency + y.frequency;
      z->character = '\0'; //make null to signify not a char node
      sortedQ[xpos].parent = z;
      sortedQ[ypos].parent = z;

      //now replace x+y with z in array in terms of queuing, alter step to compensate
      //make new queue
     //  cout << toHuff.size() << " tohuff size should be -2 \n"; //DEBUG

      //remaking queue caused issues
   /*   for (int j = 0; j < (charNum-i);  j++){ //new queue will be charNum-i big
            if(toHuff.front().frequency > z->frequency){
                newToHuff.push(*z);
            }
            else {// < =
                newToHuff.push(toHuff.front());
                toHuff.pop();
            }
            cout << "j in loop = " << j << endl;

      } */
       //remake queue by making a new array
      //make sorted array // queue
      Node newSortedQ[MAX_CHARS];
      queue<Node> newToHuff;

        int afterQsize = (int)toHuff.size();
        cout << "after a combo mainQ size is: " << afterQsize << endl;
      //for each char we have in queue put into newQ

      for(int i = 0; i < afterQsize ; i++){
        Node temp;
        temp = toHuff.front();
        toHuff.pop();
        cout << "temp f at " << i <<" is : " << temp.frequency << endl;
        newSortedQ[i] = temp;
      }
      newSortedQ[afterQsize] = *z;

      //verify aray
      cout << "new arrays frequencys are: " << endl;
      for(int l = 0; l < afterQsize + 1; l++){
          cout << " " << newSortedQ[l].frequency << " l is " << l << endl;
      }

      //sort
      Node temp01;
      for(int i = 0; i < afterQsize; i++){
        for(int j = 0; j < afterQsize - i; j++){
          if(newSortedQ[j].frequency > newSortedQ[j + 1].frequency){
        //swap them
        temp01 = newSortedQ[j];
        newSortedQ[j] = newSortedQ[j+1];
        newSortedQ[j+1] = temp01;
          }
        }
      }
      //verify aray
      for(int l = 0; l < afterQsize + 1; l++){
          cout << " after sort is now: " << newSortedQ[l].frequency << "  l is " << l << endl;
      }

      //push each element of array onto queue (biggest 1st)
      for (int i = 0; i < afterQsize+1;  i++){
          newToHuff.push(sortedQ[i]);
      }
      //end remaking queue


      //test if new queue valid
      cout << "1st freq in new is "<< toHuff.front().frequency << "\n and its char is" << toHuff.front().character << endl;
      toHuff = newToHuff; //queue size should decrease by 1 every time
      if ((int)toHuff.size() != (qOrigSize -1)){
          cout << "new queue incorrect" << endl;
      }


  }
  //at the end toHuff should be one node, the root of entire tree
  cout << "root val is "<< toHuff.front().frequency << "\n and its char is" << toHuff.front().character << endl;

  return EXIT_SUCCESS;
} // main


