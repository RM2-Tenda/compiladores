%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include "../utils/headers/variables.h"

int yylex();

void yyerror(char *s);

extern int yylineno;

Variable *get_variables();

extern int num_variables;

extern int line_number;

extern int column_number;

extern char *current_line;

extern char *yytext;

void print_error(const char *error_type, const char *error_msg);
int list_similar_variables(const char *line);
void suggest_syntax_corrections(const char *line);
int levenshtein_distance(const char *s1, const char *s2);
int is_valid_identifier(const char *name);

%}

%union {
    struct {
        double value;
        int type; // 0 for int, 1 for float
    } expr_val;
    double fval;
    int ival;
    char *id;
}

%token <fval> FLOAT
%token <ival> INTEGER
%token <id> ID
%token PLUS MINUS TIMES DIVIDE MOD POWER AND OR XOR
%token RSHIFT LSHIFT NOT INC DEC ASSIGN LPAREN RPAREN
%token CLEAR LIST
%token SIN COS TAN LOG LN PI

%left OR
%left XOR
%left AND
%left EQUALS NOTEQUALS
%left PLUS MINUS
%left LT LTE GT GTE
%left TIMES DIVIDE MOD
%right NOT UMINUS
%right INC DEC 
%right POWER

%type <expr_val> expr
%type <expr_val> term
%type <expr_val> factor
%type <expr_val> unary

%locations

%%

program:
    /* empty */
    | program line
    ;

line:
    '\n'                          /* empty line */
    | expr '\n'                   {
                                    if (!yyerrstatus) {
                                        if ($1.type == 0) {
                                            printf("%d\n", (int)$1.value);
                                        } else {
                                            printf("%f\n", $1.value);
                                        }
                                    }
                                  }
    | ID ASSIGN expr '\n'         {
                                    if (!is_valid_identifier($1)) {
                                        print_error("Invalid Identifier", "Identifier cannot start with a digit or contain special characters");
                                        YYERROR;
                                    } else {
                                        if ($3.type == -1) {
                                            // An error occurred in the expression
                                            YYERROR;
                                        } else {
                                            assign_variable($1, $3.value, $3.type);
                                            if ($3.type == 0) {
                                                printf("%d\n", (int)$3.value);
                                            } else {
                                                printf("%f\n", $3.value);
                                            }
                                        }
                                        free($1);
                                    }
                                }
    | ID INC '\n'                 {
                                    if (variable_exists($1)) {
                                        increment_variable($1);
                                        if (!yyerrstatus) {
                                            print_variable($1);
                                        }
                                    } else {
                                        print_error("Undefined Variable", "Variable not found");
                                        YYERROR;
                                    }
                                    free($1);
                                  }
    | ID DEC '\n'                 {
                                    if (variable_exists($1)) {
                                        decrement_variable($1);
                                        if (!yyerrstatus) {
                                            print_variable($1);
                                        }
                                    } else {
                                        print_error("Undefined Variable", "Variable not found");
                                        YYERROR;
                                    }
                                    free($1);
                                  }
    | ID '\n'                     {
                                    if (variable_exists($1)) {
                                        print_variable($1);
                                    } else {
                                        print_error("Undefined Variable", "Variable not found");
                                        YYERROR;
                                    }
                                    free($1);
                                  }
    | CLEAR '\n'                  {
                                    clear_all_variables();
                                    printf("All variables cleared\n");
                                  }
    | CLEAR ID '\n'               {
                                    if (variable_exists($2)) {
                                        clear_variable($2);
                                        printf("Variable %s cleared\n", $2);
                                    } else {
                                        print_error("Undefined Variable", "Variable not found");
                                        YYERROR;
                                    }
                                    free($2);
                                  }
    | LIST '\n'                   {
                                    list_all_variables();
                                  }
    | LIST ID '\n'                {
                                    if (variable_exists($2)) {
                                        list_variable($2);
                                    } else {
                                        print_error("Undefined Variable", "Variable not found");
                                        YYERROR;
                                    }
                                    free($2);
                                  }
    | error '\n'                  {
                                    if (current_line != NULL) {
                                        free(current_line);
                                    }
                                    current_line = strdup(yytext);
                                    yyerrok;
                                    yyclearin;
                                  }
    ;

