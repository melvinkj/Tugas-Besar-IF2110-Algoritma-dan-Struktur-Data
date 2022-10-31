#include "undoredo.h"

Stack UndoStack;
Stack RedoStack;

void CreateEmptyUndoRedo(){
    CreateEmpty(&UndoStack);
    CreateEmpty(&RedoStack);
}

void addUndo(infotype S){
    Push(&UndoStack, S);
}

void addRedo(infotype S){
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
    infotype X;
    Pop(&UndoStack, &X);
    addRedo(X);
    return InfoTop(UndoStack);
}

Simulator redo(){
    infotype X;
    Pop(&RedoStack, &X);
    addUndo(X);
    return InfoTop(RedoStack);
}
    