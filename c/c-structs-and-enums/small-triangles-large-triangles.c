

double volume_triangle(float a, float b, float c) {
  double p = (a + b + c) / 2.0;
  double s = sqrt(p * (p - a) * (p - b) * (p - c));
  return s;
}

int cmp_triangle(const void *t1, const void *t2) {
  triangle *tr1 = (triangle *)t1;
  triangle *tr2 = (triangle *)t2;
  double s1 = volume_triangle(tr1->a, tr1->b, tr1->c);
  double s2 = volume_triangle(tr2->a, tr2->b, tr2->c);
  if (s1 < s2)
    return -1;
  if (s1 > s2)
    return 1;
  return 0;
}

void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    qsort(tr, n, sizeof(triangle), cmp_triangle);
    
}


