%{ 
	#include <stdio.h> 
	#include<stdlib.h>
	#include "y.tab.h"
	#include "final.c"
	int yylex(void);
	int linecount =0;	
	int vartype;
	int codegen(struct node1 *nd);
	struct Argument *add_to_arg_list(int type,char * name,struct Argument *list);
	void Ginstall(char *name,int type, int size,struct Argument *arglist);
	struct Expression *add_to_exp_linked_list(int type,struct node1 *expression,struct Expression *list);
	void Linstall(char *name, int type, int local_args );
	int checkfunc_decl(int type,char * name, struct Argument * arglist) ;
	struct local_symbol_table *Llookup(char *name);
	struct global_symbol_table *Glookup(char *name);
	int array_def=1;
	int recursion =0;
	int call_func =2;
	int bool_cond=-2;
%}

%union
{
	int val;
	char *str;
	struct node1 *ptr;
	struct Expression *pointer1;
	struct Argument *pointer2;
};

%token <val> NUMBER
%token <str> ID
%token MAIN BEGI RETURN WRITE READ IF ENDIF THEN ELSE WHILE END ENDWHILE GE LE NE DO EQUAL AND OR INT BOOL TRUE FALSE DECL ENDDECL START STOP

%type <pointer1> exprlist
%type <pointer2> arglist
%type <ptr> expr
%type <ptr> stmtseq
%type <val> type
%type <ptr> Body
%type <ptr> Retstmt
%type <ptr> READ
%type <ptr> WRITE
%type <ptr> IF
%type <ptr> THEN
%type <ptr> ENDIF 
%type <ptr> WHILE
%type <ptr> DO
%type <ptr> ENDWHILE
%type <ptr> EQUAL
%type <ptr> stmt
%type <ptr> AND
%type <ptr> OR
%type <ptr> RETURN
%type <ptr> BEGI
%type <ptr> MAIN
%type <ptr> END
%type <ptr> GE
%type <ptr> LE
%type <ptr> NE

%left '<' '>' GE NE LE EQUAL
%left AND OR 
%left '+' '-' 
%left '*' '/' '%'

%%

pgm : Gdefblock Fdeflist Mainblock

Gdefblock : DECL dclseq ENDDECL
		  ;
      
dclseq  : dclseq dcl
		| 
		;

dcl     : type intidseq ';'								      
		;

intidseq 	:	 ID ',' intidseq                    {Ginstall($1, vartype, 1,NULL);} 
		 			| ID '[' NUMBER ']' ',' intidseq      {Ginstall($1,vartype,	$3,NULL);}
         	| ID                                 	{Ginstall($1, vartype, 1,NULL);}
         	| ID '[' NUMBER ']'                   {Ginstall($1,vartype,$3,NULL);}
         	| ID '(' arglist ')' ',' intidseq    	{Ginstall($1,vartype+ 3, 0,$3);local_symbol_table=NULL;argument_binding=-3;local_binding=1;}
																													
																													
         	| ID '(' arglist ')'                 	{Ginstall($1, vartype+3, 0,$3);local_symbol_table=NULL;argument_binding=-3;local_binding=1;}
         	;


arglist :  type ID ',' arglist             			{Linstall($2,vartype,0);$$=add_to_arg_list(vartype,$2,$4); }
				|  type '&' ID ',' arglist         			{Linstall($3,vartype+2,0);$$=add_to_arg_list(vartype+2,$3,$5);}
				|  type ID                         			{Linstall($2,vartype,0);$$=add_to_arg_list(vartype,$2,NULL);}
				|  type '&' ID                     			{Linstall($3,vartype+2,0);$$=add_to_arg_list(vartype+2,$3,NULL);}
				|                                  			{$$=NULL;}
				;
		
		
type 		:	INT                                		{vartype=0;} 
	 			|	BOOL                               		{vartype=1;}
	 			;

Fdeflist : Fdeflist fdef
		 |
		 ;
		 
