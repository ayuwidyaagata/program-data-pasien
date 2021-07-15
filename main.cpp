#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct pasien{
	long long int id;
	char tanggal[50];
	char usia[50];
	char nama[50];
	char dokter[50];
	char diagnosa[50];
	struct pasien * next;
};

int pilih2;
struct pasien *head = NULL;
struct pasien *tail = NULL;

//menambahkan data pasien awal, menggunakan sisip awal
void pasien_tambahAwal(long long int id, char tanggal[], char usia[], char nama[], char dokter[], char diagnosa[]){
	struct pasien * newData = (struct pasien*)malloc(sizeof(struct pasien));
	newData->id = id;
	strcpy(newData->tanggal, tanggal);
	strcpy(newData->usia, usia);
	strcpy(newData->nama, nama);
	strcpy(newData->dokter, dokter);
	strcpy(newData->diagnosa, diagnosa);
	
	if(head==NULL){
		head = newData;
		head->next = NULL;
	}
	else{
		newData->next = head;
		head = newData;
	}
}

//menambahkan data akhir, menggunakan sisip akhir
void pasien_tambahAkhir(long long id, char tanggal[], char usia[], char nama[], char dokter[], char diagnosa[]){
	struct pasien* newData = (struct pasien*)malloc(sizeof(struct pasien));
	newData->id = id;
	strcpy(newData->tanggal, tanggal);
	strcpy(newData->usia, usia);
	strcpy(newData->nama, nama);
	strcpy(newData->dokter, dokter);
	strcpy(newData->diagnosa, diagnosa);
	
	if(head==NULL){
		head = newData;
		head->next = NULL;
	}
	else{
		tail = head;
		while(tail->next != NULL){
		tail = tail->next;
		}
		tail->next = newData;
		tail = newData;
		tail->next = NULL;
	}
}

//mengupdate data pasien (edit data)
void pasien_updateData(long long id){
	int i=1;
	bool exist = false;
	struct pasien* temp = head;
	while(temp != NULL){
		if(temp->id == id){
			cout<<"======================================================"<<endl;
			cout<<"\tMASUKKAN DATA PASIEN YANG BARU "<<endl;
			cout<<"======================================================"<<endl;
			cout<<"ID Pasien\t\t: "; cin>>temp->id;
			cout<<"Tanggal Periksa\t\t: "; cin.ignore(); cin.getline(temp->tanggal, 50); 
			cout<<"Usia\t\t\t: "; cin.getline(temp->usia, 50);
			cout<<"Nama Pasien\t\t: "; cin.getline(temp->nama, 50);
			cout<<"Dokter Periksa\t\t: "; cin.getline(temp->dokter, 50);
			cout<<"Hasil Diagnosa\t\t: "; cin.getline(temp->diagnosa, 50);
			cout<<""<<endl;
			exist = true;	
		}
		temp = temp->next;	
	}
	if(!exist){
		cout<<"======================================================"<<endl;
		cout<<"\tMaaf ID Paseien TIDAK DITEMUKAN! "<<endl;
		cout<<"======================================================"<<endl;
	}
}

//menampilkan data pasien
void pasien_tampilData(){
	cout<<"======================================================"<<endl;
	cout<<"\t\tDATA PASIEN RUMAH SAKIT MEDIKA "<<endl;
	cout<<"======================================================"<<endl;
	int i=1;
	struct pasien* temp = head;
	while(temp != NULL){
		cout<<"Data Pasien ke - "<< i<<endl; i++;
		cout<<"ID Pasien\t\t: "<< temp->id<<endl;
		cout<<"Tanggal Periksa\t\t: "<< temp->tanggal<<endl;
		cout<<"Usia\t\t\t: "<< temp->usia<<endl;
		cout<<"Nama Pasien\t\t: "<< temp->nama<<endl;
		cout<<"Dokter Periksa\t\t: "<< temp->dokter<<endl;
		cout<<"Hasil Diagnosa\t\t: "<< temp->diagnosa<<endl;
		cout<<""<<endl;
		temp = temp->next;
	}
}

bool isEmpty(){
    //cek apakah linkedlist kosong atau tidak
    if (head==NULL){
        return true; 	//true=1
    }
    else return false;	//false=0
}

//mencari data pasien
void pasien_cariData(long long id){
	int i=1;
	bool exist = false;
	struct pasien* temp = head;
	while(temp != NULL){
		if(temp->id == id){
			cout<<"======================================================"<<endl;
			cout<<"\tDATA PASIEN RUMAH SAKIT MEDIKA DITEMUKAN "<<endl;
			cout<<"======================================================"<<endl;
			cout<<"Data Pasien ke - "<< i<<endl; i++;
			cout<<"ID Pasien\t\t: "<< temp->id<<endl;
			cout<<"Tanggal Periksa\t\t: "<< temp->tanggal<<endl;
			cout<<"Usia\t\t\t: "<< temp->usia<<endl;
			cout<<"Nama Pasien\t\t: "<< temp->nama<<endl;
			cout<<"Dokter Periksa\t\t: "<< temp->dokter<<endl;
			cout<<"Hasil Diagnosa\t\t: "<< temp->diagnosa<<endl;
			cout<<""<<endl;
			exist = true;	
		}
		temp = temp->next;	
	}
	if(!exist){
		cout<<"======================================================"<<endl;
		cout<<"\tMaaf Data yang Dicari TIDAK DITEMUKAN! "<<endl;
		cout<<"======================================================"<<endl;
	}
}

