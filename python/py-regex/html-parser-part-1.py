from html.parser import HTMLParser

class MyHTMLParser(HTMLParser):
    
    def handle_starttag(self, tag, attrs):
        print("Start : " + tag)
        for k, v in attrs:
            print("-> " + k + " > " + str(v))
            
    def handle_endtag(self, tag):
        print("End   : " + tag)
        
    def handle_startendtag(self, tag, attrs):
        print("Empty : " + tag)
        for k, v in attrs:
            print("-> " + k + " > " + str(v))
            
n = int(input())
html = []
for _ in range(n):
    html.append(input())
    
parser = MyHTMLParser()
parser.feed("".join(html))


