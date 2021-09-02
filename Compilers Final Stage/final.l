%{ 
		#include <stdio.h>
		#include <stdlib.h> 
		#include "y.tab.h"
		extern int linecount;
%} 

%% 
[ \t] ;

[ \n] 		{++linecount;};
[0-9]+		{ 
			yylval.val=atoi(yytext);
			return NUMBER;
		}
"true"  	{ return TRUE; }
"false" 	{ return FALSE; }
"read"  	{ return READ; }
"write" 	{ return WRITE; }
"if"    	{ return IF; }
"endif"    	{ return ENDIF;}
"else"  	{ return ELSE;}
"while" 	{ return WHILE;}
"endwhile"      { return ENDWHILE;}
"==" 		{ return EQUAL; }
"<="		{ return LE; }
">="		{ return GE; }
"!="		{ return NE; }
"&&"		{ return AND;}
"||"		{ return OR; }
"int"		{ return INT;}
"bool"		{ return BOOL; }
"["		{ return *yytext; }
"]"		{ return *yytext; }
"decl"  	{ return DECL; }
"enddecl"	{ return  ENDDECL; }
"begin" 	{ return BEGI; }
"end"   	{ return END; }
"return"	{ return  RETURN; }
"main"  	{ return  MAIN;}
"then"  	{ return  THEN;}
"do"		{ return DO; }
[a-zA-Z0-9]+  	{
        		yylval.str=malloc(yyleng*sizeof(char));
        		strcpy(yylval.str,yytext);
        		return ID;
        	}
		
[-+*%/<>;\,=()!&|{}^\n]	{ return *yytext; }
.		{ yyerror("Lex Error");}

%%
