#include "kbBuffer.h"

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

void kbBuffer::readFile() {
	std::ifstream fh;
	fh.open(fname);
	char c;
	while(fh.get(c)!= std::eof) {

	}
}
