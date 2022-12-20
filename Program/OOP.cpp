#include<iostream>
#include<string>
#include<fstream>
#include<limits>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
#include <thread>
#include <mutex>

using namespace std;

mutex mu; // mutex for critical section

string feedBack; //feedback stringi

int fark; // zamanlar arasındaki fark

int orderNo = 0;//Siparis numarasi

string nameList[] = { "Celalettin Mantar","Burhan sahin","Berhan Saydam","Talha Yay","Sefa Subasi",
	"Cemil NovruzOğlu","Mustafa Novruzğlu","Mehmet sahin","Talha Subasi" }; // isimler

string telList[] = { "0532 123 45 67","0532 123 45 68","0532 123 45 69","0532 123 45 70","0532 123 45 71",
    "0532 123 45 72","0532 123 45 73","0532 123 45 74","0532 123 45 75" }; //telefon numaraları

class Time { //Zaman Sinifi
private:
    int hour;
    int minute;
public:
    Time() {
        hour = rand() % 23 + 0;
        minute = rand() % 59 + 0;
    }
    Time(int h, int m) {//Kurucu fonksiyon

        if (m >= 60)
        {
            h += m / 60;
            m = (int(m) % 60);
        }
        if (h >= 24)
        {
            h = 0;
        }

        hour = h;
        minute = m;
    }
    void setHour(int s) { //Saat değerini ayarlar
        hour = s;
    }
    void setMinute(int d) { //Dakika değerini ayarlar
        minute = d;
    }
    int getHour() { //Saat değerini döndürür
        return hour;
    }
    int getMinute() { //Dakika değerini döndürür
        return minute;
    }
    void print() { //Saat ve dakika değerlerini ekrana yazdirir
        cout << hour << ":" << minute << endl;
    }
    static void setTimer(Time);

    void delay(int d) { //Saat ve dakika değerlerini gecikme değeri kadar arttirir
        minute += d;
        if (minute >= 60) {
            hour += minute / 60;
            minute = minute % 60;
        }
    }

    bool operator>(const Time& t) {//Saat ve dakika değerlerini karsilastirir
        if (hour == t.hour) {
            if (minute > t.minute) {
                return true;
            }
        }
        else if (hour > t.hour) {
            return true;
        }
        else { return false; }
        return false;
    }

    bool operator>(const Time* t) {//Saat ve dakika değerlerini karsilastirir
        if (hour == t->hour) {
            if (minute > t->minute) {
                return true;
            }
        }
        else if (hour > t->hour) {
            return true;
        }
        else { return false; }
        return false;
    }

    bool operator==(const Time& t) {//Saat ve dakika değerlerini karsilastirir
        if (hour == t.hour) {
            if (minute == t.minute) {
                return true;
            }
        }
        return false;
    }

    friend ostream& operator<<(ostream& os, const Time& t) {//Saat ve dakika değerlerini ekrana yazdirir
        if (t.minute < 10 && t.hour < 10)
        {
            os << "0" << t.hour << ":0" << t.minute;
        }
        else if (t.minute < 10) {
            os << t.hour << ":0" << t.minute;
        }
        else if (t.hour < 10) {
            os << "0" << t.hour << ":" << t.minute;
        }
        else {
            os << t.hour << ":" << t.minute;
        }
        return os;
    }
};

class Clothes { //ürünler sınıfı
protected:
    string category;
    string name;
    double price;
    string size;
    string color;
    static int clotheCount;
    static int listSize;
public:
    Clothes() {}
    Clothes(string c, string n, double p, string s, string col) {//Kurucu fonksiyon
        category = c;
        name = n;
        price = p;
        size = s;
        color = col;
        clotheCount++;
    }
    void setCategory(string c) {
        category = c;
    }
    void setName(string n) {
        name = n;
    }
    void setPrice(double p) {
        price = p;
    }
    void setSize(string s) {
        size = s;
    }
    void setColor(string col) {
        color = col;
    }
    string getCategory() {
        return category;
    }
    string getName() {
        return name;
    }
    double getPrice() {
        return price;
    }
    string getSize() {
        return size;
    }
    string getColor() {
        return color;
    }
    static int getClotheCount() {
        return clotheCount;
    }
    static void addClothe(Clothes*, Clothes[]);
    static void delClothe(Clothes, Clothes[]);
    static void listClothes(Clothes[]);
    static void orderClotes(Clothes*);
    void Edit();
    void print() {
        cout << "Category: " << category << endl;
        cout << "Name: " << name << endl;
        cout << "Price: " << price << "TL" << endl;
        cout << "Size: " << size << endl;
        cout << "Color: " << color << endl;
        cout << "-----------------------" << endl;
    }
};

int Clothes::clotheCount = 0;
int Clothes::listSize = 500;
Clothes clothesList[500];//Kiyafetlerin tutulduğu liste


void Clothes::orderClotes(Clothes* list) {//Siparis verme fonksiyonu
    for (int i = 1; i <= clotheCount; i++)
    {
        list[i].print();//Kiyafetleri listeler
        cout << "Satin almak icin " << i << " tusuna basiniz." << endl << endl;
    }

}

void Clothes::listClothes(Clothes list[]) {//Kiyafetleri listeler
    for (int i = 1; i <= clotheCount; i++) {
        list[i].print();
    }
}

void Clothes::addClothe(Clothes* c, Clothes list[]) {//Kiyafet ekler
    if (clotheCount < listSize) {//Stok dolu değilse
        list[clotheCount] = *c;//Kiyafetleri listeye ekler
    }
    else {
        cout << "Stok Dolu!" << endl;//Stok doluysa
    }
}
void Clothes::delClothe(Clothes c, Clothes list[]) {//Kiyafet siler
    Clothes* tmp = new Clothes[clotheCount];//Geçici bir liste olusturur

    for (int i = 1; i <= clotheCount; i++) {//Kiyafetleri gezer

        if (list[i].getName() == c.getName()) {//Eğer silinecek kiyafet bulunursa

            list[clotheCount + 1] = list[i];//Son kiyafet silinecek kiyafetin yerine konur

            for (int k = i; k < clotheCount; k++)//Silinen kiyafetin yerine gelen kiyafetlerin yerini değistirir
            {
                list[k] = list[k + 1];//Kiyafetlerin yerini değistirir
            }
            clotheCount--;
        }
        if (!(i > clotheCount))//Eğer silinen kiyafet yoksa

            tmp[i] = list[i];//Geçici listeye kiyafetleri ekler
    }
    list = tmp;//Geçici listeyi ana listeye atar
}

