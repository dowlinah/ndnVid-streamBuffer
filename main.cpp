#include<iostream>
using std::cout;
using std::endl;

#include "kbBuffer.hpp"

int main () {
  kbBuffer buf("test.txt");
  cout << "testing init..." << endl;
  cout << "\tmax seq(unused)" << buf.getMaxSeq() << endl;
  cout << "\tcomplete buffers(0): " << buf.getCompleteBuffers() << endl;
  cout << "\tfile size: " << buf.getFileSize() << endl;
  cout << "attempting to read file..." << endl;
  buf.readFile();
  cout << "file successfully read!" << endl;
  cout << "\tbuffers read: " << buf.getCompleteBuffers() << endl;
  
  cout << "Printing file to cout...\n\n";
  buf.printFile(cout);
  cout << endl;
  cout << "Testing pulling one buffer...\n\n";
  unsigned int testBufNum = 6;
  if( !buf.isLastBuffer(testBufNum) ) {
    char * testBuf;
    testBuf = buf.getBuffer(testBufNum);

    for(int j = 0; j < 1024; j++) {
      cout << testBuf[j]; 
    }
  }

  cout << "\n\ntesting invalid buffer checks...\n";
  std::string invalidBufferTest = buf.getStrBuffer(buf.getCompleteBuffers()+4);
  std::string iBTR = "";
  if( invalidBufferTest == "" ) {
    iBTR = "Success";
  } else {
    iBTR = "Failed";
  }
  cout << "\tgetStrBuffer: " << iBTR << endl;

  char * ch = buf.getBuffer(buf.getCompleteBuffers()+4);
  if( ch == NULL ) {
    iBTR = "Success";
  } else {
    iBTR = "Failed";
  }
  cout << "\tgetBuffer: " << iBTR << endl;
}
