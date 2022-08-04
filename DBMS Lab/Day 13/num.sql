declare
    n   number := &factorial;
    m   number := &square_of_n;
    o   number := &fibonacci_n;
    p   number := &prime_n;
    out number;
    st  boolean;

begin
    dbms_output.put_line('--------------------------');
    out := custom.fact(n);
    dbms_output.put_line('Factorial of ' || n || '!= ' || out);
    out := custom.square(m);
    dbms_output.put_line('Square of ' || m || ' = ' || out);
    out := custom.fibo(o);
    dbms_output.put_line(o || 'th fibonacci number = ' || out);
    st := custom.isPrime(p);
    if (st) then
        dbms_output.put_line(p || ' is Prime');
    else
        dbms_output.put_line(p || ' is not Prime');
    end if;
end;
/

-- Factorial of 4!= 24
-- Square of 5 = 25
-- 11th fibonacci number = 89
-- 17 is Prime

-- Factorial of 10!= 3628800
-- Square of 10 = 100
-- 10th fibonacci number = 55
-- 10 is not Prime