fdef :	type ID '(' arglist ')' '{' LDeclblock Body '}' {
																													regno=0;
																													int label_no=checkfunc_decl(vartype,$2,$4);
																													printf("VISHAL%d:\n",label_no);
																													printf("PUSH BP\n");
																													printf("MOV BP, SP\n");
																													struct Argument *dummy=Glookup($2)->arglist;
																													int arg_count=0;
																													while(dummy!=NULL) 
																													{
																															arg_count=arg_count+1;
																															dummy=dummy->next;																					
																													}
															
																													struct local_symbol_table *dummy2=local_symbol_table;
																													int total_vars=0;
																													while(dummy2!=NULL) 
																													{
																															total_vars=total_vars+1;
																															dummy2=dummy2->next;
																													}
																													int final=total_vars-arg_count;
															
																													printf("MOV R%d, %d\n",regno,final);
																													printf("MOV R%d, SP\n",regno+1);
																													printf("ADD R%d, R%d\n",regno, regno+1);
																													printf("MOV SP, R%d\n",regno);
																													codegen($8);
																													local_symbol_table=NULL;argument_binding=-3;local_binding=1;}
																												
	 ;

LDeclblock 	 : 			DECL localdeclseq ENDDECL

localdeclseq : 			ldcl localdeclseq
			       |
			 			 ;

ldcl    		 : 			type locsequence ';'	    
		
						 ;
		
locsequence  :		  ID ',' locsequence    							{Linstall($1,vartype,1);}
		  			 | 			ID                  								{Linstall($1,vartype,1);}
		  			 ;
		   
Mainblock 	 : INT MAIN '(' ')' '{' LDeclblock Body '}' 
																												{
																												regno=0;
																												
																												struct global_symbol_table * temp;
																												temp=symboltable;
																												while(temp!=NULL)
																												{
																												if(temp->type==0 || temp->type==1) {temp=temp->next;continue;}
																								if(temp->is_function==0) {printf("Function %s is declared but not defined\n",temp->var_name);
																								exit(0);}
																																temp=temp->next;
																																}
																													printf("\n\nMAIN:\n");
																													printf("PUSH BP\nMOV BP, SP\n");
															
																													struct local_symbol_table *dummy1=local_symbol_table;
																													int total_vars=0;
																													while(dummy1!=NULL) 
																													{
																														total_vars++;
																														dummy1=dummy1->next;
																													}
															
																													printf("MOV R%d, %d\n",regno,total_vars);
																													printf("MOV R%d, SP\n",regno+1);
																													printf("ADD R%d, R%d\n",regno, regno+1);
																													printf("MOV SP, R%d\n",regno);
																													codegen($7);
																													local_symbol_table=NULL;
																													argument_binding=-3;
																													local_binding=1;
	
																													printf("\n\nSTART\n");
																													printf("MOV SP, %d\n",sim_space);
																													printf("CALL MAIN\n");
																													printf("HALT\n");
															
																													exit(0);
													 															}

Body 		: BEGI stmtseq Retstmt END    		{$$=make_node(2,recursion,-1,"",NULL,$2,$3,NULL,NULL,NULL);}

Retstmt : RETURN expr ';' 								{$$=make_node(2,RETURN,-1,"",$2,NULL,NULL,NULL,NULL,NULL);}
								
						 

stmtseq : stmtseq stmt 										{$$=make_node(2,recursion,-1,"",NULL,$1,$2,NULL,NULL,NULL);}
        | stmt		   											{$$=$1;}
				;
      
