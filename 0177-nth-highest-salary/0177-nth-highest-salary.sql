CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  -- Adjust N because LIMIT offset is 0-indexed
  SET N = N - 1;
  
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT salary 
      FROM Employee
      ORDER BY salary DESC
      LIMIT N, 1
  );
END