void fillup() {
    Clothes c1("Giysi", "Pantolon", 200, "M", "Kirmizi"), c2("Giysi", "Tişort", 80, "S", "Mavi"), c3("Giysi", "Gomlek", 150, "M", "Yesil"),
        c4("Aksesuar", "Kolye", 900, "Dusuk", "Gumus"), c5("Aksesuar", "Bileklik", 1700, "Orta", "Altin"), c6("Aksesuar", "Yuzuk", 3500, "Yuksek", "Altin"),
        c7("Ayakkabi", "Nike", 300, "40 EU", "Beyaz"), c8("Ayakkabi", "Adidas", 300, "42 EU", "Siyah"), c9("Ayakkabi", "Puma", 300, "38 EU", "Beyaz"),
        c10("Giysi", "Şort", 60, "L", "Gri"), c11("Aksesuar", "Gerdanlik", 2500, "Dusuk", "Gumus"), c12("Ayakkabi", "Reebok", 300, "41 EU", "Siyah");
	clothesList[1] = c1;
	clothesList[2] = c2;
	clothesList[3] = c3;
	clothesList[4] = c4;
	clothesList[5] = c5;
	clothesList[6] = c6;
	clothesList[7] = c7;
	clothesList[8] = c8;
	clothesList[9] = c9;
	clothesList[10] = c10;
	clothesList[11] = c11;
	clothesList[12] = c12;
}

class Person { //kişi sınıfı
protected:
    string name;
    string telNo;
    static int personCount;
    static int listSize;
public:
    Person() {}
    Person(string n, string t) {
        name = n;
        telNo = t;
        personCount++;
    }
    ~Person() {
        personCount--;
    }
    void setName(string n) {
        name = n;
    }
    void setTelNo(string t) {
        telNo = t;
    }
    void setPersonCount(int p) {
        personCount = p;
    }
    void setListSize(int l) {
        listSize = l;
    }
    string getName() {
        return name;
    }
    string getTelNo() {
        return telNo;
    }
    static int getPersonCount() {
        return personCount;
    }
    static int getListSize() {
        return listSize;
    }
    void print() {
        cout << "Name: " << name << endl;
        cout << "Tel No: " << telNo << endl;
    }
    static void addPerson(Person* p, Person* list) {//Person ekleme fonksiyonu
        if (personCount < listSize) {//Liste dolu değilse
            list[personCount] = *p;//Personu listeye ekler
        }
        else {
            cout << "List is full!" << endl;
        }
    }
    static void del(Person p, Person* list) {//düzenlenicek
        for (int i = 0; i < personCount; i++) {
            if (list[i].getName() == p.getName()) {
                for (int j = i; j < personCount; j++) {
                    list[j] = list[j + 1];
                }
                personCount--;
                break;
            }
        }
    }
    static void printList(Person* list) {//Personlari listeler
        for (int i = 0; i < personCount; i++) {
            list[i].print();
        }
        cout << endl;
    }
};

int Person::personCount = 0;
int Person::listSize = 1000;

class Courier : Person { // kurye sınıfı
private:
    Time* orderCompleteTime;
    int orderNo;
    static int courierCount;
    static int listSize;
public:
    int gozleme = courierCount;
    Courier() { courierCount++; }
    Courier(string n, string t, Time* o, int no) : Person(n, t) {
        orderCompleteTime = o;
        orderNo = no;
        courierCount++;
    }
    static void setCourierCount(int cor) {
        courierCount = cor;
    }
    static int getCourierCount() {
        return courierCount;
    }
    void setOrderCompleteTime(Time* o) {
        orderCompleteTime = o;
    }
    string getName() {
        return name;
    }
    string getTelNo() {
        return telNo;
    }
    void setOrderNo(int no) {
        orderNo = no;
    }
    Time* getOrderCompleteTime() {
        return orderCompleteTime;
    }
    int getOrderNo() {
        return orderNo;
    }
    static void addCourier(Courier*, Courier list[]);
    void print() {
        cout << "Name: " << name << endl;
        cout << "Tel No: " << telNo << endl;
        cout << "Order Complete Time: " << *orderCompleteTime << endl;
        cout << "Order No: " << orderNo << endl;
    }
};

int Courier::listSize = 1000;
int Courier::courierCount = 0;
Courier courierList[1000];

Time SAAT(4, 0); //sistem saaati başlangıç değeri

double a = SAAT.getHour(), b = SAAT.getMinute(); //saat sayısal değerler

class order : Clothes { //sipariş sınıfı
private:
    int orderNo;
    double orderPrice;
    Time orderTime;
    Time deliveryTime;
    static int listSize;
public:
    Courier courier;
    order() {};
    order(int o, double p, Time t, Time d, string c, string n, double pr, string s, string col);
    void setOrderNo(int o) {
        orderNo = o;
    }
    void setOrderPrice(double p) {
        orderPrice = p;
    }
    void setOrderTime(Time t) {
        orderTime = t;
    }
    void setDeliveryTime(Time d) {
        deliveryTime = d;
    }
    void setOrderCount(int o);
    void setListSize(int l) {
        listSize = l;
    }
    int getOrderNo() {
        return orderNo;
    }
    double getOrderPrice() {
        return orderPrice;
    }
    Time getOrderTime() {
        return orderTime;
    }
    Time getDeliveryTime() {
        return deliveryTime;
    }
    static int getOrderCount();
    int getListSize() {
        return listSize;
    }
    void print();
    int orderDeliveryTime() {
        return deliveryTime.getHour() - orderTime.getHour();
    }
    static void addOrder(order* o, order list[], Courier*);
    static void delOrder(order o, order* list);
    static void printList(order* list);
};

int order::listSize = 100;

