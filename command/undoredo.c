#include "undoredo.h"
#include "inventory_delivery.h"
#include <stdio.h>
#include <stdlib.h>

Stack UndoStack;
Stack RedoStack;

void CreateEmptyUndoRedo(){
    CreateEmpty(&UndoStack);
    CreateEmpty(&RedoStack);
}

void addUndo(Simulator S){
    Push(&UndoStack, S);
}

void addRedo(Simulator S){
    Push(&RedoStack, S);
}

boolean isUndoEmpty(){
    return IsStackEmpty(UndoStack);
}

boolean isRedoEmpty(){
    return IsStackEmpty(RedoStack);
}

boolean isUndoRedoEmpty(){
    return isUndoEmpty() && isRedoEmpty();
}

void undo(Simulator *S){
    if(!isUndoEmpty()){
        Simulator temp;
        Pop(&UndoStack, &temp);
        Push(&RedoStack, temp);
        *S = InfoTop(UndoStack);
    }else{
        printf("Undo tidak bisa dilakukan karena tidak ada perintah yang bisa diundo\n");
    }
}

void printstackundo(){
    printstack(UndoStack);
}

void redo(Simulator *S){
    if(!isRedoEmpty()){
        Simulator temp;
        Pop(&RedoStack, &temp);
        Push(&UndoStack, temp);
        *S = InfoTop(UndoStack);
    }else{
        printf("Redo tidak bisa dilakukan karena tidak ada perintah yang bisa diredo\n");
    }
}

void notification(Simulator S){
 Simulator sekarang,sebelum;
 createSimulator(&sekarang);
 createSimulator(&sebelum);
 copySimulator(&sekarang,S);
 copySimulator(&sebelum,InfoTop(UndoStack));

 /* *** Cek Delivery **** */
 if(NBElmt(sekarang.delivery) > NBElmt(sebelum.delivery)){

     /* delivery sekarang lebih besar, setelah melakukan buy */
     /* cari elemen yang tidak jadi dibeli */

    }else if (NBElmt(sekarang.delivery) < NBElmt(sebelum.delivery)){
        
        /* delivery sekarang lebih kecil, waktu habis berpindah ke inventory */
        /* cari elemen yang tidak jadi dimasukan ke inventory */

    }

/* cek inventory */
if(NBElmt(sekarang.inventory) < NBElmt(sebelum.inventory)){

    /* inventory sekarang lebih kecil, setelah melakukan pengolahan atau expired */
    /* cari elemen yang tidak jadi diolah atau expired */
    /* *** abstraksi *** */
    /* cari elemen di inventory sekarang dengan lokasi dan child yang ada di inventory sebelum */
    /* remove elemen di inventory sebelum yang merupakan child dari elemen inventory sekarang*/
    /* elemen yang tersisa di inventory sebelum adalah elemen yang expired jika tidak ada di elemen inventroy sekarang */

}else if (NBElmt(sekarang.inventory) == NBElmt(sekarang.delivery)){

    /* inventory sekarang sama dengan delivery sekarang, tidak ada perubahan atau elemen melakukan pengolahan */
    /* cari elemen yang tidak jadi diolah */
    /* *** abstraksi *** */
    /* cari elemen di inventory sekarang dengan lokasi dan child yang ada di inventory sebelum */
    /* remove elemen di inventory sebelum yang merupakan child dari elemen inventory sekarang*/

}

