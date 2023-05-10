program example (input,output);
procedure cal(a:integer);
var x,y:integer;r,w:real;
begin
    read(x,y);
    write(x/y);
    write(x+y);
    write(x-y);
    write(x mod y);
    write(x div y);
    x := -x;
    write(x);
    y := not y;
    write(y);
    read(r,w);
    write(r/w);
    write(r+w);
    write(r-w);
    r := -r;
    write(r);
end;
begin
    cal(1);
End.