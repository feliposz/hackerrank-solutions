require 'prime'

n = gets.to_i

palindromic_primes = -> (size) do 
    1.upto(Float::INFINITY).lazy
        .filter { |x| x.prime? }
        .filter { |x| x.to_s == x.to_s.reverse }
        .first(size)
end

p palindromic_primes.(n)

