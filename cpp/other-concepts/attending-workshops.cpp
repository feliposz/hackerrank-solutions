

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshop {
    int start_time;
    int duration;
    int end_time;    
};

struct Available_Workshops {
    int n;
    Workshop *ws;
};

Available_Workshops* initialize (int start_time[], int duration[], int n)
{
    Available_Workshops *result = new Available_Workshops();
    result->n = n;
    result->ws = new Workshop[n];
    for (int i = 0; i < n; i++) {
        result->ws[i].start_time = start_time[i];
        result->ws[i].duration = duration[i];
        result->ws[i].end_time = start_time[i] + duration[i];
    }
    return result;
}

int cmp(const void *a, const void *b) {
    Workshop *pa = (Workshop *)a;
    Workshop *pb = (Workshop *)b;
    return pa->end_time - pb->end_time;
}

int CalculateMaxWorkshops(Available_Workshops* ptr)
{
    qsort(ptr->ws, ptr->n, sizeof(Workshop), cmp);

    int count = 0;
    int end_time = 0;
    for (int i = 0; i < ptr->n; i++) {
        if (ptr->ws[i].start_time >= end_time) {
            end_time = ptr->ws[i].end_time;
            count++;
        }
    }
    return count;
}


