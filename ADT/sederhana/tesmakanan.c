#include <stdio.h>
#include "makanan.h"
#include "../sederhana/waktu.h"
#include "../char_word_machine/string.h"

// gcc tesmakanan.c makanan.c ../sederhana/waktu.c ../char_word_machine/string.c

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

    Makanan m_ayam,m_sambel,m_ayam_sambel,m_minyak,m_ayam_goreng;
    m_ayam = CreateMakanan(101, s_ayam, t, T, t, 2, 2);
    m_sambel = CreateMakanan(102, s_sambel, t, T, t, 1, 1);
    m_ayam_sambel = CreateMakanan(201, s_ayam_sambel, t, M, t, 2, 2);
    m_minyak = CreateMakanan(103, s_minyak, t, T, t, 1, 1);
    m_ayam_goreng = CreateMakanan(202, s_ayam_goreng, t, F, t, 2, 2);

    // buat list makanan
    ListMakanan lm = {m_ayam,m_sambel,m_ayam_sambel,m_minyak,m_ayam_goreng};

    printf("%s\n", NAMA_MAKANAN(SearchById(202, lm)).content);

    return 0;
}