class User : Person { //kullanıcı sınıfı
private:
    string nickname;
    string mail;
    string adress;
    string pass;
    string saleCoupon;
    string bDate;
    static int userCount;
public:
    order orderList[100];//Siparis listesi
    int orderCount;
    User() { ; }
    User(string n, string t, string ni, string m, string a, string p, string b) : Person(n, t), saleCoupon("0") {
        nickname = ni;
        mail = m;
        adress = a;
        pass = p;
        bDate = b;
        userCount++;
    }
    static int getUserCount() {
        return userCount;
    }
    void setNickname(string n) {
        nickname = n;
    }
    void setMail(string m) {
        mail = m;
    }
    void setAdress(string a) {
        adress = a;
    }
    void setPass(string p) {
        pass = p;
    }
    void setSaleCoupon(string s) {
        saleCoupon = s;
    }
    void setBDate(string b) {
        bDate = b;
    }
    string getNickame() {
        return nickname;
    }
    string getMail() {
        return mail;
    }
    string getAdress() {
        return adress;
    }
    string getPass() {
        return pass;
    }
    string getSaleCoupon() {
        return saleCoupon;
    }
    string getBDate() {
        return bDate;
    }
    void print() {
        cout << "Name: " << name << endl;
        cout << "Nickname: " << nickname << endl;
        cout << "Tel No: " << telNo << endl;
        cout << "Mail: " << mail << endl;
        cout << "Adress: " << adress << endl;
        cout << "Pass: " << pass << endl;
        cout << "Sale Coupon: " << saleCoupon << endl;
        cout << "Birth Date: " << bDate << endl;
        cout << "--------------------------" << endl;
    }
    static void signUp(); 
};

int User::userCount = 0;
User u("", "", "", "", "", "", ""); //anlık kullanıcı

order::order(int o, double p, Time t, Time d, string c, string n, double pr, string s, string col) : Clothes(c, n, pr, s, col) {
    orderNo = o;
    orderPrice = p;
    orderTime = t;
    deliveryTime = d;
    u.orderCount++;
}

void order::setOrderCount(int o) {
    u.orderCount = o;
}

int order::getOrderCount() {
    return u.orderCount;
}

void order::delOrder(order o, order* list) {//Siparis silme fonksiyonu
    for (int i = 1; i <= u.orderCount; i++) {//Siparis sayisi kadar döner
        if (list[i].getOrderNo() == o.getOrderNo()) {//Siparis numarasi esitse
            for (int j = i; j <= u.orderCount; j++) {//Siparis sayisi kadar döner
                list[j] = list[j + 1];//Siparisi siler
            }
            u.orderCount--;//Siparis sayisini azaltir
            break;
        }
    }
}

void order::printList(order* list) {
    for (int i = 1; i <= u.orderCount; i++) {
        list[i].print();
    }
    cout << endl;
}

void order::print() { //Siparişi yazırır
    mu.lock();
    Time comp(a, b);
    mu.unlock();
    fark = (deliveryTime.getHour() - orderTime.getHour()) * 60 + (deliveryTime.getMinute() - orderTime.getMinute());
    if (deliveryTime.getHour() == 0) {
        fark = (24 - orderTime.getHour()) * 60 + (deliveryTime.getMinute() - orderTime.getMinute());
        if (orderTime.getHour() == 0)
        {
            (deliveryTime.getMinute() - orderTime.getMinute());
        }
    }

    if (comp > deliveryTime)
    {
        cout << "Order No: " << orderNo << endl;
        cout << "Order Price: " << orderPrice - stoi(u.getSaleCoupon()) << "TL" << endl;
        cout << "Order Time: " << orderTime << endl;
        cout << "Delivery Time: " << deliveryTime << " Siparis " << fark << " dakikada teslim edildi! " << endl;
        cout << "Kurye Bilgileri : " << courier.getName() << " Tel: " << courier.getTelNo() << endl;
        cout << "Adres: " << u.getAdress() << endl << endl;
        cout << "---Ürün Bilgileri---" << endl << endl;
        Clothes::print();
    }
    else {
        cout << "Order No: " << orderNo << endl;
        cout << "Order Price: " << orderPrice - stoi(u.getSaleCoupon()) << "TL" << endl;
        cout << "Order Time: " << orderTime << endl;
        cout << "Order - Delivery Time: " << fark << endl;
        cout << "Delivery Time: " << deliveryTime << endl;
        cout << "Kurye Bilgileri : " << courier.getName() << " Tel: " << courier.getTelNo() << endl;
        cout << "Adres: " << u.getAdress() << endl << endl;
        cout << "---Ürün Bilgileri---" << endl << endl;
        Clothes::print();
    }
}

class Admin : Person {// admin sınıfı
private:
    string pass;
public:
    Admin() {} //default constructor
    Admin(string n, string t, string p) : Person(n, t) {
        pass = p;
    }
    string getName() {
		return name;
    }
    void setPass(string p) {
        pass = p;
    }
    string getPass() {
        return pass;
    }
    void print() {
        cout << "Name: " << name << endl;
        cout << "Tel No: " << telNo << endl;
        cout << "Pass: " << pass << endl;
    }
};

Admin nowAdmin("", "", ""); //anlık admin

int admin = -1;//Admin girisi kontrolü
bool menu = true;//Menü kontrolü

void mainMenu();
void SystemLogin();
void userLogin();
void orders();
User userList[100];//Kullanici listesi

void order::addOrder(order* o, order list[], Courier* c) {//Siparis ekleme fonksiyonu

    if (u.orderCount < listSize) {//Liste dolu değilse
        o->courier = *c;
        for (int i = 0; i < Courier::getCourierCount(); i++)
        {
            if (list[i].getName() != o->getName()) {
                Courier::setCourierCount(Courier::getCourierCount() - 1);
                break;
            }
        }
        list[u.orderCount] = *o;//Siparisi listeye ekler
        clotheCount--;//Kiyafet sayisini azaltir
        delClothe(*o, clothesList);//Kiyafeti siler
    }
    else {
        cout << "Sepet Dolu!" << endl;
    }
    Courier::addCourier(c, courierList);
}

void Courier::addCourier(Courier* o, Courier list[]) { //kurye ekleme fonksiyonu
    if (courierCount < listSize) {
        list[courierCount] = *o;
    }
    else {
        cout << "Kadro Dolu!" << endl;
    }
}

int j = 1;


