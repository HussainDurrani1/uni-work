use educational_institute;

select * from department;

insert into department values (3, 'FOCS', '03119434258', 'UCP, PCSIR'),
							  (4, 'FOAI', '03229434258', 'UCP, Lahore'),
                              (5, 'FOSE', '03339434258', 'UCP, D Building'),
                              (6, 'FODS', '03449434258', 'UCP, A Building'),
                              (7, 'FOML', '03559434258', 'UCP, C Building');
                              
select * from department;


insert into department (dep_no, name, phone_no) values (9, 'FOMD', '11334455'),
													   (10, 'FODL', '1122'),
                                                       (11, 'FO_Stats', '22334455');
	
select * from department;