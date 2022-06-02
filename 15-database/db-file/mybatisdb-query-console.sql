DELETE FROM person WHERE id = 4;

INSERT INTO person
		(id,user_name,age,remark)
		VALUES
		(6,'jim',20,'test');
SELECT COUNT(*) FROM person;