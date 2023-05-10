program example(input, output);
var x,y:integer;
begin
x := 10;
for y:=1 to 10 do
begin
    if x<20 then
    begin
        for x:=10 to 15 do
        begin
            x :=x+1;
            write(x);
        end;
    end
    else
    begin
        write(x);
        write(y);
    end;
end;
write(100);
end.