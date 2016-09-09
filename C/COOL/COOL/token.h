/*-------------------------------------------------------

--------------------------------------------------------*/
#ifndef __COMMON_H__
#define __COMMON_H__
#include "common.h"
enum Tok
{
	INT=256,ID,STR,CMT,KEY,SPS,PUC
};
class Token{
private:
	Tok type;
	string value;
	unsigned int line, pos;
public:
	Token(Tok t, string v = "", unsigned int l = 1, unsigned int p = 0):
	type(t),value(v),line(l),pos(p){}
	~Token(){}
};
#endif //__COMMON_H__