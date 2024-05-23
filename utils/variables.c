#include "headers/variables.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Variable *variables = NULL;
int num_variables = 0;

void assign_variable(char *name, double value, int is_int) {
    Variable *v = find_variable(name);
    if (v == NULL) {
        variables = realloc(variables, (num_variables + 1) * sizeof(Variable));
        if (variables == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        v = &variables[num_variables++];
        v->name = strdup(name);
        if (v->name == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
    }
    v->value = value;
    v->is_int = !is_int;
}

void get_variable_value(char *name, double *value, int *type) {
    Variable *v = find_variable(name);
    if (v == NULL) {
        *value = 0.0;
        *type = 0;
    } else {
        *value = v->value;
        *type = v->is_int ? 0 : 1;
    }
}

int get_variable_type(char *name) {
    Variable *v = find_variable(name);
    if (v == NULL) {
        // fprintf(stderr, "Variable %s not found\n", name);
        return 0;
    }
    return v->is_int ? 0 : 1;
}

int is_variable_int(char *name) {
    Variable *v = find_variable(name);
    if (v == NULL) {
        return 0;
    }
    return v->is_int;
}

void increment_variable(const char *name) {
    for (int i = 0; i < num_variables; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            variables[i].value++;
            return;
        }
    }
}

void decrement_variable(const char *name) {
    for (int i = 0; i < num_variables; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            variables[i].value--;
            return;
        }
    }
}

void clear_variable(char *name) {
    for (int i = 0; i < num_variables; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            free(variables[i].name);
            variables[i] = variables[--num_variables];
            return;
        }
    }
}

void clear_all_variables() {
    for (int i = 0; i < num_variables; i++) {
        free(variables[i].name);
    }
    free(variables);
    variables = NULL;
    num_variables = 0;
}

void list_variable(char *name) {
    Variable *v = find_variable(name);
    if (v == NULL) {
        fprintf(stderr, "Variable %s not found\n", name);
        return;
    }
    if (v->is_int) {
        printf("%s (int) = %d\n", v->name, (int)v->value);
    } else {
        printf("%s (float) = %lf\n", v->name, v->value);
    }
}

void print_variable(const char *name) {
    for (int i = 0; i < num_variables; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            if (variables[i].is_int) {
                printf("%d\n", (int)variables[i].value);
            } else {
                printf("%f\n", variables[i].value);
            }
            return;
        }
    }
    printf("Variable %s not found\n", name);
}

int variable_exists(const char *name) {
    for (int i = 0; i < num_variables; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            return 1;
        }
    }
    return 0;
}

void list_all_variables() {
    for (int i = 0; i < num_variables; i++) {
        if (variables[i].is_int) {
            printf("%s (int) = %d\n", variables[i].name,
                   (int)variables[i].value);
        } else {
            printf("%s (float) = %lf\n", variables[i].name, variables[i].value);
        }
    }
}

Variable *find_variable(char *name) {
    for (int i = 0; i < num_variables; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            return &variables[i];
        }
    }
    return NULL;
}

double get_float_variable(char *name) {
    Variable *v = find_variable(name);
    if (v == NULL) {
        return 0.0;
    }
    return v->value;
}

int get_integer_variable(char *name) {
    Variable *v = find_variable(name);
    if (v == NULL) {
        return 0;
    }
    return (int)v->value;
}

Variable *get_variables() { return variables; }