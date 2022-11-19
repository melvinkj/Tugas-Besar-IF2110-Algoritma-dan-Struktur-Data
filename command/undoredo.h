#ifndef UNDOREDO_H
#define UNDOREDO_H

#include "../ADT/stack_queue/stack.h"
#include "../ADT/char_word_machine/charmachine.h"
#include "../ADT/list_statik_resep/liststatikresep.h"

/* **** UndoRedo adalah ADT yang menyimpan perintah-perintah yang telah dilakukan *** */

/* State Simulator */
extern Stack UndoStack;
extern Stack RedoStack;

/* *** konstruktor *** */
void CreateEmptyUndoRedo();


/* *** Operasi UndoRedo *** */

void addUndo(Simulator S);
/* Menambahkan state ke UndoStack */
/* I.S. undo bisa kosong dan S terdefinisi */
/* F.S. undo bertambah satu elemen */

void addRedo(Simulator S);
/* Menambahkan state ke RedoStack */
/* I.S. redo bisa kosong */
/* F.S. redo bertambah satu elemen */

boolean isUndoEmpty();
/* Mengembalikan true jika UndoStack kosong */
/* I.S. UndoStack terdefinisi */
/* F.S. UndoStack tidak berubah */

boolean isRedoEmpty();
/* Mengembalikan true jika RedoStack kosong */
/* I.S. RedoStack terdefinisi */
/* F.S. RedoStack tidak berubah */

boolean isUndoOneElmt();
/* Mengembalikan true jika UndoStack hanya berisi satu elemen */

boolean isRedoOneElmt();
/* Mengembalikan true jika RedoStack hanya berisi satu elemen */

boolean isUndoRedoEmpty();
/* Mengembalikan true jika UndoStack dan RedoStack kosong */
/* I.S. Semua stack terdefinisi */
/* F.S. Semua stack tidak berubah */

void undo(Simulator *S, ListStatikResep resep);
/* Mengembalikan state sebelumnya */
/* I.S. UndoStack tidak kosong */
/* F.S. UndoStack berkurang satu elemen, RedoStack bertambah satu elemen */

void redo(Simulator *S, ListStatikResep resep);
/* Mengembalikan state selanjutnya */
/* I.S. RedoStack tidak kosong */
/* F.S. RedoStack berkurang satu elemen, UndoStack bertambah satu elemen */

void printstackundo();
/* Menampilkan stack undo */


void notificationUndo(Simulator S, ListStatikResep resep);
void notificationRedo(Simulator S, ListStatikResep resep);
/* Menampilkan notifikasi perbandingan state sebelum dan sesudah */
/* I.S. Semua stack terdefinisi */
/* F.S. Semua stack tidak berubah */

#endif