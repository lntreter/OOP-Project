#include <iostream>
#include <string.h>

using namespace std;

int admin = -1;

void mainMenu();

void yoneticiGiris(){
    string kullaniciAdi;
    string sifre;
    cout << "Kullanici Adi: ";
    cin >> kullaniciAdi;
    cout << "Sifre: ";
    cin >> sifre;
    if( kullaniciAdi == "admin" && sifre == "1234"){
        cout << "Giris Basarili" << endl;
        admin = 1;
        mainMenu();
    }else{
        cout << "Giris Basarisiz" << endl;
        yoneticiGiris();
    }
};

void musteriGiris(){
    string kullaniciAdi;
    string sifre;
    cout << "Kullanici Adi: ";
    cin >> kullaniciAdi;
    cout << "Sifre: ";
    cin >> sifre;
    if( kullaniciAdi == "user" && sifre == "1234"){
        cout << "Giris Basarili" << endl;
        admin = 0;
        mainMenu();
    }else{
        cout << "Giris Basarisiz" << endl;
        musteriGiris();
    }
};


void sistemeGiris() {
    int c;
    cout << "1. Yönetici girişi" << endl;
    cout << "2. Müşteri girişi" << endl;
    cout << "3. Ana menüye dön" << endl;
    cin >> c;
    switch (c) {
        case 1:
            cout << "Yönetici girişi" << endl;
            yoneticiGiris();
            break;
        case 2:
            cout << "Müşteri girişi" << endl;
            musteriGiris();
            break;
        case 3:
            cout << "Ana menüye dön" << endl;
            mainMenu();
            break;
        default:
            cout << "Hatalı giriş!" << endl << "Tekrar deneyiniz." << endl;
            sistemeGiris();
            break;
    }
}

void uyeKaydi() {
    string ad;
    string soyad;
    string kullaniciAdi;
    string sifre;
    cout << "Ad: ";
    cin >> ad;
    cout << "Soyad: ";
    cin >> soyad;
    cout << "Kullanici Adi: ";
    cin >> kullaniciAdi;
    cout << "Sifre: ";
    cin >> sifre;
    cout << "Kayit Basarili" << endl;
    mainMenu();
}

void exit() {
    return;
}

void mainMenu()
{
    int c;

    if (admin == -1){
        cout << "1. Sisteme Giriş" << endl;
        cout << "2. Üye Kaydı" << endl;
        cout << "3. Çıkış" << endl;
        cin >> c;

        switch (c)
        {
            case 1:
                cout << "Sisteme Giriş" << endl;
                sistemeGiris();
                break;
            case 2:
                cout << "Üye Kaydı" << endl;
                uyeKaydi();
                break;
            case 3:
                cout << "Çıkış Yapılıyor..." << endl;
                exit();
                break;
            default:
                cout << "Hatalı Giriş" << endl;
                mainMenu();
                break;
        }
    }

    else if (admin == 1)
    {
        cout << "1. Siparişleri Görüntüle / Düzenle" << endl;
        cout << "2. Ürünleri Görüntüle / Düzenle" << endl;
        cout << "3. Kuryeleri Düzenle" << endl;
        cout << "4. Şikayet - Öneri (Geri Bildirimler)" << endl;
        cout << "5. İndirim kodu tanımla " << endl;
        cout << "6. Oturumu Kapat" << endl;
        cout << "7. Çıkış" << endl;
        cin >> c;

        switch (c)
        {
            case 1:
                cout << "Siparişleri Görüntüle / Düzenle" << endl;
                break;
            case 2:
                cout << "Ürünleri Görüntüle / Düzenle" << endl;
                break;
            case 3:
                cout << "Kuryeleri Düzenle" << endl;
                break;
            case 4:
                cout << "Şikayet - Öneri (Geri Bildirimler)" << endl;
                break;
            case 5:
                cout << "İndirim kodu tanımla " << endl;
                break;
            case 6:
                cout << "Oturumu Kapatılıyor..." << endl;
                admin = -1;
                mainMenu();
                break;
            case 7:
                cout << "Çıkış Yapılıyor..." << endl;
                exit();
                break;
            default:
                cout << "Hatalı Giriş" << endl;
                mainMenu();
                break;
        }

    }

    else{
        cout << "1. Sipariş Ver" << endl;
        cout << "2. Siparişleri Görüntüle" << endl;
        cout << "3. Şikayet - Öneri (Geri Bildirimler) " << endl;
        cout << "4. Oturumu Kapat" << endl;
        cout << "5. Çıkış" << endl;
        cin >> c;

        switch (c)
        {
            case 1:
                cout << "Sipariş Ver" << endl;
                break;
            case 2:
                cout << "Siparişleri Görüntüle" << endl;
                break;
            case 3:
                cout << "Şikayet - Öneri (Geri Bildirimler) " << endl;
                break;
            case 4:
                cout << "Oturumu Kapatılıyor..." << endl;
                admin = -1;
                mainMenu();
                break;
            case 5:
                cout << "Çıkış Yapılıyor..." << endl;
                exit();
                break;
            default:
                cout << "Hatalı Giriş" << endl;
                mainMenu();
                break;
        }
    }

}

int main()
{
    mainMenu();
    return 0;
}
