# Write your MySQL query statement below
select distinct v.author_id as id from Views v
join views p
on v.author_id=p.viewer_id
where v.article_id=p.article_id
order by id asc 