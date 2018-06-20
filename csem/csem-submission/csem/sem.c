# include <stdio.h>
# include "cc.h"
# include "semutil.h"
# include "sem.h"
# include "sym.h"
# define MAXARGS 50
# define MAXLOCS 50

extern int formalnum;
extern int localnum;
extern char formaltypes[MAXARGS];
extern char localtypes[MAXLOCS];
extern int localwidths[MAXLOCS];
int labelnum = 0;
int branchnum = 0;
struct sem_rec *n_node;
struct sem_rec *cont;
struct sem_rec *break_node;

int cont_call = 0;
int break_call = 0;
/* backpatch - backpatch list of quadruples starting at p with k
 */
void backpatch(struct sem_rec *p, int k)
{
	
	while(p!=NULL){
		printf("B%d=L%d\n", p->s_place, k);   
		p = p->back.s_link;	
	}
	
}

/*
 * bgnstmt - encountered the beginning of a statement
 */
void bgnstmt()
{
   int c;
   extern int lineno;
   static int laststmt = 0;

   skip();
   c = getchar();
   putbak(c);
   if (c != '}' && lineno != laststmt) {
      printf("bgnstmt %d\n", lineno);
      laststmt = lineno;
   }
}

/*
 * call - procedure invocation
 */
struct sem_rec *call(char *f, struct sem_rec *args)
{	
	struct sem_rec *y;
	y = (struct sem_rec *) alloc(sizeof(struct sem_rec));
	int args_count=0;
	while(args!=NULL){
		if( args->s_mode == T_INT)
			printf("argi t%d\n", args->s_place);
		else if( args->s_mode == T_DOUBLE)
			printf("argf t%d\n", args->s_place);
		args = args->back.s_link;
		args_count++;
	}
	
   	printf("t%d := global %s\n", nexttemp(), f);
	printf("t%d := fi t%d %d\n",nexttemp(),currtemp(),args_count);
	y->s_place = currtemp();
	return y;

}

/*
 * ccand - logical and
 */
struct sem_rec *ccand(struct sem_rec *e1, int m, struct sem_rec *e2)
{
	backpatch(e1->back.s_true,m);
	
	
	struct sem_rec *y = merge(e1,e2);
	
	y->back.s_true = e2->back.s_link;
	e1->s_false->back.s_link = e2->s_false;
	y->s_false = e1->s_false;
	
	return y; 
	
}

/*
 * ccexpr - convert arithmetic expression to logical expression
 */
struct sem_rec *ccexpr(struct sem_rec *e)
{
   
   return e;
}

/*
 * ccnot - logical not
 */
struct sem_rec *ccnot(struct sem_rec *e)
{
		
	struct sem_rec *p = (struct sem_rec *) alloc(sizeof(struct sem_rec));
	struct sem_rec *p1 = (struct sem_rec *) alloc(sizeof(struct sem_rec));
	printf("t%d := 0\n", nexttemp());
	printf("t%d := t%d !=i t%d\n", nexttemp(), e->s_place, currtemp());
	printf("bt t%d B%d\n", currtemp(), ++branchnum);
	
	p1->s_place = branchnum;
	p1->s_mode = T_LBL;
	
	printf("br B%d\n", ++branchnum);
	p->s_place = branchnum;
	p->s_mode = T_LBL;
	
	struct sem_rec *t = node(p->s_place,T_LBL, NULL, p1);
	t->back.s_true = p;
	
	return t;
   
	
}

/*
 * ccor - logical or
 */
struct sem_rec *ccor(struct sem_rec *e1, int m, struct sem_rec *e2)
{
	
	backpatch(e1->s_false,m);
	
	struct sem_rec *y = merge(e1,e2);
	e2->back.s_link = NULL;
	y->back.s_true = e1->back.s_link;
	y->s_false = e2->s_false;
	
	return y;   
	
}

/*
 * con - constant reference in an expression
 */
struct sem_rec *con(char *x){
	struct sem_rec *y;
	y = (struct sem_rec *) alloc(sizeof(struct sem_rec));
	printf("t%d := %s\n",nexttemp(),x);
	y->s_place = currtemp();
	y->s_mode = T_INT;
	return y;
		
	
}

