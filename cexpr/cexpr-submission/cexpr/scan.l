%{
#include "y.tab.h"
%}

%{
    void yyerror(char *);
%}
%%


"="	{ return EQUAL; }
"+="	{ return PLUS_EQUAL; }
"-="	{ return MINUS_EQUAL; }
"*="	{ return MULT_EQUAL; }
"/="	{ return DIVIDE_EQUAL; }
"%="	{ return MOD_EQUAL; }
"<<="	{ return LEFT_SHIFT_EQUAL; }
">>="	{ return RIGHT_SHIFT_EQUAL; }
"&="	{ return AND_EQUAL; }
"^="	{ return XOR_EQUAL; }
"|="	{ return OR_EQUAL; }
"|"	{ return OR; }
"^"	{ return XOR; }
"&"	{ return AND; }
"<<"	{ return LEFT_SHIFT; }
">>"	{ return RIGHT_SHIFT; }
"+"	{ return PLUS; }
"-"	{ return MINUS; }
"*" 	{ return MULT; }
" / "	{ return DIVIDE; }
"/"	{ return DIVIDE; }
"%"	{ return MOD; }
"-"	{ return NEG; }
"~"	{ return BITWISE_NOT; }
"("	{ return BRAC_OPEN; }
")"	{ return BRAC_CLOSE; }


[0-9]+    { sscanf(yytext, "%d", &yylval.num);
            return NUM; }

[a-z]       { yylval.num = *yytext - 'a';
            return VAR; }
[ \t\r\n]+      {}

"dump"      { yylval.string=strdup(yytext);
            return DUMP; }

"clear"     { return CLEAR; }

.         { return yytext[0]; }
