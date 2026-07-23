create database online_store;
use online_store;



CREATE TABLE Address (
    Address_ID INT PRIMARY KEY,
    House_no VARCHAR(10),
    Street_Address VARCHAR(100),
    Area_Block VARCHAR(50),
    Apartment_no VARCHAR(10),
    City VARCHAR(50),
    Postal_Code VARCHAR(10)
);

CREATE TABLE User (
    User_ID INT PRIMARY KEY,
    First_Name VARCHAR(50),
    Last_Name VARCHAR(50),
    Email VARCHAR(100) UNIQUE,
    Password VARCHAR(100),
    Account_Status VARCHAR(20),
    Last_Visit_Date DATE,
    Address_ID INT,
    FOREIGN KEY (Address_ID) REFERENCES Address(Address_ID)
);

CREATE TABLE Category (
    Category_ID INT PRIMARY KEY,
    Category_Name VARCHAR(50),
    Description VARCHAR(100)
);

CREATE TABLE Warehouse (
    Warehouse_ID INT PRIMARY KEY,
    Manager_Name VARCHAR(100),
    Location VARCHAR(100),
    City VARCHAR(50)
);

CREATE TABLE Product (
    Product_ID INT PRIMARY KEY,
    Product_Name VARCHAR(100),
    Product_Description VARCHAR(200),
    Brand_Name VARCHAR(50),
    Price DECIMAL(10,2),
    Unit VARCHAR(20),
    Stock_Quantity INT,
    Product_IMG_url VARCHAR(200),
    Category_ID INT,
    Warehouse_ID INT,
    FOREIGN KEY (Category_ID) REFERENCES Category(Category_ID),
    FOREIGN KEY (Warehouse_ID) REFERENCES Warehouse(Warehouse_ID)
);

CREATE TABLE Orders (
    Order_ID INT PRIMARY KEY,
    Order_Date DATE,
    Delivery_Address VARCHAR(200),
    City VARCHAR(50),
    Total_Amount DECIMAL(10,2),
    Order_Status VARCHAR(20),
    Payment_Status VARCHAR(20),
    Expected_Delivery_Time VARCHAR(50),
    User_ID INT,
    FOREIGN KEY (User_ID) REFERENCES User(User_ID)
);

CREATE TABLE Payment (
    Payment_ID INT PRIMARY KEY,
    Payment_Method VARCHAR(50),
    Amount_Paid DECIMAL(10,2),
    Transaction_Date DATE,
    Order_ID INT,
    FOREIGN KEY (Order_ID) REFERENCES Orders(Order_ID)
);

CREATE TABLE Order_Details (
    Order_Details_ID INT PRIMARY KEY,
    Quantity INT,
    Price_at_Purchase DECIMAL(10,2),
    Order_ID INT,
    Product_ID INT,
    FOREIGN KEY (Order_ID) REFERENCES Orders(Order_ID),
    FOREIGN KEY (Product_ID) REFERENCES Product(Product_ID)
);





INSERT INTO Address VALUES
(1,'12','Street 1','A','-','Lahore','54000'),
(2,'45','Street 2','B','-','Karachi','74000'),
(3,'78','Street 3','C','-','Islamabad','44000'),
(4,'23','Street 4','D','-','Lahore','54001'),
(5,'67','Street 5','E','-','Karachi','74001'),
(6,'89','Street 6','F','-','Islamabad','44001'),
(7,'34','Street 7','G','-','Lahore','54002'),
(8,'56','Street 8','H','-','Karachi','74002'),
(9,'91','Street 9','I','-','Islamabad','44002'),
(10,'11','Street 10','J','-','Lahore','54003'),
(11,'22','Street 11','K','-','Karachi','74003'),
(12,'33','Street 12','L','-','Islamabad','44003'),
(13,'44','Street 13','M','-','Lahore','54004'),
(14,'55','Street 14','N','-','Karachi','74004'),
(15,'66','Street 15','O','-','Islamabad','44004'),
(16,'77','Street 16','P','-','Lahore','54005'),
(17,'88','Street 17','Q','-','Karachi','74005'),
(18,'99','Street 18','R','-','Islamabad','44005'),
(19,'100','Street 19','S','-','Lahore','54006'),
(20,'101','Street 20','T','-','Karachi','74006');
select * from Address;




