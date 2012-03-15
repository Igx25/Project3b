// compiler.cpp : Defines the entry point for the console application.
//

#include <cstdio>
#include <iostream>
#include <list>

using namespace std;

extern "C" {
#include "y.flicker.h"
#include "functions.h"
  extern FILE *yyin;
  extern int yylex();
  extern int yyparse();
  extern char *yytext;
}


void Execute();

int main(int argc, char **argv)
{
  FILE *file;

  if(argc < 2)
  {
       fprintf(stderr, "Usage: advcalc filename");
       return 1;
  }

  file = fopen(argv[1], "r");
  if(!file)
  {
      fprintf(stderr, "Unable to open file %s", argv[1]);
      return 1;
  }

  yyin = file;

  do
    {
      yyparse();
    } while(!feof(yyin));

  Execute();
  return 0;
}



extern "C" void yyerror(char *s)
{ 
  cout << s << endl;
}


