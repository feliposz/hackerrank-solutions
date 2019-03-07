
int  sum (int count,...) {
    va_list vl;
    va_start(vl, count);
    int result;
    for (int i = 0; i < count; i++) {
        result += va_arg(vl, int);
    }
    va_end(vl);
    return result;
}

int min(int count,...) {
  if (count <= 0)
    return 0;
  va_list vl;
  va_start(vl, count);
  int result = va_arg(vl, int);
  for (int i = 1; i < count; i++) {
    int num = va_arg(vl, int);
    if (num < result)
      result = num;
  }
  va_end(vl);
  return result;
}

int max(int count,...) {
  if (count <= 0)
    return 0;
  va_list vl;
  va_start(vl, count);
  int result = va_arg(vl, int);
  for (int i = 1; i < count; i++) {
    int num = va_arg(vl, int);
    if (num > result)
      result = num;
  }
  va_end(vl);
  return result;
}


