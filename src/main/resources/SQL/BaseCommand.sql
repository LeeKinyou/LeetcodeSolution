SHOW DATABASES;

USE `kinyou's-test-database`;

SHOW TABLES;
DROP TABLE IF EXISTS `users`;
CREATE TABLE IF NOT EXISTS `users` (
    `id` int(11) NOT NULL AUTO_INCREMENT,
    `sex` ENUM('male', 'female') NOT NULL,
    `age` int(3) NOT NULL,
    `work_time` int(3) NOT NULL,
    `work_place` varchar(255) NOT NULL,
    `username` varchar(255) NOT NULL,
    `password` varchar(255) NOT NULL,
    PRIMARY KEY (`id`)
);

INSERT INTO `users` (`username`, `password`) VALUES('admin', 'admin');
INSERT INTO `users` (`username`, `password`) VALUES('user', 'user');
INSERT INTO `users` (`username`, `password`) VALUES('test', 'test');

SELECT * FROM `users`;

CREATE TABLE IF NOT EXISTS `emp` (
    `id` int(11) NOT NULL AUTO_INCREMENT,
    `title` varchar(255) NOT NULL,
    `content` text NOT NULL,
    PRIMARY KEY (`id`)
);

ALTER TABLE `emp` RENAME TO `employees`;
ALTER TABLE `employees` ADD COLUMN `created_at` TIMESTAMP DEFAULT CURRENT_TIMESTAMP;
ALTER TABLE `employees` MODIFY COLUMN `title` VARCHAR(255) NOT NULL;
ALTER TABLE `employees` CHANGE `title` `title` VARCHAR(255) NOT NULL;
ALTER TABLE `employees` DROP COLUMN `created_at`;
ALTER TABLE `users` ADD COLUMN `sex` ENUM('male', 'female') NOT NULL;
ALTER TABLE `employees` ADD COLUMN `age` INT(3) NOT NULL;

DROP TABLE `employees`;

UPDATE `users` SET `username` = 'administrator', `password` = 'administrator' WHERE `id` = 1;
DELETE FROM `users` WHERE `id` = 2;
SELECT * FROM users;

