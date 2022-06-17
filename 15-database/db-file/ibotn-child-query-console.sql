/*
1.查询留样列表，并根据留样人对应的用户id,从另一个数据库表中查询出用户头像。
*/
SELECT
	t1.*, t2.avatar
FROM
	i_logistics_sample AS t1
LEFT JOIN `ibotn-sys`.sys_user AS t2 ON t1.dept_id = t2.dept_id
AND t1.user_id = t2.user_id;

/*
1.1 查询留样列表，并根据留样人对应的用户id,从另一个数据库表中查询出用户头像。
		1.1.1 先执行条件过滤（先根据园所dept_id过滤），再执行左连接，提高效率。
		1.1.2 
*/
SELECT
	t1.*, t2.avatar
FROM
	(
		SELECT
			*
		FROM
			i_logistics_sample AS tx
		WHERE
			tx.dept_id = 101
	) AS t1
LEFT JOIN (
	SELECT
		*
	FROM
		`ibotn-sys`.sys_user AS ty
	WHERE
		ty.dept_id = 101
) AS t2 ON t1.user_id = t2.user_id;

/*
2 查询食谱列表，并根据留样人对应的用户id,从另一个数据库表中查询出用户头像。
		2.1 先执行条件过滤（先根据园所dept_id过滤），再执行左连接，提高效率。
		
*/
SELECT
	t1.*, t2.avatar
FROM
	(
		SELECT
			*
		FROM
			i_logistics_recipe AS tx
		WHERE
			tx.dept_id = 101
	) AS t1
LEFT JOIN (
	SELECT
		*
	FROM
		`ibotn-sys`.sys_user AS ty
	WHERE
		ty.dept_id = 101
) AS t2 ON t1.publish_id = t2.user_id;
