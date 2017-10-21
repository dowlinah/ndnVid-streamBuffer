#include "kbBuffer.hpp"

#include <string>
#include <fstream>


int kbBuffer::getMaxSeq() {
	return maxSeq;
}

int kbBuffer::getCompleteBuffers() {
	return currentCompleteBuffers;
}

std::string kbBuffer::getFileName() {
	return fname;
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

void kbBuffer::readFile() {
	std::ifstream fh(fname, std::ios::in);
	char c;
	unsigned int numChunks = (getFileSize()/1024)+1;
	mainBuf = new char*[numChunks];
	int currentChunk = 0;
	unsigned int bytesLeft = getFileSize();
	int sizeOfCurrentBuffer = 0;
	while(1) { // infinite loop to read the file. EOF is handled inside the loop
		if(bytesLeft < 1024) {
			sizeOfCurrentBuffer = bytesLeft;
		} else {
			sizeOfCurrentBuffer = 1024;
			bytesLeft -= 1024;
		}
		mainBuf[currentChunk] = new char[sizeOfCurrentBuffer];

		for(int i = 0; i < sizeOfCurrentBuffer; i++) {
			if(fh.get(c)) {
				
			}
			if(fh.eof()) {
				break;
			}
		}
	}
};
