WITH NumberOfOrder AS (
  SELECT CUSTOMER_ID, COUNT(ORDER_ID) AS NUMBER_OF_ORDERS
  FROM ordert
  GROUP BY CUSTOMER_ID
)

SELECT c.CUSTOMER_ID, c.CUSTOMER_NAME
FROM CUSTOMER c
JOIN NumberOfOrder noo
ON c.CUSTOMER_ID = noo.CUSTOMER_ID
WHERE noo.NUMBER_OF_ORDERS = (
    SELECT MAX(NUMBER_OF_ORDERS)
    FROM NumberOfOrder
);