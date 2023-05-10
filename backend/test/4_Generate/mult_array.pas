program example(input, output);
var x:array[0..4,0..4] of integer;i,y,z:integer;
begin
for i:=0 to 4 do
begin
    read(y);
    x[0,i] :=y;
    write(x[0,i]);
    {z := x[i];}
    {write(z);}
end;
for i:=0 to 4 do
begin
    write(x[0,i]);
end;
write(x[0,1]);
end.