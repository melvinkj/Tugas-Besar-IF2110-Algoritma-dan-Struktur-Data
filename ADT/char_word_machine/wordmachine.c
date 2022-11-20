/* File: wordmachine.c */
/* Implementasi Mesin Kata */

#include "wordmachine.h"
#include "charmachine.h"
#include <stdio.h>
#include "../sederhana/boolean.h"

// Init machinechar
//char currentChar;
// boolean EOP;

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
    if (currentChar == MARKCM)
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
    if (currentChar == MARKCM)
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
    while ((currentChar != MARKCM) && (currentChar != BLANK) && i < NMax)
    {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.Length = i;
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

void processWaitCommand(string wait_cmd ,int * extra_h, int * extra_m) {
    // wait_cmd valid
    int h = 0, m = 0, process_dum = 0;
    boolean counted_h = false;
    while (*wait_cmd.content != '\0') {
        if (!counted_h && *wait_cmd.content != ' ' && ((int) *wait_cmd.content) >= 48 && ((int) *wait_cmd.content) <= 57) {
            h *= 10;
            h += ((int) *wait_cmd.content) - 48;
            process_dum = 1;
        }
        if (*wait_cmd.content == ' ' && process_dum == 1){
            counted_h = true;
        }
        if (counted_h && *wait_cmd.content != ' ' && ((int) *wait_cmd.content) >= 48 && ((int) *wait_cmd.content) <= 57) {
            m *= 10;
            m += ((int) *wait_cmd.content) - 48;
        }
        *wait_cmd.content++;
    }
    *extra_h = h;
    *extra_m = m;
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
    string undo = { .content = "UNDO", .Length = 4 };
    string redo = { .content = "REDO", .Length = 4 };
    string catalog = { .content = "CATALOG", .Length = 7 };
    string cookbook = { .content = "COOKBOOK", .Length = 8 };
    string inventory = {.content = "INVENTORY", .Length = 9};
    string kulkas = { .content = "KULKAS", .Length = 6 };
    string wait_x_y = { .content = "WAIT", .Length = 4 };
    // For Wait x y Command
    if (hasSubstring(wait_x_y, input)) {
        int h = 0;
        int m = 0;
        int i = 4;
        boolean invalid = false;
        while (input.content[i] != '\0' && !invalid) {
            if (input.content[i] != ' ') {
                if (((int) input.content[i]) < 48 || ((int) input.content[i]) > 57){
                    invalid = true;
                }
            }
            i++;
        }
        
        if (invalid) {
            return "INVALID";
        } else {
            return "VALID";
        }

    }



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
    else if (cmpStrType2(input.content, inventory.content)) return "VALID";
    else if (cmpStrType2(input.content, kulkas.content)) return "VALID";
    else
    {
        return result = "INVALID";
    }
}