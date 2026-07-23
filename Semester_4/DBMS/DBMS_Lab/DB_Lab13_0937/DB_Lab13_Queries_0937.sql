-- 1. Create a view to display customer_name and city from the Customers table.
CREATE VIEW vw_customer_city AS
SELECT customer_name, city
FROM Customers;

select * from vw_customer_city;




-- 2. Create a view that displays account_id, account_type, and balance from Accounts table.
CREATE VIEW vw_account_info AS
SELECT account_id, account_type, balance
FROM Accounts;

select * from vw_account_info;





-- 3. Create a view that joins Customers and Accounts to show customer_name and balance.
CREATE VIEW vw_customer_balance AS
SELECT c.customer_name, a.balance
FROM Customers c
JOIN Accounts a
ON c.customer_id = a.customer_id;

select * from vw_customer_balance;




-- 4. Create a view to display only savings accounts.
CREATE VIEW vw_savings_accounts AS
SELECT *
FROM Accounts
WHERE account_type = 'Savings';

select * from vw_savings_accounts;





-- 5. Create a view to show accounts with balance greater than 50000.
CREATE VIEW vw_high_balance_accounts AS
SELECT *
FROM Accounts
WHERE balance > 50000;

select * from vw_high_balance_accounts;





-- 6. Create a view to display transaction details for each account.
CREATE VIEW vw_account_transactions AS
SELECT
    a.account_id,
    t.transaction_id,
    t.transaction_date,
    t.transaction_amount,
    t.transaction_type
FROM Accounts a
JOIN Transactions t
ON a.account_id = t.account_id;

select * from vw_account_transactions;





-- 7. Create a view that shows customer_name, account_type, and transaction_amount.
CREATE VIEW vw_customer_transactions AS
SELECT
    c.customer_name,
    a.account_type,
    t.transaction_amount
FROM Customers c
JOIN Accounts a
ON c.customer_id = a.customer_id
JOIN Transactions t
ON a.account_id = t.account_id;

select * from vw_customer_transactions;





-- 8. Create a stored procedure to display all records from Customers table.
DELIMITER $$

CREATE PROCEDURE ShowCustomers()
BEGIN
    SELECT * FROM Customers;
END $$

DELIMITER ;

CALL ShowCustomers();




-- 9. Create a stored procedure to display all records from Accounts table.
DELIMITER $$

CREATE PROCEDURE ShowAccounts()
BEGIN
    SELECT * FROM Accounts;
END $$

DELIMITER ;

CALL ShowAccounts();






-- 10. Create a stored procedure that accepts customer_id and displays related accounts.
DELIMITER $$

CREATE PROCEDURE GetCustomerAccounts(
    IN p_customer_id INT
)
BEGIN
    SELECT *
    FROM Accounts
    WHERE customer_id = p_customer_id;
END $$

DELIMITER ;

CALL GetCustomerAccounts(1);






-- 11. Create a stored procedure that accepts account_id and shows account balance.
DELIMITER $$

CREATE PROCEDURE GetAccountBalance(
    IN p_account_id INT
)
BEGIN
    SELECT balance
    FROM Accounts
    WHERE account_id = p_account_id;
END $$

DELIMITER ;

CALL GetAccountBalance(2);





-- 12. Create a stored procedure to display all transactions of a given account_id.
DELIMITER $$

CREATE PROCEDURE GetAccountTransactions(
    IN p_account_id INT
)
BEGIN
    SELECT *
    FROM Transactions
    WHERE account_id = p_account_id;
END $$

DELIMITER ;

CALL GetAccountTransactions(2);






-- Q13: Create a stored procedure that displays transactions greater than a given amount.
DELIMITER //

CREATE PROCEDURE GetTransactionsGreaterThanAmount(
    IN p_amount DECIMAL(12,2)
)
BEGIN
    SELECT *
    FROM Transactions
    WHERE transaction_amount > p_amount;
END //

DELIMITER ;

CALL GetTransactionsGreaterThanAmount(10000);






-- Q14: Create a stored procedure to display customers belonging to a specific city.
DELIMITER //

CREATE PROCEDURE GetCustomersByCity(
    IN p_city VARCHAR(100)
)
BEGIN
    SELECT *
    FROM Customers
    WHERE city = p_city;
END //

DELIMITER ;

CALL GetCustomersByCity('Lahore');





-- Q15: Create a stored procedure that accepts account_type and displays matching accounts.
DELIMITER //

CREATE PROCEDURE GetAccountsByType(
    IN p_account_type VARCHAR(50)
)
BEGIN
    SELECT *
    FROM Accounts
    WHERE account_type = p_account_type;
END //

DELIMITER ;

CALL GetAccountsByType('Savings');






-- Q16: Create a view to display total balance of each customer.
CREATE VIEW CustomerTotalBalance AS
SELECT
    c.customer_id,
    c.customer_name,
    SUM(a.balance) AS total_balance
FROM Customers c
JOIN Accounts a
    ON c.customer_id = a.customer_id
GROUP BY c.customer_id, c.customer_name;

SELECT * FROM CustomerTotalBalance;





-- Q17: Create a stored procedure to count total number of accounts.
DELIMITER //

CREATE PROCEDURE CountTotalAccounts()
BEGIN
    SELECT COUNT(*) AS Total_Accounts
    FROM Accounts;
END //

DELIMITER ;

CALL CountTotalAccounts();




-- Q18: Create a stored procedure that accepts customer_id and counts total accounts of that customer.
DELIMITER //

CREATE PROCEDURE CountCustomerAccounts(
    IN p_customer_id INT
)
BEGIN
    SELECT
        customer_id,
        COUNT(*) AS Total_Accounts
    FROM Accounts
    WHERE customer_id = p_customer_id
    GROUP BY customer_id;
END //

DELIMITER ;

CALL CountCustomerAccounts(1);






-- Q19: Create a view to display recent transactions.
CREATE VIEW RecentTransactions AS
SELECT *
FROM Transactions
WHERE transaction_date >= CURDATE() - INTERVAL 30 DAY;

SELECT * FROM RecentTransactions;






-- Q20: Create a stored procedure to display transactions between two dates.
DELIMITER //

CREATE PROCEDURE GetTransactionsBetweenDates(
    IN p_start_date DATE,
    IN p_end_date DATE
)
BEGIN
    SELECT *
    FROM Transactions
    WHERE transaction_date
          BETWEEN p_start_date AND p_end_date;
END //

DELIMITER ;


CALL GetTransactionsBetweenDates(
    '2025-05-01',
    '2025-06-30'
);




