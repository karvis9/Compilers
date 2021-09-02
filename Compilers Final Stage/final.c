#include<stdbool.h>

int regno=0;
int sim_space=1;   
int label=0;        
int tmp;
int funlabel=0;    
int local_binding=1;
int argument_binding=-3;
extern int linecount;
struct global_symbol_table *Gtemp;
struct local_symbol_table *Ltemp;


struct Argument
{
	int type;
	char* name;
	struct Argument *next;
};

struct global_symbol_table
{
	char *var_name;
	int type;
	int size;     
	int binding;  
	int is_function; 
	struct Argument *arglist;
	struct global_symbol_table *next;
}*symboltable,atemp;

struct local_symbol_table
{
	char *var_name;
	int type;  
	int binding;
	struct local_symbol_table *next;
}*local_symbol_table;

struct Expression
{
	int type;
	int isref;
	struct node1 * expression;
	struct Expression * next;
};


struct node1
{
	int type; 
	int node_type;
	int value;
	char *name;
	struct node1 *left, *middle, *right;
	struct global_symbol_table *gentry;
	struct local_symbol_table *lentry;
	struct Expression *exp_linked_list;
};







//creating a tree node

struct node1 *make_node(int type, int node_type, int val,char *name, struct node1 *spartan,struct node1 *pt2, struct node1 *pt3,struct global_symbol_table *gentry, struct local_symbol_table *lentry, struct Expression *exp_linked_list)
{
		struct node1 *tree_node;
		tree_node = malloc(sizeof(struct node1));
		tree_node->type = type;
		tree_node->node_type = node_type;
		tree_node->value = val;
		tree_node->name = name;
		tree_node->left = spartan;
		tree_node->middle = pt2;
		tree_node->right = pt3;
		tree_node->gentry=gentry;
		tree_node->lentry = lentry;  
		tree_node->exp_linked_list=exp_linked_list;
		return tree_node;
}


		


