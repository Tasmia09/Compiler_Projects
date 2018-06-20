/*
 * This file defines an example yacc grammar for simple C expressions.
 */

%{
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
%}

%union {

  long long int num;
  char *string;
}

%token <num> NUM
%token <num> VAR
%token <string> DUMP
%token <string> CLEAR
%token <num> EQUAL
%token <num> PLUS_EQUAL
%token <num> MINUS_EQUAL

%token <num> MULT_EQUAL
%token <num> DIVIDE_EQUAL
%token <num> MOD_EQUAL
%token <num> LEFT_SHIFT_EQUAL
%token <num> RIGHT_SHIFT_EQUAL
%token <num> AND_EQUAL
%token <num> XOR_EQUAL
%token <num> OR_EQUAL
%token <num> OR
%token <num> XOR
%token <num> AND
%token <num> LEFT_SHIFT
%token <num> RIGHT_SHIFT
%token <num> PLUS
%token <num> MINUS
%token <num> MULT
%token <num> DIVIDE
%token <num> MOD
%token <num> NEG
%token <num> BITWISE_NOT
%token <num> BRAC_OPEN
%token <num> BRAC_CLOSE

%type <num> assign
%type <num> value
%type <num> expr
%type <num> term
%type <num> param
%type <num> bitNot
%type <num> negate
%type <num> shifts
%type <num> bitAnd
%type <num> bitXor
%type <num> bitOr


%{
    long long int alph[26];
    long long int yylex();
    void val_dump();
    void val_clear();    
%}



%%
commands:
	|	commands command
	;

command	:	assign ';'      		{ if($1 != LONG_MIN ) printf("%lld\n", $1); }
	|	DUMP ';'        		{ val_dump(); }
	|	CLEAR ';'			{ val_clear(); }			
	;

assign  :	VAR EQUAL assign  		{ if($3 > INT_MAX || $3 <= INT_MIN) {printf("overflow\n"); $$ = LONG_MIN;} else {alph[$1] = $3; $$ = alph[$1]; } }
	|	VAR PLUS_EQUAL assign		{ if ($1 <= INT_MAX-$3) {alph[$1] += $3; $$ = alph[$1];} else { printf("overflow\n"); $$ = LONG_MIN; }}
	|	VAR MINUS_EQUAL assign		{ if ($1 > INT_MIN+$3) {alph[$1] -= $3; $$ = alph[$1];} else { printf("overflow\n"); $$ = LONG_MIN; } }
	|	VAR MULT_EQUAL assign		{ if($3 == 0) {$$ = 0;}else if ($1 <= INT_MAX/$3) {alph[$1] *= $3; $$ = alph[$1];} else {printf("overflow\n"); $$ = LONG_MIN; }}
	|	VAR DIVIDE_EQUAL assign		{ if($3 != 0) {alph[$1] /= $3; $$ = alph[$1];}else { printf("dividebyzero\n");$$ = LONG_MIN;}  }
	|	VAR MOD_EQUAL assign		{ if($3 != 0){alph[$1] %= $3; $$ = alph[$1];} else { printf("dividebyzero\n");$$ = LONG_MIN;}  }
	|	VAR LEFT_SHIFT_EQUAL assign	{ alph[$1] <<= $3; $$ = alph[$1]; }
	|	VAR RIGHT_SHIFT_EQUAL assign	{ alph[$1] >>= $3; $$ = alph[$1]; }
	|	VAR AND_EQUAL assign		{ alph[$1] &= $3; $$ = alph[$1]; }
	|	VAR XOR_EQUAL assign		{ alph[$1] ^= $3; $$ = alph[$1]; }
	| 	VAR OR_EQUAL assign		{ alph[$1] |= $3; $$ = alph[$1]; }	
	|	bitOr				
	;


bitOr	:	bitOr OR bitXor			{ $$ = $1 | $3; }
	|	bitXor				
	;

bitXor	:	bitXor XOR bitAnd		{ $$ = $1 ^ $3; }
	|	bitAnd				
	;

bitAnd	:	bitAnd AND shifts		{ $$ = $1 & $3; }
	|	shifts				
	;

shifts	:	shifts LEFT_SHIFT expr		{ $$ = $1 << $3; }
	|	shifts RIGHT_SHIFT expr		{ $$ = $1 >> $3; }
	|	expr				
	;	

expr	:	expr PLUS term   		{ $$ = $1 + $3; }
	|	expr MINUS term			{ $$ = $1 - $3; }
	|	term						           	
	;

term	:	term MULT negate		{ if($3 == 0) {$$ = 0;}else if($1 <= INT_MAX/$3) $$ = $1 * $3; else { printf("overflow\n"); $$ = LONG_MIN;}}
	|	term DIVIDE negate		{ if($3!=0) $$ = $1 / $3; else { printf("dividebyzero\n");$$ = LONG_MIN;}  }
	|	term MOD negate  		{ if($3!=0) $$ = $1 % $3; else { printf("dividebyzero\n"); $$ = LONG_MIN;} }
	|	negate				
	;

negate	:	MINUS bitNot			{ $$ = - $2; }
	|	bitNot				
	;

bitNot	:	BITWISE_NOT param 		{ $$ = ~ $2; }
	|	param				
	; 	

param	:	BRAC_OPEN bitOr BRAC_CLOSE	{ $$ = $2; }
	|	value				
	;

value   :   NUM             			
        |   VAR             			{ $$ = alph[$1]; }	
        ;
%%

main(int argc, char *argv[])
{
 FILE *inputfile = stdin;   

 if (yyparse())
      printf("\nInvalid expression.\n");
   else
      printf("\nCalculator off.\n");

}

yyerror(s)
char *s;
{
   fprintf(stderr, "%s\n", s);
}


void val_dump(){
    char c = 'a';
	int i = 0;
    for (i = 0; i < 26; i++) {
        printf("%c: %d\n", (c++), alph[i]);
	}
}

void val_clear(){
	int i = 0;
    for (i = 0; i < 26; i++) {
        alph[i] = 0;
	}
}
