INSERT INTO `test`.`tbcategory` (`name`, `parentId`, `state`, `sortNum`) VALUES ('电器', '0', '0', '0'); 
SHOW FULL COLUMNS FROM tbcategory;
SELECT * FROM tbcategory;
INSERT INTO `test`.`tbcategory` (`name`, `parentId`, `state`, `sortNum`) VALUES ('办公电器', '4', '0', '0'); 
DELETE FROM tb_temp_delete_test WHERE 1=1;

/* 查询所有主类*/
SELECT * FROM tb_category WHERE parent_id = 0;

/*查询所有子类*/
SELECT * FROM tb_category WHERE parent_id > 0;

/*使用左连接查询*/
SELECT a.*,b.*
FROM tb_category a 
LEFT JOIN tb_category b 
ON 1=1;

/*查询所有主类及其对应的子类*/
SELECT a.*
FROM tb_category a 
LEFT JOIN tb_category b 
ON a.`id` = b.`parent_id`;

/*查询所有主类及其对应的子类,去掉完全重复的*/
SELECT DISTINCT a.*
FROM tb_category a 
LEFT JOIN tb_category b 
ON a.`id` = b.`parent_id`;

