/* File: wordmachine.c */
/* Implementasi Mesin Kata */

#include "wordmachine.h"
#include "charmachine.h"
#include "boolean.h"
#include <stdio.h>

// Init machinechar
char currentChar;
boolean EOP;

// Init machineword
boolean endWord;
Word currentWord;

void IgnoreBlanks()
{
    while (currentChar == BLANK)
    {
        ADV();
    }
}

void STARTWORD()
{
    START();
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
    }
}

void ADVWORD()
{
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord()
{
    int i = 0;
    while ((currentChar != MARK) && (currentChar != BLANK) && i < NMax)
    {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.Length = i;
}

void LowerCase()
{
    int i;
    for (i = 0; i < currentWord.Length; i++)
    {
        if (currentWord.TabWord[i] <= 90 && currentWord.TabWord[i] >= 65)
        {
            currentWord.TabWord[i] = currentWord.TabWord[i] + 32;
        }
    }
}

void concatWord(Word *new_word, Word word)
{
    int i = 0;
    while (i < word.Length)
    {
        new_word->TabWord[i + new_word->Length] = word.TabWord[i];
        i++;
    }
    new_word->Length += word.Length;
    // new_word->TabWord[new_word->Length] = cc;
}

void displayWord(Word word)
{
    for (int i = 0; i < word.Length; i++)
    {
        printf("%c", word.TabWord[i]);
    }
}

void scanWord(Word *command, char * args)
{
    command->Length = 0;
    printf(args);
    STARTWORD();
    while (!endWord)
    {
        int i;
        concatWord(command, currentWord);
        ADVWORD();
    }
    // displayWord(*command);
}

boolean IsWordSame(Word word_1, Word word_2)
{
    boolean same = true;
    if (word_1.Length != word_2.Length)
    {
        return !same;
    }
    else
    {
        int i = 0;
        while (i < word_1.Length && same)
        {
            if (word_1.TabWord[i] != word_2.TabWord[i])
            {
                same = false;
            }
            i++;
        }
        return same;
    }
}

boolean cmpWord(Word word, string commands)
{
    if (word.Length != commands.Length)
    {
        return false;
    }
    else
    {
        int i = 0;
        boolean same = true;
        while (i < commands.Length)
        {
            if (word.TabWord[i] != commands.content[i])
            {
                same = false;
            }
            i++;
        }
        return same;
    }
}

char * commandOptions(Word word)
{
    char * result;
    // All Available Commands
    string start = { .content = "START", .Length = 5 };
    string exit = { .content = "EXIT", .Length = 4 };
    string buy = { .content = "BUY", .Length = 3 };
    string fry = { .content = "FRY", .Length = 3 };
    string delivery = { .content = "DELIVERY", .Length = 8 };
    string move_north = { .content = "MOVENORTH", .Length = 9 };
    string move_east = { .content = "MOVEEAST", .Length = 8 };
    string move_west = { .content = "MOVEWEST", .Length = 8 };
    string move_south = { .content = "MOVESOUTH", .Length = 9 };
    string mix = { .content = "MIX", .Length = 3 };
    string chop = { .content = "CHOP", .Length = 4 };
    string boil = { .content = "BOIL", .Length = 4 };
    string wait_x_y = { .content = "WAITxy", .Length = 6 };
    string undo = { .content = "UNDO", .Length = 4 };
    string redo = { .content = "REDO", .Length = 4 };
    string catalog = { .content = "CATALOG", .Length = 7 };
    string cookbook = { .content = "COOKBOOK", .Length = 8 };


    if (cmpWord(word, start)) return result = "START";
    else if (cmpWord(word, exit)) return result = "EXIT";
    else if (cmpWord(word, buy)) return result = "BUY";
    else if (cmpWord(word, fry)) return result = "FRY";
    else if (cmpWord(word, delivery)) return result = "DELIVERY";
    else if (cmpWord(word, move_north)) return result = "MOVE NORTH";
    else if (cmpWord(word, move_east)) return result = "MOVE EAST";
    else if (cmpWord(word, move_west)) return result = "MOVE WEST";
    else if (cmpWord(word, move_south)) return result = "MOVE SOUTH";
    else if (cmpWord(word, mix)) return result = "MIX";
    else if (cmpWord(word, chop)) return result = "CHOP";
    else if (cmpWord(word, boil)) return result = "BOIL";
    else if (cmpWord(word, wait_x_y)) return result = "WAIT x y";
    else if (cmpWord(word, undo)) return result = "UNDO";
    else if (cmpWord(word, redo)) return result = "REDO";
    else if (cmpWord(word, catalog)) return result = "CATALOG";
    else if (cmpWord(word, cookbook)) return result = "COOKBOOK";
    else
    {
        return result = "INVALID COMMAND";
    }
}