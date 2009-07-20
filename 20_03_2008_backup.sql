-- MySQL dump 10.11
--
-- Host: localhost    Database: post_rest
-- ------------------------------------------------------
-- Server version	5.0.45

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `dishes`
--

DROP TABLE IF EXISTS `dishes`;
CREATE TABLE `dishes` (
  `id` int(11) NOT NULL auto_increment,
  `name` text collate utf8_unicode_ci NOT NULL,
  `price` double NOT NULL,
  `menu_id` int(11) NOT NULL,
  `comment` text collate utf8_unicode_ci NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=37 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `dishes`
--

LOCK TABLES `dishes` WRITE;
/*!40000 ALTER TABLE `dishes` DISABLE KEYS */;
INSERT INTO `dishes` VALUES (19,'Mountain Man brat',7.95,9,'Comes with ketchup.'),(20,'Beef brat',7.95,9,'Comes with ketchup.'),(18,'Beef burger',6.95,9,'Comes with ketchup.'),(17,'Elk burger',7.95,9,'Comes with ketchup.'),(16,'Cinamon French Toast',8.95,8,'Comes with syrop or honey.'),(15,'Corncakes',8.95,8,'Comes with syrop or honey.'),(14,'Pancakes',8.95,8,'Comes with syrop or honey.'),(21,'Fish & Fries',7.95,9,'Comes with Tartar Sauce!'),(22,'Elk stew',13.95,10,'Comes with salad first.'),(23,'Beef stew',12.95,10,'Comes with salad first.'),(24,'Coca-cola',0.95678,11,''),(25,'Sprite',1.95,11,''),(26,'Root Beer',1.95,11,''),(27,'Coca-cola Light',1.95,11,''),(28,'Ice Tea',1.95,11,''),(29,'Coffee Dark',1.95,11,''),(30,'Coffe Medium',1.95,11,''),(31,'Coffee Decaf',1.95,11,''),(32,'Wine (bottle)',17.95,12,''),(33,'Wine (glass)',4.95,12,''),(34,'Reg. beer',2.95,12,''),(35,'Premium beer',3.95,12,''),(36,'Cranberry stew',14.95,10,'Very spicy');
/*!40000 ALTER TABLE `dishes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `dishes_parts`
--

DROP TABLE IF EXISTS `dishes_parts`;
CREATE TABLE `dishes_parts` (
  `id` int(11) NOT NULL auto_increment,
  `dishes_id` int(11) NOT NULL,
  `parts_id` int(11) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=52 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `dishes_parts`
--

LOCK TABLES `dishes_parts` WRITE;
/*!40000 ALTER TABLE `dishes_parts` DISABLE KEYS */;
INSERT INTO `dishes_parts` VALUES (46,15,36),(21,22,52),(22,22,0),(23,23,53),(24,23,0),(25,19,46),(26,19,0),(27,20,47),(28,20,0),(29,18,45),(30,18,42),(31,18,41),(32,18,40),(33,18,39),(34,18,0),(35,17,38),(36,17,42),(37,17,41),(38,17,40),(39,17,39),(40,17,0),(41,21,51),(42,16,37),(43,16,0),(47,15,0),(48,14,30),(49,14,0),(50,36,56),(51,36,0);
/*!40000 ALTER TABLE `dishes_parts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `dishes_parts_ors`
--

DROP TABLE IF EXISTS `dishes_parts_ors`;
CREATE TABLE `dishes_parts_ors` (
  `id` int(11) NOT NULL auto_increment,
  `dishes_parts_id` int(11) NOT NULL,
  `parts_id` int(11) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=37 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `dishes_parts_ors`
--

LOCK TABLES `dishes_parts_ors` WRITE;
/*!40000 ALTER TABLE `dishes_parts_ors` DISABLE KEYS */;
INSERT INTO `dishes_parts_ors` VALUES (15,22,54),(16,22,55),(17,24,54),(18,24,55),(19,26,43),(20,26,44),(21,28,43),(22,28,44),(23,34,43),(24,34,44),(25,40,43),(26,40,44),(27,43,32),(28,43,31),(32,47,31),(31,47,32),(33,49,32),(34,49,31),(35,51,54),(36,51,55);
/*!40000 ALTER TABLE `dishes_parts_ors` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `groups`
--

DROP TABLE IF EXISTS `groups`;
CREATE TABLE `groups` (
  `id` int(11) NOT NULL auto_increment,
  `name` text collate utf8_unicode_ci NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=25 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `groups`
--

LOCK TABLES `groups` WRITE;
/*!40000 ALTER TABLE `groups` DISABLE KEYS */;
INSERT INTO `groups` VALUES (17,'fries'),(16,'burger addons'),(14,'toasts'),(15,'burgers'),(13,'breakfast'),(18,'brats'),(19,'other'),(20,'brat addons'),(21,'stew'),(22,'breads');
/*!40000 ALTER TABLE `groups` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `menus`
--

DROP TABLE IF EXISTS `menus`;
CREATE TABLE `menus` (
  `id` int(11) NOT NULL auto_increment,
  `name` text collate utf8_unicode_ci NOT NULL,
  `tax_id` int(11) NOT NULL,
  `show` tinyint(1) NOT NULL default '1',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=13 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `menus`
--

LOCK TABLES `menus` WRITE;
/*!40000 ALTER TABLE `menus` DISABLE KEYS */;
INSERT INTO `menus` VALUES (11,'Beverages',1,1),(10,'Dinner',1,1),(9,'Lunch',1,1),(8,'Breakfastt',1,1),(12,'Alc. beverages',3,1);
/*!40000 ALTER TABLE `menus` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `orders`
--

DROP TABLE IF EXISTS `orders`;
CREATE TABLE `orders` (
  `id` int(11) NOT NULL auto_increment,
  `number` int(11) NOT NULL,
  `time` timestamp NOT NULL default CURRENT_TIMESTAMP,
  `time_served` timestamp NOT NULL default '0000-00-00 00:00:00',
  `status` int(11) NOT NULL COMMENT '0 - just taken, 1 - served, 2 - paid',
  `pay_type` int(11) NOT NULL COMMENT '1- cash, 2 - charge',
  `amount` double NOT NULL COMMENT 'amount paid',
  `waiter_id` int(11) NOT NULL,
  `comment` text collate utf8_unicode_ci NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=76 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `orders`
--

LOCK TABLES `orders` WRITE;
/*!40000 ALTER TABLE `orders` DISABLE KEYS */;
INSERT INTO `orders` VALUES (31,3,'2008-03-15 17:54:54','0000-00-00 00:00:00',2,0,0,0,''),(30,2,'2008-03-15 17:53:41','0000-00-00 00:00:00',0,0,0,0,''),(29,1,'2008-03-15 17:53:19','0000-00-00 00:00:00',2,1,100,0,''),(32,4,'2008-03-15 18:02:28','0000-00-00 00:00:00',0,0,0,0,''),(33,1,'2008-03-16 13:19:03','0000-00-00 00:00:00',2,0,0,0,''),(34,2,'2008-03-16 13:19:14','0000-00-00 00:00:00',2,0,0,0,''),(35,3,'2008-03-16 13:19:21','0000-00-00 00:00:00',2,0,0,0,''),(36,4,'2008-03-16 13:19:54','0000-00-00 00:00:00',2,0,0,0,''),(37,5,'2008-03-16 13:23:03','0000-00-00 00:00:00',2,47,47.46,0,''),(38,6,'2008-03-16 13:33:10','0000-00-00 00:00:00',2,32,31.98,0,''),(39,7,'2008-03-16 13:33:31','0000-00-00 00:00:00',2,42,42.32,0,''),(40,8,'2008-03-16 13:37:41','0000-00-00 00:00:00',2,2,27.88,0,''),(41,9,'2008-03-16 13:37:53','0000-00-00 00:00:00',2,1,13.15,0,''),(42,10,'2008-03-16 13:39:21','0000-00-00 00:00:00',2,1,27.88,0,''),(43,11,'2008-03-16 13:41:17','0000-00-00 00:00:00',2,1,40.24,0,''),(44,12,'2008-03-16 13:41:43','0000-00-00 00:00:00',2,1,27.88,0,''),(45,13,'2008-03-16 13:46:41','0000-00-00 00:00:00',2,1,27.88,0,''),(46,14,'2008-03-16 18:19:04','0000-00-00 00:00:00',2,1,9.29,0,''),(47,15,'2008-03-16 18:40:10','0000-00-00 00:00:00',2,2,24.27,0,''),(48,16,'2008-03-16 18:56:23','0000-00-00 00:00:00',2,2,103.85,0,''),(49,17,'2008-03-16 18:58:56','0000-00-00 00:00:00',2,2,117.94,0,''),(50,18,'2008-03-16 19:00:08','0000-00-00 00:00:00',2,2,38.51,0,''),(51,19,'2008-03-16 19:05:14','0000-00-00 00:00:00',2,2,11.23,0,''),(52,20,'2008-03-16 19:06:39','0000-00-00 00:00:00',2,2,2.97,0,''),(53,1,'2008-03-16 23:12:14','0000-00-00 00:00:00',2,2,30.42,0,''),(54,2,'2008-03-16 23:21:38','0000-00-00 00:00:00',2,2,5.32,0,''),(58,1,'2008-03-20 15:13:16','0000-00-00 00:00:00',2,2,48.5,7,'preved, medved!'),(59,2,'2008-03-20 15:29:56','0000-00-00 00:00:00',2,2,23.73,8,'babogy!'),(60,3,'2008-03-20 15:46:14','0000-00-00 00:00:00',2,1,40.24,2,''),(61,4,'2008-03-20 15:50:02','0000-00-00 00:00:00',2,1,27.88,2,''),(62,5,'2008-03-20 15:56:32','0000-00-00 00:00:00',2,1,23.73,2,''),(63,6,'2008-03-20 15:56:41','0000-00-00 00:00:00',2,1,40.24,2,''),(64,7,'2008-03-20 15:58:39','0000-00-00 00:00:00',2,2,31.98,2,''),(65,8,'2008-03-20 15:58:46','0000-00-00 00:00:00',2,1,32.93,2,''),(66,9,'2008-03-20 16:03:08','0000-00-00 00:00:00',2,2,31.98,2,''),(67,10,'2008-03-20 16:03:14','0000-00-00 00:00:00',2,1,23.73,2,''),(68,11,'2008-03-20 16:08:04','0000-00-00 00:00:00',2,2,40.24,5,'babogy'),(69,12,'2008-03-20 16:08:25','0000-00-00 00:00:00',2,1,52.5,7,'medvedu preved'),(70,13,'2008-03-20 16:13:30','0000-00-00 00:00:00',2,1,58.93,9,'gy'),(71,14,'2008-03-20 16:13:49','0000-00-00 00:00:00',2,1,34.95,7,'dfgfdgdgfd'),(72,15,'2008-03-20 16:17:29','0000-00-00 00:00:00',2,2,90.72,5,'gy :D'),(73,16,'2008-03-20 16:19:49','0000-00-00 00:00:00',2,1,32.24,6,''),(74,17,'2008-03-20 16:58:44','0000-00-00 00:00:00',2,1,23.73,2,''),(75,18,'2008-03-20 17:00:12','0000-00-00 00:00:00',2,2,31.98,2,'');
/*!40000 ALTER TABLE `orders` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `orders_dishes`
--

DROP TABLE IF EXISTS `orders_dishes`;
CREATE TABLE `orders_dishes` (
  `id` int(11) NOT NULL auto_increment,
  `order_id` int(11) NOT NULL,
  `qty` int(11) NOT NULL,
  `name` text collate utf8_unicode_ci NOT NULL,
  `price` double NOT NULL,
  `tax` double NOT NULL,
  `tax_id` int(11) NOT NULL,
  `comment` text collate utf8_unicode_ci NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=454 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `orders_dishes`
--

LOCK TABLES `orders_dishes` WRITE;
/*!40000 ALTER TABLE `orders_dishes` DISABLE KEYS */;
INSERT INTO `orders_dishes` VALUES (130,30,1,'Elk burger',7.95,0.03845,0,''),(129,30,1,'Beef burger',6.95,0.03845,0,''),(128,30,1,'Beef brat',7.95,0.03845,0,''),(148,33,1,'Corncakes',8.95,0.03845,0,''),(147,33,1,'Cinamon French Toast',8.95,0.03845,0,''),(127,30,1,'Mountain Man brat',7.95,0.03845,0,''),(146,29,1,'Beef brat',7.95,0.03845,0,''),(145,29,1,'Beef burger',6.95,0.03845,0,''),(131,30,1,'Fish & Fries',7.95,0.03845,0,''),(132,30,1,'Sprite',1.95,0.03845,0,''),(133,30,1,'Root Beer',1.95,0.03845,0,''),(134,30,1,'Coffe Medium',1.95,0.03845,0,''),(135,30,1,'Coffee Decaf',1.95,0.03845,0,''),(136,31,1,'Mountain Man brat',7.95,0.03845,0,''),(137,31,1,'Beef brat',7.95,0.03845,0,''),(138,31,1,'Beef burger',6.95,0.03845,0,''),(139,31,1,'Elk burger',7.95,0.03845,0,''),(140,31,1,'Fish & Fries',7.95,0.03845,0,''),(141,32,1,'Mountain Man brat',7.95,0.03845,0,''),(142,32,1,'Beef brat',7.95,0.03845,0,''),(143,32,1,'Beef burger',6.95,0.03845,0,''),(144,32,1,'Elk burger',7.95,0.03845,0,''),(149,33,1,'Pancakes',8.95,0.03845,0,''),(150,34,1,'Coca-cola',0.95678,0.03845,0,''),(151,34,1,'Coca-cola',0.95678,0.03845,0,''),(152,34,1,'Sprite',1.95,0.03845,0,''),(153,34,1,'Root Beer',1.95,0.03845,0,''),(154,34,1,'Coca-cola Light',1.95,0.03845,0,''),(155,34,1,'Coffee Decaf',1.95,0.03845,0,''),(156,34,1,'Coffe Medium',1.95,0.03845,0,''),(157,34,1,'Coffee Dark',1.95,0.03845,0,''),(158,34,1,'Coffee Dark',1.95,0.03845,0,''),(159,34,1,'Coffee Dark',1.95,0.03845,0,''),(160,34,1,'Ice Tea',1.95,0.03845,0,''),(161,35,1,'Elk stew',13.95,0.03845,0,''),(162,35,1,'Beef stew',12.95,0.03845,0,''),(163,35,1,'Mountain Man brat',7.95,0.03845,0,''),(164,35,1,'Beef brat',7.95,0.03845,0,''),(165,35,1,'Beef burger',6.95,0.03845,0,''),(166,35,1,'Elk burger',7.95,0.03845,0,''),(167,36,1,'Mountain Man brat',7.95,0.03845,0,''),(168,36,1,'Beef brat',7.95,0.03845,0,''),(173,37,1,'Beef brat',7.95,0.03845,0,''),(172,37,1,'Mountain Man brat',7.95,0.03845,0,''),(174,37,1,'Beef burger',6.95,0.03845,0,''),(175,37,1,'Mountain Man brat',7.95,0.03845,0,''),(176,37,1,'Beef brat',7.95,0.03845,0,''),(177,37,1,'Beef burger',6.95,0.03845,0,''),(184,38,1,'Beef burger',6.95,0.03845,0,''),(183,38,1,'Beef brat',7.95,0.03845,0,''),(182,38,1,'Mountain Man brat',7.95,0.03845,0,''),(185,38,1,'Elk burger',7.95,0.03845,0,''),(186,39,1,'Mountain Man brat',7.95,0.03845,0,''),(187,39,1,'Beef brat',7.95,0.03845,0,''),(188,39,1,'Elk burger',7.95,0.03845,0,''),(189,39,1,'Fish & Fries',7.95,0.03845,0,''),(190,39,1,'Cinamon French Toast',8.95,0.03845,0,''),(191,40,1,'Cinamon French Toast',8.95,0.03845,0,''),(192,40,1,'Corncakes',8.95,0.03845,0,''),(193,40,1,'Pancakes',8.95,0.03845,0,''),(194,41,1,'Coca-cola',0.95678,0.03845,0,''),(195,41,1,'Sprite',1.95,0.03845,0,''),(196,41,1,'Coca-cola Light',1.95,0.03845,0,''),(197,41,1,'Coffee Decaf',1.95,0.03845,0,''),(198,41,1,'Coffe Medium',1.95,0.03845,0,''),(199,41,1,'Coffee Dark',1.95,0.03845,0,''),(200,41,1,'Ice Tea',1.95,0.03845,0,''),(201,42,1,'Cinamon French Toast',8.95,0.03845,0,''),(202,42,1,'Corncakes',8.95,0.03845,0,''),(203,42,1,'Pancakes',8.95,0.03845,0,''),(204,43,1,'Mountain Man brat',7.95,0.03845,0,''),(205,43,1,'Beef brat',7.95,0.03845,0,''),(206,43,1,'Beef burger',6.95,0.03845,0,''),(207,43,1,'Elk burger',7.95,0.03845,0,''),(208,43,1,'Fish & Fries',7.95,0.03845,0,''),(209,44,1,'Cinamon French Toast',8.95,0.03845,0,''),(210,44,1,'Corncakes',8.95,0.03845,0,''),(211,44,1,'Pancakes',8.95,0.03845,0,''),(212,45,1,'Cinamon French Toast',8.95,0.03845,0,''),(213,45,1,'Corncakes',8.95,0.03845,0,''),(214,45,1,'Pancakes',8.95,0.03845,0,''),(215,46,1,'Cinamon French Toast',8.95,0.03845,0,''),(216,47,1,'prevedovka',23.45,0.0348,0,'horoszaja vodka!'),(217,48,1,'pszenicznaja',100,0.03845,0,'dorogaja'),(221,49,1,'ddddddd',12.34,0.03845,0,'rrtr'),(220,49,1,'fhfgh',1.23,0.03845,0,'dsda'),(222,49,1,'rgrtgtgtrgr',100,0.03845,0,'erfef'),(223,50,1,'Cinamon French Toast',8.95,0.03845,0,''),(224,50,1,'Corncakes',8.95,0.03845,0,''),(225,50,1,'Pancakes',8.95,0.03845,0,''),(226,50,1,'vodka russkaja',10.23,0.03845,0,'vodiara'),(227,51,1,'pivo pennoe',10.45,0.075,0,'potomu czto pennoe'),(228,52,1,'candy',2.54,0.17,0,''),(229,53,1,'preved',20.34,0.03845,0,''),(230,53,1,'Cinamon French Toast',8.95,0.03845,0,''),(231,54,3,'prevedovka',4.95,0.075,0,'cheap vodka'),(371,58,1,'Mountain Man brat',7.95,0.03845,1,''),(365,59,1,'Beef burger',6.95,0.03845,1,''),(370,58,1,'Beef brat',7.95,0.03845,1,''),(369,58,1,'Mountain Man brat',7.95,0.03845,1,''),(368,58,1,'Fish & Fries',7.95,0.03845,1,''),(367,58,1,'Elk burger',7.95,0.03845,1,''),(366,58,1,'Beef burger',6.95,0.03845,1,''),(364,59,1,'Mountain Man brat',7.95,0.03845,1,''),(363,59,1,'Beef brat',7.95,0.03845,1,''),(372,60,1,'Mountain Man brat',7.95,0.03845,1,''),(373,60,1,'Beef brat',7.95,0.03845,1,''),(374,60,1,'Beef brat',7.95,0.03845,1,''),(375,60,1,'Beef burger',6.95,0.03845,1,''),(376,60,1,'Elk burger',7.95,0.03845,1,''),(377,61,1,'Cinamon French Toast',8.95,0.03845,1,''),(378,61,1,'Corncakes',8.95,0.03845,1,''),(379,61,1,'Pancakes',8.95,0.03845,1,''),(380,62,1,'Beef brat',7.95,0.03845,1,''),(381,62,1,'Elk burger',7.95,0.03845,1,''),(382,62,1,'Beef burger',6.95,0.03845,1,''),(383,63,1,'Mountain Man brat',7.95,0.03845,1,''),(384,63,1,'Beef brat',7.95,0.03845,1,''),(385,63,1,'Beef burger',6.95,0.03845,1,''),(386,63,1,'Elk burger',7.95,0.03845,1,''),(387,63,1,'Fish & Fries',7.95,0.03845,1,''),(388,64,1,'Beef brat',7.95,0.03845,1,''),(389,64,1,'Beef burger',6.95,0.03845,1,''),(390,64,1,'Mountain Man brat',7.95,0.03845,1,''),(391,64,1,'Elk burger',7.95,0.03845,1,''),(392,65,1,'Cinamon French Toast',8.95,0.03845,1,''),(393,65,1,'Corncakes',8.95,0.03845,1,''),(394,65,1,'Pancakes',8.95,0.03845,1,''),(395,65,1,'Root Beer',1.95,0.03845,1,''),(396,65,1,'Sprite',1.95,0.03845,1,''),(397,65,1,'Coca-cola',0.95678,0.03845,1,''),(398,66,1,'Mountain Man brat',7.95,0.03845,1,''),(399,66,1,'Beef brat',7.95,0.03845,1,''),(400,66,1,'Beef burger',6.95,0.03845,1,''),(401,66,1,'Elk burger',7.95,0.03845,1,''),(402,67,1,'Mountain Man brat',7.95,0.03845,1,''),(403,67,1,'Beef brat',7.95,0.03845,1,''),(404,67,1,'Beef burger',6.95,0.03845,1,''),(405,68,1,'Mountain Man brat',7.95,0.03845,1,''),(406,68,1,'Beef brat',7.95,0.03845,1,''),(407,68,1,'Beef burger',6.95,0.03845,1,''),(408,68,1,'Elk burger',7.95,0.03845,1,''),(409,68,1,'Fish & Fries',7.95,0.03845,1,''),(410,69,1,'Cinamon French Toast',8.95,0.03845,1,''),(411,69,1,'Corncakes',8.95,0.03845,1,''),(412,69,1,'Pancakes',8.95,0.03845,1,''),(413,69,1,'Wine (bottle)',17.95,0.075,3,''),(414,69,1,'Wine (glass)',4.95,0.075,3,''),(431,70,1,'Beef burger',6.95,0.03845,1,''),(430,70,1,'Beef brat',7.95,0.03845,1,''),(429,70,1,'Cranberry stew',14.95,0.03845,1,''),(428,70,1,'Beef stew',12.95,0.03845,1,''),(427,70,1,'Elk stew',13.95,0.03845,1,''),(420,71,1,'Corncakes',8.95,0.03845,1,''),(421,71,1,'Pancakes',8.95,0.03845,1,''),(422,71,1,'Cinamon French Toast',8.95,0.03845,1,''),(423,71,1,'Sprite',1.95,0.03845,1,''),(424,71,1,'Coca-cola',0.95678,0.03845,1,''),(425,71,1,'Root Beer',1.95,0.03845,1,''),(426,71,1,'Coca-cola Light',1.95,0.03845,1,''),(440,72,1,'Beef brat',8.45,0.03845,1,'a v czem delo, brat?'),(441,72,2,'Pancakes',8.95,0.03845,1,'tag vod'),(439,72,3,'Elk burger',7.95,0.03845,1,'a delo v pravde'),(442,72,2,'Wine (bottle)',17.95,0.075,3,'vino'),(443,73,1,'Mountain Man brat',7.95,0.03845,1,''),(444,73,1,'Beef brat',7.95,0.03845,1,''),(445,73,1,'Elk burger',7.95,0.03845,1,''),(446,73,1,'Beef burger',6.95,0.075,3,''),(447,74,1,'Mountain Man brat',7.95,0.03845,1,''),(448,74,1,'Beef brat',7.95,0.03845,1,''),(449,74,1,'Beef burger',6.95,0.03845,1,''),(450,75,1,'Mountain Man brat',7.95,0.03845,1,''),(451,75,1,'Beef brat',7.95,0.03845,1,''),(452,75,1,'Beef burger',6.95,0.03845,1,''),(453,75,1,'Elk burger',7.95,0.03845,1,'');
/*!40000 ALTER TABLE `orders_dishes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `parts`
--

DROP TABLE IF EXISTS `parts`;
CREATE TABLE `parts` (
  `id` int(11) NOT NULL auto_increment,
  `name` text collate utf8_unicode_ci NOT NULL,
  `group_id` text collate utf8_unicode_ci NOT NULL,
  `price_change` double NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=57 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `parts`
--

LOCK TABLES `parts` WRITE;
/*!40000 ALTER TABLE `parts` DISABLE KEYS */;
INSERT INTO `parts` VALUES (44,'sw. pot. fries','17',0.5),(33,'rye','14',0.5),(34,'wheat','14',0),(35,'yellow','14',0),(36,'2 corncakes','13',0),(37,'cinamon bread','13',0),(43,'reg. fries','17',0),(42,'onions','16',0),(41,'pickles','16',0),(40,'lettuce','16',0),(39,'tomatoes','16',0),(38,'elk patty','15',0),(32,'fruitmix','13',0),(31,'homefries','13',0),(30,'2 pancakes','13',0),(45,'beef patty','15',0),(46,'mountain man brat','18',0),(47,'beef brat','18',0),(51,'Fish & Fries','19',0),(49,'sauerkraut','20',0),(50,'onions & pepper','20',0),(52,'elk stew','21',0),(53,'beef stew','21',0),(54,'cornbread','22',0),(55,'mount. man bread','22',0),(56,'cranberry stew','21',0);
/*!40000 ALTER TABLE `parts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `taxes`
--

DROP TABLE IF EXISTS `taxes`;
CREATE TABLE `taxes` (
  `id` int(11) NOT NULL auto_increment,
  `name` text collate utf8_unicode_ci NOT NULL,
  `value` double NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=6 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `taxes`
--

LOCK TABLES `taxes` WRITE;
/*!40000 ALTER TABLE `taxes` DISABLE KEYS */;
INSERT INTO `taxes` VALUES (1,'Food & Drinks',3.845),(3,'Alcohol',7.5),(4,'GiftShop',17),(5,'Tabaco',20);
/*!40000 ALTER TABLE `taxes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `workers`
--

DROP TABLE IF EXISTS `workers`;
CREATE TABLE `workers` (
  `id` int(11) NOT NULL auto_increment,
  `name` text collate utf8_unicode_ci NOT NULL,
  `show` tinyint(1) NOT NULL default '1',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=13 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `workers`
--

LOCK TABLES `workers` WRITE;
/*!40000 ALTER TABLE `workers` DISABLE KEYS */;
INSERT INTO `workers` VALUES (1,'Vitaly Belskiy',0),(2,'Leonty Belskiy',0),(5,'Binty Ktulhu',1),(6,'Preved Medvedov',0),(7,'Vladimir Putin',0),(8,'Angelina Jolie',1),(9,'Charlise Theron',1),(12,'Homer Simpson',0);
/*!40000 ALTER TABLE `workers` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2008-03-20 20:02:03
