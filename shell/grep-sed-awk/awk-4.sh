awk '{if(prev){printf("%s;%s\n",prev,$0);prev=0;}else prev=$0;}
END{if(prev)printf("%s;\n",prev);}'

