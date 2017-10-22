#ifndef _KB_BUFFERS_H_
#define _KB_BUFFERS_H_
#include<string>

class kbBuffer {
public:
  kbBuffer(std::string s){
    maxSeq = 0;
    currentCompleteBuffers = 0;
    maxSeq = 0;
    fname = s;
  };

  //accessors:
  int getMaxSeq();
  int getCompleteBuffers();
  int getFileSize();
  int getSizeOfLastBuffer();
  std::string getFileName();
  
  //file methods for full files:
  void readFile();
  void printFile(std::ostream& out);
  //  std::ostream& operator<<(std::ostream& out);
  
  //methods for specific buffers
  char * getBuffer(const int &num);
  std::string getStrBuffer(const int &num);
  bool isLastBuffer(const int &num);
  
private:
  //data:
  std::string fname;
  int maxSeq;	// maximum in-order sequence recieved
  char ** mainBuf;	// "buffer of buffers" in kB
  bool * completions;	//buffer of bools -filled buffers
  int sizeOfLastBuffer;	// size of the last buffer read
  int currentCompleteBuffers;	// count of buffers full

  //methods:
  bool isValidIndex(const int &num);
};

#endif
