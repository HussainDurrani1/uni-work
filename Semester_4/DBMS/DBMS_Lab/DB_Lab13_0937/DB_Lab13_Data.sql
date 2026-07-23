CREATE DATABASE BankDB;
USE BankDB;



CREATE TABLE Customers (
    customer_id INT PRIMARY KEY AUTO_INCREMENT,
    customer_name VARCHAR(100) NOT NULL,
    city VARCHAR(50),
    phone VARCHAR(20)
);



CREATE TABLE Accounts (
    account_id INT PRIMARY KEY AUTO_INCREMENT,
    customer_id INT,
    account_type VARCHAR(20),
    balance DECIMAL(12,2),

    FOREIGN KEY (customer_id)
    REFERENCES Customers(customer_id)
);



CREATE TABLE Transactions (
    transaction_id INT PRIMARY KEY AUTO_INCREMENT,
    account_id INT,
    transaction_date DATE,
    transaction_amount DECIMAL(12,2),
    transaction_type VARCHAR(20),

    FOREIGN KEY (account_id)
    REFERENCES Accounts(account_id)
);



INSERT INTO Customers (customer_name, city, phone)
VALUES
('Ali Khan', 'Lahore', '03001234567'),
('Sara Ahmed', 'Karachi', '03111234567'),
('Usman Malik', 'Islamabad', '03221234567');



INSERT INTO Accounts (customer_id, account_type, balance)
VALUES
(1, 'Savings', 80000),
(1, 'Current', 30000),
(2, 'Savings', 120000),
(3, 'Current', 45000);



INSERT INTO Transactions
(account_id, transaction_date, transaction_amount, transaction_type)
VALUES
(1, '2025-06-01', 10000, 'Deposit'),
(1, '2025-06-03', 5000, 'Withdrawal'),
(2, '2025-06-05', 20000, 'Deposit'),
(3, '2025-06-06', 15000, 'Withdrawal'),
(4, '2025-06-07', 25000, 'Deposit');
