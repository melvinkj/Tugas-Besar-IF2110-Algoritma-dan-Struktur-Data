#include <stdio.h>
#include "../list_statik_resep/liststatikresep.h"
#include "../char_word_machine/charmachine.h"

// int isIn(ListStatikResep lr, int ID);

int locRes(ListStatikResep lr, int ID);
AddressTree addrInRes(ListStatikResep lr, int ID);
void toStatikResep(ListStatikResep *lr, ListResep ld);