declare
n number:= &n;
j number:= 2;
flag number:=0

begin

while(j<=n/2) loop
if mod(j,n) = 0 then
	dbms_output.put_line(n||' is not prime');
	flag :=1;
	exit;
else
j:=j+1;

end if;
end loop;
if flag = 0 then
dbms_output.put_line(n||' is prime');

end if;
end;
/