INSERT INTO User VALUES
(1,'Hussain','Durrani','h1@gmail.com','123','Active','2026-04-01',1),
(2,'Ali','Hamza','h2@gmail.com','123','Active','2026-04-02',2),
(3,'Ahmed','Raza','h3@gmail.com','123','Active','2026-04-03',3),
(4,'Usman','Khan','h4@gmail.com','123','Active','2026-04-04',4),
(5,'Bilal','Sheikh','h5@gmail.com','123','Inactive','2026-04-05',5),
(6,'Zain','Malik','h6@gmail.com','123','Active','2026-04-06',6),
(7,'Saad','Qureshi','h7@gmail.com','123','Active','2026-04-07',7),
(8,'Farhan','Ali','h8@gmail.com','123','Active','2026-04-08',8),
(9,'Imran','Butt','h9@gmail.com','123','Inactive','2026-04-09',9),
(10,'Tariq','Mehmood','h10@gmail.com','123','Active','2026-04-10',10),
(11,'Ayesha','Khan','h11@gmail.com','123','Active','2026-04-11',11),
(12,'Fatima','Noor','h12@gmail.com','123','Active','2026-04-12',12),
(13,'Zara','Ahmed','h13@gmail.com','123','Active','2026-04-13',13),
(14,'Hina','Rashid','h14@gmail.com','123','Inactive','2026-04-14',14),
(15,'Maryam','Iqbal','h15@gmail.com','123','Active','2026-04-15',15),
(16,'Sana','Javed','h16@gmail.com','123','Active','2026-04-16',16),
(17,'Rabia','Shah','h17@gmail.com','123','Active','2026-04-17',17),
(18,'Nida','Hassan','h18@gmail.com','123','Active','2026-04-18',18),
(19,'Mehwish','Akram','h19@gmail.com','123','Inactive','2026-04-19',19),
(20,'Kiran','Aslam','h20@gmail.com','123','Active','2026-04-20',20);
select * from User;




INSERT INTO Category VALUES
(1,'Beverages','Drinks'),
(2,'Dairy','Milk products'),
(3,'Snacks','Chips & biscuits'),
(4,'Staples','Rice & flour'),
(5,'Frozen','Frozen food'),
(6,'Fruits','Fresh fruits'),
(7,'Vegetables','Fresh vegetables'),
(8,'Bakery','Bread items'),
(9,'Personal Care','Hygiene'),
(10,'Health','Supplements'),
(11,'Baby','Baby care'),
(12,'Cleaning','Household'),
(13,'Electronics','Devices'),
(14,'Men Fashion','Clothes'),
(15,'Women Fashion','Clothes'),
(16,'Kids','Kids wear'),
(17,'Home','Furniture'),
(18,'Kitchen','Appliances'),
(19,'Stationery','Office items'),
(20,'Books','Reading');
select * from Category;




INSERT INTO Warehouse VALUES
(1,'Ali Khan','Johar Town','Lahore'),
(2,'Ahmed Raza','Gulshan','Karachi'),
(3,'Usman Tariq','F-10','Islamabad'),
(4,'Bilal Khan','Model Town','Lahore'),
(5,'Zain Ali','Clifton','Karachi'),
(6,'Saad Ahmed','G-11','Islamabad'),
(7,'Farhan Malik','DHA','Lahore'),
(8,'Imran Butt','North Nazimabad','Karachi'),
(9,'Tariq Mehmood','F-11','Islamabad'),
(10,'Hassan Raza','Cantt','Lahore'),
(11,'Adeel Khan','Malir','Karachi'),
(12,'Omar Sheikh','G-13','Islamabad'),
(13,'Noman Ali','Township','Lahore'),
(14,'Shahid Khan','Korangi','Karachi'),
(15,'Kamran Raza','I-8','Islamabad'),
(16,'Junaid Malik','Bahria','Lahore'),
(17,'Waqar Ahmed','Defence','Karachi'),
(18,'Asad Ali','F-6','Islamabad'),
(19,'Sohail Khan','Garden Town','Lahore'),
(20,'Fahad Raza','PECHS','Karachi');
select * from Warehouse;



INSERT INTO Product VALUES
(1,'Milk','Fresh Milk','Nestle',220,'Litre',50,'img1',2,1),
(2,'Bread','Brown Bread','Dawn',120,'Piece',40,'img2',8,2),
(3,'Rice','Basmati','Guard',300,'Kg',60,'img3',4,3),
(4,'Juice','Mango Juice','Nestle',180,'Litre',70,'img4',1,4),
(5,'Eggs','Farm Eggs','Local',250,'Dozen',80,'img5',2,5),
(6,'Chips','Potato Chips','Lays',100,'Pack',90,'img6',3,6),
(7,'Apple','Fresh Apple','Local',200,'Kg',30,'img7',6,7),
(8,'Soap','Beauty Soap','Lux',90,'Piece',100,'img8',9,8),
(9,'Shampoo','Hair Care','Sunsilk',350,'Bottle',40,'img9',9,9),
(10,'Chicken','Fresh Chicken','Local',500,'Kg',25,'img10',7,10),
(11,'Flour','Wheat Flour','Ashraf',150,'Kg',80,'img11',4,11),
(12,'Ice Cream','Vanilla','Walls',400,'Tub',35,'img12',5,12),
(13,'Butter','Salted','Nurpur',250,'Pack',45,'img13',2,13),
(14,'Banana','Fresh Banana','Local',120,'Dozen',50,'img14',6,14),
(15,'Detergent','Washing Powder','Surf',500,'Kg',60,'img15',12,15),
(16,'Laptop','Basic Laptop','Dell',80000,'Piece',10,'img16',13,16),
(17,'Shirt','Men Shirt','Outfitters',2000,'Piece',25,'img17',14,17),
(18,'Dress','Women Dress','Khaadi',3500,'Piece',20,'img18',15,18),
(19,'Notebook','School Notebook','Local',100,'Piece',70,'img19',19,19),
(20,'Book','Story Book','Oxford',600,'Piece',30,'img20',20,20);
select * from Product;



