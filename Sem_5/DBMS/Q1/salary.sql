begin
update emp
set salary = 1.15*salary where dept = 'd1';

dbms_output.put_line('Number of rows changed'||sql%rowcount);
end;
/