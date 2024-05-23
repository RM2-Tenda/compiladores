# Compiladores: Calculadora

## Descrição do Projeto
Este projeto é um interpretador de expressões matemáticas - Calculadora - desenvolvido para a disciplina de Compiladores. Suporta operações aritméticas básicas, bit shifts, funções trigonometricas e manipulação de variáveis.

## Estrutura do Projeto

```
src/  
  ├── calc.yacc  
  ├── calc.lex  
  ├── main.c  
tests/  
  ├── test_runner.c  
utils/  
  ├── headers/variables.h  
  ├── variables.c 
```

## Compilar, Testar e Utilizar
### Compilar
Para compilar o projeto, utilize o comando:
```bash
make all
```
    
## Testar
Para garantir que o programa corra corretamente e para evitar a introdução de erros com o aumento de funcionalidades, são feitos uma bateria de testes, incluíndo 23 testes de precedência. Para os correr, execute:
```bash
make tests
```

## Utilizar
Após a compilação, execute o interpretador com o comando:
```bash
./bin/main
```

## Funcionalidades
- Operações Aritméticas: `Adição`, `subtração`, `multiplicação`, `divisão`, `módulo` e `exponenciação`.
- Operações de Bits: `AND`, `OR`, `XOR`, `left shift` e `right shift`.
- Funções Matemáticas: `Seno`, `cosseno`, `tangente`, `logaritmo` e `logaritmo natural`.
- Manipulação de Variáveis: `Atribuição`, `incremento`, `decremento`, `listagem` e `limpeza de variáveis`.

## Regras de Precedência
As regras de precedência seguem a convenção matemática padrão:
1. Exponenciação: `**`
2. Operações Unárias: `+`, `-`, `~`
3. Multiplicação, Divisão e Módulo: `*`, `/`, `%`
4. Adição e Subtração: `+`, `-`
5. Deslocamento de Bits: `<<`, `>>`
6. Operações de Bits: `&`, `^`, `|`
7. Atribuição: `=`


## Tratamento de Erros e Sugestões
O interpretador inclui funcionalidades avançadas de tratamento de erros e sugestões para correção de sintaxe. Quando um erro é detectado, o interpretador fornece mensagens detalhadas e sugestões para corrigir o erro. Por exemplo:
- Erro de Variável Não Definida: Sugere variáveis com nomes semelhantes.
- Erro de Divisão por Zero: Informa que a divisão por zero não é permitida.
- Erro de Sintaxe: Sugere correções de parênteses, operadores ou operandos ausentes.