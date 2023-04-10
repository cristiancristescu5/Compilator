%{
#include <stdio.h>
#include "source.hpp"
#include "y.tab.h"
%}
%option noyywrap
%%
"[int]"|"[float]"|"[char]"|"[string]"|"[bool]" {yylval.strval = strdup(yytext);return TYPE;}
"begin_main()" {return BEGIN_MAIN;}
"end_main" {return END_MAIN;}
"function" {return FUNCTION;}
"CONST" {return CONST;}
"classify" {return CLASS;}
"private_stuff:" {return PRIVATE;}
"public_stuff:" {return PUBLIC;}
"do_the_while" {return WHILE;}
"do_the_for" {return FOR;}
"if" {return IF;}
"else" {return ELSE;}
"DECLARE" {return DECLARE;}
"eval" {return EVAL;}
"typeof" {return TYPEOF;}

"~" {return ACCESS;}
"+" {return('+') ;}
"@" {return('@');}
"/" {return('/');}
"%" {return('%');}
"<" { return LR; }
">" { return GR; }
">=" { return GE; }
"<=" { return LE; }
"==" { return EQ; }
"!=" { return NE; }
"&&" { return AND; }
"||" { return OR; }
"!" { return NOT; }
"DO" { return DO; }
"TRUE"|"FALSE" {yylval.strval = strdup(yytext);return BOOLEAN;}
\"[^\"]+\" { yylval.strval = strdup(yytext); return STRING; }
'.' {yylval.strval=strdup(yytext); return CHAR;}
[_a-zA-Z][_a-zA-Z0-9]* {yylval.strval = strdup(yytext);return ID;}
-?[1-9][0-9]*|0 {yylval.intval = atoi(yytext);return INTEGER;}
-?[1-9][0-9]*\.[0-9]*|-?0\.[0-9]* { yylval.floatval=atof(yytext);return FLOAT;}
":=" {return ASSIGN;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
%% 