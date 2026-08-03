# Write your MySQL query statement below
select distinct p.email as Email from Person p
join Person r
ON p.id!=r.id 
AND p.email=r.email 