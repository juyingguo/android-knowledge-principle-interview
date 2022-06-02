/*
SQLyog Ultimate v12.08 (64 bit)
MySQL - 5.5.27 : Database - test
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
CREATE DATABASE /*!32312 IF NOT EXISTS*/`test` /*!40100 DEFAULT CHARACTER SET utf8 */;

USE `test`;

/*Table structure for table `tb_category` */

DROP TABLE IF EXISTS `tb_category`;

CREATE TABLE `tb_category` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(64) DEFAULT NULL COMMENT '分类名称',
  `parent_id` int(11) unsigned zerofill DEFAULT NULL COMMENT '0:为大分类,大于0为子分类',
  `state` tinyint(3) unsigned zerofill DEFAULT NULL COMMENT '状态,0:正常,1:禁用',
  `sort_num` int(11) unsigned zerofill DEFAULT NULL COMMENT '排序序号',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8;

/*Data for the table `tb_category` */

insert  into `tb_category`(`id`,`name`,`parent_id`,`state`,`sort_num`) values (1,'家具',00000000000,000,00000000000),(2,'办公家具',00000000001,000,00000000000),(3,'班级家具',00000000001,000,00000000000),(4,'电器',00000000000,000,00000000000),(5,'办公电器',00000000004,000,00000000000),(7,'家用电器',00000000004,NULL,NULL);

/*Table structure for table `tb_temp_delete_test` */

DROP TABLE IF EXISTS `tb_temp_delete_test`;

CREATE TABLE `tb_temp_delete_test` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `name` varchar(64) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8;

/*Data for the table `tb_temp_delete_test` */

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
