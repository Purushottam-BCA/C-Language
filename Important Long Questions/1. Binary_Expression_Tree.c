// A string of EXPRESSION is given. Build a binary expression tree and traverse it in all 3 order.

#include<stdio.h>
#include<malloc.h>
#include<ctype.h>
#include<string.h>

typedef struct node   // Expression Tree Node
{
    char data;
    struct node *left;
    struct node *right;
} Node;

Node* Stack[30];  // Stack of Nodes of Tree
int TOP=-1;

void push(Node *data)
{
   Stack[++TOP] = data;
}

Node* pop()
{
   if(TOP!=-1)
   {
    Node *temp= Stack[TOP--];
    return (temp);
   }
}

char Char_Stack[30];    // Stack to evaluate Single expression
int TOS=-1;

void push_char(char ch)
{
   Char_Stack[++TOS] = ch;
}

char pop_char()
{
   if(TOS!=-1)
   {
    char temp= Char_Stack[TOS--];
    return (temp);
   }
}

void InOrder(Node *tree)    // Inorder Traversal
{
   if (tree != NULL)
    {
      InOrder(tree->left);
      printf("%c ",tree->data);
      InOrder(tree->right);
   }
}

void PreOrder(Node *tree)
{
   if (tree != NULL)
   {
      printf("%c ",tree->data);
      PreOrder(tree->left);
      PreOrder(tree->right);
   }
}

void PostOrder(Node *tree)
{
   if (tree != NULL)
   {
      PostOrder(tree->left);
      PostOrder(tree->right);
      printf("%c ",tree->data);
   }
}

int priority(char ch)  // Finding Priority of Operators
{
    if(ch=='^') return 3;   // Highest Priority
    if(ch == '*' || ch == '/' ) return 2;
    if(ch == '+' || ch == '-')  return 1;
    return 0; // If Not a operator
}

Node* Create(char ch)
{
    Node *New=(Node*)malloc(sizeof(Node));
    New->data = ch;
    New->left = New->right = NULL;
    return New;
}

Node* Make_Tree(char *Exp)  // Actual Expression Tree
{
    int index=0;
    char ch=Exp[index];
    Node *New;
    while(ch!='\0')
    {
        if(ch=='(')           // Push '(' in char stack
            push_char(ch);
        else if(isalnum(ch))  // Operand Then Push it onto Node Stack
        {
            New = Create(ch);
            push(New);
        }
        else if (priority(ch)>0)  // if it is a valid Operator
        {
            while((TOS!=-1 && Char_Stack[TOS]!='(') && priority(Char_Stack[TOS])>=priority(ch))
            {
                New = Create(Char_Stack[TOS]);
                pop_char();
                New->right = pop();
                New->left = pop();
                push(New);
            }
            push_char(ch);
        }
        else if(ch==')') // If Right Parenthesis Found
        {
            while(Char_Stack[TOS]!='(' && TOS!=-1)
            {
                New = Create(Char_Stack[TOS]); pop_char();
                New->right = pop(); New->left = pop();
                push(New);
            }
          pop_char(); //delete the left parenthesis also
        }
        ch=Exp[++index];     // Move to next character
    }
 return(Stack[TOP]);
}

int main()
{
   Node *Root;
   char exp[30] = "(a*(b+c)-(d*e-f)*g)";
   printf("EXPRESSION : %s\n", exp);
   push_char('(');  // Push ( to stack
   strcat(exp,")"); // Add ) at the end of expression
   Root = Make_Tree(exp);
   printf("\nINORDER TRAVERSAL : ");
   InOrder(Root);
   printf("\n\nPREORDER TRAVERSAL : ");
   PreOrder(Root);
   printf("\n\nPOSTORDER TRAVERSAL : ");
   PostOrder(Root);
   return 0;
}

