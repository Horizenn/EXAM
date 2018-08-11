/*
Navicat MySQL Data Transfer

Source Server         : localhost_3306
Source Server Version : 50640
Source Host           : localhost:3306
Source Database       : examonline

Target Server Type    : MYSQL
Target Server Version : 50640
File Encoding         : 65001

Date: 2018-08-11 12:36:51
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for examminginfo
-- ----------------------------
DROP TABLE IF EXISTS `examminginfo`;
CREATE TABLE `examminginfo` (
  `testnum` int(11) DEFAULT NULL,
  `question` varchar(255) DEFAULT NULL,
  `answer` varchar(255) DEFAULT NULL,
  `totle` int(11) DEFAULT NULL,
  `studentid` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of examminginfo
-- ----------------------------
INSERT INTO `examminginfo` VALUES ('1', '1+1', 'B', '20', '1');
INSERT INTO `examminginfo` VALUES ('2', '1+2', 'A', '20', '1');
INSERT INTO `examminginfo` VALUES ('3', '2+2', 'B', '20', '1');
INSERT INTO `examminginfo` VALUES ('4', '2+4', 'C', '20', '1');
INSERT INTO `examminginfo` VALUES ('5', '3+3', 'D', '20', '1');

-- ----------------------------
-- Table structure for register
-- ----------------------------
DROP TABLE IF EXISTS `register`;
CREATE TABLE `register` (
  `studentid` int(11) NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) DEFAULT NULL,
  `name` varchar(255) DEFAULT NULL,
  `age` int(11) DEFAULT NULL,
  `sex` varchar(255) DEFAULT NULL,
  `phone` varchar(255) DEFAULT NULL,
  `power` varchar(255) DEFAULT NULL,
  `idcard` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`studentid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of register
-- ----------------------------
INSERT INTO `register` VALUES ('0', '0', '0', null, null, null, null, '教职工', null);
INSERT INTO `register` VALUES ('1', '1', '1', null, null, null, null, '学生', null);
INSERT INTO `register` VALUES ('2', '2', '2', null, null, null, null, '学生', null);
INSERT INTO `register` VALUES ('3', '3', '3', '吴皓泽', '20', '男', '1562222222', '学生', '456465');
INSERT INTO `register` VALUES ('4', '4', '4', '吴泽楠', '0', '', '', '学生', '45646456');

-- ----------------------------
-- Table structure for result
-- ----------------------------
DROP TABLE IF EXISTS `result`;
CREATE TABLE `result` (
  `starttime` varchar(255) DEFAULT NULL,
  `closetime` varchar(255) DEFAULT NULL,
  `subject` varchar(255) DEFAULT NULL,
  `totle` int(11) DEFAULT NULL,
  `studentid` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of result
-- ----------------------------
INSERT INTO `result` VALUES ('06月02日12:59', '06月02日12:59', '语文', '40', '1');
INSERT INTO `result` VALUES ('06月02日13:14', '06月02日13:14', '数学', '80', '2');
INSERT INTO `result` VALUES ('06月02日13:28', '06月02日13:28', '语文', '100', '2');
INSERT INTO `result` VALUES ('06月04日13:17', '06月04日13:17', '数学', '100', '3');
INSERT INTO `result` VALUES ('07月07日13:59', '07月07日14:00', '数学', '100', '1');

-- ----------------------------
-- Table structure for subject
-- ----------------------------
DROP TABLE IF EXISTS `subject`;
CREATE TABLE `subject` (
  `subjectid` int(11) NOT NULL,
  `subjectname` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`subjectid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of subject
-- ----------------------------
INSERT INTO `subject` VALUES ('1', '数学');
INSERT INTO `subject` VALUES ('2', '语文');
INSERT INTO `subject` VALUES ('3', '英语');
INSERT INTO `subject` VALUES ('4', '历史');

-- ----------------------------
-- Table structure for text
-- ----------------------------
DROP TABLE IF EXISTS `text`;
CREATE TABLE `text` (
  `testid` int(11) NOT NULL,
  `question` varchar(255) DEFAULT NULL,
  `rightanswer` varchar(255) DEFAULT NULL,
  `totle` int(11) DEFAULT NULL,
  `subjectid` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of text
-- ----------------------------
INSERT INTO `text` VALUES ('1', '你爱我吗', 'B', '20', '2');
INSERT INTO `text` VALUES ('2', '你是狗', 'B', '20', '2');
INSERT INTO `text` VALUES ('3', '广东的省会', 'A', '20', '2');
INSERT INTO `text` VALUES ('1', '1+1', 'B', '20', '1');
INSERT INTO `text` VALUES ('2', '1+2', 'A', '20', '1');
INSERT INTO `text` VALUES ('3', '2+2', 'B', '20', '1');
INSERT INTO `text` VALUES ('4', '2+4', 'C', '20', '1');
INSERT INTO `text` VALUES ('5', '3+3', 'D', '20', '1');

-- ----------------------------
-- Table structure for textanswer
-- ----------------------------
DROP TABLE IF EXISTS `textanswer`;
CREATE TABLE `textanswer` (
  `testid` int(11) NOT NULL,
  `AnswerA` varchar(255) DEFAULT NULL,
  `AnswerB` varchar(255) DEFAULT NULL,
  `AnswerC` varchar(255) DEFAULT NULL,
  `AnswerD` varchar(255) DEFAULT NULL,
  `subjectid` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of textanswer
-- ----------------------------
INSERT INTO `textanswer` VALUES ('1', '不爱', '爱', '滚', '傻逼', '2');
INSERT INTO `textanswer` VALUES ('2', '是的', '不是', '否', '你才是', '2');
INSERT INTO `textanswer` VALUES ('3', '广州', '深圳', '佛山', '揭阳', '2');
INSERT INTO `textanswer` VALUES ('1', '1', '2', '3', '4', '1');
INSERT INTO `textanswer` VALUES ('2', '3', '2', '4', '5', '1');
INSERT INTO `textanswer` VALUES ('3', '1', '4', '3', '8', '1');
INSERT INTO `textanswer` VALUES ('4', '1', '2', '6', '8', '1');
INSERT INTO `textanswer` VALUES ('5', '1', '2', '5', '6', '1');
