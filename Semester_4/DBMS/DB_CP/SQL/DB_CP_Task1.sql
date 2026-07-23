-- CREATE DATABASE Educational_Institute;
USE Educational_Institute;

CREATE TABLE Department (
 dep_no INT AUTO_INCREMENT PRIMARY KEY,
 name VARCHAR(100) NOT NULL,
 phone_no VARCHAR(20) UNIQUE NOT NULL,
 location VARCHAR(100) DEFAULT NULL
);

SELECT * FROM Department;


CREATE TABLE Professor (
 EMP_ID INT AUTO_INCREMENT PRIMARY KEY,
 first_name VARCHAR(100) NOT NULL,
 last_name VARCHAR(100) NOT NULL,
 phone_no VARCHAR(20) UNIQUE NOT NULL,
 location VARCHAR(100) DEFAULT NULL,
 `Department_no` INT NOT NULL,
 FOREIGN KEY (`Department_no`) REFERENCES `Department` (`dep_no`)
);

SELECT * FROM Professor;




CREATE TABLE Research_Product (
 ProjectID INT AUTO_INCREMENT PRIMARY KEY,
 StartDate date DEFAULT NULL,
 EndDate date DEFAULT NULL,
 AmountOfMoney INT DEFAULT NULL,
 Funding_Agencies VARCHAR(100) DEFAULT NULL,
 `emp_id` INT NOT NULL,
 FOREIGN KEY (`emp_id`) REFERENCES `Professor` (`EMP_ID`)
);

SELECT * FROM Research_Product;




CREATE TABLE Section (
 SectionID INT AUTO_INCREMENT PRIMARY KEY,
 timings VARCHAR(50) NOT NULL,
 RoomNO VARCHAR(20) NOT NULL,
 `emp_id` INT NOT NULL,
 FOREIGN KEY (`emp_id`) REFERENCES `Professor` (`EMP_ID`)
);

SELECT * FROM Section;




CREATE TABLE Course (
 course_ID INT AUTO_INCREMENT PRIMARY KEY,
 NoOfCredits INT NOT NULL,
 Course_name VARCHAR(1000) NOT NULL,
 `Pre_Reqs` VARCHAR(100) NULL,
 `section_id` INT NOT NULL,
 FOREIGN KEY (`section_id`) REFERENCES `Section` (`SectionID`)
);

SELECT * FROM Course;




CREATE TABLE Students (
 RollNo INT AUTO_INCREMENT PRIMARY KEY,
 first_name VARCHAR(100) NOT NULL,
 last_name VARCHAR(100) NOT NULL,
 emailAddress VARCHAR(100) NOT NULL,
 HouseNO VARCHAR(50) NOT NULL,
 Street  VARCHAR(50) NOT NULL,
 City VARCHAR(50) NOT NULL,
 PIN INT UNIQUE NOT NULL,
 DateOfBirth DATE NOT NULL,
 phone_no VARCHAR(20) UNIQUE NOT NULL,
 RoomNO VARCHAR(20) NOT NULL,
 Hostel_Name VARCHAR(50) NOT NULL,
 `courseID` INT NOT NULL,
 `dep_no` INT NOT NULL,
 FOREIGN KEY (`dep_no`) REFERENCES `Department` (`dep_no`),
 FOREIGN KEY (`courseID`) REFERENCES `Course` (`course_ID`)
);

SELECT * FROM Students;


ALTER TABLE Students
ADD COLUMN sectionID INT NOT NULL,
ADD CONSTRAINT fk_student_section FOREIGN KEY (sectionID) REFERENCES Section(SectionID);

