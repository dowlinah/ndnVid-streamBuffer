#include "kbBuffer.hpp"

#include <string>
#include <fstream>
#include <iostream>

int kbBuffer::getMaxSeq() {
  return maxSeq;
}

int kbBuffer::getCompleteBuffers() {
  return currentCompleteBuffers;
}

std::string kbBuffer::getFileName() {
  return fname;
}

int kbBuffer::getSizeOfLastBuffer() {
  return sizeOfLastBuffer;
}

// gets the size of the file that is to be read in
int kbBuffer::getFileSize() {
  std::ifstream fh(fname, std::ios::in);
  std::streampos fsize = 0;
  fsize = fh.tellg();
  fh.seekg(0, std::ios::end);
  fsize = fh.tellg() - fsize;
  fh.close();

  return fsize;
}

void kbBuffer::printFile(std::ostream& out) {
  unsigned int sizeOfCurrentBuffer = 1024;
  for(int j = 0; j < currentCompleteBuffers; j++) {
    if((currentCompleteBuffers - j) == 1) {
      sizeOfCurrentBuffer = sizeOfLastBuffer;
    }
    for(int i = 0; i < sizeOfCurrentBuffer; i++) {
      out << mainBuf[j][i];
    }
  }
}

// std::ostream& operator<<(std::ostream& out) {
//   printFile(out);
//   return &out;

  
// }


void kbBuffer::readFile() {
  std::ifstream fh(fname, std::ios::in);
  char c;
  unsigned int numChunks = (getFileSize()/1024)+1;
  unsigned int currentChunk = 0;
  unsigned int bytesLeft = getFileSize();
  unsigned int sizeOfCurrentBuffer = 0;
  bool done = false;
  
  mainBuf = new char*[numChunks];
  
  while(1) { // infinite loop to read the file.
    if(bytesLeft < 1024) { //handles the last buffer
      sizeOfCurrentBuffer = bytesLeft;
      sizeOfLastBuffer = bytesLeft;
      done = true;
    } else { // handles "full" buffers
      sizeOfCurrentBuffer = 1024;
      bytesLeft -= 1024;
    }
    mainBuf[currentChunk] = new char[sizeOfCurrentBuffer];

    for(int i = 0; i < sizeOfCurrentBuffer; i++) {
      if(fh.get(c)) {
	mainBuf[currentChunk][i] = c;
      }
      if(fh.eof()) {
	break;
      }
    }
    currentCompleteBuffers++;
    if(done) {
      break;
    }
    currentChunk++;
  } // while loop
}

// SINGLE BUFFER OPS:::::::::::::::::::::::::::::::::::::::::::::::

bool kbBuffer::isLastBuffer(const int &num) {
  if(num < (currentCompleteBuffers-1)) {
    return false;
  } else {
    return true;
  }
}

char * kbBuffer::getBuffer(const int &num) {
    
  if( !isValidIndex(num) ) {
    return NULL;
  } 
  return mainBuf[num];
}

std::string kbBuffer::getStrBuffer(const int &num) {
  std::string str = "";
  unsigned int size = 1024;
  if( !isValidIndex(num) ) {
    return str;
  }
  if(isLastBuffer(num)) {
    size = sizeOfLastBuffer;
  }
  for(int i = 0; i < size; i++) {
    str += mainBuf[num][i];
  }
  
  return str;
}

bool kbBuffer::isValidIndex(const int & num) {
  return ( num < currentCompleteBuffers && num > 0 );
};
