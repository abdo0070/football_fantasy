
use fantasy;
-- select * from leagues;
-- select * from players;
-- select * from clubs;

-- delete from users
-- where id > 0;

-- delete from players
-- where id > 0;

-- delete from leagues
-- where id > 0;

-- delete from clubs
-- where id > 0;




insert into leagues values(1,'Premier League');
insert into leagues values (2,'Egyption League');
insert into leagues values(3,'Laliga');

insert into clubs values(1,'Liverpool',1);
insert into clubs values(2,'Chelsea',1);
insert into clubs values(3,'ManchesterCity',1);
insert into clubs values (4,'Pyramids',2);
insert into clubs values (5,'Alahly',2);
insert into clubs values (6,'Zamalek',2);
insert into clubs values(7, 'Barcelona', 3);
insert into clubs values(8, 'RealMadrid', 3);
insert into clubs values(9, 'AtleticoMadrid', 3);

-- players of clubs Liverpool

insert into players values(1,30,45000,'GoalKeeper',1,'Alisson');
insert into players values(2,24,8000,'GoalKeeper',1,'Caoimhin Kelleher');
insert into players values(3,36,1000,'GoalKeeper',1,'Adrian');
insert into players values(4,31,45000,'Centre-Back',1,'virgil van dijk');
insert into players values(5,23,35000,'Centre-Back',1,'Ibrahima Konate');
insert into players values(6,25,30000,'Centre-Back',1,'Joe Gomez');
insert into players values(7,31,16000,'Centre-Back',1,'Joel Matip');
insert into players values(8,26,6000,'Centre-Back',1,'Nathaniel Phillips');
insert into players values(9,22,3000,'Centre-Back',1,'Rhys Williams');
insert into players values(10,29,48000,'Left-Back',1,'Andrew Robertson');
insert into players values(11,26,18000,'Left-Back',1,'Konstantinos Tsimikas');
insert into players values(12,24,65000,'Right-Back',1,'Trent Alexander-Arnold');
insert into players values(13,19,5000,'Right-Back',1,'Calvin Ramsay');
insert into players values(14,29,45000,'Defensive Midfield',1,'Fabinho');
insert into players values(15,18,13000,'Defensive Midfield',1,'Stefan Bajcetic');
insert into players values(16,32,18000,'Central Midfield',1,'Thiago');
insert into players values(17,28,17000,'Central Midfield',1,'Naby Keita');
insert into players values(18,22,17000,'Central Midfield',1,'Curtis Jones');
insert into players values(19,26,15000,'Central Midfield',1,'Arthur Melo');
insert into players values(20,32,10000,'Central Midfield',1,'Jordan Henderson');
insert into players values(21,29,10000,'Central Midfield',1,'Alex Oxlade-Chamberlain');
insert into players values(22,37,2000,'Central Midfield',1,'James Milner');
insert into players values(23,20,35000,'Attacking Midfield',1,'Harvey Elliott');
insert into players values(24,20,20000,'Attacking Midfield',1,'Fabio Carvalho');
insert into players values(25,26,75000,'Left Winger',1,'Luis Diaz');
insert into players values(26,23,60000,'Left Winger',1,'Cody Gakpo');
insert into players values(27,26,55000,'Left Winger',1,'Diogo Jota');
insert into players values(28,30,70000,'Right Winger',1,'Mohamed Salah');
insert into players values(29,23,70000,'Centre-Forward',1,'Darwin Nunez');
insert into players values(30,31,22000,'Centre-Forward',1,'Roberto Firmino');

-- players of clubs Chelsea

