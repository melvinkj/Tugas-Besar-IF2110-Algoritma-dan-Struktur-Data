#include "undoredo.h"

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

void notification(Simulator s1, Simulator s2){
    
}