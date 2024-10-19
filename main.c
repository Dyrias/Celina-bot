#include "memory.h"
#include <string.h>
#include <stdio.h>

int checkChStr(char* str, char ch)
{
    for(int x = 0; str[x] != '\0'; x++)
        if(str[x] == ch)
            return 1;
    return 0;
}

enum Errors {
    WORDS_END,
    SUCESS
};

/**
 * Parser will parse each word in a char* of char**.
 * ( ,.)(a-z, A-Z)(-l)
 */
typedef struct Parser
{
    char jmp[WORD];
    char brk[WORD];
    char skip[WORD];
} Parser;

void init_parser(Parser* parser, char* jmp, char* brk, char* skip)
{
    memcpy(parser->jmp, jmp,  WORD);
    memcpy(parser->brk, brk, WORD);
    memcpy(parser->skip, skip, WORD);
}

int check_gram(char ch, char* str)
{
    int x = 0;
    
    for(; str[x] != ')'; x++)
    {
        if(ch == str[x])
            return 1;
    }
    return 0;
}

int parse_in_words(char* text, char** words, int length, Parser* rules)
{
    int ch;
    for(int x = 0, z = 0, y = 0; (ch = text[x]) != '\0'; x++)
    {
        if(check_gram(ch, rules->jmp))
            continue;
        else if(check_gram(ch, rules->brk))
        {
            words[y][z] = '\0';
            z++;
            y = 0;
        }
        else if(check_gram(ch, rules->skip))
            words[y][z++] = ch;
        else
            break;
    }
    return SUCESS;
}

int getLine(char* str, int length)
{
    int x = 0;
    int ch;
    while(x < length && (ch = getc(stdin)) != '\n' && ch != '\r')
        str[x++] = ch;
    str[x] = '\0';
    return x;
}

int main(int argc, char* argv[])
{
    char words[MEM_WORDS][WORD];
    char str[WORD*MEM_WORDS];

    Parser pText;
    initParser(&pText, "( ,.)", 
    
    while(getLine(str, WORD*MEM_WORDS))
    {
        fprintf(stdout, "%s\n", str);
    }
    return 0;
}
