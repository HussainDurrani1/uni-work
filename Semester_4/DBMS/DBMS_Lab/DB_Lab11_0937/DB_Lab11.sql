-- 1. List the name, account ID, and branch name of all customers who have an account.
SELECT c.customer_name, a.account_id, b.branch_name
FROM Customer c
JOIN Account a ON c.customer_id = a.customer_id
JOIN Branch b ON a.branch_id = b.branch_id;


-- 2. Find customers who have both a loan and an account in the same branch.
SELECT DISTINCT c.customer_name, b.branch_name
FROM Customer c
JOIN Account a ON c.customer_id = a.customer_id
JOIN Loan l ON c.customer_id = l.customer_id
AND a.branch_id = l.branch_id
JOIN Branch b ON a.branch_id = b.branch_id;




-- 3. Show total balance held in each branch (branch-wise total balance of accounts).
SELECT b.branch_name, SUM(a.balance) AS total_balance
FROM Branch b
JOIN Account a ON b.branch_id = a.branch_id
GROUP BY b.branch_name;





-- 4. Find the customer(s) with the highest total balance across all their accounts.
SELECT c.customer_name, SUM(a.balance) AS total_balance
FROM Customer c
JOIN Account a ON c.customer_id = a.customer_id
GROUP BY c.customer_id, c.customer_name
HAVING SUM(a.balance) = (
    SELECT MAX(total_balance)
    FROM (
        SELECT SUM(balance) AS total_balance
        FROM Account
        GROUP BY customer_id
    ) AS temp
);





-- 5. Find the average loan amount per branch.
SELECT b.branch_name, AVG(l.loan_amount) AS average_loan
FROM Branch b
JOIN Loan l ON b.branch_id = l.branch_id
GROUP BY b.branch_name;





-- 6. Count how many customers have taken a loan and how many have an account.
SELECT 
    (SELECT COUNT(DISTINCT customer_id) FROM Loan) AS customers_with_loan,
    (SELECT COUNT(DISTINCT customer_id) FROM Account) AS customers_with_account;
    
    
    
    


-- 7. List all customers whose account balance is above the average balance of all accounts in their branch.
SELECT c.customer_name, a.account_id, b.branch_name, a.balance
FROM Customer c
JOIN Account a ON c.customer_id = a.customer_id
JOIN Branch b ON a.branch_id = b.branch_id
WHERE a.balance > (
    SELECT AVG(a2.balance)
    FROM Account a2
    WHERE a2.branch_id = a.branch_id
);




-- 8. Find the customer(s) who made the highest transaction (by amount) in each branch.
SELECT c.customer_name, b.branch_name, t.transaction_amount
FROM TransactionRecord t
JOIN Account a ON t.account_id = a.account_id
JOIN Customer c ON a.customer_id = c.customer_id
JOIN Branch b ON a.branch_id = b.branch_id
WHERE t.transaction_amount = (
    SELECT MAX(t2.transaction_amount)
    FROM TransactionRecord t2
    JOIN Account a2 ON t2.account_id = a2.account_id
    WHERE a2.branch_id = a.branch_id
);





-- 9. Display customer names who have made transactions only above 10,000.
SELECT c.customer_name
FROM Customer c
JOIN Account a ON c.customer_id = a.customer_id
JOIN TransactionRecord t ON a.account_id = t.account_id
GROUP BY c.customer_id, c.customer_name
HAVING MIN(t.transaction_amount) > 10000;





-- 10. Show the top 3 branches with the highest total loan disbursement.
SELECT b.branch_name, SUM(l.loan_amount) AS total_loan_disbursement
FROM Branch b
JOIN Loan l ON b.branch_id = l.branch_id
GROUP BY b.branch_name
ORDER BY total_loan_disbursement DESC
LIMIT 3;



