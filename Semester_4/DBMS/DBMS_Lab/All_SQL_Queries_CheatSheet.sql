CREATE DATABASE UNIVERSITY;
USE UNIVERSITY;

CREATE TABLE STUDENT (
	rollNo INT PRIMARY KEY AUTO_INCREMENT,
    studentName varchar(100) not null,
    cgpa float default 0.0,
    department varchar(100) not null,
    phoneNo varchar(100) not null unique,
    studentEmail varchar(100) not null unique,
    portalPassword varchar(100) not null,
    systemPassword varchar(100) not null,
    currentSemester int not null,
    gender ENUM('Male', 'Female', 'Other') not null,
    degreeStartDate DATE not null,
    degreeEndDate DATE not null,
    feeSubmitted BOOLEAN not null
    -- add "Address" and "DOB"
);

SELECT * FROM STUDENT;

SELECT rollNo, studentName, cgpa, gender, studentEmail, phoneNo, department from STUDENT;

RENAME table newStudent to student;


ALTER TABLE student ADD COLUMN IsPassed bool default true;
ALTER TABLE student drop column IsPassed;
ALTER TABLE student MODIFY COLUMN cgpa float default 4.0;


ALTER TABLE STUDENT MODIFY COLUMN gender ENUM('Male', 'Female', 'Other') not null after cgpa;

ALTER TABLE STUDENT MODIFY COLUMN studentName varchar(100) not null FIRST;

-- ALTER TABLE LAB
-- ADD CONSTRAINT PatientID
-- FOREIGN KEY (PatientID) REFERENCES PATIENT(PatientID);

INSERT INTO STUDENT VALUES 
('Hussain Durrani', 0937, 3.5, 'Male','FoIT', '0326-9426206', 'L1F24BSCS0937', 'DURRANI.0937', 'MHD,0937', 4, '2024-10-08', '2028-10-08', TRUE),
('Ali Hamza', 1037, 2.77, 'Male','FoIT', '0333-77xxxxx', 'L1F24BSCS1037', 'ALi.0937', 'ALi,0937', 4, '2024-10-20', '2028-10-20', false);

DELETE FROM STUDENT WHERE rollNo=1037;

INSERT INTO STUDENT VALUES 
('Ali Hamza', 1037, DEFAULT,'Male','FoIT', '0333-77xxxxx', 'L1F24BSCS1037', 'ALi.0937', 'ALi,0937', 4, '2024-10-20', '2028-10-20', false);

SELECT * FROM STUDENT;

alter table student modify column portalPassword varchar(100) default 'student.ucp';
alter table student modify column systemPassword varchar(100) default 'student.ucp';
alter table student modify column gender ENUM('Male', 'Female', 'Other') default 'Male';
alter table student modify column feeSubmitted BOOLEAN default null;
alter table student modify column degreeStartDate DATE default null;
alter table student modify column degreeEndDate DATE default null;

INSERT INTO STUDENT (studentName, rollNo, cgpa, gender, department, phoneNo, studentEmail, currentSemester) VALUES
('Talha Khurram', 0938, 3.7, 'Male', 'FoIT', '03__-xx__x@x', 'L1F24BSCS0938', 4);


SELECT * FROM STUDENT;

SELECT * FROM STUDENT WHERE department = 'FoIT';
SELECT * FROM STUDENT WHERE cgpa >= 3.5 and cgpa < 3.8;
SELECT * FROM STUDENT WHERE gender <> 'Male';
SELECT * FROM STUDENT WHERE degreeStartDate > '2024-10-08';
SELECT * FROM STUDENT WHERE rollNo != 0937;
SELECT * FROM STUDENT WHERE feeSubmitted IS NOT NULL AND feeSubmitted is NOT false;
SELECT * FROM STUDENT WHERE cgpa between 3.5 and 3.9;
SELECT * FROM STUDENT WHERE feeSubmitted IS true OR feeSubmitted is false;
SELECT * FROM STUDENT WHERE gender in ('Other', 'Female');

SELECT * FROM STUDENT WHERE phoneNo like '%26%';
SELECT * FROM STUDENT WHERE phoneNo like '0333%';
SELECT * FROM STUDENT WHERE phoneNo like '%206';
SELECT * FROM STUDENT WHERE portalPassword like '___.0937';

SELECT * FROM STUDENT ORDER BY cgpa DESC LIMIT 1;
SELECT * FROM STUDENT ORDER BY cgpa LIMIT 2;



-- Updating Existing Table Data
UPDATE STUDENT SET cgpa = 3.0 where rollNo = 1037;

UPDATE STUDENT SET phoneNo='0301-xxxxxxx', feeSubmitted=true where rollNo=938;

-- SET SQL_SAFE_UPDATES = 0;

UPDATE STUDENT SET department = 'CS' WHERE cgpa = 3.7;

UPDATE STUDENT SET department = 'CS' WHERE feeSubmitted = true;

UPDATE STUDENT SET department = 'CS & AI' WHERE rollNo != 937;

SELECT * FROM STUDENT;



INSERT INTO STUDENT (studentName, rollNo, cgpa, gender, department, phoneNo, studentEmail, currentSemester) VALUES
('X name', 0945, 3.7, 'Male', 'FoIT', '03__-xx__x@x', 'L1F24BSCS0945', 4);

DELETE FROM STUDENT
WHERE rollNo = 0945;

-- DELETE FROM STUDENT;
-- DELETE FROM STUDENT WHERE gender = 'Other';
-- DROP TABLE STUDENT;

-- ALTER TABLE STUDENT ADD CONSTRAINT UniqueName UNIQUE (studentName);
-- ALTER TABLE STUDENT DROP CONSTRAINT UniqueName;

-- ALTER TABLE STUDENT ADD CONSTRAINT chk_dob CHECK (date_of_birth > '2006-01-01');
-- ALTER TABLE STUDENT ADD PRIMARY KEY (rollNo);

-- Without rollNo as it is auto_incrementing
INSERT INTO STUDENT (studentName, cgpa, gender, department, phoneNo, studentEmail, currentSemester) VALUES
('X name', 3.7, 'Male', 'FoIT', '03__-xx__x@x', 'L1F24BSCS0945', 4);

