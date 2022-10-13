#include<iostream>

using namespace std;

class zaman{ //Zaman Sınıfı
    private:
    int saat;
    int dakika;
    public:
    void setSaat(int s){ //Saat değerini ayarlar
        saat = s;
    }
    void setDakika(int d){ //Dakika değerini ayarlar
        dakika = d;
    }
    int getSaat(){ //Saat değerini döndürür
        return saat;
    }
    int getDakika(){ //Dakika değerini döndürür
        return dakika;
    }
    void yazdir(){ //Saat ve dakika değerlerini ekrana yazdırır
        cout << saat << ":" << dakika << endl;
    }
    void gecikme(int s, int d){ //Saat ve dakika değerlerini gecikme değerleri kadar arttırır
        saat += s;
        dakika += d;
        if(dakika >= 60){
            saat += dakika / 60;
            dakika = dakika % 60;
        }
        if(saat >= 24){
            saat = saat % 24;
        }
    }

    friend ostream& operator<<(ostream &os, const zaman &z){
        return os;
    }



};

class kiyafet{ //Kıyafe sınıfı
    private:
    char *kategori;
    char kiyafet_adi;
    double fiyat;
    char* boyut;
    char* renk;
    public: //Yapıcı fonksiyon
    void setKategori(char *k){
        kategori = k;
    }
    void setKiyafetAdi(char k){
        kiyafet_adi = k;
    }
    void setFiyat(double f){
        fiyat = f;
    }
    void setBoyut(char *b){
        boyut = b;
    }
    void setRenk(char *r){
        renk = r;
    }
    char* getKategori(){
        return kategori;
    }
    char getKiyafetAdi(){
        return kiyafet_adi;
    }
    double getFiyat(){
        return fiyat;
    }
    char* getBoyut(){
        return boyut;
    }
    char* getRenk(){
        return renk;
    }
    void yazdir(){
        cout << "Kategori: " << kategori << endl;
        cout << "Kiyafet Adi: " << kiyafet_adi << endl;
        cout << "Fiyat: " << fiyat << endl;
        cout << "Boyut: " << boyut << endl;
        cout << "Renk: " << renk << endl;
    }

};

class kisi{
    private:
    char* ad_soyad;
    char telNo;
    public:
    void setAdSoyad(char *a){
        ad_soyad = a;
    }
    void setTelNo(char t){
        telNo = t;
    }
    char* getAdSoyad(){
        return ad_soyad;
    }
    char getTelNo(){
        return telNo;
    }
    void yazdir(){
        cout << "Ad Soyad: " << ad_soyad << endl;
        cout << "Tel No: " << telNo << endl;
    }


};

class siparis : kiyafet{
    private:
    int siparis_No;
    double siparis_fiyat;
    zaman siparis_baslangic;
    zaman siparis_ulasim;
    public:
    void setSiparisNo(int s){
        siparis_No = s;
    }
    void setSiparisFiyat(double f){
        siparis_fiyat = f;
    }
    void setSiparisBaslangic(zaman s){
        siparis_baslangic = s;
    }
    void setSiparisUlasim(zaman u){
        siparis_ulasim = u;
    }
    int getSiparisNo(){
        return siparis_No;
    }
    double getSiparisFiyat(){
        return siparis_fiyat;
    }
    zaman getSiparisBaslangic(){
        return siparis_baslangic;
    }
    zaman getSiparisUlasim(){
        return siparis_ulasim;
    }
    void yazdir(){
        cout << "Siparis No: " << siparis_No << endl;
        cout << "Siparis Fiyat: " << siparis_fiyat << endl;
        cout << "Siparis Baslangic: " << siparis_baslangic << endl;
        cout << "Siparis Ulasim: " << siparis_ulasim << endl;
    }

};

class kullanici : kisi{
    private:
    char* kullanici_adi;
    char* eposta;
    char* adres;
    char* sifre;
    char* indirim_kodu;
    char* dtarihi;
    public:
    void setKullaniciAdi(char *k){
        kullanici_adi = k;
    }
    void setEposta(char *e){
        eposta = e;
    }
    void setAdres(char *a){
        adres = a;
    }
    void setSifre(char *s){
        sifre = s;
    }
    void setIndirimKodu(char *i){
        indirim_kodu = i;
    }
    void setDTarihi(char *d){
        dtarihi = d;
    }
    char* getKullaniciAdi(){
        return kullanici_adi;
    }
    char* getEposta(){
        return eposta;
    }
    char* getAdres(){
        return adres;
    }
    char* getSifre(){
        return sifre;
    }
    char* getIndirimKodu(){
        return indirim_kodu;
    }
    char* getDTarihi(){
        return dtarihi;
    }
    void yazdir(){
        cout << "Kullanici Adi: " << kullanici_adi << endl;
        cout << "Eposta: " << eposta << endl;
        cout << "Adres: " << adres << endl;
        cout << "Sifre: " << sifre << endl;
        cout << "Indirim Kodu: " << indirim_kodu << endl;
        cout << "Dogum Tarihi: " << dtarihi << endl;
    }


};

class yonetici : kisi{
    private:
    char* sifre;
    public:
    void setSifre(char *s){
        sifre = s;
    }
    char* getSifre(){
        return sifre;
    }
    void yazdir(){
        cout << "Sifre: " << sifre << endl;
    }

};

class kurye : kisi{
    private:
    zaman* dagitim_bitisler;
    int* siparis_numaraları;
    public:
    void setDagitimBitisler(zaman *d){
        dagitim_bitisler = d;
    }
    void setSiparisNumaralari(int *s){
        siparis_numaraları = s;
    }
    zaman* getDagitimBitisler(){
        return dagitim_bitisler;
    }
    int* getSiparisNumaralari(){
        return siparis_numaraları;
    }
    void yazdir(){
        cout << "Dagitim Bitisler: " << dagitim_bitisler << endl;
        cout << "Siparis Numaralari: " << siparis_numaraları << endl;
    }

};

int main(){

    zaman d;
    d.setSaat(23);
    d.setDakika(59);
    d.gecikme(0, 70);
    d.yazdir();

    return 0;
}
