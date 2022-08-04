declare
    binary number;
    dec    number;

    procedure convert_bin_dec(x in number, y out number) IS
    i number := 0;
    len number := LENGTH(TO_CHAR(x));
    temp   number := x;
    begin
        y := 0;
        while (i < len)
            loop
                y := y + POWER(2,i) * MOD(temp, 10);
                temp := FLOOR(temp / 10);
                i := i + 1;
            end loop;
    end;

begin
    binary := &binary;
    convert_bin_dec(binary, dec);
    DBMS_OUTPUT.PUT_LINE('DECIMAL EQUIVALENT OF ' || binary || ' is ' || dec);
end;
/

-- Enter value for binary: 1011
-- old  20:     binary := &binary;
-- new  20:     binary := 1011;
-- DECIMAL EQUIVALENT OF 1011 is 11

-- Enter value for binary: 10
-- old  20:     binary := &binary;
-- new  20:     binary := 10;
-- DECIMAL EQUIVALENT OF 10 is 2