
use fantasy;
select * from users;
delete from players
where id > 0;

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

insert into players values(1,30,45000,'GoalKeeper',1,'Alisson',0);
insert into players values(2,24,8000,'GoalKeeper',1,'Caoimhin Kelleher',0);
insert into players values(3,36,1000,'GoalKeeper',1,'Adrian',0);
insert into players values(4,31,45000,'Centre-Back',1,'virgil van dijk',0);
insert into players values(5,23,35000,'Centre-Back',1,'Ibrahima Konate',0);
insert into players values(6,25,30000,'Centre-Back',1,'Joe Gomez',0);
insert into players values(7,31,16000,'Centre-Back',1,'Joel Matip',0);
insert into players values(8,26,6000,'Centre-Back',1,'Nathaniel Phillips',0);
insert into players values(9,22,3000,'Centre-Back',1,'Rhys Williams',0);
insert into players values(10,29,48000,'Left-Back',1,'Andrew Robertson',0);
insert into players values(11,26,18000,'Left-Back',1,'Konstantinos Tsimikas',0);
insert into players values(12,24,65000,'Right-Back',1,'Trent Alexander-Arnold',0);
insert into players values(13,19,5000,'Right-Back',1,'Calvin Ramsay',0);
insert into players values(14,29,45000,'Defensive Midfield',1,'Fabinho',0);
insert into players values(15,18,13000,'Defensive Midfield',1,'Stefan Bajcetic',0);
insert into players values(16,32,18000,'Central Midfield',1,'Thiago',0);
insert into players values(17,28,17000,'Central Midfield',1,'Naby Keita',0);
insert into players values(18,22,17000,'Central Midfield',1,'Curtis Jones',0);
insert into players values(19,26,15000,'Central Midfield',1,'Arthur Melo',0);
insert into players values(20,32,10000,'Central Midfield',1,'Jordan Henderson',0);
insert into players values(21,29,10000,'Central Midfield',1,'Alex Oxlade-Chamberlain',0);
insert into players values(22,37,2000,'Central Midfield',1,'James Milner',0);
insert into players values(23,20,35000,'Attacking Midfield',1,'Harvey Elliott',0);
insert into players values(24,20,20000,'Attacking Midfield',1,'Fabio Carvalho',0);
insert into players values(25,26,75000,'Left Winger',1,'Luis Diaz',0);
insert into players values(26,23,60000,'Left Winger',1,'Cody Gakpo',0);
insert into players values(27,26,55000,'Left Winger',1,'Diogo Jota',0);
insert into players values(28,30,70000,'Right Winger',1,'Mohamed Salah',0);
insert into players values(29,23,70000,'Centre-Forward',1,'Darwin Nunez',0);
insert into players values(30,31,22000,'Centre-Forward',1,'Roberto Firmino',0);

-- players of clubs Chelsea