stmt 		: READ '('  ID ')' ';'          		{

																						Ltemp=Llookup($3);
																						if(Ltemp!=NULL)
																			  		{
																			  			$$=make_node(2,READ,-1,$3,NULL,NULL,NULL,NULL,Ltemp,NULL);
																			  		}
																  					else
																  					{
																  						Gtemp=Glookup($3);
																  						$$=make_node(2,READ,-1,$3,NULL,NULL,NULL,Gtemp,NULL,NULL);
																  					}
																  	  		}
     | READ '('  ID '[' expr ']' ')' ';'             {Gtemp=Glookup($3);$$=make_node(2,READ,-1,$3,$5,NULL,NULL,Gtemp,NULL,NULL);}
     | WRITE '(' expr ')' ';'                         {$$=make_node(2,WRITE,-1,"",$3,NULL,NULL,NULL,NULL,NULL); }            
     | ID '=' expr ';'                             {
														Ltemp=Llookup($1);
														if(Ltemp==NULL)
														{
															Gtemp=Glookup($1);
															if(Gtemp->type != $3->type) 
															{
																printf("Different data types on either side of =\n check line number %d \n",linecount);
																exit(0);
															}
															$$=make_node(2,3,-1,$1,NULL,$3,NULL,Gtemp,NULL,NULL);
														}
														else
														{
															if(Ltemp->type != $3->type && Ltemp->type-2 != $3->type) 
															{
																printf("Different data types on either side of =\n check line number %d \n",linecount);
																exit(0);
															}
															$$=make_node(2,3,-1,$1,NULL,$3,NULL,NULL,Ltemp,NULL);
														}
													} 
	 | ID '[' expr ']' '=' expr ';'                {
														if($3->type!=0) { 
															printf("Array index must be an integer\n");
															exit(0);
														 }
														Ltemp=Llookup($1);
														if(Ltemp==NULL)
														{
															Gtemp=Glookup($1);
															if(Gtemp->type != $3->type) 
															{
																printf("Different data types on either side of =\n check line number %d \n",linecount);
																exit(0);
															}
															$$=make_node(2,5,-1,$1,NULL,$3,$6,Gtemp,NULL,NULL);
														}
														else
														{
															if(Ltemp->type != $3->type && Ltemp->type-2 != $3->type) 
															{
																printf("Different data types on either side of =\n check line number %d \n",linecount);
																exit(0);
															}
															$$=make_node(2,5,-1,$1,NULL,$3,$6,NULL,Ltemp,NULL);
														}
												   }  
     | IF '(' expr ')' THEN stmtseq ENDIF ';' {if($3->type!=1) { printf("If condition is an Integer and not boolean\ncheck line %d\n",linecount); exit(0);} $$=make_node(2,IF,-1,"",$3,$6,NULL,NULL,NULL,NULL);}
     | IF '(' expr ')' THEN stmtseq ELSE stmtseq ENDIF ';' {if($3->type!=1) { printf("If condition is an Integer and not boolean\ncheck line number %d \n",linecount); exit(0); } $$=make_node(2,IF,-1,"",$3,$6,$8,NULL,NULL,NULL);}
     | WHILE '(' expr ')' DO stmtseq ENDWHILE  ';'    {if($3->type!=1) { printf("If condition is an Integer and not boolean\ncheck line number %d \n",linecount); exit(0); } $$=make_node(2,WHILE,-1,"",$3,$6,NULL,NULL,NULL,NULL);}
     ;

exprlist : expr ',' exprlist    {$$=add_to_exp_linked_list($1->type,$1,$3);}
		 | expr                 {$$=add_to_exp_linked_list($1->type,$1,NULL);}
		 |                      {$$=NULL;}
		 ;
		 
