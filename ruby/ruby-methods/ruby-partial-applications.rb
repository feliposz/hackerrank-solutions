def fact(x)
    return 1 if x < 2
    return x * fact(x-1)
end

combination = -> (n) do
    -> (k) do
        return fact(n) / (fact(k) * fact(n - k))
    end
end

n = gets.to_i
r = gets.to_i
nCr = combination.(n)
puts nCr.(r)


