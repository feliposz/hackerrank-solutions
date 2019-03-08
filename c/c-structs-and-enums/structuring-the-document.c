

struct document get_document(char *text) {
  struct document doc = {NULL, 0};
  int pi = 0;
  while (*text) {
    int pi = doc.paragraph_count++;
    doc.data = (struct paragraph *)realloc(doc.data, sizeof(struct paragraph) *
                                                         doc.paragraph_count);
    doc.data[pi].data = NULL;
    doc.data[pi].sentence_count = 0;
    while (*text && *text != '\n') {
      int si = doc.data[pi].sentence_count++;
      doc.data[pi].data = (struct sentence *)realloc(
          doc.data[pi].data,
          sizeof(struct sentence) * (doc.data[pi].sentence_count));
      doc.data[pi].data[si].data = NULL;
      doc.data[pi].data[si].word_count = 0;
      while (*text && *text != '\n' && *text != '.') {
        int wi = doc.data[pi].data[si].word_count++;
        doc.data[pi].data[si].data = (struct word *)realloc(
            doc.data[pi].data[si].data,
            sizeof(struct word) * (doc.data[pi].data[si].word_count));
        doc.data[pi].data[si].data[wi].data = NULL;
        int ci = 0;
        while (*text && *text != '\n' && *text != '.' && *text != ' ') {
          doc.data[pi].data[si].data[wi].data = (char *)realloc(
              doc.data[pi].data[si].data[wi].data, sizeof(char) * (ci + 2));
          doc.data[pi].data[si].data[wi].data[ci] = *text;
          ci++;
          text++;
        }
        doc.data[pi].data[si].data[wi].data[ci] = '\0';
        while (*text == ' ') {
          text++;
        }
      }
      while (*text == '.') {
        text++;
      }
    }
    while (*text == '\n') {
      text++;
    }
  }
  return doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc,
                                                      int k, int m, int n) {
  return Doc.data[n - 1].data[m - 1].data[k - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k,
                                              int m) {
  return Doc.data[m - 1].data[k - 1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
  return Doc.data[k - 1];
}