expr:
    term                          { $$ = $1; }
    | expr RSHIFT term            {
                                    if ($1.type == -1 || $3.type == -1) {
                                        $$.type = -1;
                                    } else {
                                        $$.value = (int)$1.value >> (int)$3.value;
                                        $$.type = 0;
                                    }
                                  }
    | expr LSHIFT term            {
                                    if ($1.type == -1 || $3.type == -1) {
                                        $$.type = -1;
                                    } else {
                                        $$.value = (int)$1.value << (int)$3.value;
                                        $$.type = 0;
                                    }
                                  }

    | expr MOD term               {
                                    if ($1.type == -1 || $3.type == -1) {
                                        $$.type = -1;
                                    } else if ($3.value == 0) {
                                        print_error("Modulo Error", "Cannot perform modulo operation with zero");
                                        $$.type = -1;
                                    } else {
                                        $$.value = fmod($1.value, $3.value);
                                        $$.type = ($1.type || $3.type);
                                    }
                                  }
    | expr OR term                {
                                    if ($1.type == -1 || $3.type == -1) {
                                        $$.type = -1;
                                    } else {
                                        $$.value = (int)$1.value | (int)$3.value;
                                        $$.type = 0;
                                    }
                                  }
    | expr AND expr               {
                                    if ($1.type == -1 || $3.type == -1) {
                                        $$.type = -1;
                                    } else {
                                        $$.value = (int)$1.value & (int)$3.value;
                                        $$.type = 0;
                                    }
                                  }
    | expr XOR term               {
                                    if ($1.type == -1 || $3.type == -1) {
                                        $$.type = -1;
                                    } else {
                                        $$.value = (int)$1.value ^ (int)$3.value;
                                        $$.type = 0;
                                    }
                                  }
    ;

term:
    factor                        { $$ = $1; }
    
    | term PLUS factor              {
                                    if ($1.type == -1 || $3.type == -1) {
                                        $$.type = -1;
                                    } else {
                                        $$.value = $1.value + $3.value;
                                        $$.type = ($1.type || $3.type);
                                    }
                                  }
    | term MINUS factor             {
                                    if ($1.type == -1 || $3.type == -1) {
                                        $$.type = -1;
                                    } else {
                                        $$.value = $1.value - $3.value;
                                        $$.type = ($1.type || $3.type);
                                    }
                                  }
    | term MOD factor             {
                                    if ($1.type == -1 || $3.type == -1) {
                                        $$.type = -1;
                                    } else if ($3.value == 0) {
                                        print_error("Modulo Error", "Cannot perform modulo operation with zero");
                                        $$.type = -1;
                                    } else {
                                        $$.value = fmod($1.value, $3.value);
                                        $$.type = ($1.type || $3.type);
                                    }
                                  }
    ;

factor:
    INTEGER                       { $$.value = $1; $$.type = 0; }
    | FLOAT                       { $$.value = $1; $$.type = 1; }
    | ID                          {
                                    if (variable_exists($1)) {
                                        get_variable_value($1, &$$.value, &$$.type);
                                    } else {
                                        print_error("Undefined Variable", "Variable not found");
                                        $$.type = -1;
                                    }
                                    free($1);
                                  }
    | LPAREN expr RPAREN          { $$ = $2; }
    | unary                       { $$ = $1; }
    | factor TIMES factor             {
                                    if ($1.type == -1 || $3.type == -1) {
                                        $$.type = -1;
                                    } else {
                                        $$.value = $1.value * $3.value;
                                        $$.type = ($1.type || $3.type);
                                    }
                                  }
    | factor DIVIDE factor            {
                                    if ($1.type == -1 || $3.type == -1) {
                                        $$.type = -1;
                                    } else if ($3.value == 0) {
                                        print_error("Division Error", "Cannot divide by zero");
                                        $$.type = -1;
                                    } else {
                                        $$.value = $1.value / $3.value;
                                        $$.type = ($1.type || $3.type);
                                    }
                                  }
    | factor POWER factor             {
                                    if ($1.type == -1 || $3.type == -1) {
                                        $$.type = -1;
                                    } else {
                                        $$.value = pow($1.value, $3.value);
                                        $$.type = (fmod($$.value, 1.0) == 0.0 && $1.type == 0 && $3.type == 0) ? 0 : 1;
                                    }
                                  }
    ;

