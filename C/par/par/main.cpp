#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BUF 1024

enum action{
	s1, s2, s3, s4, s5, s6, s7, s8, s9,
	r1, r2, r3, r4, acc, err
};
enum action lalr[][7] = {
	{ s3, err, err, s2, err, err, s1 },
	{ err, s4, s5, err, err, acc, err },
	{ s3, err, err, s2, err, err, s6 },
	{ err, r4, r4, err, r4, r4, err },
	{ s3, err, err, s2, err, err, s7 },
	{ s3, err, err, s2, err, err, s8 },
	{ err, s4, s5, err, s9, err, err },
	{ err, r1, s5, err, r1, r1, err },
	{ err, r2, r2, err, r2, r2, err },
	{ err, r3, r3, err, r3, r3, err }
};


//abstract syntax tree for expression
struct ast{
	//+,- for add sub
	//i for id
	char nodetype;
	struct ast *l;
	struct ast *r;
};
struct ast *newast(char nodetype, struct ast *l, struct ast *r){
	struct ast *newnode = (struct ast*)malloc(sizeof(struct ast));
	newnode->nodetype = nodetype;
	newnode->l = l;
	newnode->r = r;
	return newnode;
}
void freeast(struct ast *tree)
{
	if (tree){
		freeast(tree->l);
		freeast(tree->r);
		free(tree);
	}
}

//stack of op
struct op_stk{
	char *base;
	char *top;
};
struct op_stk *new_op_stk(){
	struct op_stk *s = (struct op_stk*)malloc(sizeof(struct op_stk));
	s->base= (char*)malloc(sizeof(char)*MAX_BUF);
	s->top = s->base + 1;
	return s;
}
void op_push(struct op_stk *s, char c){
	if (s->top - s->base < MAX_BUF){
		*s->top = c;
		s->top++;
	}
}
void op_pop(struct op_stk *s){
	if (s->top != s->base)s->top--;
}
bool op_isempty(struct op_stk *s){
	return s->base == s->top;
}

//stack of expression
struct exp_stk{
	struct ast *base;
	struct ast *top;
};
struct exp_stk *new_exp_stk(){
	struct exp_stk *s = (struct exp_stk*)malloc(sizeof(struct exp_stk));
	s->base = (struct ast *)malloc(sizeof(struct ast)*MAX_BUF);
	s->top = s->base + 1;
	return s;
}
void exp_push(struct exp_stk *s, struct ast a){
	if (s->top - s->base < MAX_BUF){
		*s->top = a;
		s->top++;
	}
}
void exp_pop(struct exp_stk *s){
	if (s->top != s->base)s->top--;
}
bool exp_isempty(struct exp_stk *s){
	return s->base == s->top;
}

//some functions...
bool isid(char c){
	return ('a' <= c && c <= 'z'|| 'A' <= c && c <= 'Z'|| c == '_');
}
bool isdigit(char c){
	return ('0' <= c && c <= '9');
}


int main(){
	char input_buffer[MAX_BUF] = { 0 };
	char output_buffer[MAX_BUF] = { 0 };
	scanf("%s", input_buffer);
	int buffer_len = strlen(input_buffer);
	int index = 0;
	//lexer
	struct op_stk *tok_stk = new_op_stk();

	op_push(tok_stk, '$');

	while (true)
	{
		if (index >= buffer_len)break;
		char c = input_buffer[index];
		if (isid(c)){
			do index++; while (isid(input_buffer[index]));
			op_push(tok_stk, 'i');
		}
		else if (c == '+'||c=='*'||c=='('||c==')'){
			op_push(tok_stk, c);
			index++;
		}
		else {
			printf("error: unacceptable character '%c', ascii %d\n", c,c);
			exit(0);
		}
	}

	//parser

	struct op_stk *state_stk = new_op_stk();
	struct exp_stk *e_stk = new_exp_stk();

	op_push(state_stk, 0);
	while (!op_isempty(tok_stk) && !exp_isempty(e_stk)){
		char s = *state_stk->top;
		char tok = *tok_stk->top;
	}
	return 0;
}