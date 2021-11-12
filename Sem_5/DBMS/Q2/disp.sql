declare
cursor c1 is select * from part;
d1 part%rowtype;

begin
open c1
loop
fetch c1 into d1;
exit when c1%notfound;
dbms_output.put_line('PID:'||d1.pid);
dbms_output.put_line('Pname:'||d1.pname);
dbms_output.put_line('color:'||d1.color);
end loop;
close c1;

update shipment
set quantity = 1.05*quantity;
dbms_output.put_line('No of rows changed:'||sql%rowcount);

end;
/
