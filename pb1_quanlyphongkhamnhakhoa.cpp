#include <iostream >
#include<string >
#include<vector>
#include<math.h>
#include <fstream>
using namespace std;
class NGUOI {
	private:

	protected:
		int id ; 		
		string hovaten;
		int tuoi ;
		int SDThoai ;
		string gioi_tinh;		 					
	public:
		int getid(){return id;	}
		string gethovaten() { return hovaten; }
        int gettuoi() { return tuoi; }
        int getSDThoai() { return SDThoai; }
        string getgioi_tinh() { return gioi_tinh; }
}; 
class BENH_NHAN : public NGUOI{
	private:
		string tien_su_benh_ly ;		 
	protected:
	public:
		BENH_NHAN(){
		}		
		BENH_NHAN(int a,string b,int c,int d,string e,string f ){
			id = a ;
			hovaten = b ;
			tuoi = c ;
			SDThoai = d ; 
			gioi_tinh = e;
			tien_su_benh_ly = f; 
		} 
		~BENH_NHAN(){
			
		}
		void show1 (){
			cout << "["<< id << "]  "<< hovaten << endl;
			cout << "Tuoi: "<< tuoi << endl;
			cout << "Gioi tinh : "<< gioi_tinh  << endl;
			cout << "so dien thoai : "<< SDThoai << endl;
			cout << "tien su benh ly : "<< tien_su_benh_ly << endl;
		}
		string gettien_su_benh_ly(){ return tien_su_benh_ly;	}	 
}; 
class DICH_VU {
	private:
		int id;
		string ten_dich_vu;
		int gia; 
	protected:
	public:
		DICH_VU(int a,string b,int c){
			id = a ;
			ten_dich_vu =b ;
			gia = c;
		}
		~DICH_VU(){
		}
		void show (){
			cout << "["<<id <<"]"; 
			cout << " dich vu :"<< ten_dich_vu<<endl; 
			cout << "gia"<< gia << "vnd"<<endl; 
			 
		} 
		int getid(){ return id;		}
		string getten_dich_vu(){ return ten_dich_vu ;		}
		int getgia (){ return gia ;		}
	 
}; 
class BAC_SI : public NGUOI {
	private:
		string chuyen_mon ;
		int luong;
		int thuong; 
		  
	protected:
	public:
		BAC_SI (){
		}
		BAC_SI (int a, string b , int c ,int d ,string e,string f ){
			id = a ;
			hovaten = b ;
			tuoi = c ;
			SDThoai = d ; 
			gioi_tinh = e; 
			chuyen_mon = f;			
		}
		~BAC_SI(){
			
		} 
		void show2 (){
			cout << "["<< id << "]  "<< hovaten << endl;
			cout << "Tuoi: "<< tuoi << endl;
			cout << "Gioi tinh : "<< gioi_tinh  << endl;
			cout << "so dien thoai : "<< SDThoai << endl;
			cout << "Chuyen mon : "<< chuyen_mon << endl;

		}
        string getchuyen_mon() { return chuyen_mon; }
};
class HEN_KHAM {
	private:
		string lich ;   //dd/mm/yy
		
	protected:
	public:
};
class HO_SO {
	private:
	protected:
	public:	 
};
class QUAN_LY {
	private:
		vector <BENH_NHAN> benhnhan;
		vector <BAC_SI> bacsi;
		vector <DICH_VU> dichvu;
		string matkhau = "mk12345";
		
