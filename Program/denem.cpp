#include<iostream>

using namespace std;

class zaman{ //Zaman Sınıfı
    private:
    int saat;
    int dakika;
    public:

};

class kiyafet{ //Kıyafe sınıfı
    private:
    char *kategori;
    char kiyafet_adi;
    double fiyat;
    char* boyut;
    char* renk;
    public: //Yapıcı fonksiyon

};

class kisi{
    private:
    char* ad_soyad;
    char telNo;
    public:

};

class siparis : kiyafet{
    private:
    int siparis_No;
    double siparis_fiyat;
    zaman siparis_baslangic;
    zaman siparis_ulasim;
    public:

};

class kullanici : kisi{
    private:
    char* kullanici_adi;
    char* eposta;
    char* adres;
    char* sifre;
    char* indirim,_kodu;
    char* dtarihi;
    public:

};

class yonetici : kisi{
    private:
    char* sifre;
    public:

};

class kurye : kisi{
    private:
    zaman* dagitim_bitisler;
    int* siparis_numaraları;
    public:

};

int main(){

    return 0;
}