void feedback() {// feedback yazma fonskiyonu
    string feedbackyaz;
    fstream fb("suggestions.txt", ios::app); //oluşturulan dosya
    if (admin == 1) //kullanıcı admin ise
    {
        if (feedBack == "") {//string boş mu diye kontrol eder
            cout << "Herhangi bir geri bildirim yapilmamis. " << endl << endl;
        }
        else
        {
            int control = -1;
            cout << feedBack << endl << endl << endl; //stringi yazdırır
            cout << "Geri bildirimlere cevap vermek için '1', çikmak için '0' tusuna basin. "; cin >> control; cout << endl;//kullanıcıya sorar
            if (control == 1)
            {
                cout << "Lütfen Mesajinizi yazin: "; getline(cin >> ws, feedbackyaz); //yazılacak feedback
                feedBack += "\n\n" + nowAdmin.getName() + ": " + feedbackyaz; //yazılan feedbacki asıl stringe ekler
                cout << "Mesajiniz basariyla gönderildi! " << endl << endl; 
                if (fb.is_open()) { //Dosya açildiysa
                    fb << "\n\nYetkili Kullanici: " + feedbackyaz << endl;   //Kullanici adi ve sifreyi dosyaya yaz
                    fb.close(); //Dosyayi kapat
                }
                else {
                    cout << "Dosya açilamadi!" << endl;
                }
            }
            else if (control == 0)
            {
                ;//geç
            }
            else
            {
                cout << "Hatali bir tuslama yaptiniz! " << endl;
            }
        }
    }
    else if (admin == 0) //kulanıcı admin değilse
    {
        cout << feedBack << endl << endl << endl;
        if (feedBack == "") {
            cout << "Henüz kimse geri bildirim yapmamis. " << endl << endl;
        }
        int control = -1;
        cout << "Bir geri bildirim mesaji yazmak için '1', geri dönmek için '0' tusuna basin. "; cin >> control; cout << endl;
        if (control == 1)
        {
            cout << "Lütfen Mesajinizi yazin: "; getline(cin >> ws, feedbackyaz);
            feedBack += "\n\n" + u.getNickame() + ": " + feedbackyaz;
            cout << "Mesajiniz basariyla gönderildi! " << endl << endl;
            if (fb.is_open()) { //Dosya açildiysa
                fb << "\n\n" + u.getNickame() + ": " + feedbackyaz << endl;   //Kullanici adi ve sifreyi dosyaya yaz
                fb.close(); //Dosyayi kapat
            }
            else {
                cout << "Dosya açilamadi!" << endl;
            }
        }
        else if (control == 0)
        {
            ;//geç
        }
        else
        {
            cout << "Hatali bir tuslama yaptiniz! " << endl;
        }
    }
    
}

void giveOrder() {//Siparis verme

    srand(time(NULL));//Rastgele sayi üretimi için
    mu.lock();//Kilit

    Time orderTime = Time(a, b);//Siparis zamani
    Time deliveryTime(a + (rand() % 2 + 0), b + (rand() % 45 + 0));//Teslimat zamani

    mu.unlock();//Kilit aç
    int opt;//Seçenek

    Clothes::orderClotes(clothesList);//Kiyafetleri listeleme
    cout << "Geri dönmek için 0 tusuna basin. " << endl;
    try                  //Hata yakalama
    {
        if (!(cin >> opt)) {   //Hata kontrolü
            throw 606;
        }
    }
    catch (int hata)
    {
        cin.clear();  //Hata durumunda cin'i temizle
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Hata durumunda cin'i temizle
        cerr << "Hatali bir giris yaptiniz lütfen tekrar deneyin ! Hata kodu: " << hata << endl; //Hata mesaji
        cout << endl; //Bosluk
        cout << "Geri dönmek için 0 tusuna basin. " << endl; //Kullaniciya bilgi ver
        cin >> opt;
    }
    for (int i = 1; i <= Clothes::getClotheCount(); i++) //Kiyafet sayisi kadar döngü
    {
        if (opt == i)
        {
            if (Courier::getCourierCount() == 100) {
                Courier::setCourierCount(0);
            }
            if (Courier::getCourierCount() == 0 || courierList[1].getName() != nameList[0])
            {
                if (courierList[1].getName() != nameList[0] && Courier::getCourierCount() == 0)
                {
                    Time* nT = new Time(deliveryTime.getHour(), deliveryTime.getMinute());
                    Courier* n = new Courier(nameList[0], telList[0], nT, orderNo);
                    Courier::addCourier(n, courierList);
                    order::addOrder(new order(++orderNo, clothesList[i].getPrice(), orderTime, deliveryTime, //Siparis ekleme
                        clothesList[i].getCategory(), clothesList[i].getName(),
                        clothesList[i].getPrice(), clothesList[i].getSize(), clothesList[i].getColor()), u.orderList, &courierList[1]);
                    cout << "Siparisiniz basariyla alindi! " << endl << endl;
                }
                else
                {
                    Time* nT = new Time(deliveryTime.getHour(), deliveryTime.getMinute());
                    courierList[1].setOrderCompleteTime(nT); courierList[i].setOrderNo(orderNo);
                    Courier::addCourier(&courierList[i], courierList);
                    order::addOrder(new order(++orderNo, clothesList[i].getPrice(), orderTime, deliveryTime, //Siparis ekleme
                        clothesList[i].getCategory(), clothesList[i].getName(),
                        clothesList[i].getPrice(), clothesList[i].getSize(), clothesList[i].getColor()), u.orderList, &courierList[1]);
                    cout << "Siparisiniz basariyla alindi! " << endl << endl;
                }
                break;
            }
            else {
                int z = 1;
                int check = 0;
                do {
                    mu.lock();
                    Time* now = new Time(a, b);
                    mu.unlock();
                    if (courierList[z].getOrderCompleteTime()->getHour() == now->getHour())
                    {
                        if (courierList[z].getOrderCompleteTime()->getMinute() < now->getMinute())
                        {
                            order::addOrder(new order(++orderNo, clothesList[i].getPrice(), orderTime, deliveryTime, //Siparis ekleme
                                clothesList[i].getCategory(), clothesList[i].getName(),
                                clothesList[i].getPrice(), clothesList[i].getSize(), clothesList[i].getColor()), u.orderList, &courierList[z]);
                            cout << "Siparisiniz basariyla alindi! " << endl << endl;
                            check = 999;
                            Time* a = new Time(deliveryTime.getHour(), deliveryTime.getMinute());
                            courierList[z].setOrderCompleteTime(a);
                            break;
                        }
                        else {
                            z;
                        }
                    }
                    if (courierList[z].getOrderCompleteTime()->getHour() < now->getHour())
                    {
                        order::addOrder(new order(++orderNo, clothesList[i].getPrice(), orderTime, deliveryTime, //Siparis ekleme
                            clothesList[i].getCategory(), clothesList[i].getName(),
                            clothesList[i].getPrice(), clothesList[i].getSize(), clothesList[i].getColor()), u.orderList, &courierList[z]);
                        cout << "Siparisiniz basariyla alindi! " << endl << endl;
                        check = 999;
                        Time* a = new Time(deliveryTime.getHour(), deliveryTime.getMinute());
                        courierList[z].setOrderCompleteTime(a);
                        break;
                    }
                    else {
                        z++;
                    }
                } while (z <= Courier::getCourierCount()); //kurye sayısı kadar tekrar eder

                z = 1;

                if (check == 999)//zaten kurye eklendiyse else e geçmez
                {
                    z = 1;
                }
                else {
                    do {
                        mu.lock();
                        Time* now = new Time(a, b);
                        mu.unlock();
                        if (courierList[z].getOrderCompleteTime()->getHour() == now->getHour()) {
                            if (courierList[z].getOrderCompleteTime()->getMinute() > now->getMinute()) {
                                Time* nT1 = new Time(deliveryTime.getHour(), deliveryTime.getMinute());
                                order::addOrder(new order(++orderNo, clothesList[i].getPrice(), orderTime, deliveryTime, //Siparis ekleme
                                    clothesList[i].getCategory(), clothesList[i].getName(),
                                    clothesList[i].getPrice(), clothesList[i].getSize(), clothesList[i].getColor()), u.orderList, new Courier(
                                        nameList[j], telList[j], nT1, orderNo
                                    ));
                                cout << "Siparisiniz basariyla alindi! " << endl << endl;
                                j++;
                                break;
                            }
                            else {
                                z;
                            }
                        }
                        if (courierList[z].getOrderCompleteTime()->getHour() > now->getHour()) {
                            Time* nT1 = new Time(deliveryTime.getHour(), deliveryTime.getMinute());
                            order::addOrder(new order(++orderNo, clothesList[i].getPrice(), orderTime, deliveryTime, //Siparis ekleme
                                clothesList[i].getCategory(), clothesList[i].getName(),
                                clothesList[i].getPrice(), clothesList[i].getSize(), clothesList[i].getColor()), u.orderList, new Courier(
                                    nameList[j], telList[j], nT1, orderNo
                                ));
                            cout << "Siparisiniz basariyla alindi! " << endl << endl;
                            j++;
                            break;
                        }
                        else {
                            z++;
                        }
                    } while (z <= Courier::getCourierCount());
                }
            }
            break;
        }
        else if (opt == 0) {//Geri dönmek için 0 tusuna basin.
            break;
            mainMenu();
        }
    }
}

