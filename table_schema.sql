-- phpMyAdmin SQL Dump
-- version 2.11.0
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: May 21, 2009 at 11:13 PM
-- Server version: 5.0.67
-- PHP Version: 5.2.9

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";

--
-- Database: `restaurant_pos`
--

-- --------------------------------------------------------

--
-- Table structure for table `dishes`
--

DROP TABLE IF EXISTS `dishes`;
CREATE TABLE IF NOT EXISTS `dishes` (
  `id` int(11) NOT NULL auto_increment,
  `name` text collate utf8_unicode_ci NOT NULL,
  `price` double NOT NULL,
  `menu_id` int(11) NOT NULL,
  `comment` text collate utf8_unicode_ci NOT NULL,
  `kitchen` tinyint(1) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=44 ;

-- --------------------------------------------------------

--
-- Table structure for table `dishes_parts`
--

DROP TABLE IF EXISTS `dishes_parts`;
CREATE TABLE IF NOT EXISTS `dishes_parts` (
  `id` int(11) NOT NULL auto_increment,
  `dishes_id` int(11) NOT NULL,
  `parts_id` int(11) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=62 ;

-- --------------------------------------------------------

--
-- Table structure for table `dishes_parts_ors`
--

DROP TABLE IF EXISTS `dishes_parts_ors`;
CREATE TABLE IF NOT EXISTS `dishes_parts_ors` (
  `id` int(11) NOT NULL auto_increment,
  `dishes_parts_id` int(11) NOT NULL,
  `parts_id` int(11) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=47 ;

-- --------------------------------------------------------

--
-- Table structure for table `groups`
--

DROP TABLE IF EXISTS `groups`;
CREATE TABLE IF NOT EXISTS `groups` (
  `id` int(11) NOT NULL auto_increment,
  `name` text collate utf8_unicode_ci NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=29 ;

-- --------------------------------------------------------

--
-- Table structure for table `menus`
--

DROP TABLE IF EXISTS `menus`;
CREATE TABLE IF NOT EXISTS `menus` (
  `id` int(11) NOT NULL auto_increment,
  `name` text collate utf8_unicode_ci NOT NULL,
  `tax_id` int(11) NOT NULL,
  `show` tinyint(1) NOT NULL default '1',
  `kitchen` tinyint(1) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=20 ;

-- --------------------------------------------------------

--
-- Table structure for table `orders`
--

DROP TABLE IF EXISTS `orders`;
CREATE TABLE IF NOT EXISTS `orders` (
  `id` int(11) NOT NULL auto_increment,
  `number` int(11) NOT NULL,
  `time` timestamp NOT NULL default CURRENT_TIMESTAMP,
  `time_served` timestamp NOT NULL default '0000-00-00 00:00:00',
  `status` int(11) NOT NULL COMMENT '0 - just taken, 1 - served, 2 - paid, 3 - sent to kitchen, 4 - ready in kitchen',
  `pay_type` int(11) NOT NULL COMMENT '1- cash, 2 - charge',
  `amount_given` double NOT NULL,
  `amount` double NOT NULL COMMENT 'amount paid',
  `taxes` double NOT NULL,
  `waiter_id` int(11) NOT NULL,
  `comment` text collate utf8_unicode_ci NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=112 ;

-- --------------------------------------------------------

--
-- Table structure for table `orders_dishes`
--

DROP TABLE IF EXISTS `orders_dishes`;
CREATE TABLE IF NOT EXISTS `orders_dishes` (
  `id` int(11) NOT NULL auto_increment,
  `order_id` int(11) NOT NULL,
  `qty` int(11) NOT NULL,
  `name` text collate utf8_unicode_ci NOT NULL,
  `price` double NOT NULL,
  `tax` double NOT NULL,
  `tax_id` int(11) NOT NULL,
  `comment` text collate utf8_unicode_ci NOT NULL,
  `kitchen` tinyint(1) NOT NULL,
  `ready` tinyint(1) NOT NULL default '0',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=565 ;

-- --------------------------------------------------------

--
-- Table structure for table `orders_dishes_parts`
--

DROP TABLE IF EXISTS `orders_dishes_parts`;
CREATE TABLE IF NOT EXISTS `orders_dishes_parts` (
  `id` int(11) NOT NULL auto_increment,
  `orders_dishes_id` int(11) NOT NULL,
  `parts_id` int(11) NOT NULL,
  `using` tinyint(1) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=33 ;

-- --------------------------------------------------------

--
-- Table structure for table `parts`
--

DROP TABLE IF EXISTS `parts`;
CREATE TABLE IF NOT EXISTS `parts` (
  `id` int(11) NOT NULL auto_increment,
  `name` text collate utf8_unicode_ci NOT NULL,
  `group_id` text collate utf8_unicode_ci NOT NULL,
  `price_change` double NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=67 ;

-- --------------------------------------------------------

--
-- Table structure for table `taxes`
--

DROP TABLE IF EXISTS `taxes`;
CREATE TABLE IF NOT EXISTS `taxes` (
  `id` int(11) NOT NULL auto_increment,
  `name` text collate utf8_unicode_ci NOT NULL,
  `value` double NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=10 ;

-- --------------------------------------------------------

--
-- Table structure for table `workers`
--

DROP TABLE IF EXISTS `workers`;
CREATE TABLE IF NOT EXISTS `workers` (
  `id` int(11) NOT NULL auto_increment,
  `name` text collate utf8_unicode_ci NOT NULL,
  `show` tinyint(1) NOT NULL default '1',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=16 ;