insert into players values (31,31,18000,'GoalKeeper',2,'Edouard Mendy',0);
insert into players values (32,28,15000,'GoalKeeper',2,'Kepa Arrizabalaga',0);
insert into players values (33,18,8000,'GoalKeeper',2,'Gabriel Slonina',0);
insert into players values (34,30,2000,'GoalKeeper',2,'Marcus Bettinelli',0);
insert into players values (35,22,65000,'Centre-Back',2,'Wesley Fofana',0);
insert into players values (36,22,40000,'Centre-Back',2,'Benoit Badiashile',0);
insert into players values (37,31,25000,'Centre-Back',2,'Kalidou Koulibaly',0);
insert into players values (38,23,22000,'Centre-Back',2,'Trevoh Chalobah',0);
insert into players values (39,38,2000,'Centre-Back',2,'Thiago Silva',0);
insert into players values (40,24,40000,'Left-Back',2,'Marc Cucurella',0);
insert into players values (41,26,35000,'Left-Back',2,'Ben Chilwell',0);
insert into players values (42,18,8000,'Left-Back',2,'Lewis Hall',0);
insert into players values (43,23,70000,'Right-Back',2,'Reece James',0);
insert into players values (44,33,8000,'Right-Back',2,'Cesar Azpilicueta',0);
insert into players values (45,22,85000,'Defensive Midfield',2,'Enzo Fernandez',0);
insert into players values (46,32,20000,'Defensive Midfield',2,'NGolo Kante',0);
insert into players values (47,26,20000,'Defensive Midfield',2,'Denis Zakaria',0);
insert into players values (48,28,40000,'Central Midfield',2,'Mateo Kovacic',0);
insert into players values (49,23,32000,'Central Midfield',2,'Conor Gallagher',0);
insert into players values (50,27,25000,'Central Midfield',2,'Ruben Loftus-Cheek',0);
insert into players values (51,19,15000,'Central Midfield',2,'Carney Chukwuemeka',0);
insert into players values (52,24,65000,'Attacking Midfield',2,'Mason Mount',0);
insert into players values (53,23,60000,'Attacking Midfield',2,'Kai Havertz',0);
insert into players values (54,22,60000,'Left Winger',2,'Mykhaylo Mudryk',0);
insert into players values (55,28,60000,'Left Winger',2,'Raheem Sterling',0);
insert into players values (56,24,32000,'Right Winger',2,'Christian Pulisic',0);
insert into players values (57,21,28000,'Right Winger',2,'Noni Madueke',0);
insert into players values (58,30,18000,'Right Winger',2,'Hakim Ziyech',0);
insert into players values (59,23,50000,'Second Striker',2,'Joao Felix',0);
insert into players values (60,21,30000,'Centre-Forward',2,'Armando Broja',0);
insert into players values (61,20,10000,'Centre-Forward',2,'David Datro Fofana',0);
insert into players values (62,33,7000,'Centre-Forward',2,'Pierre-Emerick Aubameyang',0);


-- players of club ManchesterCity

insert into players values (63,29,45000,'GoalKeeper',3,'Ederson',0);
insert into players values (64,30,6000,'GoalKeeper',3,'Stefan Ortegan',0);
insert into players values (65,37,2500,'GoalKeeper',3,'Scott Carson',0);
insert into players values (66,25,75000,'Centre-Back',3,'Ruben Dias',0);
insert into players values (67,28,35000,'Centre-Back',3,'Nathan Ake',0);
insert into players values (68,28,30000,'Centre-Back',3,'John Stones',0);
insert into players values (69,28,30000,'Centre-Back',3,'Aymeric Laporte',0);
insert into players values (70,27,30000,'Centre-Back',3,'Manuel Akanji',0);
insert into players values (71,22,15000,'Left-Back',3,'Sergio Gomez',0);
insert into players values (72,32,15000,'Right-Back',3,'Kyle Walker',0);
insert into players values (73,18,15000,'Right-Back',3,'Rico Lewis',0);
insert into players values (74,26,80000,'Defensive Midfield',3,'Rodri',0);
insert into players values (75,27,35000,'Defensive Midfield',3,'Kalvin Philips',0);
insert into players values (76,20,10000,'Defensive Midfield',3,'Maximo Perrone',0);
insert into players values (77,32,25000,'Central Midfield',3,'Ilkay Gundogan',0);
insert into players values (78,31,80000,'Attacking Midfield',3,'Kevin De Bruyne',0);
insert into players values (79,28,80000,'Attacking Midfield',3,'Bernardo Selva',0);
insert into players values (80,20,15000,'Attacking Midfield',3,'Cole Palmer',0);
insert into players values (81,22,110000,'Left Winger',3,'Phil Foden',0);
insert into players values (82,27,70000,'Left Winger',3,'Jack Grealish',0);
insert into players values (83,32,30000,'Right Winger',3,'Riyad Mahrez',0);
insert into players values (84,22,170000,'Centre-Forward',3,'Erling Haaland',0);
insert into players values (85,23,50000,'Centre-Forward',3,'Julian Alvarez',0);

