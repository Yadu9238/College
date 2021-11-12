declare 
cursor c1 is select * from parts;
counter int;
row parts%rowtype;

begin
open c1;
loop
fetch c1 into row;
exit when c1%notfound;
insert into copy_part values(row.pid,row.pname,row.color);
end loop;
counter := c1%rowcount;
close c1;
dbms_output.put_line('No of rows changed:'counter);
end;
/

