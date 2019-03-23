# Your code here
def serial_average(s)
    prefix = s[0,3]
    avg = (s[4,5].to_f + s[10,5].to_f) / 2
    suffix = avg.round(2)
    return "#{prefix}-#{'%02.2f' % suffix}"
end

