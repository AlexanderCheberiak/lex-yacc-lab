%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

extern int yylineno;
extern FILE* yyin;
extern int yyparse();
extern int yylex();
extern void yyerror(const char* s);

ASTNode* root = NULL;
int parse_error = 0;

%}

%union {
    int int_val;
    char* string_val;
    ASTNode* ast_node;
}

%token <int_val> INTEGER_LITERAL
%token <string_val> FLOAT_LITERAL STRING_LITERAL CHAR_LITERAL IDENTIFIER
%token <string_val> AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE
%token <string_val> ELSE ENUM EXTERN FLOAT FOR GOTO IF INT LONG REGISTER
%token <string_val> RETURN SHORT SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF
%token <string_val> UNION UNSIGNED VOID VOLATILE WHILE
%token <string_val> PLUS MINUS MULTIPLY DIVIDE MODULO ASSIGN EQUAL NOT_EQUAL
%token <string_val> LESS LESS_EQUAL GREATER GREATER_EQUAL AND OR NOT
%token <string_val> BITWISE_AND BITWISE_OR BITWISE_XOR BITWISE_NOT
%token <string_val> LEFT_SHIFT RIGHT_SHIFT INCREMENT DECREMENT
%token <string_val> PLUS_ASSIGN MINUS_ASSIGN MULTIPLY_ASSIGN DIVIDE_ASSIGN
%token <string_val> MODULO_ASSIGN AND_ASSIGN OR_ASSIGN XOR_ASSIGN
%token <string_val> LEFT_SHIFT_ASSIGN RIGHT_SHIFT_ASSIGN
%token <string_val> LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET
%token <string_val> SEMICOLON COMMA DOT ARROW QUESTION COLON

%type <ast_node> program external_declaration declaration function_definition
%type <ast_node> type_specifier parameter_list parameter statement
%type <ast_node> statement_list expression primary_expression postfix_expression
%type <ast_node> unary_expression multiplicative_expression additive_expression
%type <ast_node> relational_expression equality_expression logical_and_expression
%type <ast_node> logical_or_expression assignment_expression
%type <ast_node> argument_list

%start program

%left OR
%left AND
%left EQUAL NOT_EQUAL
%left LESS GREATER LESS_EQUAL GREATER_EQUAL
%left PLUS MINUS
%left MULTIPLY DIVIDE MODULO
%right NOT
%right ASSIGN

%%

program:
    external_declaration
    {
        root = $1;
        $$ = create_ast_node(AST_PROGRAM, TYPE_VOID, NULL);
        $$->child = $1;
    }
    | program external_declaration
    {
        if ($$ == NULL) {
            $$ = create_ast_node(AST_PROGRAM, TYPE_VOID, NULL);
        }
        if ($2 != NULL) {
            if ($$->child == NULL) {
                $$->child = $2;
            } else {
                ASTNode* current = $$->child;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = $2;
            }
        }
        root = $$;
    }
    ;

external_declaration:
    function_definition
    | declaration
    ;

function_definition:
    type_specifier IDENTIFIER LPAREN parameter_list RPAREN LBRACE statement_list RBRACE
    {
        $$ = create_ast_node(AST_FUNCTION_DEF, $1->data_type, $2);
        $$->child = $4;  // parameters
        $$->right = $7;  // body
        free_ast_node($1);
    }
    | type_specifier IDENTIFIER LPAREN RPAREN LBRACE statement_list RBRACE
    {
        $$ = create_ast_node(AST_FUNCTION_DEF, $1->data_type, $2);
        $$->right = $6;  // body
        free_ast_node($1);
    }
    ;

declaration:
    type_specifier IDENTIFIER SEMICOLON
    {
        $$ = create_variable_decl($2, $1->data_type);
        free_ast_node($1);
    }
    | type_specifier IDENTIFIER ASSIGN expression SEMICOLON
    {
        $$ = create_ast_node(AST_VARIABLE_DEF, $1->data_type, $2);
        $$->left = $4;
        free_ast_node($1);
    }
    ;

type_specifier:
    INT
    {
        $$ = create_ast_node(AST_TYPE_SPECIFIER, TYPE_INT, NULL);
    }
    | FLOAT
    {
        $$ = create_ast_node(AST_TYPE_SPECIFIER, TYPE_FLOAT, NULL);
    }
    | DOUBLE
    {
        $$ = create_ast_node(AST_TYPE_SPECIFIER, TYPE_DOUBLE, NULL);
    }
    | CHAR
    {
        $$ = create_ast_node(AST_TYPE_SPECIFIER, TYPE_CHAR, NULL);
    }
    | VOID
    {
        $$ = create_ast_node(AST_TYPE_SPECIFIER, TYPE_VOID, NULL);
    }
    ;

