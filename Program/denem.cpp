#include<iostream>
#include<vector>

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
    vector <kiyafet> kiyafetler;
    char *kategori;
    char kiyafet_adi;
    double fiyat;
    char* boyut;
    char* renk;
    public: //Yapıcı fonksiyon
    kiyafet(char *k, char ka, double f, char *b, char *r){
        kategori = k;
        kiyafet_adi = ka;
        fiyat = f;
        boyut = b;
        renk = r;
    }
    kiyafet(); //Yapıcı fonksiyon

    void setKiyafetler(vector <kiyafet> k){
        kiyafetler = k;
    }
    vector <kiyafet> getKiyafetler(){
        return kiyafetler;
    }
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
    void ekle(kiyafet k){
        kiyafetler.push_back(k);
    }
    void sil(char k){
        for(int i = 0; i < kiyafetler.size(); i++){
            if(kiyafetler[i].getKiyafetAdi() == k){
                kiyafetler.erase(kiyafetler.begin() + i);
            }
        }
    }
    void guncelle(char k, kiyafet k1){
        for(int i = 0; i < kiyafetler.size(); i++){
            if(kiyafetler[i].getKiyafetAdi() == k){
                kiyafetler[i] = k1;
            }
        }
    }
    void listele(){ //Kıyafetleri listeler
        for(int i = 0; i < kiyafetler.size(); i++){
            kiyafetler[i].yazdir();
        }
    }
    void listele(char *k){ //Kategoriye göre listeleme
        for(int i = 0; i < kiyafetler.size(); i++){
            if(kiyafetler[i].getKategori() == k){
                kiyafetler[i].yazdir();
            }
        }
    }
    void listele(char *r){ //Renge göre listeleme
        for(int i = 0; i < kiyafetler.size(); i++){
            if(kiyafetler[i].getRenk() == r){
                kiyafetler[i].yazdir();
            }
        }
    }
    void listele(double f){ //Fiyata göre listeleme
        for(int i = 0; i < kiyafetler.size(); i++){
            if(kiyafetler[i].getFiyat() == f){
                kiyafetler[i].yazdir();
            }
        }
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
    vector<siparis> siparisler;
    int siparis_No;
    double siparis_fiyat;
    zaman siparis_baslangic;
    zaman siparis_ulasim;
    public:
    void setSiparisler(vector<siparis> s){
        siparisler = s;
    }
    vector <siparis> getSiparisler(){
        return siparisler;
    }
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
    int siparisSure(){
        int sure = 0;
        sure = (siparis_ulasim.getSaat() - siparis_baslangic.getSaat()) * 60;
        sure += (siparis_ulasim.getDakika() - siparis_baslangic.getDakika());
        return sure;
    }
    void siparisEkle(siparis s){
        siparisler.push_back(s);
    }
    void siparisSil(int s){
        siparisler.erase(siparisler.begin() + s);
    }
    void siparisGuncelle(int s, siparis g){
        siparisler[s] = g;
    }
    void siparisListele(){
        for(int i = 0; i < siparisler.size(); i++){
            cout << "Siparis No: " << siparisler[i].getSiparisNo() << endl;
            cout << "Siparis Fiyat: " << siparisler[i].getSiparisFiyat() << endl;
            cout << "Siparis Baslangic: " << siparisler[i].getSiparisBaslangic() << endl;
            cout << "Siparis Ulasim: " << siparisler[i].getSiparisUlasim() << endl;
        }
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