void products() {
    string category;
    string name;
    double price;
    string size;
    string color;
    string named;
    int i = 1;

    int sec;

    cout << "1. Ürün Ekle " << endl;
    cout << "2. Ürün Sil " << endl;
    cout << "3. Ürün Listele " << endl;
    cout << "4. Geri Dön " << endl;

    try {
        if (!(cin >> sec)) {
            throw 505;
        }
    }
    catch (int hata) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Hatali bir giris yaptiniz lütfen tekrar deneyin ! Hata kodu: " << hata << endl;
        cout << endl;
        cout << "1. Ürün Ekle " << endl;
        cout << "2. Ürün Sil " << endl;
        cout << "3. Ürünleri Listele " << endl;
        cout << "4. Geri Dön " << endl;
        cin >> sec;
    }

    switch (sec)
    {
    case 1:
        cout << "---Ürün Ekleme Ekrani---" << endl;
        cout << "Eklemek istediğiniz ürünün türünü (Giysi - Aksesuar - Ayakkabi) seçiniz: " << endl;
        getline(cin >> ws, category);
        cout << "Ürünün adini giriniz: " << endl;
        getline(cin >> ws, name);
        cout << "Ürünün fiyatini giriniz: " << endl;
        cin >> price;
        cout << "Ürünün bedenini, numarasini veya kalitesini (S, M, L), (40 EU, 36 EU, 42 EU), (Dusuk, Orta, Yuksek) giriniz: " << endl;
        getline(cin >> ws, size);
        cout << "Ürünün rengini giriniz: " << endl;
        getline(cin >> ws, color);
        Clothes::addClothe(new Clothes(category, name, price, size, color), clothesList);
        cout << "Ürün basariyla eklendi!" << endl << endl;
        products();
        break;
    case 2:
        cout << "---Ürün Silme Ekrani---" << endl << endl;
        cout << "Silmek istediğiniz ürünün adini giriniz: " << endl;
        getline(cin >> ws, named);
        do {
            if (named == clothesList[i].getName()) //Kiyafet adi girilen kiyafet adi ile ayni ise
            {
                Clothes::delClothe(clothesList[i], clothesList); //Kiyafet sil
                cout << "Ürün basariyla silindi." << endl;
                i = 1;
                break;
            }
            i++;

        } while (i <= Clothes::getClotheCount());  //Kiyafet sayisi kadar döngü

        if (i > Clothes::getClotheCount() && i != 1) //Kiyafet sayisi kadar döngü döndüyse ve ürün bulunamadiysa
        {
            cout << "Ürün Bulunamadi" << endl; //Ürün bulunamadi mesaji
            i = 1;
        }
        break;
    case 3:
        cout << "---Ürün Listeleme Ekrani---" << endl << endl;
        system("cls");
        Clothes::listClothes(clothesList); //Kiyafetleri listele

        cout << "Devam etmek için bir tusa basin. " << endl; //Kullaniciya bilgi ver

        getchar(); //Kullanicidan bir tusa basmasini bekler
        cout << endl;
        break;
    case 4:
        cout << endl;
        break;
    default:
        cout << "Hatali bir giris yaptiniz lütfen tekrar deneyin !" << endl;
        products();
        break;
    }
}

