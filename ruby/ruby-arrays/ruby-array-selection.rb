def select_arr(arr)
  # select and return all odd numbers from the Array variable `arr`
    return arr.select { |x| x.odd? }
end

def reject_arr(arr)
  # reject all elements which are divisible by 3
    return arr.reject { |x| x % 3 == 0 }
end

def delete_arr(arr)
  # delete all negative elements
    arr.delete_if { |x| x < 0 }
end

def keep_arr(arr)
  # keep all non negative elements ( >= 0)
    arr.keep_if { |x| x >= 0 }
end