parameter_list:
    parameter
    | parameter_list COMMA parameter
    {
        if ($$ == NULL) {
            $$ = create_ast_node(AST_PARAMETER_LIST, TYPE_VOID, NULL);
        }
        if ($3 != NULL) {
            if ($$->child == NULL) {
                $$->child = $3;
            } else {
                ASTNode* current = $$->child;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = $3;
            }
        }
    }
    ;

parameter:
    type_specifier IDENTIFIER
    {
        $$ = create_ast_node(AST_PARAMETER, $1->data_type, $2);
        free_ast_node($1);
    }
    ;

statement:
    expression SEMICOLON
    {
        $$ = create_ast_node(AST_EXPRESSION_STMT, TYPE_VOID, NULL);
        $$->left = $1;
    }
    | declaration
    {
        $$ = $1;
    }
    | LBRACE statement_list RBRACE
    {
        $$ = create_block_stmt($2);
    }
    | LBRACE RBRACE
    {
        $$ = create_block_stmt(NULL);
    }
    | IF LPAREN expression RPAREN statement
    {
        $$ = create_if_stmt($3, $5, NULL);
    }
    | IF LPAREN expression RPAREN statement ELSE statement
    {
        $$ = create_if_stmt($3, $5, $7);
    }
    | WHILE LPAREN expression RPAREN statement
    {
        $$ = create_while_stmt($3, $5);
    }
    | FOR LPAREN expression SEMICOLON expression SEMICOLON expression RPAREN statement
    {
        $$ = create_for_stmt($3, $5, $7, $9);
    }
    | RETURN expression SEMICOLON
    {
        $$ = create_return_stmt($2);
    }
    | RETURN SEMICOLON
    {
        $$ = create_return_stmt(NULL);
    }
    | BREAK SEMICOLON
    {
        $$ = create_ast_node(AST_BREAK_STMT, TYPE_VOID, NULL);
    }
    | CONTINUE SEMICOLON
    {
        $$ = create_ast_node(AST_CONTINUE_STMT, TYPE_VOID, NULL);
    }
    ;

statement_list:
    statement
    | statement_list statement
    {
        if ($$ == NULL) {
            $$ = create_ast_node(AST_STATEMENT_LIST, TYPE_VOID, NULL);
        }
        if ($2 != NULL) {
            if ($$->child == NULL) {
                $$->child = $2;
            } else {
                ASTNode* current = $$->child;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = $2;
            }
        }
    }
    | /* empty */
    {
        $$ = NULL;
    }
    ;

expression:
    assignment_expression
    ;

assignment_expression:
    logical_or_expression
    | IDENTIFIER ASSIGN assignment_expression
    {
        $$ = create_ast_node(AST_ASSIGNMENT, TYPE_VOID, NULL);
        $$->left = create_identifier($1);
        $$->right = $3;
    }
    ;

logical_or_expression:
    logical_and_expression
    | logical_or_expression OR logical_and_expression
    {
        $$ = create_binary_op(AST_BINARY_OP, $1, $3);
    }
    ;

logical_and_expression:
    equality_expression
    | logical_and_expression AND equality_expression
    {
        $$ = create_binary_op(AST_BINARY_OP, $1, $3);
    }
    ;

equality_expression:
    relational_expression
    | equality_expression EQUAL relational_expression
    {
        $$ = create_binary_op(AST_BINARY_OP, $1, $3);
    }
    | equality_expression NOT_EQUAL relational_expression
    {
        $$ = create_binary_op(AST_BINARY_OP, $1, $3);
    }
    ;

relational_expression:
    additive_expression
    | relational_expression LESS additive_expression
    {
        $$ = create_binary_op(AST_BINARY_OP, $1, $3);
    }
    | relational_expression GREATER additive_expression
    {
        $$ = create_binary_op(AST_BINARY_OP, $1, $3);
    }
    | relational_expression LESS_EQUAL additive_expression
    {
        $$ = create_binary_op(AST_BINARY_OP, $1, $3);
    }
    | relational_expression GREATER_EQUAL additive_expression
    {
        $$ = create_binary_op(AST_BINARY_OP, $1, $3);
    }
    ;

