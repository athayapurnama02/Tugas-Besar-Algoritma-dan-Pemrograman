#include <stdio.h>		
#include <stdlib.h>		
#include <string.h>		
#include <time.h>		

time_t timeS;	
char fileName[]="logR.txt";

typedef struct USER {
	char nama [50];
	char email [50];
	char username [16];
	char password [8];
} user; user ppl;

typedef struct {
	char *nama[50];
	char *telepon[15];
	char *alamat[75];
} ID;

typedef struct {
	int tanggal;
	int bulan;
	int tahun;
}Date;

void waktu(){
	time(&timeS);
	struct tm* waktu = localtime(&timeS);
	FILE *hasil;
	hasil = fopen("transaction.txt", "w");
	printf (" Waktu Pemesanan   : %s", asctime (waktu));
	fprintf (hasil, " Waktu Pemesanan   : %s", asctime (waktu));
	fclose(hasil);
}

void cover(){
	printf("\t\t\t============================================================\n");
	printf("\t\t\t                                                            \n");
	printf("\t\t\t````````````````````````````````````````````````````````````\n");
	printf("\t\t\t                  SELAMAT DATANG DI SISTEM                  \n");
	printf("\t\t\t                     GREAT PHOTO STUDIO                     \n");
	printf("\t\t\t                Jl.Raya Kampus Unud Jimbaran                \n");
	printf("\t\t\t                no.telepon : (0361) XXX XXX                 \n");
	printf("\t\t\t                 email : gpstudio@gmail.com                 \n");
	printf("\t\t\t                                                            \n");
	printf("\t\t\t````````````````````````````````````````````````````````````\n");
	printf("\t\t\t============================================================\n");
	printf("\n\n\n\n");
	printf("\t\t\t Tekan enter untuk melanjutkan...");
	getchar();
	system("cls");
}

void signin(){
	void signup();
	/*  Variabel username[16] digunakan untuk menyimpan input username. 
		Inputan tersebut akan divalidasi dengan username yang sudah terdaftar pada file logR.txt   */
	char username[16];
	
	/*  Variabel password[10] digunakan untuk menyimpan input password
        yang dilakukan oleh pengguna. Inputan tersebut akan divalidasi
        dengan password yang sudah terdaftar pada file logR.txt   */
	char password[8];
	
	// Variabel pil untuk pilihan user apakah ingin mendaftar, masuk ulang, atau keluar
	int pil;
	
	// Membuat pointer record untuk menunjuk pada file "logR.txt"
	FILE *record;
	
	// Membuka file dengan mode "r"
	record = fopen (fileName, "r");

	if (record == NULL){
		printf ("Error, tidak terdapat file untuk menyimpan akun\n");
		printf ("Silahkan daftarkan akun Anda terlebih dahulu! (tekan enter)\n");
		getch();
		system("cls");
		menuUtama();
	}
	
	// Instruksi untuk login
	printf ("\t\t\t================================\n");
	printf ("\t\t\t              LOGIN             \n");
	printf ("\t\t\t================================\n");
	printf ("\t\t\t|| Username : ");
	scanf ("%s", username);
	printf ("\t\t\t|| Password : ");
	scanf ("%s", password);
	
	// Membersikan layar terminal
	system ("cls");
	
	// Membeaca file "logR.txt"
	while (fread(&ppl, sizeof(ppl),1,record)){
		 /*  Mengkomparasi username serta password yang diinput user ke dalam fungsi
            	signin() dengan username serta password yang sudah terdaftar */
		if(strcmp(username, ppl.username)==0 && strcmp(password, ppl.password)==0){
			printf ("\t\t\t================================\n");
			printf ("\t\t\t         LOGIN BERHASIL         \n");
			printf ("\t\t\t================================\n");
			getch();
			system("cls");	
		}
		//  Jika akun tidak terdaftar maka akan diberikan pilihan untuk mendaftar, masuk ulang, atau keluar
		else {
			printf ("\t\t\t================================\n");
			printf ("\t\t\t      AKUN TIDAK TERDAFTAR      \n");
			printf ("\t\t\t================================\n");
			
			menupilih:
			printf ("\t\t\t================================\n");
			printf ("\t\t\t     PILIH MENU DIBAWAH INI     \n");
			printf ("\t\t\t================================\n");
			printf ("\t\t\t|| [1] Daftar                   \n");
			printf ("\t\t\t|| [2] Masuk Ulang              \n");
			printf ("\t\t\t|| [3] Keluar                   \n");
			printf ("\t\t\t================================\n");
			printf ("\t\t\t|| Pilihan Menu : ");
			scanf ("%d", &pil);
			system ("cls");
			if (pil == 1){
				signup();
			}
			else if (pil == 2){
				signin();
			}
			else if (pil == 3){
				exit(1);
			}
			else {
				printf ("\n\t\t\t Terjadi Kesalahan! Silahkan Masukkan Pilihan dengan Benar\n");
				goto menupilih;
			}
		}
	}
	fclose (record);
	return;
}

void signup(){
	// Membuat pointer regis untuk file "loginRecord.txt"
	FILE *regis;
	// Membuka file "loginRecord.txt" dengan mode "w"
	regis = fopen(fileName, "w");
	
	//Instruksi untuk melakukan registrasi akun 
	printf ("\t\t\t================================\n");
	printf ("\t\t\t      REGISTRASI DIRI ANDA      \n");
	printf ("\t\t\t================================\n");
	getchar ();
	printf ("\n\t\t\t|| Nama Lengkap : ");
	gets (ppl.nama);
	
	int ketemu = 0;
	do{
	printf ("\n\t\t\t|| Email        : ");
	scanf ("%s", ppl.email);
	int i = 0;
	while(ppl.email[i]!='\0'){
		if(ppl.email[i]=='@'){
			ketemu++;
		}
		i++;
	}
	if(ketemu==0){
		printf("\n\t\t\t Format Penulisan Email Salah \n");
	}
	} while(ketemu==0);
	
	printf ("\n\t\t\t Hallo %s! \n", ppl.nama);
	printf ("\n\t\t\t Mari buat username (max 16 karakter), serta password (max 8 karakter) \n\n");
	
	// Instruksi untuk menginput username serta password
	printf ("\t\t\t================================\n");
	printf ("\t\t\t             SIGN UP            \n");
	printf ("\t\t\t================================\n");
	printf ("\t\t\t|| Username : ");
	scanf ("%s", ppl.username);
	printf ("\t\t\t|| Password : ");
	scanf ("%s", ppl.password);
	
	// Menuliskan nama yang diinput oleh pengguna kedalam file "loginRecord.txt"
	fwrite (&ppl, sizeof(ppl),1,regis);
	fclose (regis);
	printf ("\n\t\t\t Registrasi Selesai");
	printf ("\n\t\t\t Akun Anda Terdaftar, Mari Lakukan Login Sekarang \n");
	
	getch();
	// Membersikan layar terminal
	system("cls");
	// Memanggil fungsi signin()
	signin ();	
}

void menuUtama(){
	//variabel pil untuk menyimpan pilihan yang diinput user pada switch case
	int pil;
	
	menupilih:
	printf ("\t\t\t================================\n");
	printf ("\t\t\t      REGISTRASI DIRI ANDA      \n");
	printf ("\t\t\t================================\n");
	printf ("\t\t\t|| [1] Masuk                  ||\n");
	printf ("\t\t\t|| [2] Registrasi             ||\n");
	printf ("\t\t\t|| [3] Keluar                 ||\n");
	printf ("\t\t\t================================\n");
	printf ("\n");
	printf ("\t\t\t--------------------------------\n");
	printf ("\t\t\t|| Masukkan Pilihan Yang Tersedia : ");
	scanf ("%d", &pil);
	printf ("\t\t\t--------------------------------\n");
	system ("cls");
	
	/* Percabangan Switch dengan kondisi nilai yang disimpan pada variabel
       pil untuk menuju ke pilihan menu masuk yang diinput user  */
	switch (pil){
		case 1:
			signin();
			break;
		case 2:
			signup();
			break;
		case 3:
			exit(1);
			break;
		default:
			printf ("Terjadi Kesalahan! Silahkan Masukkan Plihan dengan Benar \n");
			break;
		goto menupilih;
	}
}

