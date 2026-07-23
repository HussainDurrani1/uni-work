CREATE DATABASE Vaccination_Center;
USE Vaccination_Center;

CREATE TABLE Vaccination_Staff (
    ID INT AUTO_INCREMENT PRIMARY KEY,
    first_name VARCHAR(100) NOT NULL,
    last_name VARCHAR(100) NOT NULL,
    Designation VARCHAR(100) NOT NULL,
    DateOfBirth DATE NOT NULL,
    Qualification VARCHAR(100) NOT NULL,
    Salary INT NOT NULL
);

SELECT * FROM Vaccination_Staff;






CREATE TABLE Vaccination_Stock (
    Vaccination_NO INT AUTO_INCREMENT PRIMARY KEY,
    Company_Name VARCHAR(100) NOT NULL,
    AgeGroup INT NOT NULL,
    Quantity INT NOT NULL,
    id INT NOT NULL,
    FOREIGN KEY (id) REFERENCES Vaccination_Staff(ID)
);

SELECT * FROM Vaccination_Stock;






CREATE TABLE Citizen (
    CNIC INT AUTO_INCREMENT PRIMARY KEY,
    Citizen_Type VARCHAR(100) NOT NULL,
    CID INT UNIQUE NOT NULL,
    BLOOD_PRESSURE FLOAT NOT NULL,
    DateOfVaccination DATE NOT NULL,
    BloodGroup VARCHAR(20) NOT NULL,
    SideEffects VARCHAR(100),
    NoOfDoses INT NOT NULL,
    Citizen_Name VARCHAR(100) NOT NULL,
    DOB DATE NOT NULL,
    V_no INT NOT NULL,
    FOREIGN KEY (V_no) REFERENCES Vaccination_Stock (Vaccination_NO)
);

SELECT * FROM Citizen;




CREATE TABLE Hall (
    HallNo INT AUTO_INCREMENT PRIMARY KEY,
    Catagory VARCHAR(50) UNIQUE NOT NULL,
    cnic INT NOT NULL,
    FOREIGN KEY (cnic) REFERENCES Citizen (CNIC)
);

SELECT * FROM Hall;