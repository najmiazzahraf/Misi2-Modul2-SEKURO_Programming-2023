#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int tampilkanMenu(){
    char tampilMenu[12][5][15] = {
        {"Id Menu", "Nama menu" , "Kategori", "Harga(k)"},
        {"a", "Ayam goreng", "makanan", "20"},
        {"b", "Ayam bakar", "makanan", "22"}, 
        {"c", "Ayam kukus", "makanan", "22"},
        {"d", "Nasi goreng", "makanan", "20"},
        {"e", "Ayam bakar", "makanan", "20"},
        {"f", "Nasi kukus", "makanan", "20"},
        {"g", "ikan goreng", "makanan", "20"},
        {"h", "mixue", "minuman", "20"},
        {"a", "Ayam kopi", "minuman", "20"},
        } ;
    for (int i = 0 ; i < 10 ; i++) {
        for (int j = 0 ; j < 4 ; j++) {
            printf("|%13s|", tampilMenu[i][j]) ;
        }
        printf("\n") ;
    }
}

char cariNamaMenu(char str[][5][15], char id) {
    int barisStr = 10, kolomStr = 4 ;
    for (int i = 0 ; i < barisStr ; i++) {
        if (str[i][0] == id) { 
            return (str[i][1]);
        }
    } 
}

int totalHarga(char str[][5][15], char id , int num) {
    int barisStr = 10, kolomStr = 4 ;
    for (int i = 0 ; i < barisStr ; i++) {
        if (str[i][0] == id) { 
            return (num * atoi((str[i][3])));
        }
    } 
}

int main() {
    char tampilMenu[12][5][15] = {
        {"Id Menu", "Nama menu" , "Kategori", "Harga(k)"},
        {"a", "Ayam goreng", "makanan", "20"},
        {"b", "Ayam bakar", "makanan", "22"}, 
        {"c", "Ayam kukus", "makanan", "22"},
        {"d", "Nasi goreng", "makanan", "20"},
        {"e", "Ayam bakar", "makanan", "20"},
        {"f", "Nasi kukus", "makanan", "20"},
        {"g", "ikan goreng", "makanan", "20"},
        {"h", "mixue", "minuman", "20"},
        {"a", "Ayam kopi", "minuman", "20"},
        } ;


    //View pemiliki toko
    int viewPemilikToko = 1 ;
    //Toko lagi buka
    int tutup = 0 ;
    //UI dengan pelanggan
    char namaPelanggan[] = "" ;
    int tampilanPelanggan;
    int pilihanPelanggan ;

    //Array untuk menyimpan riwayat

    //Variabel untuk membantu membentuk riwayat
    char idMenu; 
    int jumlahBeli;

    while (tutup == 0) {
        printf("\n\nPilihan program : \n1. Tutup , masukkan angka 1.\n2. Pelanggan masuk, masukkan angka 0.\n\nMasukkan pilihan anda : ");
        scanf("%d", &tutup) ;

        if (tutup == 0) {
            printf("Masukkan nama pelanggan : ");
            scanf("%s", namaPelanggan);
            tampilanPelanggan = 1;
            while (tampilanPelanggan == 1) {
                printf("\n\nPilihan program : \n1. Melihat menu , masukkan angka 1.\n2. Membeli makanan / minuman, masukkan angka 2.\n3. Keluar dari warung, masukkan angka 3.\n\nMasukkan pilihan anda: ");
                scanf("%d", &pilihanPelanggan);
                if (pilihanPelanggan == 1) {
                    printf("\nMenu yang tersedia :\n");
                    tampilkanMenu();
                    tampilanPelanggan = 1;
                } else if (pilihanPelanggan == 2) {
                    printf("\nMasukkan id menu : ");
                    scanf("%c%*c", &idMenu);
                    printf("\nMasukkan jumlah beli : ");
                    scanf("%d", &jumlahBeli);; 
                    tampilanPelanggan = 1 ;
                } else {
                    tampilanPelanggan = 0;
                    tutup = 0 ;
                }
            } 
        } else {
            tutup = 1;
        }
    }
    //Jika tutup = 1 
    printf("\n\nRiwayat penjualan : \n -> Nama pelanggan : %15s.\n -> Nama menu : %s.\n -> Jumlah : %d.\n -> Total harga:  ", namaPelanggan, cariNamaMenu(tampilMenu[12][5][15], idMenu), jumlahBeli);
    return 0 ;
}