insert into players values (31,31,18000,'GoalKeeper',2,'Edouard Mendy');
insert into players values (32,28,15000,'GoalKeeper',2,'Kepa Arrizabalaga');
insert into players values (33,18,8000,'GoalKeeper',2,'Gabriel Slonina');
insert into players values (34,30,2000,'GoalKeeper',2,'Marcus Bettinelli');
insert into players values (35,22,65000,'Centre-Back',2,'Wesley Fofana');
insert into players values (36,22,40000,'Centre-Back',2,'Benoit Badiashile');
insert into players values (37,31,25000,'Centre-Back',2,'Kalidou Koulibaly');
insert into players values (38,23,22000,'Centre-Back',2,'Trevoh Chalobah');
insert into players values (39,38,2000,'Centre-Back',2,'Thiago Silva');
insert into players values (40,24,40000,'Left-Back',2,'Marc Cucurella');
insert into players values (41,26,35000,'Left-Back',2,'Ben Chilwell');
insert into players values (42,18,8000,'Left-Back',2,'Lewis Hall');
insert into players values (43,23,70000,'Right-Back',2,'Reece James');
insert into players values (44,33,8000,'Right-Back',2,'Cesar Azpilicueta');
insert into players values (45,22,85000,'Defensive Midfield',2,'Enzo Fernandez');
insert into players values (46,32,20000,'Defensive Midfield',2,'NGolo Kante');
insert into players values (47,26,20000,'Defensive Midfield',2,'Denis Zakaria');
insert into players values (48,28,40000,'Central Midfield',2,'Mateo Kovacic');
insert into players values (49,23,32000,'Central Midfield',2,'Conor Gallagher');
insert into players values (50,27,25000,'Central Midfield',2,'Ruben Loftus-Cheek');
insert into players values (51,19,15000,'Central Midfield',2,'Carney Chukwuemeka');
insert into players values (52,24,65000,'Attacking Midfield',2,'Mason Mount');
insert into players values (53,23,60000,'Attacking Midfield',2,'Kai Havertz');
insert into players values (54,22,60000,'Left Winger',2,'Mykhaylo Mudryk');
insert into players values (55,28,60000,'Left Winger',2,'Raheem Sterling');
insert into players values (56,24,32000,'Right Winger',2,'Christian Pulisic');
insert into players values (57,21,28000,'Right Winger',2,'Noni Madueke');
insert into players values (58,30,18000,'Right Winger',2,'Hakim Ziyech');
insert into players values (59,23,50000,'Second Striker',2,'Joao Felix');
insert into players values (60,21,30000,'Centre-Forward',2,'Armando Broja');
insert into players values (61,20,10000,'Centre-Forward',2,'David Datro Fofana');
insert into players values (62,33,7000,'Centre-Forward',2,'Pierre-Emerick Aubameyang');


-- players of club ManchesterCity

insert into players values (63,29,45000,'GoalKeeper',3,'Ederson');
insert into players values (64,30,6000,'GoalKeeper',3,'Stefan Ortegan');
insert into players values (65,37,2500,'GoalKeeper',3,'Scott Carson');
insert into players values (66,25,75000,'Centre-Back',3,'Ruben Dias');
insert into players values (67,28,35000,'Centre-Back',3,'Nathan Ake');
insert into players values (68,28,30000,'Centre-Back',3,'John Stones');
insert into players values (69,28,30000,'Centre-Back',3,'Aymeric Laporte');
insert into players values (70,27,30000,'Centre-Back',3,'Manuel Akanji');
insert into players values (71,22,15000,'Left-Back',3,'Sergio Gomez');
insert into players values (72,32,15000,'Right-Back',3,'Kyle Walker');
insert into players values (73,18,15000,'Right-Back',3,'Rico Lewis');
insert into players values (74,26,80000,'Defensive Midfield',3,'Rodri');
insert into players values (75,27,35000,'Defensive Midfield',3,'Kalvin Philips');
insert into players values (76,20,10000,'Defensive Midfield',3,'Maximo Perrone');
insert into players values (77,32,25000,'Central Midfield',3,'Ilkay Gundogan');
insert into players values (78,31,80000,'Attacking Midfield',3,'Kevin De Bruyne');
insert into players values (79,28,80000,'Attacking Midfield',3,'Bernardo Selva');
insert into players values (80,20,15000,'Attacking Midfield',3,'Cole Palmer');
insert into players values (81,22,110000,'Left Winger',3,'Phil Foden');
insert into players values (82,27,70000,'Left Winger',3,'Jack Grealish');
insert into players values (83,32,30000,'Right Winger',3,'Riyad Mahrez');
insert into players values (84,22,170000,'Centre-Forward',3,'Erling Haaland');
insert into players values (85,23,50000,'Centre-Forward',3,'Julian Alvarez');

