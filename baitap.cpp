#include <iostream >
#include<string >
#include<vector>
#include<math.h>
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
}; 
class BENH_NHAN : public NGUOI{
	private:
		string tien_su_benh_ly ;
		string trieu_chung; 		 
	protected:
	public:
		BENH_NHAN(int a,string b,int c,int d,string e ){
			id = a ;
			hovaten = b ;
			tuoi = c ;
			SDThoai = d ; 
			gioi_tinh = e; 
		} 
		~BENH_NHAN(){
			
		}	 
}; 
class DICH_VU {
	private:
		int id;
		string ten_dich_vu;
		int gia; 
	protected:
	public:
		void show (){
			cout << "["<<id <<"]"; 
			cout << " dich vu :"<< ten_dich_vu<<endl; 
			cout << "gia"<< gia << "vnd"<<endl; 
			 
		} 
	 
}; 
class BAC_SI : public NGUOI {
	private:
		string chuyen_mon ;
		int luong;
		int thuong; 
		  
	protected:
	public:
		BAC_SI (int a, string b , int c ,int d ,string e ){
			id = a ;
			hovaten = b ;
			tuoi = c ;
			SDThoai = d ; 
			gioi_tinh = e; 			
		} 
};
class HEN_KHAM {
	private:
		int ngay ; int thang ; int nam ;
		 int id ;
		  
	protected:
	public:
};
class HOA_DON {
	private:
	protected:
	public:	 
};
class QUAN_LY {
	private:
	protected:
	public:	
};
int main (){
	cout<< "ok";
	return 0; 
} 
