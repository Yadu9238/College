create procedure fibo as
begin

declare
n number;
a number;
b number;
c number;
i number;
begin
n:=8;
a:=0;
b:=1;
i:=3;
dbms_output.put_line(a);
dbms_output.put_line(b);
while (i <=n) loop
c:=a+b;
dbms_output.put_line(c);
a:=b;
b:=c;
i:=i+1;
end loop;
end;
end;
/