expr	:	    expr '+' expr	{
									if($1->type!=0 || $3->type!=0) {printf("e+e error check line number %d \n",linecount); exit(0);}
									$$ = make_node(0,'+',-1,"",$1,$3,NULL,NULL,NULL,NULL);
							    }							    
			|	expr '-' expr	{
									if($1->type!=0 || $3->type!=0) {printf("e-e error check line number %d \n",linecount); exit(0);}
									$$ = make_node(0,'-',-1,"",$1,$3,NULL,NULL,NULL,NULL);
								}								
			|	expr '*' expr	{
									if($1->type!=0 || $3->type!=0) {printf("e*e error check line number %d \n",linecount); exit(0);}
									$$ = make_node(0,'*',-1,"",$1,$3,NULL,NULL,NULL,NULL);
								}
			|	expr '/' expr	{
									if($1->type!=0 || $3->type!=0) {printf("/ error check line number %d \n",linecount); exit(0);}
									$$ = make_node(0,'/',-1,"",$1,$3,NULL,NULL,NULL,NULL);
								}								
			|	expr '%' expr	{
									if($1->type!=0 || $3->type!=0) {printf("MOD  error check line number %d \n",linecount); exit(0);}
									$$ = make_node(0,'%',-1,"",$1,$3,NULL,NULL,NULL,NULL);
								}
			|   expr '<' expr   {
									if($1->type!=0 || $3->type!=0) {printf("< error check line number %d \n",linecount); exit(0);}
			                        $$ = make_node(1,'<',-1,"",$1,$3,NULL,NULL,NULL,NULL);
			                    }
			|   expr '>' expr   {
									if($1->type!=0 || $3->type!=0) {printf("> error check line number %d \n",linecount); exit(0);}
			                        $$ = make_node(1,'>',-1,"",$1,$3,NULL,NULL,NULL,NULL);
			                    }
			|   expr LE expr    {
									if($1->type!=0 || $3->type!=0) {printf("LE error check line number %d \n",linecount); exit(0);}
			                        $$ = make_node(1,LE,-1,"",$1,$3,NULL,NULL,NULL,NULL);
			                    }
			|   expr GE expr    {
									if($1->type!=0 || $3->type!=0) {printf("GE error check line number %d \n",linecount); exit(0);}
			                        $$ = make_node(1,GE,-1,"",$1,$3,NULL,NULL,NULL,NULL);
			                    }		
			|   expr EQUAL expr  {
									if($1->type!=0 || $3->type!=0) {printf("== error check line number %d \n",linecount); exit(0);}
			                        $$ = make_node(1,EQUAL,-1,"",$1,$3,NULL,NULL,NULL,NULL);
			                    }			
			|   expr NE expr    {
									if($1->type!=0 || $3->type!=0) {printf("NE error check line number %d \n",linecount); exit(0);}
			                        $$ = make_node(1,NE,-1,"",$1,$3,NULL,NULL,NULL,NULL);
								}
			|	'(' expr ')'	{ $$ = $2; }
			|	NUMBER			{ $$ = make_node(0,NUMBER,$1,"",NULL,NULL,NULL,NULL,NULL,NULL); }
			|   ID              { 
									Ltemp=Llookup($1);
									if(Ltemp==NULL)
									{
										Gtemp=Glookup($1);
										$$=make_node(Gtemp->type,ID,-1,$1,NULL,NULL,NULL,Gtemp,NULL,NULL);
									}
									else
									{
										int variablefortype;
										variablefortype=Ltemp->type;
										if(variablefortype>1) variablefortype-=2;
										$$=make_node(variablefortype,ID,-1,$1,NULL,NULL,NULL,NULL,Ltemp,NULL);
									}
								}
			|	ID '[' expr ']' { if($3->type!=0) { printf("Array index must be an integer\n");exit(0); } 
			                      Ltemp=Llookup($1);
    							  if(Ltemp==NULL)
								  {
									Gtemp=Glookup($1);
									$$=make_node(Gtemp->type,6,-1,$1,$3,NULL,NULL,Gtemp,NULL,NULL);
								  }
								  else
								  {
									$$=make_node(Ltemp->type,6,-1,$1,$3,NULL,NULL,NULL,Ltemp,NULL);
								  }
								}
			|   TRUE              { $$ = make_node(1,bool_cond,1,"",NULL,NULL,NULL,NULL,NULL,NULL); }
			|   FALSE              { $$ = make_node(1,bool_cond,0,"",NULL,NULL,NULL,NULL,NULL,NULL); }
			|   ID '(' exprlist ')'              {
														struct global_symbol_table *glook=Glookup($1);
														int sequencevalue=0;
														struct Expression *list=$3;
														struct Argument *spartan =glook->arglist;
														while(list!=NULL && spartan!=NULL)
														{
															if(spartan->type==list->type){
															printf("%d%d sdada ",spartan->type,list->type);
															list=list->next;
															spartan=spartan->next;
														}
														else{		
														printf("Function %s cadadalled with wrong argument list\n line no %d",$1,linecount);exit(0);}
														}
														list=$3;
														struct Argument *test=glook->arglist;
														while(test!=NULL)
														{
															if(test->type<2) list->isref=0;
															else 
															{
																if(list->expression->node_type!=ID) {printf("Function %s called with expression for referenced variable\n",$1);exit(0);}
																list->isref=1;
															}
															test=test->next;
															list=list->next;
														}
													 	$$=make_node(glook->type-3,call_func,-1,$1,NULL,NULL,NULL,glook,NULL,$3);
												 } 
			;
