def mask_article(str, words)
    words.each do |word|
       str = str.gsub(word, strike(word)) 
    end
    return str   
end

def strike(word)
   return "<strike>#{word}</strike>"
end
