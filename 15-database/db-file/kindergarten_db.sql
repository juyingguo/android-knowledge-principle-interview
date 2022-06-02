/*
Navicat MySQL Data Transfer

Source Server         : 47.112.198.104_3306
Source Server Version : 50738
Source Host           : 47.112.198.104:3306
Source Database       : kindergarten_db

Target Server Type    : MYSQL
Target Server Version : 50738
File Encoding         : 65001

Date: 2022-06-02 10:53:13
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for gen_table
-- ----------------------------
DROP TABLE IF EXISTS `gen_table`;
CREATE TABLE `gen_table` (
  `table_id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '编号',
  `table_name` varchar(200) DEFAULT '' COMMENT '表名称',
  `table_comment` varchar(500) DEFAULT '' COMMENT '表描述',
  `sub_table_name` varchar(64) DEFAULT NULL COMMENT '关联子表的表名',
  `sub_table_fk_name` varchar(64) DEFAULT NULL COMMENT '子表关联的外键名',
  `class_name` varchar(100) DEFAULT '' COMMENT '实体类名称',
  `tpl_category` varchar(200) DEFAULT 'crud' COMMENT '使用的模板（crud单表操作 tree树表操作）',
  `package_name` varchar(100) DEFAULT NULL COMMENT '生成包路径',
  `module_name` varchar(30) DEFAULT NULL COMMENT '生成模块名',
  `business_name` varchar(30) DEFAULT NULL COMMENT '生成业务名',
  `function_name` varchar(50) DEFAULT NULL COMMENT '生成功能名',
  `function_author` varchar(50) DEFAULT NULL COMMENT '生成功能作者',
  `gen_type` char(1) DEFAULT '0' COMMENT '生成代码方式（0zip压缩包 1自定义路径）',
  `gen_path` varchar(200) DEFAULT '/' COMMENT '生成路径（不填默认项目路径）',
  `options` varchar(1000) DEFAULT NULL COMMENT '其它生成选项',
  `create_by` varchar(64) DEFAULT '' COMMENT '创建者',
  `create_time` datetime DEFAULT NULL COMMENT '创建时间',
  `update_by` varchar(64) DEFAULT '' COMMENT '更新者',
  `update_time` datetime DEFAULT NULL COMMENT '更新时间',
  `remark` varchar(500) DEFAULT NULL COMMENT '备注',
  PRIMARY KEY (`table_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='代码生成业务表';

-- ----------------------------
-- Records of gen_table
-- ----------------------------

-- ----------------------------
-- Table structure for gen_table_column
-- ----------------------------
DROP TABLE IF EXISTS `gen_table_column`;
CREATE TABLE `gen_table_column` (
  `column_id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '编号',
  `table_id` varchar(64) DEFAULT NULL COMMENT '归属表编号',
  `column_name` varchar(200) DEFAULT NULL COMMENT '列名称',
  `column_comment` varchar(500) DEFAULT NULL COMMENT '列描述',
  `column_type` varchar(100) DEFAULT NULL COMMENT '列类型',
  `java_type` varchar(500) DEFAULT NULL COMMENT 'JAVA类型',
  `java_field` varchar(200) DEFAULT NULL COMMENT 'JAVA字段名',
  `is_pk` char(1) DEFAULT NULL COMMENT '是否主键（1是）',
  `is_increment` char(1) DEFAULT NULL COMMENT '是否自增（1是）',
  `is_required` char(1) DEFAULT NULL COMMENT '是否必填（1是）',
  `is_insert` char(1) DEFAULT NULL COMMENT '是否为插入字段（1是）',
  `is_edit` char(1) DEFAULT NULL COMMENT '是否编辑字段（1是）',
  `is_list` char(1) DEFAULT NULL COMMENT '是否列表字段（1是）',
  `is_query` char(1) DEFAULT NULL COMMENT '是否查询字段（1是）',
  `query_type` varchar(200) DEFAULT 'EQ' COMMENT '查询方式（等于、不等于、大于、小于、范围）',
  `html_type` varchar(200) DEFAULT NULL COMMENT '显示类型（文本框、文本域、下拉框、复选框、单选框、日期控件）',
  `dict_type` varchar(200) DEFAULT '' COMMENT '字典类型',
  `sort` int(11) DEFAULT NULL COMMENT '排序',
  `create_by` varchar(64) DEFAULT '' COMMENT '创建者',
  `create_time` datetime DEFAULT NULL COMMENT '创建时间',
  `update_by` varchar(64) DEFAULT '' COMMENT '更新者',
  `update_time` datetime DEFAULT NULL COMMENT '更新时间',
  PRIMARY KEY (`column_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='代码生成业务表字段';

-- ----------------------------
-- Records of gen_table_column
-- ----------------------------

-- ----------------------------
-- Table structure for sys_config
-- ----------------------------
DROP TABLE IF EXISTS `sys_config`;
CREATE TABLE `sys_config` (
  `config_id` int(5) NOT NULL AUTO_INCREMENT COMMENT '参数主键',
  `config_name` varchar(100) DEFAULT '' COMMENT '参数名称',
  `config_key` varchar(100) DEFAULT '' COMMENT '参数键名',
  `config_value` varchar(500) DEFAULT '' COMMENT '参数键值',
  `config_type` char(1) DEFAULT 'N' COMMENT '系统内置（Y是 N否）',
  `create_by` varchar(64) DEFAULT '' COMMENT '创建者',
  `create_time` datetime DEFAULT NULL COMMENT '创建时间',
  `update_by` varchar(64) DEFAULT '' COMMENT '更新者',
  `update_time` datetime DEFAULT NULL COMMENT '更新时间',
  `remark` varchar(500) DEFAULT NULL COMMENT '备注',
  PRIMARY KEY (`config_id`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8 COMMENT='参数配置表';

-- ----------------------------
-- Records of sys_config
-- ----------------------------
INSERT INTO `sys_config` VALUES ('1', '主框架页-默认皮肤样式名称', 'sys.index.skinName', 'skin-blue', 'Y', 'admin', '2022-05-29 12:33:46', '', null, '蓝色 skin-blue、绿色 skin-green、紫色 skin-purple、红色 skin-red、黄色 skin-yellow');
INSERT INTO `sys_config` VALUES ('2', '用户管理-账号初始密码', 'sys.user.initPassword', '123456', 'Y', 'admin', '2022-05-29 12:33:46', '', null, '初始化密码 123456');
INSERT INTO `sys_config` VALUES ('3', '主框架页-侧边栏主题', 'sys.index.sideTheme', 'theme-dark', 'Y', 'admin', '2022-05-29 12:33:47', '', null, '深色主题theme-dark，浅色主题theme-light');
INSERT INTO `sys_config` VALUES ('4', '账号自助-验证码开关', 'sys.account.captchaOnOff', 'false', 'Y', 'admin', '2022-05-29 12:33:47', '', null, '是否开启验证码功能（true开启，false关闭）');
INSERT INTO `sys_config` VALUES ('5', '账号自助-是否开启用户注册功能', 'sys.account.registerUser', 'false', 'Y', 'admin', '2022-05-29 12:33:47', '', null, '是否开启注册用户功能（true开启，false关闭）');

-- ----------------------------
-- Table structure for sys_dept
-- ----------------------------
DROP TABLE IF EXISTS `sys_dept`;
CREATE TABLE `sys_dept` (
  `dept_id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '部门id',
  `parent_id` bigint(20) DEFAULT '0' COMMENT '父部门id',
  `ancestors` varchar(50) DEFAULT '' COMMENT '祖级列表',
  `dept_name` varchar(30) DEFAULT '' COMMENT '部门名称',
  `order_num` int(4) DEFAULT '0' COMMENT '显示顺序',
  `leader` varchar(20) DEFAULT NULL COMMENT '负责人',
  `phone` varchar(11) DEFAULT NULL COMMENT '联系电话',
  `email` varchar(50) DEFAULT NULL COMMENT '邮箱',
  `status` char(1) DEFAULT '0' COMMENT '部门状态（0正常 1停用）',
  `del_flag` char(1) DEFAULT '0' COMMENT '删除标志（0代表存在 2代表删除）',
  `create_by` varchar(64) DEFAULT '' COMMENT '创建者',
  `create_time` datetime DEFAULT NULL COMMENT '创建时间',
  `update_by` varchar(64) DEFAULT '' COMMENT '更新者',
  `update_time` datetime DEFAULT NULL COMMENT '更新时间',
  PRIMARY KEY (`dept_id`)
) ENGINE=InnoDB AUTO_INCREMENT=110 DEFAULT CHARSET=utf8 COMMENT='部门表';

-- ----------------------------
-- Records of sys_dept
-- ----------------------------
INSERT INTO `sys_dept` VALUES ('100', '0', '0', '玉林幼儿园', '0', '杨园长', '15888888887', 'yulin@qq.com', '0', '0', 'admin', '2022-05-29 12:33:25', 'admin', '2022-06-01 08:00:59');
INSERT INTO `sys_dept` VALUES ('101', '100', '0,100', '后勤部门', '1', '钟部长', '15888888888', 'zhon@qq.com', '0', '0', 'admin', '2022-05-29 12:33:25', 'admin', '2022-06-01 08:01:35');
INSERT INTO `sys_dept` VALUES ('102', '100', '0,100', '财务部门', '2', '张部长', '15888888888', 'zhan@qq.com', '0', '0', 'admin', '2022-05-29 12:33:25', 'admin', '2022-06-01 08:02:05');
INSERT INTO `sys_dept` VALUES ('103', '101', '0,100,101', 'a部门', '1', '李', '15888888888', 'ry@qq.com', '0', '0', 'admin', '2022-05-29 12:33:26', 'admin', '2022-06-01 08:03:21');
INSERT INTO `sys_dept` VALUES ('104', '101', '0,100,101', '市场部门', '2', '若依', '15888888888', 'ry@qq.com', '0', '2', 'admin', '2022-05-29 12:33:26', '', null);
INSERT INTO `sys_dept` VALUES ('105', '101', '0,100,101', 'b部门', '3', '李', '15888888888', 'ry@qq.com', '0', '0', 'admin', '2022-05-29 12:33:26', 'admin', '2022-06-01 08:03:35');
INSERT INTO `sys_dept` VALUES ('106', '101', '0,100,101', '财务部门', '4', '若依', '15888888888', 'ry@qq.com', '0', '2', 'admin', '2022-05-29 12:33:26', '', null);
INSERT INTO `sys_dept` VALUES ('107', '101', '0,100,101', '运维部门', '5', '若依', '15888888888', 'ry@qq.com', '0', '2', 'admin', '2022-05-29 12:33:26', '', null);
INSERT INTO `sys_dept` VALUES ('108', '102', '0,100,102', '市场部门', '1', '若依', '15888888888', 'ry@qq.com', '0', '2', 'admin', '2022-05-29 12:33:26', '', null);
INSERT INTO `sys_dept` VALUES ('109', '102', '0,100,102', '财务部门', '2', '若依', '15888888888', 'ry@qq.com', '0', '2', 'admin', '2022-05-29 12:33:26', '', null);

-- ----------------------------
-- Table structure for sys_dict_data
-- ----------------------------
DROP TABLE IF EXISTS `sys_dict_data`;
CREATE TABLE `sys_dict_data` (
  `dict_code` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '字典编码',
  `dict_sort` int(4) DEFAULT '0' COMMENT '字典排序',
  `dict_label` varchar(100) DEFAULT '' COMMENT '字典标签',
  `dict_value` varchar(100) DEFAULT '' COMMENT '字典键值',
  `dict_type` varchar(100) DEFAULT '' COMMENT '字典类型',
  `css_class` varchar(100) DEFAULT NULL COMMENT '样式属性（其他样式扩展）',
  `list_class` varchar(100) DEFAULT NULL COMMENT '表格回显样式',
  `is_default` char(1) DEFAULT 'N' COMMENT '是否默认（Y是 N否）',
  `status` char(1) DEFAULT '0' COMMENT '状态（0正常 1停用）',
  `create_by` varchar(64) DEFAULT '' COMMENT '创建者',
  `create_time` datetime DEFAULT NULL COMMENT '创建时间',
  `update_by` varchar(64) DEFAULT '' COMMENT '更新者',
  `update_time` datetime DEFAULT NULL COMMENT '更新时间',
  `remark` varchar(500) DEFAULT NULL COMMENT '备注',
  PRIMARY KEY (`dict_code`)
) ENGINE=InnoDB AUTO_INCREMENT=29 DEFAULT CHARSET=utf8 COMMENT='字典数据表';

-- ----------------------------
-- Records of sys_dict_data
-- ----------------------------
INSERT INTO `sys_dict_data` VALUES ('1', '1', '男', '0', 'sys_user_sex', '', '', 'Y', '0', 'admin', '2022-05-29 12:33:44', '', null, '性别男');
INSERT INTO `sys_dict_data` VALUES ('2', '2', '女', '1', 'sys_user_sex', '', '', 'N', '0', 'admin', '2022-05-29 12:33:44', '', null, '性别女');
INSERT INTO `sys_dict_data` VALUES ('3', '3', '未知', '2', 'sys_user_sex', '', '', 'N', '0', 'admin', '2022-05-29 12:33:44', '', null, '性别未知');
INSERT INTO `sys_dict_data` VALUES ('4', '1', '显示', '0', 'sys_show_hide', '', 'primary', 'Y', '0', 'admin', '2022-05-29 12:33:44', '', null, '显示菜单');
INSERT INTO `sys_dict_data` VALUES ('5', '2', '隐藏', '1', 'sys_show_hide', '', 'danger', 'N', '0', 'admin', '2022-05-29 12:33:44', '', null, '隐藏菜单');
INSERT INTO `sys_dict_data` VALUES ('6', '1', '正常', '0', 'sys_normal_disable', '', 'primary', 'Y', '0', 'admin', '2022-05-29 12:33:44', '', null, '正常状态');
INSERT INTO `sys_dict_data` VALUES ('7', '2', '停用', '1', 'sys_normal_disable', '', 'danger', 'N', '0', 'admin', '2022-05-29 12:33:44', '', null, '停用状态');
INSERT INTO `sys_dict_data` VALUES ('8', '1', '正常', '0', 'sys_job_status', '', 'primary', 'Y', '0', 'admin', '2022-05-29 12:33:44', '', null, '正常状态');
INSERT INTO `sys_dict_data` VALUES ('9', '2', '暂停', '1', 'sys_job_status', '', 'danger', 'N', '0', 'admin', '2022-05-29 12:33:45', '', null, '停用状态');
INSERT INTO `sys_dict_data` VALUES ('10', '1', '默认', 'DEFAULT', 'sys_job_group', '', '', 'Y', '0', 'admin', '2022-05-29 12:33:45', '', null, '默认分组');
INSERT INTO `sys_dict_data` VALUES ('11', '2', '系统', 'SYSTEM', 'sys_job_group', '', '', 'N', '0', 'admin', '2022-05-29 12:33:45', '', null, '系统分组');
INSERT INTO `sys_dict_data` VALUES ('12', '1', '是', 'Y', 'sys_yes_no', '', 'primary', 'Y', '0', 'admin', '2022-05-29 12:33:45', '', null, '系统默认是');
INSERT INTO `sys_dict_data` VALUES ('13', '2', '否', 'N', 'sys_yes_no', '', 'danger', 'N', '0', 'admin', '2022-05-29 12:33:45', '', null, '系统默认否');
INSERT INTO `sys_dict_data` VALUES ('14', '1', '通知', '1', 'sys_notice_type', '', 'warning', 'Y', '0', 'admin', '2022-05-29 12:33:45', '', null, '通知');
INSERT INTO `sys_dict_data` VALUES ('15', '2', '公告', '2', 'sys_notice_type', '', 'success', 'N', '0', 'admin', '2022-05-29 12:33:45', '', null, '公告');
INSERT INTO `sys_dict_data` VALUES ('16', '1', '正常', '0', 'sys_notice_status', '', 'primary', 'Y', '0', 'admin', '2022-05-29 12:33:45', '', null, '正常状态');
INSERT INTO `sys_dict_data` VALUES ('17', '2', '关闭', '1', 'sys_notice_status', '', 'danger', 'N', '0', 'admin', '2022-05-29 12:33:45', '', null, '关闭状态');
INSERT INTO `sys_dict_data` VALUES ('18', '1', '新增', '1', 'sys_oper_type', '', 'info', 'N', '0', 'admin', '2022-05-29 12:33:45', '', null, '新增操作');
INSERT INTO `sys_dict_data` VALUES ('19', '2', '修改', '2', 'sys_oper_type', '', 'info', 'N', '0', 'admin', '2022-05-29 12:33:45', '', null, '修改操作');
INSERT INTO `sys_dict_data` VALUES ('20', '3', '删除', '3', 'sys_oper_type', '', 'danger', 'N', '0', 'admin', '2022-05-29 12:33:45', '', null, '删除操作');
INSERT INTO `sys_dict_data` VALUES ('21', '4', '授权', '4', 'sys_oper_type', '', 'primary', 'N', '0', 'admin', '2022-05-29 12:33:46', '', null, '授权操作');
INSERT INTO `sys_dict_data` VALUES ('22', '5', '导出', '5', 'sys_oper_type', '', 'warning', 'N', '0', 'admin', '2022-05-29 12:33:46', '', null, '导出操作');
INSERT INTO `sys_dict_data` VALUES ('23', '6', '导入', '6', 'sys_oper_type', '', 'warning', 'N', '0', 'admin', '2022-05-29 12:33:46', '', null, '导入操作');
INSERT INTO `sys_dict_data` VALUES ('24', '7', '强退', '7', 'sys_oper_type', '', 'danger', 'N', '0', 'admin', '2022-05-29 12:33:46', '', null, '强退操作');
INSERT INTO `sys_dict_data` VALUES ('25', '8', '生成代码', '8', 'sys_oper_type', '', 'warning', 'N', '0', 'admin', '2022-05-29 12:33:46', '', null, '生成操作');
INSERT INTO `sys_dict_data` VALUES ('26', '9', '清空数据', '9', 'sys_oper_type', '', 'danger', 'N', '0', 'admin', '2022-05-29 12:33:46', '', null, '清空操作');
INSERT INTO `sys_dict_data` VALUES ('27', '1', '成功', '0', 'sys_common_status', '', 'primary', 'N', '0', 'admin', '2022-05-29 12:33:46', '', null, '正常状态');
INSERT INTO `sys_dict_data` VALUES ('28', '2', '失败', '1', 'sys_common_status', '', 'danger', 'N', '0', 'admin', '2022-05-29 12:33:46', '', null, '停用状态');

-- ----------------------------
-- Table structure for sys_dict_type
-- ----------------------------
DROP TABLE IF EXISTS `sys_dict_type`;
CREATE TABLE `sys_dict_type` (
  `dict_id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '字典主键',
  `dict_name` varchar(100) DEFAULT '' COMMENT '字典名称',
  `dict_type` varchar(100) DEFAULT '' COMMENT '字典类型',
  `status` char(1) DEFAULT '0' COMMENT '状态（0正常 1停用）',
  `create_by` varchar(64) DEFAULT '' COMMENT '创建者',
  `create_time` datetime DEFAULT NULL COMMENT '创建时间',
  `update_by` varchar(64) DEFAULT '' COMMENT '更新者',
  `update_time` datetime DEFAULT NULL COMMENT '更新时间',
  `remark` varchar(500) DEFAULT NULL COMMENT '备注',
  PRIMARY KEY (`dict_id`),
  UNIQUE KEY `dict_type` (`dict_type`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8 COMMENT='字典类型表';

-- ----------------------------
-- Records of sys_dict_type
-- ----------------------------
INSERT INTO `sys_dict_type` VALUES ('1', '用户性别', 'sys_user_sex', '0', 'admin', '2022-05-29 12:33:43', '', null, '用户性别列表');
INSERT INTO `sys_dict_type` VALUES ('2', '菜单状态', 'sys_show_hide', '0', 'admin', '2022-05-29 12:33:43', '', null, '菜单状态列表');
INSERT INTO `sys_dict_type` VALUES ('3', '系统开关', 'sys_normal_disable', '0', 'admin', '2022-05-29 12:33:43', '', null, '系统开关列表');
INSERT INTO `sys_dict_type` VALUES ('4', '任务状态', 'sys_job_status', '0', 'admin', '2022-05-29 12:33:43', '', null, '任务状态列表');
INSERT INTO `sys_dict_type` VALUES ('5', '任务分组', 'sys_job_group', '0', 'admin', '2022-05-29 12:33:43', '', null, '任务分组列表');
INSERT INTO `sys_dict_type` VALUES ('6', '系统是否', 'sys_yes_no', '0', 'admin', '2022-05-29 12:33:43', '', null, '系统是否列表');
INSERT INTO `sys_dict_type` VALUES ('7', '通知类型', 'sys_notice_type', '0', 'admin', '2022-05-29 12:33:43', '', null, '通知类型列表');
INSERT INTO `sys_dict_type` VALUES ('8', '通知状态', 'sys_notice_status', '0', 'admin', '2022-05-29 12:33:43', '', null, '通知状态列表');
INSERT INTO `sys_dict_type` VALUES ('9', '操作类型', 'sys_oper_type', '0', 'admin', '2022-05-29 12:33:44', '', null, '操作类型列表');
INSERT INTO `sys_dict_type` VALUES ('10', '系统状态', 'sys_common_status', '0', 'admin', '2022-05-29 12:33:44', '', null, '登录状态列表');

-- ----------------------------
-- Table structure for sys_job
-- ----------------------------
DROP TABLE IF EXISTS `sys_job`;
CREATE TABLE `sys_job` (
  `job_id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '任务ID',
  `job_name` varchar(64) NOT NULL DEFAULT '' COMMENT '任务名称',
  `job_group` varchar(64) NOT NULL DEFAULT 'DEFAULT' COMMENT '任务组名',
  `invoke_target` varchar(500) NOT NULL COMMENT '调用目标字符串',
  `cron_expression` varchar(255) DEFAULT '' COMMENT 'cron执行表达式',
  `misfire_policy` varchar(20) DEFAULT '3' COMMENT '计划执行错误策略（1立即执行 2执行一次 3放弃执行）',
  `concurrent` char(1) DEFAULT '1' COMMENT '是否并发执行（0允许 1禁止）',
  `status` char(1) DEFAULT '0' COMMENT '状态（0正常 1暂停）',
  `create_by` varchar(64) DEFAULT '' COMMENT '创建者',
  `create_time` datetime DEFAULT NULL COMMENT '创建时间',
  `update_by` varchar(64) DEFAULT '' COMMENT '更新者',
  `update_time` datetime DEFAULT NULL COMMENT '更新时间',
  `remark` varchar(500) DEFAULT '' COMMENT '备注信息',
  PRIMARY KEY (`job_id`,`job_name`,`job_group`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8 COMMENT='定时任务调度表';

-- ----------------------------
-- Records of sys_job
-- ----------------------------
INSERT INTO `sys_job` VALUES ('1', '系统默认（无参）', 'DEFAULT', 'ryTask.ryNoParams', '0/10 * * * * ?', '3', '1', '1', 'admin', '2022-05-29 12:33:47', '', null, '');
INSERT INTO `sys_job` VALUES ('2', '系统默认（有参）', 'DEFAULT', 'ryTask.ryParams(\'ry\')', '0/15 * * * * ?', '3', '1', '1', 'admin', '2022-05-29 12:33:47', '', null, '');
INSERT INTO `sys_job` VALUES ('3', '系统默认（多参）', 'DEFAULT', 'ryTask.ryMultipleParams(\'ry\', true, 2000L, 316.50D, 100)', '0/20 * * * * ?', '3', '1', '1', 'admin', '2022-05-29 12:33:47', '', null, '');

-- ----------------------------
-- Table structure for sys_job_log
-- ----------------------------
DROP TABLE IF EXISTS `sys_job_log`;
CREATE TABLE `sys_job_log` (
  `job_log_id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '任务日志ID',
  `job_name` varchar(64) NOT NULL COMMENT '任务名称',
  `job_group` varchar(64) NOT NULL COMMENT '任务组名',
  `invoke_target` varchar(500) NOT NULL COMMENT '调用目标字符串',
  `job_message` varchar(500) DEFAULT NULL COMMENT '日志信息',
  `status` char(1) DEFAULT '0' COMMENT '执行状态（0正常 1失败）',
  `exception_info` varchar(2000) DEFAULT '' COMMENT '异常信息',
  `create_time` datetime DEFAULT NULL COMMENT '创建时间',
  PRIMARY KEY (`job_log_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='定时任务调度日志表';

-- ----------------------------
-- Records of sys_job_log
-- ----------------------------

-- ----------------------------
-- Table structure for sys_logininfor
-- ----------------------------
DROP TABLE IF EXISTS `sys_logininfor`;
CREATE TABLE `sys_logininfor` (
  `info_id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '访问ID',
  `user_name` varchar(50) DEFAULT '' COMMENT '用户账号',
  `ipaddr` varchar(128) DEFAULT '' COMMENT '登录IP地址',
  `login_location` varchar(255) DEFAULT '' COMMENT '登录地点',
  `browser` varchar(50) DEFAULT '' COMMENT '浏览器类型',
  `os` varchar(50) DEFAULT '' COMMENT '操作系统',
  `status` char(1) DEFAULT '0' COMMENT '登录状态（0成功 1失败）',
  `msg` varchar(255) DEFAULT '' COMMENT '提示消息',
  `login_time` datetime DEFAULT NULL COMMENT '访问时间',
  PRIMARY KEY (`info_id`)
) ENGINE=InnoDB AUTO_INCREMENT=56 DEFAULT CHARSET=utf8 COMMENT='系统访问记录';

-- ----------------------------
-- Records of sys_logininfor
-- ----------------------------
INSERT INTO `sys_logininfor` VALUES ('1', 'aute velit', '112.96.228.54', 'XX XX', 'Unknown', 'Unknown', '1', '验证码已失效', '2022-05-30 16:42:02');
INSERT INTO `sys_logininfor` VALUES ('2', 'admin', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '0', '登录成功', '2022-05-31 02:33:20');
INSERT INTO `sys_logininfor` VALUES ('3', 'admin', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '1', '验证码错误', '2022-05-31 05:39:48');
INSERT INTO `sys_logininfor` VALUES ('4', 'admin', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '0', '登录成功', '2022-05-31 05:40:01');
INSERT INTO `sys_logininfor` VALUES ('5', 'admin', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '0', '退出成功', '2022-05-31 05:56:10');
INSERT INTO `sys_logininfor` VALUES ('6', 'admin', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '1', '验证码错误', '2022-05-31 06:14:46');
INSERT INTO `sys_logininfor` VALUES ('7', 'admin', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '1', '验证码错误', '2022-05-31 06:15:00');
INSERT INTO `sys_logininfor` VALUES ('8', 'admin', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '0', '登录成功', '2022-05-31 06:15:21');
INSERT INTO `sys_logininfor` VALUES ('9', 'admin', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '0', '登录成功', '2022-05-31 06:22:44');
INSERT INTO `sys_logininfor` VALUES ('10', 'admin', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '0', '退出成功', '2022-05-31 06:32:23');
INSERT INTO `sys_logininfor` VALUES ('11', 'zhonhai', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '1', '验证码错误', '2022-05-31 06:32:53');
INSERT INTO `sys_logininfor` VALUES ('12', 'zhonhai', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '0', '登录成功', '2022-05-31 06:33:06');
INSERT INTO `sys_logininfor` VALUES ('13', 'admin', '127.0.0.1', '内网IP', 'Chrome', 'Windows 10', '0', '登录成功', '2022-05-31 06:37:48');
INSERT INTO `sys_logininfor` VALUES ('14', 'admin', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '1', '验证码错误', '2022-05-31 06:45:37');
INSERT INTO `sys_logininfor` VALUES ('15', 'admin', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '1', '验证码错误', '2022-05-31 06:45:56');
INSERT INTO `sys_logininfor` VALUES ('16', 'admin', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '1', '验证码错误', '2022-05-31 06:46:03');
INSERT INTO `sys_logininfor` VALUES ('17', 'admin', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '1', '验证码错误', '2022-05-31 06:46:13');
INSERT INTO `sys_logininfor` VALUES ('18', 'zhonhai', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '0', '退出成功', '2022-05-31 06:46:14');
INSERT INTO `sys_logininfor` VALUES ('19', 'admin', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '1', '验证码错误', '2022-05-31 06:46:22');
INSERT INTO `sys_logininfor` VALUES ('20', 'zhonhai', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '0', '登录成功', '2022-05-31 06:46:24');
INSERT INTO `sys_logininfor` VALUES ('21', 'admin', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '0', '登录成功', '2022-05-31 06:46:31');
INSERT INTO `sys_logininfor` VALUES ('22', 'zhonhai', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '0', '退出成功', '2022-05-31 06:51:14');
INSERT INTO `sys_logininfor` VALUES ('23', 'zhonhai', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '1', '验证码错误', '2022-05-31 06:51:43');
INSERT INTO `sys_logininfor` VALUES ('24', 'zhonhai', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '0', '登录成功', '2022-05-31 06:51:54');
INSERT INTO `sys_logininfor` VALUES ('25', 'admin', '127.0.0.1', '内网IP', 'Chrome 9', 'Windows 10', '0', '登录成功', '2022-05-31 06:52:14');
INSERT INTO `sys_logininfor` VALUES ('26', 'zhonhai', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '1', '验证码错误', '2022-05-31 08:00:13');
INSERT INTO `sys_logininfor` VALUES ('27', 'zhonhai', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '0', '登录成功', '2022-05-31 08:00:19');
INSERT INTO `sys_logininfor` VALUES ('28', 'zhonhai', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '0', '退出成功', '2022-05-31 08:05:39');
INSERT INTO `sys_logininfor` VALUES ('29', 'zhonhai', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '0', '登录成功', '2022-05-31 08:05:43');
INSERT INTO `sys_logininfor` VALUES ('30', 'admin', '127.0.0.1', '内网IP', 'Chrome 9', 'Windows 10', '0', '登录成功', '2022-05-31 08:11:41');
INSERT INTO `sys_logininfor` VALUES ('31', 'admin', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '1', '验证码错误', '2022-05-31 08:13:16');
INSERT INTO `sys_logininfor` VALUES ('32', 'admin', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '0', '登录成功', '2022-05-31 08:13:20');
INSERT INTO `sys_logininfor` VALUES ('33', 'admin', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '0', '登录成功', '2022-05-31 08:29:42');
INSERT INTO `sys_logininfor` VALUES ('34', 'admin', '127.0.0.1', '内网IP', 'Chrome 9', 'Windows 10', '0', '登录成功', '2022-05-31 08:39:28');
INSERT INTO `sys_logininfor` VALUES ('35', 'admin', '127.0.0.1', '内网IP', 'Chrome', 'Windows 10', '1', '验证码已失效', '2022-05-31 11:07:51');
INSERT INTO `sys_logininfor` VALUES ('36', 'admin', '127.0.0.1', '内网IP', 'Chrome', 'Windows 10', '0', '登录成功', '2022-05-31 11:07:59');
INSERT INTO `sys_logininfor` VALUES ('37', 'zhonhai', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '0', '登录成功', '2022-05-31 11:12:19');
INSERT INTO `sys_logininfor` VALUES ('38', 'admin', '127.0.0.1', '内网IP', 'Chrome 9', 'Windows 10', '0', '登录成功', '2022-06-01 01:22:14');
INSERT INTO `sys_logininfor` VALUES ('39', 'admin', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '0', '登录成功', '2022-06-01 01:22:40');
INSERT INTO `sys_logininfor` VALUES ('40', 'admin', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '0', '登录成功', '2022-06-01 02:30:50');
INSERT INTO `sys_logininfor` VALUES ('41', 'admin', '127.0.0.1', '内网IP', 'Chrome 9', 'Windows 10', '0', '登录成功', '2022-06-01 02:36:51');
INSERT INTO `sys_logininfor` VALUES ('42', 'o4THO4n60CTl5rY55cvuVfz-V5cY', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '0', '登录成功', '2022-06-01 03:37:04');
INSERT INTO `sys_logininfor` VALUES ('43', 'o4THO4n60CTl5rY55cvuVfz-V5cY', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '0', '退出成功', '2022-06-01 03:37:11');
INSERT INTO `sys_logininfor` VALUES ('44', 'admin', '127.0.0.1', '内网IP', 'Chrome 9', 'Windows 10', '0', '登录成功', '2022-06-01 05:34:51');
INSERT INTO `sys_logininfor` VALUES ('45', 'admin', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '0', '登录成功', '2022-06-01 06:02:27');
INSERT INTO `sys_logininfor` VALUES ('46', 'admin', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '0', '登录成功', '2022-06-01 06:24:47');
INSERT INTO `sys_logininfor` VALUES ('47', 'admin', '127.0.0.1', '内网IP', 'Chrome 9', 'Windows 10', '0', '登录成功', '2022-06-01 06:50:34');
INSERT INTO `sys_logininfor` VALUES ('48', 'admin', '127.0.0.1', '内网IP', 'Chrome 9', 'Windows 10', '0', '登录成功', '2022-06-01 08:45:36');
INSERT INTO `sys_logininfor` VALUES ('49', 'admin', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '0', '登录成功', '2022-06-01 10:26:16');
INSERT INTO `sys_logininfor` VALUES ('50', 'admin', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '0', '退出成功', '2022-06-01 11:51:19');
INSERT INTO `sys_logininfor` VALUES ('51', 'admin', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '0', '登录成功', '2022-06-02 01:10:15');
INSERT INTO `sys_logininfor` VALUES ('52', 'admin', '183.14.28.13', 'XX XX', 'Internet Explorer 11', 'Windows 10', '0', '登录成功', '2022-06-02 01:54:26');
INSERT INTO `sys_logininfor` VALUES ('53', 'admin', '183.14.28.13', 'XX XX', 'Chrome 9', 'Windows 10', '0', '登录成功', '2022-06-02 01:56:58');
INSERT INTO `sys_logininfor` VALUES ('54', 'admin', '127.0.0.1', '内网IP', 'Chrome 9', 'Windows 10', '0', '登录成功', '2022-06-02 01:58:24');
INSERT INTO `sys_logininfor` VALUES ('55', 'admin', '127.0.0.1', '内网IP', 'Chrome 10', 'Windows 10', '0', '登录成功', '2022-06-02 02:05:21');

-- ----------------------------
-- Table structure for sys_menu
-- ----------------------------
DROP TABLE IF EXISTS `sys_menu`;
CREATE TABLE `sys_menu` (
  `menu_id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '菜单ID',
  `menu_name` varchar(50) NOT NULL COMMENT '菜单名称',
  `parent_id` bigint(20) DEFAULT '0' COMMENT '父菜单ID',
  `order_num` int(4) DEFAULT '0' COMMENT '显示顺序',
  `path` varchar(200) DEFAULT '' COMMENT '路由地址',
  `component` varchar(255) DEFAULT NULL COMMENT '组件路径',
  `query` varchar(255) DEFAULT NULL COMMENT '路由参数',
  `is_frame` int(1) DEFAULT '1' COMMENT '是否为外链（0是 1否）',
  `is_cache` int(1) DEFAULT '0' COMMENT '是否缓存（0缓存 1不缓存）',
  `menu_type` char(1) DEFAULT '' COMMENT '菜单类型（M目录 C菜单 F按钮）',
  `visible` char(1) DEFAULT '0' COMMENT '菜单状态（0显示 1隐藏）',
  `status` char(1) DEFAULT '0' COMMENT '菜单状态（0正常 1停用）',
  `perms` varchar(100) DEFAULT NULL COMMENT '权限标识',
  `icon` varchar(100) DEFAULT '#' COMMENT '菜单图标',
  `create_by` varchar(64) DEFAULT '' COMMENT '创建者',
  `create_time` datetime DEFAULT NULL COMMENT '创建时间',
  `update_by` varchar(64) DEFAULT '' COMMENT '更新者',
  `update_time` datetime DEFAULT NULL COMMENT '更新时间',
  `remark` varchar(500) DEFAULT '' COMMENT '备注',
  PRIMARY KEY (`menu_id`)
) ENGINE=InnoDB AUTO_INCREMENT=1086 DEFAULT CHARSET=utf8 COMMENT='菜单权限表';

-- ----------------------------
-- Records of sys_menu
-- ----------------------------
INSERT INTO `sys_menu` VALUES ('1', '设置', '0', '11', 'system', null, '', '1', '0', 'M', '0', '0', '', 'system', 'admin', '2022-05-29 12:33:28', 'admin', '2022-06-01 07:58:36', '系统管理目录');
INSERT INTO `sys_menu` VALUES ('2', '系统监控', '0', '2', 'monitor', null, '', '1', '0', 'M', '1', '1', '', 'monitor', 'admin', '2022-05-29 12:33:28', 'admin', '2022-06-02 02:16:20', '系统监控目录');
INSERT INTO `sys_menu` VALUES ('100', '用户管理', '1', '1', 'user', 'system/user/index', '', '1', '0', 'C', '0', '0', 'system:user:list', 'user', 'admin', '2022-05-29 12:33:28', '', null, '用户管理菜单');
INSERT INTO `sys_menu` VALUES ('101', '角色管理', '1', '2', 'role', 'system/role/index', '', '1', '0', 'C', '0', '0', 'system:role:list', 'peoples', 'admin', '2022-05-29 12:33:28', '', null, '角色管理菜单');
INSERT INTO `sys_menu` VALUES ('102', '菜单管理', '1', '3', 'menu', 'system/menu/index', '', '1', '0', 'C', '0', '0', 'system:menu:list', 'tree-table', 'admin', '2022-05-29 12:33:28', '', null, '菜单管理菜单');
INSERT INTO `sys_menu` VALUES ('103', '部门管理', '1', '4', 'dept', 'system/dept/index', '', '1', '0', 'C', '0', '0', 'system:dept:list', 'tree', 'admin', '2022-05-29 12:33:28', '', null, '部门管理菜单');
INSERT INTO `sys_menu` VALUES ('104', '岗位管理', '1', '5', 'post', 'system/post/index', '', '1', '0', 'C', '1', '0', 'system:post:list', 'post', 'admin', '2022-05-29 12:33:28', 'admin', '2022-06-01 07:55:56', '岗位管理菜单');
INSERT INTO `sys_menu` VALUES ('105', '字典管理', '1', '6', 'dict', 'system/dict/index', '', '1', '0', 'C', '1', '0', 'system:dict:list', 'dict', 'admin', '2022-05-29 12:33:28', 'admin', '2022-06-01 07:55:00', '字典管理菜单');
INSERT INTO `sys_menu` VALUES ('106', '参数设置', '1', '7', 'config', 'system/config/index', '', '1', '0', 'C', '1', '0', 'system:config:list', 'edit', 'admin', '2022-05-29 12:33:28', 'admin', '2022-06-01 07:54:52', '参数设置菜单');
INSERT INTO `sys_menu` VALUES ('107', '通知公告', '1', '8', 'notice', 'system/notice/index', '', '1', '0', 'C', '1', '0', 'system:notice:list', 'message', 'admin', '2022-05-29 12:33:29', 'admin', '2022-06-01 07:54:44', '通知公告菜单');
INSERT INTO `sys_menu` VALUES ('108', '日志管理', '1', '9', 'log', '', '', '1', '0', 'M', '1', '0', '', 'log', 'admin', '2022-05-29 12:33:29', 'admin', '2022-06-01 07:54:28', '日志管理菜单');
INSERT INTO `sys_menu` VALUES ('109', '在线用户', '2', '1', 'online', 'monitor/online/index', '', '1', '0', 'C', '0', '0', 'monitor:online:list', 'online', 'admin', '2022-05-29 12:33:29', '', null, '在线用户菜单');
INSERT INTO `sys_menu` VALUES ('111', '数据监控', '2', '3', 'druid', 'monitor/druid/index', '', '1', '0', 'C', '0', '0', 'monitor:druid:list', 'druid', 'admin', '2022-05-29 12:33:29', '', null, '数据监控菜单');
INSERT INTO `sys_menu` VALUES ('112', '服务监控', '2', '4', 'server', 'monitor/server/index', '', '1', '0', 'C', '0', '0', 'monitor:server:list', 'server', 'admin', '2022-05-29 12:33:29', '', null, '服务监控菜单');
INSERT INTO `sys_menu` VALUES ('113', '缓存监控', '2', '5', 'cache', 'monitor/cache/index', '', '1', '0', 'C', '0', '0', 'monitor:cache:list', 'redis', 'admin', '2022-05-29 12:33:29', '', null, '缓存监控菜单');
INSERT INTO `sys_menu` VALUES ('500', '操作日志', '108', '1', 'operlog', 'monitor/operlog/index', '', '1', '0', 'C', '0', '0', 'monitor:operlog:list', 'form', 'admin', '2022-05-29 12:33:29', '', null, '操作日志菜单');
INSERT INTO `sys_menu` VALUES ('501', '登录日志', '108', '2', 'logininfor', 'monitor/logininfor/index', '', '1', '0', 'C', '0', '0', 'monitor:logininfor:list', 'logininfor', 'admin', '2022-05-29 12:33:29', '', null, '登录日志菜单');
INSERT INTO `sys_menu` VALUES ('1001', '用户查询', '100', '1', '', '', '', '1', '0', 'F', '0', '0', 'system:user:query', '#', 'admin', '2022-05-29 12:33:30', '', null, '');
INSERT INTO `sys_menu` VALUES ('1002', '用户新增', '100', '2', '', '', '', '1', '0', 'F', '0', '0', 'system:user:add', '#', 'admin', '2022-05-29 12:33:30', 'zhonhai', '2022-05-31 07:01:44', '');
INSERT INTO `sys_menu` VALUES ('1003', '用户修改', '100', '3', '', '', '', '1', '0', 'F', '0', '0', 'system:user:edit', '#', 'admin', '2022-05-29 12:33:30', '', null, '');
INSERT INTO `sys_menu` VALUES ('1004', '用户删除', '100', '4', '', '', '', '1', '0', 'F', '0', '0', 'system:user:remove', '#', 'admin', '2022-05-29 12:33:30', '', null, '');
INSERT INTO `sys_menu` VALUES ('1005', '用户导出', '100', '5', '', '', '', '1', '0', 'F', '0', '0', 'system:user:export', '#', 'admin', '2022-05-29 12:33:30', '', null, '');
INSERT INTO `sys_menu` VALUES ('1006', '用户导入', '100', '6', '', '', '', '1', '0', 'F', '0', '0', 'system:user:import', '#', 'admin', '2022-05-29 12:33:30', '', null, '');
INSERT INTO `sys_menu` VALUES ('1007', '重置密码', '100', '7', '', '', '', '1', '0', 'F', '0', '0', 'system:user:resetPwd', '#', 'admin', '2022-05-29 12:33:30', '', null, '');
INSERT INTO `sys_menu` VALUES ('1008', '角色查询', '101', '1', '', '', '', '1', '0', 'F', '0', '0', 'system:role:query', '#', 'admin', '2022-05-29 12:33:30', '', null, '');
INSERT INTO `sys_menu` VALUES ('1009', '角色新增', '101', '2', '', '', '', '1', '0', 'F', '0', '0', 'system:role:add', '#', 'admin', '2022-05-29 12:33:30', '', null, '');
INSERT INTO `sys_menu` VALUES ('1010', '角色修改', '101', '3', '', '', '', '1', '0', 'F', '0', '0', 'system:role:edit', '#', 'admin', '2022-05-29 12:33:30', '', null, '');
INSERT INTO `sys_menu` VALUES ('1011', '角色删除', '101', '4', '', '', '', '1', '0', 'F', '0', '0', 'system:role:remove', '#', 'admin', '2022-05-29 12:33:30', '', null, '');
INSERT INTO `sys_menu` VALUES ('1012', '角色导出', '101', '5', '', '', '', '1', '0', 'F', '0', '0', 'system:role:export', '#', 'admin', '2022-05-29 12:33:30', '', null, '');
INSERT INTO `sys_menu` VALUES ('1013', '菜单查询', '102', '1', '', '', '', '1', '0', 'F', '0', '0', 'system:menu:query', '#', 'admin', '2022-05-29 12:33:31', '', null, '');
INSERT INTO `sys_menu` VALUES ('1014', '菜单新增', '102', '2', '', '', '', '1', '0', 'F', '0', '0', 'system:menu:add', '#', 'admin', '2022-05-29 12:33:31', '', null, '');
INSERT INTO `sys_menu` VALUES ('1015', '菜单修改', '102', '3', '', '', '', '1', '0', 'F', '0', '0', 'system:menu:edit', '#', 'admin', '2022-05-29 12:33:31', '', null, '');
INSERT INTO `sys_menu` VALUES ('1016', '菜单删除', '102', '4', '', '', '', '1', '0', 'F', '0', '0', 'system:menu:remove', '#', 'admin', '2022-05-29 12:33:31', '', null, '');
INSERT INTO `sys_menu` VALUES ('1017', '部门查询', '103', '1', '', '', '', '1', '0', 'F', '0', '0', 'system:dept:query', '#', 'admin', '2022-05-29 12:33:31', '', null, '');
INSERT INTO `sys_menu` VALUES ('1018', '部门新增', '103', '2', '', '', '', '1', '0', 'F', '0', '0', 'system:dept:add', '#', 'admin', '2022-05-29 12:33:31', '', null, '');
INSERT INTO `sys_menu` VALUES ('1019', '部门修改', '103', '3', '', '', '', '1', '0', 'F', '0', '0', 'system:dept:edit', '#', 'admin', '2022-05-29 12:33:31', '', null, '');
INSERT INTO `sys_menu` VALUES ('1020', '部门删除', '103', '4', '', '', '', '1', '0', 'F', '0', '0', 'system:dept:remove', '#', 'admin', '2022-05-29 12:33:31', '', null, '');
INSERT INTO `sys_menu` VALUES ('1021', '岗位查询', '104', '1', '', '', '', '1', '0', 'F', '0', '0', 'system:post:query', '#', 'admin', '2022-05-29 12:33:31', '', null, '');
INSERT INTO `sys_menu` VALUES ('1022', '岗位新增', '104', '2', '', '', '', '1', '0', 'F', '0', '0', 'system:post:add', '#', 'admin', '2022-05-29 12:33:31', '', null, '');
INSERT INTO `sys_menu` VALUES ('1023', '岗位修改', '104', '3', '', '', '', '1', '0', 'F', '0', '0', 'system:post:edit', '#', 'admin', '2022-05-29 12:33:31', '', null, '');
INSERT INTO `sys_menu` VALUES ('1024', '岗位删除', '104', '4', '', '', '', '1', '0', 'F', '0', '0', 'system:post:remove', '#', 'admin', '2022-05-29 12:33:31', '', null, '');
INSERT INTO `sys_menu` VALUES ('1025', '岗位导出', '104', '5', '', '', '', '1', '0', 'F', '0', '0', 'system:post:export', '#', 'admin', '2022-05-29 12:33:32', '', null, '');
INSERT INTO `sys_menu` VALUES ('1026', '字典查询', '105', '1', '#', '', '', '1', '0', 'F', '0', '0', 'system:dict:query', '#', 'admin', '2022-05-29 12:33:32', '', null, '');
INSERT INTO `sys_menu` VALUES ('1027', '字典新增', '105', '2', '#', '', '', '1', '0', 'F', '0', '0', 'system:dict:add', '#', 'admin', '2022-05-29 12:33:32', '', null, '');
INSERT INTO `sys_menu` VALUES ('1028', '字典修改', '105', '3', '#', '', '', '1', '0', 'F', '0', '0', 'system:dict:edit', '#', 'admin', '2022-05-29 12:33:32', '', null, '');
INSERT INTO `sys_menu` VALUES ('1029', '字典删除', '105', '4', '#', '', '', '1', '0', 'F', '0', '0', 'system:dict:remove', '#', 'admin', '2022-05-29 12:33:32', '', null, '');
INSERT INTO `sys_menu` VALUES ('1030', '字典导出', '105', '5', '#', '', '', '1', '0', 'F', '0', '0', 'system:dict:export', '#', 'admin', '2022-05-29 12:33:32', '', null, '');
INSERT INTO `sys_menu` VALUES ('1031', '参数查询', '106', '1', '#', '', '', '1', '0', 'F', '0', '0', 'system:config:query', '#', 'admin', '2022-05-29 12:33:32', '', null, '');
INSERT INTO `sys_menu` VALUES ('1032', '参数新增', '106', '2', '#', '', '', '1', '0', 'F', '0', '0', 'system:config:add', '#', 'admin', '2022-05-29 12:33:32', '', null, '');
INSERT INTO `sys_menu` VALUES ('1033', '参数修改', '106', '3', '#', '', '', '1', '0', 'F', '0', '0', 'system:config:edit', '#', 'admin', '2022-05-29 12:33:32', '', null, '');
INSERT INTO `sys_menu` VALUES ('1034', '参数删除', '106', '4', '#', '', '', '1', '0', 'F', '0', '0', 'system:config:remove', '#', 'admin', '2022-05-29 12:33:32', '', null, '');
INSERT INTO `sys_menu` VALUES ('1035', '参数导出', '106', '5', '#', '', '', '1', '0', 'F', '0', '0', 'system:config:export', '#', 'admin', '2022-05-29 12:33:32', '', null, '');
INSERT INTO `sys_menu` VALUES ('1036', '公告查询', '107', '1', '#', '', '', '1', '0', 'F', '0', '0', 'system:notice:query', '#', 'admin', '2022-05-29 12:33:32', '', null, '');
INSERT INTO `sys_menu` VALUES ('1037', '公告新增', '107', '2', '#', '', '', '1', '0', 'F', '0', '0', 'system:notice:add', '#', 'admin', '2022-05-29 12:33:32', '', null, '');
INSERT INTO `sys_menu` VALUES ('1038', '公告修改', '107', '3', '#', '', '', '1', '0', 'F', '0', '0', 'system:notice:edit', '#', 'admin', '2022-05-29 12:33:33', '', null, '');
INSERT INTO `sys_menu` VALUES ('1039', '公告删除', '107', '4', '#', '', '', '1', '0', 'F', '0', '0', 'system:notice:remove', '#', 'admin', '2022-05-29 12:33:33', '', null, '');
INSERT INTO `sys_menu` VALUES ('1040', '操作查询', '500', '1', '#', '', '', '1', '0', 'F', '0', '0', 'monitor:operlog:query', '#', 'admin', '2022-05-29 12:33:33', '', null, '');
INSERT INTO `sys_menu` VALUES ('1041', '操作删除', '500', '2', '#', '', '', '1', '0', 'F', '0', '0', 'monitor:operlog:remove', '#', 'admin', '2022-05-29 12:33:33', '', null, '');
INSERT INTO `sys_menu` VALUES ('1042', '日志导出', '500', '4', '#', '', '', '1', '0', 'F', '0', '0', 'monitor:operlog:export', '#', 'admin', '2022-05-29 12:33:33', '', null, '');
INSERT INTO `sys_menu` VALUES ('1043', '登录查询', '501', '1', '#', '', '', '1', '0', 'F', '0', '0', 'monitor:logininfor:query', '#', 'admin', '2022-05-29 12:33:33', '', null, '');
INSERT INTO `sys_menu` VALUES ('1044', '登录删除', '501', '2', '#', '', '', '1', '0', 'F', '0', '0', 'monitor:logininfor:remove', '#', 'admin', '2022-05-29 12:33:33', '', null, '');
INSERT INTO `sys_menu` VALUES ('1045', '日志导出', '501', '3', '#', '', '', '1', '0', 'F', '0', '0', 'monitor:logininfor:export', '#', 'admin', '2022-05-29 12:33:33', '', null, '');
INSERT INTO `sys_menu` VALUES ('1046', '在线查询', '109', '1', '#', '', '', '1', '0', 'F', '0', '0', 'monitor:online:query', '#', 'admin', '2022-05-29 12:33:33', '', null, '');
INSERT INTO `sys_menu` VALUES ('1047', '批量强退', '109', '2', '#', '', '', '1', '0', 'F', '0', '0', 'monitor:online:batchLogout', '#', 'admin', '2022-05-29 12:33:33', '', null, '');
INSERT INTO `sys_menu` VALUES ('1048', '单条强退', '109', '3', '#', '', '', '1', '0', 'F', '0', '0', 'monitor:online:forceLogout', '#', 'admin', '2022-05-29 12:33:33', '', null, '');
INSERT INTO `sys_menu` VALUES ('1049', '任务查询', '110', '1', '#', '', '', '1', '0', 'F', '0', '0', 'monitor:job:query', '#', 'admin', '2022-05-29 12:33:33', '', null, '');
INSERT INTO `sys_menu` VALUES ('1050', '任务新增', '110', '2', '#', '', '', '1', '0', 'F', '0', '0', 'monitor:job:add', '#', 'admin', '2022-05-29 12:33:34', '', null, '');
INSERT INTO `sys_menu` VALUES ('1051', '任务修改', '110', '3', '#', '', '', '1', '0', 'F', '0', '0', 'monitor:job:edit', '#', 'admin', '2022-05-29 12:33:34', '', null, '');
INSERT INTO `sys_menu` VALUES ('1052', '任务删除', '110', '4', '#', '', '', '1', '0', 'F', '0', '0', 'monitor:job:remove', '#', 'admin', '2022-05-29 12:33:34', '', null, '');
INSERT INTO `sys_menu` VALUES ('1053', '状态修改', '110', '5', '#', '', '', '1', '0', 'F', '0', '0', 'monitor:job:changeStatus', '#', 'admin', '2022-05-29 12:33:34', '', null, '');
INSERT INTO `sys_menu` VALUES ('1054', '任务导出', '110', '7', '#', '', '', '1', '0', 'F', '0', '0', 'monitor:job:export', '#', 'admin', '2022-05-29 12:33:34', '', null, '');
INSERT INTO `sys_menu` VALUES ('1055', '生成查询', '115', '1', '#', '', '', '1', '0', 'F', '0', '0', 'tool:gen:query', '#', 'admin', '2022-05-29 12:33:34', '', null, '');
INSERT INTO `sys_menu` VALUES ('1056', '生成修改', '115', '2', '#', '', '', '1', '0', 'F', '0', '0', 'tool:gen:edit', '#', 'admin', '2022-05-29 12:33:34', '', null, '');
INSERT INTO `sys_menu` VALUES ('1057', '生成删除', '115', '3', '#', '', '', '1', '0', 'F', '0', '0', 'tool:gen:remove', '#', 'admin', '2022-05-29 12:33:34', '', null, '');
INSERT INTO `sys_menu` VALUES ('1058', '导入代码', '115', '2', '#', '', '', '1', '0', 'F', '0', '0', 'tool:gen:import', '#', 'admin', '2022-05-29 12:33:34', '', null, '');
INSERT INTO `sys_menu` VALUES ('1059', '预览代码', '115', '4', '#', '', '', '1', '0', 'F', '0', '0', 'tool:gen:preview', '#', 'admin', '2022-05-29 12:33:34', '', null, '');
INSERT INTO `sys_menu` VALUES ('1060', '生成代码', '115', '5', '#', '', '', '1', '0', 'F', '0', '0', 'tool:gen:code', '#', 'admin', '2022-05-29 12:33:34', '', null, '');
INSERT INTO `sys_menu` VALUES ('1061', '事务管理', '0', '2', 'affairManage', null, null, '1', '0', 'M', '0', '0', '', 'documentation', 'admin', '2022-06-01 06:30:15', 'admin', '2022-06-01 08:28:42', '');
INSERT INTO `sys_menu` VALUES ('1062', '请假', '1061', '1', 'askForLeave', 'affairManage/askForLeave/index', null, '1', '0', 'C', '0', '0', '', 'date-range', 'admin', '2022-06-01 06:31:44', 'admin', '2022-06-01 06:56:42', '');
INSERT INTO `sys_menu` VALUES ('1063', '物资申购', '1061', '2', 'materialPurchase', 'affairManage/materialPurchase/index', null, '1', '0', 'C', '0', '0', '', 'money', 'admin', '2022-06-01 06:33:54', 'admin', '2022-06-01 08:40:11', '');
INSERT INTO `sys_menu` VALUES ('1064', '领用', '1061', '3', 'receiving', 'affairManage/receiving/index', null, '1', '0', 'C', '0', '0', '', 'cascader', 'admin', '2022-06-01 06:34:40', 'admin', '2022-06-01 07:00:43', '');
INSERT INTO `sys_menu` VALUES ('1065', '报修', '1061', '4', 'repairRequest', 'affairManage/repairRequest/index', null, '1', '0', 'C', '0', '0', '', 'clipboard', 'admin', '2022-06-01 06:35:40', 'admin', '2022-06-01 06:58:22', '');
INSERT INTO `sys_menu` VALUES ('1066', '考勤', '0', '3', 'checkWork', '', null, '1', '0', 'M', '0', '0', '', 'documentation', 'admin', '2022-06-01 06:37:34', 'admin', '2022-06-01 08:28:48', '');
INSERT INTO `sys_menu` VALUES ('1067', '教工考勤', '1066', '1', 'teachinStaff', 'checkWork/teachinStaff/index', null, '1', '0', 'C', '0', '0', '', 'druid', 'admin', '2022-06-01 06:39:46', 'admin', '2022-06-01 07:30:03', '');
INSERT INTO `sys_menu` VALUES ('1068', '宝贝考勤', '1066', '2', 'babyWork', 'checkWork/babyWork/index', null, '1', '0', 'C', '0', '0', '', 'user', 'admin', '2022-06-01 07:03:51', 'admin', '2022-06-01 08:40:36', '');
INSERT INTO `sys_menu` VALUES ('1069', '安全管理', '0', '5', 'saftyManage', null, null, '1', '0', 'M', '0', '0', '', 'documentation', 'admin', '2022-06-01 07:05:23', 'admin', '2022-06-01 08:28:56', '');
INSERT INTO `sys_menu` VALUES ('1070', '消防检查', '1069', '1', 'fireCheck', 'saftyManage/fireCheck/index', null, '1', '0', 'C', '0', '0', null, 'date-range', 'admin', '2022-06-01 07:07:09', '', null, '');
INSERT INTO `sys_menu` VALUES ('1071', '安防巡查', '1069', '2', 'securityPatrol', 'saftyManage/securityPatrol/index', null, '1', '0', 'C', '0', '0', '', 'dict', 'admin', '2022-06-01 07:13:23', 'admin', '2022-06-01 08:41:35', '');
INSERT INTO `sys_menu` VALUES ('1072', '食品安全', '1069', '3', 'goodSafty', 'saftyManage/goodSafty/index', null, '1', '0', 'C', '0', '0', '', 'international', 'admin', '2022-06-01 07:15:34', 'admin', '2022-06-01 08:41:52', '');
INSERT INTO `sys_menu` VALUES ('1073', '防疫', '1069', '4', 'epidemicPrevention', 'saftyManage/epidemicPrevention/index', null, '1', '0', 'C', '0', '0', '', 'phone', 'admin', '2022-06-01 07:16:19', 'admin', '2022-06-01 08:42:01', '');
INSERT INTO `sys_menu` VALUES ('1074', '园所信息', '0', '6', 'parkInformation', null, null, '1', '0', 'M', '0', '0', '', 'documentation', 'admin', '2022-06-01 07:33:39', 'admin', '2022-06-01 08:29:04', '');
INSERT INTO `sys_menu` VALUES ('1075', '部门管理', '1074', '1', 'departmentManagement', 'parkInformation/departmentManagement/index', null, '1', '0', 'C', '0', '0', '', 'row', 'admin', '2022-06-01 07:37:47', 'admin', '2022-06-01 08:42:18', '');
INSERT INTO `sys_menu` VALUES ('1076', '班级管理', '1074', '2', 'classManage', 'parkInformation/classManage/index', null, '1', '0', 'C', '0', '0', '', 'redis', 'admin', '2022-06-01 07:38:40', 'admin', '2022-06-01 08:42:27', '');
INSERT INTO `sys_menu` VALUES ('1077', '后勤管理', '0', '7', 'logisticsManage', null, null, '1', '0', 'M', '0', '0', '', 'documentation', 'admin', '2022-06-01 07:40:02', 'admin', '2022-06-01 08:29:12', '');
INSERT INTO `sys_menu` VALUES ('1078', '厨房', '1077', '1', 'kitchen', 'logisticsManage/kitchen/index', null, '1', '0', 'C', '0', '0', '', 'log', 'admin', '2022-06-01 07:40:48', 'admin', '2022-06-01 08:42:39', '');
INSERT INTO `sys_menu` VALUES ('1079', '仓库', '1077', '2', 'warehouse', 'logisticsManage/warehouse/index', null, '1', '0', 'C', '0', '0', '', 'log', 'admin', '2022-06-01 07:42:43', 'admin', '2022-06-01 08:42:49', '');
INSERT INTO `sys_menu` VALUES ('1080', '固定资产', '1077', '3', 'fixedAssets', 'logisticsManage/fixedAssets/index', null, '1', '0', 'C', '0', '0', '', 'money', 'admin', '2022-06-01 07:44:16', 'admin', '2022-06-01 08:43:05', '');
INSERT INTO `sys_menu` VALUES ('1081', '财务管理', '0', '8', 'financeManage', null, null, '1', '0', 'M', '0', '0', '', 'documentation', 'admin', '2022-06-01 07:45:28', 'admin', '2022-06-01 07:51:40', '');
INSERT INTO `sys_menu` VALUES ('1082', '账单管理', '1081', '1', 'billManage', 'financeManage/billManage/index', null, '1', '0', 'C', '0', '0', '', 'message', 'admin', '2022-06-01 07:46:32', 'admin', '2022-06-01 08:43:35', '');
INSERT INTO `sys_menu` VALUES ('1083', '收费项目', '1081', '2', 'payService', 'financeManage/payService/index', null, '1', '0', 'C', '0', '0', '', 'list', 'admin', '2022-06-01 07:48:29', 'admin', '2022-06-01 08:43:47', '');
INSERT INTO `sys_menu` VALUES ('1084', '活动', '0', '9', 'activity', null, null, '1', '0', 'M', '0', '0', null, 'documentation', 'admin', '2022-06-01 07:52:25', '', null, '');
INSERT INTO `sys_menu` VALUES ('1085', '档案管理', '0', '10', 'fileManagement', null, null, '1', '0', 'M', '0', '0', null, 'documentation', 'admin', '2022-06-01 07:53:30', '', null, '');

-- ----------------------------
-- Table structure for sys_notice
-- ----------------------------
DROP TABLE IF EXISTS `sys_notice`;
CREATE TABLE `sys_notice` (
  `notice_id` int(4) NOT NULL AUTO_INCREMENT COMMENT '公告ID',
  `notice_title` varchar(50) NOT NULL COMMENT '公告标题',
  `notice_type` char(1) NOT NULL COMMENT '公告类型（1通知 2公告）',
  `notice_content` longblob COMMENT '公告内容',
  `status` char(1) DEFAULT '0' COMMENT '公告状态（0正常 1关闭）',
  `create_by` varchar(64) DEFAULT '' COMMENT '创建者',
  `create_time` datetime DEFAULT NULL COMMENT '创建时间',
  `update_by` varchar(64) DEFAULT '' COMMENT '更新者',
  `update_time` datetime DEFAULT NULL COMMENT '更新时间',
  `remark` varchar(255) DEFAULT NULL COMMENT '备注',
  PRIMARY KEY (`notice_id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 COMMENT='通知公告表';

-- ----------------------------
-- Records of sys_notice
-- ----------------------------
INSERT INTO `sys_notice` VALUES ('1', '温馨提醒：2018-07-01 若依新版本发布啦', '2', 0xE696B0E78988E69CACE58685E5AEB9, '0', 'admin', '2022-05-29 12:33:48', '', null, '管理员');
INSERT INTO `sys_notice` VALUES ('2', '维护通知：2018-07-01 若依系统凌晨维护', '1', 0xE7BBB4E68AA4E58685E5AEB9, '0', 'admin', '2022-05-29 12:33:48', '', null, '管理员');

-- ----------------------------
-- Table structure for sys_oper_log
-- ----------------------------
DROP TABLE IF EXISTS `sys_oper_log`;
CREATE TABLE `sys_oper_log` (
  `oper_id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '日志主键',
  `title` varchar(50) DEFAULT '' COMMENT '模块标题',
  `business_type` int(2) DEFAULT '0' COMMENT '业务类型（0其它 1新增 2修改 3删除）',
  `method` varchar(100) DEFAULT '' COMMENT '方法名称',
  `request_method` varchar(10) DEFAULT '' COMMENT '请求方式',
  `operator_type` int(1) DEFAULT '0' COMMENT '操作类别（0其它 1后台用户 2手机端用户）',
  `oper_name` varchar(50) DEFAULT '' COMMENT '操作人员',
  `dept_name` varchar(50) DEFAULT '' COMMENT '部门名称',
  `oper_url` varchar(255) DEFAULT '' COMMENT '请求URL',
  `oper_ip` varchar(128) DEFAULT '' COMMENT '主机地址',
  `oper_location` varchar(255) DEFAULT '' COMMENT '操作地点',
  `oper_param` varchar(2000) DEFAULT '' COMMENT '请求参数',
  `json_result` varchar(2000) DEFAULT '' COMMENT '返回参数',
  `status` int(1) DEFAULT '0' COMMENT '操作状态（0正常 1异常）',
  `error_msg` varchar(2000) DEFAULT '' COMMENT '错误消息',
  `oper_time` datetime DEFAULT NULL COMMENT '操作时间',
  PRIMARY KEY (`oper_id`)
) ENGINE=InnoDB AUTO_INCREMENT=127 DEFAULT CHARSET=utf8 COMMENT='操作日志记录';

-- ----------------------------
-- Records of sys_oper_log
-- ----------------------------
INSERT INTO `sys_oper_log` VALUES ('1', '用户管理', '4', 'com.ibotn.web.controller.system.SysUserController.insertAuthRole()', 'PUT', '1', 'admin', null, '/system/user/authRole', '127.0.0.1', '内网IP', '2 []', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-05-31 06:26:41');
INSERT INTO `sys_oper_log` VALUES ('2', '用户管理', '4', 'com.ibotn.web.controller.system.SysUserController.insertAuthRole()', 'PUT', '1', 'admin', null, '/system/user/authRole', '127.0.0.1', '内网IP', '2 [2]', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-05-31 06:27:08');
INSERT INTO `sys_oper_log` VALUES ('3', '用户管理', '1', 'com.ibotn.web.controller.system.SysUserController.add()', 'POST', '1', 'admin', null, '/system/user', '127.0.0.1', '内网IP', '{\"admin\":false,\"deptId\":100,\"nickName\":\"zhonhai\",\"params\":{},\"password\":\"admin123\",\"phonenumber\":\"18126495953\",\"postIds\":[1],\"remark\":\"我是钟海\",\"roleIds\":[],\"sex\":\"0\",\"status\":\"0\",\"userName\":\"admin\"}', '{\"msg\":\"新增用户\'admin\'失败，登录账号已存在\",\"code\":500}', '0', null, '2022-05-31 06:30:27');
INSERT INTO `sys_oper_log` VALUES ('4', '用户管理', '1', 'com.ibotn.web.controller.system.SysUserController.add()', 'POST', '1', 'admin', null, '/system/user', '127.0.0.1', '内网IP', '{\"admin\":false,\"createBy\":\"admin\",\"deptId\":100,\"nickName\":\"zhonhai\",\"params\":{},\"password\":\"$2a$10$SGoKF6OshF4617jQvI.GreMV12Z1i2PhT9oTl3ZrN88UNMTienJge\",\"phonenumber\":\"18126495953\",\"postIds\":[1],\"remark\":\"我是钟海\",\"roleIds\":[],\"sex\":\"0\",\"status\":\"0\",\"userId\":3,\"userName\":\"zhonhai\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-05-31 06:30:40');
INSERT INTO `sys_oper_log` VALUES ('5', '用户管理', '2', 'com.ibotn.web.controller.system.SysUserController.edit()', 'PUT', '1', 'admin', null, '/system/user', '127.0.0.1', '内网IP', '{\"admin\":false,\"avatar\":\"\",\"createBy\":\"admin\",\"createTime\":\"2022-05-31 06:30:40\",\"delFlag\":\"0\",\"dept\":{\"ancestors\":\"0\",\"children\":[],\"deptId\":100,\"deptName\":\"若依科技\",\"leader\":\"若依\",\"orderNum\":0,\"params\":{},\"parentId\":0,\"status\":\"0\"},\"deptId\":100,\"email\":\"\",\"loginDate\":\"2022-05-31 14:33:06\",\"loginIp\":\"127.0.0.1\",\"nickName\":\"zhonhai\",\"params\":{},\"password\":\"\",\"phonenumber\":\"18126495953\",\"postIds\":[1],\"remark\":\"我是钟海\",\"roleIds\":[2],\"roles\":[],\"sex\":\"0\",\"status\":\"0\",\"updateBy\":\"admin\",\"userId\":3,\"userName\":\"zhonhai\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-05-31 06:38:00');
INSERT INTO `sys_oper_log` VALUES ('6', '角色管理', '2', 'com.ibotn.web.controller.system.SysRoleController.edit()', 'PUT', '1', 'admin', null, '/system/role', '127.0.0.1', '内网IP', '{\"admin\":false,\"createTime\":\"2022-05-29 12:33:27\",\"dataScope\":\"2\",\"delFlag\":\"0\",\"deptCheckStrictly\":true,\"flag\":false,\"menuCheckStrictly\":true,\"menuIds\":[1,101,1008,1009,1010,1011,1012,102,1013,1014,1015,1016,103,1017,1018,1019,1020,104,1021,1022,1023,1024,1025,105,1026,1027,1028,1029,1030,106,1031,1032,1033,1034,1035,107,1036,1037,1038,1039,108,500,1040,1041,1042,501,1043,1044,1045,2,109,1046,1047,1048,110,1049,1050,1051,1052,1053,1054,111,112,113,3,114,115,1055,1056,1058,1057,1059,1060,116,4],\"params\":{},\"remark\":\"普通角色\",\"roleId\":2,\"roleKey\":\"common\",\"roleName\":\"普通角色\",\"roleSort\":\"2\",\"status\":\"0\",\"updateBy\":\"admin\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-05-31 06:47:04');
INSERT INTO `sys_oper_log` VALUES ('7', '角色管理', '2', 'com.ibotn.web.controller.system.SysRoleController.edit()', 'PUT', '1', 'admin', null, '/system/role', '127.0.0.1', '内网IP', '{\"admin\":false,\"createTime\":\"2022-05-29 12:33:27\",\"dataScope\":\"2\",\"delFlag\":\"0\",\"deptCheckStrictly\":true,\"flag\":false,\"menuCheckStrictly\":true,\"menuIds\":[1,100,1004,1005,1006,1007,101,1008,1009,1010,1011,1012,102,1013,1014,1015,1016,103,1017,1018,1019,1020,104,1021,1022,1023,1024,1025,105,1026,1027,1028,1029,1030,106,1031,1032,1033,1034,1035,107,1036,1037,1038,1039,108,500,1040,1041,1042,501,1043,1044,1045,2,109,1046,1047,1048,110,1049,1050,1051,1052,1053,1054,111,112,113,3,114,115,1055,1056,1058,1057,1059,1060,116,4],\"params\":{},\"remark\":\"普通角色\",\"roleId\":2,\"roleKey\":\"common\",\"roleName\":\"普通角色\",\"roleSort\":\"2\",\"status\":\"0\",\"updateBy\":\"admin\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-05-31 06:47:25');
INSERT INTO `sys_oper_log` VALUES ('8', '角色管理', '2', 'com.ibotn.web.controller.system.SysRoleController.edit()', 'PUT', '1', 'admin', null, '/system/role', '127.0.0.1', '内网IP', '{\"admin\":false,\"createTime\":\"2022-05-29 12:33:27\",\"dataScope\":\"2\",\"delFlag\":\"0\",\"deptCheckStrictly\":true,\"flag\":false,\"menuCheckStrictly\":true,\"menuIds\":[1,100,1001,1004,1005,1006,1007,101,1008,1009,1010,1011,1012,102,1013,1014,1015,1016,103,1017,1018,1019,1020,104,1021,1022,1023,1024,1025,105,1026,1027,1028,1029,1030,106,1031,1032,1033,1034,1035,107,1036,1037,1038,1039,108,500,1040,1041,1042,501,1043,1044,1045,2,109,1046,1047,1048,110,1049,1050,1051,1052,1053,1054,111,112,113,3,114,115,1055,1056,1058,1057,1059,1060,116,4],\"params\":{},\"remark\":\"普通角色\",\"roleId\":2,\"roleKey\":\"common\",\"roleName\":\"普通角色\",\"roleSort\":\"2\",\"status\":\"0\",\"updateBy\":\"admin\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-05-31 06:47:49');
INSERT INTO `sys_oper_log` VALUES ('9', '角色管理', '2', 'com.ibotn.web.controller.system.SysRoleController.edit()', 'PUT', '1', 'admin', null, '/system/role', '127.0.0.1', '内网IP', '{\"admin\":false,\"createTime\":\"2022-05-29 12:33:27\",\"dataScope\":\"2\",\"delFlag\":\"0\",\"deptCheckStrictly\":true,\"flag\":false,\"menuCheckStrictly\":true,\"menuIds\":[1,100,1004,1005,1006,1007,101,1008,1009,1010,1011,1012,102,1013,1014,1015,1016,103,1017,1018,1019,1020,104,1021,1022,1023,1024,1025,105,1026,1027,1028,1029,1030,106,1031,1032,1033,1034,1035,107,1036,1037,1038,1039,108,500,1040,1041,1042,501,1043,1044,1045,2,109,1046,1047,1048,110,1049,1050,1051,1052,1053,1054,111,112,113,3,114,115,1055,1056,1058,1057,1059,1060,116,4],\"params\":{},\"remark\":\"普通角色\",\"roleId\":2,\"roleKey\":\"common\",\"roleName\":\"普通角色\",\"roleSort\":\"2\",\"status\":\"0\",\"updateBy\":\"admin\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-05-31 06:48:13');
INSERT INTO `sys_oper_log` VALUES ('10', '角色管理', '2', 'com.ibotn.web.controller.system.SysRoleController.edit()', 'PUT', '1', 'admin', null, '/system/role', '127.0.0.1', '内网IP', '{\"admin\":false,\"createTime\":\"2022-05-29 12:33:27\",\"dataScope\":\"2\",\"delFlag\":\"0\",\"deptCheckStrictly\":true,\"flag\":false,\"menuCheckStrictly\":true,\"menuIds\":[1,100,1002,1004,1005,1006,1007,101,1008,1009,1010,1011,1012,102,1013,1014,1015,1016,103,1017,1018,1019,1020,104,1021,1022,1023,1024,1025,105,1026,1027,1028,1029,1030,106,1031,1032,1033,1034,1035,107,1036,1037,1038,1039,108,500,1040,1041,1042,501,1043,1044,1045,2,109,1046,1047,1048,110,1049,1050,1051,1052,1053,1054,111,112,113,3,114,115,1055,1056,1058,1057,1059,1060,116,4],\"params\":{},\"remark\":\"普通角色\",\"roleId\":2,\"roleKey\":\"common\",\"roleName\":\"普通角色\",\"roleSort\":\"2\",\"status\":\"0\",\"updateBy\":\"admin\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-05-31 06:49:00');
INSERT INTO `sys_oper_log` VALUES ('11', '角色管理', '2', 'com.ibotn.web.controller.system.SysRoleController.edit()', 'PUT', '1', 'admin', null, '/system/role', '127.0.0.1', '内网IP', '{\"admin\":false,\"createTime\":\"2022-05-29 12:33:27\",\"dataScope\":\"2\",\"delFlag\":\"0\",\"deptCheckStrictly\":true,\"flag\":false,\"menuCheckStrictly\":true,\"menuIds\":[1,100,1001,1002,1004,1005,1006,1007,101,1008,1009,1010,1011,1012,102,1013,1014,1015,1016,103,1017,1018,1019,1020,104,1021,1022,1023,1024,1025,105,1026,1027,1028,1029,1030,106,1031,1032,1033,1034,1035,107,1036,1037,1038,1039,108,500,1040,1041,1042,501,1043,1044,1045,2,109,1046,1047,1048,110,1049,1050,1051,1052,1053,1054,111,112,113,3,114,115,1055,1056,1058,1057,1059,1060,116,4],\"params\":{},\"remark\":\"普通角色\",\"roleId\":2,\"roleKey\":\"common\",\"roleName\":\"普通角色\",\"roleSort\":\"2\",\"status\":\"0\",\"updateBy\":\"admin\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-05-31 06:49:38');
INSERT INTO `sys_oper_log` VALUES ('12', '角色管理', '2', 'com.ibotn.web.controller.system.SysRoleController.edit()', 'PUT', '1', 'admin', null, '/system/role', '127.0.0.1', '内网IP', '{\"admin\":false,\"createTime\":\"2022-05-29 12:33:27\",\"dataScope\":\"2\",\"delFlag\":\"0\",\"deptCheckStrictly\":true,\"flag\":false,\"menuCheckStrictly\":true,\"menuIds\":[1,100,1002,1004,1005,1006,1007,101,1008,1009,1010,1011,1012,102,1013,1014,1015,1016,103,1017,1018,1019,1020,104,1021,1022,1023,1024,1025,105,1026,1027,1028,1029,1030,106,1031,1032,1033,1034,1035,107,1036,1037,1038,1039,108,500,1040,1041,1042,501,1043,1044,1045,2,109,1046,1047,1048,110,1049,1050,1051,1052,1053,1054,111,112,113,3,114,115,1055,1056,1058,1057,1059,1060,116,4],\"params\":{},\"remark\":\"普通角色\",\"roleId\":2,\"roleKey\":\"common\",\"roleName\":\"普通角色\",\"roleSort\":\"2\",\"status\":\"0\",\"updateBy\":\"admin\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-05-31 06:50:08');
INSERT INTO `sys_oper_log` VALUES ('13', '角色管理', '2', 'com.ibotn.web.controller.system.SysRoleController.edit()', 'PUT', '1', 'admin', null, '/system/role', '127.0.0.1', '内网IP', '{\"admin\":false,\"createTime\":\"2022-05-29 12:33:27\",\"dataScope\":\"2\",\"delFlag\":\"0\",\"deptCheckStrictly\":true,\"flag\":false,\"menuCheckStrictly\":true,\"menuIds\":[1,100,1001,1002,1004,1005,1006,1007,101,1008,1009,1010,1011,1012,102,1013,1014,1015,1016,103,1017,1018,1019,1020,104,1021,1022,1023,1024,1025,105,1026,1027,1028,1029,1030,106,1031,1032,1033,1034,1035,107,1036,1037,1038,1039,108,500,1040,1041,1042,501,1043,1044,1045,2,109,1046,1047,1048,110,1049,1050,1051,1052,1053,1054,111,112,113,3,114,115,1055,1056,1058,1057,1059,1060,116,4],\"params\":{},\"remark\":\"普通角色\",\"roleId\":2,\"roleKey\":\"common\",\"roleName\":\"普通角色\",\"roleSort\":\"2\",\"status\":\"0\",\"updateBy\":\"admin\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-05-31 06:58:17');
INSERT INTO `sys_oper_log` VALUES ('14', '角色管理', '2', 'com.ibotn.web.controller.system.SysRoleController.edit()', 'PUT', '1', 'admin', null, '/system/role', '127.0.0.1', '内网IP', '{\"admin\":false,\"createTime\":\"2022-05-29 12:33:27\",\"dataScope\":\"2\",\"delFlag\":\"0\",\"deptCheckStrictly\":true,\"flag\":false,\"menuCheckStrictly\":true,\"menuIds\":[1,100,1002,1004,1005,1006,1007,101,1008,1009,1010,1011,1012,102,1013,1014,1015,1016,103,1017,1018,1019,1020,104,1021,1022,1023,1024,1025,105,1026,1027,1028,1029,1030,106,1031,1032,1033,1034,1035,107,1036,1037,1038,1039,108,500,1040,1041,1042,501,1043,1044,1045,2,109,1046,1047,1048,110,1049,1050,1051,1052,1053,1054,111,112,113,3,114,115,1055,1056,1058,1057,1059,1060,116,4],\"params\":{},\"remark\":\"普通角色\",\"roleId\":2,\"roleKey\":\"common\",\"roleName\":\"普通角色\",\"roleSort\":\"2\",\"status\":\"0\",\"updateBy\":\"admin\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-05-31 06:59:16');
INSERT INTO `sys_oper_log` VALUES ('15', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'zhonhai', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"\",\"createTime\":\"2022-05-29 12:33:30\",\"icon\":\"#\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1002,\"menuName\":\"用户新增\",\"menuType\":\"F\",\"orderNum\":2,\"params\":{},\"parentId\":100,\"path\":\"\",\"perms\":\"system:user:add4\",\"query\":\"\",\"status\":\"0\",\"updateBy\":\"zhonhai\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-05-31 07:01:20');
INSERT INTO `sys_oper_log` VALUES ('16', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'zhonhai', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"\",\"createTime\":\"2022-05-29 12:33:30\",\"icon\":\"#\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1002,\"menuName\":\"用户新增\",\"menuType\":\"F\",\"orderNum\":2,\"params\":{},\"parentId\":100,\"path\":\"\",\"perms\":\"system:user:add\",\"query\":\"\",\"status\":\"0\",\"updateBy\":\"zhonhai\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-05-31 07:01:44');
INSERT INTO `sys_oper_log` VALUES ('17', '角色管理', '2', 'com.ibotn.web.controller.system.SysRoleController.edit()', 'PUT', '1', 'admin', null, '/system/role', '127.0.0.1', '内网IP', '{\"admin\":false,\"createTime\":\"2022-05-29 12:33:27\",\"dataScope\":\"2\",\"delFlag\":\"0\",\"deptCheckStrictly\":true,\"flag\":false,\"menuCheckStrictly\":true,\"menuIds\":[1,100,1001,1002,1003,1004,1005,1006,1007,101,1008,1009,1010,1011,1012,102,1013,1014,1015,1016,103,1017,1018,1019,1020,104,1021,1022,1023,1024,1025,105,1026,1027,1028,1029,1030,106,1031,1032,1033,1034,1035,107,1036,1037,1038,1039,108,500,1040,1041,1042,501,1043,1044,1045,2,109,1046,1047,1048,110,1049,1050,1051,1052,1053,1054,111,112,113,3,114,115,1055,1056,1058,1057,1059,1060,116,4],\"params\":{},\"remark\":\"普通角色\",\"roleId\":2,\"roleKey\":\"common\",\"roleName\":\"普通角色\",\"roleSort\":\"2\",\"status\":\"0\",\"updateBy\":\"admin\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-05-31 07:02:15');
INSERT INTO `sys_oper_log` VALUES ('18', '部门管理', '2', 'com.ibotn.web.controller.system.SysDeptController.edit()', 'PUT', '1', 'admin', null, '/system/dept', '127.0.0.1', '内网IP', '{\"ancestors\":\"0\",\"children\":[],\"createBy\":\"admin\",\"createTime\":\"2022-05-29 12:33:25\",\"delFlag\":\"0\",\"deptId\":100,\"deptName\":\"若依科技\",\"email\":\"ry@qq.com\",\"leader\":\"若依\",\"orderNum\":0,\"params\":{},\"parentId\":0,\"phone\":\"15888888887\",\"status\":\"0\",\"updateBy\":\"admin\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 03:20:35');
INSERT INTO `sys_oper_log` VALUES ('19', '菜单管理', '1', 'com.ibotn.web.controller.system.SysMenuController.add()', 'POST', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"createBy\":\"admin\",\"icon\":\"validCode\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuName\":\"事务管理\",\"menuType\":\"M\",\"orderNum\":2,\"params\":{},\"parentId\":0,\"path\":\"affairManage\",\"status\":\"0\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 06:30:15');
INSERT INTO `sys_oper_log` VALUES ('20', '菜单管理', '1', 'com.ibotn.web.controller.system.SysMenuController.add()', 'POST', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"createBy\":\"admin\",\"icon\":\"date-range\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuName\":\"请假\",\"menuType\":\"M\",\"orderNum\":1,\"params\":{},\"parentId\":1061,\"path\":\"askForLeave\",\"status\":\"0\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 06:31:44');
INSERT INTO `sys_oper_log` VALUES ('21', '菜单管理', '1', 'com.ibotn.web.controller.system.SysMenuController.add()', 'POST', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"createBy\":\"admin\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuName\":\"物资申购\",\"menuType\":\"M\",\"orderNum\":2,\"params\":{},\"parentId\":1061,\"path\":\"materialPurchase\",\"status\":\"0\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 06:33:55');
INSERT INTO `sys_oper_log` VALUES ('22', '菜单管理', '1', 'com.ibotn.web.controller.system.SysMenuController.add()', 'POST', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"createBy\":\"admin\",\"icon\":\"cascader\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuName\":\"领用\",\"menuType\":\"M\",\"orderNum\":3,\"params\":{},\"parentId\":1061,\"path\":\"collect\",\"status\":\"0\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 06:34:40');
INSERT INTO `sys_oper_log` VALUES ('23', '菜单管理', '1', 'com.ibotn.web.controller.system.SysMenuController.add()', 'POST', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"createBy\":\"admin\",\"icon\":\"clipboard\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuName\":\"报修\",\"menuType\":\"M\",\"orderNum\":4,\"params\":{},\"parentId\":1061,\"path\":\"repairRequest\",\"status\":\"0\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 06:35:40');
INSERT INTO `sys_oper_log` VALUES ('24', '菜单管理', '1', 'com.ibotn.web.controller.system.SysMenuController.add()', 'POST', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"createBy\":\"admin\",\"icon\":\"job\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuName\":\"考勤\",\"menuType\":\"M\",\"orderNum\":3,\"params\":{},\"parentId\":0,\"path\":\"checkWork\",\"status\":\"0\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 06:37:34');
INSERT INTO `sys_oper_log` VALUES ('25', '菜单管理', '1', 'com.ibotn.web.controller.system.SysMenuController.add()', 'POST', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"createBy\":\"admin\",\"icon\":\"druid\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuName\":\"教工考勤\",\"menuType\":\"M\",\"orderNum\":1,\"params\":{},\"parentId\":1066,\"path\":\"tTeachinStaff\",\"status\":\"0\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 06:39:46');
INSERT INTO `sys_oper_log` VALUES ('26', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"createTime\":\"2022-06-01 06:31:44\",\"icon\":\"date-range\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1062,\"menuName\":\"请假\",\"menuType\":\"C\",\"orderNum\":1,\"params\":{},\"parentId\":1061,\"path\":\"askForLeave\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 06:41:14');
INSERT INTO `sys_oper_log` VALUES ('27', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"affairManage/askForLeave\",\"createTime\":\"2022-06-01 06:31:44\",\"icon\":\"date-range\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1062,\"menuName\":\"请假\",\"menuType\":\"C\",\"orderNum\":1,\"params\":{},\"parentId\":1061,\"path\":\"askForLeave\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 06:48:18');
INSERT INTO `sys_oper_log` VALUES ('28', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"checkWork/teachinStaff/index\",\"createTime\":\"2022-06-01 06:39:46\",\"icon\":\"druid\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1067,\"menuName\":\"教工考勤\",\"menuType\":\"C\",\"orderNum\":1,\"params\":{},\"parentId\":1066,\"path\":\"teachinStaff\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 06:51:53');
INSERT INTO `sys_oper_log` VALUES ('29', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"affairManage/materialPurchase/index\",\"createTime\":\"2022-06-01 06:33:54\",\"icon\":\"#\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1063,\"menuName\":\"物资申购\",\"menuType\":\"C\",\"orderNum\":2,\"params\":{},\"parentId\":1061,\"path\":\"materialPurchase\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 06:56:28');
INSERT INTO `sys_oper_log` VALUES ('30', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"affairManage/askForLeave/index\",\"createTime\":\"2022-06-01 06:31:44\",\"icon\":\"date-range\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1062,\"menuName\":\"请假\",\"menuType\":\"C\",\"orderNum\":1,\"params\":{},\"parentId\":1061,\"path\":\"askForLeave\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 06:56:43');
INSERT INTO `sys_oper_log` VALUES ('31', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"affairManage/collect/index\",\"createTime\":\"2022-06-01 06:34:40\",\"icon\":\"cascader\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1064,\"menuName\":\"领用\",\"menuType\":\"C\",\"orderNum\":3,\"params\":{},\"parentId\":1061,\"path\":\"collect\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 06:57:53');
INSERT INTO `sys_oper_log` VALUES ('32', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"affairManage/repairRequest/index\",\"createTime\":\"2022-06-01 06:35:40\",\"icon\":\"clipboard\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1065,\"menuName\":\"报修\",\"menuType\":\"C\",\"orderNum\":4,\"params\":{},\"parentId\":1061,\"path\":\"repairRequest\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 06:58:22');
INSERT INTO `sys_oper_log` VALUES ('33', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"affairManage/receiving/index\",\"createTime\":\"2022-06-01 06:34:40\",\"icon\":\"cascader\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1064,\"menuName\":\"领用\",\"menuType\":\"C\",\"orderNum\":3,\"params\":{},\"parentId\":1061,\"path\":\"receiving\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:00:43');
INSERT INTO `sys_oper_log` VALUES ('34', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"checkWork/teachinStaff/index\",\"createTime\":\"2022-06-01 06:39:46\",\"icon\":\"druid\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1067,\"menuName\":\"教工考勤\",\"menuType\":\"C\",\"orderNum\":1,\"params\":{},\"parentId\":1066,\"path\":\"teachinStaff\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:01:01');
INSERT INTO `sys_oper_log` VALUES ('35', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"checkWork/babyWork/index\",\"createTime\":\"2022-06-01 06:37:34\",\"icon\":\"job\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1066,\"menuName\":\"宝贝考勤\",\"menuType\":\"C\",\"orderNum\":2,\"params\":{},\"parentId\":0,\"path\":\"babyWork\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:02:25');
INSERT INTO `sys_oper_log` VALUES ('36', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"checkWork/babyWork/index\",\"createTime\":\"2022-06-01 06:37:34\",\"icon\":\"job\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1066,\"menuName\":\"考勤\",\"menuType\":\"M\",\"orderNum\":2,\"params\":{},\"parentId\":0,\"path\":\"checkWork\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:02:57');
INSERT INTO `sys_oper_log` VALUES ('37', '菜单管理', '1', 'com.ibotn.web.controller.system.SysMenuController.add()', 'POST', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"checkWork/babyWork/index\",\"createBy\":\"admin\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuName\":\"宝贝考勤\",\"menuType\":\"C\",\"orderNum\":2,\"params\":{},\"parentId\":1066,\"path\":\"babyWork\",\"status\":\"0\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:03:51');
INSERT INTO `sys_oper_log` VALUES ('38', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"checkWork/babyWork/index\",\"createTime\":\"2022-06-01 06:37:34\",\"icon\":\"job\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1066,\"menuName\":\"考勤\",\"menuType\":\"M\",\"orderNum\":3,\"params\":{},\"parentId\":0,\"path\":\"checkWork\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:03:57');
INSERT INTO `sys_oper_log` VALUES ('39', '菜单管理', '1', 'com.ibotn.web.controller.system.SysMenuController.add()', 'POST', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"createBy\":\"admin\",\"icon\":\"cascader\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuName\":\"安全管理\",\"menuType\":\"M\",\"orderNum\":5,\"params\":{},\"parentId\":0,\"path\":\"saftyManage\",\"status\":\"0\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:05:23');
INSERT INTO `sys_oper_log` VALUES ('40', '菜单管理', '1', 'com.ibotn.web.controller.system.SysMenuController.add()', 'POST', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"saftyManage/fireCheck/index\",\"createBy\":\"admin\",\"icon\":\"date-range\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuName\":\"消防检查\",\"menuType\":\"C\",\"orderNum\":1,\"params\":{},\"parentId\":1069,\"path\":\"fireCheck\",\"status\":\"0\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:07:09');
INSERT INTO `sys_oper_log` VALUES ('41', '菜单管理', '1', 'com.ibotn.web.controller.system.SysMenuController.add()', 'POST', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"saftyManage/securityPatrol/index\",\"createBy\":\"admin\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuName\":\"安防巡查\",\"menuType\":\"C\",\"orderNum\":2,\"params\":{},\"parentId\":1069,\"path\":\"securityPatrol\",\"status\":\"0\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:13:23');
INSERT INTO `sys_oper_log` VALUES ('42', '菜单管理', '1', 'com.ibotn.web.controller.system.SysMenuController.add()', 'POST', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"saftyManage/goodSafty/index\",\"createBy\":\"admin\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuName\":\"食品安全\",\"menuType\":\"C\",\"orderNum\":3,\"params\":{},\"parentId\":1069,\"path\":\"goodSafty\",\"status\":\"0\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:15:34');
INSERT INTO `sys_oper_log` VALUES ('43', '菜单管理', '1', 'com.ibotn.web.controller.system.SysMenuController.add()', 'POST', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"saftyManage/epidemicPrevention/index\",\"createBy\":\"admin\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuName\":\"防疫\",\"menuType\":\"C\",\"orderNum\":4,\"params\":{},\"parentId\":1069,\"path\":\"epidemicPrevention\",\"status\":\"0\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:16:19');
INSERT INTO `sys_oper_log` VALUES ('44', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"createTime\":\"2022-05-29 12:33:28\",\"icon\":\"guide\",\"isCache\":\"0\",\"isFrame\":\"0\",\"menuId\":4,\"menuName\":\"若依官网\",\"menuType\":\"M\",\"orderNum\":4,\"params\":{},\"parentId\":0,\"path\":\"http://ruoyi.vip\",\"perms\":\"\",\"query\":\"\",\"status\":\"1\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:25:09');
INSERT INTO `sys_oper_log` VALUES ('45', '菜单管理', '3', 'com.ibotn.web.controller.system.SysMenuController.remove()', 'DELETE', '1', 'admin', null, '/system/menu/4', '127.0.0.1', '内网IP', '{menuId=4}', '{\"msg\":\"菜单已分配,不允许删除\",\"code\":500}', '0', null, '2022-06-01 07:25:27');
INSERT INTO `sys_oper_log` VALUES ('46', '菜单管理', '3', 'com.ibotn.web.controller.system.SysMenuController.remove()', 'DELETE', '1', 'admin', null, '/system/menu/4', '127.0.0.1', '内网IP', '{menuId=4}', '{\"msg\":\"菜单已分配,不允许删除\",\"code\":500}', '0', null, '2022-06-01 07:25:48');
INSERT INTO `sys_oper_log` VALUES ('47', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"createTime\":\"2022-05-29 12:33:28\",\"icon\":\"guide\",\"isCache\":\"0\",\"isFrame\":\"0\",\"menuId\":4,\"menuName\":\"若依官网\",\"menuType\":\"M\",\"orderNum\":4,\"params\":{},\"path\":\"http://ruoyi.vip\",\"perms\":\"\",\"query\":\"\",\"status\":\"1\",\"updateBy\":\"admin\",\"visible\":\"1\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:26:06');
INSERT INTO `sys_oper_log` VALUES ('48', '菜单管理', '3', 'com.ibotn.web.controller.system.SysMenuController.remove()', 'DELETE', '1', 'admin', null, '/system/menu/4', '127.0.0.1', '内网IP', '{menuId=4}', '{\"msg\":\"菜单已分配,不允许删除\",\"code\":500}', '0', null, '2022-06-01 07:26:09');
INSERT INTO `sys_oper_log` VALUES ('49', '菜单管理', '3', 'com.ibotn.web.controller.system.SysMenuController.remove()', 'DELETE', '1', 'admin', null, '/system/menu/4', '127.0.0.1', '内网IP', '{menuId=4}', '{\"msg\":\"菜单已分配,不允许删除\",\"code\":500}', '0', null, '2022-06-01 07:26:47');
INSERT INTO `sys_oper_log` VALUES ('50', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"createTime\":\"2022-05-29 12:33:28\",\"icon\":\"system\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1,\"menuName\":\"设置\",\"menuType\":\"M\",\"orderNum\":10,\"params\":{},\"parentId\":0,\"path\":\"system\",\"perms\":\"\",\"query\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:27:18');
INSERT INTO `sys_oper_log` VALUES ('51', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"checkWork/babyWork/index\",\"createTime\":\"2022-06-01 06:37:34\",\"icon\":\"job\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1066,\"menuName\":\"考勤\",\"menuType\":\"M\",\"orderNum\":3,\"params\":{},\"parentId\":0,\"path\":\"checkWork\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:29:05');
INSERT INTO `sys_oper_log` VALUES ('52', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"checkWork/teachinStaff/index\",\"createTime\":\"2022-06-01 06:39:46\",\"icon\":\"druid\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1067,\"menuName\":\"教工考勤\",\"menuType\":\"C\",\"orderNum\":1,\"params\":{},\"parentId\":1066,\"path\":\"teachinStaff\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:29:17');
INSERT INTO `sys_oper_log` VALUES ('53', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"checkWork/babyWork/index\",\"createTime\":\"2022-06-01 06:37:34\",\"icon\":\"job\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1066,\"menuName\":\"考勤\",\"menuType\":\"M\",\"orderNum\":3,\"params\":{},\"parentId\":0,\"path\":\"checkWork\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:29:46');
INSERT INTO `sys_oper_log` VALUES ('54', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"checkWork/teachinStaff/index\",\"createTime\":\"2022-06-01 06:39:46\",\"icon\":\"druid\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1067,\"menuName\":\"教工考勤\",\"menuType\":\"C\",\"orderNum\":1,\"params\":{},\"parentId\":1066,\"path\":\"teachinStaff\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:30:03');
INSERT INTO `sys_oper_log` VALUES ('55', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"\",\"createTime\":\"2022-06-01 06:37:34\",\"icon\":\"job\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1066,\"menuName\":\"考勤\",\"menuType\":\"M\",\"orderNum\":3,\"params\":{},\"parentId\":0,\"path\":\"checkWork\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:31:30');
INSERT INTO `sys_oper_log` VALUES ('56', '菜单管理', '1', 'com.ibotn.web.controller.system.SysMenuController.add()', 'POST', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"createBy\":\"admin\",\"icon\":\"date-range\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuName\":\"园所信息\",\"menuType\":\"M\",\"orderNum\":6,\"params\":{},\"parentId\":0,\"path\":\"parkInformation\",\"status\":\"0\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:33:39');
INSERT INTO `sys_oper_log` VALUES ('57', '菜单管理', '1', 'com.ibotn.web.controller.system.SysMenuController.add()', 'POST', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"parkInformation/departmentManagement/index\",\"createBy\":\"admin\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuName\":\"部门管理\",\"menuType\":\"C\",\"orderNum\":1,\"params\":{},\"parentId\":1074,\"path\":\"departmentManagement\",\"status\":\"0\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:37:47');
INSERT INTO `sys_oper_log` VALUES ('58', '菜单管理', '1', 'com.ibotn.web.controller.system.SysMenuController.add()', 'POST', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"parkInformation/classManage/index\",\"createBy\":\"admin\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuName\":\"班级管理\",\"menuType\":\"C\",\"orderNum\":2,\"params\":{},\"parentId\":1074,\"path\":\"classManage\",\"status\":\"0\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:38:40');
INSERT INTO `sys_oper_log` VALUES ('59', '菜单管理', '1', 'com.ibotn.web.controller.system.SysMenuController.add()', 'POST', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"createBy\":\"admin\",\"icon\":\"date-range\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuName\":\"后勤管理\",\"menuType\":\"M\",\"orderNum\":7,\"params\":{},\"parentId\":0,\"path\":\"logisticsManage\",\"status\":\"0\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:40:02');
INSERT INTO `sys_oper_log` VALUES ('60', '菜单管理', '1', 'com.ibotn.web.controller.system.SysMenuController.add()', 'POST', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"logisticsManage/kitchen/index\",\"createBy\":\"admin\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuName\":\"厨房\",\"menuType\":\"C\",\"orderNum\":1,\"params\":{},\"parentId\":1077,\"path\":\"kitchen\",\"status\":\"0\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:40:48');
INSERT INTO `sys_oper_log` VALUES ('61', '菜单管理', '1', 'com.ibotn.web.controller.system.SysMenuController.add()', 'POST', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"logisticsManage/warehouse/index\",\"createBy\":\"admin\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuName\":\"仓库\",\"menuType\":\"C\",\"orderNum\":2,\"params\":{},\"parentId\":1077,\"path\":\"warehouse\",\"status\":\"0\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:42:43');
INSERT INTO `sys_oper_log` VALUES ('62', '菜单管理', '1', 'com.ibotn.web.controller.system.SysMenuController.add()', 'POST', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"logisticsManage/fixedAssets/index\",\"createBy\":\"admin\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuName\":\"固定资产\",\"menuType\":\"C\",\"orderNum\":3,\"params\":{},\"parentId\":1077,\"path\":\"fixedAssets\",\"status\":\"0\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:44:16');
INSERT INTO `sys_oper_log` VALUES ('63', '菜单管理', '1', 'com.ibotn.web.controller.system.SysMenuController.add()', 'POST', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"createBy\":\"admin\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuName\":\"财务管理\",\"menuType\":\"M\",\"orderNum\":8,\"params\":{},\"parentId\":0,\"path\":\"financeManage\",\"status\":\"0\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:45:29');
INSERT INTO `sys_oper_log` VALUES ('64', '菜单管理', '1', 'com.ibotn.web.controller.system.SysMenuController.add()', 'POST', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"financeManage/billManage/index\",\"createBy\":\"admin\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuName\":\"账单管理\",\"menuType\":\"C\",\"orderNum\":1,\"params\":{},\"parentId\":1081,\"path\":\"billManage\",\"status\":\"0\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:46:32');
INSERT INTO `sys_oper_log` VALUES ('65', '菜单管理', '1', 'com.ibotn.web.controller.system.SysMenuController.add()', 'POST', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"financeManage/payService/index\",\"createBy\":\"admin\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuName\":\"收费项目\",\"menuType\":\"C\",\"orderNum\":2,\"params\":{},\"parentId\":1081,\"path\":\"payService\",\"status\":\"0\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:48:29');
INSERT INTO `sys_oper_log` VALUES ('66', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"createTime\":\"2022-06-01 07:45:28\",\"icon\":\"documentation\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1081,\"menuName\":\"财务管理\",\"menuType\":\"M\",\"orderNum\":8,\"params\":{},\"parentId\":0,\"path\":\"financeManage\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:51:40');
INSERT INTO `sys_oper_log` VALUES ('67', '菜单管理', '1', 'com.ibotn.web.controller.system.SysMenuController.add()', 'POST', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"createBy\":\"admin\",\"icon\":\"documentation\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuName\":\"活动\",\"menuType\":\"M\",\"orderNum\":9,\"params\":{},\"parentId\":0,\"path\":\"activity\",\"status\":\"0\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:52:25');
INSERT INTO `sys_oper_log` VALUES ('68', '菜单管理', '1', 'com.ibotn.web.controller.system.SysMenuController.add()', 'POST', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"createBy\":\"admin\",\"icon\":\"documentation\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuName\":\"档案管理\",\"menuType\":\"M\",\"orderNum\":10,\"params\":{},\"parentId\":0,\"path\":\"fileManagement\",\"status\":\"0\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:53:30');
INSERT INTO `sys_oper_log` VALUES ('69', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"\",\"createTime\":\"2022-05-29 12:33:29\",\"icon\":\"log\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":108,\"menuName\":\"日志管理\",\"menuType\":\"M\",\"orderNum\":9,\"params\":{},\"parentId\":1,\"path\":\"log\",\"perms\":\"\",\"query\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"1\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:54:28');
INSERT INTO `sys_oper_log` VALUES ('70', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"system/notice/index\",\"createTime\":\"2022-05-29 12:33:29\",\"icon\":\"message\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":107,\"menuName\":\"通知公告\",\"menuType\":\"C\",\"orderNum\":8,\"params\":{},\"parentId\":1,\"path\":\"notice\",\"perms\":\"system:notice:list\",\"query\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"1\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:54:44');
INSERT INTO `sys_oper_log` VALUES ('71', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"system/config/index\",\"createTime\":\"2022-05-29 12:33:28\",\"icon\":\"edit\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":106,\"menuName\":\"参数设置\",\"menuType\":\"C\",\"orderNum\":7,\"params\":{},\"parentId\":1,\"path\":\"config\",\"perms\":\"system:config:list\",\"query\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"1\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:54:52');
INSERT INTO `sys_oper_log` VALUES ('72', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"system/dict/index\",\"createTime\":\"2022-05-29 12:33:28\",\"icon\":\"dict\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":105,\"menuName\":\"字典管理\",\"menuType\":\"C\",\"orderNum\":6,\"params\":{},\"parentId\":1,\"path\":\"dict\",\"perms\":\"system:dict:list\",\"query\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"1\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:55:00');
INSERT INTO `sys_oper_log` VALUES ('73', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"system/post/index\",\"createTime\":\"2022-05-29 12:33:28\",\"icon\":\"post\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":104,\"menuName\":\"岗位管理\",\"menuType\":\"C\",\"orderNum\":5,\"params\":{},\"parentId\":1,\"path\":\"post\",\"perms\":\"system:post:list\",\"query\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"1\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:55:56');
INSERT INTO `sys_oper_log` VALUES ('74', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"createTime\":\"2022-05-29 12:33:28\",\"icon\":\"tool\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":3,\"menuName\":\"系统工具\",\"menuType\":\"M\",\"orderNum\":3,\"params\":{},\"parentId\":0,\"path\":\"tool\",\"perms\":\"\",\"query\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"1\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:56:24');
INSERT INTO `sys_oper_log` VALUES ('75', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"createTime\":\"2022-05-29 12:33:28\",\"icon\":\"monitor\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":2,\"menuName\":\"系统监控\",\"menuType\":\"M\",\"orderNum\":2,\"params\":{},\"parentId\":0,\"path\":\"monitor\",\"perms\":\"\",\"query\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"1\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:56:33');
INSERT INTO `sys_oper_log` VALUES ('76', '菜单管理', '3', 'com.ibotn.web.controller.system.SysMenuController.remove()', 'DELETE', '1', 'admin', null, '/system/menu/4', '127.0.0.1', '内网IP', '{menuId=4}', '{\"msg\":\"菜单已分配,不允许删除\",\"code\":500}', '0', null, '2022-06-01 07:56:43');
INSERT INTO `sys_oper_log` VALUES ('77', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"createTime\":\"2022-05-29 12:33:28\",\"icon\":\"monitor\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":2,\"menuName\":\"系统监控\",\"menuType\":\"M\",\"orderNum\":2,\"params\":{},\"parentId\":0,\"path\":\"monitor\",\"perms\":\"\",\"query\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"1\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:57:51');
INSERT INTO `sys_oper_log` VALUES ('78', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"createTime\":\"2022-05-29 12:33:28\",\"icon\":\"system\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1,\"menuName\":\"设置\",\"menuType\":\"M\",\"orderNum\":11,\"params\":{},\"parentId\":0,\"path\":\"system\",\"perms\":\"\",\"query\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 07:58:36');
INSERT INTO `sys_oper_log` VALUES ('79', '部门管理', '2', 'com.ibotn.web.controller.system.SysDeptController.edit()', 'PUT', '1', 'admin', null, '/system/dept', '127.0.0.1', '内网IP', '{\"ancestors\":\"0\",\"children\":[],\"createBy\":\"admin\",\"createTime\":\"2022-05-29 12:33:25\",\"delFlag\":\"0\",\"deptId\":100,\"deptName\":\"玉林幼儿园\",\"email\":\"yulin@qq.com\",\"leader\":\"杨园长\",\"orderNum\":0,\"params\":{},\"parentId\":0,\"phone\":\"15888888887\",\"status\":\"0\",\"updateBy\":\"admin\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:00:59');
INSERT INTO `sys_oper_log` VALUES ('80', '部门管理', '2', 'com.ibotn.web.controller.system.SysDeptController.edit()', 'PUT', '1', 'admin', null, '/system/dept', '127.0.0.1', '内网IP', '{\"ancestors\":\"0,100\",\"children\":[],\"createBy\":\"admin\",\"createTime\":\"2022-05-29 12:33:25\",\"delFlag\":\"0\",\"deptId\":101,\"deptName\":\"后勤部门\",\"email\":\"zhon@qq.com\",\"leader\":\"钟部长\",\"orderNum\":1,\"params\":{},\"parentId\":100,\"phone\":\"15888888888\",\"status\":\"0\",\"updateBy\":\"admin\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:01:35');
INSERT INTO `sys_oper_log` VALUES ('81', '部门管理', '2', 'com.ibotn.web.controller.system.SysDeptController.edit()', 'PUT', '1', 'admin', null, '/system/dept', '127.0.0.1', '内网IP', '{\"ancestors\":\"0,100\",\"children\":[],\"createBy\":\"admin\",\"createTime\":\"2022-05-29 12:33:25\",\"delFlag\":\"0\",\"deptId\":102,\"deptName\":\"财务部门\",\"email\":\"zhan@qq.com\",\"leader\":\"张部长\",\"orderNum\":2,\"params\":{},\"parentId\":100,\"phone\":\"15888888888\",\"status\":\"0\",\"updateBy\":\"admin\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:02:05');
INSERT INTO `sys_oper_log` VALUES ('82', '部门管理', '3', 'com.ibotn.web.controller.system.SysDeptController.remove()', 'DELETE', '1', 'admin', null, '/system/dept/103', '127.0.0.1', '内网IP', '{deptId=103}', '{\"msg\":\"部门存在用户,不允许删除\",\"code\":500}', '0', null, '2022-06-01 08:02:27');
INSERT INTO `sys_oper_log` VALUES ('83', '部门管理', '3', 'com.ibotn.web.controller.system.SysDeptController.remove()', 'DELETE', '1', 'admin', null, '/system/dept/107', '127.0.0.1', '内网IP', '{deptId=107}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:02:37');
INSERT INTO `sys_oper_log` VALUES ('84', '部门管理', '3', 'com.ibotn.web.controller.system.SysDeptController.remove()', 'DELETE', '1', 'admin', null, '/system/dept/105', '127.0.0.1', '内网IP', '{deptId=105}', '{\"msg\":\"部门存在用户,不允许删除\",\"code\":500}', '0', null, '2022-06-01 08:02:42');
INSERT INTO `sys_oper_log` VALUES ('85', '部门管理', '3', 'com.ibotn.web.controller.system.SysDeptController.remove()', 'DELETE', '1', 'admin', null, '/system/dept/104', '127.0.0.1', '内网IP', '{deptId=104}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:02:47');
INSERT INTO `sys_oper_log` VALUES ('86', '部门管理', '3', 'com.ibotn.web.controller.system.SysDeptController.remove()', 'DELETE', '1', 'admin', null, '/system/dept/103', '127.0.0.1', '内网IP', '{deptId=103}', '{\"msg\":\"部门存在用户,不允许删除\",\"code\":500}', '0', null, '2022-06-01 08:02:50');
INSERT INTO `sys_oper_log` VALUES ('87', '部门管理', '3', 'com.ibotn.web.controller.system.SysDeptController.remove()', 'DELETE', '1', 'admin', null, '/system/dept/106', '127.0.0.1', '内网IP', '{deptId=106}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:02:54');
INSERT INTO `sys_oper_log` VALUES ('88', '部门管理', '3', 'com.ibotn.web.controller.system.SysDeptController.remove()', 'DELETE', '1', 'admin', null, '/system/dept/105', '127.0.0.1', '内网IP', '{deptId=105}', '{\"msg\":\"部门存在用户,不允许删除\",\"code\":500}', '0', null, '2022-06-01 08:02:57');
INSERT INTO `sys_oper_log` VALUES ('89', '部门管理', '3', 'com.ibotn.web.controller.system.SysDeptController.remove()', 'DELETE', '1', 'admin', null, '/system/dept/109', '127.0.0.1', '内网IP', '{deptId=109}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:03:00');
INSERT INTO `sys_oper_log` VALUES ('90', '部门管理', '3', 'com.ibotn.web.controller.system.SysDeptController.remove()', 'DELETE', '1', 'admin', null, '/system/dept/108', '127.0.0.1', '内网IP', '{deptId=108}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:03:03');
INSERT INTO `sys_oper_log` VALUES ('91', '部门管理', '2', 'com.ibotn.web.controller.system.SysDeptController.edit()', 'PUT', '1', 'admin', null, '/system/dept', '127.0.0.1', '内网IP', '{\"ancestors\":\"0,100,101\",\"children\":[],\"createBy\":\"admin\",\"createTime\":\"2022-05-29 12:33:26\",\"delFlag\":\"0\",\"deptId\":103,\"deptName\":\"a部门\",\"email\":\"ry@qq.com\",\"leader\":\"李\",\"orderNum\":1,\"params\":{},\"parentId\":101,\"phone\":\"15888888888\",\"status\":\"0\",\"updateBy\":\"admin\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:03:21');
INSERT INTO `sys_oper_log` VALUES ('92', '部门管理', '2', 'com.ibotn.web.controller.system.SysDeptController.edit()', 'PUT', '1', 'admin', null, '/system/dept', '127.0.0.1', '内网IP', '{\"ancestors\":\"0,100,101\",\"children\":[],\"createBy\":\"admin\",\"createTime\":\"2022-05-29 12:33:26\",\"delFlag\":\"0\",\"deptId\":105,\"deptName\":\"b部门\",\"email\":\"ry@qq.com\",\"leader\":\"李\",\"orderNum\":3,\"params\":{},\"parentId\":101,\"phone\":\"15888888888\",\"status\":\"0\",\"updateBy\":\"admin\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:03:35');
INSERT INTO `sys_oper_log` VALUES ('93', '菜单管理', '1', 'com.ibotn.web.controller.system.SysMenuController.add()', 'POST', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"createBy\":\"admin\",\"icon\":\"date-range\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuName\":\"斤斤计较军\",\"menuType\":\"M\",\"orderNum\":222,\"params\":{},\"parentId\":0,\"path\":\"aaaa\",\"status\":\"0\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:17:03');
INSERT INTO `sys_oper_log` VALUES ('94', '菜单管理', '1', 'com.ibotn.web.controller.system.SysMenuController.add()', 'POST', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"aaaa/bbbb\",\"createBy\":\"admin\",\"icon\":\"documentation\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuName\":\"bbbb\",\"menuType\":\"C\",\"orderNum\":1,\"params\":{},\"parentId\":1086,\"path\":\"bbbb\",\"status\":\"0\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:20:54');
INSERT INTO `sys_oper_log` VALUES ('95', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"aaaa/bbbb/index\",\"createTime\":\"2022-06-01 08:20:54\",\"icon\":\"documentation\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1087,\"menuName\":\"bbbb\",\"menuType\":\"C\",\"orderNum\":1,\"params\":{},\"parentId\":1086,\"path\":\"bbbb\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:24:36');
INSERT INTO `sys_oper_log` VALUES ('96', '菜单管理', '3', 'com.ibotn.web.controller.system.SysMenuController.remove()', 'DELETE', '1', 'admin', null, '/system/menu/1086', '127.0.0.1', '内网IP', '{menuId=1086}', '{\"msg\":\"存在子菜单,不允许删除\",\"code\":500}', '0', null, '2022-06-01 08:27:48');
INSERT INTO `sys_oper_log` VALUES ('97', '菜单管理', '3', 'com.ibotn.web.controller.system.SysMenuController.remove()', 'DELETE', '1', 'admin', null, '/system/menu/1087', '127.0.0.1', '内网IP', '{menuId=1087}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:27:54');
INSERT INTO `sys_oper_log` VALUES ('98', '菜单管理', '3', 'com.ibotn.web.controller.system.SysMenuController.remove()', 'DELETE', '1', 'admin', null, '/system/menu/1086', '127.0.0.1', '内网IP', '{menuId=1086}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:28:14');
INSERT INTO `sys_oper_log` VALUES ('99', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"createTime\":\"2022-06-01 06:30:15\",\"icon\":\"documentation\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1061,\"menuName\":\"事务管理\",\"menuType\":\"M\",\"orderNum\":2,\"params\":{},\"parentId\":0,\"path\":\"affairManage\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:28:42');
INSERT INTO `sys_oper_log` VALUES ('100', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"\",\"createTime\":\"2022-06-01 06:37:34\",\"icon\":\"documentation\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1066,\"menuName\":\"考勤\",\"menuType\":\"M\",\"orderNum\":3,\"params\":{},\"parentId\":0,\"path\":\"checkWork\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:28:48');
INSERT INTO `sys_oper_log` VALUES ('101', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"createTime\":\"2022-06-01 07:05:23\",\"icon\":\"documentation\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1069,\"menuName\":\"安全管理\",\"menuType\":\"M\",\"orderNum\":5,\"params\":{},\"parentId\":0,\"path\":\"saftyManage\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:28:56');
INSERT INTO `sys_oper_log` VALUES ('102', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"createTime\":\"2022-06-01 07:33:39\",\"icon\":\"documentation\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1074,\"menuName\":\"园所信息\",\"menuType\":\"M\",\"orderNum\":6,\"params\":{},\"parentId\":0,\"path\":\"parkInformation\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:29:04');
INSERT INTO `sys_oper_log` VALUES ('103', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"createTime\":\"2022-06-01 07:40:02\",\"icon\":\"documentation\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1077,\"menuName\":\"后勤管理\",\"menuType\":\"M\",\"orderNum\":7,\"params\":{},\"parentId\":0,\"path\":\"logisticsManage\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:29:12');
INSERT INTO `sys_oper_log` VALUES ('104', '菜单管理', '3', 'com.ibotn.web.controller.system.SysMenuController.remove()', 'DELETE', '1', 'admin', null, '/system/menu/4', '127.0.0.1', '内网IP', '{menuId=4}', '{\"msg\":\"菜单已分配,不允许删除\",\"code\":500}', '0', null, '2022-06-01 08:31:45');
INSERT INTO `sys_oper_log` VALUES ('105', '用户头像', '2', 'com.ibotn.web.controller.system.SysProfileController.avatar()', 'POST', '1', 'admin', null, '/system/user/profile/avatar', '127.0.0.1', '内网IP', '', '{\"msg\":\"操作成功\",\"imgUrl\":\"/profile/avatar/2022/06/01/blob_20220601163211A001.jpeg\",\"code\":200}', '0', null, '2022-06-01 08:32:11');
INSERT INTO `sys_oper_log` VALUES ('106', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"affairManage/materialPurchase/index\",\"createTime\":\"2022-06-01 06:33:54\",\"icon\":\"money\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1063,\"menuName\":\"物资申购\",\"menuType\":\"C\",\"orderNum\":2,\"params\":{},\"parentId\":1061,\"path\":\"materialPurchase\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:40:11');
INSERT INTO `sys_oper_log` VALUES ('107', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"checkWork/babyWork/index\",\"createTime\":\"2022-06-01 07:03:51\",\"icon\":\"user\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1068,\"menuName\":\"宝贝考勤\",\"menuType\":\"C\",\"orderNum\":2,\"params\":{},\"parentId\":1066,\"path\":\"babyWork\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:40:36');
INSERT INTO `sys_oper_log` VALUES ('108', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"saftyManage/securityPatrol/index\",\"createTime\":\"2022-06-01 07:13:23\",\"icon\":\"server\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1071,\"menuName\":\"安防巡查\",\"menuType\":\"C\",\"orderNum\":2,\"params\":{},\"parentId\":1069,\"path\":\"securityPatrol\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:41:25');
INSERT INTO `sys_oper_log` VALUES ('109', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"saftyManage/securityPatrol/index\",\"createTime\":\"2022-06-01 07:13:23\",\"icon\":\"dict\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1071,\"menuName\":\"安防巡查\",\"menuType\":\"C\",\"orderNum\":2,\"params\":{},\"parentId\":1069,\"path\":\"securityPatrol\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:41:35');
INSERT INTO `sys_oper_log` VALUES ('110', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"saftyManage/goodSafty/index\",\"createTime\":\"2022-06-01 07:15:34\",\"icon\":\"international\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1072,\"menuName\":\"食品安全\",\"menuType\":\"C\",\"orderNum\":3,\"params\":{},\"parentId\":1069,\"path\":\"goodSafty\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:41:52');
INSERT INTO `sys_oper_log` VALUES ('111', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"saftyManage/epidemicPrevention/index\",\"createTime\":\"2022-06-01 07:16:19\",\"icon\":\"phone\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1073,\"menuName\":\"防疫\",\"menuType\":\"C\",\"orderNum\":4,\"params\":{},\"parentId\":1069,\"path\":\"epidemicPrevention\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:42:01');
INSERT INTO `sys_oper_log` VALUES ('112', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"parkInformation/departmentManagement/index\",\"createTime\":\"2022-06-01 07:37:47\",\"icon\":\"row\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1075,\"menuName\":\"部门管理\",\"menuType\":\"C\",\"orderNum\":1,\"params\":{},\"parentId\":1074,\"path\":\"departmentManagement\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:42:18');
INSERT INTO `sys_oper_log` VALUES ('113', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"parkInformation/classManage/index\",\"createTime\":\"2022-06-01 07:38:40\",\"icon\":\"redis\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1076,\"menuName\":\"班级管理\",\"menuType\":\"C\",\"orderNum\":2,\"params\":{},\"parentId\":1074,\"path\":\"classManage\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:42:27');
INSERT INTO `sys_oper_log` VALUES ('114', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"logisticsManage/kitchen/index\",\"createTime\":\"2022-06-01 07:40:48\",\"icon\":\"log\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1078,\"menuName\":\"厨房\",\"menuType\":\"C\",\"orderNum\":1,\"params\":{},\"parentId\":1077,\"path\":\"kitchen\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:42:39');
INSERT INTO `sys_oper_log` VALUES ('115', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"logisticsManage/warehouse/index\",\"createTime\":\"2022-06-01 07:42:43\",\"icon\":\"log\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1079,\"menuName\":\"仓库\",\"menuType\":\"C\",\"orderNum\":2,\"params\":{},\"parentId\":1077,\"path\":\"warehouse\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:42:49');
INSERT INTO `sys_oper_log` VALUES ('116', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"logisticsManage/fixedAssets/index\",\"createTime\":\"2022-06-01 07:44:16\",\"icon\":\"money\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1080,\"menuName\":\"固定资产\",\"menuType\":\"C\",\"orderNum\":3,\"params\":{},\"parentId\":1077,\"path\":\"fixedAssets\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:43:05');
INSERT INTO `sys_oper_log` VALUES ('117', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"financeManage/billManage/index\",\"createTime\":\"2022-06-01 07:46:32\",\"icon\":\"message\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1082,\"menuName\":\"账单管理\",\"menuType\":\"C\",\"orderNum\":1,\"params\":{},\"parentId\":1081,\"path\":\"billManage\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:43:35');
INSERT INTO `sys_oper_log` VALUES ('118', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '127.0.0.1', '内网IP', '{\"children\":[],\"component\":\"financeManage/payService/index\",\"createTime\":\"2022-06-01 07:48:29\",\"icon\":\"list\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":1083,\"menuName\":\"收费项目\",\"menuType\":\"C\",\"orderNum\":2,\"params\":{},\"parentId\":1081,\"path\":\"payService\",\"perms\":\"\",\"status\":\"0\",\"updateBy\":\"admin\",\"visible\":\"0\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-01 08:43:47');
INSERT INTO `sys_oper_log` VALUES ('119', '用户管理', '5', 'com.ibotn.web.controller.system.SysUserController.export()', 'POST', '1', 'admin', null, '/system/user/export', '127.0.0.1', '内网IP', '{\"admin\":false,\"params\":{\"dataScope\":\"\"}}', null, '0', null, '2022-06-01 11:40:33');
INSERT INTO `sys_oper_log` VALUES ('120', '菜单管理', '3', 'com.ibotn.web.controller.system.SysMenuController.remove()', 'DELETE', '1', 'admin', null, '/system/menu/4', '127.0.0.1', '内网IP', '{menuId=4}', '{\"msg\":\"菜单已分配,不允许删除\",\"code\":500}', '0', null, '2022-06-01 11:47:00');
INSERT INTO `sys_oper_log` VALUES ('121', '菜单管理', '3', 'com.ibotn.web.controller.system.SysMenuController.remove()', 'DELETE', '1', 'admin', null, '/system/menu/2', '127.0.0.1', '内网IP', '{menuId=2}', '{\"msg\":\"存在子菜单,不允许删除\",\"code\":500}', '0', null, '2022-06-01 11:47:17');
INSERT INTO `sys_oper_log` VALUES ('122', '菜单管理', '3', 'com.ibotn.web.controller.system.SysMenuController.remove()', 'DELETE', '1', 'admin', null, '/system/menu/113', '127.0.0.1', '内网IP', '{menuId=113}', '{\"msg\":\"菜单已分配,不允许删除\",\"code\":500}', '0', null, '2022-06-01 11:47:23');
INSERT INTO `sys_oper_log` VALUES ('123', '菜单管理', '3', 'com.ibotn.web.controller.system.SysMenuController.remove()', 'DELETE', '1', 'admin', null, '/system/menu/112', '127.0.0.1', '内网IP', '{menuId=112}', '{\"msg\":\"菜单已分配,不允许删除\",\"code\":500}', '0', null, '2022-06-01 11:47:27');
INSERT INTO `sys_oper_log` VALUES ('124', '菜单管理', '3', 'com.ibotn.web.controller.system.SysMenuController.remove()', 'DELETE', '1', 'admin', null, '/system/menu/4', '183.14.28.13', 'XX XX', '{menuId=4}', '{\"msg\":\"菜单已分配,不允许删除\",\"code\":500}', '0', null, '2022-06-02 02:06:20');
INSERT INTO `sys_oper_log` VALUES ('125', '菜单管理', '2', 'com.ibotn.web.controller.system.SysMenuController.edit()', 'PUT', '1', 'admin', null, '/system/menu', '183.14.28.13', 'XX XX', '{\"children\":[],\"createTime\":\"2022-05-29 12:33:28\",\"icon\":\"monitor\",\"isCache\":\"0\",\"isFrame\":\"1\",\"menuId\":2,\"menuName\":\"系统监控\",\"menuType\":\"M\",\"orderNum\":2,\"params\":{},\"parentId\":0,\"path\":\"monitor\",\"perms\":\"\",\"query\":\"\",\"status\":\"1\",\"updateBy\":\"admin\",\"visible\":\"1\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-02 02:16:20');
INSERT INTO `sys_oper_log` VALUES ('126', '个人信息', '2', 'com.ibotn.web.controller.system.SysProfileController.updateProfile()', 'PUT', '1', 'admin', null, '/system/user/profile', '183.14.28.13', 'XX XX', '{\"admin\":true,\"avatar\":\"/profile/avatar/2022/06/01/blob_20220601163211A001.jpeg\",\"createBy\":\"admin\",\"createTime\":\"2022-05-29 12:33:26\",\"delFlag\":\"0\",\"dept\":{\"ancestors\":\"0,100,101\",\"children\":[],\"deptId\":103,\"deptName\":\"a部门\",\"leader\":\"李\",\"orderNum\":1,\"params\":{},\"parentId\":101,\"status\":\"0\"},\"deptId\":103,\"email\":\"sw@ibotn.com\",\"loginDate\":\"2022-06-02 09:10:15\",\"loginIp\":\"127.0.0.1\",\"nickName\":\"ibotn\",\"params\":{},\"phonenumber\":\"15888888888\",\"remark\":\"管理员\",\"roles\":[{\"admin\":true,\"dataScope\":\"1\",\"deptCheckStrictly\":false,\"flag\":false,\"menuCheckStrictly\":false,\"params\":{},\"roleId\":1,\"roleKey\":\"admin\",\"roleName\":\"超级管理员\",\"roleSort\":\"1\",\"status\":\"0\"}],\"sex\":\"0\",\"status\":\"0\",\"userId\":1,\"userName\":\"admin\"}', '{\"msg\":\"操作成功\",\"code\":200}', '0', null, '2022-06-02 02:18:21');

-- ----------------------------
-- Table structure for sys_post
-- ----------------------------
DROP TABLE IF EXISTS `sys_post`;
CREATE TABLE `sys_post` (
  `post_id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '岗位ID',
  `post_code` varchar(64) NOT NULL COMMENT '岗位编码',
  `post_name` varchar(50) NOT NULL COMMENT '岗位名称',
  `post_sort` int(4) NOT NULL COMMENT '显示顺序',
  `status` char(1) NOT NULL COMMENT '状态（0正常 1停用）',
  `create_by` varchar(64) DEFAULT '' COMMENT '创建者',
  `create_time` datetime DEFAULT NULL COMMENT '创建时间',
  `update_by` varchar(64) DEFAULT '' COMMENT '更新者',
  `update_time` datetime DEFAULT NULL COMMENT '更新时间',
  `remark` varchar(500) DEFAULT NULL COMMENT '备注',
  PRIMARY KEY (`post_id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8 COMMENT='岗位信息表';

-- ----------------------------
-- Records of sys_post
-- ----------------------------
INSERT INTO `sys_post` VALUES ('1', 'ceo', '董事长', '1', '0', 'admin', '2022-05-29 12:33:27', '', null, '');
INSERT INTO `sys_post` VALUES ('2', 'se', '项目经理', '2', '0', 'admin', '2022-05-29 12:33:27', '', null, '');
INSERT INTO `sys_post` VALUES ('3', 'hr', '人力资源', '3', '0', 'admin', '2022-05-29 12:33:27', '', null, '');
INSERT INTO `sys_post` VALUES ('4', 'user', '普通员工', '4', '0', 'admin', '2022-05-29 12:33:27', '', null, '');

-- ----------------------------
-- Table structure for sys_role
-- ----------------------------
DROP TABLE IF EXISTS `sys_role`;
CREATE TABLE `sys_role` (
  `role_id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '角色ID',
  `role_name` varchar(30) NOT NULL COMMENT '角色名称',
  `role_key` varchar(100) NOT NULL COMMENT '角色权限字符串',
  `role_sort` int(4) NOT NULL COMMENT '显示顺序',
  `data_scope` char(1) DEFAULT '1' COMMENT '数据范围（1：全部数据权限 2：自定数据权限 3：本部门数据权限 4：本部门及以下数据权限）',
  `menu_check_strictly` tinyint(1) DEFAULT '1' COMMENT '菜单树选择项是否关联显示',
  `dept_check_strictly` tinyint(1) DEFAULT '1' COMMENT '部门树选择项是否关联显示',
  `status` char(1) NOT NULL COMMENT '角色状态（0正常 1停用）',
  `del_flag` char(1) DEFAULT '0' COMMENT '删除标志（0代表存在 2代表删除）',
  `create_by` varchar(64) DEFAULT '' COMMENT '创建者',
  `create_time` datetime DEFAULT NULL COMMENT '创建时间',
  `update_by` varchar(64) DEFAULT '' COMMENT '更新者',
  `update_time` datetime DEFAULT NULL COMMENT '更新时间',
  `remark` varchar(500) DEFAULT NULL COMMENT '备注',
  PRIMARY KEY (`role_id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 COMMENT='角色信息表';

-- ----------------------------
-- Records of sys_role
-- ----------------------------
INSERT INTO `sys_role` VALUES ('1', '超级管理员', 'admin', '1', '1', '1', '1', '0', '0', 'admin', '2022-05-29 12:33:27', '', null, '超级管理员');
INSERT INTO `sys_role` VALUES ('2', '普通角色', 'common', '2', '2', '1', '1', '0', '0', 'admin', '2022-05-29 12:33:27', 'admin', '2022-05-31 07:02:15', '普通角色');

-- ----------------------------
-- Table structure for sys_role_dept
-- ----------------------------
DROP TABLE IF EXISTS `sys_role_dept`;
CREATE TABLE `sys_role_dept` (
  `role_id` bigint(20) NOT NULL COMMENT '角色ID',
  `dept_id` bigint(20) NOT NULL COMMENT '部门ID',
  PRIMARY KEY (`role_id`,`dept_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='角色和部门关联表';

-- ----------------------------
-- Records of sys_role_dept
-- ----------------------------
INSERT INTO `sys_role_dept` VALUES ('2', '100');
INSERT INTO `sys_role_dept` VALUES ('2', '101');
INSERT INTO `sys_role_dept` VALUES ('2', '105');

-- ----------------------------
-- Table structure for sys_role_menu
-- ----------------------------
DROP TABLE IF EXISTS `sys_role_menu`;
CREATE TABLE `sys_role_menu` (
  `role_id` bigint(20) NOT NULL COMMENT '角色ID',
  `menu_id` bigint(20) NOT NULL COMMENT '菜单ID',
  PRIMARY KEY (`role_id`,`menu_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='角色和菜单关联表';

-- ----------------------------
-- Records of sys_role_menu
-- ----------------------------
INSERT INTO `sys_role_menu` VALUES ('2', '1');
INSERT INTO `sys_role_menu` VALUES ('2', '2');
INSERT INTO `sys_role_menu` VALUES ('2', '3');
INSERT INTO `sys_role_menu` VALUES ('2', '4');
INSERT INTO `sys_role_menu` VALUES ('2', '100');
INSERT INTO `sys_role_menu` VALUES ('2', '101');
INSERT INTO `sys_role_menu` VALUES ('2', '102');
INSERT INTO `sys_role_menu` VALUES ('2', '103');
INSERT INTO `sys_role_menu` VALUES ('2', '104');
INSERT INTO `sys_role_menu` VALUES ('2', '105');
INSERT INTO `sys_role_menu` VALUES ('2', '106');
INSERT INTO `sys_role_menu` VALUES ('2', '107');
INSERT INTO `sys_role_menu` VALUES ('2', '108');
INSERT INTO `sys_role_menu` VALUES ('2', '109');
INSERT INTO `sys_role_menu` VALUES ('2', '110');
INSERT INTO `sys_role_menu` VALUES ('2', '111');
INSERT INTO `sys_role_menu` VALUES ('2', '112');
INSERT INTO `sys_role_menu` VALUES ('2', '113');
INSERT INTO `sys_role_menu` VALUES ('2', '114');
INSERT INTO `sys_role_menu` VALUES ('2', '115');
INSERT INTO `sys_role_menu` VALUES ('2', '116');
INSERT INTO `sys_role_menu` VALUES ('2', '500');
INSERT INTO `sys_role_menu` VALUES ('2', '501');
INSERT INTO `sys_role_menu` VALUES ('2', '1001');
INSERT INTO `sys_role_menu` VALUES ('2', '1002');
INSERT INTO `sys_role_menu` VALUES ('2', '1003');
INSERT INTO `sys_role_menu` VALUES ('2', '1004');
INSERT INTO `sys_role_menu` VALUES ('2', '1005');
INSERT INTO `sys_role_menu` VALUES ('2', '1006');
INSERT INTO `sys_role_menu` VALUES ('2', '1007');
INSERT INTO `sys_role_menu` VALUES ('2', '1008');
INSERT INTO `sys_role_menu` VALUES ('2', '1009');
INSERT INTO `sys_role_menu` VALUES ('2', '1010');
INSERT INTO `sys_role_menu` VALUES ('2', '1011');
INSERT INTO `sys_role_menu` VALUES ('2', '1012');
INSERT INTO `sys_role_menu` VALUES ('2', '1013');
INSERT INTO `sys_role_menu` VALUES ('2', '1014');
INSERT INTO `sys_role_menu` VALUES ('2', '1015');
INSERT INTO `sys_role_menu` VALUES ('2', '1016');
INSERT INTO `sys_role_menu` VALUES ('2', '1017');
INSERT INTO `sys_role_menu` VALUES ('2', '1018');
INSERT INTO `sys_role_menu` VALUES ('2', '1019');
INSERT INTO `sys_role_menu` VALUES ('2', '1020');
INSERT INTO `sys_role_menu` VALUES ('2', '1021');
INSERT INTO `sys_role_menu` VALUES ('2', '1022');
INSERT INTO `sys_role_menu` VALUES ('2', '1023');
INSERT INTO `sys_role_menu` VALUES ('2', '1024');
INSERT INTO `sys_role_menu` VALUES ('2', '1025');
INSERT INTO `sys_role_menu` VALUES ('2', '1026');
INSERT INTO `sys_role_menu` VALUES ('2', '1027');
INSERT INTO `sys_role_menu` VALUES ('2', '1028');
INSERT INTO `sys_role_menu` VALUES ('2', '1029');
INSERT INTO `sys_role_menu` VALUES ('2', '1030');
INSERT INTO `sys_role_menu` VALUES ('2', '1031');
INSERT INTO `sys_role_menu` VALUES ('2', '1032');
INSERT INTO `sys_role_menu` VALUES ('2', '1033');
INSERT INTO `sys_role_menu` VALUES ('2', '1034');
INSERT INTO `sys_role_menu` VALUES ('2', '1035');
INSERT INTO `sys_role_menu` VALUES ('2', '1036');
INSERT INTO `sys_role_menu` VALUES ('2', '1037');
INSERT INTO `sys_role_menu` VALUES ('2', '1038');
INSERT INTO `sys_role_menu` VALUES ('2', '1039');
INSERT INTO `sys_role_menu` VALUES ('2', '1040');
INSERT INTO `sys_role_menu` VALUES ('2', '1041');
INSERT INTO `sys_role_menu` VALUES ('2', '1042');
INSERT INTO `sys_role_menu` VALUES ('2', '1043');
INSERT INTO `sys_role_menu` VALUES ('2', '1044');
INSERT INTO `sys_role_menu` VALUES ('2', '1045');
INSERT INTO `sys_role_menu` VALUES ('2', '1046');
INSERT INTO `sys_role_menu` VALUES ('2', '1047');
INSERT INTO `sys_role_menu` VALUES ('2', '1048');
INSERT INTO `sys_role_menu` VALUES ('2', '1049');
INSERT INTO `sys_role_menu` VALUES ('2', '1050');
INSERT INTO `sys_role_menu` VALUES ('2', '1051');
INSERT INTO `sys_role_menu` VALUES ('2', '1052');
INSERT INTO `sys_role_menu` VALUES ('2', '1053');
INSERT INTO `sys_role_menu` VALUES ('2', '1054');
INSERT INTO `sys_role_menu` VALUES ('2', '1055');
INSERT INTO `sys_role_menu` VALUES ('2', '1056');
INSERT INTO `sys_role_menu` VALUES ('2', '1057');
INSERT INTO `sys_role_menu` VALUES ('2', '1058');
INSERT INTO `sys_role_menu` VALUES ('2', '1059');
INSERT INTO `sys_role_menu` VALUES ('2', '1060');

-- ----------------------------
-- Table structure for sys_user
-- ----------------------------
DROP TABLE IF EXISTS `sys_user`;
CREATE TABLE `sys_user` (
  `user_id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '用户ID',
  `dept_id` bigint(20) DEFAULT NULL COMMENT '部门ID',
  `user_name` varchar(30) NOT NULL COMMENT '用户账号',
  `nick_name` varchar(30) NOT NULL COMMENT '用户昵称',
  `user_type` varchar(2) DEFAULT '00' COMMENT '用户类型（00系统用户）',
  `email` varchar(50) DEFAULT '' COMMENT '用户邮箱',
  `phonenumber` varchar(11) DEFAULT '' COMMENT '手机号码',
  `sex` char(1) DEFAULT '0' COMMENT '用户性别（0男 1女 2未知）',
  `avatar` varchar(100) DEFAULT '' COMMENT '头像地址',
  `password` varchar(100) DEFAULT '' COMMENT '密码',
  `status` char(1) DEFAULT '0' COMMENT '帐号状态（0正常 1停用）',
  `del_flag` char(1) DEFAULT '0' COMMENT '删除标志（0代表存在 2代表删除）',
  `login_ip` varchar(128) DEFAULT '' COMMENT '最后登录IP',
  `login_date` datetime DEFAULT NULL COMMENT '最后登录时间',
  `create_by` varchar(64) DEFAULT '' COMMENT '创建者',
  `create_time` datetime DEFAULT NULL COMMENT '创建时间',
  `update_by` varchar(64) DEFAULT '' COMMENT '更新者',
  `update_time` datetime DEFAULT NULL COMMENT '更新时间',
  `remark` varchar(500) DEFAULT NULL COMMENT '备注',
  PRIMARY KEY (`user_id`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8 COMMENT='用户信息表';

-- ----------------------------
-- Records of sys_user
-- ----------------------------
INSERT INTO `sys_user` VALUES ('1', '103', 'admin', 'ibotn', '00', 'sw@ibotn.com', '15888888888', '0', '/profile/avatar/2022/06/01/blob_20220601163211A001.jpeg', '$2a$10$7JB720yubVSZvUI0rEqK/.VqGOZTH.ulu33dHOiBE8ByOhJIrdAu2', '0', '0', '127.0.0.1', '2022-06-02 09:10:15', 'admin', '2022-05-29 12:33:26', '', '2022-06-02 02:18:21', '管理员');
INSERT INTO `sys_user` VALUES ('2', '105', 'ry', '若依', '00', 'ry@qq.com', '15666666666', '1', '', '$2a$10$7JB720yubVSZvUI0rEqK/.VqGOZTH.ulu33dHOiBE8ByOhJIrdAu2', '0', '0', '127.0.0.1', '2022-05-29 12:33:27', 'admin', '2022-05-29 12:33:27', '', null, '测试员');
INSERT INTO `sys_user` VALUES ('3', '100', 'zhonhai', 'zhonhai', '00', '', '18126495953', '0', '', '$2a$10$SGoKF6OshF4617jQvI.GreMV12Z1i2PhT9oTl3ZrN88UNMTienJge', '0', '0', '127.0.0.1', '2022-05-31 19:12:20', 'admin', '2022-05-31 06:30:40', 'admin', '2022-05-31 11:12:19', '我是钟海');
INSERT INTO `sys_user` VALUES ('5', null, 'o4THO4n60CTl5rY55cvuVfz-V5cY', '鼎盛智能', '00', '', '', '0', '', '$2a$10$s99OwGyvyOoLw4PiF1SVmeZdBXB2PeegXWELccfkyMWzcu6fbbH7C', '0', '0', '127.0.0.1', '2022-06-01 11:37:04', 'wxmini', '2022-06-01 03:29:03', '', '2022-06-01 03:37:04', null);

-- ----------------------------
-- Table structure for sys_user_post
-- ----------------------------
DROP TABLE IF EXISTS `sys_user_post`;
CREATE TABLE `sys_user_post` (
  `user_id` bigint(20) NOT NULL COMMENT '用户ID',
  `post_id` bigint(20) NOT NULL COMMENT '岗位ID',
  PRIMARY KEY (`user_id`,`post_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='用户与岗位关联表';

-- ----------------------------
-- Records of sys_user_post
-- ----------------------------
INSERT INTO `sys_user_post` VALUES ('1', '1');
INSERT INTO `sys_user_post` VALUES ('2', '2');
INSERT INTO `sys_user_post` VALUES ('3', '1');

-- ----------------------------
-- Table structure for sys_user_role
-- ----------------------------
DROP TABLE IF EXISTS `sys_user_role`;
CREATE TABLE `sys_user_role` (
  `user_id` bigint(20) NOT NULL COMMENT '用户ID',
  `role_id` bigint(20) NOT NULL COMMENT '角色ID',
  PRIMARY KEY (`user_id`,`role_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='用户和角色关联表';

-- ----------------------------
-- Records of sys_user_role
-- ----------------------------
INSERT INTO `sys_user_role` VALUES ('1', '1');
INSERT INTO `sys_user_role` VALUES ('2', '2');
INSERT INTO `sys_user_role` VALUES ('3', '2');
