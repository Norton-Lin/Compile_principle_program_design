program example(input, output);
var x:array[0..8] of integer;i,y,z:integer;
begin
for i:=0 to 8 do
begin
    read(y);
    x[i] :=y;
    write(x[i]);
    z := x[i];
    write(z);
end;
for i:=0 to 8 do
begin
    write(x[i]);
end;
write(x[1]);
end.