#include "ast.h"
#define _GNU_SOURCE
#include <string.h>

/* Custom strdup implementation for compatibility */
char* my_strdup(const char* s) {
    if (!s) return NULL;
    size_t len = strlen(s) + 1;
    char* dup = malloc(len);
    if (dup) {
        memcpy(dup, s, len);
    }
    return dup;
}

/* Create a new AST node */
ASTNode* create_ast_node(ASTNodeType type, DataType data_type, char* value) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    if (!node) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }
    
    node->type = type;
    node->data_type = data_type;
    node->value = value ? my_strdup(value) : NULL;
    node->left = NULL;
    node->right = NULL;
    node->child = NULL;
    node->next = NULL;
    node->line_number = 0;
    node->column_number = 0;
    
    return node;
}

/* Create binary operation node */
ASTNode* create_binary_op(ASTNodeType type, ASTNode* left, ASTNode* right) {
    ASTNode* node = create_ast_node(type, TYPE_INT, NULL);
    node->left = left;
    node->right = right;
    return node;
}

/* Create unary operation node */
ASTNode* create_unary_op(ASTNodeType type, ASTNode* operand) {
    ASTNode* node = create_ast_node(type, TYPE_INT, NULL);
    node->left = operand;
    return node;
}

/* Create literal node */
ASTNode* create_literal(ASTNodeType type, char* value) {
    DataType data_type = TYPE_INT;
    if (type == AST_FLOAT_LITERAL) data_type = TYPE_FLOAT;
    else if (type == AST_STRING_LITERAL) data_type = TYPE_POINTER;
    else if (type == AST_CHAR_LITERAL) data_type = TYPE_CHAR;
    
    return create_ast_node(type, data_type, value);
}

/* Create identifier node */
ASTNode* create_identifier(char* name) {
    return create_ast_node(AST_VARIABLE_REF, TYPE_INT, name);
}

/* Create function call node */
ASTNode* create_function_call(char* name, ASTNode* args) {
    ASTNode* node = create_ast_node(AST_FUNCTION_CALL, TYPE_INT, name);
    node->child = args;
    return node;
}

/* Create variable declaration node */
ASTNode* create_variable_decl(char* name, DataType type) {
    ASTNode* node = create_ast_node(AST_VARIABLE_DECL, type, name);
    return node;
}

/* Create function declaration node */
ASTNode* create_function_decl(char* name, DataType return_type, ASTNode* params) {
    ASTNode* node = create_ast_node(AST_FUNCTION_DECL, return_type, name);
    node->child = params;
    return node;
}

/* Create if statement node */
ASTNode* create_if_stmt(ASTNode* condition, ASTNode* then_stmt, ASTNode* else_stmt) {
    ASTNode* node = create_ast_node(AST_IF_STMT, TYPE_VOID, NULL);
    node->left = condition;
    node->right = then_stmt;
    node->child = else_stmt;
    return node;
}

/* Create while statement node */
ASTNode* create_while_stmt(ASTNode* condition, ASTNode* body) {
    ASTNode* node = create_ast_node(AST_WHILE_STMT, TYPE_VOID, NULL);
    node->left = condition;
    node->right = body;
    return node;
}

/* Create for statement node */
ASTNode* create_for_stmt(ASTNode* init, ASTNode* condition, ASTNode* increment, ASTNode* body) {
    ASTNode* node = create_ast_node(AST_FOR_STMT, TYPE_VOID, NULL);
    node->left = init;
    node->right = condition;
    node->child = increment;
    node->next = body;
    return node;
}

/* Create return statement node */
ASTNode* create_return_stmt(ASTNode* expression) {
    ASTNode* node = create_ast_node(AST_RETURN_STMT, TYPE_VOID, NULL);
    node->left = expression;
    return node;
}

/* Create block statement node */
ASTNode* create_block_stmt(ASTNode* statements) {
    ASTNode* node = create_ast_node(AST_BLOCK_STMT, TYPE_VOID, NULL);
    node->child = statements;
    return node;
}

/* Free AST node and all its children */
void free_ast_node(ASTNode* node) {
    if (!node) return;
    
    free_ast_node(node->left);
    free_ast_node(node->right);
    free_ast_node(node->child);
    free_ast_node(node->next);
    
    if (node->value) {
        free(node->value);
    }
    free(node);
}

