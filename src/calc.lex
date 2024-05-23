%{
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include "calc.tab.h"
#include "../utils/headers/variables.h"

extern int yylineno;
extern char *yytext;
char *current_line = NULL;
int line_number = 1;
int column_number = 1;

void update_location(const char *text) {
    const char *p;
    for (p = text; *p; p++) {
        if (*p == '\n') {
            line_number++;
            column_number = 1;
        } else {
            column_number++;
        }
    }
}

void append_to_current_line(const char *text) {
    if (current_line == NULL) {
        current_line = strdup(text);
    } else {
        current_line = realloc(current_line, strlen(current_line) + strlen(text) + 1);
        strcat(current_line, text);
    }
    update_location(text);
}

%}

%option nounput
%option noinput

%%

"PI"                                { yylval.fval = M_PI; append_to_current_line(yytext); return PI; }
"sin"                               { append_to_current_line(yytext); return SIN; }
"cos"                               { append_to_current_line(yytext); return COS; }
"tan"                               { append_to_current_line(yytext); return TAN; }
"log"                               { append_to_current_line(yytext); return LOG; }
"ln"                                { append_to_current_line(yytext); return LN; }
[0-9]+\.[0-9]*([eE][+-]?[0-9]+)?    { yylval.fval = atof(yytext); append_to_current_line(yytext); return FLOAT; }
[0-9]+                              { yylval.ival = atoi(yytext); append_to_current_line(yytext); return INTEGER; }
[a-zA-Z_][a-zA-Z0-9_]*              { yylval.id = strdup(yytext); if (yylval.id == NULL) { fprintf(stderr, "Memory allocation failed\n"); exit(1); } append_to_current_line(yytext); return ID; }
"+"                                 { append_to_current_line(yytext); return PLUS; }
"-"                                 { append_to_current_line(yytext); return MINUS; }
"*"                                 { append_to_current_line(yytext); return TIMES; }
"/"                                 { append_to_current_line(yytext); return DIVIDE; }
"%"                                 { append_to_current_line(yytext); return MOD; }
"**"                                { append_to_current_line(yytext); return POWER; }
"&"                                 { append_to_current_line(yytext); return AND; }
"|"                                 { append_to_current_line(yytext); return OR; }
"^"                                 { append_to_current_line(yytext); return XOR; }
">>"                                { append_to_current_line(yytext); return RSHIFT; }
"<<"                                { append_to_current_line(yytext); return LSHIFT; }
"~"                                 { append_to_current_line(yytext); return NOT; }
"++"                                { append_to_current_line(yytext); return INC; }
"--"                                { append_to_current_line(yytext); return DEC; }
"="                                 { append_to_current_line(yytext); return ASSIGN; }
"("                                 { append_to_current_line(yytext); return LPAREN; }
")"                                 { append_to_current_line(yytext); return RPAREN; }
"@CLEAR"                            { append_to_current_line(yytext); return CLEAR; }
"@LIST"                             { append_to_current_line(yytext); return LIST; }
[ \t]                               { append_to_current_line(yytext); }
\n                                  { if (current_line) { free(current_line); current_line = NULL; } update_location(yytext); return '\n'; }
.                                   { append_to_current_line(yytext); return yytext[0]; }

%%

int yywrap() { return 1; }