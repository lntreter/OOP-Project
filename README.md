# OOP-Project
OOP Fall Project for Object Orianted Programming lessons

https://docs.google.com/document/d/1MdFfRV5glprAS4ROJQG3qC3l0QckXh4bcZvpPXSZzqU/edit

Project summary (What the program has to have)
- [x] Log in screen with registration(admin login and member login is in another screen with divided selections)
- [x] Login info is provided by users.txt file(both admins and members)
- [x] Admin privileges: System log file editor for clothes( can’t edit the categories), Courier edit menu,Complaint and suggestions showing up, Discount coupons given to members, Receipt showing up for the previous and current sales.
- [x] Member privileges: Cloth categories showing up and selecting clothes,  Info about the courier, Feedback pop-up ( complaint and suggestions), change password, turn back(page wise).
- [x] Clothes: dress, jeans, t-shirt, shirt , skirt, shoes.
- [ ] In product select, member should be able to do multiple selections.
- [x] Clothes should have more options ( size wise and color wise )
- [x] After the shopping, system is gonna create a detailed receipt.(name of  client, order price, order time, order info.)
- [x] Order tracking system is gonna inform the member about order info and order estimated delivery time. What it should show up is ; Courier number, Order number, Destination, Order time, estimated time, process time.
- [x] Estimated delivery time is gonna calculate the left time by defined order of cities and defined time that couriers gonna deliver. In order tracking screen of members, the order time is gonna add up to the amount of time courier is gonna deliver, then it should show up the time clock wise.
- [x] Courier thing is fucked up 
- [ ] Feedback from clients( complaints and suggestions ) are gonna stored up in a suggestions.txt file. Readable by admin privileges
- [ ] Change password is change password
- [x] Turn back is gonna make the user go up in menu
- [ ] Registration menu is gonna get the info from client, and save the info in users.txt, gonna verify the email, verify the birth date’s order(if it is proper or not), while entering the password for log in; password’s gonna show up as *. The password’s reliability is gonna be tested by program and if it’s not reliable, system is not gonna accept the password.
- [x] The math on the objects created by time class is gonna be produced by operator overload.
- [x] Time class has the attributes: int hour, int minute
- [x] Clothe class has the attributes ; Char category,Int cloth_name, Double price, Char size, Char color
- [x] Person class has the attributes ; char name_surname, char telno 
- [x] Classes named admin, courier, user is gonna inherit person class; while order class inherits cloth class.
- [x] Admin class has the attribute char password
- [x] Courier class has the attribute time::order_finish and int order_no
- [x] User class has the attributes: char username, char email, char address, char password, char discount_code, char birthdate.
- [x] Order class has the attributes : int order_no , double order_price, time::order_start, time::order_finish
- [ ] 

