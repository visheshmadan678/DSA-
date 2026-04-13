# Write your MySQL query statement below#
select c.name as Customers
from customers c 
left join orders o
on c.Id = o.customerId
where o.id is null;