additive_expression:
    multiplicative_expression
    | additive_expression PLUS multiplicative_expression
    {
        $$ = create_binary_op(AST_BINARY_OP, $1, $3);
    }
    | additive_expression MINUS multiplicative_expression
    {
        $$ = create_binary_op(AST_BINARY_OP, $1, $3);
    }
    ;

multiplicative_expression:
    unary_expression
    | multiplicative_expression MULTIPLY unary_expression
    {
        $$ = create_binary_op(AST_BINARY_OP, $1, $3);
    }
    | multiplicative_expression DIVIDE unary_expression
    {
        $$ = create_binary_op(AST_BINARY_OP, $1, $3);
    }
    | multiplicative_expression MODULO unary_expression
    {
        $$ = create_binary_op(AST_BINARY_OP, $1, $3);
    }
    ;

unary_expression:
    postfix_expression
    | PLUS unary_expression
    {
        $$ = create_unary_op(AST_UNARY_OP, $2);
    }
    | MINUS unary_expression
    {
        $$ = create_unary_op(AST_UNARY_OP, $2);
    }
    | NOT unary_expression
    {
        $$ = create_unary_op(AST_UNARY_OP, $2);
    }
    | INCREMENT unary_expression
    {
        $$ = create_unary_op(AST_UNARY_OP, $2);
    }
    | DECREMENT unary_expression
    {
        $$ = create_unary_op(AST_UNARY_OP, $2);
    }
    ;

postfix_expression:
    primary_expression
    | postfix_expression LPAREN argument_list RPAREN
    {
        $$ = create_function_call($1->value, $3);
    }
    | postfix_expression LPAREN RPAREN
    {
        $$ = create_function_call($1->value, NULL);
    }
    | postfix_expression LBRACKET expression RBRACKET
    {
        $$ = create_ast_node(AST_ARRAY_ACCESS, TYPE_INT, NULL);
        $$->left = $1;
        $$->right = $3;
    }
    | postfix_expression INCREMENT
    {
        $$ = create_unary_op(AST_UNARY_OP, $1);
    }
    | postfix_expression DECREMENT
    {
        $$ = create_unary_op(AST_UNARY_OP, $1);
    }
    ;

primary_expression:
    IDENTIFIER
    {
        $$ = create_identifier($1);
    }
    | INTEGER_LITERAL
    {
        char* value = malloc(32);
        sprintf(value, "%d", $1);
        $$ = create_literal(AST_INTEGER_LITERAL, value);
        free(value);
    }
    | FLOAT_LITERAL
    {
        $$ = create_literal(AST_FLOAT_LITERAL, $1);
    }
    | STRING_LITERAL
    {
        $$ = create_literal(AST_STRING_LITERAL, $1);
    }
    | CHAR_LITERAL
    {
        $$ = create_literal(AST_CHAR_LITERAL, $1);
    }
    | LPAREN expression RPAREN
    {
        $$ = $2;
    }
    ;

argument_list:
    assignment_expression
    {
        $$ = create_ast_node(AST_STATEMENT_LIST, TYPE_VOID, NULL);
        $$->child = $1;
    }
    | argument_list COMMA assignment_expression
    {
        if ($$ == NULL) {
            $$ = create_ast_node(AST_STATEMENT_LIST, TYPE_VOID, NULL);
        }
        if ($3 != NULL) {
            if ($$->child == NULL) {
                $$->child = $3;
            } else {
                ASTNode* current = $$->child;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = $3;
            }
        }
    }
    ;

%%

void yyerror(const char* s) {
    printf("Parse error at line %d: %s\n", yylineno, s);
    parse_error = 1;
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            printf("Error: Cannot open file %s\n", argv[1]);
            return 1;
        }
    }
    
    int result = yyparse();
    
    if (result == 0 && !parse_error) {
        printf("Parsing successful!\n");
        if (root) {
            printf("\nAST Structure:\n");
            print_ast(root, 0);
            
            // Generate JSON for visualization
            FILE* json_file = fopen("ast.json", "w");
            if (json_file) {
                print_ast_json(root, json_file);
                fclose(json_file);
                printf("\nAST JSON saved to ast.json\n");
            }
            
            // Generate code
            FILE* code_file = fopen("generated.c", "w");
            if (code_file) {
                generate_code(root, code_file);
                fclose(code_file);
                printf("Generated code saved to generated.c\n");
            }
        }
    } else {
        printf("Parsing failed!\n");
    }
    
    if (yyin != stdin) {
        fclose(yyin);
    }
    
    if (root) {
        free_ast_node(root);
    }
    
    return result;
}
