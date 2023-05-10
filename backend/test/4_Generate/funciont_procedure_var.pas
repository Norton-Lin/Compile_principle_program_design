program example(input, output);
var x,y:integer;
function gcd(var c:integer):integer;
begin
    c:=c-1;
    write(c);
    gcd:=100;
    if c>0 then gcd:=gcd(c)
    else gcd := 100
end;
procedure test(x,y:integer);
var a,b:integer;
begin
    a:=x;
    b:=y;
    write(x);
    write(y);
    write(gcd(a));
    write(a);
    write(b);
end;
begin
x := 10;
y := 10;
test(x,y);
write(100);
end.