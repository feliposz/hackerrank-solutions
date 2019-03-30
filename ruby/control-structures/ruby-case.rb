
def identify_class(obj)
    case 
    when obj.class == Hacker
        puts "It's a Hacker!"
    when obj.class == Submission
        puts "It's a Submission!"
    when obj.class == TestCase
        puts "It's a TestCase!"
    when obj.class == Contest
        puts "It's a Contest!"
    else
        puts "It's an unknown model"
    end
end