void aboutCreator(){
	char buff[100];
	FILE*pembuat;
	if((pembuat=fopen("about_creator.txt", "r"))==NULL){
		printf("Tidak ada file \n");
	}
	while(fgets(buff, sizeof(buff), pembuat)){
		printf("%s",buff);
	}
	fclose(pembuat);
}

void aboutUs(){
	char buff[100];
	FILE*GPS;
	if((GPS=fopen("aboutUs.txt", "r"))==NULL){
	printf("Tidak ada file \n");
	}
	while(fgets(buff, sizeof(buff), GPS)){
	printf("%s",buff);
	}
	fclose(GPS);
}

void iPackSelection(){
	char buff[100];
	FILE*iPackSelection;
	if((iPackSelection=fopen("PackSelectionInformation.txt", "r"))==NULL){
	printf("Tidak ada file \n");
	}
	while(fgets(buff, sizeof(buff), iPackSelection)){
	printf("%s",buff);
	}
	fclose(iPackSelection);
}

void menu1(){
	//variabel pil untuk menyimpan pilihan yang diinput user pada switch case
	int pil;
	
	menu:
	printf ("\t\t\t===============================================================\n");
	printf ("\t\t\t                                                               \n");
	printf ("\t\t\t                              MENU                             \n");
	printf ("\t\t\t                                                               \n");
	printf ("\t\t\t===============================================================\n");
	printf ("\t\t\t\n");
	printf ("\t\t\t_______________________________________________________________\n");
	printf ("\t\t\t|| [1] Cek Informasi Jasa	                                ||\n");
	printf ("\t\t\t||     (Meliputi Paket, Harga Paket, dan Diskon lainnya)     ||\n");
	printf ("\t\t\t||___________________________________________________________||\n");
	printf ("\t\t\t|| [2] Tentang Pembuat                                       ||\n");
	printf ("\t\t\t||___________________________________________________________||\n");
	printf ("\t\t\t|| [3] Tentang `GREAT PHOTO STUDIO`                          ||\n");
	printf ("\t\t\t||___________________________________________________________||\n");
	printf ("\t\t\t|| [4] Keluar                                                ||\n");
	printf ("\t\t\t||___________________________________________________________||\n\n");

	printf ("\t\t\t||===========================================================||\n");
	printf ("\t\t\t|| Tekan karakter acak untuk lanjut ke Registrasi Pemesanan...\n");
	printf ("\t\t\t|| Masukkan nomor Men anda : ");
	scanf ("%d", &pil);
	printf ("\t\t\t||===========================================================||\n");
	system ("cls");
	if (pil == 1){
		iPackSelection();
		goto menu;
	}
	else if (pil == 2){
		aboutUs();
		goto menu;
	}
	else if (pil == 3){
		aboutCreator();
		goto menu;
	}
	else if (pil == 4){
		exit(1);
	}		
}

Date InputTanggalPemesanan (){
	printf ("\n=============================================================================");
	printf ("\n                             GREAT PHOTO STUDIO                              ");
	printf ("\n-----------------------------------------------------------------------------");
	printf ("\n                             REGISTRASI PESANAN                              ");
	printf ("\n=============================================================================");
	printf ("\n");
	waktu();
}

ID InputDataCustomer (ID customer){
	printf("\n");
	printf(" Nama Customer     : ");
	scanf(" %[^\n]s", &customer.nama);
	printf(" Alamat            : ");
	scanf(" %[^\n]s", &customer.alamat);
	printf(" No. Telepon       : ");
	scanf("%s", &customer.telepon);
	
	
	return customer;
}

Date InputTanggalDigunakan (Date digunakanTanggal){
	do{
	printf ("\nDigunakan pada tanggal dd  : ");
	scanf ("%d", &digunakanTanggal.tanggal );
	if(digunakanTanggal.tanggal<1||digunakanTanggal.tanggal>31){
		printf( "\nInput Tidak Valid!");
	}
	} while (digunakanTanggal.tanggal<1||digunakanTanggal.tanggal>31);
	
	return digunakanTanggal;
}

Date InputBulanDigunakan (Date digunakanBulan){
	do{
	printf ("\nDigunakan pada bulan	mm    : ");
	scanf ("%d", &digunakanBulan.bulan );
	if(digunakanBulan.bulan<1||digunakanBulan.bulan>12){
		printf( "\nInput Tidak Valid!");
	}
	} while (digunakanBulan.bulan<1||digunakanBulan.bulan>12);
	
	return digunakanBulan;
}

Date InputTahunDigunakan (Date digunakanTahun){
	do{
	printf ("\nDigunakan pada tahun yyyy  : ");
	scanf ("%d", &digunakanTahun.tahun );
	if(digunakanTahun.tahun<2022||digunakanTahun.tahun>2023){
		printf( "\nInput Tidak Valid!");
	}
	} while (digunakanTahun.tahun<2022||digunakanTahun.tahun>2023);
	
	return digunakanTahun;
}

void TampilkanDaftarMenu(){
char buff[100];
	FILE*in;
	if((in=fopen("PackSelectionInformation.txt", "r"))==NULL){
		printf("Tidak ada file \n");
	}
	while(fgets(buff, sizeof(buff), in)){
		printf("%s",buff);
	}
	fclose(in);
}

void TampilkanExtraOptionPrawedding(){
	char buff[100];
	FILE*extraPrewed;
	if((extraPrewed=fopen("ExtraOptionalPrewedding.txt", "r"))==NULL){
		printf("Tidak ada file \n");
	}
	while(fgets(buff, sizeof(buff), extraPrewed)){
		printf("%s",buff);
	}
	fclose(extraPrewed);
}

void TampilkanExtraOptionDokumenter(){
	char buff[100];
	FILE*extraDokumen;
	if((extraDokumen=fopen("ExtraOptionDokumenter.txt", "r"))==NULL){
		printf("Tidak ada file \n");
	}
	while(fgets(buff, sizeof(buff), extraDokumen)){
		printf("%s",buff);
	}
	fclose(extraDokumen);
}

int HitungHargaFotografer (int sewa_fotografer, int jumlah_fotografer){
	int sub_fotografer = sewa_fotografer * jumlah_fotografer;
	return sub_fotografer;
}

int HitungHargaVideografer (int sewa_videografer, int jumlah_videografer){
	int sub_videografer = sewa_videografer * jumlah_videografer;
	return sub_videografer;
}

int HitungHargaPerorang (int harga_perorang, int jumlah_orang){
	int sub_perorang = harga_perorang * jumlah_orang;
	return sub_perorang;
}

void TampilkanHasilRegistrasi (ID customer, Date pesan, Date digunakanTanggal, Date digunakanBulan, Date digunakanTahun){
	system ("cls");
	printf ("\n=============================================================================");
	printf ("\n|                          DETAIL DATA REGISTRASI                           |");
	printf ("\n=============================================================================");
	printf ("\n");
	printf ("\n                       Nama Customer	: %s", customer.nama);
	printf ("\n");
	printf ("\n                         No. Telepon	: %s", customer.telepon);
	printf ("\n");
	printf ("\n                              Alamat	: %s", customer.alamat);
	printf ("\n");
	printf ("\n");                             waktu();
	printf ("\n");
	printf ("\n	               Akan Digunakan Pada  : %d-%d-%d", digunakanTanggal.tanggal, digunakanBulan.bulan, digunakanTahun.tahun);
	printf ("\n");
	printf ("\n=============================================================================");
}

int checker(){
    char enter;
    int input;
    
    if(enter=scanf("%d%c", &input, &enter)!=2){
        fflush(stdin);
        printf("\t\t\t     Masukkan Angka! : ");
        return checker(); 
    }
    else{
        if(input>=0){
            return input;
        }
        else{
            fflush(stdin);
            printf("\t\t\t     Angka Tidak Valid! : ");
            return checker();
        }
    }
    
    return input;
}
	