//menghapus data pasien
void pasien_hapusData(int posisi)
{
    if(posisi==1)
    {
        if(isEmpty()==true)
        {
            cout<<"\t\tMAAF DATA MASIH KOSONG"<<endl;
        }
        else
        {
            pasien* delfirst=head;
            head=delfirst->next;
            free(delfirst);
            pasien_tampilData();
        }
        return;
    }
    pasien *current=head;
    pasien *prev;
    for(int i=1;i<posisi;i++)
    {
        prev=current;
        current=current->next;
    }
    prev->next=current->next;
    delete current;
}

int main(){
	int pilihan, pilih2, posisi;
	long long id, tempId, updateId;
	char tanggal[50];
	char usia[50];
	char nama[50];
	char dokter[50];
	char diagnosa[50];
	
	system("cls");
	cout<<"======================================================"<<endl;
	cout<<"\t\tMasukkan Data Pasien"<<endl;
	cout<<"======================================================"<<endl;
	cout<<"1. Tambah Data Pasien"<<endl;
	cout<<"2. Tambah Pasien Selanjutnya"<<endl;
	cout<<"3. Tampilkan Data Pasien"<<endl;
	cout<<"4. Update Data Pasien"<<endl;
	cout<<"5. Cari Data Pasien"<<endl;
	cout<<"6. Hapus Data Pasien"<<endl;
	cout<<"0. Cancel"<<endl;
	cout<<"======================================================"<<endl;
	cout<<"Masukkan Pilihan : "<<endl;
	cin>>pilihan;
	cout<<"======================================================"<<endl;
	switch(pilihan){
		
		case 1:{
			cout<<"ID Pasien\t\t: "; cin>>id;
			cout<<"Tanggal Periksa\t\t: "; cin.ignore(); cin.getline(tanggal, 50); 
			cout<<"Usia\t\t\t: "; cin.getline(usia, 50);
			cout<<"Nama Pasien\t\t: "; cin.getline(nama, 50);
			cout<<"Dokter Periksa\t\t: "; cin.getline(dokter, 50);
			cout<<"Hasil Diagnosa\t\t: "; cin.getline(diagnosa, 50);
			pasien_tambahAwal(id, tanggal, usia, nama, dokter, diagnosa);
			break;	
		}
		case 2:{
			cout<<"ID Pasien\t\t: "; cin>>id;
			cout<<"Tanggal Periksa\t\t: "; cin.ignore(); cin.getline(tanggal, 50);
			cout<<"Usia\t\t\t: "; cin.getline(usia, 50);
			cout<<"Nama Pasien\t\t: "; cin.getline(nama, 50);
			cout<<"Dokter Periksa\t\t: "; cin.getline(dokter, 50);
			cout<<"Hasil Diagnosa\t\t: "; cin.getline(diagnosa, 50);
			pasien_tambahAkhir(id, tanggal, usia, nama, dokter, diagnosa);
			break;	
		}
		case 3:{
			system("cls");
			pasien_tampilData();
			break;			
		}
		case 4:{
			system("cls");
			pasien_tampilData();
			cout<<("======================================================\n");
			cout<<("\tMasukkan ID Pasien yang akan di Update Datanya\n");
			cout<<("======================================================\n");
			cout<<"ID Pasien\t\t: "; cin>>updateId;
			pasien_updateData(updateId);
			break;
		}
		case 5:{
			system("cls");
			cout<<("======================================================\n");
			cout<<("\t\tCari Data Pasien Berdasarkan ID\n");
			cout<<("======================================================\n");
			cout<<"ID Pasien\t\t: "; cin>>tempId;
			pasien_cariData(tempId);
			break;	
		}
		case 6:{
			pasien_tampilData();
	        cout<<"Pilih Posisi : ";cin>>posisi;
	        pasien_hapusData(posisi);
			break;
		
		}
		case 0:{
			break;
			
		}
		default:{
			system("cls");
			cout<<"Error!";
			//break;
		}
	}
	cout<<"\nKembali ke Menu Awal?";
	cout<<"\n[1] Ya\n[2] Tidak";
	cout<<"\nPilih : ";
	cin>>pilih2;
	if(pilih2==1){
		system("cls");
		main();	
	} 
	else if(pilih2==2){
		system("cls");
		cout<<"\nTerima Kasih";
	}
}
