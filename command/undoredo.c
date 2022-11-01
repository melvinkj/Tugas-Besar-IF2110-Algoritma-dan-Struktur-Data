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

    