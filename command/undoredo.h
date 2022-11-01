#ifndef UNDOREDO_H
#define UNDOREDO_H

#include "../ADT/stack_queue/stack.h"

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

boolean isUndoRedoEmpty();
/* Mengembalikan true jika UndoStack dan RedoStack kosong */
/* I.S. Semua stack terdefinisi */
/* F.S. Semua stack tidak berubah */

void undo(Simulator S*);
/* Mengembalikan state sebelumnya */
/* I.S. UndoStack tidak kosong */
/* F.S. State sebelumnya dipanggil */
/*      State sebelumnya dimasukkan ke RedoStack */

void redo(Simulator S*);
/* Mengembalikan state selanjutnya */
/* I.S. RedoStack tidak kosong */
/* F.S. State selanjutnya dipanggil */
/*      State selanjutnya dimasukkan ke UndoStack */

#endif