INSERT INTO Orders VALUES
(1,'2026-04-01','Addr1','Lahore',500,'Delivered','Paid','2 Days',1),
(2,'2026-04-02','Addr2','Karachi',800,'Pending','Unpaid','3 Days',2),
(3,'2026-04-03','Addr3','Islamabad',600,'Delivered','Paid','2 Days',3),
(4,'2026-04-04','Addr4','Lahore',700,'Pending','Paid','3 Days',4),
(5,'2026-04-05','Addr5','Karachi',900,'Delivered','Paid','2 Days',5),
(6,'2026-04-06','Addr6','Islamabad',400,'Pending','Unpaid','3 Days',6),
(7,'2026-04-07','Addr7','Lahore',550,'Delivered','Paid','2 Days',7),
(8,'2026-04-08','Addr8','Karachi',650,'Pending','Paid','3 Days',8),
(9,'2026-04-09','Addr9','Islamabad',750,'Delivered','Paid','2 Days',9),
(10,'2026-04-10','Addr10','Lahore',850,'Pending','Unpaid','3 Days',10),
(11,'2026-04-11','Addr11','Karachi',950,'Delivered','Paid','2 Days',11),
(12,'2026-04-12','Addr12','Islamabad',300,'Pending','Paid','3 Days',12),
(13,'2026-04-13','Addr13','Lahore',450,'Delivered','Paid','2 Days',13),
(14,'2026-04-14','Addr14','Karachi',550,'Pending','Unpaid','3 Days',14),
(15,'2026-04-15','Addr15','Islamabad',650,'Delivered','Paid','2 Days',15),
(16,'2026-04-16','Addr16','Lahore',750,'Pending','Paid','3 Days',16),
(17,'2026-04-17','Addr17','Karachi',850,'Delivered','Paid','2 Days',17),
(18,'2026-04-18','Addr18','Islamabad',950,'Pending','Unpaid','3 Days',18),
(19,'2026-04-19','Addr19','Lahore',500,'Delivered','Paid','2 Days',19),
(20,'2026-04-20','Addr20','Karachi',600,'Pending','Paid','3 Days',20);
select * from Orders;




INSERT INTO Payment VALUES
(1,'Cash',500,'2026-04-01',1),
(2,'Card',800,'2026-04-02',2),
(3,'Cash',600,'2026-04-03',3),
(4,'Card',700,'2026-04-04',4),
(5,'Cash',900,'2026-04-05',5),
(6,'Card',400,'2026-04-06',6),
(7,'Cash',550,'2026-04-07',7),
(8,'Card',650,'2026-04-08',8),
(9,'Cash',750,'2026-04-09',9),
(10,'Card',850,'2026-04-10',10),
(11,'Cash',950,'2026-04-11',11),
(12,'Card',300,'2026-04-12',12),
(13,'Cash',450,'2026-04-13',13),
(14,'Card',550,'2026-04-14',14),
(15,'Cash',650,'2026-04-15',15),
(16,'Card',750,'2026-04-16',16),
(17,'Cash',850,'2026-04-17',17),
(18,'Card',950,'2026-04-18',18),
(19,'Cash',500,'2026-04-19',19),
(20,'Card',600,'2026-04-20',20);
select * from Payment;




INSERT INTO Order_Details VALUES
(1,2,220,1,1),
(2,1,120,2,2),
(3,3,300,3,3),
(4,2,180,4,4),
(5,1,250,5,5),
(6,4,100,6,6),
(7,2,200,7,7),
(8,3,90,8,8),
(9,1,350,9,9),
(10,2,500,10,10),
(11,3,150,11,11),
(12,1,400,12,12),
(13,2,250,13,13),
(14,3,120,14,14),
(15,2,500,15,10),
(16,1,80000,16,16),
(17,2,2000,17,17),
(18,1,3500,18,18),
(19,5,100,19,19),
(20,2,600,20,20);
select * from Order_Details;





SELECT * FROM Product
WHERE Price > (SELECT AVG(Price) FROM Product);



SELECT First_Name FROM User
WHERE User_ID IN (SELECT User_ID FROM Orders WHERE City='Lahore');





SELECT City, COUNT(*) 
FROM Orders
GROUP BY City
HAVING COUNT(*) > 5;




SELECT U.First_Name, P.Product_Name, O.Order_ID
FROM User U
JOIN Orders O ON U.User_ID = O.User_ID
JOIN Order_Details OD ON O.Order_ID = OD.Order_ID
JOIN Product P ON OD.Product_ID = P.Product_ID;




CREATE VIEW Order_Summary AS
SELECT U.First_Name, O.Order_ID, O.Total_Amount
FROM User U
JOIN Orders O ON U.User_ID = O.User_ID;



