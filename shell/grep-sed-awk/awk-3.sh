awk '{avg=($2+$3+$4)/3;if(avg<50)g="FAIL";else if(avg<60)g="C";else if(avg<80)g="B";else g="A";printf("%s : %s\n", $0, g);}'

