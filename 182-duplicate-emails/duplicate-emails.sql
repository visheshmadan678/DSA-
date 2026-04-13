# Write your MySQL query statement below
# so i have to return the all the emails which are duplicate
select email 
from Person
group by email
having count(email) > 1;