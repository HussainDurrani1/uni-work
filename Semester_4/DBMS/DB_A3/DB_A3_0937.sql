-- 1. Simple Subquery: Products more expensive than average product price
SELECT Product_Name, Price
FROM Product
WHERE Price > (
    SELECT AVG(Price)
    FROM Product
);


-- 2. Subquery with IN: Users who placed orders from Lahore
SELECT First_Name, Last_Name, Email
FROM User
WHERE User_ID IN (
    SELECT User_ID
    FROM Orders
    WHERE City = 'Lahore'
);



-- 3. Correlated Subquery: Products costlier than average price of their own category
SELECT Product_ID, Product_Name, Category_ID, Price
FROM Product P
WHERE Price > (
    SELECT AVG(P2.Price)
    FROM Product P2
    WHERE P2.Category_ID = P.Category_ID
);




-- 4. Correlated Subquery: Users whose order amount is greater than their own average order amount
SELECT O.Order_ID, O.User_ID, O.Total_Amount
FROM Orders O
WHERE O.Total_Amount > (
    SELECT AVG(Ord.Total_Amount)
    FROM Orders Ord
    WHERE Ord.User_ID = O.User_ID
);




-- 5. INNER JOIN: Show user names with their orders
SELECT U.User_ID, U.First_Name, U.Last_Name, O.Order_ID, O.Total_Amount, O.Order_Status
FROM User U
INNER JOIN Orders O
ON U.User_ID = O.User_ID;



-- 6. Multiple JOINs: User, order, product, and quantity
SELECT U.First_Name, U.Last_Name, O.Order_ID,
    P.Product_Name, OD.Quantity, OD.Price_at_Purchase
FROM User U
JOIN Orders O ON U.User_ID = O.User_ID
JOIN Order_Details OD ON O.Order_ID = OD.Order_ID
JOIN Product P ON OD.Product_ID = P.Product_ID;




-- 7. JOIN with Category: Products with category names
SELECT  P.Product_Name, P.Brand_Name, P.Price, C.Category_Name
FROM Product P
JOIN Category C
ON P.Category_ID = C.Category_ID;




-- 8. JOIN with Warehouse: Products stored in warehouses
SELECT P.Product_Name, P.Stock_Quantity,
    W.Manager_Name, W.Location, W.City
FROM Product P
JOIN Warehouse W
ON P.Warehouse_ID = W.Warehouse_ID;





-- 9. Aggregate Function: Total sales amount
SELECT SUM(Total_Amount) AS Total_Sales
FROM Orders;



-- 10. GROUP BY: Number of orders in each city
SELECT City, COUNT(Order_ID) AS Total_Orders
FROM Orders
GROUP BY City;



-- 11. Aggregate Functions: Min, max, average product price
SELECT 
    MIN(Price) AS Minimum_Price,
    MAX(Price) AS Maximum_Price,
    AVG(Price) AS Average_Price
FROM Product;





-- 12. GROUP BY with SUM: Total sales by city
SELECT City, SUM(Total_Amount) AS City_Sales
FROM Orders
GROUP BY City;




-- 13. HAVING: Cities having more than 5 orders
SELECT City, COUNT(Order_ID) AS Total_Orders
FROM Orders
GROUP BY City
HAVING COUNT(Order_ID) > 5;



-- 14. HAVING with SUM: Cities where total sales are above 4000
SELECT City, SUM(Total_Amount) AS Total_Sales
FROM Orders
GROUP BY City
HAVING SUM(Total_Amount) > 4000;



-- 15. Set Operation UNION: Cities from Address and Orders
SELECT City FROM Address
UNION
SELECT City FROM Orders;



-- 16. Set Operation INTERSECT alternative in MySQL: Cities present in both Address and Orders
SELECT DISTINCT A.City
FROM Address A
WHERE A.City IN (
    SELECT O.City
    FROM Orders O
);




-- 17. Set Operation EXCEPT alternative in MySQL: Cities in Address but not in Orders
SELECT DISTINCT A.City
FROM Address A
WHERE A.City NOT IN (
    SELECT O.City
    FROM Orders O
);




-- 18. Nested Subquery: Products ordered by users from Karachi
SELECT Product_Name
FROM Product
WHERE Product_ID IN (
    SELECT Product_ID
    FROM Order_Details
    WHERE Order_ID IN (
        SELECT Order_ID
        FROM Orders
        WHERE City = 'Karachi'
    )
);



-- 19. JOIN + GROUP BY + HAVING: Categories having more than 2 products
SELECT 
    C.Category_Name,
    COUNT(P.Product_ID) AS Total_Products
FROM Category C
JOIN Product P
ON C.Category_ID = P.Category_ID
GROUP BY C.Category_Name
HAVING COUNT(P.Product_ID) > 2;




-- 20. Payment Analysis: Total amount paid by payment method
SELECT  Payment_Method,
    SUM(Amount_Paid) AS Total_Paid
FROM Payment
GROUP BY Payment_Method;




-- 21. JOIN + Aggregate: Total quantity sold per product
SELECT  P.Product_Name,
    SUM(OD.Quantity) AS Total_Quantity_Sold
FROM Product P
JOIN Order_Details OD
ON P.Product_ID = OD.Product_ID
GROUP BY P.Product_Name;




-- 22. Correlated Subquery with EXISTS: Users who have placed at least one order
SELECT U.User_ID, U.First_Name, U.Last_Name
FROM User U
WHERE EXISTS (
    SELECT 1
    FROM Orders O
    WHERE O.User_ID = U.User_ID
);



-- 23. NOT EXISTS: Users who have not placed any order
SELECT U.User_ID, U.First_Name, U.Last_Name
FROM User U
WHERE NOT EXISTS (
    SELECT 1
    FROM Orders O
    WHERE O.User_ID = U.User_ID
);




-- 24. Advanced JOIN: Delivered and paid orders with user and payment details
SELECT 
    U.First_Name,
    U.Last_Name,
    O.Order_ID,
    O.Order_Status,
    O.Payment_Status,
    P.Payment_Method,
    P.Amount_Paid
FROM User U
JOIN Orders O ON U.User_ID = O.User_ID
JOIN Payment P ON O.Order_ID = P.Order_ID
WHERE O.Order_Status = 'Delivered'
AND O.Payment_Status = 'Paid';

