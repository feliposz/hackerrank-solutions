def sum_terms(n)
  (1..n).reduce(0) { |result, x| result + x*x + 1 }
end
