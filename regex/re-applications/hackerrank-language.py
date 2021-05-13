# Enter your code here. Read input from STDIN. Print output to STDOUT
languages = "C:CPP:JAVA:PYTHON:PERL:PHP:RUBY:CSHARP:HASKELL:CLOJURE:BASH:SCALA:ERLANG:CLISP:LUA:BRAINFUCK:JAVASCRIPT:GO:D:OCAML:R:PASCAL:SBCL:DART:GROOVY:OBJECTIVEC".split(":")

n = int(input())

for _ in range(n):
    num, lang = input().split(" ")
    if lang in languages:
        print("VALID")
    else:
        print("INVALID")

