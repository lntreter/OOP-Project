#include<iostream>
#include<string>
#include<fstream>
#include<limits>
#include<conio.h>
#include<locale.h>

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
    static int clotheCount;
    static int listSize;
    public:
    Clothes(){}
    Clothes(string c, string n, double p, string s, string col){//Kurucu fonksiyon
        category = c;
        name = n;
        price = p;
        size = s;
        color = col;
        clotheCount++;
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
    static int getClotheCount(){
        return clotheCount;
    }
    static void addClothe(Clothes*,Clothes[]);
    static void delClothe(Clothes,Clothes[]);
    static void listClothes(Clothes[]);
    static void orderClotes(Clothes*);
    void Edit();
    void print(){
        cout << "Category: " << category << endl;
        cout << "Name: " << name << endl;
        cout << "Price: " << price << "TL"<< endl;
        cout << "Size: " << size << endl;
        cout << "Color: " << color << endl;
        cout << "-----------------------" << endl;
    }
};

int Clothes::clotheCount = 0;
int Clothes::listSize = 500;
Clothes clothesList[500];//Kıyafetlerin tutulduğu liste

void Clothes::orderClotes(Clothes* list){//Sipariş verme fonksiyonu
    for (int i = 1; i <= clotheCount; i++)
    {
        list[i].print();//Kıyafetleri listeler
        cout << "Satin almak icin " << i << " tusuna basiniz." << endl<<endl;
    }
    
}

void Clothes::listClothes(Clothes list[]){//Kıyafetleri listeler
    for(int i = 1; i <= clotheCount; i++){
        list[i].print();
    }
}

void Clothes::addClothe(Clothes *c,Clothes list[]){//Kıyafet ekler
    if(clotheCount < listSize){//Stok dolu değilse
        list[clotheCount] = *c;//Kıyafetleri listeye ekler
    }
    else{
        cout << "Stok Dolu!"<< endl;//Stok doluysa
    }
}
void Clothes::delClothe(Clothes c,Clothes list[]){//Kıyafet siler
    Clothes *tmp = new Clothes[clotheCount];//Geçici bir liste oluşturur

    for(int i = 1; i <= clotheCount; i++){//Kıyafetleri gezer
        
        if(list[i].getName() == c.getName()){//Eğer silinecek kıyafet bulunursa
            
            list[clotheCount+1]=list[i];//Son kıyafet silinecek kıyafetin yerine konur
            
            for (int k = i; k < clotheCount; k++)//Silinen kıyafetin yerine gelen kıyafetlerin yerini değiştirir
            {
                list[i] = list[i+1];//Kıyafetlerin yerini değiştirir
            }
            clotheCount--;
        }
        if(!(i > clotheCount))//Eğer silinen kıyafet yoksa
            
            tmp[i] = list[i];//Geçici listeye kıyafetleri ekler
    }
    list = tmp;//Geçici listeyi ana listeye atar
}

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
    static void addPerson(Person *p, Person *list){//Person ekleme fonksiyonu
        if(personCount < listSize){//Liste dolu değilse
            list[personCount] = *p;//Personu listeye ekler
        }
        else{
            cout << "List is full!" << endl;
        }
    }
    static void del(Person p, Person *list){//düzenlenicek
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
    static void printList(Person *list){//Personları listeler
        for(int i = 0; i < personCount; i++){
            list[i].print();
        }
        cout << endl;
    }
};

int Person::personCount = 0;
int Person::listSize = 1000;

