#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 6

struct package {
  char *id;
  int weight;
};

typedef struct package package;

struct post_office {
  int min_weight;
  int max_weight;
  package *packages;
  int packages_count;
};

typedef struct post_office post_office;

struct town {
  char *name;
  post_office *offices;
  int offices_count;
};

typedef struct town town;

void print_all_packages(town t) {
  printf("%s:\n", t.name);
  for (int i = 0; i < t.offices_count; i++) {
    printf("\t%d:\n", i);
    for (int j = 0; j < t.offices[i].packages_count; j++) {
      printf("\t\t%s\n", t.offices[i].packages[j].id);
    }
  }
}

int count_moveable(post_office *from, post_office *to) {
  int moveable = 0;
  for (int i = 0; i < from->packages_count; i++) {
    if (from->packages[i].weight >= to->min_weight &&
        from->packages[i].weight <= to->max_weight) {
      moveable++;
    }
  }
  return moveable;
}

void resize_office(post_office *o, int diff) {
  o->packages_count += diff;
  o->packages = realloc(o->packages, sizeof(package) * o->packages_count);
}

void move_packages(post_office *from, post_office *to, int position) {
  for (int i = 0; i < from->packages_count; i++) {
    if (from->packages[i].weight >= to->min_weight &&
        from->packages[i].weight <= to->max_weight) {
      to->packages[position++] = from->packages[i];
      from->packages[i].weight = 0; // mark as moved!
    }
  }
}

void prune_empty_packages(post_office *o) {
  int n = o->packages_count;
  for (int i = 0; i < n; i++) {
    while (o->packages[i].weight == 0 && i < n) {
      for (int j = i; j < n - 1; j++) {
        o->packages[j] = o->packages[j + 1];
      }
      n--;
    }
  }
}

void send_all_acceptable_packages(town *source, int source_office_index,
                                  town *target, int target_office_index) {
  int moveable = count_moveable(&source->offices[source_office_index],
                                &target->offices[target_office_index]);
  int last_position = target->offices[target_office_index].packages_count;
  resize_office(&target->offices[target_office_index], moveable);
  move_packages(&source->offices[source_office_index],
                &target->offices[target_office_index], last_position);
  prune_empty_packages(&source->offices[source_office_index]);
  resize_office(&source->offices[source_office_index], -moveable);
}

int count_packages(town *t) {
  int count = 0;
  for (int i = 0; i < t->offices_count; i++) {
    count += t->offices[i].packages_count;
  }
  return count;
}

town town_with_most_packages(town *towns, int towns_count) {
  town t = towns[0];
  int max_count = count_packages(&t);
  for (int i = 1; i < towns_count; i++) {
    int count = count_packages(&towns[i]);
    if (count > max_count) {
      t = towns[i];
      max_count = count;
    }
  }
  return t;
}

town *find_town(town *towns, int towns_count, char *name) {
  for (int i = 0; i < towns_count; i++) {
    if (strcmp(towns[i].name, name) == 0) {
      return &towns[i];
    }
  }
  return NULL;
}

int main() {
  int towns_count;
  scanf("%d", &towns_count);
  town *towns = malloc(sizeof(town) * towns_count);
  for (int i = 0; i < towns_count; i++) {
    towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
    scanf("%s", towns[i].name);
    scanf("%d", &towns[i].offices_count);
    towns[i].offices = malloc(sizeof(post_office) * towns[i].offices_count);
    for (int j = 0; j < towns[i].offices_count; j++) {
      scanf("%d%d%d", &towns[i].offices[j].packages_count,
            &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
      towns[i].offices[j].packages =
          malloc(sizeof(package) * towns[i].offices[j].packages_count);
      for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
        towns[i].offices[j].packages[k].id =
            malloc(sizeof(char) * MAX_STRING_LENGTH);
        scanf("%s", towns[i].offices[j].packages[k].id);
        scanf("%d", &towns[i].offices[j].packages[k].weight);
      }
    }
  }
  int queries;
  scanf("%d", &queries);
  char town_name[MAX_STRING_LENGTH];
  while (queries--) {
    int type;
    scanf("%d", &type);
    switch (type) {
    case 1:
      scanf("%s", town_name);
      town *t = find_town(towns, towns_count, town_name);
      print_all_packages(*t);
      break;
    case 2:
      scanf("%s", town_name);
      town *source = find_town(towns, towns_count, town_name);
      int source_index;
      scanf("%d", &source_index);
      scanf("%s", town_name);
      town *target = find_town(towns, towns_count, town_name);
      int target_index;
      scanf("%d", &target_index);
      send_all_acceptable_packages(source, source_index, target, target_index);
      break;
    case 3:
      printf("Town with the most number of packages is %s\n",
             town_with_most_packages(towns, towns_count).name);
      break;
    }
  }
  return 0;
}

