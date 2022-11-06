#include<iostream>
#include<string>
#include<fstream>
#include<limits>

using namespace std;

class Time{ //Zaman Sınıfı
    private:
    int hour;
    int minute;
    public:
    Time(){}
    Time(int h, int m){//Kurucu fonksiyon
        hour = h;
        minute = m;
    }
    void setHour(int s){ //Saat değerini ayarlar
        hour = s;
    }
    void setMinute(int d){ //Dakika değerini ayarlar
        minute = d;
    }
    int getHour(){ //Saat değerini döndürür
        return hour;
    }
    int getMinute(){ //Dakika değerini döndürür
        return minute;
    }
    void print(){ //Saat ve dakika değerlerini ekrana yazdırır
        cout << hour << ":" << minute << endl;
    }
    void delay(int d){ //Saat ve dakika değerlerini gecikme değeri kadar arttırır
        minute += d;
        if(minute >= 60){
            hour += minute / 60;
            minute = minute % 60;
        }
    }
    friend ostream& operator<<(ostream& os, const Time& t){//Saat ve dakika değerlerini ekrana yazdırır
        os << t.hour << ":" << t.minute;
        return os;
    }
};

class Clothes{
    protected:
    string category;
    string name;
    double price;
    string size;
    string color;
    public:
    Clothes(string c, string n, double p, string s, string col){
        category = c;
        name = n;
        price = p;
        size = s;
        color = col;
    }
    void setCategory(string c){
        category = c;
    }
    void setName(string n){
        name = n;
    }
    void setPrice(double p){
        price = p;
    }
    void setSize(string s){
        size = s;
    }
    void setColor(string col){
        color = col;
    }
    string getCategory(){
        return category;
    }
    string getName(){
        return name;
    }
    double getPrice(){
        return price;
    }
    string getSize(){
        return size;
    }
    string getColor(){
        return color;
    }
    void print(){
        cout << "Category: " << category << endl;
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Size: " << size << endl;
        cout << "Color: " << color << endl;
        cout << "-----------------------" << endl;
    }
};

class Person{
    protected:
    string name;
    string telNo;
    static int personCount;
    static int listSize;
    public:
    Person(){}
    Person(string n, string t){
        name = n;
        telNo = t;
        personCount++;
    }
    ~Person(){
        personCount--;
    }
    void setName(string n){
        name = n;
    }
    void setTelNo(string t){
        telNo = t;
    }
    void setPersonCount(int p){
        personCount = p;
    }
    void setListSize(int l){
        listSize = l;
    }
    string getName(){
        return name;
    }
    string getTelNo(){
        return telNo;
    }
    int getPersonCount(){
        return personCount;
    }
    static int getListSize(){
        return listSize;
    }
    void print(){
        cout << "Name: " << name << endl;
        cout << "Tel No: " << telNo << endl;
    }
    static void addPerson(Person *p, Person *list){
        if(personCount < listSize){
            list[personCount] = *p;
        }
        else{
            cout << "List is full!" << endl;
        }
    }
    static void del(Person p, Person *list){
        for(int i = 0; i < personCount; i++){
            if(list[i].getName() == p.getName()){
                for(int j = i; j < personCount; j++){
                    list[j] = list[j+1];
                }
                personCount--;
                break;
            }
        }
    }
    static void printList(Person *list){
        for(int i = 0; i < personCount; i++){
            list[i].print();
        }
        cout << endl;
    }
};

int Person::personCount = 0;
int Person::listSize = 0;

