

char *kth_word_in_mth_sentence_of_nth_paragraph(char ****document, int k, int m,
                                                int n) {
  return document[n - 1][m - 1][k - 1];
}

char **kth_sentence_in_mth_paragraph(char ****document, int k, int m) {
  return document[m - 1][k - 1];
}

char ***kth_paragraph(char ****document, int k) { return document[k - 1]; }

char ****get_document(char *text) {
  char ****doc = NULL;
  int pi = 0;
  while (*text) {
    doc = (char ****)realloc(doc, sizeof(char ***) * (pi + 1));
    int si = 0;
    doc[pi] = NULL;
    while (*text && *text != '\n') {
      doc[pi] = (char ***)realloc(doc[pi], sizeof(char **) * (si + 1));
      int wi = 0;
      doc[pi][si] = NULL;
      while (*text && *text != '\n' && *text != '.') {
        doc[pi][si] = (char **)realloc(doc[pi][si], sizeof(char *) * (wi + 1));
        int ci = 0;
        doc[pi][si][wi] = NULL;
        while (*text && *text != '\n' && *text != '.' && *text != ' ') {
          doc[pi][si][wi] =
              (char *)realloc(doc[pi][si][wi], sizeof(char) * (ci + 2));
          doc[pi][si][wi][ci] = *text;
          ci++;
          text++;
        }
        doc[pi][si][wi][ci] = '\0';
        wi++;
        while (*text == ' ') {
          text++;
        }
      }
      si++;
      while (*text == '.') {
        text++;
      }
    }
    pi++;
    while (*text == '\n') {
      text++;
    }
  }
  return doc;
}