/*
 * dobreak - break statement
 */
void dobreak()
{
	break_call = 100;
	break_node = merge(break_node,n());
	
}

/*
 * docontinue - continue statement
 */
void docontinue()
{
	cont_call = 100;
	cont = merge(cont,n());	
}

/*
 * dodo - do statement
 */
void dodo(int m1, int m2, struct sem_rec *e, int m3)
{ 
   
	backpatch(e->back.s_true, m1);
	
	backpatch(e->s_false, m3);
	if(cont_call == 100){
		
		backpatch(cont,m2);
		cont_call = 0;
		cont = NULL;
	}
	if(break_call == 100){
		
		backpatch(break_node,m3);
		break_call = 0;
		break_node = NULL;
	}
	
	
	
}

/*
 * dofor - for statement
 */
void dofor(int m1, struct sem_rec *e2, int m2, struct sem_rec *n1,
           int m3, struct sem_rec *n2, int m4)
{
	backpatch(e2->back.s_true, m3);
	backpatch(e2->s_false, m4);
	if(cont_call == 100){
		
		backpatch(cont,m2);
		cont_call = 0;
		cont = NULL;
	}
	
	backpatch(n1,m1);
	backpatch(n2,m2);
	if(break_call == 100){
		
		backpatch(break_node,m4);
		break_call = 0;
		break_node = NULL;
	}
	
	
	

}

/*
 * dogoto - goto statement
 */
void dogoto(char *id)
{
   fprintf(stderr, "sem: dogoto not implemented\n");
}

/*
 * doif - one-arm if statement
 */
void doif(struct sem_rec *e, int m1, int m2)
{
		
		backpatch(e->back.s_true, m1); 
		backpatch(e->s_false, m2); 
	
}

/*
 * doifelse - if then else statement
 */
void doifelse(struct sem_rec *e, int m1, struct sem_rec *n,
                         int m2, int m3)
{
	backpatch(e->back.s_true, m1);
	backpatch(e->s_false, m2); 
	backpatch(n, m3);    	
	
	
}

/*
 * doret - return statement
 */
void doret(struct sem_rec *e){
	if (e->s_mode == T_DOUBLE){
		printf("t%d := cvi t%d\n",nexttemp(),e->s_place);
		printf("ret%s t%d\n","i",currtemp());	
	}else{
		printf("ret%s t%d\n","i",e->s_place);
	}
	
   
}

/*
 * dowhile - while statement
 */
void dowhile(int m1, struct sem_rec *e, int m2, struct sem_rec *n,
             int m3)
{	
	backpatch(e->back.s_true,m2);
	backpatch(e->s_false,m3);
	backpatch(n,m1);
	if(cont_call == 100){
		
		backpatch(cont,m1);
		cont_call = 0;
		cont = NULL;
	}
	if(break_call == 100){
		
		backpatch(break_node,m3);
		cont_call = 0;
		break_node = NULL;
	}
		
	
}

/*
 * endloopscope - end the scope for a loop
 */
void endloopscope(int m)
{
   fprintf(stderr, "sem: endloopscope not implemented\n");
}

/*
 * exprs - form a list of expressions
 */
struct sem_rec *exprs(struct sem_rec *l, struct sem_rec *e)
{
  
	struct sem_rec *p = merge(l,e);
	return p;
	
}

/*
 * fhead - beginning of function body
 */
void fhead(struct id_entry *p)
{
	int i;
	printf("func %s\n",p->i_name);
	for(i = 0; i < formalnum; i++){
		if(formaltypes[i] == 'f'){
			printf("formal 8\n");
		}else if(formaltypes[i] == 'i'){
			printf("formal 4\n");
		}else{
			yyerror("formal type somehow stored incorrectly");
		}
	}

	for(i = 0; i < localnum; i++){
		if(localtypes[i] == 'f'){
			printf("localloc %d\n", 8*localwidths[i]);
		}else if(localtypes[i] == 'i'){
			printf("localloc %d\n", 4*localwidths[i]);
		}else{
			yyerror("local type somehow stored incorrectly");
		}
	}


   
}

