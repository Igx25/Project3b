%{
/*
 * Flicker Application
*/
#include "stdio.h"
#include "functions.h"
%}

%union {
	void *pval;		// Pointer to tree nodes
	int   ival;		// Integer values
	char *sval;		// String values
	double dval;		// Double values
}

%token FLICKER PRINT
%token<ival> INT_VALUE
%token<sval> STR_VALUE
%token<dval> DBL_VALUE
%type<pval> program stmts stmt V

%%
program : stmts			{setRoot($1);}
;
stmts 	: stmts '\n' stmt 	{$$ = createNodeStmts($1, $3);}
	| stmt            	{$$ = createNodeStmts(NULL,$1);}
;
stmt 	:			{$$ = NULL;}
	| V			{$$ = $1;}
	| stmt '+' V		{$$ = createNodeAdd($1, $3);}
	| stmt '*' V		{$$ = createNodeMul($1, $3);}
;
V 	: INT_VALUE           	{$$ = createNodeDbl($1);}
	| STR_VALUE           	{$$ = createNodeStr($1);  free($1);}
	| DBL_VALUE		{$$ = createNodeDbl($1);}
%%
