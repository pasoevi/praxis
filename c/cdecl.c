/*
 *  cdecl2en - translate C declarations into English.
    Copyright (C) 2014, 2015  Sergi Pasoev

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
 *
 *
 */


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXTOKENS 100
#define MAXTOKENLEN 64

enum type_tag {IDENTIFIER, QUALIFIER, TYPE};

struct token{
  char type;
  char string[MAXTOKENLEN];
};

int top = -1;
struct token stack[MAXTOKENS];
struct token this;

#define pop stack[top--]
#define push(s) stack[++top]=s

/* Figure out the identifier type */
enum type_tag classify_string(void){
	char *s = this.string;
	if(!strcmp(s, "const")){
		strcpy(s, "read-only");
		return QUALIFIER;
	}
	if(!strcmp(s, "volatile")){
		return QUALIFIER;
	}
	if(!strcmp(s, "void")){
		return TYPE;
	}
	if(!strcmp(s, "char")){
		return TYPE;
	}
	if(!strcmp(s, "signed")){
		return TYPE;
	}
	if(!strcmp(s, "unsigned")){
		return TYPE;
	}
	if(!strcmp(s, "short")){
		return TYPE;
	}
	if(!strcmp(s, "int")){
		return TYPE;
	}
	if(!strcmp(s, "long")){
		return TYPE;
	}
	if(!strcmp(s, "float")){
		return TYPE;
	}	
	if(!strcmp(s, "double")){
		return TYPE;
	}
	if(!strcmp(s, "struct")){
		return TYPE;
	}
	if(!strcmp(s, "union")){
		return TYPE;
	}
	if(!strcmp(s, "enum")){
		return TYPE;
	}
	return IDENTIFIER;
}

/* Read the next token into "this". */
void gettoken(void){
	char *p = this.string;
	while((*p = getchar()) == ' '){
		/* Skip past any spaces */
	}

	if(isalnum(*p)){
		/* It starts with A-Z, 0-9 read in an identifier */
		while(isalnum(*++p=getchar()));
		ungetc(*p, stdin);
		*p = '\0';
		this.type = classify_string();
		return;
	}
	if(*p == '*'){
		strcpy(this.string, "pointer to");
		this.type = *p;
		return;
	}
	this.string[1] = '\0';
	this.type = *p;
	return;
}

/* The piece of code that understandeth all parsing */
read_to_first_identifier(){
	gettoken();
	while(this.type != IDENTIFIER){
		push(this);
		gettoken();
	}
	printf("%s is ", this.string);
	gettoken();
}

deal_with_arrays(){
	while(this.type == '['){
		printf("array ");
		gettoken(); /* A number or ']' */
		if(isdigit(this.string[0])){
			printf("0..%d ", atoi(this.string) - 1);
			gettoken(); /* Read the ']' */
		}
		gettoken();
		printf("of ");
	}
}

deal_with_function_args(){
	while(this.type != ')'){
		gettoken();
	}
	gettoken();
	printf("function returning");
}

deal_with_pointers(){
	while(stack[top].type == '*'){
		printf("%s ", pop.string);
	}
}

deal_with_declarator(){
	/* deal with possible array/function following identifier */
	switch(this.type){
		case '[' : deal_with_arrays(); break;
		case '(' : deal_with_function_args();
	}
	deal_with_pointers();
	/* Process tokens that we stacked while reading identifier */
	while(top >= 0){
		if(stack[top].type == '('){
			pop;
			gettoken(); /* Read past ')' */
			deal_with_declarator();
		}else{
			printf("%s ", pop.string);
		}
	}
}

main(){
	/* Stack tokens until we reach an identifier. */
	read_to_first_identifier();
	deal_with_declarator();
	printf("\n");
	return 0;
}