/*
 * fname - function declaration
 */
struct id_entry *fname(int t, char *id)
{
   struct id_entry *p;
   if((p = lookup(id,0)) == NULL){
		p = install(id,0);
   } else if(p->i_defined){
		yyerror("Procedure previously declared");
   } else if(p->i_type != t){
		yyerror("function declaration types do not match");
   }

   p->i_type = t;
   p->i_scope = GLOBAL;
   p->i_defined = 1;
   enterblock();
   formalnum = 0;
   localnum = 0;
   return p;
	
}

/*
 * ftail - end of function body
 */
void ftail()
{
   printf("fend\n");
	leaveblock();	

}

/*
 * id - variable reference
 */
struct sem_rec *id(char *x)
{
   struct id_entry *p;
   struct sem_rec *y;
	
  
   if((p = lookup(x,0)) == NULL){
		p = install(x,0);
   }
		
	if(p->i_scope == 1){
		printf("t%d := %s %d\n",nexttemp(),"param", p->i_offset);
	}else if (p->i_scope == 0){
		printf("t%d := %s %d\n",nexttemp(),"local", p->i_offset);	
	}else if (p->i_scope == 2){
		printf("t%d := %s %s\n",nexttemp(),"global", p->i_name);
	}
	y = (struct sem_rec *) alloc(sizeof(struct sem_rec));
	y->s_place = currtemp();
	y->s_mode = p->i_type;
	
	return y;
	
}

/*
 * indx - subscript
 */
struct sem_rec *indx(struct sem_rec *x, struct sem_rec *i)
{
	struct sem_rec *y = (struct sem_rec *) alloc(sizeof(struct sem_rec));	
	if(x->s_mode == T_ARRAY+T_DOUBLE){
		printf("t%d := t%d []f t%d\n", nexttemp(), x->s_place, i->s_place);
		y->s_mode = T_DOUBLE;
	}
	if(x->s_mode == T_ARRAY+T_INT){
		printf("t%d := t%d []i t%d\n", nexttemp(), x->s_place, i->s_place);
		y->s_mode = T_INT;
	}
	
	y->s_place = currtemp();
	
	return y;
   

}

/*
 * labeldcl - process a label declaration
 */
void labeldcl(char *id)
{
   fprintf(stderr, "sem: labeldcl not implemented\n");
}

/*
 * m - generate label and return next temporary number
 */
int m()
{
 
 printf("label L%d\n", ++labelnum);
 return labelnum;  
	

}

/*
 * n - generate goto and return backpatch pointer
 */
struct sem_rec *n()
{
	
	printf("br B%d\n", ++branchnum);
	n_node = node(branchnum,T_LBL,NULL,NULL);
	 return n_node; 
	//fprintf(stderr, "sem: n not implemented\n");
   //return ((struct sem_rec *) NULL);
}

/*
 * op1 - unary operators
 */
struct sem_rec *op1(char *op, struct sem_rec *y)
{	
	
	if(y->s_mode == T_DOUBLE){
		printf("t%d := %sf t%d\n",nexttemp(),op,currtemp());	
		
	}
	else if(y->s_mode == T_INT){
		printf("t%d := %si t%d\n",nexttemp(),op,currtemp());	
	}
		
	y->s_place = currtemp();
	return y;  
}

/*
 * op2 - arithmetic operators
 */
struct sem_rec *op2(char *op, struct sem_rec *x, struct sem_rec *y)
{
	
	
	if(x->s_mode == T_INT && y->s_mode == T_INT){
		
		printf("t%d := t%d %si t%d\n", nexttemp(), x->s_place,op,y->s_place); 
	}
	else if(x->s_mode == T_DOUBLE && y->s_mode == T_DOUBLE){
		
		printf("t%d := t%d %sf t%d\n", nexttemp(), x->s_place,op,y->s_place);
	}  
	else if(x->s_mode == T_INT || x->s_mode == T_INT+T_ARRAY){
		printf("t%d := cvf t%d\n",nexttemp(),x->s_place);
		printf("t%d := t%d %sf t%d\n", nexttemp(), currtemp(), op, y->s_place);
		x->s_mode = T_DOUBLE;
	}else if(y->s_mode == T_INT || y->s_mode == T_INT+T_ARRAY){
		printf("t%d := cvf t%d\n",nexttemp(),y->s_place);
		printf("t%d := t%d %sf t%d\n", nexttemp(), x->s_place, op, currtemp());
		y->s_mode = T_DOUBLE;
	}
	y->s_place = currtemp();
		return y;  
	
}

