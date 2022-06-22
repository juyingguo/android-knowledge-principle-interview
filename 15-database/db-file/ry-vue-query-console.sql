/*2.3 菜单管理*/
/*2.1 菜单管理-根据用户查询系统菜单列表*/
SELECT m.* from sys_menu as m
LEFT JOIN sys_role_menu as rm on rm.menu_id = m.menu_id
LEFT JOIN sys_user_role as ur on rm.role_id = ur.role_id
LEFT JOIN sys_role AS r on r.role_id = ur.role_id
WHERE user_id = 3;

/*2.5 岗位管理*/
select d.dept_id, d.parent_id, d.ancestors, d.dept_name, d.order_num, d.leader, d.phone, d.email, d.status, d.del_flag, d.create_by, d.create_time from sys_dept d where dept_id = 112;
/*用户*/
select count(1) from sys_user where user_name = 'ry' limit 1;