-- PYRAMIDS
insert into players values (86,31,8000,'Goalkeeper',4,'A. El Shenawy',0);
insert into players values (87,39,1500,'Goalkeeper',4,'S. Ekramy',0);
insert into players values (88,34,8000,'Centre-Back',4,'Ali Gabr',0);
insert into players values (89,25,8000,'Centre-Back',4,'osama Galal',0);
insert into players values (90,28,10000,'Left-Back',4,'M. Hamdi',0);
insert into players values (91,27,5000,'Left-Back',4,'Karim Hafez',0);
insert into players values (92,30,8000,'Right-Back',4,'M. Chibi',0);
insert into players values (93,36,2000,'Right-Back',4,'A. Magdy',0);
insert into players values (94,28,10000,'Defensive Midfield',4,'I. Toure',0);
insert into players values (95,30,3000,'Defensive Midfield',4,'Mahmoud dunga',0);
insert into players values (96,28,15000,'Central Midfield',4,'W. El Karti',0);
insert into players values (97,27,6000,'Central Midfield',4,'Islam Issa',0);
insert into players values (98,37,6000,'Attacking Midfield',4,'A. Said',0);
insert into players values (99,21,2500,'Attacking Midfield',4,'Mahmoud Saber',0);
insert into players values (100,26,30000,'Left Winger',4,'R. Sobhi',0);
insert into players values (101,22,12000,'Left Winger',4,'Ibrahim Adel',0);
insert into players values (102,28,18000,'Right Winger',4,'M. Faith',0);
insert into players values (103,19,250,'Right Winger',4,'T. Ojo',0);
insert into players values (104,25,8000,'Centre-Forward',4,'F. Lakay',0);
insert into players values (105,31,8000,'Centre-Forward',4,'F. Ben Youssef',0);

-- alahly
insert into players values (106,34,25000,'Goalkeeper',5,'M. El Shenawy',0);
insert into players values (107,24,20000,'Centre-Back',5,'M. abdelmonem',0);
insert into players values (108,33,13000,'Left-Back',5,'A. Maaloul',0);
insert into players values (109,25,10000,'Right-Back',5,'A. Tawfik',0);
insert into players values (110,25,40000,'Defensive Midfield',5,'A. Dieng',0);
insert into players values (111,23,15000,'Central Midfield',5,'A. kendouci',0);
insert into players values (112,27,18000,'Attacking Midfield',5,'Afsha',0);
insert into players values (113,23,8000,'Left Winger',5,'Ahmed Abdelkader',0);
insert into players values (114,28,15000,'Right Winger',5,'Percy Tau',0);
insert into players values (115,27,18000,'Centre-Forward',5,'M. sherif',0);
insert into players values (116,33,2000,'Goalkeeper',5,'Ali Lotfi',0);
insert into players values (117,32,6000,'Centre-Back',5,'A. Ashraf',0);
insert into players values (118,21,1000,'Left-Back',5,'Mohamed Ashraf',0);
insert into players values (119,27,8000,'Right-Back',5,'M. Hany',0);
insert into players values (120,28,15000,'Defensive Midfield',5,'H. Fathi',0);
insert into players values (121,33,12000,'Central Midfield',5,'A. El Solia',0);
insert into players values (122,19,10000,'Right Winger',5,'M. Dhaoui',0);
insert into players values (123,29,6000,'Centre-Forward',5,'Kahraba',0);

-- zamalak
insert into players values (124,30,8000,'Goalkeeper',6,'Mohamed Awad',0);
insert into players values (125,27,20000,'Centre-Back',6,'Mahmoud El Wensh',0);
insert into players values (126,25,15000,'Left-Back',6,'Ahmed Fatouh',0);
insert into players values (127,30,6000,'Right-Back',6,'H. Mathlouthi',0);
insert into players values (128,27,12000,'Defensive Midfield',6,'Nabil Dounga',0);
insert into players values (129,25,7000,'Central Midfield',6,'A. Belhadji',0);
insert into players values (130,24,6000,'Left Winger',6,'I. Ndiaye',0);
insert into players values (131,27,40000,'Right Winger',6,'Zizo',0);
insert into players values (132,37,50000,'Right Winger',6,'Shikabala',0);
insert into players values (133,30,12000,'Centre-Forward',6,'S. Jaziri',0);
insert into players values (134,23,6000,'Goalkeeper',6,'M. Sobhi',0);
insert into players values (135,29,6000,'Centre-Back',6,'M. Abdelghani',0);
insert into players values (136,27,3500,'Left-Back',6,'A. Gomaa',0);
insert into players values (137,31,4000,'Right-Back',6,'O. Gaber',0);
insert into players values (138,29,3000,'Defensive Midfield',6,'Mohamed Roqa',0);
insert into players values (139,28,6000,'Central Midfield',6,'Amr El Sisi',0);
insert into players values (140,25,6000,'Centre-Forward',6,'N. Mansy',0);
insert into players values (141,23,5000,'Centre-Forward',6,'Sayed Abdallah',0);

