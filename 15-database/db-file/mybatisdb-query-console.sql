DELETE FROM person WHERE id = 4;

INSERT INTO person
		(id,user_name,age,remark)
		VALUES
		(6,'jim',20,'test');
SELECT COUNT(*) FROM person;

/* 4. 查询，人员和人员扩展信息*/
SELECT
			p.id,p.user_name,p.age,p.remark,
			i.id AS infoid,i.station,i.join_date
		FROM
			(SELECT id,user_name,age,remark FROM person) p
			LEFT JOIN
			(SELECT id,station,join_date FROM person_info) i
		ON p.id=i.id and p.user_name LIKE 'jin';
/* 4.1. 查询，人员和人员扩展信息*/
SELECT
			p.id,p.user_name,p.age,p.remark,
			i.id AS infoid,i.station,i.join_date
		FROM
			(SELECT id,user_name,age,remark FROM person) p
			LEFT JOIN
			(SELECT id,station,join_date FROM person_info) i
		ON p.id=i.id and user_name LIKE 'jin';
/* 4.2. 查询，人员和人员扩展信息。
				子查询内先过滤。
*/
SELECT
			p.id,p.user_name,p.age,p.remark,
			i.id AS infoid,i.station,i.join_date
		FROM
			(SELECT id,user_name,age,remark FROM person WHERE user_name LIKE 'jin') p
		LEFT JOIN
			(SELECT id,station,join_date FROM person_info) i
		ON p.id=i.id;

/* 5. 查询某个人的人员信息，（扩展信息，书籍） */
/*5.1 error。as 后的别名不能用在本where条件判断中*/
SELECT id,user_name as name,age,remark FROM person
						where 1=1 and name='jin';

/*5.2 error*/
SELECT id,user_name as name,age,remark FROM person
						where 1=1 and user_name='jin';
/*5.3 ok*/
SELECT
			p.id,p.name,p.age,p.remark,
			p.infoid,p.station,p.join_date,
			b.book_id,b.book_name,b.money
		FROM
			(
				SELECT
					p.id,p.name,p.age,p.remark,
					i.infoid,i.station,i.join_date
				FROM
					(SELECT id,user_name as name,age,remark FROM person
						where 1=1 and user_name='jin'
					) p
				LEFT JOIN
					(SELECT id AS infoid,station,join_date FROM person_info
						#where 1=1 and user_name='jin'
					) i
				ON p.id=i.infoid
			) p
		LEFT JOIN
			(SELECT id AS book_id,NAME AS book_name,money,person_id FROM book) b
		ON p.id=b.person_id