unary:
    MINUS factor %prec UMINUS     { $$.value = -$2.value; $$.type = $2.type; }
    | NOT factor                  { $$.value = ~(int)$2.value; $$.type = 0; }
    | INC ID                      {
                                    if (variable_exists($2)) {
                                        increment_variable($2);
                                        get_variable_value($2, &$$.value, &$$.type);
                                    } else {
                                        print_error("Undefined Variable", "Variable not found");
                                        YYERROR;
                                    }
                                    free($2);
                                  }
    | DEC ID                      {
                                    if (variable_exists($2)) {
                                        decrement_variable($2);
                                        get_variable_value($2, &$$.value, &$$.type);
                                    } else {
                                        print_error("Undefined Variable", "Variable not found");
                                        YYERROR;
                                    }
                                    free($2);
                                  }
    | SIN LPAREN expr RPAREN      { $$.value = sin($3.value); $$.type = 1; }
    | COS LPAREN expr RPAREN      { $$.value = cos($3.value); $$.type = 1; }
    | TAN LPAREN expr RPAREN      {
                                    if (cos($3.value) == 0) {
                                        print_error("Tangent Error", "Tangent is undefined for this input");
                                        // YYERROR;
                                    } else {
                                        $$.value = tan($3.value); $$.type = 1;
                                    }
                                  }
    | LOG LPAREN expr RPAREN      {
                                    if ($3.type == -1) {
                                        //YYERROR;
                                    } else {
                                        if ($3.value <= 0) {
                                            print_error("Logarithm Error", "Logarithm is undefined for non-positive input");
                                            //YYERROR;
                                        } else {
                                            $$.value = log10($3.value); $$.type = 1;
                                        }
                                    }
                                  }
    | LOG LPAREN error RPAREN     {
                                    print_error("Syntax Error", "Invalid argument for logarithm function");
                                    fprintf(stderr, "Hint: Provide a valid numeric argument for the logarithm function\n");
                                    //YYERROR;
                                  }
    | LOG LPAREN expr error       {
                                    print_error("Syntax Error", "Missing closing parenthesis for logarithm function");
                                    fprintf(stderr, "Hint: Add the missing closing parenthesis\n");
                                    fprintf(stderr, "Suggestion: Add ')' after the argument\n");
                                    //YYERROR;
                                  }
    | LN LPAREN expr RPAREN       {
                                    if ($3.value <= 0) {
                                        print_error("Natural Logarithm Error", "Natural logarithm is undefined for non-positive input");
                                        // YYERROR;
                                    } else {
                                        $$.value = log($3.value); $$.type = 1;
                                    }
                                  }
    | PI                          { $$.value = M_PI; $$.type = 1; }
    ;

%%

void yyerror(char *s) {
    fprintf(stderr, "Error at line %d, column %d: %s\n", line_number, column_number, s);
    if (current_line) {
        fprintf(stderr, "  --> %s\n", current_line);
        int error_pos = column_number - 1;
        fprintf(stderr, "     ");
        for (int i = 0; i < error_pos; i++) {
            if (current_line[i] == '\t') {
                fprintf(stderr, "\t");
            } else {
                fprintf(stderr, " ");
            }
        }
        fprintf(stderr, "^\n");
        suggest_syntax_corrections(current_line);
    } else {
        fprintf(stderr, "  --> Line not available\n");
    }
    // Set the type to -1 to indicate an error
    yylval.expr_val.type = -1;
}

void print_error(const char *error_type, const char *error_msg) {
    fprintf(stderr, "Error at line %d, column %d: %s\n", line_number, column_number, error_type);
    fprintf(stderr, "%s\n", error_msg);

    if (current_line != NULL) {
        fprintf(stderr, "  --> %s\n", current_line);
        int error_pos = column_number - 1;
        fprintf(stderr, "     ");
        for (int i = 0; i < error_pos; i++) {
            if (current_line[i] == '\t') {
                fprintf(stderr, "\t");
            } else {
                fprintf(stderr, " ");
            }
        }
        fprintf(stderr, "^\n");
    }

    yylval.expr_val.type = -1;

    // Provide suggestions based on error type
    if (strcmp(error_type, "Undefined Variable") == 0) {
        fprintf(stderr, "Hint: Check if the variable is declared or if there is a typo in the variable name.\n");
        if (current_line != NULL) {
            list_similar_variables(current_line);
        }
    } else if (strcmp(error_type, "Division Error") == 0) {
        fprintf(stderr, "Hint: Ensure the divisor is not zero to avoid division by zero errors.\n");
    } else if (strcmp(error_type, "Syntax Error") == 0) {
        fprintf(stderr, "Hint: Check for missing parentheses, operators, or operands.\n");
        if (current_line != NULL) {
            suggest_syntax_corrections(current_line);
        }
    } else if (strcmp(error_type, "Invalid Identifier") == 0) {
        fprintf(stderr, "Hint: Identifiers must start with a letter or underscore and can only contain letters, digits, and underscores.\n");
    }
}