string hidePass() {

START:
    char passw[32]; //char arrayi oluşturur
    int p = 0;
	char tmpC; //araya geçici olarak karakteri atar
    for (p = 0;;) {
        tmpC = _getch(); //kullanıcıdan karakteri ister
        if ((tmpC >= 'a' && tmpC <= 'z') || (tmpC >= 'A' && tmpC <= 'Z') || (tmpC >= '0' && tmpC <= '9'))
        {
			passw[p] = tmpC; //eğer alınan karakter harf veya rakam ise passw arrayine atar
            p++;
            cout << "*"; //ekrana yıldız yazdırır
        }
        if (tmpC == '\b' && p >= 1)
        {
            cout << "\b \b"; //silerse siler
            --p;
        }
        if (tmpC == '\r')
        {
            passw[p] = '\0'; //entera basınca işlemi sonlandırır
            break;
        }
    }
    if (p <= 5)
    {
        cout << "Sifreniz en az 6 basamakli olmalidir! " << endl;
        goto START;
    }
    return passw;
}

void User::signUp() {
    fstream dosya("users.txt", ios::app);

    string name, nickname, telNo, mail, adress, pass, bDate;


    //Kullanicidan bilgileri al

    cout << "Kayit olmak için bilgilerinizi giriniz." << endl;
    cout << endl;
    cout << "Adiniz: "; getline(cin >> ws, name);
    cout << "Kullanici adiniz: "; getline(cin >> ws, nickname);
    cout << "sifreniz: "; pass = hidePass(); cout << endl;
    cout << "Telefon Numaraniz: "; getline(cin >> ws, telNo);
    cout << "Mail Adredsiniz: "; getline(cin >> ws, mail);
    cout << "Adresiniz: "; getline(cin >> ws, adress);
    cout << "Doğum Tarihiniz (Gün.Ay.Yil): "; getline(cin >> ws, bDate);
    cout << endl;

    //Kullaniciyi olustur

    try {
        User* a = new User(name, telNo, nickname, mail, adress, pass, bDate);
        a->orderCount = 0;
        userList[userCount] = *a;
        cout << "Kayit Basarili! ---> Lütfen Giris Yapiniz! " << endl;
        cout << endl;

    }  //Hata yakalarsa

    catch (exception& e) {
        cout << "Kayit basarisiz! " << endl;
    }

    if (dosya.is_open()) { //Dosya açildiysa
        dosya << nickname + pass << endl;   //Kullanici adi ve sifreyi dosyaya yaz
        dosya.close(); //Dosyayi kapat
    }
    else {
        cout << "Dosya açilamadi!" << endl;
    }
}

Admin admin1("Burhan Sahin", "05452482420", "burhan2002"), admin2("Berhan Saydam", "05418763490", "progp2000");

void adminLogin() {
    //cout << "Lütfen Admin sifresini Giriniz: " << endl;
    //cout << endl;

    ////Admin sifresini al

    //string pass;

    //cout << "Admin sifre: "; getline(cin >> ws, pass);
    //cout << endl;

    //if (pass == "admin")
    //{
    //    cout << "sifre Doğru! Admin Olarak Giris Yapiliyor..." << endl;
    //    cout << endl;
    //    admin = 1;
    //}
    //else {
    //    cout << "sifre Yanlis! " << endl;
    //    cout << endl;
    //}

    //Kullanici adi ve sifreyi al

    cout << "Lütfen Giris Yapiniz! " << endl;
    cout << endl;
    string pass, passCheck, line;
    cout << "Sifrenizi Giriniz: "; pass = hidePass();
    cout << endl;

    passCheck = pass;

    fstream dosya("users.txt", ios::in); //Kullanici bilgilerini oku

    bool tf = false; //Kullanici bilgileri doğruysa true

    if (dosya.is_open()) { //Dosya açildiysa

        while (!dosya.eof()) { //Dosya sonuna gelene kadar

            getline(dosya, line); //Dosyadan satir satir oku

            int offset; //Satirda aranan kelimenin bulunduğu konumu tutar

            //Satirda aranan kelime varsa
            if ((offset = line.find(passCheck, 0)) != string::npos) {
                cout << "Bilgiler Doğru! Giris Yapiliyor... " << endl;
                cout << endl;
                admin = 1;
                if (pass == admin1.getPass())
                {
					nowAdmin = admin1;
                }
				else if (pass == admin2.getPass())
				{
					nowAdmin = admin2;
				}
                tf = true;
            }
        }
    }
    //Kullanici bilgileri yanlissa
    if (!tf) {
        cout << "Bilgileriniz Yanlis! " << endl;
        cout << endl;
    }
}

void passReset() {
    //Kullanici adi ve sifreyi al

RETRY:
    string pass, passAgain, passCheck, line;
	cout << "Yeni şifrenizi girininiz: "; pass = hidePass(); cout << endl;
    cout << endl;
    cout << "Tekrar yeni şifrenizi girininiz: "; passAgain = hidePass(); cout << endl;
    cout << endl;

    passCheck = u.getNickame() + u.getPass();

    fstream dosya("users.txt", ios::in); //Kullanici bilgilerini oku
    fstream dosya2("new.txt", ios::app);//yeni dosya



    if (dosya.is_open()) { //Dosya açildiysa

        while (!dosya.eof()) { //Dosya sonuna gelene kadar

            getline(dosya, line); //Dosyadan satir satir oku

            int offset = line.find(passCheck, 0);//Satirda aranan kelimenin bulunduğu konumu tutar

            //Satirda aranan kelime varsa
            if (offset != string::npos) {
				//okunan satirdaki aranan kelimeyi degistir
                dosya2 << u.getNickame() + pass + "\n";
                u.setPass(pass);
                cout << "Şifreniz başarıyla değiştirilmiştir!" << endl;
                cout << endl;
			}
			else {
				dosya2 << line << endl;
            }
        }
    }
    else
    {
        cout << "Islem basarisiz! " << endl << endl;
    }
    dosya.close();
    dosya2.close();
    remove("users.txt");
    rename("new.txt", "users.txt");
}

