-- creating a data base as per the entities
CREATE DATABASE HOSPITAL;
USE HOSPITAL;

-- creating PATIENT entity with its attributes
CREATE TABLE PATIENT (
    PatientID varchar (15) PRIMARY KEY NOT NULL,
    NAME VARCHAR(15) NOT NULL,
    AGE INT,
    GENDER VARCHAR(5),
    ADDRESS VARCHAR(20),
    DISEASE VARCHAR(10),
    DoctorID VARCHAR(15)
);

-- changing gender from varchar(5) to char
ALTER TABLE PATIENT MODIFY COLUMN GENDER CHAR NOT NULL;

SELECT * FROM PATIENT;

-- creating doctor entity with its attributes
CREATE TABLE DOCTOR (
    DoctorID VARCHAR(15)  PRIMARY KEY NOT NULL,
    NAME VARCHAR(15) NOT NULL,
    AGE INT,
    GENDER CHAR,
    ADDRESS VARCHAR(20)
);

-- adding a column DoctorWard in DOCTOR table
ALTER TABLE DOCTOR ADD COLUMN DoctorWard varchar(15);

SELECT * FROM DOCTOR;

-- reference DoctorID in patient to primary key DoctorID in DOCTOR
ALTER TABLE PATIENT
ADD CONSTRAINT DoctorID
FOREIGN KEY (DoctorID) REFERENCES DOCTOR(DoctorID);

-- creating LAB entity with its attributes
CREATE TABLE LAB (
	LabID varchar(15) primary key,
	TestDate DATE,
    TestAmount varchar(20),
    PatientID varchar(15),
    DoctorID varchar(15)
);

-- reference PatientID in LAB to primary key PatientID in patient
ALTER TABLE LAB
ADD CONSTRAINT PatientID
FOREIGN KEY (PatientID) REFERENCES PATIENT(PatientID);

-- reference DoctorID in LAB to primary key DoctorID in DOCTOR
ALTER TABLE LAB
ADD CONSTRAINT FOREIGN KEY (DoctorID) REFERENCES DOCTOR(DoctorID);

-- CHANGING Name OF TestAmount to Amount
ALTER TABLE LAB CHANGE TestAmount Amount varchar(20);

-- CHANGING data type OF Amount to double
ALTER TABLE LAB MODIFY COLUMN Amount double;

-- adding a column LabNO in LAB
ALTER TABLE LAB Add column LabNO varchar(10);

select * from lab;

-- creating HospitalRoom entity with its attributes
CREATE TABLE HospitalRoom (
	RoomID varchar (15) PRIMARY KEY,
    RoomAllocationDate date,
    RoomType varchar(20),
    RoomStatus varchar(5)
);

-- creating PatientBill entity with its attributes
CREATE TABLE PatientBill (
	BillID varchar (15) PRIMARY KEY,
    BillDate date,
    Amount varchar(20),
    PatientID varchar(15)
);

-- referencing PatientID in PatientBill to primary key PatientID in PATIENT
ALTER TABLE PatientBill
ADD CONSTRAINT foreign key (PatientID) references PATIENT(PatientID);

-- Renaming Table HospitalRoom TO ROOM
RENAME TABLE HospitalRoom TO ROOM;