int list_similar_variables(const char *line) {
    if (line == NULL) {
        return 0;
    }

    char *token = strtok(strdup(line), " \t\n");
    Variable *variables = get_variables();
    if (variables == NULL) {
        return 0;
    }

    int min_distance = INT_MAX;
    char *closest_var = NULL;
    while (token != NULL) {
        if (is_valid_identifier(token) && !variable_exists(token)) {
            for (int i = 0; i < num_variables; i++) {
                if (variables[i].name != NULL) {
                    int distance = levenshtein_distance(token, variables[i].name);
                    if (distance < min_distance) {
                        min_distance = distance;
                        if (closest_var != NULL) {
                            free(closest_var);
                        }
                        closest_var = strdup(variables[i].name);
                    }
                }
            }
        }
        token = strtok(NULL, " \t\n");
    }

    if (closest_var != NULL) {
        fprintf(stderr, "Did you mean '%s'?\n", closest_var);
        free(closest_var);
        return 1;
    }
    return 0;
}

void suggest_syntax_corrections(const char *line) {
    if (line == NULL) {
        return;
    }

    // Check for missing parentheses
    int left_paren_count = 0;
    int right_paren_count = 0;
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '(') {
            left_paren_count++;
        } else if (line[i] == ')') {
            right_paren_count++;
        }
    }
    if (left_paren_count > right_paren_count) {
        fprintf(stderr, "Hint: It seems like you are missing a closing parenthesis ')'\n");
        fprintf(stderr, "Suggestion: %s", line);
        for (int i = 0; i < left_paren_count - right_paren_count; i++) {
            fprintf(stderr, ")");
        }
        fprintf(stderr, "\n");
    } else if (right_paren_count > left_paren_count) {
        fprintf(stderr, "Hint: It seems like you have an extra closing parenthesis ')'\n");
        fprintf(stderr, "Suggestion: Check the parentheses in your expression\n");
    }

    // Check for missing operators
    char *token = strtok(strdup(line), " \t\n");
    while (token != NULL) {
        if (is_valid_identifier(token) || isdigit(token[0])) {
            char *next_token = strtok(NULL, " \t\n");
            if (next_token != NULL && (is_valid_identifier(next_token) || isdigit(next_token[0]))) {
                fprintf(stderr, "Hint: It seems like you are missing an operator between '%s' and '%s'\n", token, next_token);
            }
        }
        token = strtok(NULL, " \t\n");
    }

    // Check for invalid function calls
    if (strstr(line, "log(") != NULL || strstr(line, "ln(") != NULL) {
        if (strstr(line, "log(#") != NULL || strstr(line, "ln(#") != NULL) {
            fprintf(stderr, "Hint: Invalid argument for logarithm function\n");
            fprintf(stderr, "Suggestion: Provide a valid numeric argument for the logarithm function\n");
        }
    }

    // Check for missing semicolons
    if (line[strlen(line) - 1] != ';') {
        fprintf(stderr, "Hint: It seems like you are missing a semicolon ';' at the end of the statement\n");
        fprintf(stderr, "Suggestion: Add a semicolon at the end of the statement\n");
    }

    // Check for missing quotes
    int single_quote_count = 0;
    int double_quote_count = 0;
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '\'') {
            single_quote_count++;
        } else if (line[i] == '\"') {
            double_quote_count++;
        }
    }
    if (single_quote_count % 2 != 0) {
        fprintf(stderr, "Hint: It seems like you are missing a closing single quote '\n");
        fprintf(stderr, "Suggestion: Add the missing single quote to complete the character literal\n");
    }
    if (double_quote_count % 2 != 0) {
        fprintf(stderr, "Hint: It seems like you are missing a closing double quote \"\n");
        fprintf(stderr, "Suggestion: Add the missing double quote to complete the string literal\n");
    }
}



int levenshtein_distance(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int matrix[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                int delete_cost = matrix[i - 1][j] + 1;
                int insert_cost = matrix[i][j - 1] + 1;
                int substitute_cost = matrix[i - 1][j - 1] + 1;
                matrix[i][j] = fmin(fmin(delete_cost, insert_cost), substitute_cost);
            }
        }
    }

    return matrix[len1][len2];
}

int is_valid_identifier(const char *name) {
    if (name == NULL || strlen(name) == 0) {
        return 0;
    }

    // Check if the first character is a letter or underscore
    if (!isalpha(name[0]) && name[0] != '_') {
        return 0;
    }

    // Check if the remaining characters are letters, digits, or underscores
    for (int i = 1; name[i] != '\0'; i++) {
        if (!isalnum(name[i]) && name[i] != '_') {
            return 0;
        }
    }

    return 1;
}