	protected:
	public:
		QUAN_LY(){
		} 
		bool  checkmatkhau(string s ){
			if (s!= matkhau){
				cout << "Mat khau sai hay nhap lai mat khau"<< endl;
				return true;
			}
			return false;
		}
	// --- QUAN LÝ BÁC SI ---
	void docfilebacsi (){
		ifstream f ;
		f.open("bacsi.txt");
		if (! f.is_open()){return;}
		int id,tuoi,SDThoai;
		string hovaten,gioi_tinh,chuyen_mon;
		while(f>> id){
			f.ignore();
			getline(f,hovaten);
			f>> tuoi;
			f>> SDThoai;
			f.ignore();
			getline(f,gioi_tinh);
			f.ignore();
			getline(f,chuyen_mon);
			bacsi.push_back(BAC_SI(id,hovaten,tuoi,SDThoai,gioi_tinh,chuyen_mon));
		}
		
	f.close();	
	} 
	void ghifilebacsi(){
		fstream f ;
		f.open("bacsi.txt",ios :: out);

		for (int i=0;i<bacsi.size();i++){
			f<< bacsi[i].getid()<<endl;
			f<< bacsi[i].gethovaten()<<endl;
			f<< bacsi[i].gettuoi()<<endl;
			f<< bacsi[i].getSDThoai()<<endl;
			f<< bacsi[i].getgioi_tinh()<<endl;
			f<< bacsi[i].getchuyen_mon()<<endl;
			}
			f.close();
	} 
    void addbacsi() {
        string ten, chuyenmon,gioitinh;
        int id , sdt, tuoi ;
        cout << "--- THEM BAC SI MOI ---"<< endl; 
        cout << "Nhap ID Bac si: "; cin >> id;
        cin.ignore();
        cout << "Nhap Ten Bac si: "; getline(cin, ten);
        cout << "Nhap Tuoi: "; cin >> tuoi;
        cout << "Nhap So dien thoai: "; cin >> sdt;
        cin.ignore();
        cout << "Nhap gioi tinh  " ;getline(cin,gioitinh ) ;       
        cin.ignore();
        cout << "Nhap chuyen mon : "; getline(cin, chuyenmon);
        

        bacsi.push_back(BAC_SI(id, ten, tuoi, sdt , gioitinh,chuyenmon));
        cout << ">> Them bac si thanh cong!\n";	
        ghifilebacsi();
    }
    void listbacsi()  {
        cout << "\n=================================== DANH SACH BAC SI ===================================\n";
        for (int i=0;i < bacsi.size();i++ ){
        	cout << "[" << bacsi[i].getid()<<"]  " << bacsi[i].gethovaten() << "SDT" << bacsi[i].getSDThoai()<< endl;        	
		}
	}
	void xoabacsi(){
		int id ; cout << "nhap id bac si can xoa   " ;cin >> id;
		for (int i=0;i<bacsi.size();i++){
			if (bacsi[i].getid() ==id){
				bacsi[i].~BAC_SI();
				cout << "bac si co id "<< id<< "da bi xoa"<< endl;
			}
		}
	}
// -------QUAN LY BENH NHAN-----------
    void docfilebenhnhan (){
    	ifstream f;
    	f.open("benhnhan.txt");
    	if (! f.is_open()){ return; }
		int id,tuoi,SDThoai;
		string hovaten,gioi_tinh,tien_su_benh_ly;
		while(f>> id){
			f.ignore();
			getline(f,hovaten);
			f>> tuoi;
			f>> SDThoai;
			f.ignore();
			getline(f,gioi_tinh);
			f.ignore();
			getline(f,tien_su_benh_ly);
			benhnhan.push_back(BENH_NHAN(id,hovaten,tuoi,SDThoai,gioi_tinh,tien_su_benh_ly));
		}
		f.close();

	}
	void ghifilebenhnhan (){
		ofstream f ;
		f.open("benhnhan.txt",ios :: out);
		if (! f.is_open()){ return;
		}
		for (int i=0;i<bacsi.size();i++){
			f<< benhnhan[i].getid()<<endl;
			f<< benhnhan[i].gethovaten()<<endl;
			f<< benhnhan[i].gettuoi()<<endl;
			f<< benhnhan[i].getSDThoai()<<endl;
			f<< benhnhan[i].getgioi_tinh()<<endl;
			f<< benhnhan[i].gettien_su_benh_ly()<<endl;
			}
		f.close();		
	}
    void addbenhnhan() {
        string ten, benhly,gioitinh;
        int id , sdt, tuoi ;
        cout << "--- THEM BENH NHAN MOI ---"<< endl; 
        cout << "Nhap ID benh nhan: "; cin >> id;
        cin.ignore();
        cout << "Nhap Ten benh nhan: "; getline(cin, ten);
        cout << "Nhap Tuoi: "; cin >> tuoi;
        cout << "Nhap So dien thoai: "; cin >> sdt;
        cin.ignore();
        cout << "Nhap gioi tinh  " ;getline(cin,gioitinh ) ;       
        cin.ignore();
        cout << "Nhap tien su benh ly : "; getline(cin, benhly);
        

        benhnhan.push_back(BENH_NHAN(id, ten, tuoi, sdt , gioitinh,benhly));
        cout << ">> Them benh nhan thanh cong!\n";	
    }
    void listbenhnhan()  {
        cout << "\n=================================== DANH SACH BENH NHAN ===================================\n";
        for (int i=0;i < benhnhan.size();i++ ){
        	cout << "[" << benhnhan[i].getid()<<"]  " << benhnhan[i].gethovaten() << "SDT" << benhnhan[i].getSDThoai()<< endl;        	
		}
	}
	void xoabenhnhan(){
		int id ; cout << "nhap id benh nhan can xoa   " ;cin >> id;
		for (int i=0;i<benhnhan.size();i++){
			if (benhnhan[i].getid() ==id){
				benhnhan[i].~BENH_NHAN();
				cout << "benh nhan co id "<< id<< "da bi xoa"<< endl;
			}
		}
    }
//---------QUAN LY DICH VU----------
    void docfiledichvu (){
    	ifstream f;
    	f.open("dichvu.txt");
    	if (! f.is_open()){ return; }
		int id,gia;
		string ten;
		while(f>> id){
			f.ignore();
			getline(f,ten);
			f>> gia;
			dichvu.push_back(DICH_VU(id,ten,gia));
		}
		f.close();

	}
	void ghifiledichvu (){
		ofstream f ;
		f.open("dichvu.txt",ios :: out);
		if (! f.is_open()){ return;
		}
		for (int i=0;i<dichvu.size();i++){
			f<< dichvu[i].getid()<<endl;
			f<< dichvu[i].getten_dich_vu()<<endl;
			f<< dichvu[i].getgia()<<endl;
		}
		    f.close();		
	}
    void adddichvu() {
        string ten;
        int id ,gia;
        cout << "--- THEM DICH VU MOI ---"<< endl; 
        cout << "Nhap ID dich vu: "; cin >> id;
        cin.ignore();
        cout << "Nhap ten dich vu "; getline(cin, ten);
        cout << "Nhap gia "; cin >> gia;
        

        dichvu.push_back(DICH_VU(id, ten, gia));
        cout << ">> Them benh nhan thanh cong!\n";	
    }
    void listdichvu()  {
        cout << "\n=================================== DANH SACH DICH VU ===================================\n";
        for (int i=0;i < dichvu.size();i++ ){
        	cout << "[" << dichvu[i].getid()<<"]  " << dichvu[i].getten_dich_vu() << "gia" << dichvu[i].getgia()<< endl;        	
		}
	}
//----------------CHUONG TRINH CHINH-------------------
	void trang1(){int a;
	    cout<< "=========================== QUAN LY PHONG KHAM NHA KHOA======================="<< endl;
    	cout << "moi chon chuc nang "<< endl;
    	cout <<"(1) Truong khoa "<<endl<< "(2) Bac si" <<endl<< "(3)Benh nhan "<< endl;
    	cout <<"Chon" ;cin >> a;
    	switch(a){
	    	case  1 :
	    	trang2(); break;
	    	case  2 :
	    	case  3 :			
	    	default : cout << "lua chon khong hop le"; break ;
    	};
    }
    void trang2(){
    	cout <<"-------------------------------------------------------------------------------------------------------------------"<< endl;
        string s;
    	cout<< " Hay nhap mat khau"<< endl; cin.ignore();
        do { getline(cin,s);
    	}while (checkmatkhau(s));
    	cout << " mat khau chinh sac"<<endl;
    	trang2_2();
    }
    void trang2_2(){
    	cout <<"----------------------------------------------------------------------------------------------------------------------"<< endl;
    	int i; 
    	cout <<"Moi chon chuc nang "<< endl;
		cout << "(1) Xem danh sach bac si "<< endl;
		cout << "(2) Xem danh sach benh nhan "<< endl;
		cout << "(3) Xem danh sach dich vu"<< endl;
		cout << "(4) Quay lai"<< endl;
		cout << "Chon" ;cin >> i;
		switch (i){
			case 1:
			listbacsi();
			trang3_1 ();
			break;
			case 2: listbenhnhan(); trang3_2(); break;
			case 3: listdichvu(); break;
			case 4: trang1();break;
			default : cout<< "lua chon khong hop le";break; 
		} 
    }
    void trang3_1 (){
		cout << "(1)them bac si moi " << endl;
		cout << "(2)Xoa bac si "<< endl;
		cout <<"(3) Quay lai"<< endl;
		int x ; cout << "chon "; cin >>x;
		switch (x){
			case 1:
				addbacsi(); trang3_1(); break;
			case 2:
				xoabacsi(); trang3_1();break;
			case 3:
				trang2_2();break;
		}    	
	}
	void trang3_2 (){
		cout << "(1) them benh nhan moi "<< endl;
		cout <<"(2) xoa benh nhan"<< endl;
		cout << "(3) quay lai"<< endl;
		int i; cout << "chon"  ;cin>>i;
		switch (i){
			case 1: addbenhnhan(); trang3_2();break;
			case 2: xoabenhnhan(); trang3_2 ();break;
			case 3: trang2_2();break;
		}
	}
			
};


int main (){
    QUAN_LY QUANLY1;    
    QUANLY1.trang1(); 
    QUANLY1.ghifilebacsi();
	return 0 ;
}

