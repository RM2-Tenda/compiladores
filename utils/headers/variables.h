#ifndef VARIABLES_H
#define VARIABLES_H

typedef struct Variable {
    char *name;
    double value;
    int is_int;
} Variable;

Variable *find_variable(char *name);
void assign_variable(char *name, double value, int is_int);
void get_variable_value(char *name, double *value, int *type);
int is_variable_int(char *name);
void increment_variable(const char *name);
void decrement_variable(const char *name);
void clear_variable(char *name);
void clear_all_variables();
void list_variable(char *name);
void print_variable(const char *name);
void list_all_variables();
double get_float_variable(char *name);
int get_integer_variable(char *name);
int get_variable_type(char *name);
int variable_exists(const char *name);
Variable *get_variables();
#endif