/* Print AST in text format */
void print_ast(ASTNode* node, int depth) {
    if (!node) return;
    
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    
    printf("%s", ast_node_type_to_string(node->type));
    if (node->value) {
        printf(": %s", node->value);
    }
    printf(" (%s)\n", data_type_to_string(node->data_type));
    
    print_ast(node->left, depth + 1);
    print_ast(node->right, depth + 1);
    print_ast(node->child, depth + 1);
    print_ast(node->next, depth + 1);
}

/* Print AST in JSON format for D3.js visualization */
void print_ast_json(ASTNode* node, FILE* file) {
    if (!node) {
        fprintf(file, "null");
        return;
    }
    
    fprintf(file, "{\n");
    fprintf(file, "  \"name\": \"%s", ast_node_type_to_string(node->type));
    if (node->value) {
        fprintf(file, " (%s)", node->value);
    }
    fprintf(file, "\",\n");
    fprintf(file, "  \"type\": \"%s\",\n", ast_node_type_to_string(node->type));
    fprintf(file, "  \"data_type\": \"%s\",\n", data_type_to_string(node->data_type));
    if (node->value) {
        fprintf(file, "  \"value\": \"%s\",\n", node->value);
    }
    
    fprintf(file, "  \"children\": [");
    
    int child_count = 0;
    if (node->left) {
        if (child_count > 0) fprintf(file, ",");
        fprintf(file, "\n    ");
        print_ast_json(node->left, file);
        child_count++;
    }
    if (node->right) {
        if (child_count > 0) fprintf(file, ",");
        fprintf(file, "\n    ");
        print_ast_json(node->right, file);
        child_count++;
    }
    if (node->child) {
        if (child_count > 0) fprintf(file, ",");
        fprintf(file, "\n    ");
        print_ast_json(node->child, file);
        child_count++;
    }
    if (node->next) {
        if (child_count > 0) fprintf(file, ",");
        fprintf(file, "\n    ");
        print_ast_json(node->next, file);
        child_count++;
    }
    
    if (child_count > 0) {
        fprintf(file, "\n  ");
    }
    fprintf(file, "]\n");
    fprintf(file, "}");
}

/* Generate code from AST */
void generate_code(ASTNode* node, FILE* file) {
    if (!node) return;
    
    switch (node->type) {
        case AST_PROGRAM:
            generate_code(node->child, file);
            break;
            
        case AST_FUNCTION_DEF:
            fprintf(file, "%s %s(", data_type_to_string(node->data_type), node->value);
            generate_code(node->child, file); // parameters
            fprintf(file, ") {\n");
            generate_code(node->right, file); // body
            fprintf(file, "}\n\n");
            break;
            
        case AST_VARIABLE_DECL:
            fprintf(file, "%s %s;\n", data_type_to_string(node->data_type), node->value);
            break;
            
        case AST_VARIABLE_DEF:
            fprintf(file, "%s %s = ", data_type_to_string(node->data_type), node->value);
            generate_code(node->left, file);
            fprintf(file, ";\n");
            break;
            
        case AST_RETURN_STMT:
            fprintf(file, "return ");
            generate_code(node->left, file);
            fprintf(file, ";\n");
            break;
            
        case AST_IF_STMT:
            fprintf(file, "if (");
            generate_code(node->left, file);
            fprintf(file, ") {\n");
            generate_code(node->right, file);
            fprintf(file, "}");
            if (node->child) {
                fprintf(file, " else {\n");
                generate_code(node->child, file);
                fprintf(file, "}");
            }
            fprintf(file, "\n");
            break;
            
        case AST_WHILE_STMT:
            fprintf(file, "while (");
            generate_code(node->left, file);
            fprintf(file, ") {\n");
            generate_code(node->right, file);
            fprintf(file, "}\n");
            break;
            
        case AST_FOR_STMT:
            fprintf(file, "for (");
            generate_code(node->left, file);
            fprintf(file, "; ");
            generate_code(node->right, file);
            fprintf(file, "; ");
            generate_code(node->child, file);
            fprintf(file, ") {\n");
            generate_code(node->next, file);
            fprintf(file, "}\n");
            break;
            
        case AST_BINARY_OP:
            generate_code(node->left, file);
            switch (node->type) {
                case AST_BINARY_OP:
                    fprintf(file, " + ");
                    break;
                default:
                    fprintf(file, " op ");
                    break;
            }
            generate_code(node->right, file);
            break;
            
        case AST_VARIABLE_REF:
            fprintf(file, "%s", node->value);
            break;
            
        case AST_INTEGER_LITERAL:
            fprintf(file, "%s", node->value);
            break;
            
        case AST_FLOAT_LITERAL:
            fprintf(file, "%s", node->value);
            break;
            
        case AST_STRING_LITERAL:
            fprintf(file, "%s", node->value);
            break;
            
        case AST_FUNCTION_CALL:
            fprintf(file, "%s(", node->value);
            generate_code(node->child, file);
            fprintf(file, ")");
            break;
            
        case AST_BLOCK_STMT:
            generate_code(node->child, file);
            break;
            
        default:
            generate_code(node->left, file);
            generate_code(node->right, file);
            generate_code(node->child, file);
            generate_code(node->next, file);
            break;
    }
}

