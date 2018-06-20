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
extern YYSTYPE yylval;
