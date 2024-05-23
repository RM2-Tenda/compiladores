TARGET:=main
CC:=gcc
CFLAGS:=-g -Wall -Wextra -Werror -std=c11 -Wpedantic -MD -MP -fsanitize=address -D_POSIX_C_SOURCE=200809L
LDLIBS:= -lm
SRC:=src
BIN:=bin
OBJ:=$(BIN)/obj
LIB:= utils
FLEX := flex
BISON := bison
TESTS:=tests

.DEFAULT_GOAL := help

# search subdirs for pattern
filesearch=	$(wildcard $1$2) $(foreach dir,$(wildcard $1*),$(call filesearch,$(dir)/,$2))

# check all subdirs for source files
SOURCES		:=	$(call filesearch,$(SRC),*.c)	
LIBSOURCES	:=	$(call filesearch,$(LIB),*.c)
LIBHEADERS	:=	$(call filesearch,$(LIB),*.h)

# remove main file					
SOURCES		:=	$(filter-out %$(TARGET).c, $(SOURCES))									
LIBSOURCES	:=	$(filter-out %test_io.c, $(LIBSOURCES))							

# build object list
OBJECTS:=	$(patsubst %.c, $(OBJ)/%.o, $(notdir $(SOURCES)))								
LIBOBJECTS:=	$(patsubst %.c, $(OBJ)/%.o, $(notdir $(LIBSOURCES)))						

# Create output directories
create_output_directories:
	$(shell mkdir -p $(BIN))
	$(shell mkdir -p $(OBJ))

all: objects calc build ## Builds the project (compiles everything), the calculator, and tests it

build: objects $(TARGET) calc ## Builds the project (compiles everything) and the calculator
$(OBJ)/%.o: $(SRC)/%.c
	$(CC) -c $(CFLAGS) -I$(dir $(LIBHEADERS)) $^ -o $@

$(TARGET): $(SRC)/$(TARGET).c $(OBJECTS) $(LIBOBJECTS) $(SRC)/calc.tab.c $(SRC)/lex.yy.c
	@printf "\033[32m[i] Generating binary\033[0m\n"
	$(CC) $(CFLAGS) -I$(dir $(LIBHEADERS)) $< $(OBJECTS) $(LIBOBJECTS) $(SRC)/calc.tab.c $(SRC)/lex.yy.c $(LDLIBS) -o $(BIN)/$@

objects: create_output_directories
	@printf "\033[32m[i] Compiling library\033[0m\n"
$(OBJ)/%.o: $(LIB)/%.c
	$(CC) -c $(CFLAGS) -I$(dir $(LIBHEADERS)) $^ -o $@

$(SRC)/calc.tab.c $(SRC)/calc.tab.h: src/calc.yacc
	$(BISON) -d -o $(SRC)/calc.tab.c src/calc.yacc
  
calc: src/calc.lex src/calc.yacc src/main.c $(LIB)/variables.c
	$(BISON) -d -o $(SRC)/calc.tab.c src/calc.yacc #-Wcounterexamples
	$(FLEX) -o $(SRC)/lex.yy.c $(SRC)/calc.lex
	$(CC) $(CFLAGS) -I$(dir $(LIBHEADERS)) -o $(BIN)/$@ $(SRC)/main.c $(SRC)/calc.tab.c $(SRC)/lex.yy.c $(LIB)/variables.c $(LDLIBS)

tests: objects calc build
	$(CC) $(CFLAGS) -I$(SRC) -o $(BIN)/test_runner $(TESTS)/test_runner.c $(SRC)/calc.tab.c $(SRC)/lex.yy.c $(LIB)/variables.c $(LDLIBS)
	$(BIN)/test_runner

clean: ## Deletes the build folder and generated files
	@printf "\033[33m[i] Deleting build folder: $(BIN)\033[0m\n"
	rm -rf $(BIN)
	@printf "\033[33m[i] Deleting generated files\033[0m\n"
	rm -f $(SRC)/calc.tab.c $(SRC)/calc.tab.h $(SRC)/lex.yy.c

run: clean objects build ## Cleans, builds and runs the program
	./$(BIN)/$(TARGET)


.PHONY: help
help: ## Display this help message
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[32m%-20s\033[0m %s\n", $$1, $$2}'