/* Helper function to convert AST node type to string */
const char* ast_node_type_to_string(ASTNodeType type) {
    switch (type) {
        case AST_PROGRAM: return "PROGRAM";
        case AST_FUNCTION_DECL: return "FUNCTION_DECL";
        case AST_FUNCTION_DEF: return "FUNCTION_DEF";
        case AST_VARIABLE_DECL: return "VARIABLE_DECL";
        case AST_VARIABLE_DEF: return "VARIABLE_DEF";
        case AST_TYPE_SPECIFIER: return "TYPE_SPECIFIER";
        case AST_PARAMETER_LIST: return "PARAMETER_LIST";
        case AST_PARAMETER: return "PARAMETER";
        case AST_STATEMENT_LIST: return "STATEMENT_LIST";
        case AST_EXPRESSION_STMT: return "EXPRESSION_STMT";
        case AST_IF_STMT: return "IF_STMT";
        case AST_WHILE_STMT: return "WHILE_STMT";
        case AST_FOR_STMT: return "FOR_STMT";
        case AST_RETURN_STMT: return "RETURN_STMT";
        case AST_BREAK_STMT: return "BREAK_STMT";
        case AST_CONTINUE_STMT: return "CONTINUE_STMT";
        case AST_BLOCK_STMT: return "BLOCK_STMT";
        case AST_ASSIGNMENT: return "ASSIGNMENT";
        case AST_BINARY_OP: return "BINARY_OP";
        case AST_UNARY_OP: return "UNARY_OP";
        case AST_FUNCTION_CALL: return "FUNCTION_CALL";
        case AST_VARIABLE_REF: return "VARIABLE_REF";
        case AST_INTEGER_LITERAL: return "INTEGER_LITERAL";
        case AST_FLOAT_LITERAL: return "FLOAT_LITERAL";
        case AST_STRING_LITERAL: return "STRING_LITERAL";
        case AST_CHAR_LITERAL: return "CHAR_LITERAL";
        case AST_ARRAY_ACCESS: return "ARRAY_ACCESS";
        case AST_POINTER_DEREF: return "POINTER_DEREF";
        case AST_ADDRESS_OF: return "ADDRESS_OF";
        case AST_CAST: return "CAST";
        case AST_SIZEOF: return "SIZEOF";
        case AST_TERNARY_OP: return "TERNARY_OP";
        default: return "UNKNOWN";
    }
}

/* Helper function to convert data type to string */
const char* data_type_to_string(DataType type) {
    switch (type) {
        case TYPE_VOID: return "void";
        case TYPE_INT: return "int";
        case TYPE_FLOAT: return "float";
        case TYPE_DOUBLE: return "double";
        case TYPE_CHAR: return "char";
        case TYPE_POINTER: return "pointer";
        case TYPE_ARRAY: return "array";
        case TYPE_STRUCT: return "struct";
        case TYPE_UNION: return "union";
        default: return "unknown";
    }
}

/* Helper function to convert string to data type */
DataType string_to_data_type(const char* type_str) {
    if (strcmp(type_str, "int") == 0) return TYPE_INT;
    if (strcmp(type_str, "float") == 0) return TYPE_FLOAT;
    if (strcmp(type_str, "double") == 0) return TYPE_DOUBLE;
    if (strcmp(type_str, "char") == 0) return TYPE_CHAR;
    if (strcmp(type_str, "void") == 0) return TYPE_VOID;
    return TYPE_INT; // default
}
