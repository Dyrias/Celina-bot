#ifndef MEMORY_H
#define MEMORY_H

#define WORD 		32
#define MEM_WORDS 	32
#define CONTEXT_WORDS 	3

typedef struct word
{
	char str[WORD];
	int flag;
} Word;

typedef struct words_Memory
{
	Word mem_words[CONTEXT_WORDS];
} Mem_Words;

typedef struct Memory
{
	Mem_Words str_words[MEM_WORDS];
	Word UserName;
} Memory;

enum Word_Flags
{
	Work,
	Play
};

#endif