-- PYRAMIDS
insert into players values (86,31,8000,'Goalkeeper',4,'A. El Shenawy');
insert into players values (87,39,1500,'Goalkeeper',4,'S. Ekramy');
insert into players values (88,34,8000,'Centre-Back',4,'Ali Gabr');
insert into players values (89,25,8000,'Centre-Back',4,'osama Galal');
insert into players values (90,28,10000,'Left-Back',4,'M. Hamdi');
insert into players values (91,27,5000,'Left-Back',4,'Karim Hafez');
insert into players values (92,30,8000,'Right-Back',4,'M. Chibi');
insert into players values (93,36,2000,'Right-Back',4,'A. Magdy');
insert into players values (94,28,10000,'Defensive Midfield',4,'I. Toure');
insert into players values (95,30,3000,'Defensive Midfield',4,'Mahmoud dunga');
insert into players values (96,28,15000,'Central Midfield',4,'W. El Karti');
insert into players values (97,27,6000,'Central Midfield',4,'Islam Issa');
insert into players values (98,37,6000,'Attacking Midfield',4,'A. Said');
insert into players values (99,21,2500,'Attacking Midfield',4,'Mahmoud Saber');
insert into players values (100,26,30000,'Left Winger',4,'R. Sobhi');
insert into players values (101,22,12000,'Left Winger',4,'Ibrahim Adel');
insert into players values (102,28,18000,'Right Winger',4,'M. Faith');
insert into players values (103,19,250,'Right Winger',4,'T. Ojo');
insert into players values (104,25,8000,'Centre-Forward',4,'F. Lakay');
insert into players values (105,31,8000,'Centre-Forward',4,'F. Ben Youssef');

-- alahly
insert into players values (106,34,25000,'Goalkeeper',5,'M. El Shenawy');
insert into players values (107,24,20000,'Centre-Back',5,'M. abdelmonem');
insert into players values (108,33,13000,'Left-Back',5,'A. Maaloul');
insert into players values (109,25,10000,'Right-Back',5,'A. Tawfik');
insert into players values (110,25,40000,'Defensive Midfield',5,'A. Dieng');
insert into players values (111,23,15000,'Central Midfield',5,'A. kendouci');
insert into players values (112,27,18000,'Attacking Midfield',5,'Afsha');
insert into players values (113,23,8000,'Left Winger',5,'Ahmed Abdelkader');
insert into players values (114,28,15000,'Right Winger',5,'Percy Tau');
insert into players values (115,27,18000,'Centre-Forward',5,'M. sherif');
insert into players values (116,33,2000,'Goalkeeper',5,'Ali Lotfi');
insert into players values (117,32,6000,'Centre-Back',5,'A. Ashraf');
insert into players values (118,21,1000,'Left-Back',5,'Mohamed Ashraf');
insert into players values (119,27,8000,'Right-Back',5,'M. Hany');
insert into players values (120,28,15000,'Defensive Midfield',5,'H. Fathi');
insert into players values (121,33,12000,'Central Midfield',5,'A. El Solia');
insert into players values (122,19,10000,'Right Winger',5,'M. Dhaoui');
insert into players values (123,29,6000,'Centre-Forward',5,'Kahraba');

