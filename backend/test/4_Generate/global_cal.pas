program example (input,output);
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
    y := !y;
End.