class order : Clothes{
    private:
    int orderNo;
    double orderPrice;
    Time orderTime;
    Time deliveryTime;
    static int orderCount;
    static int listSize;
    public:
    order(int o, double p, Time t, Time d, string c, string n, double pr, string s, string col) : Clothes(c, n, pr, s, col){
        orderNo = o;
        orderPrice = p;
        orderTime = t;
        deliveryTime = d;
        orderCount++;
    }
    void setOrderNo(int o){
        orderNo = o;
    }
    void setOrderPrice(double p){
        orderPrice = p;
    }
    void setOrderTime(Time t){
        orderTime = t;
    }
    void setDeliveryTime(Time d){
        deliveryTime = d;
    }
    void setOrderCount(int o){
        orderCount = o;
    }
    void setListSize(int l){
        listSize = l;
    }
    int getOrderNo(){
        return orderNo;
    }
    double getOrderPrice(){
        return orderPrice;
    }
    Time getOrderTime(){
        return orderTime;
    }
    Time getDeliveryTime(){
        return deliveryTime;
    }
    int getOrderCount(){
        return orderCount;
    }
    int getListSize(){
        return listSize;
    }
    void print(){
        cout << "Order No: " << orderNo << endl;
        cout << "Order Price: " << orderPrice << endl;
        cout << "Order Time: " << orderTime << endl;
        cout << "Delivery Time: " << deliveryTime << endl;
        Clothes::print();
        cout << "-----------------------" << endl;
    }
    int orderDeliveryTime(){
        return deliveryTime.getHour() - orderTime.getHour();
    }
    static void addOrder(order *o, order *list){
        if(orderCount < listSize){
            list[orderCount] = *o;
        }
        else{
            cout << "List is full!" << endl;
        }
    }
    static void delOrder(order o, order *list){
        for(int i = 0; i < orderCount; i++){
            if(list[i].getOrderNo() == o.getOrderNo()){
                for(int j = i; j < orderCount; j++){
                    list[j] = list[j+1];
                }
                orderCount--;
                break;
            }
        }
    }
    static void updateOrder(order o, order *list){
        for(int i = 0; i < orderCount; i++){
            if(list[i].getOrderNo() == o.getOrderNo()){
                list[i] = o;
                break;
            }
        }
    }
    static void printList(order *list){
        for(int i = 0; i < orderCount; i++){
            list[i].print();
        }
        cout << endl;
    }
};

int order::orderCount = 0;
int order::listSize = 0;

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
    User(string n, string t, string ni, string m, string a, string p, string sc, string b) : Person(n, t){
        nickname = ni;
        mail = m;
        adress = a;
        pass = p;
        saleCoupon = sc;
        bDate = b;
        userCount++;
    }
    void setNickname(string n){
        nickname = n;
    }
    void setMail(string m){
        mail = m;
    }
    void setAdress(string a){
        adress = a;
    }
    void setPass(string p){
        pass = p;
    }
    void setSaleCoupon(string s){
        saleCoupon = s;
    }
    void setBDate(string b){
        bDate = b;
    }
    string getNickame(){
        return nickname;
    }
    string getMail(){
        return mail;
    }
    string getAdress(){
        return adress;
    }
    string getPass(){
        return pass;
    }
    string getSaleCoupon(){
        return saleCoupon;
    }
    string getBDate(){
        return bDate;
    }
    void print(){
        cout << "Name: " << name << endl;
        cout << "Nickname: " << nickname << endl;
        cout << "Tel No: " << telNo << endl;
        cout << "Mail: " << mail << endl;
        cout << "Adress: " << adress << endl;
        cout << "Pass: " << pass << endl;
        cout << "Sale Coupon: " << saleCoupon << endl;
        cout << "Birth Date: " << bDate << endl;
    }
    static void signUp();
};

int User::userCount = 0;

class Admin : Person {
    private:
    string pass;
    public:
    Admin(){} //default constructor
    Admin(string n, string t, string p) : Person(n, t){
        pass = p;
    }
    void setPass(string p){
        pass = p;
    }
    string getPass(){
        return pass;
    }
    void print(){
        cout << "Name: " << name << endl;
        cout << "Tel No: " << telNo << endl;
        cout << "Pass: " << pass << endl;
    }
};

