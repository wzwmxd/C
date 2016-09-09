#include "common.h"
#include "token.h"

void lex(char *file){
	//文件读入缓冲区
	FILE* f = fopen(file, "rb");
	fseek(f, 0, SEEK_END);
	long lSize = ftell(f);
	char* buf = (char*)malloc(sizeof(char)*(lSize+1));
	size_t result;
	rewind(f);
	if (buf)result = fread(buf, 1, lSize, f);
	fclose(f);
	if (result != lSize)return;
	buf[lSize] = 0;
	//printf("%s", buf);
	//生成token流
	int pos = 0; char c; int dfa_begin = 0;
	while (pos <= lSize){
		c = buf[pos];
		if (isalpha(c) || c == '_'){
			pos++;
			goto ID;
		}
		else if (isdigit(c)){
			pos++;
			goto INT;
		}
		else if (c == '"'){
			pos++;
			goto STR;
		}
		else if (c == '-'){
			pos++;
			goto MNS_CMT;
		}
		else if (c == '('){
			pos++;
			goto CMT_LPA;
		}
	ID:
	INT:
	STR:
			   MNS_CMT:
	}
}

int main(int argc, char *argv[]){
	lex("C:\\C\\C\\C\\COOL\\Debug\\main.cpp");
}