-- zamalak
insert into players values (124,30,8000,'Goalkeeper',6,'Mohamed Awad');
insert into players values (125,27,20000,'Centre-Back',6,'Mahmoud El Wensh');
insert into players values (126,25,15000,'Left-Back',6,'Ahmed Fatouh');
insert into players values (127,30,6000,'Right-Back',6,'H. Mathlouthi');
insert into players values (128,27,12000,'Defensive Midfield',6,'Nabil Dounga');
insert into players values (129,25,7000,'Central Midfield',6,'A. Belhadji');
insert into players values (130,24,6000,'Left Winger',6,'I. Ndiaye');
insert into players values (131,27,40000,'Right Winger',6,'Zizo');
insert into players values (132,37,50000,'Right Winger',6,'Shikabala');
insert into players values (133,30,12000,'Centre-Forward',6,'S. Jaziri');
insert into players values (134,23,6000,'Goalkeeper',6,'M. Sobhi');
insert into players values (135,29,6000,'Centre-Back',6,'M. Abdelghani');
insert into players values (136,27,3500,'Left-Back',6,'A. Gomaa');
insert into players values (137,31,4000,'Right-Back',6,'O. Gaber');
insert into players values (138,29,3000,'Defensive Midfield',6,'Mohamed Roqa');
insert into players values (139,28,6000,'Central Midfield',6,'Amr El Sisi');
insert into players values (140,25,6000,'Centre-Forward',6,'N. Mansy');
insert into players values (141,23,5000,'Centre-Forward',6,'Sayed Abdallah');

-- Barcelona players
insert into players values(142,31, 40000, 'Goalkeeper', 7, 'Marc-Andre ter Stegen');
insert into players values(143,24, 4000, 'Goalkeeper', 7, 'Inaki Pena');
insert into players values(144,21, 2000, 'Goalkeeper', 7, 'Arnau Tenas');
insert into players values(145,24, 70000, 'Centre-Back', 7, 'Ronald Araújo');
insert into players values(146,24, 60000, 'Centre-Back', 7, 'Jules Kounde');
insert into players values(147,27, 30000, 'Centre-Back', 7, 'Andreas Christensen');
insert into players values(148,22, 12000, 'Centre-Back', 7, 'Eric Garcia');
insert into players values(149,19, 30000, 'Left-Back', 7, 'Alejandro Balde');
insert into players values(150,32, 7000, 'Left-Back', 7, 'Marcos Alonso');
insert into players values(151,34, 5000, 'Left-Back', 7, 'Jordi Alba');
insert into players values(152,31, 6000, 'Right-Back', 7, 'Sergi Roberto');
insert into players values(153,34, 5000, 'Defensive Midfield', 7, 'Sergio Busquets');
insert into players values(154,20, 100000, 'Centre-Forward', 7, 'Pedri');
insert into players values(155,18, 90000, 'Centre-Forward', 7, 'Gavi');
insert into players values(156,25, 60000, 'Centre-Forward', 7, 'Frenkie de Jong');
insert into players values(157,26, 20000, 'Centre-Forward', 7, 'Franck Kessie');
insert into players values(158,20, 3000, 'Central Midfield', 7, 'Pablo Torre');
insert into players values(159,20, 35000, 'Left Winger', 7, 'Ansu Fati');
insert into players values(160,23, 30000, 'Left Winger', 7, 'Ferran Torres');
insert into players values(161,25, 60000, 'Right Winger', 7, 'Ousmane Dembele');
insert into players values(162,26, 50000, 'Right Winger', 7, 'Raphinha');
insert into players values(163,34, 40000, 'Centre-Forward', 7, 'Robert Lewandowski');


