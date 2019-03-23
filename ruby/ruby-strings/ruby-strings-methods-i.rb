def process_text(arr)
    arr.map {|s| s.chomp.strip }.join(" ")
end