-- Barcelona players
insert into players values(142,31, 40000, 'Goalkeeper', 7, 'Marc-Andre ter Stegen',0);
insert into players values(143,24, 4000, 'Goalkeeper', 7, 'Inaki Pena',0);
insert into players values(144,21, 2000, 'Goalkeeper', 7, 'Arnau Tenas',0);
insert into players values(145,24, 70000, 'Centre-Back', 7, 'Ronald Araújo',0);
insert into players values(146,24, 60000, 'Centre-Back', 7, 'Jules Kounde',0);
insert into players values(147,27, 30000, 'Centre-Back', 7, 'Andreas Christensen',0);
insert into players values(148,22, 12000, 'Centre-Back', 7, 'Eric Garcia',0);
insert into players values(149,19, 30000, 'Left-Back', 7, 'Alejandro Balde',0);
insert into players values(150,32, 7000, 'Left-Back', 7, 'Marcos Alonso',0);
insert into players values(151,34, 5000, 'Left-Back', 7, 'Jordi Alba',0);
insert into players values(152,31, 6000, 'Right-Back', 7, 'Sergi Roberto',0);
insert into players values(153,34, 5000, 'Defensive Midfield', 7, 'Sergio Busquets',0);
insert into players values(154,20, 100000, 'Centre-Forward', 7, 'Pedri',0);
insert into players values(155,18, 90000, 'Centre-Forward', 7, 'Gavi',0);
insert into players values(156,25, 60000, 'Centre-Forward', 7, 'Frenkie de Jong',0);
insert into players values(157,26, 20000, 'Centre-Forward', 7, 'Franck Kessie',0);
insert into players values(158,20, 3000, 'Central Midfield', 7, 'Pablo Torre',0);
insert into players values(159,20, 35000, 'Left Winger', 7, 'Ansu Fati',0);
insert into players values(160,23, 30000, 'Left Winger', 7, 'Ferran Torres',0);
insert into players values(161,25, 60000, 'Right Winger', 7, 'Ousmane Dembele',0);
insert into players values(162,26, 50000, 'Right Winger', 7, 'Raphinha',0);
insert into players values(163,34, 40000, 'Centre-Forward', 7, 'Robert Lewandowski',0);


