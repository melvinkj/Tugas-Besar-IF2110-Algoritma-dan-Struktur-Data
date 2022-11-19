#include "pemesanan.h"
#include "../ADT/list_statik/liststatik.h"
// #include "../ADT/char_word_machine/string.h"
// #include "../ADT/char_word_machine/"

void buy (Simulator *s, ListMakanan LM){
    int i = 0, nomor = 1, len, delivery;
    int id;
    char inputChar;
    boolean valid;
    string nama, aksi;
    char *buy = "Buy";
    ListStatik idContainer;
    Makanan makanan;
    CreateListStatik(&idContainer);

    printf("===================\n");
    printf("=       BUY       =\n");
    printf("===================\n");
    printf("List Bahan Makanan:\n");

    while (LM.arr[i].id != -9999)
    {
        int id = LM.arr[i].id;
        string nama = {.content = LM.arr[i].nama.content, .Length = LM.arr[i].nama.Length};
        TIME expiry_time = LM.arr[i].waktu_kedaluwarsa;
        TIME delivery_time = LM.arr[i].lama_pengiriman;
        string aksi = {.content = LM.arr[i].lokasi_aksi.content, .Length = LM.arr[i].lokasi_aksi.Length};

        if (cmpStrType2(aksi.content, buy))
        {
            printf("\t%d. %s (", nomor, nama.content);
            if (delivery_time.DD != 0)
            {
                printf("%d hari ", delivery_time.DD);
            }
            if (delivery_time.HH != 0)
            {
                if (delivery_time.MM != 0)
                {
                    printf("%d jam ", delivery_time.HH);
                }
                else
                {
                    printf("%d jam", delivery_time.HH);
                }
            }
            if (delivery_time.MM != 0)
            {
                    printf("%d menit", delivery_time.MM);
            }
            insertLast(&idContainer, id);
            nomor++;
            printf(")\n");
        }
        i++;
    }
    valid  = false;
    int c;
    string inputs;
    do {
        printf("Kirim 0 untuk exit.\n");
        printf("Enter Command: ");
        scanWord(&inputs);
        if (inputs.Length == 2){
            c = (((int) inputs.content[0])*10 + (int) inputs.content[1]) - 48;    
        } else {
            c = ((int) inputs.content[0]) - 48;
        }
        if(c>listLength(idContainer)){
            printf("Input tidak valid. Silakan ulangi.\n");
        } else {
            valid = true;
        }
    } while(valid==false);

    if(c!=0){
        id = ELMTLIST(idContainer,c-1);
        
        makanan = SearchById(id, LM);
        TIME deliveryMakanan = makanan.lama_pengiriman;
        string namaMakanan= {.content = makanan.nama.content, .Length = makanan.nama.Length};
        s->waktu = NextMenit(s->waktu);
        kurang_waktu_deliv(&Delivery(*s), &Inventory(*s));
        kurang_waktu_inv(&Inventory(*s));
        Enqueue_Delivery(&Delivery(*s), makanan);

        printf("Berhasil memesan %s. %s akan diantar dalam ", namaMakanan.content, namaMakanan.content);
        if (deliveryMakanan.DD != 0)
        {
            printf("%d hari ", deliveryMakanan.DD);
        }
        if (deliveryMakanan.HH != 0)
        {
            printf("%d jam ", deliveryMakanan.HH);
        }
        if (deliveryMakanan.MM != 0)
        {
            printf("%d menit", deliveryMakanan.MM);
        }
        printf(".\n");
    }
}