int main (){

	int menu;
	int total, total1, total2;
	int diskon1, diskon2;
	int bayar;
	int kembalian;
	int kembaliandisc1, kembaliandisc2;
	ID customer;
	//Date pemesanan, digunakan;
	Date pemesanan, digunakanTanggal, digunakanBulan, digunakanTahun;
	ID input_customer;
	Date input_pemesanan, input_digunakanTanggal, input_digunakanBulan, input_digunakanTahun;
	//Date input_pemesanan, input_digunakan;
	char kembali = 'r';
	int sewa_fotografer, sewa_videografer;
	int jumlah_fotografer, jumlah_videografer;
	int price_fotografer, price_videografer;
	char opsi;
	int jumlah_opsi;
	int pilih_opsi;
	int harga_opsi;
	int subtotal_opsi = 0;

	cover();
	menuUtama();
	menu1();


	while (kembali == 'r' || kembali == 'R'){

		system ("cls");
		pemesanan = InputTanggalPemesanan (input_pemesanan);

		customer = InputDataCustomer (input_customer);

		//digunakan = InputTanggalDigunakan (input_digunakan);
		digunakanTanggal = InputTanggalDigunakan (input_digunakanTanggal);
		digunakanBulan = InputBulanDigunakan (input_digunakanBulan);
		digunakanTahun = InputTahunDigunakan (input_digunakanTahun);

		system ("cls");
		TampilkanDaftarMenu();

		printf ("\n\n\n Silahkan Masukkan Menu Pilihan : ");
		scanf ("%d", &menu);

		system ("cls");
		if (menu == 1){
			FILE * hasil;
			hasil=fopen("transaction.txt","w");
			fprintf(hasil, "\n PAKET PREWEDDING");
			fclose (hasil);
			sewa_fotografer = 390000;
			sewa_videografer = 460000;
			total = 0;
			harga_opsi = 0;

			printf("\n=============================================================================");
			printf("\n|                             PAKET PRAWEDDING                              |");
			printf("\n|                  Semakin Banyak Kamera, Semakin Estetik                   |");
			printf("\n=============================================================================");
			printf("\n Masukkan Jumlah Fotografer		: ");
			jumlah_fotografer = checker();
			//scanf("%d", &jumlah_fotografer);
			printf("\n Masukkan Jumlah Videografer		: ");
			jumlah_videografer = checker();
			//scanf("%d", &jumlah_videografer);
			printf("\n=============================================================================");
			//mencetak struk
			FILE * hasil1;
			hasil1=fopen("transaction.txt","w");
			fprintf(hasil1, "\n Jumlah Fotografer		: %d ", jumlah_fotografer);
			fprintf(hasil1, "\n Jumlah Videografer		: %d ", jumlah_videografer);
			fclose (hasil1);

			printf ("\n\nIngin Menambahkan Pembelian	 ( Y / N )	 ?	");
			scanf (" %c", &opsi);

			if (opsi == 'Y' || opsi == 'y'){
				int i = 1;
				system ("cls");

				TampilkanExtraOptionPrawedding();

				printf ("\n\n Masukkan Jumlah Opsi	: ");
				scanf ("%d", &jumlah_opsi);
				printf ("\n=============================================================================\n");

				while (i <= jumlah_opsi){
					printf ("\n Silahkan Pilih Opsi 	: ");
					scanf ("%d", &pilih_opsi);
					if (pilih_opsi == 1){
						harga_opsi = 240000;
					}
					else if (pilih_opsi == 2){
						harga_opsi = 162000;
					}
					else if (pilih_opsi == 3 || pilih_opsi == 14){
						harga_opsi = 146000;
					}
					else if (pilih_opsi == 4 || pilih_opsi == 15){
						harga_opsi = 120000;
					}
					else if (pilih_opsi == 5 || pilih_opsi == 16){
						harga_opsi = 84000;
					}
					else if (pilih_opsi == 6 || pilih_opsi == 17){
						harga_opsi = 71000;
					}
					else if (pilih_opsi == 7 || pilih_opsi == 18){
						harga_opsi = 68000;
					}
					else if (pilih_opsi == 8 || pilih_opsi == 19){
						harga_opsi = 61000;
					}
					else if (pilih_opsi == 9 || pilih_opsi == 20){
						harga_opsi = 58000;
					}
					else if (pilih_opsi == 10 || pilih_opsi == 21){
						harga_opsi = 53000;
					}
					else if (pilih_opsi == 11 || pilih_opsi == 22){
						harga_opsi = 50000;
					}
					else if (pilih_opsi == 12 || pilih_opsi == 23){
						harga_opsi = 46000;
					}
					else if (pilih_opsi == 13 || pilih_opsi == 24){
						harga_opsi = 42000;
					}
					else if (pilih_opsi == 25){
						harga_opsi = 70000;
					}
					else if (pilih_opsi == 26){
						harga_opsi = 45000;
					}else if (pilih_opsi == 27){
						harga_opsi = 34000;
					}else if (pilih_opsi == 28){
						harga_opsi = 22000;
					}else if (pilih_opsi == 29){
						harga_opsi = 10000;
					}else if (pilih_opsi == 30){
						harga_opsi = 8000;
					}else if (pilih_opsi == 31){
						harga_opsi = 6500;
					}else if (pilih_opsi == 32){
						harga_opsi = 4500;
					}else if (pilih_opsi == 33){
						harga_opsi = 2500;
					}
					else if (pilih_opsi == 34){
						harga_opsi = 2000;
					}
					else if (pilih_opsi == 35){
						harga_opsi = 1500;
					}
					else {
						printf ("\nMOHON INPUTKAN KODE SESUAI DAFTAR EXTRA OPTION !\n");
						i--;
					}
					subtotal_opsi = subtotal_opsi + harga_opsi;
					i++;
				}

				price_fotografer = HitungHargaFotografer (sewa_fotografer, jumlah_fotografer);

				price_videografer = HitungHargaVideografer (sewa_videografer, jumlah_videografer);

				total = total + price_fotografer + price_videografer + subtotal_opsi;
				diskon1 = total*10/100;
				diskon2 = total*20/100;
				total1=total-diskon1;
				total2=total-diskon2;
				kembaliandisc1=bayar-total1;
				kembaliandisc2=bayar-total2;
				kembalian=bayar-total;

				TampilkanHasilRegistrasi(customer, pemesanan, digunakanTanggal, digunakanBulan, digunakanTahun);


				printf ("\n|                              RINCIAN BIAYA                                |");
				printf ("\n=============================================================================");
				printf ("\n");
				printf ("\n              Harga Sewa %d Fotografer	: Rp. %d",jumlah_fotografer, price_fotografer);
				printf ("\n");
				printf ("\n             Harga Sewa %d Videografer	: Rp. %d",jumlah_videografer, price_videografer);
				printf ("\n");
				printf ("\n                         Opsi Tambahan	: Rp. %d", subtotal_opsi);
				printf ("\n");
				printf ("\n-----------------------------------------------------------------------------");
				printf ("\n");
				printf ("\n	                           Total Biaya  : Rp. %d", total);
				printf ("\n");
				printf ("\n-----------------------------------------------------------------------------");
				//struk
				FILE * hasil2;
				hasil2=fopen("transaction.txt","w");
				fprintf (hasil2,"\n|                              RINCIAN BIAYA                                |");
				fprintf (hasil2,"\n=============================================================================");
				fprintf (hasil2,"\n");
				fprintf (hasil2,"\n              Harga Sewa %d Fotografer	: Rp. %d",jumlah_fotografer, price_fotografer);
				fprintf (hasil2,"\n");
				fprintf (hasil2,"\n             Harga Sewa %d Videografer	: Rp. %d",jumlah_videografer, price_videografer);
				fprintf (hasil2,"\n");
				fprintf (hasil2,"\n                         Opsi Tambahan	: Rp. %d", subtotal_opsi);
				fprintf (hasil2,"\n");
				fprintf (hasil2,"\n-----------------------------------------------------------------------------");
				fprintf (hasil2,"\n");
				fprintf (hasil2,"\n	                           Total Biaya  : Rp. %d", total);
				fprintf (hasil2,"\n");
				fprintf (hasil2,"\n-----------------------------------------------------------------------------");
				fclose (hasil2);
				if (total > 1100000){
					printf ("\n 		Anda mendapatkan diskon sebesar 10 persen!");
					printf ("\n");
					printf ("\n 		Potongan harga : Rp. %d", diskon1);
					printf ("\n");
					printf ("\n 		Total Biaya : Rp. %d", total1);
					printf ("\n");
					printf ("\n=============================================================================");
					printf ("\n 		Bayar : Rp. ");
					scanf ("%d", &bayar);
					kembaliandisc1=bayar-total1;
					printf ("\n		Kembalian : Rp. %d", kembaliandisc1);
					//struk
					FILE * hasil3;
					hasil3=fopen("transaction.txt","w");
					fprintf (hasil3,"\n|                              RINCIAN BIAYA                                |");
					fprintf (hasil3,"\n=============================================================================");
					fprintf (hasil3,"\n");
					fprintf (hasil3,"\n              Harga Sewa %d Fotografer	: Rp. %d",jumlah_fotografer, price_fotografer);
					fprintf (hasil3,"\n");
					fprintf (hasil3,"\n             Harga Sewa %d Videografer	: Rp. %d",jumlah_videografer, price_videografer);
					fprintf (hasil3,"\n");
					fprintf (hasil3,"\n                         Opsi Tambahan	: Rp. %d", subtotal_opsi);
					fprintf (hasil3,"\n");
					fprintf (hasil3,"\n-----------------------------------------------------------------------------");
					fprintf (hasil3,"\n");
					fprintf (hasil3,"\n	                           Total Biaya  : Rp. %d", total);
					fprintf (hasil3,"\n");
					fprintf (hasil3,"\n-----------------------------------------------------------------------------");
					fprintf (hasil3,"\n 		Anda mendapatkan diskon sebesar 10 persen!");
					fprintf (hasil3,"\n");
					fprintf (hasil3,"\n 		Potongan harga : Rp. %d", diskon1);
					fprintf (hasil3,"\n");
					fprintf (hasil3,"\n 		Total Biaya : Rp. %d", total1);
					fprintf (hasil3,"\n");
					fprintf (hasil3,"\n=============================================================================");
					fprintf (hasil3,"\n 		Bayar : Rp. %d", bayar);
					fprintf (hasil3,"\n		Kembalian : Rp. %d", kembaliandisc1);
					fclose (hasil3);
				}
				else if (total > 5200000){
					printf ("\n 		Anda mendapatkan diskon sebesar 20 persen!");
					printf ("\n");
					printf ("\n 		Potongan harga : Rp. %d", diskon2);
					printf ("\n");
					printf ("\n 		Total Biaya : Rp. %d", total2);
					printf ("\n");
					printf ("\n=============================================================================");
					printf ("\n 		Bayar : Rp. ");
					scanf ("%d", &bayar);
					kembaliandisc2=bayar-total2;
					printf ("\n		Kembalian : Rp. %d", kembaliandisc2);
					//struk
					FILE * hasil4;
					hasil4=fopen("transaction.txt","w");
					fprintf (hasil4,"\n|                              RINCIAN BIAYA                                |");
					fprintf (hasil4,"\n=============================================================================");
					fprintf (hasil4,"\n");
					fprintf (hasil4,"\n              Harga Sewa %d Fotografer	: Rp. %d",jumlah_fotografer, price_fotografer);
					fprintf (hasil4,"\n");
					fprintf (hasil4,"\n             Harga Sewa %d Videografer	: Rp. %d",jumlah_videografer, price_videografer);
					fprintf (hasil4,"\n");
					fprintf (hasil4,"\n                         Opsi Tambahan	: Rp. %d", subtotal_opsi);
					fprintf (hasil4,"\n");
					fprintf (hasil4,"\n-----------------------------------------------------------------------------");
					fprintf (hasil4,"\n");
					fprintf (hasil4,"\n	                           Total Biaya  : Rp. %d", total);
					fprintf (hasil4,"\n");
					fprintf (hasil4,"\n-----------------------------------------------------------------------------");
					fprintf (hasil4,"\n 		Anda mendapatkan diskon sebesar 20 persen!");
					fprintf (hasil4,"\n");
					fprintf (hasil4,"\n 		Potongan harga : Rp. %d", diskon2);
					fprintf (hasil4,"\n");
					fprintf (hasil4,"\n 		Total Biaya : Rp. %d", total2);
					fprintf (hasil4,"\n");
					fprintf (hasil4,"\n=============================================================================");
					fprintf (hasil4,"\n 		Bayar : Rp. %d", bayar);
					fprintf (hasil4,"\n		Kembalian : Rp. %d", kembaliandisc2);
					fclose (hasil4);
				}
				else {
					printf ("\n 		Potongan harga : Rp. -");
					printf ("\n");
					printf ("\n 		Total Biaya : Rp. %d", total);
					printf ("\n");
					printf ("\n=============================================================================");
					printf ("\n 		Bayar : Rp. ");
					scanf ("%d", &bayar);
					kembalian=bayar-total;
					printf ("\n			Kembalian : Rp. %d", kembalian);
					//struk
					FILE * hasil5;
					hasil5=fopen("transaction.txt","w");
					fprintf (hasil5,"\n|                              RINCIAN BIAYA                                |");
					fprintf (hasil5,"\n=============================================================================");
					fprintf (hasil5,"\n");
					fprintf (hasil5,"\n              Harga Sewa %d Fotografer	: Rp. %d",jumlah_fotografer, price_fotografer);
					fprintf (hasil5,"\n");
					fprintf (hasil5,"\n             Harga Sewa %d Videografer	: Rp. %d",jumlah_videografer, price_videografer);
					fprintf (hasil5,"\n");
					fprintf (hasil5,"\n                         Opsi Tambahan	: Rp. %d", subtotal_opsi);
					fprintf (hasil5,"\n");
					fprintf (hasil5,"\n-----------------------------------------------------------------------------");
					fprintf (hasil5,"\n");
					fprintf (hasil5,"\n	                           Total Biaya  : Rp. %d", total);
					fprintf (hasil5,"\n");
					fprintf (hasil5,"\n-----------------------------------------------------------------------------");
					fprintf (hasil5,"\n 		Potongan harga : Rp. -");
					fprintf (hasil5,"\n");
					fprintf (hasil5,"\n 		Total Biaya : Rp. %d", total);
					fprintf (hasil5,"\n");
					fprintf (hasil5,"\n=============================================================================");
					fprintf (hasil5,"\n 		Bayar : Rp. %d", bayar);
					fprintf (hasil5,"\n		Kembalian : Rp. %d", kembalian);
					fclose (hasil5);
				}
			}

			else {
				int total = 0;

				TampilkanHasilRegistrasi(customer, pemesanan, digunakanTanggal, digunakanBulan, digunakanTahun);

				price_fotografer = HitungHargaFotografer (sewa_fotografer, jumlah_fotografer);

				price_videografer = HitungHargaVideografer (sewa_videografer, jumlah_videografer);

				total = total + price_fotografer + price_videografer;
				diskon1 = total*10/100;
				diskon2 = total*20/100;
				total1=total-diskon1;
				total2=total-diskon2;
				kembaliandisc1=bayar-total1;
				kembaliandisc2=bayar-total2;
				kembalian=bayar-total;

				printf ("\n|                              RINCIAN BIAYA                                |");
				printf ("\n=============================================================================");
				printf ("\n");
				printf ("\n              Harga Sewa %d Fotografer	: Rp. %d",jumlah_fotografer, price_fotografer);
				printf ("\n");
				printf ("\n             Harga Sewa %d Videografer	: Rp. %d",jumlah_videografer, price_videografer);
				printf ("\n");
				printf ("\n                         Opsi Tambahan	: -");
				printf ("\n");
				printf ("\n=============================================================================");
				printf ("\n");
				printf ("\n	                  Total Biaya	: Rp. %d", total);
				printf ("\n");
				printf ("\n=============================================================================");
				//struk
				FILE * hasil6;
				hasil6=fopen("transaction.txt","w");
				fprintf (hasil6,"\n|                              RINCIAN BIAYA                                |");
				fprintf (hasil6,"\n=============================================================================");
				fprintf (hasil6,"\n");
				fprintf (hasil6,"\n              Harga Sewa %d Fotografer	: Rp. %d",jumlah_fotografer, price_fotografer);
				fprintf (hasil6,"\n");
				fprintf (hasil6,"\n             Harga Sewa %d Videografer	: Rp. %d",jumlah_videografer, price_videografer);
				fprintf (hasil6,"\n");
				fprintf (hasil6,"\n                         Opsi Tambahan	: -");
				fprintf (hasil6,"\n");
				fprintf (hasil6,"\n=============================================================================");
				fprintf (hasil6,"\n");
				fprintf (hasil6,"\n	                           Total Biaya  : Rp. %d", total);
				fprintf (hasil6,"\n");
				fprintf (hasil6,"\n=============================================================================");
				fclose (hasil6);
				if (total > 1100000){
					printf ("\n 		Anda mendapatkan diskon sebesar 10 persen!");
					printf ("\n");
					printf ("\n 		Potongan harga : Rp. %d", diskon1);
					printf ("\n");
					printf ("\n 		Total Biaya : Rp. %d", total1);
					printf ("\n");
					printf ("\n=============================================================================");
					printf ("\n 		Bayar : Rp. ");
					scanf ("%d", &bayar);
					kembaliandisc1=bayar-total1;
					printf ("\n		Kembalian : Rp. %d", kembaliandisc1);
					//struk
					FILE * hasil7;
					hasil7=fopen("transaction.txt","w");
					fprintf (hasil7,"\n|                              RINCIAN BIAYA                                |");
					fprintf (hasil7,"\n=============================================================================");
					fprintf (hasil7,"\n");
					fprintf (hasil7,"\n              Harga Sewa %d Fotografer	: Rp. %d",jumlah_fotografer, price_fotografer);
					fprintf (hasil7,"\n");
					fprintf (hasil7,"\n             Harga Sewa %d Videografer	: Rp. %d",jumlah_videografer, price_videografer);
					fprintf (hasil7,"\n");
					fprintf (hasil7,"\n                         Opsi Tambahan	: -");
					fprintf (hasil7,"\n");
					fprintf (hasil7,"\n=============================================================================");
					fprintf (hasil7,"\n");
					fprintf (hasil7,"\n	                           Total Biaya  : Rp. %d", total);
					fprintf (hasil7,"\n");
					fprintf (hasil7,"\n=============================================================================");
					fprintf (hasil7,"\n 		Anda mendapatkan diskon sebesar 10 persen!");
					fprintf (hasil7,"\n");
					fprintf (hasil7,"\n 		Potongan harga : Rp. %d", diskon1);
					fprintf (hasil7,"\n");
					fprintf (hasil7,"\n 		Total Biaya : Rp. %d", total1);
					fprintf (hasil7,"\n");
					fprintf (hasil7,"\n=============================================================================");
					fprintf (hasil7,"\n 		Bayar : Rp. %d", bayar);
					fprintf (hasil7,"\n		Kembalian : Rp. %d", kembaliandisc1);
					fclose (hasil7);
				}
				else if (total > 5200000){
					printf ("\n 		Anda mendapatkan diskon sebesar 20 persen!");
					printf ("\n");
					printf ("\n 		Potongan harga : Rp. %d", diskon2);
					printf ("\n");
					printf ("\n 		Total Biaya : Rp. %d", total2);
					printf ("\n");
					printf ("\n=============================================================================");
					printf ("\n 		Bayar : Rp. ");
					scanf ("%d", &bayar);
                    kembaliandisc2=bayar-total2;
					printf ("\n		Kembalian : Rp. %d", kembaliandisc2);
					//struk
					FILE * hasil8;
					hasil8=fopen("transaction.txt","w");
					fprintf (hasil8,"\n|                              RINCIAN BIAYA                                |");
					fprintf (hasil8,"\n=============================================================================");
					fprintf (hasil8,"\n");
					fprintf (hasil8,"\n              Harga Sewa %d Fotografer	: Rp. %d",jumlah_fotografer, price_fotografer);
					fprintf (hasil8,"\n");
					fprintf (hasil8,"\n             Harga Sewa %d Videografer	: Rp. %d",jumlah_videografer, price_videografer);
					fprintf (hasil8,"\n");
					fprintf (hasil8,"\n                         Opsi Tambahan	: -");
					fprintf (hasil8,"\n");
					fprintf (hasil8,"\n=============================================================================");
					fprintf (hasil8,"\n");
					fprintf (hasil8,"\n	                           Total Biaya  : Rp. %d", total);
					fprintf (hasil8,"\n");
					fprintf (hasil8,"\n=============================================================================");
					fprintf (hasil8,"\n 		Anda mendapatkan diskon sebesar 20 persen!");
					fprintf (hasil8,"\n");
					fprintf (hasil8,"\n 		Potongan harga : Rp. %d", diskon2);
					fprintf (hasil8,"\n");
					fprintf (hasil8,"\n 		Total Biaya : Rp. %d", total2);
					fprintf (hasil8,"\n");
					fprintf (hasil8,"\n=============================================================================");
					fprintf (hasil8,"\n 		Bayar : Rp. %d", bayar);
					fprintf (hasil8,"\n		Kembalian : Rp. %d", kembaliandisc2);
					fclose (hasil8);
				}
				else {
					printf ("\n 		Potongan harga : Rp. -");
					printf ("\n");
					printf ("\n 		Total Biaya : Rp. %d", total);
					printf ("\n");
					printf ("\n=============================================================================");
					printf ("\n 		Bayar : Rp. ");
					scanf ("%d", &bayar);
                   			kembalian=bayar-total;
					printf ("\n			Kembalian : Rp. %d", kembalian);
					FILE * hasil9;
					hasil9=fopen("transaction.txt","w");
					fprintf (hasil9,"\n|                              RINCIAN BIAYA                                |");
					fprintf (hasil9,"\n=============================================================================");
					fprintf (hasil9,"\n");
					fprintf (hasil9,"\n              Harga Sewa %d Fotografer	: Rp. %d",jumlah_fotografer, price_fotografer);
					fprintf (hasil9,"\n");
					fprintf (hasil9,"\n             Harga Sewa %d Videografer	: Rp. %d",jumlah_videografer, price_videografer);
					fprintf (hasil9,"\n");
					fprintf (hasil9,"\n                         Opsi Tambahan	: -");
					fprintf (hasil9,"\n");
					fprintf (hasil9,"\n=============================================================================");
					fprintf (hasil9,"\n");
					fprintf (hasil9,"\n	                           Total Biaya  : Rp. %d", total);
					fprintf (hasil9,"\n");
					fprintf (hasil9,"\n=============================================================================");
					fprintf (hasil9,"\n 		Potongan harga : Rp. -");
					fprintf (hasil9,"\n");
					fprintf (hasil9,"\n 		Total Biaya : Rp. %d", total);
					fprintf (hasil9,"\n");
					fprintf (hasil9,"\n=============================================================================");
					fprintf (hasil9,"\n 		Bayar : Rp. %d", bayar);
					fprintf (hasil9,"\n		Kembalian : Rp. %d", kembalian);
					fclose (hasil9);
				}
			}
		}

		else if (menu == 2){
			FILE * hasil4;
			hasil4=fopen("transaction.txt","w");
			fprintf(hasil4, "\n PAKET DOKUMENTER");
			fclose (hasil4);
			sewa_fotografer = 245000;
			sewa_videografer = 365000;
			total = 0;
			harga_opsi = 0;
			int jumlah_orang;
			int harga_perorang = 20000;
			int price_orang;

			printf ("=============================================================================");
			printf ("\n|                             PAKET DOKUMENTER                              |");
			printf ("\n|                  Semakin Banyak Kamera, Semakin Estetik                   |");
			printf ("\n=============================================================================");
			printf ("\n\nSilahkan Masukkan Jumlah Fotografer		: ");
			scanf ("%d", &jumlah_fotografer);
			printf ("\nSilahkan Masukkan Jumlah Videografer		: ");
			scanf ("%d", &jumlah_videografer);
			printf ("\nSilahkan Masukkan Jumlah Orang / Peserta	: ");
			scanf ("%d", &jumlah_orang);
			printf ("\n=============================================================================");
			//mencetak history transaksi
			FILE * hasil10;
			hasil10=fopen("transaction.txt","w");
			fprintf (hasil10, "\n Jumlah Fotografer : %d ", jumlah_fotografer);
			fprintf (hasil10, "\n Jumlah Videografer : %d ", jumlah_videografer);
			fprintf(hasil10, "\n Jumlah Peserta : %d ", jumlah_orang );
			fclose (hasil10);
			printf ("\n\nApakah Ingin Membeli Opsi Tambahan	(Y/N)	? ");
			scanf (" %c", &opsi);

			if (opsi == 'y' || opsi == 'Y'){
				int i = 1;
				system ("cls");

				TampilkanExtraOptionDokumenter();

				printf ("\n\nMasukkan Jumlah Opsi	: ");
				scanf ("%d", &jumlah_opsi);
				printf ("\n=============================================================================\n");

				while (i <= jumlah_opsi){
					printf ("\nSilahkan Pilih Opsi 	: ");
					scanf ("%d", &pilih_opsi);
					if (pilih_opsi == 1){
						harga_opsi = 40000;
					}
					else if (pilih_opsi == 2){
						harga_opsi = 180000;
					}
					else if (pilih_opsi == 3 || pilih_opsi == 14){
						harga_opsi = 146000;
					}
					else if (pilih_opsi == 4 || pilih_opsi == 15){
						harga_opsi = 120000;
					}
					else if (pilih_opsi == 5 || pilih_opsi == 16){
						harga_opsi = 84000;
					}
					else if (pilih_opsi == 6 || pilih_opsi == 17){
						harga_opsi = 71000;
					}
					else if (pilih_opsi == 7 || pilih_opsi == 18){
						harga_opsi = 68000;
					}
					else if (pilih_opsi == 8 || pilih_opsi == 19){
						harga_opsi = 61000;
					}
					else if (pilih_opsi == 9 || pilih_opsi == 20){
						harga_opsi = 58000;
					}
					else if (pilih_opsi == 10 || pilih_opsi == 21){
						harga_opsi = 53000;
					}
					else if (pilih_opsi == 11 || pilih_opsi == 22){
						harga_opsi = 50000;
					}
					else if (pilih_opsi == 12 || pilih_opsi == 23){
						harga_opsi = 46000;
					}
					else if (pilih_opsi == 13 || pilih_opsi == 24){
						harga_opsi = 42000;
					}
					else if (pilih_opsi == 25){
						harga_opsi = 70000;
					}
					else if (pilih_opsi == 26){
						harga_opsi = 45000;
					}else if (pilih_opsi == 27){
						harga_opsi = 34000;
					}else if (pilih_opsi == 28){
						harga_opsi = 22000;
					}else if (pilih_opsi == 29){
						harga_opsi = 10000;
					}else if (pilih_opsi == 30){
						harga_opsi = 8000;
					}else if (pilih_opsi == 31){
						harga_opsi = 6500;
					}else if (pilih_opsi == 32){
						harga_opsi = 4500;
					}else if (pilih_opsi == 33){
						harga_opsi = 2500;
					}
					else if (pilih_opsi == 34){
						harga_opsi = 2000;
					}
					else if (pilih_opsi == 35){
						harga_opsi = 1500;
					}
					else {
						printf ("\nMOHON INPUTKAN KODE SESUAI DAFTAR EXTRA OPTION !\n");
						i--;
					}
					subtotal_opsi = subtotal_opsi + harga_opsi;
					i++;
				}
				price_fotografer = HitungHargaFotografer (sewa_fotografer, jumlah_fotografer);

				price_videografer = HitungHargaVideografer (sewa_videografer, jumlah_videografer);

				price_orang = HitungHargaPerorang (jumlah_orang, harga_perorang);

				total = total + price_fotografer + price_videografer + price_orang + subtotal_opsi;

				TampilkanHasilRegistrasi(customer, pemesanan, digunakanTanggal, digunakanBulan, digunakanTahun);

				//TampilkanHasilRegistrasi(customer, pemesanan, digunakan);
				diskon1 = total*10/100;
				diskon2 = total*20/100;
				total1=total-diskon1;
				total2=total-diskon2;
				kembaliandisc1=bayar-total1;
				kembaliandisc2=bayar-total2;
				kembalian=bayar-total;

				printf ("\n=============================================================================");
				printf ("\n|                              RINCIAN BIAYA                                |");
				printf ("\n=============================================================================");
				printf ("\n");
				printf ("\n              Harga Sewa %d Fotografer	: Rp. %d",jumlah_fotografer, price_fotografer);
				printf ("\n");
				printf ("\n             Harga Sewa %d Videografer	: Rp. %d",jumlah_videografer, price_videografer);
				printf ("\n");
				printf ("\n                       Harga %d Orang	: Rp. %d",jumlah_orang, price_orang);
				printf ("\n");
				printf ("\n                        Opsi Tambahan	: Rp. %d", subtotal_opsi);
				printf ("\n");
				printf ("\n=============================================================================");
				printf ("\n");
				printf ("\n	                 	 Total Biaya	: Rp. %d", total);
				printf ("\n");
				printf ("\n=============================================================================");
				//struct
				FILE * hasil11;
				hasil11=fopen("transaction.txt","w");
				fprintf (hasil11,"\n|                              RINCIAN BIAYA                                |");
				fprintf (hasil11,"\n=============================================================================");
				fprintf (hasil11,"\n");
				fprintf (hasil11,"\n              Harga Sewa %d Fotografer	: Rp. %d",jumlah_fotografer, price_fotografer);
				fprintf (hasil11,"\n");
				fprintf (hasil11,"\n             Harga Sewa %d Videografer	: Rp. %d",jumlah_videografer, price_videografer);
				fprintf (hasil11,"\n");
				fprintf (hasil11,"\n                       Harga %d Orang	: Rp. %d",jumlah_orang, price_orang);
				fprintf (hasil11,"\n");
				fprintf (hasil11,"\n                         Opsi Tambahan	: Rp. %d", subtotal_opsi);
				fprintf (hasil11,"\n");
				fprintf (hasil11,"\n=============================================================================");
				fprintf (hasil11,"\n");
				fprintf (hasil11,"\n	                           Total Biaya  : Rp. %d", total);
				fprintf (hasil11,"\n");
				fprintf (hasil11,"\n=============================================================================");
				fclose (hasil11);
				
				if (total > 1100000){
					printf ("\n 		Anda mendapatkan diskon sebesar 10 persen!");
					printf ("\n");
					printf ("\n 		Potongan harga : Rp. %d", diskon1);
					printf ("\n");
					printf ("\n 		Total Biaya : Rp. %d", total1);
					printf ("\n");
					printf ("\n=============================================================================");
					printf ("\n 		Bayar : Rp. ");
					scanf ("%d", &bayar);
					kembaliandisc1=bayar-total1;
					printf ("\n		Kembalian : Rp. %d", kembaliandisc1);
					//struk
					FILE * hasil12;
					hasil12=fopen("transaction.txt","w");
					fprintf (hasil12,"\n|                              RINCIAN BIAYA                                |");
					fprintf (hasil12,"\n=============================================================================");
					fprintf (hasil12,"\n");
					fprintf (hasil12,"\n              Harga Sewa %d Fotografer	: Rp. %d",jumlah_fotografer, price_fotografer);
					fprintf (hasil12,"\n");
					fprintf (hasil12,"\n             Harga Sewa %d Videografer	: Rp. %d",jumlah_videografer, price_videografer);
					fprintf (hasil12,"\n");
					fprintf (hasil12,"\n                       Harga %d Orang	: Rp. %d",jumlah_orang, price_orang);
					fprintf (hasil12,"\n");
					fprintf (hasil12,"\n                         Opsi Tambahan	: Rp. %d", subtotal_opsi);
					fprintf (hasil12,"\n");
					fprintf (hasil12,"\n=============================================================================");
					fprintf (hasil12,"\n");
					fprintf (hasil12,"\n	                           Total Biaya  : Rp. %d", total);
					fprintf (hasil12,"\n");
					fprintf (hasil12,"\n=============================================================================");
					fprintf (hasil12,"\n 		Anda mendapatkan diskon sebesar 10 persen!");
					fprintf (hasil12,"\n");
					fprintf (hasil12,"\n 		Potongan harga : Rp. %d", diskon1);
					fprintf (hasil12,"\n");
					fprintf (hasil12,"\n 		Total Biaya : Rp. %d", total1);
					fprintf (hasil12,"\n");
					fprintf (hasil12,"\n=============================================================================");
					fprintf (hasil12,"\n 		Bayar : Rp. %d", bayar);
					fprintf (hasil12,"\n		Kembalian : Rp. %d", kembaliandisc1);
					fclose (hasil12);
				}
				else if (total > 5200000){
					printf ("\n 		Anda mendapatkan diskon sebesar 20 persen!");
					printf ("\n");
					printf ("\n 		Potongan harga : Rp. %d", diskon2);
					printf ("\n");
					printf ("\n 		Total Biaya : Rp. %d", total2);
					printf ("\n");
					printf ("\n=============================================================================");
					printf ("\n 		Bayar : Rp. ");
					scanf ("%d", &bayar);
                    			kembaliandisc2=bayar-total2;
					printf ("\n		Kembalian : Rp. %d", kembaliandisc2);
					//struk
					FILE * hasil13;
					hasil13=fopen("transaction.txt","w");
					fprintf (hasil13,"\n|                              RINCIAN BIAYA                                |");
					fprintf (hasil13,"\n=============================================================================");
					fprintf (hasil13,"\n");
					fprintf (hasil13,"\n              Harga Sewa %d Fotografer	: Rp. %d",jumlah_fotografer, price_fotografer);
					fprintf (hasil13,"\n");
					fprintf (hasil13,"\n             Harga Sewa %d Videografer	: Rp. %d",jumlah_videografer, price_videografer);
					fprintf (hasil13,"\n");
					fprintf (hasil13,"\n                       Harga %d Orang	: Rp. %d",jumlah_orang, price_orang);
					fprintf (hasil13,"\n");
					fprintf (hasil13,"\n                         Opsi Tambahan	: Rp. %d", subtotal_opsi);
					fprintf (hasil13,"\n");
					fprintf (hasil13,"\n=============================================================================");
					fprintf (hasil13,"\n");
					fprintf (hasil13,"\n	                           Total Biaya  : Rp. %d", total);
					fprintf (hasil13,"\n");
					fprintf (hasil13,"\n=============================================================================");
					fprintf (hasil13,"\n 		Anda mendapatkan diskon sebesar 20 persen!");
					fprintf (hasil13,"\n");
					fprintf (hasil13,"\n 		Potongan harga : Rp. %d", diskon2);
					fprintf (hasil13,"\n");
					fprintf (hasil13,"\n 		Total Biaya : Rp. %d", total2);
					fprintf (hasil13,"\n");
					fprintf (hasil13,"\n=============================================================================");
					fprintf (hasil13,"\n 		Bayar : Rp. %d", bayar);
					fprintf (hasil13,"\n		Kembalian : Rp. %d", kembaliandisc2);
					fclose (hasil13);
				}
				else {
					printf ("\n 		Potongan harga : Rp. -");
					printf ("\n");
					printf ("\n 		Total Biaya : Rp. %d", total);
					printf ("\n");
					printf ("\n=============================================================================");
					printf ("\n 		Bayar : Rp. ");
					scanf ("%d", &bayar);
                    			kembalian=bayar-total;
					printf ("\n			Kembalian : Rp. %d", kembalian);
					//struk
					FILE * hasil14;
					hasil14=fopen("transaction.txt","w");
					fprintf (hasil14,"\n|                              RINCIAN BIAYA                                |");
					fprintf (hasil14,"\n=============================================================================");
					fprintf (hasil14,"\n");
					fprintf (hasil14,"\n              Harga Sewa %d Fotografer	: Rp. %d",jumlah_fotografer, price_fotografer);
					fprintf (hasil14,"\n");
					fprintf (hasil14,"\n             Harga Sewa %d Videografer	: Rp. %d",jumlah_videografer, price_videografer);
					fprintf (hasil14,"\n");
					fprintf (hasil14,"\n                       Harga %d Orang	: Rp. %d",jumlah_orang, price_orang);
					fprintf (hasil14,"\n");
					fprintf (hasil14,"\n                         Opsi Tambahan	: Rp. %d", subtotal_opsi);
					fprintf (hasil14,"\n");
					fprintf (hasil14,"\n=============================================================================");
					fprintf (hasil14,"\n");
					fprintf (hasil14,"\n	                           Total Biaya  : Rp. %d", total);
					fprintf (hasil14,"\n");
					fprintf (hasil14,"\n=============================================================================");
					fprintf (hasil14,"\n 		Potongan harga : Rp. -");
					fprintf (hasil14,"\n");
					fprintf (hasil14,"\n 		Total Biaya : Rp. %d", total);
					fprintf (hasil14,"\n");
					fprintf (hasil14,"\n=============================================================================");
					fprintf (hasil14,"\n 		Bayar : Rp. %d", bayar);
					fprintf (hasil14,"\n		Kembalian : Rp. %d", kembalian);
					fclose (hasil14);
				}
			}

			else {
				int total = 0;
				int total1 =0, total2=0;
				int diskon1, diskon2;
				int bayar=0;
				int kembalian = 0;
				int kembaliandisc1=0, kembaliandisc2=0;


				TampilkanHasilRegistrasi(customer, pemesanan, digunakanTanggal, digunakanBulan, digunakanTahun);

				price_fotografer = HitungHargaFotografer (sewa_fotografer, jumlah_fotografer);

				price_videografer = HitungHargaVideografer (sewa_videografer, jumlah_videografer);

				price_orang = HitungHargaPerorang (jumlah_orang, harga_perorang);

				total = total + price_fotografer + price_videografer + price_orang;
				diskon1 = total*10/100;
				diskon2 = total*20/100;
				total1=total-diskon1;
				total2=total-diskon2;
				kembaliandisc1=bayar-total1;
				kembaliandisc2=bayar-total2;
				kembalian=bayar-total;

				printf ("\n|                              RINCIAN BIAYA                                |");
				printf ("\n=============================================================================");
				printf ("\n");
				printf ("\n              Harga Sewa %d Fotografer	: Rp. %d",jumlah_fotografer, price_fotografer);
				printf ("\n");
				printf ("\n             Harga Sewa %d Videografer	: Rp. %d",jumlah_videografer, price_videografer);
				printf ("\n");
				printf ("\n                       Harga %d Orang	: Rp. %d",jumlah_orang, price_orang);
				printf ("\n");
				printf ("\n                        Opsi Tambahan	: -");
				printf ("\n");
				printf ("\n=============================================================================");
				printf ("\n");
				printf ("\n	                  Total Biaya	: Rp. %d", total);
				printf ("\n");
				printf ("\n=============================================================================");
				//struct
				FILE * hasil15;
				hasil15=fopen("transaction.txt","w");
				fprintf (hasil15,"\n|                              RINCIAN BIAYA                                |");
				fprintf (hasil15,"\n=============================================================================");
				fprintf (hasil15,"\n");
				fprintf (hasil15,"\n              Harga Sewa %d Fotografer	: Rp. %d",jumlah_fotografer, price_fotografer);
				fprintf (hasil15,"\n");
				fprintf (hasil15,"\n             Harga Sewa %d Videografer	: Rp. %d",jumlah_videografer, price_videografer);
				fprintf (hasil15,"\n");
				fprintf (hasil15,"\n                       Harga %d Orang	: Rp. %d",jumlah_orang, price_orang);
				fprintf (hasil15,"\n");
				fprintf (hasil15,"\n                         Opsi Tambahan	: -");
				fprintf (hasil15,"\n");
				fprintf (hasil15,"\n=============================================================================");
				fprintf (hasil15,"\n");
				fprintf (hasil15,"\n	                           Total Biaya  : Rp. %d", total);
				fprintf (hasil15,"\n");
				fprintf (hasil15,"\n=============================================================================");
				fclose (hasil15);
				if (total > 1100000){
					printf ("\n 		Anda mendapatkan diskon sebesar 10 persen!");
					printf ("\n");
					printf ("\n 		Potongan harga : Rp. %d", diskon1);
					printf ("\n");
					printf ("\n 		Total Biaya : Rp. %d", total1);
					printf ("\n");
					printf ("\n=============================================================================");
					printf ("\n 		Bayar : Rp. ");
					scanf ("%d", &bayar);
					kembaliandisc1=bayar-total1;
					printf ("\n		Kembalian : Rp. %d", kembaliandisc1);
					//struk
					FILE * hasil16;
					hasil16=fopen("transaction.txt","w");
					fprintf (hasil16,"\n|                              RINCIAN BIAYA                                |");
					fprintf (hasil16,"\n=============================================================================");
					fprintf (hasil16,"\n");
					fprintf (hasil16,"\n              Harga Sewa %d Fotografer	: Rp. %d",jumlah_fotografer, price_fotografer);
					fprintf (hasil16,"\n");
					fprintf (hasil16,"\n             Harga Sewa %d Videografer	: Rp. %d",jumlah_videografer, price_videografer);
					fprintf (hasil16,"\n");
					fprintf (hasil16,"\n                       Harga %d Orang	: Rp. %d",jumlah_orang, price_orang);
					fprintf (hasil16,"\n");
					fprintf (hasil16,"\n                         Opsi Tambahan	: -");
					fprintf (hasil16,"\n");
					fprintf (hasil16,"\n=============================================================================");
					fprintf (hasil16,"\n");
					fprintf (hasil16,"\n	                           Total Biaya  : Rp. %d", total);
					fprintf (hasil16,"\n");
					fprintf (hasil16,"\n=============================================================================");
					fprintf (hasil16,"\n 		Anda mendapatkan diskon sebesar 10 persen!");
					fprintf (hasil16,"\n");
					fprintf (hasil16,"\n 		Potongan harga : Rp. %d", diskon1);
					fprintf (hasil16,"\n");
					fprintf (hasil16,"\n 		Total Biaya : Rp. %d", total1);
					fprintf (hasil16,"\n");
					fprintf (hasil16,"\n=============================================================================");
					fprintf (hasil16,"\n 		Bayar : Rp. %d", bayar);
					fprintf (hasil16,"\n		Kembalian : Rp. %d", kembaliandisc1);
					fclose (hasil16);
				}
				else if (total > 5200000){
					printf ("\n 		Anda mendapatkan diskon sebesar 20 persen!");
					printf ("\n");
					printf ("\n 		Potongan harga : Rp. %d", diskon2);
					printf ("\n");
					printf ("\n 		Total Biaya : Rp. %d", total2);
					printf ("\n");
					printf ("\n=============================================================================");
					printf ("\n 		Bayar : Rp. ");
					scanf ("%d", &bayar);
                    			kembaliandisc2=bayar-total2;
					printf ("\n		Kembalian : Rp. %d", kembaliandisc2);
					//struk
					FILE * hasil17;
					hasil17=fopen("transaction.txt","w");
					fprintf (hasil17,"\n|                              RINCIAN BIAYA                                |");
					fprintf (hasil17,"\n=============================================================================");
					fprintf (hasil17,"\n");
					fprintf (hasil17,"\n              Harga Sewa %d Fotografer	: Rp. %d",jumlah_fotografer, price_fotografer);
					fprintf (hasil17,"\n");
					fprintf (hasil17,"\n             Harga Sewa %d Videografer	: Rp. %d",jumlah_videografer, price_videografer);
					fprintf (hasil17,"\n");
					fprintf (hasil17,"\n                       Harga %d Orang	: Rp. %d",jumlah_orang, price_orang);
					fprintf (hasil17,"\n");
					fprintf (hasil17,"\n                         Opsi Tambahan	: -");
					fprintf (hasil17,"\n");
					fprintf (hasil17,"\n=============================================================================");
					fprintf (hasil17,"\n");
					fprintf (hasil17,"\n	                           Total Biaya  : Rp. %d", total);
					fprintf (hasil17,"\n");
					fprintf (hasil17,"\n=============================================================================");
					fprintf (hasil17,"\n 		Anda mendapatkan diskon sebesar 20 persen!");
					fprintf (hasil17,"\n");
					fprintf (hasil17,"\n 		Potongan harga : Rp. %d", diskon2);
					fprintf (hasil17,"\n");
					fprintf (hasil17,"\n 		Total Biaya : Rp. %d", total2);
					fprintf (hasil17,"\n");
					fprintf (hasil17,"\n=============================================================================");
					fprintf (hasil17,"\n 		Bayar : Rp. %d", bayar);
					fprintf (hasil17,"\n		Kembalian : Rp. %d", kembaliandisc2);
					fclose (hasil17);
				}
				else {
					printf ("\n 		Potongan harga : Rp. -");
					printf ("\n");
					printf ("\n 		Total Biaya : Rp. %d", total);
					printf ("\n");
					printf ("\n=============================================================================");
					printf ("\n 		Bayar : Rp. ");
					scanf ("%d", &bayar);
                    			kembalian=bayar-total;
					printf ("\n			Kembalian : Rp. %d", kembalian);
					//struk
					FILE * hasil18;
					hasil18=fopen("transaction.txt","w");
					fprintf (hasil18,"\n|                              RINCIAN BIAYA                                |");
					fprintf (hasil18,"\n=============================================================================");
					fprintf (hasil18,"\n");
					fprintf (hasil18,"\n              Harga Sewa %d Fotografer	: Rp. %d",jumlah_fotografer, price_fotografer);
					fprintf (hasil18,"\n");
					fprintf (hasil18,"\n             Harga Sewa %d Videografer	: Rp. %d",jumlah_videografer, price_videografer);
					fprintf (hasil18,"\n");
					fprintf (hasil18,"\n                       Harga %d Orang	: Rp. %d",jumlah_orang, price_orang);
					fprintf (hasil18,"\n");
					fprintf (hasil18,"\n                         Opsi Tambahan	: -");
					fprintf (hasil18,"\n");
					fprintf (hasil18,"\n=============================================================================");
					fprintf (hasil18,"\n");
					fprintf (hasil18,"\n	                           Total Biaya  : Rp. %d", total);
					fprintf (hasil18,"\n");
					fprintf (hasil18,"\n=============================================================================");
					fprintf (hasil18,"\n 		Potongan harga : Rp. -");
					fprintf (hasil18,"\n");
					fprintf (hasil18,"\n 		Total Biaya : Rp. %d", total);
					fprintf (hasil18,"\n");
					fprintf (hasil18,"\n=============================================================================");
					fprintf (hasil18,"\n 		Bayar : Rp. %d", bayar);
					fprintf (hasil18,"\n		Kembalian : Rp. %d", kembalian);
					fclose (hasil18);
				}
			}

		}


		else {
			printf ("! MOHON MASUKKAN KODE YANG SESUAI DENGAN NOMOR MENU !");
		}

		printf ("\n\nReturn (R) or Quit (Q) : ");
		scanf (" %c", &kembali);
	}
	

	return 0;
}
