

int main()
{
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);
    
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);

    total_number_of_books = (int *) calloc(total_number_of_shelves, sizeof(int));
    total_number_of_pages = (int **) calloc(total_number_of_shelves, sizeof(int *));

    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {
            /*
             * Process the query of first type here.
             */
            int x, y;
            scanf("%d %d", &x, &y);
            int pos = total_number_of_books[x];
            total_number_of_books[x]++;
            int new_length = total_number_of_books[x];
            total_number_of_pages[x] = (int *)
                realloc(total_number_of_pages[x], new_length * sizeof(int));
            total_number_of_pages[x][pos] = y;


