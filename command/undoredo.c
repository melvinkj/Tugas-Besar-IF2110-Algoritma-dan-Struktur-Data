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

boolean isUndoOneElmt(){
    Simulator temp;
    Pop(&UndoStack, &temp);
    if (IsStackEmpty(UndoStack)){
        Push(&UndoStack, temp);
        return true;
    } else {
        Push(&UndoStack, temp);
        return false;
    }
}

boolean isRedoOneElmt(){
    Simulator temp;
    Pop(&RedoStack, &temp);
    if (IsStackEmpty(RedoStack)){
        Push(&RedoStack, temp);
        return true;
    } else {
        Push(&RedoStack, temp);
        return false;
    }
}

void undo(Simulator *S){
    if(!isUndoOneElmt()){
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

void notification(Simulator S, ListResep resep){
 Simulator sekarang,sebelum;
 createSimulator(&sekarang);
 createSimulator(&sebelum);
 copySimulator(&sekarang,S);
 copySimulator(&sebelum,InfoTop(UndoStack));

 /* *** Cek Delivery **** */
 if(NBElmt(sekarang.delivery) > NBElmt(sebelum.delivery)){
    tidakjadibeli(sebelum.delivery,sekarang.delivery);
    /* delivery sekarang lebih besar, setelah melakukan buy */
    /* cari elemen yang tidak jadi dibeli */
}else if (NBElmt(sekarang.delivery) < NBElmt(sebelum.delivery)){
    kembalikedelivery(sebelum.delivery,sekarang.delivery);
    /* delivery sekarang lebih kecil, waktu habis berpindah ke inventory */
    /* cari elemen yang tidak jadi dimasukan ke inventory */
    }
/* cek inventory */
 if(NBElmt(sekarang.inventory) < NBElmt(sebelum.inventory)){
    // tidakjadipengolahan(sebelum.inventory,sekarang.inventory,resep);
    kembalikeinventory(sebelum.inventory,sekarang.inventory);
    /* inventory sekarang lebih kecil, setelah melakukan pengolahan atau expired */
    /* cari elemen yang tidak jadi diolah atau expired */
    /* *** abstraksi *** */
    /* cari elemen di inventory sekarang dengan lokasi dan child yang ada di inventory sebelum */
    /* remove elemen di inventory sebelum yang merupakan child dari elemen inventory sekarang*/
    /* elemen yang tersisa di inventory sebelum adalah elemen yang expired jika tidak ada di elemen inventroy sekarang */

 }else if (NBElmt(sekarang.inventory) == NBElmt(sekarang.delivery)){
    // tidakjadipengolahan(sebelum.inventory,sekarang.inventory,resep);
    /* inventory sekarang sama dengan delivery sekarang, tidak ada perubahan atau elemen melakukan pengolahan */
    /* cari elemen yang tidak jadi diolah */
    /* *** abstraksi *** */
    /* cari elemen di inventory sekarang dengan lokasi dan child yang ada di inventory sebelum */
    /* remove elemen di inventory sebelum yang merupakan child dari elemen inventory sekarang*/

}

}