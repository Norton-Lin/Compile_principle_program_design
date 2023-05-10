program operation (input,output);

procedure procedure3(a:integer;var a0:integer;b:boolean;var b0:boolean;c:char;var c0:char;d:real;var d0:real);
const a1 = 1;b1 = true;c1 = 'c';d1 = 1.1;
var a2:integer;b2:boolean;c2:char;d2:real;
a3:array[0..1] of integer;b3:array[0..1] of boolean;c3:array[0..1] of char;d3:array[0..1] of real;
begin
write(not d);
write(not c);
write(-b);
write(- c);
write(1+5.1);
write(true+1);
write(true-1);
write(true*1);
write(true/1);
write(true+false);
write(true-false);
write(true*false);
write(true/false);
write(10.1 div 6.1);
write(10.1 mod 5.1); 
write(1.1 and 4.4);
write(1.1 or 4.4);
write(c1 and 1);

write(not a);
write(not b);
write(- a);
write(- d);

write(1+1);
write(1-1);
write(1*1);
write(1/1);

write(10 div 6);

write(10 mod 5);

write(true and false);
write(1 and 4);

write(true or false);
write(1 or 4);

write(a <> 1);
write(a0 <> 1);
write(a1 <> 1);
write(a2 <> 1);
write(a3[0]<>1);
write(b <> true);
write(b0 <> true);
write(b1 <> true);
write(b2 <> true);
write(b3[0]<>true);
write(c <> c1);
write(c0 <> c1);
write(c1 <> c1);
write(c2 <> c1);
write(c3[0] <> c1);
write(d <> 1.1);
write(d0 <> 1.1);
write(d1 <> 1.1);
write(d2 <> 1.1);
write(d3[0] <> 1.1);

end;
begin

end.