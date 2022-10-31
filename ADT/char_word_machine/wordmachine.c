/* File: wordmachine.c */
/* Implementasi Mesin Kata */

#include "wordmachine.h"
#include "charmachine.h"
#include <stdio.h>
#include "../sederhana/boolean.h"

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
    // IgnoreBlanks();
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
}

void displayWord(Word word)
{
    for (int i = 0; i < word.Length; i++)
    {
        printf("%c", word.TabWord[i]);
    }
}

void scanWord(string * input)
{
    string new_str;
    createString(&new_str);

    STARTWORD();
    while (!endWord)
    {
        for (int i = 0; i < currentWord.Length; i++){
            new_str = appendCCtoStr(new_str, currentWord.TabWord[i]);
        }
        new_str = appendCCtoStr(new_str, ' ');
        ADVWORD();
    }
    new_str.content[new_str.Length-1] = '\0';
    new_str.Length--;
    *input = new_str;
}

void clearTabWord (Word * word){
    for (int i = 0; i < word->Length; i++) {
        word->TabWord[i] = '\0';
    }
    word->Length = 0;
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

char * commandOptions(string input)
{
    char * result;
    // All Available Commands
    string start = { .content = "START", .Length = 5 };
    string exit = { .content = "EXIT", .Length = 4 };
    string buy = { .content = "BUY", .Length = 3 };
    string fry = { .content = "FRY", .Length = 3 };
    string delivery = { .content = "DELIVERY", .Length = 8 };
    string move_north = { .content = "MOVE NORTH", .Length = 10 };
    string move_east = { .content = "MOVE EAST", .Length = 9 };
    string move_west = { .content = "MOVE WEST", .Length = 9 };
    string move_south = { .content = "MOVE SOUTH", .Length = 10 };
    string mix = { .content = "MIX", .Length = 3 };
    string chop = { .content = "CHOP", .Length = 4 };
    string boil = { .content = "BOIL", .Length = 4 };
    // string wait_x_y = { .content = "WAIT x y", .Length = 8 };
    string undo = { .content = "UNDO", .Length = 4 };
    string redo = { .content = "REDO", .Length = 4 };
    string catalog = { .content = "CATALOG", .Length = 7 };
    string cookbook = { .content = "COOKBOOK", .Length = 8 };


    if (cmpStrType2(input.content, start.content)) return "VALID";
    else if (cmpStrType2(input.content, exit.content)) return "VALID";
    else if (cmpStrType2(input.content, buy.content)) return "VALID";
    else if (cmpStrType2(input.content, fry.content)) return "VALID";
    else if (cmpStrType2(input.content, delivery.content)) return "VALID";
    else if (cmpStrType2(input.content, move_north.content)) return "VALID";
    else if (cmpStrType2(input.content, move_east.content)) return "VALID";
    else if (cmpStrType2(input.content, move_west.content)) return "VALID";
    else if (cmpStrType2(input.content, move_south.content)) return "VALID";
    else if (cmpStrType2(input.content, mix.content)) return "VALID";
    else if (cmpStrType2(input.content, chop.content)) return "VALID";
    else if (cmpStrType2(input.content, boil.content)) return "VALID";
    else if (cmpStrType2(input.content, undo.content)) return "VALID";
    else if (cmpStrType2(input.content, redo.content)) return "VALID";
    else if (cmpStrType2(input.content, catalog.content)) return "VALID";
    else if (cmpStrType2(input.content, cookbook.content)) return "VALID";
    else
    {
        return result = "INVALID";
    }
}