void userLogin() {

    //Kullanici adi ve sifreyi al

    cout << "Lütfen Giris Yapiniz! " << endl;
    cout << endl;
    string nickname, pass, passCheck, line;
    cout << "Kullanici Adiniz: "; getline(cin >> ws, nickname);
    cout << "Sifrenizi Giriniz: "; pass = hidePass();
    cout << endl;

    passCheck = (nickname + pass);

    fstream dosya("users.txt", ios::in); //Kullanici bilgilerini oku

    bool tf = false; //Kullanici bilgileri doğruysa true

    if (dosya.is_open()) { //Dosya açildiysa

        while (!dosya.eof()) { //Dosya sonuna gelene kadar

            getline(dosya, line); //Dosyadan satir satir oku

            int offset; //Satirda aranan kelimenin bulunduğu konumu tutar

            //Satirda aranan kelime varsa
            if ((offset = line.find(passCheck, 0)) != string::npos) {
                cout << "Bilgiler Doğru! Giris Yapiliyor... " << endl;
                cout << endl;
                admin = 0;
                tf = true;
                for (int i = 1; i <= User::getUserCount(); i++)
                {
                    if (userList[i].getNickame() == nickname && userList[i].getPass() == pass)
                    {
                        u = userList[i];
                        break;
                    }
                }
            }
        }
    }
    //Kullanici bilgileri yanlissa
    if (!tf) {
        cout << "Bilgileriniz Yanlis! " << endl;
        cout << endl;
    }
}

void showOrders() { //siparişleri listeler
    cout << endl;

    order::printList(u.orderList);

}

void SystemLogin() {
    //Sistem giris menüsü
    int c;
    cout << "1. Yönetici Girisi " << endl;
    cout << "2. Müsteri Girisi " << endl;
    cout << "3. Ana Menüye Geri Dön " << endl;

    //Hata yakalama
    try
    {
        if (!(cin >> c)) {
            throw 505;
        }
    }
    //Hata yakalandiysa
    catch (int hata)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Hatali bir giris yaptiniz lütfen tekrar deneyin ! Hata kodu: " << hata << endl;
        cout << endl;
        cout << "1. Yönetici Girisi " << endl;
        cout << "2. Müsteri Girisi " << endl;
        cout << "3. Ana Menüye Geri Dön " << endl;
        cin >> c;
    }

    //Seçim yap
    switch (c) {
    case 1:
        cout << "---Yönetici Girisi---" << endl;
        adminLogin();
        break;
    case 2:
        cout << "---Müsteri Girisi---" << endl;
        userLogin();
        break;
    case 3:
        cout << endl;
        break;
    default:
        cout << "Hatali Giris!" << endl;
        SystemLogin();
        break;
    }
}

