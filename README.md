# OOP-Project
OOP Fall Project for Object Orianted Programming lessons

https://docs.google.com/document/d/1MdFfRV5glprAS4ROJQG3qC3l0QckXh4bcZvpPXSZzqU/edit

Project summary (What the program has to have)
- [ ] Log in screen with registration(admin login and member login is in another screen with divided selections)
- [ ] Login info is provided by users.txt file(both admins and members)
- [ ] Admin privileges: System log file editor for clothes( can’t edit the categories), Courier edit menu,Complaint and suggestions showing up, Discount coupons given to members, Receipt showing up for the previous and current sales.
- [ ] Member privileges: Cloth categories showing up and selecting clothes,  Info about the courier, Feedback pop-up ( complaint and suggestions), change password, turn back(page wise).
- [ ] Clothes: dress, jeans, t-shirt, shirt , skirt, shoes.
- [ ] In product select, member should be able to do multiple selections.
- [ ] Clothes should have more options ( size wise and color wise )
- [ ] After the shopping, system is gonna create a detailed receipt.(name of  client, order price, order time, order info.)
- [ ] Order tracking system is gonna inform the member about order info and order estimated delivery time. What it should show up is ; Courier number, Order number, Destination, Order time, estimated time, process time.
- [ ] Estimated delivery time is gonna calculate the left time by defined order of cities and defined time that couriers gonna deliver. In order tracking screen of members, the order time is gonna add up to the amount of time courier is gonna deliver, then it should show up the time clock wise.
- [ ] Courier thing is fucked up 
- [ ] Feedback from clients( complaints and suggestions ) are gonna stored up in a suggestions.txt file. Readable by admin privileges
- [ ] Change password is change password
- [ ] Turn back is gonna make the user go up in menu
- [ ] Registration menu is gonna get the info from client, and save the info in users.txt, gonna verify the email, verify the birth date’s order(if it is proper or not), while entering the password for log in; password’s gonna show up as *. The password’s reliability is gonna be tested by program and if it’s not reliable, system is not gonna accept the password.
- [ ] The math on the objects created by time class is gonna be produced by operator overload.
- [ ] Time class has the attributes: int hour, int minute
- [ ] Clothe class has the attributes ; Char category,Int cloth_name, Double price, Char size, Char color
- [ ] Person class has the attributes ; char name_surname, char telno 
- [ ] Classes named admin, courier, user is gonna inherit person class; while order class inherits cloth class.
- [ ] Admin class has the attribute char password
- [ ] Courier class has the attribute time::order_finish and int order_no
- [ ] User class has the attributes: char username, char email, char address, char password, char discount_code, char birthdate.
- [ ] Order class has the attributes : int order_no , double order_price, time::order_start, time::order_finish
- [ ] 

