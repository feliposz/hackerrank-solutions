# Your code here
def count_multibyte_char(s)
    count = 0
    s.each_codepoint do |codepoint| 
        count += 1 if codepoint > 255
    end
    return count
end
