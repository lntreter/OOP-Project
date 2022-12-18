#include<iostream>
#include<string>
#include<fstream>
#include<limits>
#include<conio.h>
#include<locale.h>
#include <thread>
#include <mutex>

using namespace std;

mutex mu;

string feedBack;

int fark;

int orderNo = 0;//Sipariş numarası

string nameList[] = { "Celalettin Mantar","Burhan Şahin","Berhan Saydam","Talha Yay","Sefa Subaşı",
    "Cemil NovruzOğlu","Mustafa Novruzğlu","Mehmet Şahin","Talha Subaşı" };

string telList[] = { "0532 123 45 67","0532 123 45 68","0532 123 45 69","0532 123 45 70","0532 123 45 71",
    "0532 123 45 72","0532 123 45 73","0532 123 45 74","0532 123 45 75" };

class Time { //Zaman Sınıfı
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
    void print() { //Saat ve dakika değerlerini ekrana yazdırır
        cout << hour << ":" << minute << endl;
    }
    static void setTimer(Time);

    void delay(int d) { //Saat ve dakika değerlerini gecikme değeri kadar arttırır
        minute += d;
        if (minute >= 60) {
            hour += minute / 60;
            minute = minute % 60;
        }
    }

    bool operator>(const Time& t) {//Saat ve dakika değerlerini karşılaştırır
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

    bool operator>(const Time* t) {//Saat ve dakika değerlerini karşılaştırır
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

    bool operator==(const Time& t) {//Saat ve dakika değerlerini karşılaştırır
        if (hour == t.hour) {
            if (minute == t.minute) {
                return true;
            }
        }
        return false;
    }

    friend ostream& operator<<(ostream& os, const Time& t) {//Saat ve dakika değerlerini ekrana yazdırır
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

class Clothes {
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
Clothes clothesList[500];//Kıyafetlerin tutulduğu liste

void Clothes::orderClotes(Clothes* list) {//Sipariş verme fonksiyonu
    for (int i = 1; i <= clotheCount; i++)
    {
        list[i].print();//Kıyafetleri listeler
        cout << "Satin almak icin " << i << " tusuna basiniz." << endl << endl;
    }

}

void Clothes::listClothes(Clothes list[]) {//Kıyafetleri listeler
    for (int i = 1; i <= clotheCount; i++) {
        list[i].print();
    }
}

void Clothes::addClothe(Clothes* c, Clothes list[]) {//Kıyafet ekler
    if (clotheCount < listSize) {//Stok dolu değilse
        list[clotheCount] = *c;//Kıyafetleri listeye ekler
    }
    else {
        cout << "Stok Dolu!" << endl;//Stok doluysa
    }
}
void Clothes::delClothe(Clothes c, Clothes list[]) {//Kıyafet siler
    Clothes* tmp = new Clothes[clotheCount];//Geçici bir liste oluşturur

    for (int i = 1; i <= clotheCount; i++) {//Kıyafetleri gezer

        if (list[i].getName() == c.getName()) {//Eğer silinecek kıyafet bulunursa

            list[clotheCount + 1] = list[i];//Son kıyafet silinecek kıyafetin yerine konur

            for (int k = i; k < clotheCount; k++)//Silinen kıyafetin yerine gelen kıyafetlerin yerini değiştirir
            {
                list[k] = list[k + 1];//Kıyafetlerin yerini değiştirir
            }
            clotheCount--;
        }
        if (!(i > clotheCount))//Eğer silinen kıyafet yoksa

            tmp[i] = list[i];//Geçici listeye kıyafetleri ekler
    }
    list = tmp;//Geçici listeyi ana listeye atar
}

class Person {
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
    static void printList(Person* list) {//Personları listeler
        for (int i = 0; i < personCount; i++) {
            list[i].print();
        }
        cout << endl;
    }
};

int Person::personCount = 0;
int Person::listSize = 1000;

class Courier : Person {
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

Time SAAT(4, 0);

double a = SAAT.getHour(), b = SAAT.getMinute();

class order : Clothes {
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

class User : Person {
private:
    string nickname;
    string mail;
    string adress;
    string pass;
    string saleCoupon;
    string bDate;
    static int userCount;
public:
    order orderList[100];//Sipariş listesi
    int orderCount;
    User() { ; }
    User(string n, string t, string ni, string m, string a, string p, string sc, string b) : Person(n, t), saleCoupon("0") {
        nickname = ni;
        mail = m;
        adress = a;
        pass = p;
        saleCoupon = sc;
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
User u("", "", "", "", "", "", "", "");

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

void order::delOrder(order o, order* list) {//Sipariş silme fonksiyonu
    for (int i = 1; i <= u.orderCount; i++) {//Sipariş sayısı kadar döner
        if (list[i].getOrderNo() == o.getOrderNo()) {//Sipariş numarası eşitse
            for (int j = i; j <= u.orderCount; j++) {//Sipariş sayısı kadar döner
                list[j] = list[j + 1];//Siparişi siler
            }
            u.orderCount--;//Sipariş sayısını azaltır
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

void order::print() {
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
        cout << "Delivery Time: " << deliveryTime << " Sipariş " << fark << " dakikada teslim edildi! " << endl;
        cout << "Kurye Bilgileri : " << courier.getName() << " Tel: " << courier.getTelNo() << endl;
        cout << "---Ürün Bilgileri---" << endl;
        Clothes::print();
    }
    else {
        cout << "Order No: " << orderNo << endl;
        cout << "Order Price: " << orderPrice - stoi(u.getSaleCoupon()) << "TL" << endl;
        cout << "Order Time: " << orderTime << endl;
        cout << "Order - Delivery Time: " << fark << endl;
        cout << "Delivery Time: " << deliveryTime << endl;
        cout << "Kurye Bilgileri : " << courier.getName() << " Tel: " << courier.getTelNo() << endl;
        cout << "---Ürün Bilgileri---" << endl;
        Clothes::print();
    }
}

class Admin : Person {
private:
    string pass;
public:
    Admin() {} //default constructor
    Admin(string n, string t, string p) : Person(n, t) {
        pass = p;
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

int admin = -1;//Admin girişi kontrolü
bool menu = true;//Menü kontrolü

void mainMenu();
void SystemLogin();
void userLogin();
void orders();
User userList[100];//Kullanıcı listesi

void order::addOrder(order* o, order list[], Courier* c) {//Sipariş ekleme fonksiyonu

    if (u.orderCount < listSize) {//Liste dolu değilse
        o->courier = *c;
        for (int i = 0; i < Courier::getCourierCount(); i++)
        {
            if (list[i].getName() != o->getName()) {
                Courier::setCourierCount(Courier::getCourierCount() - 1);
                break;
            }
        }
        list[u.orderCount] = *o;//Siparişi listeye ekler
        clotheCount--;//Kıyafet sayısını azaltır
        delClothe(*o, clothesList);//Kıyafeti siler
    }
    else {
        cout << "Sepet Dolu!" << endl;
    }
    Courier::addCourier(c, courierList);
}

void Courier::addCourier(Courier* o, Courier list[]) {
    if (courierCount < listSize) {
        list[courierCount] = *o;
    }
    else {
        cout << "Kadro Dolu!" << endl;
    }
}

int j = 1;


void feedback() {
    string feedbackyaz;
    if (admin == 1)
    {
        if (feedBack == "") {
            cout << "Herhangi bir geri bildirim yapılmamış. " << endl << endl;
        }
        else
        {
            int control = -1;
            cout << feedBack << endl << endl << endl;
            cout << "Geri bildirimlere cevap vermek için '1', çıkmak için '0' tuşuna basın. "; cin >> control; cout << endl;
            if (control == 1)
            {
                cout << "Lütfen Mesajınızı yazın: "; getline(cin >> ws, feedbackyaz);
                feedBack += "\n\nYetkili Kullanıcı: " + feedbackyaz;
                cout << "Mesajınız başarıyla gönderildi! " << endl << endl;
            }
            else if (control == 0)
            {
                ;//geç
            }
            else
            {
                cout << "Hatalı bir tuşlama yaptınız! " << endl;
            }
        }
    }
    else if (admin == 0)
    {
        cout << feedBack << endl << endl << endl;
        if (feedBack == "") {
            cout << "Henüz kimse geri bildirim yapmamış. " << endl << endl;
        }
        int control = -1;
        cout << "Bir geri bildirim mesajı yazmak için '1', geri dönmek için '0' tuşuna basın. "; cin >> control; cout << endl;
        if (control == 1)
        {
            cout << "Lütfen Mesajınızı yazın: "; getline(cin >> ws, feedbackyaz);
            feedBack += "\n\n" + u.getNickame() + ": " + feedbackyaz;
            cout << "Mesajınız başarıyla gönderildi! " << endl << endl;
        }
        else if (control == 0)
        {
            ;//geç
        }
        else
        {
            cout << "Hatalı bir tuşlama yaptınız! " << endl;
        }
    }
}

void giveOrder() {//Sipariş verme

    srand(time(NULL));//Rastgele sayı üretimi için
    mu.lock();//Kilit

    Time orderTime = Time(a, b);//Sipariş zamanı
    Time deliveryTime(a + (rand() % 2 + 0), b + (rand() % 45 + 0));//Teslimat zamanı

    mu.unlock();//Kilit aç
    int opt;//Seçenek

    Clothes::orderClotes(clothesList);//Kıyafetleri listeleme
    cout << "Geri dönmek için 0 tuşuna basın. " << endl;
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
        cerr << "Hatalı bir giriş yaptınız lütfen tekrar deneyin ! Hata kodu: " << hata << endl; //Hata mesajı
        cout << endl; //Boşluk
        cout << "Geri dönmek için 0 tuşuna basın. " << endl; //Kullanıcıya bilgi ver
        cin >> opt;
    }
    for (int i = 1; i <= Clothes::getClotheCount(); i++) //Kıyafet sayısı kadar döngü
    {
        if (opt == i)
        {
            if (Courier::getCourierCount() == 100) {
                Courier::setCourierCount(0);
            }
            if (Courier::getCourierCount() == 0)
            {
                Time* nT = new Time(deliveryTime.getHour(), deliveryTime.getMinute());
                Courier* n = new Courier(nameList[0], telList[0], nT, orderNo);
                Courier::addCourier(n, courierList);
                order::addOrder(new order(++orderNo, clothesList[i].getPrice(), orderTime, deliveryTime, //Sipariş ekleme
                    clothesList[i].getCategory(), clothesList[i].getName(),
                    clothesList[i].getPrice(), clothesList[i].getSize(), clothesList[i].getColor()), u.orderList, &courierList[1]);
                cout << "Siparişiniz başarıyla alındı! " << endl << endl;
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
                            order::addOrder(new order(++orderNo, clothesList[i].getPrice(), orderTime, deliveryTime, //Sipariş ekleme
                                clothesList[i].getCategory(), clothesList[i].getName(),
                                clothesList[i].getPrice(), clothesList[i].getSize(), clothesList[i].getColor()), u.orderList, &courierList[z]);
                            cout << "Siparişiniz başarıyla alındı! " << endl << endl;
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
                        order::addOrder(new order(++orderNo, clothesList[i].getPrice(), orderTime, deliveryTime, //Sipariş ekleme
                            clothesList[i].getCategory(), clothesList[i].getName(),
                            clothesList[i].getPrice(), clothesList[i].getSize(), clothesList[i].getColor()), u.orderList, &courierList[z]);
                        cout << "Siparişiniz başarıyla alındı! " << endl << endl;
                        check = 999;
                        Time* a = new Time(deliveryTime.getHour(), deliveryTime.getMinute());
                        courierList[z].setOrderCompleteTime(a);
                        break;
                    }
                    else {
                        z++;
                    }
                } while (z <= Courier::getCourierCount());

                z = 1;

                if (check == 999)
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
                                order::addOrder(new order(++orderNo, clothesList[i].getPrice(), orderTime, deliveryTime, //Sipariş ekleme
                                    clothesList[i].getCategory(), clothesList[i].getName(),
                                    clothesList[i].getPrice(), clothesList[i].getSize(), clothesList[i].getColor()), u.orderList, new Courier(
                                        nameList[j], telList[j], nT1, orderNo
                                    ));
                                cout << "Siparişiniz başarıyla alındı! " << endl << endl;
                                j++;
                                break;
                            }
                            else {
                                z;
                            }
                        }
                        if (courierList[z].getOrderCompleteTime()->getHour() > now->getHour()) {
                            Time* nT1 = new Time(deliveryTime.getHour(), deliveryTime.getMinute());
                            order::addOrder(new order(++orderNo, clothesList[i].getPrice(), orderTime, deliveryTime, //Sipariş ekleme
                                clothesList[i].getCategory(), clothesList[i].getName(),
                                clothesList[i].getPrice(), clothesList[i].getSize(), clothesList[i].getColor()), u.orderList, new Courier(
                                    nameList[j], telList[j], nT1, orderNo
                                ));
                            cout << "Siparişiniz başarıyla alındı! " << endl << endl;
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
        else if (opt == 0) {//Geri dönmek için 0 tuşuna basın.
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
        cerr << "Hatalı bir giriş yaptınız lütfen tekrar deneyin ! Hata kodu: " << hata << endl;
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
        cout << "---Ürün Ekleme Ekranı---" << endl;
        cout << "Eklemek istediğiniz ürünün türünü (Giysi - Aksesuar - Ayakkabı) seçiniz: " << endl;
        getline(cin >> ws, category);
        cout << "Ürünün adını giriniz: " << endl;
        getline(cin >> ws, name);
        cout << "Ürünün fiyatını giriniz: " << endl;
        cin >> price;
        cout << "Ürünün bedenini (Small: S, Medium: M, Large: L) giriniz: " << endl;
        getline(cin >> ws, size);
        cout << "Ürünün rengini giriniz: " << endl;
        getline(cin >> ws, color);
        Clothes::addClothe(new Clothes(category, name, price, size, color), clothesList);
        cout << "Ürün başarıyla eklendi!" << endl << endl;
        products();
        break;
    case 2:
        cout << "---Ürün Silme Ekranı---" << endl << endl;
        cout << "Silmek istediğiniz ürünün adını giriniz: " << endl;
        getline(cin >> ws, named);
        do {
            if (named == clothesList[i].getName()) //Kıyafet adı girilen kıyafet adı ile aynı ise
            {
                Clothes::delClothe(clothesList[i], clothesList); //Kıyafet sil
                cout << "Ürün başarıyla silindi." << endl;
                i = 1;
                break;
            }
            i++;

        } while (i <= Clothes::getClotheCount());  //Kıyafet sayısı kadar döngü

        if (i > Clothes::getClotheCount() && i != 1) //Kıyafet sayısı kadar döngü döndüyse ve ürün bulunamadıysa
        {
            cout << "Ürün Bulunamadı" << endl; //Ürün bulunamadı mesajı
            i = 1;
        }
        break;
    case 3:
        cout << "---Ürün Listeleme Ekranı---" << endl << endl;
        system("cls");
        Clothes::listClothes(clothesList); //Kıyafetleri listele

        cout << "Devam etmek için bir tuşa basın. " << endl; //Kullanıcıya bilgi ver

        getchar(); //Kullanıcıdan bir tuşa basmasını bekler
        cout << endl;
        break;
    case 4:
        cout << endl;
        break;
    default:
        cout << "Hatalı bir giriş yaptınız lütfen tekrar deneyin !" << endl;
        products();
        break;
    }
}

void User::signUp() {
    fstream dosya("users.txt", ios::app);

    string name, nickname, telNo, mail, adress, pass, saleCoupon, bDate;

    //Kullanıcıdan bilgileri al

    cout << "Kayıt olmak için bilgilerinizi giriniz." << endl;
    cout << endl;
    cout << "Adınız: "; getline(cin >> ws, name);
    cout << "Kullanıcı adınız: "; getline(cin >> ws, nickname);
    cout << "Şifreniz: "; getline(cin >> ws, pass);
    cout << "Telefon Numaranız: "; getline(cin >> ws, telNo);
    cout << "Mail Adredsiniz: "; getline(cin >> ws, mail);
    cout << "Adresiniz: "; getline(cin >> ws, adress);
    cout << "Doğum Tarihiniz (Gün.Ay.Yıl): "; getline(cin >> ws, bDate);
    cout << endl;

    //Kullanıcıyı oluştur

    try {
        User* a = new User(name, telNo, nickname, mail, adress, pass, saleCoupon, bDate);
        a->orderCount = 0;
        userList[userCount] = *a;
        cout << "Kayıt Başarılı! ---> Lütfen Giriş Yapınız! " << endl;
        cout << endl;

    }  //Hata yakalarsa

    catch (exception& e) {
        cout << "Kayıt başarısız! " << endl;
        mainMenu();
    }

    if (dosya.is_open()) { //Dosya açıldıysa
        dosya << nickname + pass << endl;   //Kullanıcı adı ve şifreyi dosyaya yaz
        dosya.close(); //Dosyayı kapat
    }
    else {
        cout << "Dosya açılamadı!" << endl;
    }
}

void adminLogin() {
    cout << "Lütfen Admin Şifresini Giriniz: " << endl;
    cout << endl;

    //Admin şifresini al

    string pass;

    cout << "Admin Şifre: "; getline(cin >> ws, pass);
    cout << endl;

    if (pass == "admin")
    {
        cout << "Şifre Doğru! Admin Olarak Giriş Yapılıyor..." << endl;
        cout << endl;
        admin = 1;
    }
    else {
        cout << "Şifre Yanlış! " << endl;
        cout << endl;
    }
}

void userLogin() {

    //Kullanıcı adı ve şifreyi al

    cout << "Lütfen Giriş Yapınız! " << endl;
    cout << endl;
    string nickname, pass, passCheck, line, candidate;
    cout << "Kullanıcı Adınız: "; getline(cin >> ws, nickname);
    cout << "Şifrenizi Giriniz: "; getline(cin >> ws, pass);
    cout << endl;

    passCheck = (nickname + pass);

    fstream dosya("users.txt", ios::in); //Kullanıcı bilgilerini oku

    bool tf = false; //Kullanıcı bilgileri doğruysa true

    if (dosya.is_open()) { //Dosya açıldıysa

        while (!dosya.eof()) { //Dosya sonuna gelene kadar

            getline(dosya, line); //Dosyadan satır satır oku

            int offset; //Satırda aranan kelimenin bulunduğu konumu tutar

            //Satırda aranan kelime varsa
            if ((offset = line.find(passCheck, 0)) != string::npos) {
                cout << "Bilgiler Doğru! Giriş Yapılıyor... " << endl;
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
    //Kullanıcı bilgileri yanlışsa
    if (!tf) {
        cout << "Bilgileriniz Yanlış! " << endl;
        cout << endl;
    }
}

void showOrders() {
    cout << endl;

    order::printList(u.orderList);

}

void SystemLogin() {
    //Sistem giriş menüsü
    int c;
    cout << "1. Yönetici Girişi " << endl;
    cout << "2. Müşteri Girişi " << endl;
    cout << "3. Ana Menüye Geri Dön " << endl;

    //Hata yakalama
    try
    {
        if (!(cin >> c)) {
            throw 505;
        }
    }
    //Hata yakalandıysa
    catch (int hata)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Hatalı bir giriş yaptınız lütfen tekrar deneyin ! Hata kodu: " << hata << endl;
        cout << endl;
        cout << "1. Yönetici Girişi " << endl;
        cout << "2. Müşteri Girişi " << endl;
        cout << "3. Ana Menüye Geri Dön " << endl;
        cin >> c;
    }

    //Seçim yap
    switch (c) {
    case 1:
        cout << "---Yönetici Girişi---" << endl;
        adminLogin();
        break;
    case 2:
        cout << "---Müşteri Girişi---" << endl;
        userLogin();
        break;
    case 3:
        cout << endl;
        break;
    default:
        cout << "Hatalı Giriş!" << endl;
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

    switch (admin) //Admin değilse
    {
    case -1:
        cout << "1. Sisteme Giriş" << endl;
        cout << "2. Üye Kaydı" << endl;
        cout << "3. Çıkış" << endl;

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
            cerr << "Hatalı bir giriş yaptınız lütfen tekrar deneyin ! Hata kodu: " << hata << endl;
            cout << endl;
            cout << "1. Sisteme Giriş" << endl;
            cout << "2. Üye Kaydı" << endl;
            cout << "3. Çıkış" << endl;
            cin >> choice;
        }


        switch (choice)
        {
        case 1:
            system("cls");
            cout << "---Sisteme Giriş---" << endl;
            SystemLogin();
            break;
        case 2:
            system("cls");
            cout << "---Üye Kaydı---" << endl;
            cout << endl;
            User::signUp(); //Üye kaydı
            break;
        case 3:
            cout << "Çıkış yapılıyor..." << endl;
            menu = false; //Ana menüden çık
            break;
        default:
            cout << "Hatalı seçim!" << endl;
            break;
        }
        break;

        //Admin ise
    case 0:
        cout << "1. Sipariş Ver " << endl;
        cout << "2. Siparişleri Görüntüle " << endl;
        cout << "3. Şikayet - Öneri (Geri Bildirimler) " << endl;
        cout << "4. Oturumu Kapat " << endl;
        cout << "5. Saati Göster " << endl;
        cout << "6. Çıkış " << endl;

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
            cerr << "Hatalı bir giriş yaptınız lütfen tekrar deneyin ! Hata kodu: " << hata << endl;
            cout << endl;
            cout << "1. Sipariş Ver " << endl;
            cout << "2. Siparişleri Görüntüle " << endl;
            cout << "3. Şikayet - Öneri (Geri Bildirimler) " << endl;
            cout << "4. Oturumu Kapat " << endl;
            cout << "5. Saati Göster " << endl;
            cout << "6. Çıkış " << endl;
            cin >> choice;
        }

        switch (choice)
        {
        case 1:
            cout << "---Sipariş Ver---" << endl << endl;
            giveOrder(); //Sipariş ver
            cout << endl;
            break;
        case 2:
            system("cls");
            cout << "---Siparişleri Görüntüle---" << endl << endl;
            order::printList(u.orderList); //Siparişleri görüntüle

            cout << "Devam etmek için bir tuşa basın... " << endl;
            getchar(); //Devam etmek için bir tuşa bas
            cout << endl;
            break;
        case 3:
            system("cls");
            cout << "---Şikayet - Öneri (Geri Bildirimler)---" << endl;
            feedback();
            break;
        case 4:
            cout << "Oturum Kapatılıyor..." << endl;
            for (int i = 1; i <= User::getUserCount(); i++)
            {
                if (u.getNickame() == userList[i].getNickame()) {
                    userList[i] = u;
                    break;
                }
            }
            admin = -1;
            break;
        case 5:
            system("cls");
            mu.lock();
            timeNow.setHour(a);
            timeNow.setMinute(b);
            cout << endl << "Sistem Saati: " << timeNow << endl << endl;
            mu.unlock();
            break;
        case 6:
            cout << "Çıkış yapılıyor..." << endl;
            menu = false;
            break;
        default:
            cout << "Hatalı seçim!" << endl;
            break;
        }
        break;

        //Müşteri ise
    case 1:
        cout << "1. Ürünleri Görüntüle / Düzenle " << endl;
        cout << "2. Kuryeleri Düzenle " << endl;
        cout << "3. Şikayet - Öneri (Geri Bildirimler) " << endl;
        cout << "4. İndirim Kodu Tanımla " << endl;
        cout << "5. Oturumu Kapat " << endl;
        cout << "6. Çıkış " << endl;

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
            cerr << "Hatalı bir giriş yaptınız lütfen tekrar deneyin ! Hata kodu: " << hata << endl;
            cout << endl;
            cout << "1. Ürünleri Görüntüle / Düzenle " << endl;
            cout << "2. Kuryeleri Düzenle " << endl;
            cout << "3. Şikayet - Öneri (Geri Bildirimler) " << endl;
            cout << "4. İndirim Kodu Tanımla " << endl;
            cout << "5. Oturumu Kapat " << endl;
            cout << "6. Çıkış " << endl;
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
            cout << "---Kuryeler---" << endl;
            break;
        case 3:
            system("cls");
            cout << "---Geri Bildirimler---" << endl;
            feedback();
            break;
        case 4:
            system("cls");
            cout << "---İndirim Kodları---" << endl;
            for (int i = 1; i <= User::getUserCount(); i++)
            {
                userList[i].print();
                cout << "Seçmek için " << i << " tuşuna basın" << endl << endl;
            }
            getline(cin >> ws, userchoice);
            if (userchoice == "1")
            {
                string coupon;
                cout << "Vermek istediğiniz kuponun indirim tutarını giriniz: (Sadece sayı olarak!)"; getline(cin >> ws, coupon);
                userList[1].setSaleCoupon(coupon);
            }
            else if (userchoice == "2")
            {
                string coupon;
                cout << "Vermek istediğiniz kuponun indirim tutarını giriniz: (Sadece sayı olarak!)"; getline(cin >> ws, coupon);
                userList[2].setSaleCoupon(coupon);
            }
            else if (userchoice == "3")
            {
                string coupon;
                cout << "Vermek istediğiniz kuponun indirim tutarını giriniz: (Sadece sayı olarak!)"; getline(cin >> ws, coupon);
                userList[3].setSaleCoupon(coupon);
            }
            else if (userchoice == "4")
            {
                string coupon;
                cout << "Vermek istediğiniz kuponun indirim tutarını giriniz: (Sadece sayı olarak!)"; getline(cin >> ws, coupon);
                userList[4].setSaleCoupon(coupon);
            }
            else if (userchoice == "5")
            {
                string coupon;
                cout << "Vermek istediğiniz kuponun indirim tutarını giriniz: (Sadece sayı olarak!)"; getline(cin >> ws, coupon);
                userList[5].setSaleCoupon(coupon);
            }
            else if (userchoice == "6")
            {
                string coupon;
                cout << "Vermek istediğiniz kuponun indirim tutarını giriniz: (Sadece sayı olarak!)"; getline(cin >> ws, coupon);
                userList[6].setSaleCoupon(coupon);
            }
            break;
        case 5:
            system("cls");
            cout << "Oturum Kapatılıyor..." << endl;
            admin = -1; //Oturumu kapat
            break;
        case 6:
            cout << "Çıkış Yapılıyor..." << endl;
            menu = false; //Ana menüden çık
            break;
        default:
            cout << "Hatalı Seçim! " << endl;
            break;
        }
    default:
        cout << endl;
        break;
    }
}

void run() {
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
    Courier::setCourierCount(0);

    thread t1(Time::setTimer, SAAT);
    thread t2(run);
    t1.join();
    t2.join();

    return 0;
}