%% 


struct Argument *add_to_arg_list(int type,char * name,struct Argument *list)
{
	struct Argument *new_decl = malloc(sizeof(struct Argument));
	new_decl->type=type;
	new_decl->name=name;
	new_decl->next=list;
	struct Argument *temp;
	temp=list;
	while(temp!=NULL)
	{
		if(strcmp(new_decl->name,temp->name)==0)
		{
			printf("Same name in arglist see line number %d\n",linecount);
			exit(0);
		} 
		temp=temp->next;
	}
	return new_decl;
}


void Ginstall(char *name,int type, int size,struct Argument *arglist)
{
	
	struct global_symbol_table *temp;
	struct global_symbol_table *new_decl = malloc(sizeof(struct global_symbol_table));	
	new_decl->var_name = name;
	
	new_decl->size = size;
	new_decl->type=type;
	new_decl->arglist=arglist;
	new_decl->is_function=0;
	if (type==0 || type==1)
	{
		new_decl->binding = sim_space;
		sim_space=sim_space+size;
	}
	else
	{
		
		new_decl->binding=funlabel;
		funlabel++;
		new_decl->size=0;
		
	}
	new_decl->next = NULL;
	temp = symboltable;
	if (symboltable == NULL) symboltable = new_decl;
	else 
	{
		while (temp->next != NULL) 
		{	
			if (strcmp(temp->var_name,name) == 0)
			{
				printf("Re-declaration of variable %s in global area see line number %d\n", name,linecount);
				exit(0);
			}
			temp=temp->next;
		}
		if (strcmp(temp->var_name,name) == 0)
		{
			printf("Re-declaration of variable %s in globalarea see line number %d\n", name,linecount);
			exit(0);
		}
		temp->next=new_decl;
	}
}

struct Expression *add_to_exp_linked_list(int type,struct node1 *expression,struct Expression *list)
{
	struct Expression * temp=malloc(sizeof(struct Expression));
	temp->type=type;
	temp->expression=expression;
	temp->next=list;
	return temp;
}

void Linstall(char *name, int type, int local_args )
{
	
	struct local_symbol_table *temp;
	struct local_symbol_table *new_decl  = malloc(sizeof(struct local_symbol_table));	
	new_decl->var_name = name;
	new_decl->type=type;
	if(local_args==0) 
	{
		new_decl->binding=argument_binding;
		argument_binding--;
	}
	else 
        {
        	new_decl->binding=local_binding;
        	local_binding++;
        }
	new_decl->next = NULL;
	temp = local_symbol_table;
	if (local_symbol_table == NULL)
	{ 
		local_symbol_table = new_decl;
	}
	else 
	{
		while (temp->next != NULL)
		{	
			if (strcmp(temp->var_name,name) == 0)
			{
				printf("Re-declaration of variable %s in localarea see line number %d\n", name,linecount);
				exit(0);
			}
			temp=temp->next;
		}
		if (strcmp(temp->var_name,name) == 0)
		{
			printf("Re-declaration of variable %s in localarea see line number %d\n", name,linecount);
			exit(0);
		}
		temp->next=new_decl;
	}	
}


