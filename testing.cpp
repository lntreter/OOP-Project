#include <iostream>
#include <string>

using namespace std;

//for courier
int hour;
int minute;
char orderStart;
char orderEnd;
//for clothings
char category;
int cloth_name;
double price;
char size;
char color;
//for client
char name_surname;
char telephone_number;
//for admin
char adminPassword;
//for user
char username;
char email;
char address;
char password;
char discount_code;
char birthdate;
//for order tracking
int orderNo;
double orderPrice;


//setter classes
class Products
{
    public:
    class Dress
    {   private:
            void addDress(int dressName)
            {
                cloth_name = dressName;
            }
            void delDress();
            void editDress();
            void viewDress();
        public:
            void selectColor(char dressColor)
            {
                color = dressColor;
            }
            void selectSize(char dressSize)
            {
                size = dressSize;
            }
    };
    class Shoes
    {   private:
            void addShoes(shoesName)
            {
                cloth_name = shoesName;
            }
            void delShoes();
            void editShoes();
            void viewShoes();
        public:
            void selectColor(shoeColor)
            {
                color = shoeColor;
            }
            void selectSize(shoeSize)
            {
                size = shoeSize;
            }
    };
    class Jeans
    {   private:
            void addJeans(jeansName)
            {
                cloth_name = jeansName
            }
            void delJeans();
            void editJeans();
            void viewJeans();
        public:
            void selectColor(jeansColor)
            {
                color = jeansColor;
            }
            void selectSize(jeansSize)
            {
                size = jeansSize;
            }
    };
    class TShirts
    {   private:
            void addTShirts(tshirtName)
            {
                cloth_name = tshirtName;
            }
            void delTShirts();
            void editTShirts();
            void viewTShirts();
        public:
            void selectColor(tshirtColor)
            {
                color = tshirtColor;
            }
            void selectSize(tshirtSize)
            {
                size = tshirtSize;
            }
    };
    class Shirts
    {   private:
            void addShirts(shirtName)
            {
                cloth_name = shirtName;
            }
            void delShirts();
            void editShirts();
            void viewShirts();
        public:
            void selectColor(shirtColor)
            {
                color = shirtColor;
            }
            void selectSize(shirtSize)
            {
                size = shirtSize;
            }
    };
    class Skirts
    {   private:
            void addSkirts(skirtName)
            {
                cloth_name = skirtName;
            }
            void delSkirts();
            void editSkirts();
            void viewSkirts();
        public:
            void selectColor(skirtColor)
            {
                color = skirtColor;
            }
            void selectSize(skirtSize)
            {
                size = skirtSize;
            }
    };
};
class Admin : Products
{  private:
    void addProduct();
    void delProduct();
    void editCourier();
    void showSuggetionsComplaints();
    void showReceipts();
    void editCoupons();
    void editProduct();
    void viewAdminInfo();
};
class Member
{
    private:
    void orderProduct();
    void disorderProduct();
    void viewCourier();
    void sendSuggetionsComplaints();
    void showReceipts();
    void showCoupons();
    void editOrder();
    void viewUserInfo();
};