-- Real Mardrid players
INSERT INTO players VALUES (164,30,60000,'Goalkeeper',8,'Thibaut Courtois' ,0);
INSERT INTO players VALUES (165,24,5000,'Goalkeeper',8,'Andriy Lunin' ,0);
INSERT INTO players VALUES (166,21,1000,'Goalkeeper',8,'Luis Lopez' ,0);
INSERT INTO players VALUES (167,25,70000,'Centre-Back',8,'Eder Militao',0);
INSERT INTO players VALUES (168,30,50000,'Centre-Back',8,'David Alabas' ,0);
INSERT INTO players VALUES (169,30,40000,'Centre-Back',8,'Antonio Rudiger' ,0);
INSERT INTO players VALUES (170,33,6000,'Centre-Back',8,'Nacho Fernandez' ,0);
INSERT INTO players VALUES (171,26,2000,'Centre-Back',8,'Jesus Vallejo' ,0);
INSERT INTO players VALUES (172,27,35000,'Left-Back',8,'Ferland Mendy' ,0);
INSERT INTO players VALUES (173,31,15000,'Right-Back',8,'Daniel Carvajal' ,0);
INSERT INTO players VALUES (174,31,9000,'Right-Back',8,'Lucas Vazquez' ,0);
INSERT INTO players VALUES (175,27,5000,'Right-Back',8,'Alvaro Odriozola' ,0);
INSERT INTO players VALUES (176,23,90000,'Defensive Midfield',8,'Aurelien Tchouameni' ,0);
INSERT INTO players VALUES (177,24,100000,'Central Midfield',8,'Federico Valverde' ,0);
INSERT INTO players VALUES (178,33,60000,'Central Midfield',8,'Eduardo Camavinga' ,0);
INSERT INTO players VALUES (179,30,18000,'Central Midfield',8,'Toni Kroos' ,0);
INSERT INTO players VALUES (180,26,12000,'Central Midfield',8,'Dani Ceballos' ,0);
INSERT INTO players VALUES (181,37,10000,'Central Midfield',8,'Luka Modric' ,0);
INSERT INTO players VALUES (182,22,120000,'Left Winger',8,'Vinicius Junior' ,0);
INSERT INTO players VALUES (183,32,5000,'Left Winger',8,'Eden Hazard' ,0);
INSERT INTO players VALUES (184,22,80000,'Right Winger',8,'Rodrygo' ,0);
INSERT INTO players VALUES (185,27,25000,'Marco Asensio',8,'Marco Asensio' ,0);
INSERT INTO players VALUES (186,35,35000,'Centre-Forward',8,'Karim Benzema' ,0);
INSERT INTO players VALUES (187,18,6000,'Centre-Forward',8,'Alvaro Rodriguez' ,0);
INSERT INTO players VALUES (188,29,3000,'Centre-Forward',8,'Mariano Diaz' ,0);

-- Atletico Madrid players

insert into players values(189, 30, 40000, 'Goalkeeper', 9, 'Jan Oblak',0);
insert into players values(190, 27, 4000, 'Goalkeeper', 9, 'Ivo Grbic',0);
insert into players values(191, 28, 35000, 'Centre-Back', 9, 'Jose Maria Gimenez',0);
insert into players values(192, 27, 18000, 'Centre-Back', 9, 'Mario Hermoso',0);
insert into players values(193, 32, 8000, 'Centre-Back', 9, 'Stefan Savic',0);
insert into players values(194, 29, 25000, 'Left-Back', 9, 'Reinildo Mandava',0);
insert into players values(195, 26, 15000, 'Left-Back', 9, 'Sergio Reguilon',0);
insert into players values(196, 25, 24000, 'Right-Back', 9, 'Nahuel Molina',0);
insert into players values(197, 31, 9000, 'Right-Back', 9, 'Matt Doherty',0);
insert into players values(198, 30, 18000, 'Defensive Midfield', 9, 'Geoffrey Kondogbia',0);
insert into players values(199, 34, 5000, 'Defensive Midfield', 9, 'Axel Witsel',0);
insert into players values(200, 28, 40000, 'Central Midfield', 9, 'Rodrigo de Paul',0);
insert into players values(201, 28, 35000, 'Central Midfield', 9, 'Marcos Llorente',0);
insert into players values(202, 31, 16000, 'Central Midfield', 9, 'Koke',0);
insert into players values(203, 328, 10000, 'Central Midfield', 9, 'Saúl Niguez',0);
insert into players values(204, 19, 5000, 'Central Midfield', 9, 'Pablo Barrios',0);
insert into players values(205, 27, 25000, 'Attacking Midfield', 9, 'Thomas Lemar',0);
insert into players values(206, 29, 25000, 'Left Winger', 9, 'Yannick Carrasco',0);
insert into players values(207, 34, 35000, 'Right Winger', 9, 'Angel Correa',0);
insert into players values(208, 32, 25000, 'Second Striker', 9, 'Antoine Griezmann',0);
insert into players values(209, 30, 25000, 'Centre-Forward', 9, 'Alvaro Mor0,ta',0);
insert into players values(210, 34, 16000, 'Centre-Forward', 9, 'Memphis De0,ay',0);