void mainMenu() {

    Time timeNow;

    //Ana menü
    int choice; //Seçim yapmak için
    bool r = true; //Döngüyü kontrol eder
    int opt; //Seçim yapmak için
    string userchoice;
    int kur = 0;
    int i = 1;

    switch (admin) //Admin değilse
    {
    case -1:
        cout << "1. Sisteme Giris" << endl;
        cout << "2. Üye Kaydi" << endl;
        cout << "3. Çikis" << endl;

        //Hata yakalama
        try
        {
            if (!(cin >> choice)) {
                throw 505;
            }
        }
        catch (int hata)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Hatali bir giris yaptiniz lütfen tekrar deneyin ! Hata kodu: " << hata << endl;
            cout << endl;
            cout << "1. Sisteme Giris" << endl;
            cout << "2. Üye Kaydi" << endl;
            cout << "3. Çikis" << endl;
            cin >> choice;
        }


        switch (choice)
        {
        case 1:
            system("cls");
            cout << "---Sisteme Giris---" << endl;
            SystemLogin();
            break;
        case 2:
            system("cls");
            cout << "---Üye Kaydi---" << endl;
            cout << endl;
            User::signUp(); //Üye kaydi
            break;
        case 3:
            cout << "Çikis yapiliyor..." << endl;
            menu = false; //Ana menüden çik
            break;
        default:
            cout << "Hatali seçim!" << endl;
            break;
        }
        break;

        //Admin ise
    case 0:
        cout << "1. Siparis Ver " << endl;
        cout << "2. Siparisleri Görüntüle " << endl;
        cout << "3. sikayet - Öneri (Geri Bildirimler) " << endl;
        cout << "4. Sifre Degistir " << endl;
        cout << "5. Oturumu Kapat " << endl;
        cout << "6. Saati Goster " << endl;
        cout << "7. Cikis " << endl;

        //Hata yakalama
        try
        {
            if (!(cin >> choice)) {
                throw 505;
            }
        }
        catch (int hata)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Hatali bir giris yaptiniz lütfen tekrar deneyin ! Hata kodu: " << hata << endl;
            cout << endl;
            cout << "1. Siparis Ver " << endl;
            cout << "2. Siparisleri Görüntüle " << endl;
            cout << "3. sikayet - Öneri (Geri Bildirimler) " << endl;
            cout << "4. Sifre Degistir " << endl;
            cout << "5. Oturumu Kapat " << endl;
            cout << "6. Saati Goster " << endl;
            cout << "7. Cikis " << endl;
            cin >> choice;
        }

        switch (choice)
        {
        case 1:
            cout << "---Siparis Ver---" << endl << endl;
            giveOrder(); //Siparis ver
            cout << endl;
            break;
        case 2:
            system("cls");
            cout << "---Siparisleri Görüntüle---" << endl << endl;
            order::printList(u.orderList); //Siparisleri görüntüle

            cout << "Devam etmek için bir tusa basin... " << endl;
            getchar(); //Devam etmek için bir tusa bas
            cout << endl;
            break;
        case 3:
            system("cls");
            cout << "---Sikayet - Oneri (Geri Bildirimler)---" << endl; //ger bildirimler
            feedback();
            break;
        case 4:
            system("cls");
            cout << "---Sifre Degistirme Paneli---" << endl << endl; //şifre değişme
            passReset();
            break;
        case 5:
            cout << "Oturum Kapatiliyor..." << endl;
            for (int i = 1; i <= User::getUserCount(); i++)
            {
				if (u.getNickame() == userList[i].getNickame()) { //oturumu kapatmadan önce anlık kullanıcı bilgilerini dizideki kullanıcı bilgilerine eşitle
                    userList[i] = u;
                    break;
                }
            }
            admin = -1;
            break;
        case 6:
            //anlık saati yazdırır
            system("cls");
            mu.lock();
            timeNow.setHour(a);
            timeNow.setMinute(b);
            cout << endl << "Sistem Saati: " << timeNow << endl << endl;
            mu.unlock();
            break;
        case 7:
            cout << "Çikis yapiliyor..." << endl;
            menu = false;
            break;
        default:
            cout << "Hatali seçim!" << endl;
            break;
        }
        break;

        //Müsteri ise
    case 1:
        cout << "1. Ürünleri Görüntüle / Düzenle " << endl;
        cout << "2. Kuryeleri Düzenle " << endl;
        cout << "3. sikayet - Öneri (Geri Bildirimler) " << endl;
        cout << "4. İndirim Kodu Tanimla " << endl;
        cout << "5. Oturumu Kapat " << endl;
        cout << "6. Çikis " << endl;

        //Hata yakalama
        try
        {
            if (!(cin >> choice)) {
                throw 505;
            }
        }
        catch (int hata)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Hatali bir giris yaptiniz lütfen tekrar deneyin ! Hata kodu: " << hata << endl;
            cout << endl;
            cout << "1. Ürünleri Görüntüle / Düzenle " << endl;
            cout << "2. Kuryeleri Düzenle " << endl;
            cout << "3. sikayet - Öneri (Geri Bildirimler) " << endl;
            cout << "4. İndirim Kodu Tanimla " << endl;
            cout << "5. Oturumu Kapat " << endl;
            cout << "6. Çikis " << endl;
            cin >> choice;
        }

        switch (choice)
        {
        case 1:
            system("cls");
            cout << "---Ürünler---" << endl;
            cout << endl;
            products(); //Ürünleri görüntüle
            cout << endl;
            break;
        case 2:
            system("cls");
            //kuryeleri düzenleme menüsü
            cout << "---Kuryeler---" << endl;
            cout << "Kuryeleri görüntülemek için 1'e, diğer kuryeleri görüntülemek için 2'ye, devam etmek için 0'a basın. " << endl << endl;
            cin >> kur;
            if (kur == 1)
            {
                if (Courier::getCourierCount() == 0)
                {
                    cout << "Sistemde hic kurye yok! " << endl << endl;
                }
				for (i = 1; i <= Courier::getCourierCount(); i++)
				{
					cout << i << ". " << courierList[i].getName()<<"   Tel No: "<<courierList[i].getTelNo() << endl;
				}
            }
            if (kur == 2)
            {
                string name, tel;
                cout << "Lütfen kuryenin adini ve telefon numarasinin giriniz: " << endl << endl;
				cout << "Adi: "; getline(cin >> ws, name);
				cout << "Telefon Numarasi: "; getline(cin >> ws, tel);
                mu.lock();
				Courier::addCourier(new Courier(name, tel,new Time(a,b), i + 1), courierList);
                mu.unlock();
                cout << "Kurye basariyla eklendi! " << endl << endl;
            }
            break;
        case 3:
            system("cls");
			cout << "---Geri Bildirimler---" << endl; //geri bildirimler
            feedback();
            break;
        case 4:
            system("cls");
            //indirim kodu tanımlama
            cout << "---İndirim Kodlari---" << endl;
            for (int i = 1; i <= User::getUserCount(); i++)
            {
                userList[i].print();
                cout << "Seçmek için " << i << " tusuna basin" << endl << endl;
            }
            getline(cin >> ws, userchoice);
            if (userchoice == "1")
            {
                string coupon;
                cout << "Vermek istediğiniz kuponun indirim tutarini giriniz: (Sadece sayi olarak!)"; getline(cin >> ws, coupon);
                userList[1].setSaleCoupon(coupon);
            }
            else if (userchoice == "2")
            {
                string coupon;
                cout << "Vermek istediğiniz kuponun indirim tutarini giriniz: (Sadece sayi olarak!)"; getline(cin >> ws, coupon);
                userList[2].setSaleCoupon(coupon);
            }
            else if (userchoice == "3")
            {
                string coupon;
                cout << "Vermek istediğiniz kuponun indirim tutarini giriniz: (Sadece sayi olarak!)"; getline(cin >> ws, coupon);
                userList[3].setSaleCoupon(coupon);
            }
            else if (userchoice == "4")
            {
                string coupon;
                cout << "Vermek istediğiniz kuponun indirim tutarini giriniz: (Sadece sayi olarak!)"; getline(cin >> ws, coupon);
                userList[4].setSaleCoupon(coupon);
            }
            else if (userchoice == "5")
            {
                string coupon;
                cout << "Vermek istediğiniz kuponun indirim tutarini giriniz: (Sadece sayi olarak!)"; getline(cin >> ws, coupon);
                userList[5].setSaleCoupon(coupon);
            }
            else if (userchoice == "6")
            {
                string coupon;
                cout << "Vermek istediğiniz kuponun indirim tutarini giriniz: (Sadece sayi olarak!)"; getline(cin >> ws, coupon);
                userList[6].setSaleCoupon(coupon);
            }
            break;
        case 5:
            system("cls");
            cout << "Oturum Kapatiliyor..." << endl;
            admin = -1; //Oturumu kapat
            break;
        case 6:
            cout << "Çikis Yapiliyor..." << endl;
            menu = false; //Ana menüden çik
            break;
        default:
            cout << "Hatali Seçim! " << endl;
            break;
        }
    default:
        cout << endl;
        break;
    }
}

void run() { //çalıştırılacak ana thread
    while (menu)
    {
        mainMenu();
    }
}

void Time::setTimer(Time SAAT)
{ //Saat ve dakika değerlerini ayarla
    while (menu)
    {
        b += 0.0000000015;
        if (b >= 60)
        {
            a += b / 60;
            b = (int(b) % 60);
        }
        if (a >= 24)
        {
            a = 0;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Turkish");

    srand(time(NULL));
    fillup();
    Courier::setCourierCount(0);
    thread t1(Time::setTimer, SAAT); //sistem saati için bir iş parçacığı oluşturur
    thread t2(run); //ana iş parçacığını oluşturur
    //threadleri çalıştırır
    t1.join();
    t2.join();

    return 0;
}
