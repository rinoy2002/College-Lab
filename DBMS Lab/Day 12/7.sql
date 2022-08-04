DECLARE
    num  NUMBER;
    rev  NUMBER;
    temp NUMBER;

    FUNCTION REVERSE(num NUMBER)
        RETURN NUMBER IS
        rev NUMBER;
    BEGIN
        rev := 0;
        temp := num;
        WHILE(temp > 0)
            LOOP
                rev := (rev * 10) + MOD(temp, 10);
                temp := FLOOR(temp / 10);
            END LOOP;
        RETURN rev;
    END;


BEGIN
    num := &num;
    rev := REVERSE(num);
    DBMS_OUTPUT.PUT_LINE('Reverse of the number is: ' || rev);
    IF (rev = num) THEN
        DBMS_OUTPUT.PUT_LINE('The number ' || num || ' is PALINDROME.');
    ELSE
        DBMS_OUTPUT.PUT_LINE('The number ' || num || ' is not PALINDROME.');
    END IF;
END;
/                     


-- Enter value for num: 100001
-- old  22:     num := &num;
-- new  22:     num := 100001;
-- Reverse of the number is: 100001
-- The number 100001 is PALINDROME.


-- Enter value for num: 100010
-- old  22:     num := &num;
-- new  22:     num := 100000;
-- Reverse of the number is: 10001
-- The number 10001 is not PALINDROME.