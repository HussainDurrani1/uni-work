CREATE DATABASE BankScheme;
USE BankScheme;

CREATE TABLE Branch (
    branch_id INT PRIMARY KEY AUTO_INCREMENT,
    branch_name VARCHAR(50) NOT NULL,
    branch_city VARCHAR(50)
);

CREATE TABLE Customer (
    customer_id INT PRIMARY KEY AUTO_INCREMENT,
    customer_name VARCHAR(50) NOT NULL,
    customer_city VARCHAR(50)
);

CREATE TABLE Account (
    account_id INT PRIMARY KEY AUTO_INCREMENT,
    customer_id INT,
    branch_id INT,
    balance DECIMAL(12,2),
    FOREIGN KEY (customer_id) REFERENCES Customer(customer_id),
    FOREIGN KEY (branch_id) REFERENCES Branch(branch_id)
);

CREATE TABLE Loan (
    loan_id INT PRIMARY KEY AUTO_INCREMENT,
    customer_id INT,
    branch_id INT,
    loan_amount DECIMAL(12,2),
    FOREIGN KEY (customer_id) REFERENCES Customer(customer_id),
    FOREIGN KEY (branch_id) REFERENCES Branch(branch_id)
);

CREATE TABLE TransactionRecord (
    transaction_id INT PRIMARY KEY AUTO_INCREMENT,
    account_id INT,
    transaction_amount DECIMAL(12,2),
    transaction_type VARCHAR(20),
    transaction_date DATE,
    FOREIGN KEY (account_id) REFERENCES Account(account_id)
);

INSERT INTO Branch (branch_name, branch_city) VALUES
('Main Branch', 'Lahore'),
('City Branch', 'Karachi'),
('North Branch', 'Islamabad'),
('South Branch', 'Multan');

INSERT INTO Customer (customer_name, customer_city) VALUES
('Ali Khan', 'Lahore'),
('Sara Ahmed', 'Karachi'),
('Ahmed Raza', 'Islamabad'),
('Fatima Noor', 'Lahore'),
('Hassan Ali', 'Multan'),
('Ayesha Malik', 'Karachi');

INSERT INTO Account (customer_id, branch_id, balance) VALUES
(1, 1, 50000),
(2, 2, 80000),
(3, 3, 120000),
(4, 1, 70000),
(5, 4, 30000),
(6, 2, 150000),
(1, 2, 40000);

INSERT INTO Loan (customer_id, branch_id, loan_amount) VALUES
(1, 1, 200000),
(2, 2, 300000),
(3, 3, 150000),
(4, 1, 250000),
(6, 2, 500000);

INSERT INTO TransactionRecord 
(account_id, transaction_amount, transaction_type, transaction_date) VALUES
(1, 12000, 'Deposit', '2025-01-01'),
(1, 8000, 'Withdraw', '2025-01-05'),
(2, 20000, 'Deposit', '2025-01-03'),
(3, 50000, 'Deposit', '2025-01-04'),
(4, 15000, 'Withdraw', '2025-01-06'),
(5, 9000, 'Deposit', '2025-01-07'),
(6, 60000, 'Deposit', '2025-01-08'),
(7, 30000, 'Deposit', '2025-01-09');