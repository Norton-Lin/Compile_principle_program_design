program PascalExample;
const
  message = 'H';
var
  i: integer;
begin
  (* 这是一个块注释 *)
  // 这是一个行注释
  writeln(message);
  for i := 1 to 200 do
    write(i);
end.