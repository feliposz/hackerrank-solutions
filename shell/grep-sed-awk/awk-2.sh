awk '{printf("%s : %s\n", $1, ($2 >= 50 && $3 >= 50 && $4 >= 50) ? "Pass" : "Fail");}'
