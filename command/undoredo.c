#include "undoredo.h"

Stack UndoStack;
Stack RedoStack;

void CreateEmptyUndoRedo(){
    CreateEmpty(&UndoStack);
    CreateEmpty(&RedoStack);
}

void addUndo(InfoType S){
    Push(&UndoStack, S);
}

void addRedo(InfoType S){
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

Simulator undo(){
    InfoType X;
    Pop(&UndoStack, &X);
    addRedo(X);
    return InfoTop(UndoStack);
}

Simulator redo(){
    InfoType X;
    Pop(&RedoStack, &X);
    addUndo(X);
    return InfoTop(RedoStack);
}
    