-- Real Mardrid players
INSERT INTO players VALUES (164,30,60000,'Goalkeeper',8,'Thibaut Courtois' );
INSERT INTO players VALUES (165,24,5000,'Goalkeeper',8,'Andriy Lunin' );
INSERT INTO players VALUES (166,21,1000,'Goalkeeper',8,'Luis Lopez' );
INSERT INTO players VALUES (167,25,70000,'Centre-Back',8,'Eder Militao');
INSERT INTO players VALUES (168,30,50000,'Centre-Back',8,'David Alabas' );
INSERT INTO players VALUES (169,30,40000,'Centre-Back',8,'Antonio Rudiger' );
INSERT INTO players VALUES (170,33,6000,'Centre-Back',8,'Nacho Fernandez' );
INSERT INTO players VALUES (171,26,2000,'Centre-Back',8,'Jesus Vallejo' );
INSERT INTO players VALUES (172,27,35000,'Left-Back',8,'Ferland Mendy' );
INSERT INTO players VALUES (173,31,15000,'Right-Back',8,'Daniel Carvajal' );
INSERT INTO players VALUES (174,31,9000,'Right-Back',8,'Lucas Vazquez' );
INSERT INTO players VALUES (175,27,5000,'Right-Back',8,'Alvaro Odriozola' );
INSERT INTO players VALUES (176,23,90000,'Defensive Midfield',8,'Aurelien Tchouameni' );
INSERT INTO players VALUES (177,24,100000,'Central Midfield',8,'Federico Valverde' );
INSERT INTO players VALUES (178,33,60000,'Central Midfield',8,'Eduardo Camavinga' );
INSERT INTO players VALUES (179,30,18000,'Central Midfield',8,'Toni Kroos' );
INSERT INTO players VALUES (180,26,12000,'Central Midfield',8,'Dani Ceballos' );
INSERT INTO players VALUES (181,37,10000,'Central Midfield',8,'Luka Modric' );
INSERT INTO players VALUES (182,22,120000,'Left Winger',8,'Vinicius Junior' );
INSERT INTO players VALUES (183,32,5000,'Left Winger',8,'Eden Hazard' );
INSERT INTO players VALUES (184,22,80000,'Right Winger',8,'Rodrygo' );
INSERT INTO players VALUES (185,27,25000,'Marco Asensio',8,'Marco Asensio' );
INSERT INTO players VALUES (186,35,35000,'Centre-Forward',8,'Karim Benzema' );
INSERT INTO players VALUES (187,18,6000,'Centre-Forward',8,'Alvaro Rodriguez' );
INSERT INTO players VALUES (188,29,3000,'Centre-Forward',8,'Mariano Diaz' );

-- Atletico Madrid players

insert into players values(189, 30, 40000, 'Goalkeeper', 9, 'Jan Oblak');
insert into players values(190, 27, 4000, 'Goalkeeper', 9, 'Ivo Grbic');
insert into players values(191, 28, 35000, 'Centre-Back', 9, 'Jose Maria Gimenez');
insert into players values(192, 27, 18000, 'Centre-Back', 9, 'Mario Hermoso');
insert into players values(193, 32, 8000, 'Centre-Back', 9, 'Stefan Savic');
insert into players values(194, 29, 25000, 'Left-Back', 9, 'Reinildo Mandava');
insert into players values(195, 26, 15000, 'Left-Back', 9, 'Sergio Reguilon');
insert into players values(196, 25, 24000, 'Right-Back', 9, 'Nahuel Molina');
insert into players values(197, 31, 9000, 'Right-Back', 9, 'Matt Doherty');
insert into players values(198, 30, 18000, 'Defensive Midfield', 9, 'Geoffrey Kondogbia');
insert into players values(199, 34, 5000, 'Defensive Midfield', 9, 'Axel Witsel');
insert into players values(200, 28, 40000, 'Central Midfield', 9, 'Rodrigo de Paul');
insert into players values(201, 28, 35000, 'Central Midfield', 9, 'Marcos Llorente');
insert into players values(202, 31, 16000, 'Central Midfield', 9, 'Koke');
insert into players values(203, 328, 10000, 'Central Midfield', 9, 'Saúl Niguez');
insert into players values(204, 19, 5000, 'Central Midfield', 9, 'Pablo Barrios');
insert into players values(205, 27, 25000, 'Attacking Midfield', 9, 'Thomas Lemar');
insert into players values(206, 29, 25000, 'Left Winger', 9, 'Yannick Carrasco');
insert into players values(207, 34, 35000, 'Right Winger', 9, 'Angel Correa');
insert into players values(208, 32, 25000, 'Second Striker', 9, 'Antoine Griezmann');
insert into players values(209, 30, 25000, 'Centre-Forward', 9, 'Alvaro Mornull,ta');
insert into players values(210, 34, 16000, 'Centre-Forward', 9, 'Memphis Denull,ay');
