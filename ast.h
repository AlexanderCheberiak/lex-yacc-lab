#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* AST Node Types */
typedef enum {
    AST_PROGRAM,
    AST_FUNCTION_DECL,
    AST_FUNCTION_DEF,
    AST_VARIABLE_DECL,
    AST_VARIABLE_DEF,
    AST_TYPE_SPECIFIER,
    AST_PARAMETER_LIST,
    AST_PARAMETER,
    AST_STATEMENT_LIST,
    AST_EXPRESSION_STMT,
    AST_IF_STMT,
    AST_WHILE_STMT,
    AST_FOR_STMT,
    AST_RETURN_STMT,
    AST_BREAK_STMT,
    AST_CONTINUE_STMT,
    AST_BLOCK_STMT,
    AST_ASSIGNMENT,
    AST_BINARY_OP,
    AST_UNARY_OP,
    AST_FUNCTION_CALL,
    AST_VARIABLE_REF,
    AST_INTEGER_LITERAL,
    AST_FLOAT_LITERAL,
    AST_STRING_LITERAL,
    AST_CHAR_LITERAL,
    AST_ARRAY_ACCESS,
    AST_POINTER_DEREF,
    AST_ADDRESS_OF,
    AST_CAST,
    AST_SIZEOF,
    AST_TERNARY_OP
} ASTNodeType;

/* Data Types */
typedef enum {
    TYPE_VOID,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_CHAR,
    TYPE_POINTER,
    TYPE_ARRAY,
    TYPE_STRUCT,
    TYPE_UNION
} DataType;

/* AST Node Structure */
typedef struct ASTNode {
    ASTNodeType type;
    DataType data_type;
    char* value;
    struct ASTNode* left;
    struct ASTNode* right;
    struct ASTNode* child;
    struct ASTNode* next;
    int line_number;
    int column_number;
} ASTNode;

/* Function prototypes */
ASTNode* create_ast_node(ASTNodeType type, DataType data_type, char* value);
ASTNode* create_binary_op(ASTNodeType type, ASTNode* left, ASTNode* right);
ASTNode* create_unary_op(ASTNodeType type, ASTNode* operand);
ASTNode* create_literal(ASTNodeType type, char* value);
ASTNode* create_identifier(char* name);
ASTNode* create_function_call(char* name, ASTNode* args);
ASTNode* create_variable_decl(char* name, DataType type);
ASTNode* create_function_decl(char* name, DataType return_type, ASTNode* params);
ASTNode* create_if_stmt(ASTNode* condition, ASTNode* then_stmt, ASTNode* else_stmt);
ASTNode* create_while_stmt(ASTNode* condition, ASTNode* body);
ASTNode* create_for_stmt(ASTNode* init, ASTNode* condition, ASTNode* increment, ASTNode* body);
ASTNode* create_return_stmt(ASTNode* expression);
ASTNode* create_block_stmt(ASTNode* statements);

void free_ast_node(ASTNode* node);
void print_ast(ASTNode* node, int depth);
void print_ast_json(ASTNode* node, FILE* file);
void generate_code(ASTNode* node, FILE* file);
void visualize_ast_html(ASTNode* node, FILE* file);

/* Helper functions */
const char* ast_node_type_to_string(ASTNodeType type);
const char* data_type_to_string(DataType type);
DataType string_to_data_type(const char* type_str);

#endif /* AST_H */