class Courier : Person {
    private:
    Time* orderCompleteTime;
    int* orderNo;
    public:
    Courier(string n, string t, Time *o, int *no) : Person(n, t){
        orderCompleteTime = o;
        orderNo = no;
    }
    ~Courier(){
        cout << "Courier deleted!" << endl;
    }
    void setOrderCompleteTime(Time *o){
        orderCompleteTime = o;
    }
    void setOrderNo(int *no){
        orderNo = no;
    }
    Time* getOrderCompleteTime(){
        return orderCompleteTime;
    }
    int* getOrderNo(){
        return orderNo;
    }
    void print(){
        cout << "Name: " << name << endl;
        cout << "Tel No: " << telNo << endl;
        cout << "Order Complete Time: " << *orderCompleteTime << endl;
        cout << "Order No: " << *orderNo << endl;
    }
};

int admin = -1;
bool menu = true;

void mainMenu();
void SystemLogin();
void userLogin();

User *userList[100];

void User::signUp(){
    fstream dosya("users.txt", ios::app);

    string name, nickname, telNo, mail, adress, pass, saleCoupon, bDate;

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

    try{
        userList[userCount] = new User(name, telNo, nickname, mail, adress, pass, saleCoupon, bDate);
        cout << "Kayıt Başarılı! ---> Lütfen Giriş Yapınız! " << endl;
        cout << endl;
    }
    catch(exception &e){
        cout << "Kayıt başarısız! "<< endl;
        mainMenu();
    }

    if (dosya.is_open()){
        dosya << nickname + pass << endl;
        dosya.close();
    }
    else{
        cout << "Dosya açılamadı!" << endl;
    }
}

void adminLogin(){
    cout << "Lütfen Admin Şifresini Giriniz: " << endl;
    cout << endl;

    string pass;

    cout << "Admin Şifre: "; getline(cin >> ws, pass);
    cout << endl;

    if (pass == "admin")
        cout << "Şifre Doğru! Admin Olarak Giriş Yapılıyor..."<< endl;
        cout << endl;
        admin = 1;
        mainMenu();

}

void userLogin(){
    cout << "Lütfen Giriş Yapınız! " << endl;
    cout << endl;
    string nickname, pass, passCheck, line, candidate;
    cout << "Kullanıcı Adınız: " ; getline(cin >> ws, nickname);
    cout << "Şifrenizi Giriniz: "; getline(cin >> ws, pass);
    cout << endl;

    passCheck = (nickname+pass);

    fstream dosya("users.txt", ios::in);

    bool tf = false;

    if(dosya.is_open()){
        while(!dosya.eof()){
            getline(dosya, line);
            int offset;
            if ((offset = line.find(passCheck, 0)) != string::npos){
                cout << "Bilgiler Doğru! Giriş Yapılıyor... " << endl;
                cout << endl;
                admin = 0;
                tf = true;
            }
        }
    }

    if(!tf){
        cout << "Bilgileriniz Yanlış! Lütfen Tekrar Deneyiniz. " << endl;
        cout << endl;
        userLogin();
    }

    if (tf) {
        mainMenu();
    }
}

void SystemLogin(){
    int c;
    cout << "1. Yönetici Girişi " << endl;
    cout << "2. Müşteri Girişi " << endl;
    cout << "3. Ana Menüye Geri Dön " << endl;
    
    try
    {
        if(!(cin >> c)){
        throw 505;
        } 
    }
    catch(int hata)
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

    switch (c){
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
            mainMenu();
            break;
        default:
            cout << "Hatalı Giriş!" << endl;
            SystemLogin();
            break;
    }
}