int checkfunc_decl(int type,char * name, struct Argument * arglist)  
{
	struct global_symbol_table *temp;
	temp=symboltable;
	while(temp!=NULL)
	{
		if(strcmp(temp->var_name,name)!=0) {temp=temp->next;continue;}
		if(temp->type!=type+3)
		{
			printf("type diff in func declaration and definition %s area see line number %d\n", name,linecount);
			exit(0);
		}
		struct Argument *tm=temp->arglist;
		struct Argument *ar=arglist;
		while(tm!=NULL)
		{
			if(ar==NULL) 
			{
				printf("Empty arg list passed for function %s area see line number %d\n", name,linecount);
				exit(0);
			}
			if(strcmp(tm->name,ar->name)!=0)
			{
				printf("not same names in definition and declaration for func %s  line number %d\n", name,linecount);
				exit(0);
			}
			if(tm->type!=ar->type)
			{
				printf("not same types of arguments in defninition and declaration for func %s line number %d\n", name,linecount);
				exit(0);
			}
			tm=tm->next;
			ar=ar->next;
		}
		if(ar!=NULL) 
		{
			printf("arg list size is diff for the function in defninition and  declaration %s line number %d\n", name,linecount);
			exit(0);
		}
		temp->is_function=1;
		return temp->binding;
	}
	if(temp==NULL)
	{
		printf("Function %s is not declared\n",name);
	}
}

struct local_symbol_table *Llookup(char *name)
{
	
	struct local_symbol_table *ltemp;
	ltemp = local_symbol_table;
	while(ltemp != NULL)
	{
		if(strcmp(ltemp->var_name, name) == 0)
		{

			return ltemp;
		}

		ltemp = ltemp->next;
	}
	return NULL;
}


struct global_symbol_table *Glookup(char *name)
{
	struct global_symbol_table *temp;
	temp=symboltable;
	while (temp != NULL)
	{
		if (strcmp(temp->var_name,name) == 0)
		{

			return temp;
		}
		temp = temp->next;
	}
	printf("Undeclared variable %s\n",name);
	exit(0);	
}




