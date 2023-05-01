use fantasy;

ALTER TABLE fantasy.players 
ADD COLUMN name VARCHAR(45) NULL AFTER club_id;

alter table users
rename column price to budget;

alter table matches_players
rename column matche_id to match_id;

alter table players
rename column value to price;

alter table users
rename column name to username;

CREATE TABLE `fantasy`.`leagues` (
  `id` INT NOT NULL,
  `name` VARCHAR(45) NULL,
  PRIMARY KEY (`id`));
  
ALTER TABLE `fantasy`.`clubs` 
ADD COLUMN `league_id` INT NULL AFTER `name`,
ADD INDEX `fk_clubs_1_idx` (`league_id` ASC) VISIBLE; -- if not working delete it
;
ALTER TABLE `fantasy`.`clubs` 
ADD CONSTRAINT `fk_clubs_1`
  FOREIGN KEY (`league_id`)
  REFERENCES `fantasy`.`leagues` (`id`)
  ON DELETE NO ACTION
  ON UPDATE NO ACTION;
