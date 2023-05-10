program example(input, output);
var x:array[0..9,0..9] of integer;i,j,z:integer;
begin
for i:=0 to 9 do
begin
  for j:=0 to 9 do
  begin
    read(z);
    x[i,j] := z;
  end;
end;
for i:=0 to 9 do
begin
  for j:=0 to 9 do
  begin
    write(x[i,j]);
  end;
end;
end.