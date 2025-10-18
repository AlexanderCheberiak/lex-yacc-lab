%{
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "ast.h"
#include "parser.tab.h"

extern YYSTYPE yylval;
extern char* yytext;
extern int yylineno;

%}

%option yylineno
%option noyywrap

%%
"auto"           { return AUTO; }
"break"          { return BREAK; }
"case"           { return CASE; }
"char"           { return CHAR; }
"const"          { return CONST; }
"continue"       { return CONTINUE; }
"default"        { return DEFAULT; }
"do"             { return DO; }
"double"         { return DOUBLE; }
"else"           { return ELSE; }
"enum"           { return ENUM; }
"extern"         { return EXTERN; }
"float"          { return FLOAT; }
"for"            { return FOR; }
"goto"           { return GOTO; }
"if"             { return IF; }
"int"            { return INT; }
"long"           { return LONG; }
"register"       { return REGISTER; }
"return"         { return RETURN; }
"short"          { return SHORT; }
"signed"         { return SIGNED; }
"sizeof"         { return SIZEOF; }
"static"         { return STATIC; }
"struct"         { return STRUCT; }
"switch"         { return SWITCH; }
"typedef"        { return TYPEDEF; }
"union"          { return UNION; }
"unsigned"       { return UNSIGNED; }
"void"           { return VOID; }
"volatile"       { return VOLATILE; }
"while"          { return WHILE; }
"+"              { return PLUS; }
"-"              { return MINUS; }
"*"              { return MULTIPLY; }
"/"              { return DIVIDE; }
"%"              { return MODULO; }
"="              { return ASSIGN; }
"=="             { return EQUAL; }
"!="             { return NOT_EQUAL; }
"<"              { return LESS; }
"<="             { return LESS_EQUAL; }
">"              { return GREATER; }
">="             { return GREATER_EQUAL; }
"&&"             { return AND; }
"||"             { return OR; }
"!"              { return NOT; }
"&"              { return BITWISE_AND; }
"|"              { return BITWISE_OR; }
"^"              { return BITWISE_XOR; }
"~"              { return BITWISE_NOT; }
"<<"             { return LEFT_SHIFT; }
">>"             { return RIGHT_SHIFT; }
"++"             { return INCREMENT; }
"--"             { return DECREMENT; }
"+="             { return PLUS_ASSIGN; }
"-="             { return MINUS_ASSIGN; }
"*="             { return MULTIPLY_ASSIGN; }
"/="             { return DIVIDE_ASSIGN; }
"%="             { return MODULO_ASSIGN; }
"&="             { return AND_ASSIGN; }
"|="             { return OR_ASSIGN; }
"^="             { return XOR_ASSIGN; }
"<<="            { return LEFT_SHIFT_ASSIGN; }
">>="            { return RIGHT_SHIFT_ASSIGN; }
"("              { return LPAREN; }
")"              { return RPAREN; }
"{"              { return LBRACE; }
"}"              { return RBRACE; }
"["              { return LBRACKET; }
"]"              { return RBRACKET; }
";"              { return SEMICOLON; }
","              { return COMMA; }
"."              { return DOT; }
"->"             { return ARROW; }
"?"              { return QUESTION; }
":"              { return COLON; }
[0-9]+           { yylval.int_val = atoi(yytext); return INTEGER_LITERAL; }
[0-9]*\.[0-9]+   { yylval.string_val = malloc(strlen(yytext) + 1); strcpy(yylval.string_val, yytext); return FLOAT_LITERAL; }
[a-zA-Z_][a-zA-Z0-9_]* { 
    yylval.string_val = malloc(strlen(yytext) + 1);
    strcpy(yylval.string_val, yytext);
    return IDENTIFIER; 
}
\"([^"\\]|\\.)*\" { 
    yylval.string_val = malloc(strlen(yytext) + 1);
    strcpy(yylval.string_val, yytext);
    return STRING_LITERAL; 
}
'([^'\\]|\\.)'   { 
    yylval.string_val = malloc(strlen(yytext) + 1);
    strcpy(yylval.string_val, yytext);
    return CHAR_LITERAL; 
}
"//".*           { /* Single line comment - ignore */ }
"/*"([^*]|\*+[^*/])*\*+"/" { /* Multi-line comment - ignore */ }
[ \t\r\n]+       { /* Ignore whitespace */ }
.                { 
    printf("Lexical error: unexpected character '%c' at line %d\n", yytext[0], yylineno);
    return yytext[0]; 
}

%%
