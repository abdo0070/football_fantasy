use fantasy;

ALTER TABLE `fantasy`.`clubs` 
DROP FOREIGN KEY `fk_clubs_1`;
ALTER TABLE `fantasy`.`clubs` 
ADD CONSTRAINT `fk_clubs_1`
  FOREIGN KEY (`league_id`)
  REFERENCES `fantasy`.`leagues` (`id`)
  ON DELETE CASCADE
  ON UPDATE RESTRICT;


ALTER TABLE `fantasy`.`matches` 
DROP FOREIGN KEY `matches_ibfk_1`;
ALTER TABLE `fantasy`.`matches` 
ADD CONSTRAINT `matches_ibfk_1`
  FOREIGN KEY (`club_1`)
  REFERENCES `fantasy`.`clubs` (`id`)
  ON DELETE CASCADE
  ON UPDATE RESTRICT;
  
  
ALTER TABLE `fantasy`.`matches` 
DROP FOREIGN KEY `matches_ibfk_2`;
ALTER TABLE `fantasy`.`matches` 
ADD CONSTRAINT `matches_ibfk_2`
  FOREIGN KEY (`club_2`)
  REFERENCES `fantasy`.`clubs` (`id`)
  ON DELETE CASCADE;
  
ALTER TABLE `fantasy`.`matches` 
DROP FOREIGN KEY `matches_ibfk_3`;
ALTER TABLE `fantasy`.`matches` 
ADD CONSTRAINT `matches_ibfk_3`
  FOREIGN KEY (`round_id`)
  REFERENCES `fantasy`.`rounds` (`id`)
  ON DELETE CASCADE;

ALTER TABLE `fantasy`.`matches_players` 
DROP FOREIGN KEY `matches_players_ibfk_1`,
DROP FOREIGN KEY `matches_players_ibfk_2`,
DROP FOREIGN KEY `matches_players_ibfk_3`;

ALTER TABLE `fantasy`.`matches_players` 
ADD CONSTRAINT `matches_players_ibfk_1`
  FOREIGN KEY (`match_id`)
  REFERENCES `fantasy`.`clubs` (`id`)
  ON DELETE CASCADE
  ON UPDATE RESTRICT,
  
ADD CONSTRAINT `matches_players_ibfk_2`
  FOREIGN KEY (`player_id`)
  REFERENCES `fantasy`.`players` (`id`)
  ON DELETE CASCADE,
  
ADD CONSTRAINT `matches_players_ibfk_3`
  FOREIGN KEY (`round_id`)
  REFERENCES `fantasy`.`rounds` (`id`)
  ON DELETE CASCADE;

ALTER TABLE `fantasy`.`players` 
DROP FOREIGN KEY `players_ibfk_1`;
ALTER TABLE `fantasy`.`players` 
ADD CONSTRAINT `players_ibfk_1`
  FOREIGN KEY (`club_id`)
  REFERENCES `fantasy`.`clubs` (`id`)
  ON DELETE CASCADE
  ON UPDATE RESTRICT;
  
ALTER TABLE `fantasy`.`teams` 
DROP FOREIGN KEY `teams_ibfk_1`;
ALTER TABLE `fantasy`.`teams` 
ADD CONSTRAINT `teams_ibfk_1`
  FOREIGN KEY (`user_id`)
  REFERENCES `fantasy`.`users` (`id`)
  ON DELETE CASCADE
  ON UPDATE RESTRICT;
  
ALTER TABLE `fantasy`.`teams_players` 
DROP FOREIGN KEY `teams_players_ibfk_1`,
DROP FOREIGN KEY `teams_players_ibfk_2`;

ALTER TABLE `fantasy`.`teams_players` 
ADD CONSTRAINT `teams_players_ibfk_1`
  FOREIGN KEY (`team_id`)
  REFERENCES `fantasy`.`teams` (`id`)
  ON DELETE CASCADE
  ON UPDATE RESTRICT,
  
ADD CONSTRAINT `teams_players_ibfk_2`
  FOREIGN KEY (`player_id`)
  REFERENCES `fantasy`.`players` (`id`)
  ON DELETE CASCADE;
  
ALTER TABLE `fantasy`.`users` 
DROP FOREIGN KEY `users_ibfk_1`;
ALTER TABLE `fantasy`.`users` 
ADD CONSTRAINT `users_ibfk_1`
  FOREIGN KEY (`club_id`)
  REFERENCES `fantasy`.`clubs` (`id`)
  ON DELETE CASCADE
  ON UPDATE RESTRICT;
  
ALTER TABLE `fantasy`.`players` 
DROP COLUMN `image`;