void mainMenu(){

    int choice;
    bool r = true;

    switch (admin)
    {
    case -1:
        cout << "1. Sisteme Giriş" << endl;
        cout << "2. Üye Kaydı" << endl;
        cout << "3. Çıkış" << endl;

        try
        {
            if(!(cin >> choice)){
                throw 505;
            } 
        }
        catch(int hata)
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
                cout << "---Sisteme Giriş---" << endl;
                SystemLogin();
                break;
            case 2:
                cout << "---Üye Kaydı---" << endl;
                cout << endl;
                User::signUp();
                mainMenu();
                break;
            case 3:
                cout << "Çıkış yapılıyor..." << endl;
                menu = false;
                break;
            default:
                cout << "Hatalı seçim!" << endl;
                break;
        }
        break;
    case 0:
        cout << "1. Sipariş Ver " << endl;
        cout << "2. Siparişleri Görüntüle " << endl;
        cout << "3. Şikayet - Öneri (Geri Bildirimler) " << endl;
        cout << "4. Oturumu Kapat " << endl;
        cout << "5. Çıkış " << endl;
        
        try
        {
            if(!(cin >> choice)){
                throw 505;
            } 
        }
        catch(int hata)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Hatalı bir giriş yaptınız lütfen tekrar deneyin ! Hata kodu: " << hata << endl;
            cout << endl;
            cout << "1. Sipariş Ver " << endl;
            cout << "2. Siparişleri Görüntüle " << endl;
            cout << "3. Şikayet - Öneri (Geri Bildirimler) " << endl;
            cout << "4. Oturumu Kapat " << endl;
            cout << "5. Çıkış " << endl;
            cin >> choice;
        }

        switch (choice)
        {
            case 1:
                cout << "---Sipariş Ver---" << endl;
                break;
            case 2:
                cout << "---Siparişleri Görüntüle---" << endl;
                break;
            case 3:
                cout << "---Şikayet - Öneri (Geri Bildirimler)---" << endl;
                break;
            case 4:
                cout << "Oturum Kapatılıyor..." << endl;
                admin = -1;
                break;
            case 5:
                cout << "Çıkış yapılıyor..." << endl;
                menu = false;
                break;
            default:
                cout << "Hatalı seçim!" << endl;
                mainMenu();
                break;
        }
        break;
    case 1:
        cout << "1. Siparişleri Görüntüle / Düzenle " << endl;
        cout << "2. Ürünleri Görüntüle / Düzenle " << endl;
        cout << "3. Kuryeleri Düzenle " << endl;
        cout << "4. Şikayet - Öneri (Geri Bildirimler) " << endl;
        cout << "5. İndirim Kodu Tanımla " << endl;
        cout << "6. Oturumu Kapat " << endl;
        cout << "7. Çıkış " << endl;
        
        try
        {
            if(!(cin >> choice)){
                throw 505;
            } 
        }
        catch(int hata)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Hatalı bir giriş yaptınız lütfen tekrar deneyin ! Hata kodu: " << hata << endl;
            cout << endl;
            cout << "1. Siparişleri Görüntüle / Düzenle " << endl;
            cout << "2. Ürünleri Görüntüle / Düzenle " << endl;
            cout << "3. Kuryeleri Düzenle " << endl;
            cout << "4. Şikayet - Öneri (Geri Bildirimler) " << endl;
            cout << "5. İndirim Kodu Tanımla " << endl;
            cout << "6. Oturumu Kapat " << endl;
            cout << "7. Çıkış " << endl;
            cin >> choice;
        }
        
        switch (choice)
        {
        case 1:
            cout << "---Siparişler---" << endl;
            break;
        case 2:
            cout << "---Ürünler---" << endl;
            break;
        case 3:
            cout << "---Kuryeler---" << endl;
            break;
        case 4:
            cout << "---Geri Bildirimler---" << endl;
            break;
        case 5:
            cout << "---İndirim Kodları---" << endl;
            break;
        case 6:
            cout << "Oturum Kapatılıyor..." << endl;
            admin = -1;
            break;
        case 7:
            cout << "Çıkış Yapılıyor..." << endl;
            menu = false;
            break;
        default:
            cout << "Hatalı Seçim! " << endl;
            mainMenu();
            break;
        }
    default:
        admin = -1;
        mainMenu();
        break;
    }
    
}

int main(){
    
    while (menu)
    {
        mainMenu();
    }
    
    return 0;
}
