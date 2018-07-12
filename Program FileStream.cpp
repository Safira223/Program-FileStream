#include <iostream>//untuk menjalankan program
#include <conio.h>//fungsi jeda pada return/getch
#include <fstream>//untuk menjalankan fungsi pengendali sistem desktop
#include <windows.h>
#define max 10
using namespace std;
	
struct Tumpukan{
	int atas;
	int data[max];
	}T;
	
void Awal(){
	T.atas=-1;}
	
int Kosong(){
	if(T.atas==-1)
	   return 1;
	else
	   return 0;}
	
int Penuh(){
	if(T.atas==max-1)
	   return 1;
	else
	   return 0;}
	
void Input(int data){
	if(Kosong()==1){
	    T.atas++;
	    T.data[T.atas]=data;
	    cout<<"  Data "<<T.data[T.atas]<<" masuk ke tumpukan";}
	
	else if(Penuh()==0){
	    T.atas++;
	    T.data[T.atas]=data;
	    cout<<"  Data "<<T.data[T.atas]<<" masuk ke tumpukan";}
	
	else
		cout<<"  Tumpukan Penuh";
	}
	
void Hapus(){
	if(Kosong()==0){
		cout<<"  Data paling atas terhapus";
		T.data[T.atas]=0;
			T.atas--;}
	
	else
		cout<<"  Data Kosong";}
	
void Tampil(){
	if(Kosong()==0){
	    for(int i=T.atas;i>=0;i--){
	    cout<<"\nTumpukan ke "<<i<<"="<<T.data[i];
	}
}
	
	else
	    cout<<"  Tumpukan Kosong";}
	
void Simpan(){
	ofstream input;
	input.open("data.txt");//fungsi pada stream untuk melakukan proses membaca file pada fstream
	    for(int i=T.atas;i>=0;i--){
		input<<" Tumpukan ke-"<<i<<": "<<T.data[i];
		
	    input<<endl;}
			
		input.close();}
	
int main(){
	int no,data;
	Awal();
	
	do{
		system("cls");
		cout<<"\t\tMenu Pilihan"<<endl;
		cout<<"\t============================="<<endl<<endl;
		cout<<"\t<1> Input Data"<<endl;
		cout<<"\t<2> Hapus Data"<<endl;
		cout<<"\t<3> Tampilkan Data"<<endl;
		cout<<"\t<4> Simpan ke Notepad"<<endl;
		cout<<"\t<5> Keluar"<<endl;
		cout<<"\n\n";
		cout<<"  Masukan pilihan: ";
		cin>>no;
		
		switch(no){
		case 1:cout<<"  Input data = ";
			cin>>data;
			Input(data);
		    break;
		case 2:Hapus();
			break;
		case 3:Tampil();
			break;
		case 4:Simpan();
			break;
		case 5: cout<<"Thank You for Using";
			break;
		}

getch();
}
	while(no!=6);
}
