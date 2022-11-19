/* File: wordmachine.h */
/* Definisi Word Machine: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../sederhana/boolean.h"
#include "charmachine.h"
#include "string.h"

#define NMax 50
#define BLANK ' '

typedef struct
{
    char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
    int Length;
} Word;


/* State Mesin Word */
extern boolean endWord;
extern Word currentWord;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void scanWord(string * input);
/* Menerima input dari stdin
   I.S. : input sembarang
   F.S. : input menjadi kata/commands yang diberikan */

void displayWord (Word word);
/* Menampilkan kata ke layar */

char * commandOptions(string input);
/* Menerima input dan memvalidasi (Valid jika ada di daftar commands dan sebaliknya) */

void processWaitCommand(string wait_cmd ,int * extra_h, int * extra_m);
/* Menerima input command wait x y
   I.S. : extra_h dan extra_m sembarang
   F.S. : extra_h terdefinisi menjadi x pada commands wait dan extra_m terdefinisi menjadi y pada commands wait */

#endif