/*
 * opb - bitwise operators
 */
struct sem_rec *opb(char *op, struct sem_rec *x, struct sem_rec *y)
{
  	
		printf("t%d := t%d %si t%d\n", nexttemp(), x->s_place, op, y->s_place); 
		y->s_place = currtemp();
		return y;
		
}

/*
 * rel - relational operators
 */
struct sem_rec *rel(char *op, struct sem_rec *x, struct sem_rec *y)
{
	struct sem_rec *p = (struct sem_rec *) alloc(sizeof(struct sem_rec));
	struct sem_rec *p1 = (struct sem_rec *) alloc(sizeof(struct sem_rec));

   	if(x->s_mode == T_DOUBLE){
		printf("t%d := cvf t%d\n",nexttemp(),currtemp());
		printf("t%d := t%d %sf t%d\n", nexttemp(), x->s_place, op, currtemp());
	}
	else if(x->s_mode == T_INT){
	
		printf("t%d := t%d %si t%d\n", nexttemp(), x->s_place, op, currtemp());
	}
		
	printf("bt t%d B%d\n", currtemp(), ++branchnum);
	p1->s_place = branchnum;
	p1->s_mode = T_LBL;
	printf("br B%d\n", ++branchnum);
	p->s_place = branchnum;
	p->s_mode = T_LBL;
	
	struct sem_rec *t = node(p1->s_place,T_LBL, p1, p);
	t->back.s_true = p1;
	
	return t;
	
}

/*
 * set - assignment operators
 */
struct sem_rec *set(char *op, struct sem_rec *x, struct sem_rec *y)
{
	if(strcmp(op,"")!=0){
		if(x->s_mode == T_DOUBLE || x->s_mode == T_ARRAY+T_DOUBLE ){
			printf("t%d := @f t%d\n", nexttemp(), x->s_place);	  
			printf("t%d := t%d %sf t%d\n", nexttemp(),currtemp(),op, y->s_place);
			if(y->s_mode == T_INT)
				printf("t%d := cvf t%d\n",nexttemp(),currtemp());
			printf("t%d := t%d =f t%d\n", nexttemp(),x->s_place, currtemp());
		}else if(x->s_mode == T_INT|| x->s_mode == T_ARRAY+T_INT){
			printf("t%d := @i t%d\n", nexttemp(), x->s_place);   
			printf("t%d := t%d %si t%d\n", nexttemp(),currtemp(),op, y->s_place);
			if(y->s_mode == T_DOUBLE)
				printf("t%d := cvi t%d\n",nexttemp(),currtemp());
			printf("t%d := t%d =i t%d\n", nexttemp(),x->s_place, currtemp());
		}
	}else{
		if(x->s_mode == T_DOUBLE || x->s_mode == T_ARRAY+T_DOUBLE){
			if(y->s_mode == T_INT)
				printf("t%d := cvf t%d\n",nexttemp(),currtemp());
			printf("t%d := t%d =f t%d\n", nexttemp(),x->s_place, currtemp());
		}else if(x->s_mode == T_INT|| x->s_mode == T_ARRAY+T_INT){
			if(y->s_mode == T_DOUBLE)
				printf("t%d := cvi t%d\n",nexttemp(),currtemp());
			
			printf("t%d := t%d =i t%d\n", nexttemp(),x->s_place, currtemp());
		}
	}
	return merge(x,y);
	
	
}

/*
 * startloopscope - start the scope for a loop
 */
void startloopscope()
{
	enterblock();   
	
}

/*
 * string - generate code for a string
 */
struct sem_rec *string(char *s)
{
	struct sem_rec *str;
	printf("t%d := ""%s""\n", nexttemp(),s);
	str = node(currtemp(),1,NULL,NULL);  
	return str;
}
