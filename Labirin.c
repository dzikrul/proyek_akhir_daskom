#include <stdio.h>
#include <windows.h>
#include <time.h>

int main(){
    /*
    PROGRAM PERMAINAN LABIRIN SEDERHANA, DIKEMBANGKAN OLEH -Dzikrul Insanul Kamila- DAN -Fajriawan Sutansa- UNTUK PROYEK
    AKHIR DASAR KOMPUTER TAHUN 2018.
    Program ini tidak memakai larik ("array") ataupun modular didalamnya.

    Berikut keterangan dari program ini:
    pil_utama = untuk memilih pilihan yang tersedia pada menu utama
    pil_tingkat = untuk memilih pilihan yang tersedia pada menu tingkat
    tingkatx = penanda bahwa tingkat x sudah selesai atau belum (1 untuk ya, 0 untuk belum)
    sal_utama = variabel apakah masukan yang dipilih salah pada menu utama
    sal_tingkat = variabel apakah masukan yang dipilih salah pada menu tingkatan
    a1 - i15 = peta labirin (koordinat)
    xa1 -xi15 = jejak di labirin
    salah_t1 = penanda bahwa pemain menabrak dinding
    gerak = variabel untuk pergerakan tokoh
    selesai = variabel bahwa dia menyelesaikan tingkat
    ke_menu = variabel konfirmasi untuk keluar saat bermain
    langkah = variabel melangkah saat tingkat 3
    tulisan = variabel omongan saat tingkat 3
    waktu_mulai = waktu yang diambil saat masuk tingkatan (awal permainan)
    waktu_akhir = waktu yang diambil saat telah menyelesaikan permainan
    selisih_waktu = waktu_akhir - waktu awal, berapa waktu yang diselesaikan pemain untuk meyelesaikan tingkatan
    penambah_waktu = variabel khusus tingkat 3 karena waktu permainan terpotong oleh pembicaraan
    waktu_x = waktu tercepat untuk menyelesaikan tingkatan ke-x
    ambil_waktu = variabel untuk menentukan apakah waktu akan perhitungkan atau tidak (jika menabrak dinding atau mati waktu dabaikan)

    */
    int tingkat1, tingkat2, tingkat3, sal_utama, sal_tingkat, selesai, salah_t1, langkah, tulisan, ambil_waktu;
    double selisih_waktu, waktu_1, waktu_2, waktu_3, penambah_waktu;
    time_t waktu_mulai, waktu_selesai;

    char a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15;
    char b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15;
    char c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15;
    char d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15;
    char e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15;
    char f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15;
    char g1, g2, g3, g4, g5, g6, g7, g8, g9, g10, g11, g12, g13, g14, g15;
    char h1, h2, h3, h4, h5, h6, h7, h8, h9, h10, h11, h12, h13, h14, h15;
    char i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15;
    char gerak, ke_menu, pil_tingkat, pil_utama;

    //Nilai awal
    tingkat1 = 0;
    tingkat2 = 0;
    tingkat3 = 0;
    sal_utama = 0;
    sal_tingkat = 0;
    waktu_1 = 0;
    waktu_2 = 0;
    waktu_3 = 0;
    ambil_waktu = 0;

    //Menu Utama
    do{

        //Judul
        printf("===========\n");
        printf(" LABIRIN C\n");
        printf("===========\n\n");

        //Keterangan
        printf("Sebuah permainan menyelesaikan berbagai labirin.\nSiapkah anda menyelesaikan labirin ini?\n\n");

        //Menu
        printf("\t[1] Mulai\n\t[2] Bantuan\n\t[3] Waktu Tercepat\n\t[4] Keluar\n");

        //Pemberitahuan masukan salah
        if(sal_utama == 1){
            printf("\nMasukan salah! Mohon diulangi!\n");
            sal_utama = 0;
        }
        else{
            printf("\n\n");
        }

        //Pilih pilihan
        printf("Masukkan pilihan: "); pil_utama = getch();

        //Proses dari menu utama
        switch(pil_utama){
            case '1': //Mulai
                do{
                    system("cls");

                    //Judul
                    printf("===========\n");
                    printf(" LABIRIN C\n");
                    printf("===========\n\n");

                    //Menu tingkat kesulitan
                    printf("Tingkat Kesulitan\n\t[1] Tingkat 1\n");
                    if(tingkat1 == 1){
                        printf("\t[2] Tingkat 2\n");
                    }
                    if(tingkat2 == 1){
                        printf("\t[3] Tingkat 3\n");
                    }
                    if(tingkat3 == 1){
                        printf("\t[4] Tingkat 4\n");
                    }
                    printf("\t[0] Menu utama\n");

                    //Pemberitahuan salah masukan
                    if(sal_tingkat == 1){
                        printf("\nMasukan salah! Mohon diulangi!\n");
                        sal_tingkat = 0;
                    }
                    else{
                        printf("\n\n");
                    }

                    //Pilih tingkat kesulitan
                    printf("Pilih tingkat kesulitan: "); pil_tingkat = getch();

                    //Proses pilihan tingkat
                    switch(pil_tingkat){
                        case '1':
                            system("cls");

                            //Peta
                            a1='='; a2='='; a3='='; a4='='; a5='='; a6='='; a7='='; a8='='; a9='='; a10='='; a11='='; a12='='; a13='='; a14='='; //a15;
                            b1='|'; b2=' '; b3=' '; b4=' '; b5=' '; b6=' '; b7=' '; b8=' '; b9=' '; b10=' '; b11=' '; b12=' '; b13=' '; b14='|'; //b15;
                            c1='|'; c2=' '; c3='='; c4='='; c5='='; c6='='; c7='='; c8='='; c9='='; c10='='; c11='='; c12='='; c13=' '; c14='|'; //c15;
                            d1='|'; d2=' '; d3=' '; d4=' '; d5='|'; d6=' '; d7=' '; d8=' '; d9=' '; d10=' '; d11=' '; d12=' '; d13=' '; d14='|'; //d15;
                            e1='|'; e2='='; e3='='; e4=' '; e5='|'; e6='='; e7='='; e8=' '; e9='='; e10='='; e11='='; e12='='; e13='='; e14='|'; //e15;
                            f1=' '; f2=' '; f3='|'; f4=' '; f5=' '; f6=' '; f7='|'; f8=' '; f9='|'; f10=' '; f11=' '; f12=' '; f13=' '; f14=' '; //f15;
                            g1='|'; g2=' '; g3='|'; g4='='; g5='='; g6=' '; g7='|'; g8=' '; g9='|'; g10='='; g11='='; g12='|'; g13=' '; g14='|'; //g15;
                            h1='|'; h2=' '; h3=' '; h4=' '; h5=' '; h6=' '; h7='|'; h8=' '; h9=' '; h10=' '; h11=' '; h12=' '; h13=' '; h14='|'; //h15;
                            i1='|'; i2='='; i3='='; i4='='; i5='='; i6='='; i7='|'; i8='='; i9='='; i10='='; i11='='; i12='='; i13='='; i14='|'; //i15;

                            //Nilai awal
                            gerak = '\0'; selesai = 0; salah_t1 = 0;

                            //Ambil waktu awal
                            time(&waktu_mulai);

                            //Memberi posisi
                            f14 = 'H';

                            do{

                                //Pergerakan
                                if(b2 == 'H'){                     //keadaan b
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            a2 = 'H'; b2 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            b1 = 'H'; b2 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            c2 = 'H'; b2 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            b3 = 'H'; b2 = ' ';
                                            break;
                                    }
                                }
                                else if(b3 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            a3 = 'H'; b3 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            b2 = 'H'; b3 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            c3 = 'H'; b3 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            b4 = 'H'; b3 = ' ';
                                            break;
                                    }
                                }
                                else if(b4 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            a4 = 'H'; b4 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            b3 = 'H'; b4 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            c4 = 'H'; b4 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            b5 = 'H'; b4 = ' ';
                                            break;
                                    }
                                }
                                else if(b5 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            a5 = 'H'; b5 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            b4 = 'H'; b5 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            c5 = 'H'; b5 = ' ';
                                        break;
                                        case 'D':
                                        case 'd':
                                            b6 = 'H'; b5 = ' ';
                                            break;
                                    }
                                }
                                else if(b6 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            a6 = 'H'; b6 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            b5 = 'H'; b6 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            c6 = 'H'; b6 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            b7 = 'H'; b6 = ' ';
                                            break;
                                    }
                                }
                                else if(b7 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            a7 = 'H'; b7 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            b6 = 'H'; b7 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            c7 = 'H'; b7 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            b8 = 'H'; b7 = ' ';
                                            break;
                                    }
                                }
                                else if(b8 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            a8 = 'H'; b8 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            b7 = 'H'; b8 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            c8 = 'H'; b8 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            b9 = 'H'; b8 = ' ';
                                            break;
                                    }
                                }
                                else if(b9 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            a9 = 'H'; b9 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            b8 = 'H'; b9 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            c9 = 'H'; b9 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            b10 = 'H'; b9 = ' ';
                                            break;
                                    }
                                }
                                else if(b10 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            a10 = 'H'; b10 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            b9 = 'H'; b10 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            c10 = 'H'; b10 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            b11 = 'H'; b10 = ' ';
                                            break;
                                    }
                                }
                                else if(b11 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            a11 = 'H'; b11 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            b10 = 'H'; b11 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            c11 = 'H'; b11 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            b12 = 'H'; b11 = ' ';
                                            break;
                                    }
                                }
                                else if(b12 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            a12 = 'H'; b12 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            b11 = 'H'; b12 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            c12 = 'H'; b12 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            b13 = 'H'; b12 = ' ';
                                            break;
                                    }
                                }
                                else if(b13 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            a13 = 'H'; b13 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            b12 = 'H'; b13 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            c13 = 'H'; b13 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            b14 = 'H'; b13 = ' ';
                                            break;
                                    }
                                }
                                else if(c2 == 'H'){                                          //keadaan c
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            b2 = 'H'; c2 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            c1 = 'H'; c2 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            d2 = 'H'; c2 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            c3 = 'H'; c2 = ' ';
                                            break;
                                    }
                                }
                                else if(c13 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            b13 = 'H'; c13 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            c12 = 'H'; c13 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            d13 = 'H'; c13 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            c14 = 'H'; c13 = ' ';
                                            break;
                                    }
                                }
                                else if(d2 == 'H'){                                             //keadaan d
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            c2 = 'H'; d2 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            d1 = 'H'; d2 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            e2 = 'H'; d2 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            d3 = 'H'; d2 = ' ';
                                            break;
                                    }
                                }
                                else if(d3 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            c3 = 'H'; d3 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            d2 = 'H'; d3 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            e3 = 'H'; d3 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            d4 = 'H'; d3 = ' ';
                                            break;
                                    }
                                }
                                else if(d4 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            c4 = 'H'; d4 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            d3 = 'H'; d4 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            e4 = 'H'; d4 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            d5 = 'H'; d4 = ' ';
                                            break;
                                    }
                                }
                                else if(d6 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            c6 = 'H'; d6 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            d5 = 'H'; d6 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            e6 = 'H'; d6 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            d7 = 'H'; d6 = ' ';
                                            break;
                                    }
                                }
                                else if(d7 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            c7 = 'H'; d7 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            d6 = 'H'; d7 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            e7 = 'H'; d7 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            d8 = 'H'; d7 = ' ';
                                            break;
                                    }
                                }
                                else if(d8 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            c8 = 'H'; d8 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            d7 = 'H'; d8 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            e8 = 'H'; d8 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            d9 = 'H'; d8 = ' ';
                                            break;
                                    }
                                }
                                else if(d9 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            c9 = 'H'; d9 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            d8 = 'H'; d9 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            e9 = 'H'; d9 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            d10 = 'H'; d9 = ' ';
                                            break;
                                    }
                                }
                                else if(d10 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            c10 = 'H'; d10 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            d9 = 'H'; d10 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            e10 = 'H'; d10 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            d11 = 'H'; d10 = ' ';
                                            break;
                                    }
                                }
                                else if(d11 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            c11 = 'H'; d11 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            d10 = 'H'; d11 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            e11 = 'H'; d11 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            d12 = 'H'; d11 = ' ';
                                            break;
                                    }
                                }
                                else if(d12 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            c12 = 'H'; d12 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            d11 = 'H'; d12 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            e12 = 'H'; d12 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            d13 = 'H'; d12 = ' ';
                                            break;
                                    }
                                }
                                else if(d13 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            c13 = 'H'; d13 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            d12 = 'H'; d13 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            e13 = 'H'; d13 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            d14 = 'H'; d13 = ' ';
                                            break;
                                    }
                                }
                                else if(e4 == 'H'){                                          //keadaan e
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            d4 = 'H'; e4 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            e3 = 'H'; e4 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            f4 = 'H'; e4 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            e5 = 'H'; e4 = ' ';
                                            break;
                                    }
                                }
                                else if(e8 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            d8 = 'H'; e8 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            e7 = 'H'; e8 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            f8 = 'H'; e8 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            e9 = 'H'; e8 = ' ';
                                            break;
                                    }
                                }
                                else if(f2 == 'H'){                                          //keadaan f
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            e2 = 'H'; f2 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            f1 = 'H'; f2 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            g2 = 'H'; f2 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            f3 = 'H'; f2 = ' ';
                                            break;
                                    }
                                }
                                else if(f4 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            e4 = 'H'; f4 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            f3 = 'H'; f4 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            g4 = 'H'; f4 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            f5 = 'H'; f4 = ' ';
                                            break;
                                    }
                                }
                                else if(f5 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            e5 = 'H'; f5 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            f4 = 'H'; f5 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            g5 = 'H'; f5 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            f6 = 'H'; f5 = ' ';
                                            break;
                                    }
                                }
                                else if(f6 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            e6 = 'H'; f6 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            f5 = 'H'; f6 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            g6 = 'H'; f6 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            f7 = 'H'; f6 = ' ';
                                            break;
                                    }
                                }
                                else if(f8 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            e8 = 'H'; f8 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            f7 = 'H'; f8 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            g8 = 'H'; f8 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            f9 = 'H'; f8 = ' ';
                                            break;
                                    }
                                }
                                else if(f10 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            e10 = 'H'; f10 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            f9 = 'H'; f10 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            g10 = 'H'; f10 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            f11 = 'H'; f10 = ' ';
                                            break;
                                    }
                                }
                                else if(f11 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            e11 = 'H'; f11 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            f10 = 'H'; f11 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            g11 = 'H'; f11 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            f12 = 'H'; f11 = ' ';
                                            break;
                                    }
                                }
                                else if(f12 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            e12 = 'H'; f12 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            f11 = 'H'; f12 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            g12 = 'H'; f12 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            f13 = 'H'; f12 = ' ';
                                            break;
                                    }
                                }
                                else if(f13 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            e13 = 'H'; f13 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            f12 = 'H'; f13 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            g13 = 'H'; f13 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            f14 = 'H'; f13 = ' ';
                                            break;
                                    }
                                }
                                else if(f14 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            e14 = 'H'; f14 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            f13 = 'H'; f14 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            g14 = 'H'; f14 = ' ';
                                            break;
                                        /*case 'D':
                                        case 'd':
                                            f4 = 'H'; f3 = ' ';
                                            break;*/
                                    }
                                }
                                else if(g2 == 'H'){                                          //keadaan g
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            f2 = 'H'; g2 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            g1 = 'H'; g2 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            h2 = 'H'; g2 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            g3 = 'H'; g2 = ' ';
                                            break;
                                    }
                                }
                                else if(g6 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            f6 = 'H'; g6 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            g5 = 'H'; g6 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            h6 = 'H'; g6 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            g7 = 'H'; g6 = ' ';
                                            break;
                                    }
                                }
                                else if(g8 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            f8 = 'H'; g8 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            g7 = 'H'; g8 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            h8 = 'H'; g8 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            g9 = 'H'; g8 = ' ';
                                            break;
                                    }
                                }
                                else if(g13 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            f13 = 'H'; g13 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            g12 = 'H'; g13 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            h13 = 'H'; g13 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            g14 = 'H'; g13 = ' ';
                                            break;
                                    }
                                }
                                else if(h2 == 'H'){                                              //keadaan h
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            g2 = 'H'; h2 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            h1 = 'H'; h2 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            i2 = 'H'; h2 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            h3 = 'H'; h2 = ' ';
                                            break;
                                    }
                                }
                                else if(h3 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            g3 = 'H'; h3 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            h2 = 'H'; h3 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            i3 = 'H'; h3 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            h4 = 'H'; h3 = ' ';
                                            break;
                                    }
                                }
                                else if(h4 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            g4 = 'H'; h4 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            h3 = 'H'; h4 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            i4 = 'H'; h4 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            h5 = 'H'; h4 = ' ';
                                            break;
                                    }
                                }
                                else if(h5 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            g5 = 'H'; h5 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            h4 = 'H'; h5 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            i5 = 'H'; h5 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            h6 = 'H'; h5 = ' ';
                                            break;
                                    }
                                }
                                else if(h6 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            g6 = 'H'; h6 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            h5 = 'H'; h6 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            i6 = 'H'; h6 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            h7 = 'H'; h6 = ' ';
                                            break;
                                    }
                                }
                                else if(h7 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            g7 = 'H'; h7 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            h6 = 'H'; h7 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            i7 = 'H'; h7 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            h8 = 'H'; h7 = ' ';
                                            break;
                                    }
                                }
                                else if(h8 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            g8 = 'H'; h8 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            h7 = 'H'; h8 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            i8 = 'H'; h8 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            h9 = 'H'; h8 = ' ';
                                            break;
                                    }
                                }
                                else if(h9 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            g9 = 'H'; h9 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            h8 = 'H'; h9 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            i9 = 'H'; h9 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            h10 = 'H'; h9 = ' ';
                                            break;
                                    }
                                }
                                else if(h10 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            g10 = 'H'; h10 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            h9 = 'H'; h10 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            i10 = 'H'; h10 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            h11 = 'H'; h10 = ' ';
                                            break;
                                    }
                                }
                                else if(h11 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            g11 = 'H'; h11 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            h10 = 'H'; h11 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            i11 = 'H'; h11 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            h12 = 'H'; h11 = ' ';
                                            break;
                                    }
                                }
                                else if(h12 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            g12 = 'H'; h12 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            h11 = 'H'; h12 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            i12 = 'H'; h12 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            h13 = 'H'; h12 = ' ';
                                            break;
                                    }
                                }
                                else if(h13 == 'H'){
                                    switch(gerak){
                                        case 'W':
                                        case 'w':
                                            g13 = 'H'; h13 = ' ';
                                            break;
                                        case 'A':
                                        case 'a':
                                            h12 = 'H'; h13 = ' ';
                                            break;
                                        case 'S':
                                        case 's':
                                            i13 = 'H'; h13 = ' ';
                                            break;
                                        case 'D':
                                        case 'd':
                                            h14 = 'H'; h13 = ' ';
                                            break;
                                    }
                                }

                                //Tampilan permainan
                                printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14);
                                printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14);
                                printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14);
                                printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14);
                                printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14);
                                printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14);
                                printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", g1, g2, g3, g4, g5, g6, g7, g8, g9, g10, g11, g12, g13, g14);
                                printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", h1, h2, h3, h4, h5, h6, h7, h8, h9, h10, h11, h12, h13, h14);
                                printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14);

                                //Membuat nilai jika menabrak dinding
                                if(a1=='H'||a2=='H'||a3=='H'||a4=='H'||a5=='H'||a6=='H'||a7=='H'||a8=='H'||a9=='H'||a10=='H'||a11=='H'||a12=='H'||a13=='H'||a14=='H'){
                                    salah_t1 = 1;
                                }
                                else if(b1=='H'||b14=='H'){
                                    salah_t1 = 1;
                                }
                                else if(c1=='H'||c3=='H'||c4=='H'||c5=='H'||c6=='H'||c7=='H'||c8=='H'||c9=='H'||c10=='H'||c11=='H'||c12=='H'||c14=='H'){
                                    salah_t1 = 1;
                                }
                                else if(d1=='H'||d5=='H'||d14=='H'){
                                    salah_t1 = 1;
                                }
                                else if(e1=='H'||e2=='H'||e3=='H'||e5=='H'||e6=='H'||e7=='H'||e9=='H'||e10=='H'||e11=='H'||e12=='H'||e13=='H'||e14=='H'){
                                    salah_t1 = 1;
                                }
                                else if(f3=='H'||f7=='H'||f9=='H'){
                                    salah_t1 = 1;
                                }
                                else if(g1=='H'||g3=='H'||g4=='H'||g5=='H'||g7=='H'||g9=='H'||g10=='H'||g11=='H'||g12=='H'||g14=='H'){
                                    salah_t1 = 1;
                                }
                                else if(h1=='H'||h7=='H'||h14=='H'){
                                    salah_t1 = 1;
                                }
                                else if(i1=='H'||i2=='H'||i3=='H'||i4=='H'||i5=='H'||i6=='H'||i7=='H'||i8=='H'||i9=='H'||i10=='H'||i11=='H'||i12=='H'||i13=='H'||i14=='H'){
                                    salah_t1 = 1;
                                }

                                //Proses jikalau selesai tingkat 1
                                if(f1 == 'H'){
                                    tingkat1 = 1;
                                    selesai = 1;
                                    salah_t1 = 3;
                                    printf("\nTingkat 1 selesai!\nTingkat 2 terbuka!");

                                    //Daftarkan waktu
                                    ambil_waktu = 1;
                                }

                                //Salah memasukkan masukan
                                switch(gerak){
                                    case 'W':
                                    case 'w':
                                    case 'A':
                                    case 'a':
                                    case 'S':
                                    case 's':
                                    case 'D':
                                    case 'd':
                                    case '\0':
                                        printf("\n");
                                        break;
                                    case 'K':
                                    case 'k':
                                        salah_t1 = 2;
                                        break;
                                    default:
                                        printf("\nBukan perintah apapun!");
                                        gerak = '\0';
                                        break;
                                }

                                //Pilihan menabrak dinding atau tidak - dilanjutkan atau tidak
                                if(salah_t1 == 1){
                                    printf("\n\nPemeran menabrak dinding beracun!");
                                    printf("\n\nTekan apa saja untuk lanjutkan"); getch();
                                    selesai = 1;
                                }
                                else if(salah_t1 == 2){
                                    ke_menu = '\0';
                                    printf("\n\nAnda yakin ingin ke menu?\nY: Ya\nT: Tidak"); ke_menu = getch();

                                    //Proses masukan diatas
                                    if(ke_menu == 'Y' || ke_menu == 'y'){
                                            selesai = 1;
                                    }
                                    else if(ke_menu == 'T' || ke_menu == 't'){
                                            salah_t1 = 0;
                                            gerak = '\0';
                                            system("cls");
                                    }
                                    else{
                                            gerak = 'X';
                                            system("cls");
                                    }

                                }
                                else if(salah_t1 == 3){
                                    salah_t1 = 0;
                                }
                                else{
                                    printf("\n\nA: Ke kiri\nS: Ke bawah\nD: Ke kanan\nW: Ke Atas\n\nK: Ke menu\n"); gerak = getch();
                                    system("cls");
                                }

                            } while(selesai < 1);

                            //Waktu selesai
                            time(&waktu_selesai);

                            //Selisih waktu
                            selisih_waktu = difftime(waktu_selesai, waktu_mulai);

                            //Menunjukan pemain waktu dia menyelesaikan tingkatan
                            if(ambil_waktu == 1){
                                printf("\nWaktu anda menyelesaikan labirin %0.0f detik\n\nTekan apa saja untuk melanjutkan", selisih_waktu);
                                getch();
                            }

                            //Waktu terbaik
                            if(ambil_waktu == 1){
                                if(waktu_1 < 1){
                                    waktu_1 = selisih_waktu;
                                }
                                else{
                                    if(waktu_1 > selisih_waktu){
                                        waktu_1 = selisih_waktu;
                                    }
                                }

                                ambil_waktu = 0;
                            }

                            break;

                        case '2':

                            //Kalau dia milih 2 apa tingkatnya sudah terbuka atau belum
                            switch(tingkat1){
                                case 0:
                                    sal_tingkat = 1;
                                    break;

                                case 1:
                                    system("cls");

                                    int xa1=0, xa2=0, xa3=0, xa4=0, xa5=0, xa6=0, xa7=0, xa8=0, xa9=0, xa10=0, xa11=0, xa12=0, xa13=0, xa14=0, xa15=0;
                                    int xb1=0, xb2=0, xb3=0, xb4=0, xb5=0, xb6=0, xb7=0, xb8=0, xb9=0, xb10=0, xb11=0, xb12=0, xb13=0, xb14=0, xb15=0;
                                    int xc1=0, xc2=0, xc3=0, xc4=0, xc5=0, xc6=0, xc7=0, xc8=0, xc9=0, xc10=0, xc11=0, xc12=0, xc13=0, xc14=0, xc15=0;
                                    int xd1=0, xd2=0, xd3=0, xd4=0, xd5=0, xd6=0, xd7=0, xd8=0, xd9=0, xd10=0, xd11=0, xd12=0, xd13=0, xd14=0, xd15=0;
                                    int xe1=0, xe2=0, xe3=0, xe4=0, xe5=0, xe6=0, xe7=0, xe8=0, xe9=0, xe10=0, xe11=0, xe12=0, xe13=0, xe14=0, xe15=0;
                                    int xf1=0, xf2=0, xf3=0, xf4=0, xf5=0, xf6=0, xf7=0, xf8=0, xf9=0, xf10=0, xf11=0, xf12=0, xf13=0, xf14=0, xf15=0;
                                    int xg1=0, xg2=0, xg3=0, xg4=0, xg5=0, xg6=0, xg7=0, xg8=0, xg9=0, xg10=0, xg11=0, xg12=0, xg13=0, xg14=0, xg15=0;
                                    int xh1=0, xh2=0, xh3=0, xh4=0, xh5=0, xh6=0, xh7=0, xh8=0, xh9=0, xh10=0, xh11=0, xh12=0, xh13=0, xh14=0, xh15=0;
                                    int xi1=0, xi2=0, xi3=0, xi4=0, xi5=0, xi6=0, xi7=0, xi8=0, xi9=0, xi10=0, xi11=0, xi12=0, xi13=0, xi14=0, xi15=0;

                                    //Peta
                                    a1='='; a2='='; a3='='; a4='='; a5='='; a6='='; a7='='; a8='='; a9='='; a10='='; a11='='; a12='='; a13='='; a14='='; //a15;
                                    b1='|'; b2=' '; b3=' '; b4=' '; b5=' '; b6=' '; b7=' '; b8=' '; b9=' '; b10=' '; b11=' '; b12=' '; b13=' '; b14=' '; //b15;
                                    c1='|'; c2=' '; c3='='; c4='='; c5='='; c6='='; c7='='; c8='='; c9='='; c10='='; c11='='; c12='='; c13='='; c14='|'; //c15;
                                    d1='|'; d2=' '; d3=' '; d4=' '; d5='|'; d6=' '; d7=' '; d8=' '; d9='|'; d10=' '; d11=' '; d12=' '; d13=' '; d14='|'; //d15;
                                    e1='|'; e2='='; e3='='; e4=' '; e5='|'; e6=' '; e7='|'; e8=' '; e9='|'; e10=' '; e11='|'; e12='='; e13='='; e14='|'; //e15;
                                    f1='|'; f2=' '; f3='|'; f4=' '; f5='|'; f6=' '; f7='|'; f8=' '; f9='|'; f10=' '; f11=' '; f12=' '; f13=' '; f14=' '; //f15;
                                    g1='|'; g2=' '; g3='|'; g4=' '; g5='|'; g6=' '; g7='|'; g8=' '; g9='|'; g10='='; g11='='; g12='|'; g13=' '; g14='|'; //g15;
                                    h1='|'; h2=' '; h3=' '; h4=' '; h5=' '; h6=' '; h7='|'; h8=' '; h9=' '; h10=' '; h11=' '; h12=' '; h13=' '; h14='|'; //h15;
                                    i1='|'; i2='='; i3='='; i4='='; i5='='; i6='='; i7='|'; i8='='; i9='='; i10='='; i11='='; i12='='; i13='='; i14='|'; //i15;

                                    //Nilai awal
                                    gerak = '\0'; selesai = 0; salah_t1 = 0;

                                    //Waktu awal
                                    time(&waktu_mulai);

                                    //Memberi posisi
                                    b14 = 'H';

                                    do{

                                        //Pergerakan
                                        if(b2 == 'H'){                     //keadaan b
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    a2 = 'H'; b2 = '.'; xb2 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    b1 = 'H'; b2 = '.'; xb2 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    c2 = 'H'; b2 = '.'; xb2 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    b3 = 'H'; b2 = '.'; xb2 = 1;
                                                    break;
                                            }
                                        }
                                        else if(b3 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    a3 = 'H'; b3 = '.'; xb3 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    b2 = 'H'; b3 = '.'; xb3 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    c3 = 'H'; b3 = '.'; xb3 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    b4 = 'H'; b3 = '.'; xb3 = 1;
                                                    break;
                                            }
                                        }
                                        else if(b4 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    a4 = 'H'; b4 = '.'; xb4 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    b3 = 'H'; b4 = '.'; xb4 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    c4 = 'H'; b4 = '.'; xb4 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    b5 = 'H'; b4 = '.'; xb4 = 1;
                                                    break;
                                            }
                                        }
                                        else if(b5 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    a5 = 'H'; b5 = '.'; xb5 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    b4 = 'H'; b5 = '.'; xb5 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    c5 = 'H'; b5 = '.'; xb5 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    b6 = 'H'; b5 = '.'; xb5 = 1;
                                                    break;
                                            }
                                        }
                                        else if(b6 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    a6 = 'H'; b6 = '.'; xb6 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    b5 = 'H'; b6 = '.'; xb6 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    c6 = 'H'; b6 = '.'; xb6 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    b7 = 'H'; b6 = '.'; xb6 = 1;
                                                    break;
                                            }
                                        }
                                        else if(b7 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    a7 = 'H'; b7 = '.'; xb7 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    b6 = 'H'; b7 = '.'; xb7 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    c7 = 'H'; b7 = '.'; xb7 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    b8 = 'H'; b7 = '.'; xb7 = 1;
                                                    break;
                                            }
                                        }
                                        else if(b8 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    a8 = 'H'; b8 = '.'; xb8 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    b7 = 'H'; b8 = '.'; xb8 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    c8 = 'H'; b8 = '.'; xb8 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    b9 = 'H'; b8 = '.'; xb8 = 1;
                                                    break;
                                            }
                                        }
                                        else if(b9 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    a9 = 'H'; b9 = '.'; xb9 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    b8 = 'H'; b9 = '.'; xb9 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    c9 = 'H'; b9 = '.'; xb9 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    b10 = 'H'; b9 = '.'; xb9 = 1;
                                                    break;
                                            }
                                        }
                                        else if(b10 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    a10 = 'H'; b10 = '.'; xb10 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    b9 = 'H'; b10 = '.'; xb10 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    c10 = 'H'; b10 = '.'; xb10 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    b11 = 'H'; b10 = '.'; xb10 = 1;
                                                    break;
                                            }
                                        }
                                        else if(b11 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    a11 = 'H'; b11 = '.'; xb11 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    b10 = 'H'; b11 = '.'; xb11 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    c11 = 'H'; b11 = '.'; xb11 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    b12 = 'H'; b11 = '.'; xb11 = 1;
                                                    break;
                                            }
                                        }
                                        else if(b12 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    a12 = 'H'; b12 = '.'; xb12 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    b11 = 'H'; b12 = '.'; xb12 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    c12 = 'H'; b12 = '.'; xb12 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    b13 = 'H'; b12 = '.'; xb12 = 1;
                                                    break;
                                            }
                                        }
                                        else if(b13 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    a13 = 'H'; b13 = '.'; xb13 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    b12 = 'H'; b13 = '.'; xb13 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    c13 = 'H'; b13 = '.'; xb13 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    b14 = 'H'; b13 = '.'; xb13 = 1;
                                                    break;
                                            }
                                        }
                                        else if(b14 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    a14 = 'H'; b14 = '.'; xb14 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    b13 = 'H'; b14 = '.'; xb14 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    c14 = 'H'; b14 = '.'; xb14 = 1;
                                                    break;
                                                /*case 'D':
                                                case 'd':
                                                    b15 = 'H'; b14 = '.'; xb14 = 1;
                                                    break;*/
                                            }
                                        }
                                        else if(c2 == 'H'){                                          //keadaan c
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    b2 = 'H'; c2 = '.'; xc2 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    c1 = 'H'; c2 = '.'; xc2 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    d2 = 'H'; c2 = '.'; xc2 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    c3 = 'H'; c2 = '.'; xc2 = 1;
                                                    break;
                                            }
                                        }
                                        /*else if(c13 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    b13 = 'H'; c13 = ' '; xc13 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    c12 = 'H'; c13 = ' '; xc13 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    d13 = 'H'; c13 = ' '; xc13 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    c14 = 'H'; c13 = ' '; xc13 = 1;
                                                    break;
                                            }
                                        }*/
                                        else if(d2 == 'H'){                                             //keadaan d
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    c2 = 'H'; d2 = '.'; xd2 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    d1 = 'H'; d2 = '.'; xd2 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    e2 = 'H'; d2 = '.'; xd2 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    d3 = 'H'; d2 = '.'; xd2 = 1;
                                                    break;
                                            }
                                        }
                                        else if(d3 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    c3 = 'H'; d3 = '.'; xd3 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    d2 = 'H'; d3 = '.'; xd3 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    e3 = 'H'; d3 = '.'; xd3 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    d4 = 'H'; d3 = '.'; xd3 = 1;
                                                    break;
                                            }
                                        }
                                        else if(d4 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    c4 = 'H'; d4 = '.'; xd4 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    d3 = 'H'; d4 = '.'; xd4 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    e4 = 'H'; d4 = '.'; xd4 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    d5 = 'H'; d4 = '.'; xd4 = 1;
                                                    break;
                                            }
                                        }
                                        else if(d6 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    c6 = 'H'; d6 = '.'; xd6 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    d5 = 'H'; d6 = '.'; xd6 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    e6 = 'H'; d6 = '.'; xd6 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    d7 = 'H'; d6 = '.'; xd6 = 1;
                                                    break;
                                            }
                                        }
                                        else if(d7 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    c7 = 'H'; d7 = '.'; xd7 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    d6 = 'H'; d7 = '.'; xd7 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    e7 = 'H'; d7 = '.'; xd7 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    d8 = 'H'; d7 = '.'; xd7 = 1;
                                                    break;
                                            }
                                        }
                                        else if(d8 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    c8 = 'H'; d8 = '.'; xd8 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    d7 = 'H'; d8 = '.'; xd8 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    e8 = 'H'; d8 = '.'; xd8 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    d9 = 'H'; d8 = '.'; xd8 = 1;
                                                    break;
                                            }
                                        }
                                        /*else if(d9 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    c9 = 'H'; d9 = ' '; xd9 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    d8 = 'H'; d9 = ' '; xd9 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    e9 = 'H'; d9 = ' '; xd9 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    d10 = 'H'; d9 = ' '; xd9 = 1;
                                                    break;
                                            }
                                        }*/
                                        else if(d10 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    c10 = 'H'; d10 = '.'; xd10 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    d9 = 'H'; d10 = '.'; xd10 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    e10 = 'H'; d10 = '.'; xd10 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    d11 = 'H'; d10 = '.'; xd10 = 1;
                                                    break;
                                            }
                                        }
                                        else if(d11 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    c11 = 'H'; d11 = '.'; xd11 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    d10 = 'H'; d11 = '.'; xd11 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    e11 = 'H'; d11 = '.'; xd11 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    d12 = 'H'; d11 = '.'; xd11 = 1;
                                                    break;
                                            }
                                        }
                                        else if(d12 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    c12 = 'H'; d12 = '.'; xd12 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    d11 = 'H'; d12 = '.'; xd12 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    e12 = 'H'; d12 = '.'; xd12 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    d13 = 'H'; d12 = '.'; xd12 = 1;
                                                    break;
                                            }
                                        }
                                        else if(d13 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    c13 = 'H'; d13 = '.'; xd13 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    d12 = 'H'; d13 = '.'; xd13 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    e13 = 'H'; d13 = '.'; xd13 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    d14 = 'H'; d13 = '.'; xd13 = 1;
                                                    break;
                                            }
                                        }
                                        else if(e4 == 'H'){                                          //keadaan e
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    d4 = 'H'; e4 = '.'; xe4 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    e3 = 'H'; e4 = '.'; xe4 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    f4 = 'H'; e4 = '.'; xe4 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    e5 = 'H'; e4 = '.'; xe4 = 1;
                                                    break;
                                            }
                                        }
                                        else if(e6 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    d6 = 'H'; e6 = '.'; xe6 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    e5 = 'H'; e6 = '.'; xe6 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    f6 = 'H'; e6 = '.'; xe6 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    e7 = 'H'; e6 = '.'; xe6 = 1;
                                                    break;
                                            }
                                        }
                                        else if(e8 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    d8 = 'H'; e8 = '.'; xe8 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    e7 = 'H'; e8 = '.'; xe8 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    f8 = 'H'; e8 = '.'; xe8 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    e9 = 'H'; e8 = '.'; xe8 = 1;
                                                    break;
                                            }
                                        }
                                        else if(e10 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    d10 = 'H'; e10 = '.'; xe10 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    e9 = 'H'; e10 = '.'; xe10 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    f10 = 'H'; e10 = '.'; xe10 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    e11 = 'H'; e10 = '.'; xe10 = 1;
                                                    break;
                                            }
                                        }
                                        else if(f2 == 'H'){                                          //keadaan f
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    e2 = 'H'; f2 = '.'; xf2 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    f1 = 'H'; f2 = '.'; xf2 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    g2 = 'H'; f2 = '.'; xf2 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    f3 = 'H'; f2 = '.'; xf2 = 1;
                                                    break;
                                            }
                                        }
                                        else if(f4 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    e4 = 'H'; f4 = '.'; xf4 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    f3 = 'H'; f4 = '.'; xf4 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    g4 = 'H'; f4 = '.'; xf4 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    f5 = 'H'; f4 = '.'; xf4 = 1;
                                                    break;
                                            }
                                        }
                                        /*else if(f5 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    e5 = 'H'; f5 = ' '; xf5 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    f4 = 'H'; f5 = ' '; xf5 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    g5 = 'H'; f5 = ' '; xf5 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    f6 = 'H'; f5 = ' '; xf5 = 1;
                                                    break;
                                            }
                                        }*/
                                        else if(f6 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    e6 = 'H'; f6 = '.'; xf6 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    f5 = 'H'; f6 = '.'; xf6 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    g6 = 'H'; f6 = '.'; xf6 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    f7 = 'H'; f6 = '.'; xf6 = 1;
                                                    break;
                                            }
                                        }
                                        else if(f8 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    e8 = 'H'; f8 = '.'; xf8 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    f7 = 'H'; f8 = '.'; xf8 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    g8 = 'H'; f8 = '.'; xf8 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    f9 = 'H'; f8 = '.'; xf8 = 1;
                                                    break;
                                            }
                                        }
                                        else if(f10 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    e10 = 'H'; f10 = '.'; xf10 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    f9 = 'H'; f10 = '.'; xf10 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    g10 = 'H'; f10 = '.'; xf10 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    f11 = 'H'; f10 = '.'; xf10 = 1;
                                                    break;
                                            }
                                        }
                                        else if(f11 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    e11 = 'H'; f11 = '.'; xf11 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    f10 = 'H'; f11 = '.'; xf11 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    g11 = 'H'; f11 = '.'; xf11 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    f12 = 'H'; f11 = '.'; xf11 = 1;
                                                    break;
                                            }
                                        }
                                        else if(f12 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    e12 = 'H'; f12 = '.'; xf12 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    f11 = 'H'; f12 = '.'; xf12 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    g12 = 'H'; f12 = '.'; xf12 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    f13 = 'H'; f12 = '.'; xf12 = 1;
                                                    break;
                                            }
                                        }
                                        else if(f13 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    e13 = 'H'; f13 = '.'; xf13 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    f12 = 'H'; f13 = '.'; xf13 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    g13 = 'H'; f13 = '.'; xf13 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    f14 = 'H'; f13 = '.'; xf13 = 1;
                                                    break;
                                            }
                                        }
                                        /*else if(f14 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    e14 = 'H'; f14 = ' '; xf14 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    f13 = 'H'; f14 = ' '; xf14 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    g14 = 'H'; f14 = ' '; xf14 = 1;
                                                    break;
                                                /*case 'D':
                                                case 'd':
                                                    f4 = 'H'; f3 = ' ';
                                                    break;
                                            }
                                        }*/
                                        else if(g2 == 'H'){                                          //keadaan g
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    f2 = 'H'; g2 = '.'; xg2 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    g1 = 'H'; g2 = '.'; xg2 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    h2 = 'H'; g2 = '.'; xg2 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    g3 = 'H'; g2 = '.'; xg2 = 1;
                                                    break;
                                            }
                                        }
                                        else if(g4 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    f4 = 'H'; g4 = '.'; xg4 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    g3 = 'H'; g4 = '.'; xg4 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    h4 = 'H'; g4 = '.'; xg4 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    g5 = 'H'; g4 = '.'; xg4 = 1;
                                                    break;
                                            }
                                        }
                                        else if(g6 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    f6 = 'H'; g6 = '.'; xg6 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    g5 = 'H'; g6 = '.'; xg6 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    h6 = 'H'; g6 = '.'; xg6 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    g7 = 'H'; g6 = '.'; xg6 = 1;
                                                    break;
                                            }
                                        }
                                        else if(g8 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    f8 = 'H'; g8 = '.'; xg8 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    g7 = 'H'; g8 = '.'; xg8 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    h8 = 'H'; g8 = '.'; xg8 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    g9 = 'H'; g8 = '.'; xg8 = 1;
                                                    break;
                                            }
                                        }
                                        else if(g13 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    f13 = 'H'; g13 = '.'; xg13 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    g12 = 'H'; g13 = '.'; xg13 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    h13 = 'H'; g13 = '.'; xg13 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    g14 = 'H'; g13 = '.'; xg13 = 1;
                                                    break;
                                            }
                                        }
                                        else if(h2 == 'H'){                                              //keadaan h
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    g2 = 'H'; h2 = '.'; xh2 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    h1 = 'H'; h2 = '.'; xh2 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    i2 = 'H'; h2 = '.'; xh2 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    h3 = 'H'; h2 = '.'; xh2 = 1;
                                                    break;
                                            }
                                        }
                                        else if(h3 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    g3 = 'H'; h3 = '.'; xh3 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    h2 = 'H'; h3 = '.'; xh3 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    i3 = 'H'; h3 = '.'; xh3 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    h4 = 'H'; h3 = '.'; xh3 = 1;
                                                    break;
                                            }
                                        }
                                        else if(h4 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    g4 = 'H'; h4 = '.'; xh4 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    h3 = 'H'; h4 = '.'; xh4 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    i4 = 'H'; h4 = '.'; xh4 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    h5 = 'H'; h4 = '.'; xh4 = 1;
                                                    break;
                                            }
                                        }
                                        else if(h5 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    g5 = 'H'; h5 = '.'; xh5 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    h4 = 'H'; h5 = '.'; xh5 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    i5 = 'H'; h5 = '.'; xh5 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    h6 = 'H'; h5 = '.'; xh5 = 1;
                                                    break;
                                            }
                                        }
                                        else if(h6 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    g6 = 'H'; h6 = '.'; xh6 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    h5 = 'H'; h6 = '.'; xh6 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    i6 = 'H'; h6 = '.'; xh6 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    h7 = 'H'; h6 = '.'; xh6 = 1;
                                                    break;
                                            }
                                        }
                                        /*else if(h7 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    g7 = 'H'; h7 = ' '; xh7 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    h6 = 'H'; h7 = ' '; xh7 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    i7 = 'H'; h7 = ' '; xh7 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    h8 = 'H'; h7 = ' '; xh7 = 1;
                                                    break;
                                            }
                                        }*/
                                        else if(h8 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    g8 = 'H'; h8 = '.'; xh8 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    h7 = 'H'; h8 = '.'; xh8 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    i8 = 'H'; h8 = '.'; xh8 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    h9 = 'H'; h8 = '.'; xh8 = 1;
                                                    break;
                                            }
                                        }
                                        else if(h9 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    g9 = 'H'; h9 = '.'; xh9 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    h8 = 'H'; h9 = '.'; xh9 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    i9 = 'H'; h9 = '.'; xh9 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    h10 = 'H'; h9 = '.'; xh9 = 1;
                                                    break;
                                            }
                                        }
                                        else if(h10 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    g10 = 'H'; h10 = '.'; xh10 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    h9 = 'H'; h10 = '.'; xh10 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    i10 = 'H'; h10 = '.'; xh10 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    h11 = 'H'; h10 = '.'; xh10 = 1;
                                                    break;
                                            }
                                        }
                                        else if(h11 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    g11 = 'H'; h11 = '.'; xh11 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    h10 = 'H'; h11 = '.'; xh11 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    i11 = 'H'; h11 = '.'; xh11 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    h12 = 'H'; h11 = '.'; xh11 = 1;
                                                    break;
                                            }
                                        }
                                        else if(h12 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    g12 = 'H'; h12 = '.'; xh12 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    h11 = 'H'; h12 = '.'; xh12 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    i12 = 'H'; h12 = '.'; xh12 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    h13 = 'H'; h12 = '.'; xh12 = 1;
                                                    break;
                                            }
                                        }
                                        else if(h13 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    g13 = 'H'; h13 = '.'; xh13 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    h12 = 'H'; h13 = '.'; xh13 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    i13 = 'H'; h13 = '.'; xh13 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    h14 = 'H'; h13 = '.'; xh13 = 1;
                                                    break;
                                            }
                                        }

                                        //Tampilan permainan
                                        printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14);
                                        printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14);
                                        printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14);
                                        printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14);
                                        printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14);
                                        printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14);
                                        printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", g1, g2, g3, g4, g5, g6, g7, g8, g9, g10, g11, g12, g13, g14);
                                        printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", h1, h2, h3, h4, h5, h6, h7, h8, h9, h10, h11, h12, h13, h14);
                                        printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14);

                                        //Membuat nilai jika menabrak dinding
                                        if(a1=='H'||a2=='H'||a3=='H'||a4=='H'||a5=='H'||a6=='H'||a7=='H'||a8=='H'||a9=='H'||a10=='H'||a11=='H'||a12=='H'||a13=='H'||a14=='H'){
                                            salah_t1 = 1;
                                        }
                                        else if(b1=='H'){
                                            salah_t1 = 1;
                                        }
                                        else if(c1=='H'||c3=='H'||c4=='H'||c5=='H'||c6=='H'||c7=='H'||c8=='H'||c9=='H'||c10=='H'||c11=='H'||c12=='H'||c13=='H'||c14=='H'){
                                            salah_t1 = 1;
                                        }
                                        else if(d1=='H'||d5=='H'||d9=='H'||d14=='H'){
                                            salah_t1 = 1;
                                        }
                                        else if(e1=='H'||e2=='H'||e3=='H'||e5=='H'||e7=='H'||e9=='H'||e11=='H'||e12=='H'||e13=='H'||e14=='H'){
                                            salah_t1 = 1;
                                        }
                                        else if(f1=='H'||f3=='H'||f5=='H'||f7=='H'||f9=='H'){
                                            salah_t1 = 1;
                                        }
                                        else if(g1=='H'||g3=='H'||g5=='H'||g7=='H'||g9=='H'||g10=='H'||g11=='H'||g12=='H'||g14=='H'){
                                            salah_t1 = 1;
                                        }
                                        else if(h1=='H'||h7=='H'||h14=='H'){
                                            salah_t1 = 1;
                                        }
                                        else if(i1=='H'||i2=='H'||i3=='H'||i4=='H'||i5=='H'||i6=='H'||i7=='H'||i8=='H'||i9=='H'||i10=='H'||i11=='H'||i12=='H'||i13=='H'||i14=='H'){
                                            salah_t1 = 1;
                                        }

                                        //Proses saat menginjak titik
                                        if(b2=='H' && xb2==1){ salah_t1 = 3;} //B
                                        else if(b3=='H' && xb3==1){ salah_t1 = 3;}
                                        else if(b4=='H' && xb4==1){ salah_t1 = 3;}
                                        else if(b5=='H' && xb5==1){ salah_t1 = 3;}
                                        else if(b6=='H' && xb6==1){ salah_t1 = 3;}
                                        else if(b7=='H' && xb7==1){ salah_t1 = 3;}
                                        else if(b8=='H' && xb8==1){ salah_t1 = 3;}
                                        else if(b9=='H' && xb9==1){ salah_t1 = 3;}
                                        else if(b10=='H' && xb10==1){ salah_t1 = 3;}
                                        else if(b11=='H' && xb11==1){ salah_t1 = 3;}
                                        else if(b12=='H' && xb12==1){ salah_t1 = 3;}
                                        else if(b13=='H' && xb13==1){ salah_t1 = 3;}
                                        else if(b14=='H' && xb14==1){ salah_t1 = 3;}
                                        else if(c2=='H' && xc2==1){ salah_t1 = 3;} //C
                                        else if(d2=='H' && xd2==1){ salah_t1 = 3;} //D
                                        else if(d3=='H' && xd3==1){ salah_t1 = 3;}
                                        else if(d4=='H' && xd4==1){ salah_t1 = 3;}
                                        else if(d6=='H' && xd6==1){ salah_t1 = 3;}
                                        else if(d7=='H' && xd7==1){ salah_t1 = 3;}
                                        else if(d8=='H' && xd8==1){ salah_t1 = 3;}
                                        else if(d10=='H' && xd10==1){ salah_t1 = 3;}
                                        else if(d11=='H' && xd11==1){ salah_t1 = 3;}
                                        else if(d12=='H' && xd12==1){ salah_t1 = 3;}
                                        else if(d13=='H' && xd13==1){ salah_t1 = 3;}
                                        else if(e4=='H' && xe4==1){ salah_t1 = 3;} //E
                                        else if(e6=='H' && xe6==1){ salah_t1 = 3;}
                                        else if(e8=='H' && xe8==1){ salah_t1 = 3;}
                                        else if(e10=='H' && xe10==1){ salah_t1 = 3;}
                                        else if(f2=='H' && xf2==1){ salah_t1 = 3;} //F
                                        else if(f4=='H' && xf4==1){ salah_t1 = 3;}
                                        else if(f6=='H' && xf6==1){ salah_t1 = 3;}
                                        else if(f8=='H' && xf8==1){ salah_t1 = 3;}
                                        else if(f10=='H' && xf10==1){ salah_t1 = 3;}
                                        else if(f11=='H' && xf11==1){ salah_t1 = 3;}
                                        else if(f12=='H' && xf12==1){ salah_t1 = 3;}
                                        else if(f13=='H' && xf13==1){ salah_t1 = 3;}
                                        else if(g2=='H' && xg2==1){ salah_t1 = 3;} //G
                                        else if(g4=='H' && xg4==1){ salah_t1 = 3;}
                                        else if(g6=='H' && xg6==1){ salah_t1 = 3;}
                                        else if(g8=='H' && xg8==1){ salah_t1 = 3;}
                                        else if(g13=='H' && xg13==1){ salah_t1 = 3;}
                                        else if(h2=='H' && xh2==1){ salah_t1 = 3;} //H
                                        else if(h3=='H' && xh3==1){ salah_t1 = 3;}
                                        else if(h4=='H' && xh4==1){ salah_t1 = 3;}
                                        else if(h5=='H' && xh5==1){ salah_t1 = 3;}
                                        else if(h6=='H' && xh6==1){ salah_t1 = 3;}
                                        else if(h8=='H' && xh8==1){ salah_t1 = 3;}
                                        else if(h9=='H' && xh9==1){ salah_t1 = 3;}
                                        else if(h10=='H' && xh10==1){ salah_t1 = 3;}
                                        else if(h11=='H' && xh11==1){ salah_t1 = 3;}
                                        else if(h12=='H' && xh12==1){ salah_t1 = 3;}
                                        else if(h13=='H' && xh13==1){ salah_t1 = 3;}

                                        //Jika selesai masuk f14 (menang)
                                        if(f14 == 'H'){
                                            tingkat2 = 1;
                                            selesai = 1;
                                            salah_t1 = 4;
                                            printf("\nTingkat 2 selesai!\nTingkat 3 terbuka!");

                                            //Mendaftarkan waktu
                                            ambil_waktu = 1;
                                        }

                                        //Salah memasukkan masukan
                                        switch(gerak){
                                            case 'W':
                                            case 'w':
                                            case 'A':
                                            case 'a':
                                            case 'S':
                                            case 's':
                                            case 'D':
                                            case 'd':
                                            case '\0':
                                                printf("\n");
                                                break;
                                            case 'K':
                                            case 'k':
                                                salah_t1 = 2;
                                                break;
                                            default:
                                                printf("\nBukan perintah apapun!");
                                                gerak = '\0';
                                                break;
                                        }

                                        //Pilihan menabrak dinding atau tidak - dilanjutkan atau tidak
                                        if(salah_t1 == 1){
                                            printf("\n\nPemeran menabrak dinding beracun!");
                                            printf("\n\nTekan apa saja untuk lanjutkan"); getch();
                                            selesai = 1;
                                        }
                                        else if(salah_t1 == 2){
                                            ke_menu = '\0';
                                            printf("\n\nAnda yakin ingin ke menu?\nY: Ya\nT: Tidak"); ke_menu = getch();

                                            //Proses masukan diatas
                                            if(ke_menu == 'Y' || ke_menu == 'y'){
                                                selesai = 1;
                                            }
                                            else if(ke_menu == 'T' || ke_menu == 't'){
                                                salah_t1 = 0;
                                                gerak = '\0';
                                                system("cls");
                                            }
                                            else{
                                                gerak = 'X';
                                                system("cls");
                                            }

                                        }
                                        else if(salah_t1 == 3){
                                            printf("\n\nPemeran terjatuh karena menginjak jalan rapuh!");
                                            printf("\n\nTekan apa saja untuk lanjutkan"); getch();
                                            selesai = 1;
                                        }
                                        else if(salah_t1 == 4){
                                            salah_t1 = 0;
                                        }
                                        else{
                                            printf("\n\nA: Ke kiri\nS: Ke bawah\nD: Ke kanan\nW: Ke Atas\n\nK: Ke menu\n"); gerak = getch();
                                            system("cls");
                                        }

                                    } while(selesai < 1);

                                    //Waktu akhir
                                    time(&waktu_selesai);

                                    //Selisih wakti
                                    selisih_waktu = difftime(waktu_selesai, waktu_mulai);

                                    //Menunjukan pemain waktu dia menyelesaikan tingkatan
                                    if(ambil_waktu == 1){
                                        printf("\nWaktu anda menyelesaikan labirin %0.0f detik\n\nTekan apa saja untuk melanjutkan", selisih_waktu);
                                        getch();
                                    }

                                    //Waktu terbaik
                                    if(ambil_waktu == 1){
                                        if(waktu_2 < 1){
                                            waktu_2 = selisih_waktu;
                                        }
                                        else{
                                            if(waktu_2 > selisih_waktu){
                                                waktu_2 = selisih_waktu;
                                            }
                                        }

                                        ambil_waktu = 0;
                                    }

                                break;
                            }

                            break;

                        case '3':

                            //Kalau dia milih 3 apa tingkatnya sudah terbuka atau belum
                            switch(tingkat2){
                                case 0:
                                    sal_tingkat = 1;
                                    break;

                                case 1:

                                    system("cls");

                                    int xa1=0, xa2=0, xa3=0, xa4=0, xa5=0, xa6=0, xa7=0, xa8=0, xa9=0, xa10=0, xa11=0, xa12=0, xa13=0, xa14=0, xa15=0;
                                    int xb1=0, xb2=0, xb3=0, xb4=0, xb5=0, xb6=0, xb7=0, xb8=0, xb9=0, xb10=0, xb11=0, xb12=0, xb13=0, xb14=0, xb15=0;
                                    int xc1=0, xc2=0, xc3=0, xc4=0, xc5=0, xc6=0, xc7=0, xc8=0, xc9=0, xc10=0, xc11=0, xc12=0, xc13=0, xc14=0, xc15=0;
                                    int xd1=0, xd2=0, xd3=0, xd4=0, xd5=0, xd6=0, xd7=0, xd8=0, xd9=0, xd10=0, xd11=0, xd12=0, xd13=0, xd14=0, xd15=0;
                                    int xe1=0, xe2=0, xe3=0, xe4=0, xe5=0, xe6=0, xe7=0, xe8=0, xe9=0, xe10=0, xe11=0, xe12=0, xe13=0, xe14=0, xe15=0;
                                    int xf1=0, xf2=0, xf3=0, xf4=0, xf5=0, xf6=0, xf7=0, xf8=0, xf9=0, xf10=0, xf11=0, xf12=0, xf13=0, xf14=0, xf15=0;
                                    int xg1=0, xg2=0, xg3=0, xg4=0, xg5=0, xg6=0, xg7=0, xg8=0, xg9=0, xg10=0, xg11=0, xg12=0, xg13=0, xg14=0, xg15=0;
                                    int xh1=0, xh2=0, xh3=0, xh4=0, xh5=0, xh6=0, xh7=0, xh8=0, xh9=0, xh10=0, xh11=0, xh12=0, xh13=0, xh14=0, xh15=0;
                                    int xi1=0, xi2=0, xi3=0, xi4=0, xi5=0, xi6=0, xi7=0, xi8=0, xi9=0, xi10=0, xi11=0, xi12=0, xi13=0, xi14=0, xi15=0;

                                    char a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15;
                                    char b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15;
                                    char c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15;
                                    char d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15;
                                    char e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15;
                                    char f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15;
                                    char g1, g2, g3, g4, g5, g6, g7, g8, g9, g10, g11, g12, g13, g14, g15;
                                    char h1, h2, h3, h4, h5, h6, h7, h8, h9, h10, h11, h12, h13, h14, h15;
                                    char i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15;
                                    char gerak, ke_menu;

                                    //Peta
                                    a1='='; a2='='; a3='='; a4='='; a5='='; a6='='; a7='='; a8='='; a9='='; a10='='; a11='='; a12='='; a13='='; a14='='; //a15;
                                    b1='|'; b2=' '; b3=' '; b4=' '; b5=' '; b6=' '; b7=' '; b8=' '; b9=' '; b10=' '; b11=' '; b12=' '; b13=' '; b14=' '; //b15;
                                    c1='|'; c2=' '; c3='='; c4='='; c5='='; c6='='; c7='='; c8='='; c9='='; c10='='; c11='='; c12='='; c13='='; c14='|'; //c15;
                                    d1='|'; d2=' '; d3=' '; d4=' '; d5='|'; d6=' '; d7=' '; d8=' '; d9=' '; d10=' '; d11=' '; d12=' '; d13=' '; d14='|'; //d15;
                                    e1='|'; e2='='; e3='='; e4=' '; e5='|'; e6=' '; e7='='; e8='='; e9='|'; e10=' '; e11='='; e12='='; e13='='; e14='|'; //e15;
                                    f1='|'; f2=' '; f3=' '; f4=' '; f5='|'; f6=' '; f7=' '; f8=' '; f9='|'; f10=' '; f11=' '; f12=' '; f13=' '; f14=' '; //f15;
                                    g1='|'; g2=' '; g3='='; g4='='; g5='|'; g6='='; g7='='; g8=' '; g9='|'; g10='='; g11='='; g12='='; g13='='; g14='|'; //g15;
                                    h1='|'; h2=' '; h3=' '; h4=' '; h5=' '; h6=' '; h7=' '; h8=' '; h9=' '; h10=' '; h11=' '; h12=' '; h13=' '; h14='|'; //h15;
                                    i1='|', i2='=', i3='=', i4='=', i5='=', i6='=', i7='=', i8='=', i9='=', i10='=', i11='=', i12='=', i13='=', i14='|', //i15;

                                    //Nilai awal
                                    gerak = '\0'; selesai = 0; salah_t1 = 0; langkah = 1; tulisan = 0;

                                    //Memberi posisi
                                    b14 = 'H';



                                    do{

                                        //Dinding yang menghilang
                                        switch(langkah){
                                            case 1:
                                            case 2:
                                            case 3:
                                                a1='='; a2='='; a3='='; a4='='; a5='='; a6='='; a7='='; a8='='; a9='='; a10='='; a11='='; a12='='; a13='='; a14='='; //a15;
                                                b1='|'; //b15;
                                                c1='|'; c3='='; c4='='; c5='='; c6='='; c7='='; c8='='; c9='='; c10='='; c11='='; c12='='; c13='='; c14='|'; //c15;
                                                d1='|'; d5='|'; d14='|'; //d15;
                                                e1='|'; e2='='; e3='='; e5='|'; e7='='; e8='='; e9='|'; e11='='; e12='='; e13='='; e14='|'; //e15;
                                                f1='|'; f5='|'; f9='|'; //f15;
                                                g1='|'; g3='='; g4='='; g5='|'; g6='='; g7='='; g9='|'; g10='='; g11='='; g12='='; g13='='; g14='|'; //g15;
                                                h1='|'; h14='|'; //h15;
                                                i1='|'; i2='='; i3='='; i4='='; i5='='; i6='='; i7='|'; i8='='; i9='='; i10='='; i11='='; i12='='; i13='='; i14='|'; //i15;
                                                break;
                                            case 4:
                                                tulisan = 1;
                                            case 5:
                                            case 6:
                                                a1=' '; a2=' '; a3=' '; a4=' '; a5=' '; a6=' '; a7=' '; a8=' '; a9=' '; a10=' '; a11=' '; a12=' '; a13=' '; a14=' '; //a15;
                                                b1=' '; //b15;
                                                c1=' '; c3=' '; c4=' '; c5=' '; c6=' '; c7=' '; c8=' '; c9=' '; c10=' '; c11=' '; c12=' '; c13=' '; c14=' '; //c15;
                                                d1=' '; d5=' '; d14=' '; //d15;
                                                e1=' '; e2=' '; e3=' '; e5=' '; e7=' '; e8=' '; e9=' '; e11=' '; e12=' '; e13=' '; e14=' '; //e15;
                                                f1=' '; f5=' '; f9=' '; //f15;
                                                g1=' '; g3=' '; g4=' '; g5=' '; g6=' '; g7=' '; g9=' '; g10=' '; g11=' '; g12=' '; g13=' '; g14=' '; //g15;
                                                h1=' '; h14=' '; //h15;
                                                i1=' '; i2=' '; i3=' '; i4=' '; i5=' '; i6=' '; i7=' '; i8=' '; i9=' '; i10=' '; i11=' '; i12=' '; i13=' '; i14=' '; //i15;
                                                break;
                                            case 7:
                                                tulisan = 2;
                                            case 8:
                                            case 9:
                                            case 10:
                                                a1='='; a2='='; a3='='; a4='='; a5='='; a6='='; a7='='; a8='='; a9='='; a10='='; a11='='; a12='='; a13='='; a14='='; //a15;
                                                b1='|'; //b15;
                                                c1='|'; c3='='; c4='='; c5='='; c6='='; c7='='; c8='='; c9='='; c10='='; c11='='; c12='='; c13='='; c14='|'; //c15;
                                                d1='|'; d5='|'; d14='|'; //d15;
                                                e1='|'; e2='='; e3='='; e5='|'; e7='='; e8='='; e9='|'; e11='='; e12='='; e13='='; e14='|'; //e15;
                                                f1='|'; f5='|'; f9='|'; //f15;
                                                g1='|'; g3='='; g4='='; g5='|'; g6='='; g7='='; g9='|'; g10='='; g11='='; g12='='; g13='='; g14='|'; //g15;
                                                h1='|'; h14='|'; //h15;
                                                i1='|'; i2='='; i3='='; i4='='; i5='='; i6='='; i7='|'; i8='='; i9='='; i10='='; i11='='; i12='='; i13='='; i14='|'; //i15;
                                                break;
                                            case 11:
                                                tulisan = 3;
                                                a1=' '; a2=' '; a3=' '; a4=' '; a5=' '; a6=' '; a7=' '; a8=' '; a9=' '; a10=' '; a11=' '; a12=' '; a13=' '; a14=' '; //a15;
                                                b1=' '; //b15;
                                                c1=' '; c3=' '; c4=' '; c5=' '; c6=' '; c7=' '; c8=' '; c9=' '; c10=' '; c11=' '; c12=' '; c13=' '; c14=' '; //c15;
                                                d1=' '; d5=' '; d14=' '; //d15;
                                                e1=' '; e2=' '; e3=' '; e5=' '; e7=' '; e8=' '; e9=' '; e11=' '; e12=' '; e13=' '; e14=' '; //e15;
                                                f1=' '; f5=' '; f9=' '; //f15;
                                                g1=' '; g3=' '; g4=' '; g5=' '; g6=' '; g7=' '; g9=' '; g10=' '; g11=' '; g12=' '; g13=' '; g14=' '; //g15;
                                                h1=' '; h14=' '; //h15;
                                                i1=' '; i2=' '; i3=' '; i4=' '; i5=' '; i6=' '; i7=' '; i8=' '; i9=' '; i10=' '; i11=' '; i12=' '; i13=' '; i14=' '; //i15;
                                                break;
                                            default :
                                                a1=' '; a2=' '; a3=' '; a4=' '; a5=' '; a6=' '; a7=' '; a8=' '; a9=' '; a10=' '; a11=' '; a12=' '; a13=' '; a14=' '; //a15;
                                                b1=' '; //b15;
                                                c1=' '; c3=' '; c4=' '; c5=' '; c6=' '; c7=' '; c8=' '; c9=' '; c10=' '; c11=' '; c12=' '; c13=' '; c14=' '; //c15;
                                                d1=' '; d5=' '; d14=' '; //d15;
                                                e1=' '; e2=' '; e3=' '; e5=' '; e7=' '; e8=' '; e9=' '; e11=' '; e12=' '; e13=' '; e14=' '; //e15;
                                                f1=' '; f5=' '; f9=' '; //f15;
                                                g1=' '; g3=' '; g4=' '; g5=' '; g6=' '; g7=' '; g9=' '; g10=' '; g11=' '; g12=' '; g13=' '; g14=' '; //g15;
                                                h1=' '; h14=' '; //h15;
                                                i1=' '; i2=' '; i3=' '; i4=' '; i5=' '; i6=' '; i7=' '; i8=' '; i9=' '; i10=' '; i11=' '; i12=' '; i13=' '; i14=' '; //i15;
                                                break;
                                        }


                                        //Pergerakan
                                        if(b2 == 'H'){                     //keadaan b
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    a2 = 'H'; b2 = '.'; xb2 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    b1 = 'H'; b2 = '.'; xb2 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    c2 = 'H'; b2 = '.'; xb2 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    b3 = 'H'; b2 = '.'; xb2 = 1;
                                                    break;
                                            }
                                        }
                                        else if(b3 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    a3 = 'H'; b3 = '.'; xb3 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    b2 = 'H'; b3 = '.'; xb3 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    c3 = 'H'; b3 = '.'; xb3 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    b4 = 'H'; b3 = '.'; xb3 = 1;
                                                    break;
                                            }
                                        }
                                        else if(b4 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    a4 = 'H'; b4 = '.'; xb4 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    b3 = 'H'; b4 = '.'; xb4 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    c4 = 'H'; b4 = '.'; xb4 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    b5 = 'H'; b4 = '.'; xb4 = 1;
                                                    break;
                                            }
                                        }
                                        else if(b5 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    a5 = 'H'; b5 = '.'; xb5 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    b4 = 'H'; b5 = '.'; xb5 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    c5 = 'H'; b5 = '.'; xb5 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    b6 = 'H'; b5 = '.'; xb5 = 1;
                                                    break;
                                            }
                                        }
                                        else if(b6 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    a6 = 'H'; b6 = '.'; xb6 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    b5 = 'H'; b6 = '.'; xb6 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    c6 = 'H'; b6 = '.'; xb6 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    b7 = 'H'; b6 = '.'; xb6 = 1;
                                                    break;
                                            }
                                        }
                                        else if(b7 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    a7 = 'H'; b7 = '.'; xb7 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    b6 = 'H'; b7 = '.'; xb7 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    c7 = 'H'; b7 = '.'; xb7 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    b8 = 'H'; b7 = '.'; xb7 = 1;
                                                    break;
                                            }
                                        }
                                        else if(b8 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    a8 = 'H'; b8 = '.'; xb8 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    b7 = 'H'; b8 = '.'; xb8 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    c8 = 'H'; b8 = '.'; xb8 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    b9 = 'H'; b8 = '.'; xb8 = 1;
                                                    break;
                                            }
                                        }
                                        else if(b9 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    a9 = 'H'; b9 = '.'; xb9 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    b8 = 'H'; b9 = '.'; xb9 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    c9 = 'H'; b9 = '.'; xb9 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    b10 = 'H'; b9 = '.'; xb9 = 1;
                                                    break;
                                            }
                                        }
                                        else if(b10 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    a10 = 'H'; b10 = '.'; xb10 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    b9 = 'H'; b10 = '.'; xb10 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    c10 = 'H'; b10 = '.'; xb10 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    b11 = 'H'; b10 = '.'; xb10 = 1;
                                                    break;
                                            }
                                        }
                                        else if(b11 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    a11 = 'H'; b11 = '.'; xb11 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    b10 = 'H'; b11 = '.'; xb11 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    c11 = 'H'; b11 = '.'; xb11 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    b12 = 'H'; b11 = '.'; xb11 = 1;
                                                    break;
                                            }
                                        }
                                        else if(b12 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    a12 = 'H'; b12 = '.'; xb12 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    b11 = 'H'; b12 = '.'; xb12 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    c12 = 'H'; b12 = '.'; xb12 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    b13 = 'H'; b12 = '.'; xb12 = 1;
                                                    break;
                                            }
                                        }
                                        else if(b13 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    a13 = 'H'; b13 = '.'; xb13 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    b12 = 'H'; b13 = '.'; xb13 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    c13 = 'H'; b13 = '.'; xb13 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    b14 = 'H'; b13 = '.'; xb13 = 1;
                                                    break;
                                            }
                                        }
                                        else if(b14 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    a14 = 'H'; b14 = '.'; xb14 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    b13 = 'H'; b14 = '.'; xb14 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    c14 = 'H'; b14 = '.'; xb14 = 1;
                                                    break;
                                                /*case 'D':
                                                case 'd':
                                                    b15 = 'H'; b14 = '.'; xb14 = 1;
                                                    break;*/
                                            }
                                        }
                                        else if(c2 == 'H'){                                          //keadaan c
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    b2 = 'H'; c2 = '.'; xc2 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    c1 = 'H'; c2 = '.'; xc2 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    d2 = 'H'; c2 = '.'; xc2 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    c3 = 'H'; c2 = '.'; xc2 = 1;
                                                    break;
                                            }
                                        }
                                        /*else if(c13 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    b13 = 'H'; c13 = ' '; xc13 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    c12 = 'H'; c13 = ' '; xc13 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    d13 = 'H'; c13 = ' '; xc13 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    c14 = 'H'; c13 = ' '; xc13 = 1;
                                                    break;
                                            }
                                        }*/
                                        else if(d2 == 'H'){                                             //keadaan d
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    c2 = 'H'; d2 = '.'; xd2 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    d1 = 'H'; d2 = '.'; xd2 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    e2 = 'H'; d2 = '.'; xd2 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    d3 = 'H'; d2 = '.'; xd2 = 1;
                                                    break;
                                            }
                                        }
                                        else if(d3 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    c3 = 'H'; d3 = '.'; xd3 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    d2 = 'H'; d3 = '.'; xd3 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    e3 = 'H'; d3 = '.'; xd3 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    d4 = 'H'; d3 = '.'; xd3 = 1;
                                                    break;
                                            }
                                        }
                                        else if(d4 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    c4 = 'H'; d4 = '.'; xd4 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    d3 = 'H'; d4 = '.'; xd4 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    e4 = 'H'; d4 = '.'; xd4 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    d5 = 'H'; d4 = '.'; xd4 = 1;
                                                    break;
                                            }
                                        }
                                        else if(d6 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    c6 = 'H'; d6 = '.'; xd6 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    d5 = 'H'; d6 = '.'; xd6 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    e6 = 'H'; d6 = '.'; xd6 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    d7 = 'H'; d6 = '.'; xd6 = 1;
                                                    break;
                                            }
                                        }
                                        else if(d7 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    c7 = 'H'; d7 = '.'; xd7 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    d6 = 'H'; d7 = '.'; xd7 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    e7 = 'H'; d7 = '.'; xd7 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    d8 = 'H'; d7 = '.'; xd7 = 1;
                                                    break;
                                            }
                                        }
                                        else if(d8 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    c8 = 'H'; d8 = '.'; xd8 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    d7 = 'H'; d8 = '.'; xd8 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    e8 = 'H'; d8 = '.'; xd8 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    d9 = 'H'; d8 = '.'; xd8 = 1;
                                                    break;
                                            }
                                        }
                                        else if(d9 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    c9 = 'H'; d9 = '.'; xd9 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    d8 = 'H'; d9 = '.'; xd9 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    e9 = 'H'; d9 = '.'; xd9 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    d10 = 'H'; d9 = '.'; xd9 = 1;
                                                    break;
                                            }
                                        }
                                        else if(d10 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    c10 = 'H'; d10 = '.'; xd10 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    d9 = 'H'; d10 = '.'; xd10 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    e10 = 'H'; d10 = '.'; xd10 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    d11 = 'H'; d10 = '.'; xd10 = 1;
                                                    break;
                                            }
                                        }
                                        else if(d11 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    c11 = 'H'; d11 = '.'; xd11 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    d10 = 'H'; d11 = '.'; xd11 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    e11 = 'H'; d11 = '.'; xd11 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    d12 = 'H'; d11 = '.'; xd11 = 1;
                                                    break;
                                            }
                                        }
                                        else if(d12 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    c12 = 'H'; d12 = '.'; xd12 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    d11 = 'H'; d12 = '.'; xd12 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    e12 = 'H'; d12 = '.'; xd12 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    d13 = 'H'; d12 = '.'; xd12 = 1;
                                                    break;
                                            }
                                        }
                                        else if(d13 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    c13 = 'H'; d13 = '.'; xd13 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    d12 = 'H'; d13 = '.'; xd13 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    e13 = 'H'; d13 = '.'; xd13 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    d14 = 'H'; d13 = '.'; xd13 = 1;
                                                    break;
                                            }
                                        }
                                        else if(e4 == 'H'){                                          //keadaan e
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    d4 = 'H'; e4 = '.'; xe4 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    e3 = 'H'; e4 = '.'; xe4 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    f4 = 'H'; e4 = '.'; xe4 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    e5 = 'H'; e4 = '.'; xe4 = 1;
                                                    break;
                                            }
                                        }
                                        else if(e6 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    d6 = 'H'; e6 = '.'; xe6 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    e5 = 'H'; e6 = '.'; xe6 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    f6 = 'H'; e6 = '.'; xe6 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    e7 = 'H'; e6 = '.'; xe6 = 1;
                                                    break;
                                            }
                                        }
                                        else if(e8 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    d8 = 'H'; e8 = '.'; xe8 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    e7 = 'H'; e8 = '.'; xe8 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    f8 = 'H'; e8 = '.'; xe8 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    e9 = 'H'; e8 = '.'; xe8 = 1;
                                                    break;
                                            }
                                        }
                                        else if(e10 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    d10 = 'H'; e10 = '.'; xe10 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    e9 = 'H'; e10 = '.'; xe10 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    f10 = 'H'; e10 = '.'; xe10 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    e11 = 'H'; e10 = '.'; xe10 = 1;
                                                    break;
                                            }
                                        }
                                        else if(f2 == 'H'){                                          //keadaan f
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    e2 = 'H'; f2 = '.'; xf2 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    f1 = 'H'; f2 = '.'; xf2 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    g2 = 'H'; f2 = '.'; xf2 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    f3 = 'H'; f2 = '.'; xf2 = 1;
                                                    break;
                                            }
                                        }
                                        else if(f3 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    e3 = 'H'; f3 = '.'; xf3 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    f2 = 'H'; f3 = '.'; xf3 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    g3 = 'H'; f3 = '.'; xf3 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    f4 = 'H'; f3 = '.'; xf3 = 1;
                                                    break;
                                            }
                                        }
                                        else if(f4 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    e4 = 'H'; f4 = '.'; xf4 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    f3 = 'H'; f4 = '.'; xf4 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    g4 = 'H'; f4 = '.'; xf4 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    f5 = 'H'; f4 = '.'; xf4 = 1;
                                                    break;
                                            }
                                        }
                                        /*else if(f5 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    e5 = 'H'; f5 = ' '; xf5 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    f4 = 'H'; f5 = ' '; xf5 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    g5 = 'H'; f5 = ' '; xf5 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    f6 = 'H'; f5 = ' '; xf5 = 1;
                                                    break;
                                            }
                                        }*/
                                        else if(f6 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    e6 = 'H'; f6 = '.'; xf6 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    f5 = 'H'; f6 = '.'; xf6 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    g6 = 'H'; f6 = '.'; xf6 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    f7 = 'H'; f6 = '.'; xf6 = 1;
                                                    break;
                                            }
                                        }
                                        else if(f7 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    e7 = 'H'; f7 = '.'; xf7 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    f6 = 'H'; f7 = '.'; xf7 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    g7 = 'H'; f7 = '.'; xf7 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    f8 = 'H'; f7 = '.'; xf7 = 1;
                                                    break;
                                            }
                                        }
                                        else if(f8 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    e8 = 'H'; f8 = '.'; xf8 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    f7 = 'H'; f8 = '.'; xf8 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    g8 = 'H'; f8 = '.'; xf8 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    f9 = 'H'; f8 = '.'; xf8 = 1;
                                                    break;
                                            }
                                        }
                                        else if(f10 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    e10 = 'H'; f10 = '.'; xf10 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    f9 = 'H'; f10 = '.'; xf10 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    g10 = 'H'; f10 = '.'; xf10 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    f11 = 'H'; f10 = '.'; xf10 = 1;
                                                    break;
                                            }
                                        }
                                        else if(f11 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    e11 = 'H'; f11 = '.'; xf11 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    f10 = 'H'; f11 = '.'; xf11 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    g11 = 'H'; f11 = '.'; xf11 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    f12 = 'H'; f11 = '.'; xf11 = 1;
                                                    break;
                                            }
                                        }
                                        else if(f12 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    e12 = 'H'; f12 = '.'; xf12 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    f11 = 'H'; f12 = '.'; xf12 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    g12 = 'H'; f12 = '.'; xf12 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    f13 = 'H'; f12 = '.'; xf12 = 1;
                                                    break;
                                            }
                                        }
                                        else if(f13 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    e13 = 'H'; f13 = '.'; xf13 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    f12 = 'H'; f13 = '.'; xf13 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    g13 = 'H'; f13 = '.'; xf13 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    f14 = 'H'; f13 = '.'; xf13 = 1;
                                                    break;
                                            }
                                        }
                                        /*else if(f14 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    e14 = 'H'; f14 = ' '; xf14 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    f13 = 'H'; f14 = ' '; xf14 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    g14 = 'H'; f14 = ' '; xf14 = 1;
                                                    break;
                                                /*case 'D':
                                                case 'd':
                                                    f4 = 'H'; f3 = ' ';
                                                    break;
                                            }
                                        }*/
                                        else if(g2 == 'H'){                                          //keadaan g
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    f2 = 'H'; g2 = '.'; xg2 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    g1 = 'H'; g2 = '.'; xg2 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    h2 = 'H'; g2 = '.'; xg2 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    g3 = 'H'; g2 = '.'; xg2 = 1;
                                                    break;
                                            }
                                        }
                                        else if(g4 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    f4 = 'H'; g4 = '.'; xg4 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    g3 = 'H'; g4 = '.'; xg4 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    h4 = 'H'; g4 = '.'; xg4 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    g5 = 'H'; g4 = '.'; xg4 = 1;
                                                    break;
                                            }
                                        }
                                        else if(g6 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    f6 = 'H'; g6 = '.'; xg6 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    g5 = 'H'; g6 = '.'; xg6 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    h6 = 'H'; g6 = '.'; xg6 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    g7 = 'H'; g6 = '.'; xg6 = 1;
                                                    break;
                                            }
                                        }
                                        else if(g8 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    f8 = 'H'; g8 = '.'; xg8 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    g7 = 'H'; g8 = '.'; xg8 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    h8 = 'H'; g8 = '.'; xg8 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    g9 = 'H'; g8 = '.'; xg8 = 1;
                                                    break;
                                            }
                                        }
                                        else if(g13 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    f13 = 'H'; g13 = '.'; xg13 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    g12 = 'H'; g13 = '.'; xg13 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    h13 = 'H'; g13 = '.'; xg13 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    g14 = 'H'; g13 = '.'; xg13 = 1;
                                                    break;
                                            }
                                        }
                                        else if(h2 == 'H'){                                              //keadaan h
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    g2 = 'H'; h2 = '.'; xh2 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    h1 = 'H'; h2 = '.'; xh2 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    i2 = 'H'; h2 = '.'; xh2 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    h3 = 'H'; h2 = '.'; xh2 = 1;
                                                    break;
                                            }
                                        }
                                        else if(h3 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    g3 = 'H'; h3 = '.'; xh3 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    h2 = 'H'; h3 = '.'; xh3 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    i3 = 'H'; h3 = '.'; xh3 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    h4 = 'H'; h3 = '.'; xh3 = 1;
                                                    break;
                                            }
                                        }
                                        else if(h4 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    g4 = 'H'; h4 = '.'; xh4 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    h3 = 'H'; h4 = '.'; xh4 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    i4 = 'H'; h4 = '.'; xh4 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    h5 = 'H'; h4 = '.'; xh4 = 1;
                                                    break;
                                            }
                                        }
                                        else if(h5 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    g5 = 'H'; h5 = '.'; xh5 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    h4 = 'H'; h5 = '.'; xh5 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    i5 = 'H'; h5 = '.'; xh5 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    h6 = 'H'; h5 = '.'; xh5 = 1;
                                                    break;
                                            }
                                        }
                                        else if(h6 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    g6 = 'H'; h6 = '.'; xh6 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    h5 = 'H'; h6 = '.'; xh6 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    i6 = 'H'; h6 = '.'; xh6 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    h7 = 'H'; h6 = '.'; xh6 = 1;
                                                    break;
                                            }
                                        }
                                        else if(h7 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    g7 = 'H'; h7 = '.'; xh7 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    h6 = 'H'; h7 = '.'; xh7 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    i7 = 'H'; h7 = '.'; xh7 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    h8 = 'H'; h7 = '.'; xh7 = 1;
                                                    break;
                                            }
                                        }
                                        else if(h8 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    g8 = 'H'; h8 = '.'; xh8 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    h7 = 'H'; h8 = '.'; xh8 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    i8 = 'H'; h8 = '.'; xh8 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    h9 = 'H'; h8 = '.'; xh8 = 1;
                                                    break;
                                            }
                                        }
                                        else if(h9 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    g9 = 'H'; h9 = '.'; xh9 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    h8 = 'H'; h9 = '.'; xh9 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    i9 = 'H'; h9 = '.'; xh9 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    h10 = 'H'; h9 = '.'; xh9 = 1;
                                                    break;
                                            }
                                        }
                                        else if(h10 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    g10 = 'H'; h10 = '.'; xh10 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    h9 = 'H'; h10 = '.'; xh10 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    i10 = 'H'; h10 = '.'; xh10 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    h11 = 'H'; h10 = '.'; xh10 = 1;
                                                    break;
                                            }
                                        }
                                        else if(h11 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    g11 = 'H'; h11 = '.'; xh11 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    h10 = 'H'; h11 = '.'; xh11 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    i11 = 'H'; h11 = '.'; xh11 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    h12 = 'H'; h11 = '.'; xh11 = 1;
                                                    break;
                                            }
                                        }
                                        else if(h12 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    g12 = 'H'; h12 = '.'; xh12 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    h11 = 'H'; h12 = '.'; xh12 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    i12 = 'H'; h12 = '.'; xh12 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    h13 = 'H'; h12 = '.'; xh12 = 1;
                                                    break;
                                            }
                                        }
                                        else if(h13 == 'H'){
                                            switch(gerak){
                                                case 'W':
                                                case 'w':
                                                    g13 = 'H'; h13 = '.'; xh13 = 1;
                                                    break;
                                                case 'A':
                                                case 'a':
                                                    h12 = 'H'; h13 = '.'; xh13 = 1;
                                                    break;
                                                case 'S':
                                                case 's':
                                                    i13 = 'H'; h13 = '.'; xh13 = 1;
                                                    break;
                                                case 'D':
                                                case 'd':
                                                    h14 = 'H'; h13 = '.'; xh13 = 1;
                                                    break;
                                            }
                                        }

                                        //Tampilan permainan
                                        printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14);
                                        printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14);
                                        printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14);
                                        printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14);
                                        printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14);
                                        printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14);
                                        printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", g1, g2, g3, g4, g5, g6, g7, g8, g9, g10, g11, g12, g13, g14);
                                        printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", h1, h2, h3, h4, h5, h6, h7, h8, h9, h10, h11, h12, h13, h14);
                                        printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14);

                                        //Membuat nilai jika menabrak dinding
                                        if(a1=='H'||a2=='H'||a3=='H'||a4=='H'||a5=='H'||a6=='H'||a7=='H'||a8=='H'||a9=='H'||a10=='H'||a11=='H'||a12=='H'||a13=='H'||a14=='H'){
                                            salah_t1 = 1;
                                        }
                                        else if(b1=='H'){
                                            salah_t1 = 1;
                                        }
                                        else if(c1=='H'||c3=='H'||c4=='H'||c5=='H'||c6=='H'||c7=='H'||c8=='H'||c9=='H'||c10=='H'||c11=='H'||c12=='H'||c13=='H'||c14=='H'){
                                            salah_t1 = 1;
                                        }
                                        else if(d1=='H'||d5=='H'||d14=='H'){
                                            salah_t1 = 1;
                                        }
                                        else if(e1=='H'||e2=='H'||e3=='H'||e5=='H'||e7=='H'||e8=='H'||e9=='H'||e11=='H'||e12=='H'||e13=='H'||e14=='H'){
                                            salah_t1 = 1;
                                        }
                                        else if(f1=='H'||f5=='H'||f9=='H'){
                                            salah_t1 = 1;
                                        }
                                        else if(g1=='H'||g3=='H'||g5=='H'||g6=='H'||g7=='H'||g9=='H'||g10=='H'||g11=='H'||g12=='H'||g14=='H'){
                                            salah_t1 = 1;
                                        }
                                        else if(h1=='H'|| h14=='H'){
                                            salah_t1 = 1;
                                        }
                                        else if(i1=='H'||i2=='H'||i3=='H'||i4=='H'||i5=='H'||i6=='H'||i7=='H'||i8=='H'||i9=='H'||i10=='H'||i11=='H'||i12=='H'||i13=='H'||i14=='H'){
                                            salah_t1 = 1;
                                        }

                                        //Proses saat menginjak titik
                                        if(b2=='H' && xb2==1){ salah_t1 = 3;} //B
                                        else if(b3=='H' && xb3==1){ salah_t1 = 3;}
                                        else if(b4=='H' && xb4==1){ salah_t1 = 3;}
                                        else if(b5=='H' && xb5==1){ salah_t1 = 3;}
                                        else if(b6=='H' && xb6==1){ salah_t1 = 3;}
                                        else if(b7=='H' && xb7==1){ salah_t1 = 3;}
                                        else if(b8=='H' && xb8==1){ salah_t1 = 3;}
                                        else if(b9=='H' && xb9==1){ salah_t1 = 3;}
                                        else if(b10=='H' && xb10==1){ salah_t1 = 3;}
                                        else if(b11=='H' && xb11==1){ salah_t1 = 3;}
                                        else if(b12=='H' && xb12==1){ salah_t1 = 3;}
                                        else if(b13=='H' && xb13==1){ salah_t1 = 3;}
                                        else if(b14=='H' && xb14==1){ salah_t1 = 3;}
                                        else if(c2=='H' && xc2==1){ salah_t1 = 3;} //C
                                        else if(d2=='H' && xd2==1){ salah_t1 = 3;} //D
                                        else if(d3=='H' && xd3==1){ salah_t1 = 3;}
                                        else if(d4=='H' && xd4==1){ salah_t1 = 3;}
                                        else if(d6=='H' && xd6==1){ salah_t1 = 3;}
                                        else if(d7=='H' && xd7==1){ salah_t1 = 3;}
                                        else if(d8=='H' && xd8==1){ salah_t1 = 3;}
                                        else if(d9=='H' && xd9==1){ salah_t1 = 3;}
                                        else if(d10=='H' && xd10==1){ salah_t1 = 3;}
                                        else if(d11=='H' && xd11==1){ salah_t1 = 3;}
                                        else if(d12=='H' && xd12==1){ salah_t1 = 3;}
                                        else if(d13=='H' && xd13==1){ salah_t1 = 3;}
                                        else if(e4=='H' && xe4==1){ salah_t1 = 3;} //E
                                        else if(e6=='H' && xe6==1){ salah_t1 = 3;}
                                        else if(e8=='H' && xe8==1){ salah_t1 = 3;}
                                        else if(e10=='H' && xe10==1){ salah_t1 = 3;}
                                        else if(f2=='H' && xf2==1){ salah_t1 = 3;} //F
                                        else if(f3=='H' && xf3==1){ salah_t1 = 3;}
                                        else if(f4=='H' && xf4==1){ salah_t1 = 3;}
                                        else if(f6=='H' && xf6==1){ salah_t1 = 3;}
                                        else if(f7=='H' && xf7==1){ salah_t1 = 3;}
                                        else if(f8=='H' && xf8==1){ salah_t1 = 3;}
                                        else if(f10=='H' && xf10==1){ salah_t1 = 3;}
                                        else if(f11=='H' && xf11==1){ salah_t1 = 3;}
                                        else if(f12=='H' && xf12==1){ salah_t1 = 3;}
                                        else if(f13=='H' && xf13==1){ salah_t1 = 3;}
                                        else if(g2=='H' && xg2==1){ salah_t1 = 3;} //G
                                        else if(g4=='H' && xg4==1){ salah_t1 = 3;}
                                        else if(g6=='H' && xg6==1){ salah_t1 = 3;}
                                        else if(g8=='H' && xg8==1){ salah_t1 = 3;}
                                        else if(g13=='H' && xg13==1){ salah_t1 = 3;}
                                        else if(h2=='H' && xh2==1){ salah_t1 = 3;} //H
                                        else if(h3=='H' && xh3==1){ salah_t1 = 3;}
                                        else if(h4=='H' && xh4==1){ salah_t1 = 3;}
                                        else if(h5=='H' && xh5==1){ salah_t1 = 3;}
                                        else if(h6=='H' && xh6==1){ salah_t1 = 3;}
                                        else if(h8=='H' && xh8==1){ salah_t1 = 3;}
                                        else if(h9=='H' && xh9==1){ salah_t1 = 3;}
                                        else if(h10=='H' && xh10==1){ salah_t1 = 3;}
                                        else if(h11=='H' && xh11==1){ salah_t1 = 3;}
                                        else if(h12=='H' && xh12==1){ salah_t1 = 3;}
                                        else if(h13=='H' && xh13==1){ salah_t1 = 3;}

                                        //JIka selesai menyelesaikan labirin (menang)
                                        if(f14 == 'H'){
                                            tingkat3 = 1;
                                            selesai = 1;
                                            salah_t1 = 4;
                                            printf("\nTingkat 3 selesai!\nTingkat 4 terbuka!");

                                            ambil_waktu = 1;
                                        }

                                        //Salah memasukkan masukan
                                        switch(gerak){
                                            case 'W':
                                            case 'w':
                                            case 'A':
                                            case 'a':
                                            case 'S':
                                            case 's':
                                            case 'D':
                                            case 'd':
                                            case '\0':
                                                    printf("\n");
                                                    langkah++;
                                                    break;
                                            case 'K':
                                                    case 'k':
                                                    salah_t1 = 2;
                                                    break;
                                            default:
                                                    printf("\nBukan perintah apapun!");
                                                    gerak = '\0';
                                                    break;
                                        }

                                        if(tulisan > 0 && salah_t1 == 0){
                                            //Percakapan saat mati lampu
                                            switch(tulisan){
                                                case 1:
                                                    //Ambil waktu dulu
                                                    time(&waktu_selesai);
                                                    penambah_waktu = difftime(waktu_selesai, waktu_mulai);

                                                    //Bicara
                                                    printf("\n\nPemeran:\tAhhhhh!!!!"); getch();
                                                    printf("\n\t\tKok gelap?"); getch();
                                                    printf("\n\t\tMati lampu kah? Apinya padam!!"); getch();
                                                    printf("\n\t\tSemoga lampunya menyala lagi\n\nTekan apa saja untuk melanjutkan"); getch();
                                                    tulisan = 0; gerak = '\0'; system("cls");

                                                    //Mulai waktu lagi
                                                    time(&waktu_mulai);

                                                    break;
                                                case 2:
                                                    //Ambil waktu dulu
                                                    time(&waktu_selesai);
                                                    selisih_waktu = difftime(waktu_selesai, waktu_mulai);
                                                    penambah_waktu = penambah_waktu + selisih_waktu;

                                                    //Bicara
                                                    printf("\n\nPemeran:\tWuuhh!!"); getch();
                                                    printf("\n\t\tLampunya menyala lagi!!"); getch();
                                                    printf("\n\t\tSemoga gak mati lagi.\n\nTekan apa saja untuk melanjutkan"); getch();
                                                    tulisan = 0; gerak = '\0'; system("cls");

                                                    //Mulai waktu lagi
                                                    time(&waktu_mulai);

                                                    break;
                                                case 3:
                                                    //Ambil waktu dulu
                                                    time(&waktu_selesai);
                                                    selisih_waktu = difftime(waktu_selesai, waktu_mulai);
                                                    penambah_waktu = penambah_waktu + selisih_waktu;

                                                    //BIcara
                                                    printf("\n\nPemeran:\t..."); getch();
                                                    printf("\n\t\tHmmm...."); getch();
                                                    printf("\n\t\tSemoga saja tidak ada hantu\n\nTekan apa saja untuk melanjutkan"); getch();
                                                    tulisan = 0; gerak = '\0'; system("cls");

                                                    //Mulai waktu lagi
                                                    time(&waktu_mulai);

                                                    break;
                                            }
                                        }

                                        else{
                                            //Pilihan menabrak dinding atau tidak - dilanjutkan atau tidak
                                            if(salah_t1 == 1){
                                                printf("\n\nPemeran menabrak dinding beracun!");
                                                printf("\n\nTekan apa saja untuk lanjutkan"); getch();
                                                selesai = 1;
                                            }
                                            else if(salah_t1 == 2){
                                                ke_menu = '\0';
                                                printf("\n\nAnda yakin ingin ke menu?\nY: Ya\nT: Tidak"); ke_menu = getch();

                                                //Proses masukan diatas
                                                if(ke_menu == 'Y' || ke_menu == 'y'){
                                                    selesai = 1;
                                                }
                                                else if(ke_menu == 'T' || ke_menu == 't'){
                                                    salah_t1 = 0;
                                                    gerak = '\0';
                                                    system("cls");
                                                }
                                                else{
                                                    gerak = 'X';
                                                    system("cls");
                                                }

                                            }
                                            else if(salah_t1 == 3){
                                                printf("\n\nPemeran terjatuh karena menginjak jalan rapuh!");
                                                printf("\n\nTekan apa saja untuk lanjutkan"); getch();
                                                selesai = 1;
                                            }
                                            else if(salah_t1 == 4){
                                                salah_t1 = 0;
                                            }
                                            else{
                                                printf("\n\nA: Ke kiri\nS: Ke bawah\nD: Ke kanan\nW: Ke Atas\n\nK: Ke menu\n"); gerak = getch();
                                                system("cls");
                                            }
                                        }

                                    } while(selesai < 1);

                                    //Waktu selesai
                                    time(&waktu_selesai);

                                    //Selisih waktu
                                    selisih_waktu = difftime(waktu_selesai, waktu_mulai);
                                    penambah_waktu = penambah_waktu + selisih_waktu;

                                    //Menunjukan pemain waktu dia menyelesaikan tingkatan
                                    if(ambil_waktu == 1){
                                        printf("\nWaktu anda menyelesaikan labirin %0.0f detik\n\nTekan apa saja untuk melanjutkan", penambah_waktu);
                                        getch();
                                    }

                                    //Waktu terbaik
                                    if(ambil_waktu == 1){
                                        if(waktu_3 < 1){
                                            waktu_3 = penambah_waktu;
                                        }
                                        else{
                                            if(waktu_3 > penambah_waktu){
                                                waktu_3 = penambah_waktu;
                                            }
                                        }

                                        ambil_waktu = 0;
                                    }

                                break;
                            }

                            break;

                        case '4':

                            //Kalau dia milih 4 apa tingkatnya sudah terbuka atau belum
                            switch(tingkat3){
                                case 0:
                                    sal_tingkat = 1;
                                    break;

                                case 1:
                                    system("cls");

                                    printf("Bersambung....\n\nTekan apa saja untuk kembali");
                                    getch();

                                    break;
                            }

                            break;


                        case '0':
                            system("cls");
                            break;

                        /*case '\0':
                            break;*/

                        default:
                            sal_tingkat = 1;
                            break;

                    }

                } while(pil_tingkat > '0' || pil_tingkat < '0');

                break;

            case '2': //Bantuan
                system("cls");

                //Bantuan
                printf(" =========\n");
                printf("  BANTUAN\n");
                printf(" =========\n\n");
                Sleep(500);
            	printf("Pemeran terjebak dalam mimpinya dan mengalami kesulitan untuk bangun dari\ntidurnya.");
            	Sleep(3000);
            	printf("\nIa harus menyelesaikan sebuah permaian untuk dapat terbangun dari tidurnya.\nDapatkah ia bangun dari tidurnya?\n\n");
            	Sleep(4000);
            	printf("=============================================================================\n\n");
            	printf("Petunjuk permainan:\n");
            	Sleep(1000);
            	printf("1. Ketik angka di sebelah kiri kalimat untuk memilih pilihan tersebut\n");
            	Sleep(2500);
            	printf("2. Untuk menggerakkan tokoh tekan:\n\tW untuk ke atas\n\tA untuk ke kiri\n\tS untuk ke bawah\n\tD untuk ke kanan\n");
            	Sleep(5000);
            	printf("3. Untuk menyelesaikan tingkatan pemain harus mengarahkan tokoh menuju garis\n   akhir labirin\n\n");
            	Sleep(3000);
            	printf("=============================================================================\n\n");
            	printf("Tekan apa saja untuk kembali ke menu utama");

            	getch();
            	system("cls");

            	break;

            case '3': //Waktu Terbaik
                system("cls");

                //Judul
                printf("===========\n");
                printf(" LABIRIN C\n");
                printf("===========\n\n");

                //Waktu terbaik
                printf("Waktu tercepat:\n");
                printf("Tingkat 1\t\t\t%0.0f detik\nTingkat 2\t\t\t%0.0f detik\nTingkat 3\t\t\t%0.0f detik\n", waktu_1, waktu_2, waktu_3);
                printf("\nTekan apa saja untuk ke menu utama");

                getch();
                system("cls");
                break;

            case '4': //Keluar
                system("cls");

                //Judul
                printf("===========\n");
                printf(" LABIRIN C\n");
                printf("===========\n\n");
                printf("Sampai Jumpa!\n");

                break;

            default: //Masukan salah
                sal_utama = 1;
                system("cls");

                break;
        }


    } while(pil_utama < '4' || pil_utama > '4');

    return 0;
}
