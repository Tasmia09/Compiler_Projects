#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 6 "cexpr.y"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#line 12 "cexpr.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {

  long long int num;
  char *string;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 63 "cexpr.y"
    long long int alph[26];
    long long int yylex();
    void val_dump();
    void val_clear();    
#line 42 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define NUM 257
#define VAR 258
#define DUMP 259
#define CLEAR 260
#define EQUAL 261
#define PLUS_EQUAL 262
#define MINUS_EQUAL 263
#define MULT_EQUAL 264
#define DIVIDE_EQUAL 265
#define MOD_EQUAL 266
#define LEFT_SHIFT_EQUAL 267
#define RIGHT_SHIFT_EQUAL 268
#define AND_EQUAL 269
#define XOR_EQUAL 270
#define OR_EQUAL 271
#define OR 272
#define XOR 273
#define AND 274
#define LEFT_SHIFT 275
#define RIGHT_SHIFT 276
#define PLUS 277
#define MINUS 278
#define MULT 279
#define DIVIDE 280
#define MOD 281
#define NEG 282
#define BITWISE_NOT 283
#define BRAC_OPEN 284
#define BRAC_CLOSE 285
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,   12,   12,   12,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,   11,   11,   10,
   10,    9,    9,    8,    8,    8,    3,    3,    3,    4,
    4,    4,    4,    7,    7,    6,    6,    5,    5,    2,
    2,
};
static const short yylen[] = {                            2,
    0,    2,    2,    2,    2,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    1,    3,    1,    3,
    1,    3,    1,    3,    3,    1,    3,    3,    1,    3,
    3,    3,    1,    2,    1,    2,    1,    3,    1,    1,
    1,
};
static const short yydefred[] = {                         1,
    0,   40,    0,    0,    0,    0,    0,    0,    0,   39,
    0,    0,   37,   35,   33,    0,    0,    0,    0,    2,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    4,    5,   41,   34,   36,    0,    3,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    6,    7,
    8,    9,   10,   11,   12,   13,   14,   15,   16,   38,
    0,    0,   30,   31,   32,    0,    0,    0,    0,    0,
};
static const short yydgoto[] = {                          1,
    9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
   19,   20,
};
static const short yysindex[] = {                         0,
 -254,    0, -206,  -58,  -52, -240, -231, -246,  -46,    0,
 -268, -199,    0,    0,    0, -236, -258, -250, -253,    0,
 -237, -237, -237, -237, -237, -237, -237, -237, -237, -237,
 -237,    0,    0,    0,    0,    0, -270,    0, -246, -246,
 -246, -246, -246, -246, -246, -246, -246, -246,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -199, -199,    0,    0,    0, -268, -268, -236, -258, -250,
};
static const short yyrindex[] = {                         0,
    0,    0,    9,    0,    0,    0,    0,    0,    0,    0,
  -51,  -59,    0,    0,    0,  -17,   -9,  -11,  -34,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -45,  -31,    0,    0,    0,  -37,  -23,  -14,   -7,   -5,
};
static const short yygindex[] = {                         0,
   48,    0,   22,   44,   24,   43,   -8,    5,   38,   39,
   78,    0,
};
#define YYTABLESIZE 290
static const short yytable[] = {                         29,
   32,   48,    2,    3,    4,    5,   33,   26,   39,   40,
    2,   34,   38,   27,   60,   46,    2,   34,   48,    2,
    3,   24,   47,    6,   17,    2,   34,   28,    7,    8,
   36,    6,   63,   64,   65,   25,    7,    8,   44,   45,
    6,   23,    7,    8,   22,    7,    8,   19,   35,   21,
   68,   20,    8,   18,   21,   22,   23,   24,   25,   26,
   27,   28,   29,   30,   31,   66,   67,   41,   49,   50,
   51,   52,   53,   54,   55,   56,   57,   58,   59,   41,
   42,   43,   61,   62,   69,   37,   70,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   29,   29,   29,   29,   29,   29,   29,    0,
   26,   26,   26,   26,   26,   29,   27,   27,   27,   27,
   27,   27,   27,   26,   24,   24,   24,   24,   24,   27,
   28,   28,   28,   28,   28,   28,   28,   24,   25,   25,
   25,   25,   25,   28,   23,   23,   23,   22,   22,   22,
   19,   25,   21,   21,   20,   20,   18,   23,    0,    0,
   22,    0,    0,   19,    0,   21,    0,   20,    0,   18,
   41,   41,   41,   41,   41,   41,   41,   41,   41,   41,
};
static const short yycheck[] = {                         59,
   59,  272,  257,  258,  259,  260,   59,   59,  277,  278,
  257,  258,   59,   59,  285,  274,  257,  258,  272,  257,
  258,   59,  273,  278,   59,  257,  258,   59,  283,  284,
    7,  278,   41,   42,   43,   59,  283,  284,  275,  276,
  278,   59,  283,  284,   59,  283,  284,   59,    6,   59,
   46,   59,  284,   59,  261,  262,  263,  264,  265,  266,
  267,  268,  269,  270,  271,   44,   45,   59,   21,   22,
   23,   24,   25,   26,   27,   28,   29,   30,   31,  279,
  280,  281,   39,   40,   47,    8,   48,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  272,  273,  274,  275,  276,  277,  278,   -1,
  272,  273,  274,  275,  276,  285,  272,  273,  274,  275,
  276,  277,  278,  285,  272,  273,  274,  275,  276,  285,
  272,  273,  274,  275,  276,  277,  278,  285,  272,  273,
  274,  275,  276,  285,  272,  273,  274,  272,  273,  274,
  272,  285,  272,  273,  272,  273,  272,  285,   -1,   -1,
  285,   -1,   -1,  285,   -1,  285,   -1,  285,   -1,  285,
  272,  273,  274,  275,  276,  277,  278,  279,  280,  281,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 285
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"NUM","VAR","DUMP","CLEAR",
"EQUAL","PLUS_EQUAL","MINUS_EQUAL","MULT_EQUAL","DIVIDE_EQUAL","MOD_EQUAL",
"LEFT_SHIFT_EQUAL","RIGHT_SHIFT_EQUAL","AND_EQUAL","XOR_EQUAL","OR_EQUAL","OR",
"XOR","AND","LEFT_SHIFT","RIGHT_SHIFT","PLUS","MINUS","MULT","DIVIDE","MOD",
"NEG","BITWISE_NOT","BRAC_OPEN","BRAC_CLOSE",
};
static const char *yyrule[] = {
"$accept : commands",
"commands :",
"commands : commands command",
"command : assign ';'",
"command : DUMP ';'",
"command : CLEAR ';'",
"assign : VAR EQUAL assign",
"assign : VAR PLUS_EQUAL assign",
"assign : VAR MINUS_EQUAL assign",
"assign : VAR MULT_EQUAL assign",
"assign : VAR DIVIDE_EQUAL assign",
"assign : VAR MOD_EQUAL assign",
"assign : VAR LEFT_SHIFT_EQUAL assign",
"assign : VAR RIGHT_SHIFT_EQUAL assign",
"assign : VAR AND_EQUAL assign",
"assign : VAR XOR_EQUAL assign",
"assign : VAR OR_EQUAL assign",
"assign : bitOr",
"bitOr : bitOr OR bitXor",
"bitOr : bitXor",
"bitXor : bitXor XOR bitAnd",
"bitXor : bitAnd",
"bitAnd : bitAnd AND shifts",
"bitAnd : shifts",
"shifts : shifts LEFT_SHIFT expr",
"shifts : shifts RIGHT_SHIFT expr",
"shifts : expr",
"expr : expr PLUS term",
"expr : expr MINUS term",
"expr : term",
"term : term MULT negate",
"term : term DIVIDE negate",
"term : term MOD negate",
"term : negate",
"negate : MINUS bitNot",
"negate : bitNot",
"bitNot : BITWISE_NOT param",
"bitNot : param",
"param : BRAC_OPEN bitOr BRAC_CLOSE",
"param : value",
"value : NUM",
"value : VAR",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 140 "cexpr.y"

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
#line 351 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 3:
#line 76 "cexpr.y"
	{ if(yystack.l_mark[-1].num != LONG_MIN ) printf("%lld\n", yystack.l_mark[-1].num); }
break;
case 4:
#line 77 "cexpr.y"
	{ val_dump(); }
break;
case 5:
#line 78 "cexpr.y"
	{ val_clear(); }
break;
case 6:
#line 81 "cexpr.y"
	{ if(yystack.l_mark[0].num > INT_MAX || yystack.l_mark[0].num <= INT_MIN) {printf("overflow\n"); yyval.num = LONG_MIN;} else {alph[yystack.l_mark[-2].num] = yystack.l_mark[0].num; yyval.num = alph[yystack.l_mark[-2].num]; } }
break;
case 7:
#line 82 "cexpr.y"
	{ if (yystack.l_mark[-2].num <= INT_MAX-yystack.l_mark[0].num) {alph[yystack.l_mark[-2].num] += yystack.l_mark[0].num; yyval.num = alph[yystack.l_mark[-2].num];} else { printf("overflow\n"); yyval.num = LONG_MIN; }}
break;
case 8:
#line 83 "cexpr.y"
	{ if (yystack.l_mark[-2].num > INT_MIN+yystack.l_mark[0].num) {alph[yystack.l_mark[-2].num] -= yystack.l_mark[0].num; yyval.num = alph[yystack.l_mark[-2].num];} else { printf("overflow\n"); yyval.num = LONG_MIN; } }
break;
case 9:
#line 84 "cexpr.y"
	{ if(yystack.l_mark[0].num == 0) {yyval.num = 0;}else if (yystack.l_mark[-2].num <= INT_MAX/yystack.l_mark[0].num) {alph[yystack.l_mark[-2].num] *= yystack.l_mark[0].num; yyval.num = alph[yystack.l_mark[-2].num];} else {printf("overflow\n"); yyval.num = LONG_MIN; }}
break;
case 10:
#line 85 "cexpr.y"
	{ if(yystack.l_mark[0].num != 0) {alph[yystack.l_mark[-2].num] /= yystack.l_mark[0].num; yyval.num = alph[yystack.l_mark[-2].num];}else { printf("dividebyzero\n");yyval.num = LONG_MIN;}  }
break;
case 11:
#line 86 "cexpr.y"
	{ if(yystack.l_mark[0].num != 0){alph[yystack.l_mark[-2].num] %= yystack.l_mark[0].num; yyval.num = alph[yystack.l_mark[-2].num];} else { printf("dividebyzero\n");yyval.num = LONG_MIN;}  }
break;
case 12:
#line 87 "cexpr.y"
	{ alph[yystack.l_mark[-2].num] <<= yystack.l_mark[0].num; yyval.num = alph[yystack.l_mark[-2].num]; }
break;
case 13:
#line 88 "cexpr.y"
	{ alph[yystack.l_mark[-2].num] >>= yystack.l_mark[0].num; yyval.num = alph[yystack.l_mark[-2].num]; }
break;
case 14:
#line 89 "cexpr.y"
	{ alph[yystack.l_mark[-2].num] &= yystack.l_mark[0].num; yyval.num = alph[yystack.l_mark[-2].num]; }
break;
case 15:
#line 90 "cexpr.y"
	{ alph[yystack.l_mark[-2].num] ^= yystack.l_mark[0].num; yyval.num = alph[yystack.l_mark[-2].num]; }
break;
case 16:
#line 91 "cexpr.y"
	{ alph[yystack.l_mark[-2].num] |= yystack.l_mark[0].num; yyval.num = alph[yystack.l_mark[-2].num]; }
break;
case 18:
#line 96 "cexpr.y"
	{ yyval.num = yystack.l_mark[-2].num | yystack.l_mark[0].num; }
break;
case 20:
#line 100 "cexpr.y"
	{ yyval.num = yystack.l_mark[-2].num ^ yystack.l_mark[0].num; }
break;
case 22:
#line 104 "cexpr.y"
	{ yyval.num = yystack.l_mark[-2].num & yystack.l_mark[0].num; }
break;
case 24:
#line 108 "cexpr.y"
	{ yyval.num = yystack.l_mark[-2].num << yystack.l_mark[0].num; }
break;
case 25:
#line 109 "cexpr.y"
	{ yyval.num = yystack.l_mark[-2].num >> yystack.l_mark[0].num; }
break;
case 27:
#line 113 "cexpr.y"
	{ yyval.num = yystack.l_mark[-2].num + yystack.l_mark[0].num; }
break;
case 28:
#line 114 "cexpr.y"
	{ yyval.num = yystack.l_mark[-2].num - yystack.l_mark[0].num; }
break;
case 30:
#line 118 "cexpr.y"
	{ if(yystack.l_mark[0].num == 0) {yyval.num = 0;}else if(yystack.l_mark[-2].num <= INT_MAX/yystack.l_mark[0].num) yyval.num = yystack.l_mark[-2].num * yystack.l_mark[0].num; else { printf("overflow\n"); yyval.num = LONG_MIN;}}
break;
case 31:
#line 119 "cexpr.y"
	{ if(yystack.l_mark[0].num!=0) yyval.num = yystack.l_mark[-2].num / yystack.l_mark[0].num; else { printf("dividebyzero\n");yyval.num = LONG_MIN;}  }
break;
case 32:
#line 120 "cexpr.y"
	{ if(yystack.l_mark[0].num!=0) yyval.num = yystack.l_mark[-2].num % yystack.l_mark[0].num; else { printf("dividebyzero\n"); yyval.num = LONG_MIN;} }
break;
case 34:
#line 124 "cexpr.y"
	{ yyval.num = - yystack.l_mark[0].num; }
break;
case 36:
#line 128 "cexpr.y"
	{ yyval.num = ~ yystack.l_mark[0].num; }
break;
case 38:
#line 132 "cexpr.y"
	{ yyval.num = yystack.l_mark[-1].num; }
break;
case 41:
#line 137 "cexpr.y"
	{ yyval.num = alph[yystack.l_mark[0].num]; }
break;
#line 669 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