class order : Clothes{
    private:
    int orderNo;
    double orderPrice;
    Time orderTime;
    Time deliveryTime;
    static int orderCount;
    static int listSize;
    public:
    order(){};
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
        cout << "Order Price: " << orderPrice<<"TL" << endl;
        cout << "Order Time: " << orderTime << endl;
        cout << "Delivery Time: " << deliveryTime << endl;
        Clothes::print();
    }
    int orderDeliveryTime(){
        return deliveryTime.getHour() - orderTime.getHour();
    }
    static void addOrder(order *o, order list[]){//Sipariş ekleme fonksiyonu
        
        if(orderCount < listSize){//Liste dolu değilse
            list[orderCount] = *o;//Siparişi listeye ekler
            clotheCount--;//Kıyafet sayısını azaltır
            delClothe(*o,clothesList);//Kıyafeti siler
        }
        else{
            cout << "Sepet Dolu!" << endl;
        }
    }
    static void delOrder(order o, order *list){//Sipariş silme fonksiyonu
        for(int i = 1; i <= orderCount; i++){//Sipariş sayısı kadar döner
            if(list[i].getOrderNo() == o.getOrderNo()){//Sipariş numarası eşitse
                for(int j = i; j <= orderCount; j++){//Sipariş sayısı kadar döner
                    list[j] = list[j+1];//Siparişi siler
                }
                orderCount--;//Sipariş sayısını azaltır
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
        for(int i = 1; i <= orderCount; i++){
            list[i].print();
        }
        cout << endl;
    }
};

int order::orderCount = 0;
int order::listSize = 100;
order orderList[100];//Sipariş listesi

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

int admin = -1;//Admin girişi kontrolü
bool menu = true;//Menü kontrolü

void mainMenu();
void SystemLogin();
void userLogin();
void orders();
User *userList[100];//Kullanıcı listesi


// void orders(){
//     int orderNo;
//     double orderPrice;
//     Time orderTime;
//     Time deliveryTime;
//     Clothes *c = new Clothes();
//     order *o = new order();
//     order *orderList[100];
//     int choice;
//     while(menu){
//         cout << "1. Add Order" << endl;
//         cout << "2. Delete Order" << endl;
//         cout << "3. Update Order" << endl;
//         cout << "4. Print Order List" << endl;
//         cout << "5. Exit" << endl;
//         cout << "Choice: ";
//         cin >> choice;
//         switch(choice){
//             case 1:
//                 cout << "Order No: ";
//                 cin >> orderNo;
//                 o->setOrderNo(orderNo);
//                 cout << "Order Price: ";
//                 cin >> orderPrice;
//                 o->setOrderPrice(orderPrice);
//                 cout << "Order Time: ";
//                 cin >> orderTime;
//                 o->setOrderTime(orderTime);
//                 cout << "Delivery Time: ";
//                 cin >> deliveryTime;
//                 o->setDeliveryTime(deliveryTime);
//                 c->input();
//                 o->setClothes(c);
//                 order::addOrder(o, orderList);
//                 break;
//             case 2:
//                 cout << "Order No: ";
//                 cin >> orderNo;
//                 o->setOrderNo(orderNo);
//                 order::delOrder(*o, orderList);
//                 break;
//             case 3:
//                 cout << "Order No: ";
//                 cin >> orderNo;
//                 o->setOrderNo(orderNo);
//                 cout << "Order Price: ";
//                 cin >> orderPrice;
//                 o->setOrderPrice(orderPrice);
//                 cout << "Order Time: ";
//                 cin >> orderTime;
//                 o->setOrderTime(orderTime);
//                 cout << "Delivery Time: ";
//                 cin >> deliveryTime;
//                 o->setDeliveryTime(deliveryTime);
//                 c->input();
//                 o->setClothes(c);
//                 order::updateOrder(*o, orderList);
//                 break;
//             case 4:
//                 order::printList(orderList);
//                 break;
//             case 5:
//                 menu = false;
//                 break;
//             default:
//                 cout << "Wrong choice!" << endl;
//                 break;
//         }
//     }
// }

int orderNo = 0;//Sipariş numarası

void giveOrder(){//Sipariş verme
    Time orderTime;//Sipariş zamanı
    Time deliveryTime;//Teslimat zamanı
    int opt;//Seçenek

    Clothes::orderClotes(clothesList);//Kıyafetleri listeleme
    cout << "Geri dönmek için 0 tuşuna basın. "<<endl;
    try                  //Hata yakalama
    {
        if(!(cin >> opt)){   //Hata kontrolü
            throw 606;
        } 
    }
    catch(int hata)
    {
        cin.clear();  //Hata durumunda cin'i temizle
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Hata durumunda cin'i temizle
        cerr << "Hatalı bir giriş yaptınız lütfen tekrar deneyin ! Hata kodu: " << hata << endl; //Hata mesajı
        cout << endl; //Boşluk
        cout << "Geri dönmek için 0 tuşuna basın. "<<endl; //Kullanıcıya bilgi ver
        cin >> opt;
    }
    for (int i = 1; i <= Clothes::getClotheCount(); i++) //Kıyafet sayısı kadar döngü
    {
        if (opt == i)
        {
            order::addOrder(new order(++orderNo, clothesList[i].getPrice(), orderTime, deliveryTime, //Sipariş ekleme
                clothesList[i].getCategory(), clothesList[i].getName(),
                    clothesList[i].getPrice(), clothesList[i].getSize(), clothesList[i].getColor()), orderList);
            cout << "Siparişiniz başarıyla alındı! "<< endl<<endl;
            break;
        }else if(opt == 0){//Geri dönmek için 0 tuşuna basın.
            break;
            mainMenu();
        }
    }    
}

void products(){
    string category;
    string name;
    double price;
    string size;
    string color;
    string named;
    int i =1;

    int sec;

    cout << "1. Ürün Ekle "<< endl;
    cout << "2. Ürün Sil "<< endl;
    cout << "3. Ürün Listele "<< endl;
    cout << "4. Geri Dön "<< endl;

    try{
        if(!(cin >> sec)){
            throw 505;
        }
    }
    catch(int hata){
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Hatalı bir giriş yaptınız lütfen tekrar deneyin ! Hata kodu: " << hata << endl;
        cout << endl;
        cout << "1. Ürün Ekle "<< endl;
        cout << "2. Ürün Sil "<< endl;
        cout << "3. Ürünleri Listele "<< endl;
        cout << "4. Geri Dön "<< endl;
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
        cout << "Ürün başarıyla eklendi!"<<endl<<endl;
        products();
        break;
    case 2:
        cout << "---Ürün Silme Ekranı---" << endl<<endl;
        cout << "Silmek istediğiniz ürünün adını giriniz: " << endl;
                    getline(cin>>ws,named);
        do{
            if (named == clothesList[i].getName()) //Kıyafet adı girilen kıyafet adı ile aynı ise
            {
                Clothes::delClothe(clothesList[i], clothesList); //Kıyafet sil
                cout << "Ürün başarıyla silindi." << endl;
                i=1;
                break;
            }
            i++;
            
        }while(i <= Clothes::getClotheCount());  //Kıyafet sayısı kadar döngü

        if(i> Clothes::getClotheCount() && i != 1) //Kıyafet sayısı kadar döngü döndüyse ve ürün bulunamadıysa
        {
            cout<<"Ürün Bulunamadı"<<endl; //Ürün bulunamadı mesajı
            i=1;
        }
        break;
    case 3:
        cout << "---Ürün Listeleme Ekranı---" << endl<<endl;
        Clothes::listClothes(clothesList); //Kıyafetleri listele

        cout << "Devam etmek için bir tuşa basın. "<< endl; //Kullanıcıya bilgi ver
        
        getch(); //Kullanıcıdan bir tuşa basmasını bekler
        cout << endl;
        break;
    case 4:
        cout << endl;
        mainMenu();
        break;
    default:
        cout << "Hatalı bir giriş yaptınız lütfen tekrar deneyin !" << endl;
        products();
        break;
    }
}

void User::signUp(){
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

    try{
        userList[userCount] = new User(name, telNo, nickname, mail, adress, pass, saleCoupon, bDate);
        cout << "Kayıt Başarılı! ---> Lütfen Giriş Yapınız! " << endl;
        cout << endl;

    }  //Hata yakalarsa

    catch(exception &e){
        cout << "Kayıt başarısız! "<< endl;
        mainMenu();
    }

    if (dosya.is_open()){ //Dosya açıldıysa
        dosya << nickname + pass << endl;   //Kullanıcı adı ve şifreyi dosyaya yaz
        dosya.close(); //Dosyayı kapat
    }
    else{
        cout << "Dosya açılamadı!" << endl;
    }
}

void adminLogin(){
    cout << "Lütfen Admin Şifresini Giriniz: " << endl;
    cout << endl;

    //Admin şifresini al

    string pass;

    cout << "Admin Şifre: "; getline(cin >> ws, pass);
    cout << endl;

    if (pass == "admin")
    {
        cout << "Şifre Doğru! Admin Olarak Giriş Yapılıyor..."<< endl;
        cout << endl;
        admin = 1;
        mainMenu();
    }else{
        cout << "Şifre Yanlış! " << endl;
        cout << endl;
        mainMenu();
    }
}

void userLogin(){

    //Kullanıcı adı ve şifreyi al

    cout << "Lütfen Giriş Yapınız! " << endl;
    cout << endl;
    string nickname, pass, passCheck, line, candidate;
    cout << "Kullanıcı Adınız: " ; getline(cin >> ws, nickname);
    cout << "Şifrenizi Giriniz: "; getline(cin >> ws, pass);
    cout << endl;

    passCheck = (nickname+pass);

    fstream dosya("users.txt", ios::in); //Kullanıcı bilgilerini oku

    bool tf = false; //Kullanıcı bilgileri doğruysa true

    if(dosya.is_open()){ //Dosya açıldıysa

        while(!dosya.eof()){ //Dosya sonuna gelene kadar

            getline(dosya, line); //Dosyadan satır satır oku

            int offset; //Satırda aranan kelimenin bulunduğu konumu tutar

            //Satırda aranan kelime varsa
            if ((offset = line.find(passCheck, 0)) != string::npos){
                cout << "Bilgiler Doğru! Giriş Yapılıyor... " << endl;
                cout << endl;
                admin = 0;
                tf = true;
            }
        }
    }

    //Kullanıcı bilgileri yanlışsa
    if(!tf){
        cout << "Bilgileriniz Yanlış! Lütfen Tekrar Deneyiniz. " << endl;
        cout << endl;
        userLogin();
    }

    //Kullanıcı bilgileri doğruysa
    if (tf) {
        mainMenu();
    }
}

void SystemLogin(){
    
    //Sistem giriş menüsü
    int c;
    cout << "1. Yönetici Girişi " << endl;
    cout << "2. Müşteri Girişi " << endl;
    cout << "3. Ana Menüye Geri Dön " << endl;
    
    //Hata yakalama
    try
    {
        if(!(cin >> c)){
        throw 505;
        } 
    }
    //Hata yakalandıysa
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

    //Seçim yap
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

    //Ana menü
    int choice; //Seçim yapmak için
    bool r = true; //Döngüyü kontrol eder
    int opt; //Seçim yapmak için

    switch (admin) //Admin değilse
    {
    case -1:
        cout << "1. Sisteme Giriş" << endl;
        cout << "2. Üye Kaydı" << endl;
        cout << "3. Çıkış" << endl;

        //Hata yakalama
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
                User::signUp(); //Üye kaydı
                mainMenu();
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
        cout << "5. Çıkış " << endl;
        
        //Hata yakalama
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
                cout << "---Sipariş Ver---" << endl<<endl;
                giveOrder(); //Sipariş ver
                cout << endl;
                break;
            case 2:
                cout << "---Siparişleri Görüntüle---" << endl<<endl;

                order::printList(orderList); //Siparişleri görüntüle

                cout << "Devam etmek için bir tuşa basın... "<<endl;
                getch(); //Devam etmek için bir tuşa bas
                cout << endl;
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
            cout << "---Ürünler---" << endl;
            cout << endl;
            products(); //Ürünleri görüntüle
            cout << endl;
            break;
        case 2:
            cout << "---Kuryeler---" << endl;
            break;
        case 3:
            cout << "---Geri Bildirimler---" << endl;
            break;
        case 4:
            cout << "---İndirim Kodları---" << endl;
            break;
        case 5:
            cout << "Oturum Kapatılıyor..." << endl;
            admin = -1; //Oturumu kapat
            break;
        case 6:
            cout << "Çıkış Yapılıyor..." << endl;
            menu = false; //Ana menüden çık
            break;
        default:
            cout << "Hatalı Seçim! " << endl;
            mainMenu();
            break;
        }
    default:
        cout << endl;
        mainMenu();
        break;
    }   
}

int main(){
    setlocale(LC_ALL, "Turkish");
    while (menu) 
    {
        mainMenu();
    }
    return 0;
}
