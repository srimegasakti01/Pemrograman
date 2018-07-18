#include<iostream>
//#include <string>
//#include <stdlib.h>
#include<iomanip>
#include <conio.h>

using namespace std;

struct rekening_bank {	
        string nama;
        long int norek;
        double saldo;  	     	
}; rekening_bank nas[50];

class datanasabah {	
private:        
        int i,no,n=0,x;
        double setor,tarik;		             
public:
	void daftar();
	void nabung();
	void ambil();
	void cetak();
	void cari();
	bool ketemu = false;
};
                
void datanasabah :: cetak(){
	rekening_bank data;
				system("cls");
				cout<<endl<<endl<<"      DAFTAR NASABAH BANK"<<endl;
                cout<<"|====|=================|==============|==============|"<<endl;
                cout<<"| No |   No Rekening   |     Nama     | Total Saldo  |"<<endl;
                cout<<"|====|=================|==============|==============|"<<endl;
                for(i=0;i<n;i++)
                {
				cout<<setiosflags(ios::left)<<setw(9)<<i+1;
                cout<<setiosflags(ios::left)<<setw(17)<<nas[i].norek;
                cout<<setiosflags(ios::left)<<setw(14)<<nas[i].nama;
                cout<<setiosflags(ios::left)<<setw(14)<<((nas[i].saldo)+(nas[i].saldo*0.1))<<endl;
            	}
				cout<<"|====|=================|==============|==============|"<<endl;
                cout<<"jumlah total saldo diatas setelah ditambah bunga 10%"<<endl<<endl;
                cout<<"masukkan sembarang angka untuk kembali ke menu utama --> ";cin>>x;         
		}
void datanasabah :: nabung(){
	rekening_bank data;

		cout<<"masukkan no rekening     --> ";cin>>no;
		for(i=0; i<n; i++)
		{
			if (no==(nas[i].norek))
				{		    
					ketemu=true;
					break;
				}
			else
					ketemu=false;
				}			
		if (ketemu)
			{
			cout<<"masukkan jumlah setoran  --> ";cin>>setor;
			nas[i].saldo=nas[i].saldo+setor;
			cout<<endl;
			}
		else
			cout<<"nomor rekening tidak ditemukan"<<endl<<endl;
			cout<<"Tekan ENTER untuk kembali ke menu utama --> ";cin>>x;
	}
void datanasabah :: ambil(){
	rekening_bank data;

		cout<<"masukkan no rekening      --> ";cin>>no;
            for(i=0; i<n; i++)
			{
		        if (no==(nas[i].norek))
					{
				        ketemu=true;
				        break;
					}
				else
				        ketemu=false;
					}
			if (ketemu)
			{
				cout<<"masukkan jumlah penarikan --> ";cin>>tarik;
	            if (tarik<(nas[i].saldo))
					{
						nas[i].saldo=nas[i].saldo-tarik;
			            cout<<endl;
					}
				else
				        cout<<"maaf saldo anda tidak mencukupi"<<endl;
					}
			else
			    cout<<"nomor rekening tidak ditemukan"<<endl<<endl;
			    cout<<"Tekan ENTER untuk kembali ke menu utama --> ";cin>>x;					
		}
				
void datanasabah :: daftar (){
	rekening_bank data;

		lagi:
		cout<<"masukkan nomer rekening     --> ";cin>>no;
        for(i=0; i<n; i++)
			{
		    if (no==(nas[i].norek))
				{
				    ketemu=true;
				    break;
				}
			else
				    ketemu=false;
				}
        if (ketemu)
			{
		        cout<<"nomor rekening tersebut sudah ada, ulangi lagi"<<endl;
		        goto lagi;
			}
        else
			{
		        cout<<"masukkan nama anda          --> ";cin>>nas[n].nama;
		        cout<<"masukkan saldo awal anda    --> ";cin>>nas[n].saldo;
			}
		        n=n+1;
                nas[i].norek=no;
                cout<<"Tekan ENTER untuk kembali ke menu utama --> ";cin>>x;				
		}		
void datanasabah :: cari(){
	rekening_bank data;
					
	    cout<<"masukkan no rekening      --> ";cin>>no;
        for(i=0; i<n; i++)
		{
		    if (no==(nas[i].norek))
				{
				    ketemu=true;
				    break;
				}
			else
				    ketemu=false;
				}
		if (ketemu)
			{
                cout<<"Nomor Rekening               : "<<nas[i].norek<<endl;
                cout<<"Nama Nasabah                 : "<<nas[i].nama<<endl;
                cout<<"Saldo                        : "<<nas[i].saldo<<endl;
                cout<<"Total Saldo Setelah Bunga    : "<<((nas[i].saldo)+(nas[i].saldo*0.1))<<endl<<endl;
			}
        else
                cout<<"nomor rekening tidak ditemukan"<<endl<<endl;
		        cout<<"Tekan ENTER untuk kembali ke menu utama --> ";cin>>x;		
		}
		

int main(){             
	datanasabah data;
	int menu;
                menuutama:
                system("cls");
                cout<<"============================"<<endl;
                cout<<"|    Bank Kecil-Kecilan    |"<<endl;
                cout<<"============================"<<endl;
                cout<<"|    ' Menu Transaksi '    |"<<endl;
                cout<<"| 1. Pendaftaran Nasabah   |"<<endl;
                cout<<"| 2. Penyetoran            |"<<endl;
                cout<<"| 3. Penarikan             |"<<endl;
                cout<<"| 4. Cetak Daftar Nasabah  |"<<endl;
                cout<<"| 5. Cari Nasabah          |"<<endl;
                cout<<"| 6. Keluar                |"<<endl;
                cout<<"============================"<<endl;
                cout<<endl;
                cout<<"Pilihan anda --> ";
                cin>> menu;
				while(menu !=6){	
				if (menu==1){
					data.daftar();
					cout<<"Data disimpan";
					goto menuutama;}
				else if (menu==2){
					data.nabung();					
					goto menuutama;}
				else if (menu==3){
					data.ambil();
					goto menuutama;}
				else if (menu==4){
					data.cetak();
					goto menuutama;}
				else if (menu==5){
					data.cari();					
					goto menuutama;}
				else if (menu==6){
					exit(0);
					cout<<endl<<"Terimakasih Telah Bertransaksi Disini . . ."<<endl<<endl;
					}
				}
		}



