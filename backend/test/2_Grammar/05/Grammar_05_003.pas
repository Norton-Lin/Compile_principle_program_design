program Test;
    var id3 : integer; id1 : integer; id2 : integer;
     id4 : boolean; id5 : array[1..20] of integer;
    procedure pr1(id2: integer; id4 : boolean);
    begin
    end;
    function fun1 : char;
    begin
    end;

    begin
        id1 := 1;
        pr1(id1, 1 + 2 > 3);
        begin
        end;
        if 1+2 >= 4 then read(id2, id5[1+1]);
        if  40 + 50 <= 100 then write(0) else write(2);
        for id3 := 0 + 1 to 5 + 5 do id1 := 0;
        while(10 + 20 > 1000) do pr1(id1, 10 > 20)
    end.
