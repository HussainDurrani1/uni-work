-- Q1. List the full name of every student along with the name of their department. 
-- Include students even if they have not yet been assigned to any department.

select s.student_id, s.first_name, s.last_name, d.dept_id, d.dept_name from students s
INNER JOIN departments d ON s.dept_id = d.dept_id or s.dept_id = null;



-- Q2. Display each department name along with the total number of professors employed in it. 
-- Also include departments that currently have no professors assigned to them.
select d.dept_name, count(p.prof_id) as Total_Professors from departments d
inner join professors p on d.dept_id = p.dept_id
group by dept_name;



-- Q3. Show the course name and the full name of the professor teaching it. 
-- Display all courses even those that do not yet have a professor assigned.

select c.course_name, p.first_name, p.last_name from professors p
INNER JOIN courses c on c.prof_id = p.prof_id or c.prof_id = null;



-- Q4. Find the average GPA of students in each department. 
-- Only include departments that actually have students enrolled in them. 
-- Show the department name and the average GPA rounded to 2 decimal places.
select d.dept_name, round(avg(s.gpa), 2) as Average_GPA from departments d
inner join students s on s.dept_id = d.dept_id
group by d.dept_id;



-- Q5. Produce a complete report of all students and all departments. 
-- Each row should show a student name and a department name. 
-- Rows where there is no match on either side should still appear 
-- (with NULLs where data is missing).

select s.first_name, s.last_name, d.dept_name from students s
inner join departments d on s.dept_id = d.dept_id or s.dept_id = null or d.dept_id = null;


