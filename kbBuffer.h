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
		int getMaxSeq();
		std::string getFileName();
		int getCompleteBuffers();
		void readFile();

	private:
		std::string fname;
		int maxSeq;	// maximum in-order sequence that has been received
		char ** mainBuf;	// "buffer of buffers" hard-coded to be kilobytes
		bool * completions;	// buffer of bools representing filled buffers
		int sizeOfLastBuffer;	// int representing the size of the last buffer
		int currentCompleteBuffers;	// count of buffers currently full
};

#endif
