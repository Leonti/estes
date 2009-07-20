SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
DROP TABLE IF EXISTS `dishes`;
CREATE TABLE `dishes` (
  `id` int(11) NOT NULL auto_increment,
  `name` text collate utf8_unicode_ci NOT NULL,
  `price` double NOT NULL,
  `menu_id` int(11) NOT NULL,
  `comment` text collate utf8_unicode_ci NOT NULL,
  `kitchen` tinyint(1) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=44 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
INSERT INTO `dishes` (`id`, `name`, `price`, `menu_id`, `comment`, `kitchen`) VALUES
(38, 'beer brat', 7, 16, 'Tasty beer brat!', 1),
(39, 'miontain man brat', 7, 16, '', 1),
(40, 'Coca-cola', 1.95, 19, '', 1),
(41, 'Pepsi', 1.95, 19, '', 1),
(42, 'coffe', 1.95, 19, '', 1),
(43, 'tea', 1.95, 19, '', 1);
DROP TABLE IF EXISTS `dishes_parts`;
CREATE TABLE `dishes_parts` (
  `id` int(11) NOT NULL auto_increment,
  `dishes_id` int(11) NOT NULL,
  `parts_id` int(11) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=62 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
INSERT INTO `dishes_parts` (`id`, `dishes_id`, `parts_id`) VALUES
(58, 38, 63),
(59, 38, 0),
(60, 39, 62),
(61, 39, 0);
DROP TABLE IF EXISTS `dishes_parts_ors`;
CREATE TABLE `dishes_parts_ors` (
  `id` int(11) NOT NULL auto_increment,
  `dishes_parts_id` int(11) NOT NULL,
  `parts_id` int(11) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=47 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
INSERT INTO `dishes_parts_ors` (`id`, `dishes_parts_id`, `parts_id`) VALUES
(41, 61, 65),
(42, 61, 64),
(43, 59, 66),
(44, 59, 64),
(45, 59, 64),
(46, 61, 66);
DROP TABLE IF EXISTS `groups`;
CREATE TABLE `groups` (
  `id` int(11) NOT NULL auto_increment,
  `name` text collate utf8_unicode_ci NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=29 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
INSERT INTO `groups` (`id`, `name`) VALUES
(27, 'brats'),
(28, 'breads');
DROP TABLE IF EXISTS `menus`;
CREATE TABLE `menus` (
  `id` int(11) NOT NULL auto_increment,
  `name` text collate utf8_unicode_ci NOT NULL,
  `tax_id` int(11) NOT NULL,
  `show` tinyint(1) NOT NULL default '1',
  `kitchen` tinyint(1) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=20 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
INSERT INTO `menus` (`id`, `name`, `tax_id`, `show`, `kitchen`) VALUES
(16, 'breakfast', 9, 1, 1),
(17, 'dinner', 9, 1, 1),
(18, 'lunch', 9, 1, 1),
(19, 'beverages', 9, 1, 1);
DROP TABLE IF EXISTS `orders`;
CREATE TABLE `orders` (
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
) ENGINE=MyISAM AUTO_INCREMENT=112 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
INSERT INTO `orders` (`id`, `number`, `time`, `time_served`, `status`, `pay_type`, `amount_given`, `amount`, `taxes`, `waiter_id`, `comment`) VALUES
(81, 1, '2009-03-25 20:13:17', '0000-00-00 00:00:00', 2, 2, 15.29, 15.29, 2.44, 15, ''),
(82, 2, '2009-03-25 20:17:23', '0000-00-00 00:00:00', 2, 1, 20, 15.29, 2.44, 13, ''),
(83, 3, '2009-03-25 20:24:45', '0000-00-00 00:00:00', 2, 2, 21.3, 21.3, 3.4, 13, ''),
(84, 1, '2009-04-16 00:59:37', '0000-00-00 00:00:00', 2, 1, 16.66, 16.66, 2.66, 13, ''),
(85, 2, '2009-04-16 01:09:24', '0000-00-00 00:00:00', 0, 0, 0, 0, 0, 13, ''),
(86, 3, '2009-04-16 01:10:47', '0000-00-00 00:00:00', 0, 0, 0, 0, 0, 13, ''),
(87, 4, '2009-04-16 01:11:26', '0000-00-00 00:00:00', 0, 0, 0, 0, 0, 15, ''),
(88, 5, '2009-04-16 01:13:52', '0000-00-00 00:00:00', 0, 0, 0, 0, 0, 13, ''),
(89, 6, '2009-04-16 01:14:25', '0000-00-00 00:00:00', 0, 0, 0, 0, 0, 15, ''),
(90, 7, '2009-04-16 01:14:36', '0000-00-00 00:00:00', 0, 0, 0, 0, 0, 13, ''),
(91, 8, '2009-04-16 01:14:52', '0000-00-00 00:00:00', 0, 0, 0, 0, 0, 13, ''),
(92, 9, '2009-04-16 01:15:09', '0000-00-00 00:00:00', 0, 0, 0, 0, 0, 13, ''),
(93, 10, '2009-04-16 01:15:21', '0000-00-00 00:00:00', 0, 0, 0, 0, 0, 15, ''),
(94, 11, '2009-04-16 01:15:31', '0000-00-00 00:00:00', 0, 0, 0, 0, 0, 13, ''),
(95, 12, '2009-04-16 01:18:00', '0000-00-00 00:00:00', 0, 0, 0, 0, 0, 13, ''),
(96, 13, '2009-04-16 01:18:05', '0000-00-00 00:00:00', 0, 0, 0, 0, 0, 13, ''),
(97, 14, '2009-04-16 01:18:13', '0000-00-00 00:00:00', 0, 0, 0, 0, 0, 13, ''),
(98, 15, '2009-04-16 01:18:25', '0000-00-00 00:00:00', 0, 0, 0, 0, 0, 13, ''),
(99, 16, '2009-04-16 01:18:33', '0000-00-00 00:00:00', 0, 0, 0, 0, 0, 13, ''),
(100, 17, '2009-04-16 01:18:45', '0000-00-00 00:00:00', 0, 0, 0, 0, 0, 13, ''),
(101, 18, '2009-04-16 01:19:13', '0000-00-00 00:00:00', 0, 0, 0, 0, 0, 13, ''),
(102, 19, '2009-04-16 01:27:21', '0000-00-00 00:00:00', 0, 0, 0, 0, 0, 13, ''),
(103, 1, '2009-05-15 22:39:48', '0000-00-00 00:00:00', 5, 0, 0, 0, 0, 15, ''),
(104, 1, '2009-05-20 20:59:34', '0000-00-00 00:00:00', 2, 1, 20, 12.97, 2.07, 13, ''),
(105, 2, '2009-05-20 21:04:40', '0000-00-00 00:00:00', 2, 1, 21.9, 21.9, 3.5, 13, ''),
(106, 3, '2009-05-20 21:47:29', '0000-00-00 00:00:00', 2, 2, 21.9, 21.9, 3.5, 13, ''),
(107, 4, '2009-05-20 22:00:04', '0000-00-00 00:00:00', 2, 1, 30, 21.9, 3.5, 15, ''),
(108, 5, '2009-05-20 22:07:47', '0000-00-00 00:00:00', 2, 1, 30, 21.9, 3.5, 13, ''),
(109, 6, '2009-05-20 22:09:06', '0000-00-00 00:00:00', 2, 1, 20, 17.26, 2.76, 13, ''),
(110, 7, '2009-05-20 22:10:19', '0000-00-00 00:00:00', 2, 2, 10.65, 10.65, 1.7, 13, ''),
(111, 8, '2009-05-20 22:14:49', '0000-00-00 00:00:00', 0, 0, 0, 0, 0, 13, '');
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
  `kitchen` tinyint(1) NOT NULL,
  `ready` tinyint(1) NOT NULL default '0',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=565 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
INSERT INTO `orders_dishes` (`id`, `order_id`, `qty`, `name`, `price`, `tax`, `tax_id`, `comment`, `kitchen`, `ready`) VALUES
(471, 79, 1, 'beer brat', 7, 0.19, 9, 'Tasty beer brat!', 1, 0),
(472, 79, 1, 'miontain man brat', 7, 0.19, 9, '', 1, 0),
(473, 79, 1, 'Pepsi', 1.95, 0.19, 9, '', 1, 0),
(474, 79, 1, 'Coca-cola', 1.95, 0.19, 9, '', 1, 0),
(475, 79, 1, 'tea', 1.95, 0.19, 9, '', 1, 0),
(476, 80, 1, 'beer brat', 7, 0.19, 9, 'Tasty beer brat!', 1, 1),
(477, 80, 1, 'Pepsi', 1.95, 0.19, 9, '', 1, 1),
(478, 80, 1, 'coffe', 1.95, 0.19, 9, '', 1, 1),
(479, 80, 1, 'tea', 1.95, 0.19, 9, '', 1, 1),
(480, 80, 1, 'Coca-cola', 1.95, 0.19, 9, '', 1, 1),
(481, 81, 1, 'beer brat', 7, 0.19, 9, 'Tasty beer brat!', 1, 0),
(482, 81, 1, 'Pepsi', 1.95, 0.19, 9, '', 1, 0),
(483, 81, 1, 'coffe', 1.95, 0.19, 9, '', 1, 0),
(484, 81, 1, 'tea', 1.95, 0.19, 9, '', 1, 0),
(485, 82, 1, 'beer brat', 7, 0.19, 9, 'Tasty beer brat!', 1, 0),
(486, 82, 1, 'Pepsi', 1.95, 0.19, 9, '', 1, 0),
(487, 82, 1, 'coffe', 1.95, 0.19, 9, '', 1, 0),
(488, 82, 1, 'tea', 1.95, 0.19, 9, '', 1, 0),
(489, 83, 1, 'beer brat', 7, 0.19, 9, 'Tasty beer brat!', 1, 1),
(490, 83, 1, 'miontain man brat', 7, 0.19, 9, '', 1, 1),
(491, 83, 1, 'Pepsi', 1.95, 0.19, 9, '', 1, 1),
(492, 83, 1, 'coffe', 1.95, 0.19, 9, '', 1, 1),
(493, 84, 1, 'beer brat', 7, 0.19, 9, 'Tasty beer brat!', 1, 0),
(494, 84, 1, 'miontain man brat', 7, 0.19, 9, '', 1, 0),
(495, 85, 2, 'beer brat', 7, 0.19, 9, 'Tasty beer brat!', 1, 0),
(496, 86, 1, 'beer brat', 7, 0.19, 9, 'Tasty beer brat!', 1, 0),
(497, 86, 1, 'miontain man brat', 7, 0.19, 9, '', 1, 0),
(498, 86, 1, 'Coca-cola', 1.95, 0.19, 9, '', 1, 0),
(499, 86, 1, 'Pepsi', 1.95, 0.19, 9, '', 1, 0),
(500, 86, 1, 'coffe', 1.95, 0.19, 9, '', 1, 0),
(501, 86, 1, 'tea', 1.95, 0.19, 9, '', 1, 0),
(502, 87, 1, 'beer brat', 7.5, 0.19, 9, 'Tasty beer brat!', 1, 0),
(507, 88, 1, 'Pepsi', 1.95, 0.19, 9, '', 1, 0),
(506, 88, 1, 'Coca-cola', 1.95, 0.19, 9, '', 1, 0),
(508, 88, 1, 'coffe', 1.95, 0.19, 9, '', 1, 0),
(509, 88, 1, 'Coca-cola', 1.95, 0.19, 9, '', 1, 0),
(510, 88, 1, 'Pepsi', 1.95, 0.19, 9, '', 1, 0),
(511, 88, 1, 'coffe', 1.95, 0.19, 9, '', 1, 0),
(512, 88, 1, 'tea', 1.95, 0.19, 9, '', 1, 0),
(513, 88, 1, 'beer brat', 7.5, 0.19, 9, 'Tasty beer brat!', 1, 0),
(514, 89, 1, 'Pepsi', 1.95, 0.19, 9, '', 1, 0),
(515, 89, 1, 'coffe', 1.95, 0.19, 9, '', 1, 0),
(516, 89, 1, 'miontain man brat', 7, 0.19, 9, '', 1, 0),
(517, 90, 1, 'beer brat', 7.5, 0.19, 9, 'Tasty beer brat!', 1, 0),
(518, 91, 1, 'beer brat', 7.5, 0.19, 9, 'Tasty beer brat!', 1, 0),
(519, 92, 1, 'beer brat', 7.5, 0.19, 9, 'Tasty beer brat!', 1, 0),
(520, 93, 1, 'miontain man brat', 7, 0.19, 9, '', 1, 0),
(521, 94, 1, 'beer brat', 7.5, 0.19, 9, 'Tasty beer brat!', 1, 0),
(522, 95, 1, 'miontain man brat', 7, 0.19, 9, '', 1, 0),
(523, 96, 1, 'beer brat', 7.5, 0.19, 9, 'Tasty beer brat!', 1, 0),
(524, 97, 1, 'beer brat', 7.5, 0.19, 9, 'Tasty beer brat!', 1, 0),
(525, 98, 1, 'Coca-cola', 1.95, 0.19, 9, '', 1, 0),
(526, 98, 1, 'beer brat', 7.5, 0.19, 9, 'Tasty beer brat!', 1, 0),
(527, 99, 1, 'Coca-cola', 1.95, 0.19, 9, '', 1, 0),
(528, 99, 1, 'miontain man brat', 7, 0.19, 9, '', 1, 0),
(529, 100, 1, 'Coca-cola', 1.95, 0.19, 9, '', 1, 0),
(530, 100, 1, 'beer brat', 7.5, 0.19, 9, 'Tasty beer brat!', 1, 0),
(531, 101, 1, 'Coca-cola', 1.95, 0.19, 9, '', 1, 0),
(532, 101, 1, 'beer brat', 7.5, 0.19, 9, 'Tasty beer brat!', 1, 0),
(533, 102, 1, 'beer brat', 7.5, 0.19, 9, 'Tasty beer brat!', 1, 0),
(534, 102, 1, 'miontain man brat', 7, 0.19, 9, '', 1, 0),
(535, 103, 1, 'beer brat', 7, 0.19, 9, 'Tasty beer brat!', 1, 0),
(536, 103, 1, 'coffe', 1.95, 0.19, 9, '', 1, 0),
(537, 103, 1, 'tea', 1.95, 0.19, 9, '', 1, 0),
(538, 104, 1, 'beer brat', 7, 0.19, 9, 'Tasty beer brat!', 1, 0),
(539, 104, 1, 'Pepsi', 1.95, 0.19, 9, '', 1, 0),
(540, 104, 1, 'coffe', 1.95, 0.19, 9, '', 1, 0),
(541, 105, 1, 'beer brat', 7, 0.19, 9, 'Tasty beer brat!', 1, 0),
(542, 105, 1, 'miontain man brat', 7.5, 0.19, 9, 'dyg, eptel', 1, 0),
(543, 105, 1, 'Coca-cola', 1.95, 0.19, 9, '', 1, 0),
(544, 105, 1, 'coffe', 1.95, 0.19, 9, '', 1, 0),
(545, 106, 1, 'beer brat', 7.5, 0.19, 9, 'Tasty beer brat!', 1, 0),
(546, 106, 1, 'miontain man brat', 7, 0.19, 9, '', 1, 0),
(547, 106, 1, 'Pepsi', 1.95, 0.19, 9, '', 1, 0),
(548, 106, 1, 'coffe', 1.95, 0.19, 9, '', 1, 0),
(549, 107, 1, 'miontain man brat', 7, 0.19, 9, '', 1, 0),
(550, 107, 1, 'beer brat', 7.5, 0.19, 9, 'Tasty beer brat!', 1, 0),
(551, 107, 1, 'coffe', 1.95, 0.19, 9, '', 1, 0),
(552, 107, 1, 'tea', 1.95, 0.19, 9, '', 1, 0),
(553, 108, 1, 'beer brat', 7.5, 0.19, 9, 'Tasty beer brat!', 1, 0),
(554, 108, 1, 'miontain man brat', 7, 0.19, 9, '', 1, 0),
(555, 108, 1, 'coffe', 1.95, 0.19, 9, '', 1, 0),
(556, 108, 1, 'tea', 1.95, 0.19, 9, '', 1, 0),
(557, 109, 1, 'miontain man brat', 7, 0.19, 9, '', 1, 0),
(558, 109, 1, 'beer brat', 7.5, 0.19, 9, 'Tasty beer brat!', 1, 0),
(559, 110, 1, 'miontain man brat', 7, 0.19, 9, '', 1, 0),
(560, 110, 1, 'coffe', 1.95, 0.19, 9, '', 1, 0),
(561, 111, 1, 'miontain man brat', 7, 0.19, 9, '', 1, 0),
(562, 111, 1, 'coffe', 1.95, 0.19, 9, '', 1, 0),
(563, 111, 1, 'beer brat', 7.5, 0.19, 9, 'Tasty beer brat!', 1, 0),
(564, 111, 1, 'coffe', 1.95, 0.19, 9, '', 1, 0);
DROP TABLE IF EXISTS `orders_dishes_parts`;
CREATE TABLE `orders_dishes_parts` (
  `id` int(11) NOT NULL auto_increment,
  `orders_dishes_id` int(11) NOT NULL,
  `parts_id` int(11) NOT NULL,
  `using` tinyint(1) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=33 DEFAULT CHARSET=latin1;
INSERT INTO `orders_dishes_parts` (`id`, `orders_dishes_id`, `parts_id`, `using`) VALUES
(1, 533, 63, 1),
(2, 533, 66, 1),
(3, 534, 62, 1),
(4, 534, 65, 1),
(5, 535, 63, 1),
(6, 535, 64, 1),
(7, 541, 63, 1),
(8, 541, 64, 1),
(9, 542, 62, 0),
(10, 542, 66, 1),
(11, 545, 63, 1),
(12, 545, 66, 1),
(13, 546, 62, 1),
(14, 546, 65, 1),
(15, 549, 62, 1),
(16, 549, 65, 1),
(17, 550, 63, 0),
(18, 550, 66, 1),
(19, 553, 63, 1),
(20, 553, 66, 1),
(21, 554, 62, 1),
(22, 554, 65, 1),
(23, 557, 62, 1),
(24, 557, 65, 1),
(25, 558, 63, 1),
(26, 558, 66, 1),
(27, 559, 62, 1),
(28, 559, 65, 1),
(29, 561, 62, 1),
(30, 561, 65, 1),
(31, 563, 63, 1),
(32, 563, 66, 1);
DROP TABLE IF EXISTS `parts`;
CREATE TABLE `parts` (
  `id` int(11) NOT NULL auto_increment,
  `name` text collate utf8_unicode_ci NOT NULL,
  `group_id` text collate utf8_unicode_ci NOT NULL,
  `price_change` double NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=67 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
INSERT INTO `parts` (`id`, `name`, `group_id`, `price_change`) VALUES
(62, 'mountain man brat', '27', 0),
(63, 'beer brat', '27', 0),
(64, 'weet bread', '28', 0),
(65, 'rye bread', '28', 0),
(66, 'banana bread', '28', 0.5);
DROP TABLE IF EXISTS `taxes`;
CREATE TABLE `taxes` (
  `id` int(11) NOT NULL auto_increment,
  `name` text collate utf8_unicode_ci NOT NULL,
  `value` double NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=10 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
INSERT INTO `taxes` (`id`, `name`, `value`) VALUES
(9, 'food & beverage', 19);
DROP TABLE IF EXISTS `workers`;
CREATE TABLE `workers` (
  `id` int(11) NOT NULL auto_increment,
  `name` text collate utf8_unicode_ci NOT NULL,
  `show` tinyint(1) NOT NULL default '1',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=16 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
INSERT INTO `workers` (`id`, `name`, `show`) VALUES
(13, 'Vitaly Belskiy', 1),
(15, 'Leonty Belskiy', 1);
