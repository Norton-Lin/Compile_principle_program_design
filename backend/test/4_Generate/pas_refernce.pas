program example(input, output);
var x,y:integer;
procedure test(var a,b:integer);
begin
    write(20);
    write(a);
    a:=5;
end;
begin
x:=10;
test(x,y);
write(x);
end.