int codegen(struct node1 *nd)
{
		if(nd->node_type== recursion){                              
				codegen(nd->middle);
				codegen(nd->right);
				}

		else if(nd->node_type== READ){
				if(nd->left!=NULL)      
				{
					codegen(nd->left);
					tmp=nd->gentry->binding;
					printf("MOV R%d,%d\n",regno, tmp);
					printf("ADD R%d,R%d\n",regno-1, regno);
					printf("IN R%d\n",regno);
					printf("MOV [R%d],R%d\n",regno-1,regno);
					regno--;
				}
				else 
				{
					if(nd->lentry==NULL)
					{
						tmp=nd->gentry->binding;
						printf("IN R%d\n",regno);
						printf("MOV [%d], R%d\n",tmp,regno);
					}
					else
					{
						tmp=nd->lentry->binding;
						printf("MOV R%d, BP\n",regno);
						printf("MOV R%d, %d\n",regno+1,tmp);
						printf("ADD R%d, R%d\n",regno,regno+1);
						if(nd->lentry->type>=2) printf("MOV R%d, [R%d]\n",regno,regno);
						printf("IN R%d\n",regno+1);
						printf("MOV [R%d], R%d\n",regno,regno+1);
					}
				}
				}
else if(nd->node_type== WRITE){
				codegen(nd->left);
				printf("OUT R%d\n",regno-1);
				regno--;
				}
else if(nd->node_type== 3){
				codegen(nd->middle);
				if(nd->lentry==NULL)
				{
					tmp=nd->gentry->binding;
					printf("MOV [%d],R%d\n",tmp,regno-1);
					regno--;
				}
				else
				{
					tmp=nd->lentry->binding;
					printf("MOV R%d, BP\n",regno);
					printf("MOV R%d, %d\n",regno+1,tmp);
					printf("ADD R%d, R%d\n",regno,regno+1);
					if(nd->lentry->type>=2) printf("MOV R%d, [R%d]\n",regno,regno);
					printf("MOV [R%d], R%d\n",regno,regno-1);
					regno--;
				}
}
else if(nd->node_type== IF){
				codegen(nd->left);
				int locallabel=label;
				label+=2;
				printf("JZ R%d,LBL%d\n",regno-1,locallabel);
				regno--;
				codegen(nd->middle);
				if(nd->right!=NULL) printf("JMP LBL%d\n",locallabel+1);
				printf("LBL%d:\n",locallabel);
				if(nd->right!=NULL)
				{
					codegen(nd->right);
					printf("LBL%d:\n",locallabel+1);
				}
}
else if(nd->node_type== WHILE){
				;
				int loclabel=label;
				label+=2;
				printf("LBL%d:\n",loclabel);
				codegen(nd->left);
				printf("JZ R%d,LBL%d\n",regno-1,loclabel+1);
				regno--;
				codegen(nd->middle);
				printf("JMP LBL%d\n",loclabel);
				printf("LBL%d:\n",loclabel+1);
}
else if(nd->node_type== '+'){
				codegen(nd->left);
				codegen(nd->middle);
				printf("ADD R%d,R%d\n",regno-2,regno-1);
				regno--;
				return nd->value;
}
else if(nd->node_type== '-'){
				codegen(nd->left);
				codegen(nd->middle);
				printf("SUB R%d,R%d\n",regno-2,regno-1);
				regno--;
}
else if(nd->node_type== '*'){
				codegen(nd->left);
				codegen(nd->middle);
				printf("MUL R%d,R%d\n",regno-2,regno-1);
				regno--;
}
else if(nd->node_type== '/'){
				codegen(nd->left);
				codegen(nd->middle);
				printf("DIV R%d,R%d\n",regno-2,regno-1);
				regno--;
}

else if(nd->node_type== '%'){
				codegen(nd->left);
				codegen(nd->middle);
				printf("MOD R%d,R%d\n",regno-2,regno-1);
				regno--;
}
else if(nd->node_type== '<'){
				codegen(nd->left);
				codegen(nd->middle);
				printf("LT R%d,R%d\n",regno-2,regno-1);
				regno--;
}
else if(nd->node_type== '>'){
				codegen(nd->left);
				codegen(nd->middle);
				printf("GT R%d,R%d\n",regno-2,regno-1);
				regno--;
}
else if(nd->node_type== LE){
				codegen(nd->left);
				codegen(nd->middle);
				printf("LE R%d,R%d\n",regno-2,regno-1);
				regno--;
}
else if(nd->node_type== GE){
				codegen(nd->left);
				codegen(nd->middle);
				printf("GE R%d,R%d\n",regno-2,regno-1);
				regno--;
}
else if(nd->node_type== EQUAL){
				codegen(nd->left);
				codegen(nd->middle);
				printf("EQ R%d,R%d\n",regno-2,regno-1);
				regno--;
}
else if(nd->node_type== NE){
				codegen(nd->left);
				codegen(nd->middle);
				printf("NE R%d,R%d\n",regno-2,regno-1);
				regno--;
}
else if(nd->node_type== NUMBER){
				printf("MOV R%d,%d\n",regno,nd->value);
				regno++;
}
else if(nd->node_type== ID){
				if(nd->lentry==NULL)
				{
					tmp=nd->gentry->binding;
					printf("MOV R%d,[%d]\n", regno, tmp);
					regno++;
				}
				else
				{
					tmp=nd->lentry->binding;
					printf("MOV R%d, BP\n",regno);
					printf("MOV R%d, %d\n",regno+1,tmp);
					printf("ADD R%d, R%d\n",regno+1,regno);
					if(nd->lentry->type>=2) printf("MOV R%d, [R%d]\n",regno+1,regno+1);
					printf("MOV R%d, [R%d]\n",regno, regno+1);
					regno++;
				}	
}
else if(nd->node_type== 6){
				codegen(nd->left);
				tmp = nd->gentry->binding;
				printf("MOV R%d,%d\n", regno, tmp);
				printf("ADD R%d,R%d\n", regno-1, regno);
				printf("MOV R%d,[R%d]\n", regno-1, regno-1);
}
else if(nd->node_type== 5){
				codegen(nd->middle);
				codegen(nd->right);
				tmp=nd->gentry->binding;
				printf("MOV R%d,%d\n", regno, tmp);
				printf("ADD R%d,R%d\n", regno-2, regno);
				printf("MOV [R%d],R%d\n",regno-2,regno-1);
				regno--;
				regno--;
			}
else if(nd->node_type== bool_cond){
		        	printf("MOV R%d,%d\n",regno,nd->value);
				regno++;
}
else if(nd->node_type== call_func){
				
				int i;
				for(i=0;i<regno;i++) printf("PUSH R%d\n",i);
				struct Expression *local_list;
				local_list=nd->exp_linked_list;
				while(local_list!=NULL)
				{
					if(local_list->isref==0)
					{	
						codegen(local_list->expression);
						local_list=local_list->next;
						printf("PUSH R%d\n",regno-1);
						regno--;
					}
					else
					{
						struct local_symbol_table *local_lookup=Llookup(local_list->expression->name);
						struct global_symbol_table *global_lookup=NULL;
						if(local_lookup==NULL) {global_lookup=Glookup(local_list->expression->name);}
						if(local_lookup!=NULL && local_lookup->type>1)
						{
							
							printf("MOV R%d, BP\n",regno);
							printf("MOV R%d, %d\n",regno+1,local_lookup->binding);
							printf("ADD R%d, R%d\n",regno+1,regno);
							printf("MOV R%d, [R%d]\n",regno, regno+1);
					
							local_list=local_list->next;
							printf("PUSH R%d\n",regno);
						}
						else
						{
							
							if(local_lookup==NULL)
							{
								tmp=global_lookup->binding;
								printf("MOV R%d, %d\n", regno, tmp);
								printf("PUSH R%d\n",regno);
							}
							else
							{
								tmp=local_lookup->binding;
								printf("MOV R%d, BP\n",regno);
								printf("MOV R%d, %d\n",regno+1,tmp);
								printf("ADD R%d, R%d\n",regno,regno+1);
								printf("PUSH R%d\n",regno);
							}	
							local_list=local_list->next;
						}
					}
				}
				printf("PUSH R0\n");//for ret address
				printf("CALL VISHAL%d\n",nd->gentry->binding);
				printf("POP R%d\n",regno);
				regno++;
				local_list=nd->exp_linked_list;
				while(local_list!=NULL)
				{
					local_list=local_list->next;
					printf("POP R%d\n",regno);
				}
				
				for(i=regno-2;i>=0;i--) 
				printf("POP R%d\n",i);
}
else if(nd->node_type== RETURN){
				codegen(nd->left);
				printf("MOV R%d, -2\n",regno);
				printf("MOV R%d, BP\n",regno+1);
				printf("ADD R%d, R%d,\n",regno,regno+1);
				printf("MOV [R%d], R%d\n",regno,regno-1);
				printf("MOV SP, BP\n");
				printf("POP BP\nRET\n");
}
}
yywrap()
{
	return 1;
}
yyerror(char *s) 
{ 
	printf("%s %d\n",s,linecount); 
} 

main() 
{
	yyparse(); 
	return 1; 
}
