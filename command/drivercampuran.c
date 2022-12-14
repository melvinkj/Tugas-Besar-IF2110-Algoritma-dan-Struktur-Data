// DRIVER INI UNTUK BEBERAPA ADT DAN FUNGSI : makanan, liststatikresep, listmakanan 



#include <stdio.h>
#include "pengolahan.h"
// gcc tespengolahan.c pengolahan.c ../ADT/tree/tree.c ../ADT/sederhana/makanan.c ../ADT/sederhana/simulator.c ../ADT/stack_queue/prioqueue.c ../ADT/list_statik_resep/liststatikresep.c ../ADT/listdin/listdin.c ../ADT/list_statik/liststatik.c ../ADT/matrix/matrix.c ../ADT/char_word_machine/string.c ../ADT/sederhana/waktu.c ../ADT/sederhana/point.c -o a
int main(){
    // buat time t misalnya 1 jam
    TIME t;
    CreateTime(&t,0,1,0);

    // buat string ayam, sambel, ayam sambel, minyak, ayam goreng
    string s_ayam,s_sambel,s_ayam_sambel,s_minyak,s_ayam_goreng;
    createString(&s_ayam);
    createString(&s_sambel);
    createString(&s_ayam_sambel);
    createString(&s_minyak);
    createString(&s_ayam_goreng);
    s_ayam.content = "ayam";
    s_sambel.content = "sambel";
    s_ayam_sambel.content = "ayam sambel";
    s_minyak.content = "minyak";
    s_ayam_goreng.content = "ayam goreng";

    string T, M, F;
    createString(&T);
    createString(&M);
    createString(&F);
    T.content = "T";
    M.content = "MIX";
    F.content = "FRY";

    // buat makanan, misalnya ayam, sambel, ayam sambel, minyak, ayam goreng
    Makanan m_ayam,m_sambel,m_ayam_sambel,m_minyak,m_ayam_goreng,parse;
    m_ayam = CreateMakanan(101, s_ayam, t, T, t, 2, 2);
    m_sambel = CreateMakanan(102, s_sambel, t, T, t, 1, 1);
    m_ayam_sambel = CreateMakanan(201, s_ayam_sambel, t, M, t, 2, 2);
    m_minyak = CreateMakanan(103, s_minyak, t, T, t, 1, 1);
    m_ayam_goreng = CreateMakanan(202, s_ayam_goreng, t, F, t, 2, 2);
    parse = CreateMakanan(-9999,s_ayam_goreng, t, F, t, 2, 2);

    // buat list makanan
    ListMakanan lm = {m_ayam,m_sambel,m_ayam_sambel,m_minyak,m_ayam_goreng,parse};

    // buat resep
    tree ayam_sambel, ayam_goreng;
    createTree(&ayam_sambel);
    createTree(&ayam_goreng);
    
    insertFirstNode(&ayam_sambel, ID_MAKANAN(m_ayam_sambel));
    insertChild(&ayam_sambel, ID_MAKANAN(m_ayam));
    insertChild(&ayam_sambel, ID_MAKANAN(m_sambel));

    insertFirstNode(&ayam_goreng, ID_MAKANAN(m_ayam_goreng));
    insertChild(&ayam_goreng, ID_MAKANAN(m_ayam));
    insertChild(&ayam_goreng, ID_MAKANAN(m_minyak));
    
    // buat list resep misalnya masukkan ayam sambel dan ayam goreng
    ListStatikResep lr;
    CreateListStatikResep(&lr);
    insertLastResep(&lr, ayam_sambel);
    insertLastResep(&lr, ayam_goreng);

    int ID;
    for (int i = 0; i < listLengthResep(lr); i++){
        printTreeFin(ELMTR(lr,i));
    }
    printf("\n");

    // buat simulator
    Simulator s;
    createSimulator(&s);

    // isi inventory
    Enqueue(&Inventory(s), m_ayam);
    Enqueue(&Inventory(s), m_sambel);

    // fry(&s, lr, lm);
    
    return 0;
}