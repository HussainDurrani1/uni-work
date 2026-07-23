CREATE DATABASE Pak_Wheels;
USE Pak_Wheels;

CREATE TABLE Customer (
    CX_no INT AUTO_INCREMENT PRIMARY KEY,
    first_name VARCHAR(100) NOT NULL,
    last_name VARCHAR(100) NOT NULL,
    phone_no VARCHAR(20) UNIQUE NOT NULL,
    Adreess VARCHAR(50) NOT NULL
);

SELECT * FROM Customer;



CREATE TABLE Sales_Person (
    SalesPerson_ID INT AUTO_INCREMENT PRIMARY KEY,
    first_name VARCHAR(100) NOT NULL,
    last_name VARCHAR(100) NOT NULL,
    phone_no VARCHAR(20) UNIQUE NOT NULL,
    Email_Adreess VARCHAR(50) UNIQUE NOT NULL
);

SELECT * FROM Sales_Person;





CREATE TABLE Car (
    Car_Code INT AUTO_INCREMENT PRIMARY KEY,
    Model VARCHAR(100) NOT NULL,
    Make DATE NOT NULL,
    YearOfManufacture DATE NOT NULL,
    Price INT NOT NULL
);

SELECT * FROM Car;







CREATE TABLE Sale (
    Sale_ID INT AUTO_INCREMENT PRIMARY KEY,
    Commission INT NOT NULL,
    CX_no INT NOT NULL,
    SalesPerson_ID INT NOT NULL,
    Car_Code INT NOT NULL,
    FOREIGN KEY (CX_no) REFERENCES Customer (CX_no),
    FOREIGN KEY (SalesPerson_ID) REFERENCES Sales_Person (SalesPerson_ID),
	FOREIGN KEY (Car_Code) REFERENCES Car (Car_Code)
);

SELECT * FROM Sale;






CREATE TABLE Repayment_Scheme (
    RepaymentScheme_no INT AUTO_INCREMENT PRIMARY KEY,
    NoOfYears INT NOT NULL,
    NoOfRepaymentSchemes INT NOT NULL,
    Sale_ID INT NOT NULL,
	FOREIGN KEY (Sale_ID) REFERENCES Sale (Sale_ID)
);

SELECT * FROM Repayment_Scheme;