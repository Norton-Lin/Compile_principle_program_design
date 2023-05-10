program funcandproc (input,output);
var a:integer;b:boolean;

procedure pro(a,b:integer;var c,d:integer);
begin

end;
function fun(a,b:integer;var c,d:integer) : integer;
begin

end;

begin
a(a,b);
pro(a,a);
pro(b,b,b,b);
pro(1,1,1,1);
write(pro(a,a,a,a));
pro(a,a,a,a);

write(fun(a,a));
write(fun(b,b,b,b));
write(fun(1,1,1,1));
write(fun(a,a,a,a));
end.