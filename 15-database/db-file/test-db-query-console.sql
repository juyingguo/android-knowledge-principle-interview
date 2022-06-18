INSERT INTO `test`.`tb_category` (
	`name`,
	`parent_id`,
	`state`,
	`sort_num`
)
VALUES
	('电器', '0', '0', '0');

SHOW FULL COLUMNS
FROM
	tb_category;

SELECT
	*
FROM
	tb_category;

INSERT INTO `test`.`tb_category` (
	`name`,
	`parent_id`,
	`state`,
	`sort_num`
)
VALUES
	('办公电器', '4', '0', '0');

DELETE
FROM
	tb_temp_delete_test
WHERE
	1 = 1;

/* 查询所有主类*/
SELECT
	*
FROM
	tb_category
WHERE
	parent_id = 0;

/*查询所有子类*/
SELECT
	*
FROM
	tb_category
WHERE
	parent_id > 0;

/*使用左连接查询*/
SELECT
	a.*, b.*
FROM
	tb_category a
LEFT JOIN tb_category b ON 1 = 1;

/*查询所有主类及其对应的子类*/
SELECT
	a.*
FROM
	tb_category a
LEFT JOIN tb_category b ON a.`id` = b.`parent_id`;

/*查询所有主类及其对应的子类,去掉完全重复的*/
SELECT DISTINCT
	a.*
FROM
	tb_category a
LEFT JOIN tb_category b ON a.`id` = b.`parent_id`;

/*查询所有学生*/
SELECT
	*
FROM
	tb_student_mytest;

/*查询所有用户*/
SELECT
	*
FROM
	tb_user;

/*查询所有所有学生及关联的头像*/
SELECT
	a.*, b.avatar
FROM
	tb_student_mytest AS a
LEFT JOIN tb_user AS b ON a.user_id = b.id;

/*查询指定用户id的学生及关联的头像,高效查询子语句中先过滤*/
SELECT
	a.*, b.avatar
FROM
	(
		SELECT
			*
		FROM
			tb_student_mytest AS x
		WHERE
			x.user_id = 3
	) AS a
LEFT JOIN (
	SELECT
		*
	FROM
		tb_user AS y
	WHERE
		y.id = 3
) AS b ON a.user_id = b.id;
/* limit*/
SELECT * FROM tb_category WHERE `name` = '电器' LIMIT 2;

SELECT * FROM tb_category WHERE id >=3 LIMIT 2;

SELECT * FROM tb_category WHERE `name` = '电器' LIMIT 0,2;
/* limit 0,-1 无法运行*/
SELECT * FROM tb_category LIMIT 0,-1;

/* date SYSDATE()*/
SELECT SYSDATE() as currentDateAndTime;
SELECT SYSDATE()  + 0 as currentDateAndTime0;
SELECT NOW() as currentDateAndTime;

