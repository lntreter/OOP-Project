#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

class zaman{ //Zaman Sınıfı
    private:
    int saat;
    int dakika;
    public:
    //Kurucu Fonksiyon
    zaman(int s=0,int d=0){
        setSaat(s);
        setDakika(d);
    }
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
    friend ostream& operator<<(ostream& os, const zaman& z){
        os << z.saat << "." << z.dakika;
        return os;
    }
};

class kiyafet{ //Kıyafe sınıfı
    protected:
    char *kategori;
    string kiyafet_adi;
    double fiyat;
    char* boyut;
    char* renk;
    public:
    //Kurucu Fonksiyon
    kiyafet(){};
    kiyafet(char *k, string ka, double f, char* b, char* r){
        setKategori(k);
        setKiyafetAdi(ka);
        setFiyat(f);
        setBoyut(b);
        setRenk(r);
    }

    //Kapsülleme fonksiyonları

    void setKategori(char *k){
        kategori = k;
    }
    void setKiyafetAdi(string k){
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
    string getKiyafetAdi(){
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
        cout << "---------------------------" << endl;
    }
};


class kisi{//Kişi sınıfı
    private:
    string ad_soyad;
    string telNo;
    static int kisiSayisi;
    static int listeBoyutu;
    public:
    kisi(){ 
        kisiSayisi++;
    };
    static void setListeBoyutu(int l){
        listeBoyutu = l;
    }
    static int getListeBoyutu(){
        return listeBoyutu;
    }
    void setKisiSayisi(int k){
        kisiSayisi = k;
    }
    int getKisiSayisi(){
        return kisiSayisi;
    }
    void setAdSoyad(string a){
        ad_soyad = a;
    }
    void setTelNo(string t){
        telNo = t;
    }
    string getAdSoyad(){
        return ad_soyad;
    }
    string getTelNo(){
        return telNo;
    }
    void yazdir(){
        cout << "Ad Soyad: " << ad_soyad << endl;
        cout << "Tel No: " << telNo << endl;
    }
    static void ekle(kisi *k,kisi *liste[]){
        if(listeBoyutu < kisiSayisi){
            liste[listeBoyutu] = k;
            listeBoyutu++;
        }
        else{
            cout << "Liste dolu" << endl;
        }
    }
    static void sil(kisi k,kisi *liste[]){
        for(int i=0;i<listeBoyutu;i++){
            if(liste[i]->getAdSoyad() == k.getAdSoyad()){
                for(int j=i;j<listeBoyutu;j++){
                    liste[j] = liste[j+1];
                }
                listeBoyutu--;
            }
        }
    }
    static void yazdirListe(kisi *liste[]){
        for(int i=0;i<listeBoyutu;i++){
            liste[i]->yazdir();
            cout << "---------------------" << endl;
        }
        cout << endl;
    }
};

int kisi::listeBoyutu = 0;
int kisi::kisiSayisi = 0;

class siparis : kiyafet
{
private:
    int siparis_No;
    double siparis_fiyat;
    zaman siparis_baslangic;
    zaman siparis_ulasim;
    static int siparisSayisi;
    static int listeBoyutu;
public:
    siparis(){siparisSayisi++;};
    static void setListeBoyutu(int l){
        listeBoyutu = l;
    }
    static int getListeBoyutu(){
        return listeBoyutu;
    }
    void setSiparisNo(int s)
    {
        siparis_No = s;
    }
    void setSiparisFiyat(double f)
    {
        siparis_fiyat = f;
    }
    void setSiparisBaslangic(zaman s)
    {
        siparis_baslangic = s;
    }
    void setSiparisUlasim(zaman u)
    {
        siparis_ulasim = u;
    }
    void setSiparisSayisi(int s)
    {
        siparisSayisi = s;
    }
    int getSiparisSayisi()
    {
        return siparisSayisi;
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
        cout << "Siparis Baslangic: " << getSiparisBaslangic() << endl;cout << "----" << endl;
        cout << "Siparis Ulasim: " << getSiparisUlasim() << endl;
    }
    int siparisSure(){
        int sure = 0;
        sure = (siparis_ulasim.getSaat() - siparis_baslangic.getSaat()) * 60;
        sure += (siparis_ulasim.getDakika() - siparis_baslangic.getDakika());
        return sure;
    }
    static void siparisEkle(siparis s,siparis *liste[]){
        if(listeBoyutu < siparisSayisi){
            liste[listeBoyutu] = &s;
            listeBoyutu++;
        }
        else{
            cout << "Liste dolu" << endl;
        }
    }
    static void siparisSil(siparis s, siparis *liste[]){
        for(int i=0;i<listeBoyutu;i++){
            if(liste[i]->getSiparisNo() == s.getSiparisNo()){
                for(int j=i;j<listeBoyutu;j++){
                    liste[j] = liste[j+1];
                }
                listeBoyutu--;
            }
        }
    }
    static void siparisGuncelle(siparis s, siparis *liste[]){
        for(int i=0;i<listeBoyutu;i++){
            if(liste[i]->getSiparisNo() == s.getSiparisNo()){
                liste[i] = &s;
            }
        }
    }
    static void siparisListele(siparis *liste[]){
        for(int i=0;i<listeBoyutu;i++){
            liste[i]->yazdir();
            cout << "---------------------" << endl;
        }
        cout << endl;
    }
    
};
int siparis::listeBoyutu = 0;
int siparis::siparisSayisi = 0;

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
    yonetici(){
        sifre = "1234";
    }
    ~yonetici(){
        delete sifre;
    }
    void setSifre(char *s){
        sifre = s;
    }
    char* getSifre(){
        return sifre;
    }
    void yazdir(){
        cout << "Sifre: " << sifre << endl;
    }
    void yoneticiEkle(kisi k){
        yonetici y;
        k = y;
    }
    void yoneticiSil(kisi k){
        yonetici y;
        y.setSifre(NULL);
        k = y;
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
    const int listSize = 100;

    kisi k,k2,*liste[listSize];
    k.setAdSoyad("Ali Yılmaz");
    k.setTelNo("0532 123 45 67");
    k2.setAdSoyad("Ahmet Yılmaz");
    k2.setTelNo("0532 123 45 66");
    kisi::ekle(&k,liste);
    kisi::yazdirListe(liste);
    kisi::ekle(&k2,liste);
    kisi::yazdirListe(liste);
    siparis s,s2,*liste2[listSize];
    zaman z(12,30),z2(13,30),z3(14,30),z4(15,30);
    s.setSiparisNo(1);
    s.setSiparisFiyat(100);
    s.setSiparisBaslangic(z);
    s.setSiparisUlasim(z2);
    s2.setSiparisNo(2);
    s2.setSiparisFiyat(200);
    s2.setSiparisBaslangic(z3);
    s2.setSiparisUlasim(z4);
    siparis::siparisEkle(s,liste2);
    siparis::siparisEkle(s2,liste2);
    siparis::siparisListele(liste2);

    return 0;
}
