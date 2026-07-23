-- Task 1
-- Many employees can work in our company. 
-- We want to retrieve record of each employee.
use company;
SELECT * FROM EMPLOYEE;

-- Task 2
-- Display the first name of employees having salary greater than 40,000.
SELECT fname, salary from employee
where salary > 40000;


-- Task 3	
-- Display the name of those employees who work as supervisor in the company.
SELECT fname, superssn from employee
where superssn is not null;


-- Task 4	
-- Display the salary and department number of all female employees’.
SELECT fname, SALARY, DNO, SEX FROM employee
WHERE SEX = 'F';



-- Task 5 
-- Display the first name of those employees whose salary is greater the 40,000 and less than 50,000. 
SELECT FNAME, SALARY FROM employee
WHERE SALARY > 40000 AND SALARY < 50000;


-- Task 6
-- Display distinct first name of all the employees works for department, having dno = 5.
SELECT distinct FNAME, DNO FROM EMPLOYEE
WHERE DNO = 5;



-- Task 7
-- Sort the data of all employees in descending order on the basis of their salary
SELECT * FROM EMPLOYEE
ORDER BY SALARY DESC;




-- Task 8 
-- User wants to start a new project of image processing in USA in department no 6.
INSERT INTO PROJECT (PNAME, PNUMBER, PLOCATION, DNUM) VALUES ('Image processing', 4, 'USA', 6);
SELECT * FROM PROJECT;



-- Task 9
-- Now user is facing difficulty while working on a project names Operating Systems in Jacksonville,
-- he wants to change the location from Jacksonville to London.
SET SQL_SAFE_UPDATES = 0;
UPDATE PROJECT SET PLOCATION = 'London' WHERE PNUMBER = 61;
SELECT * FROM PROJECT;



-- Task 10
-- User wants to stop the work on image processing project.
-- So delete the record against this project from database.
DELETE FROM PROJECT
WHERE PNUMBER=4;
SELECT * FROM PROJECT;



-- Task 11
-- Show the names of all employees except who are working in department no. 7
SELECT FNAME, LNAME, DNO FROM employee
WHERE DNO = 7;


