SELECT c.tweet_id AS tweet_id 
FROM tweets c
WHERE CHAR_LENGTH(c.content) > 15;   