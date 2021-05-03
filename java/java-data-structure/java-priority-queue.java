
import java.util.PriorityQueue;
import java.util.Comparator;
/*
 * Create the Student and Priorities classes here.
 */
class Student {
    int id;
    String name;
    double cgpa;
    
    public Student(int id, String name, double cgpa) {
        this.id = id;
        this.name = name;
        this.cgpa = cgpa;    
    }
    
    int getId() { return id; }
    String getName() { return name; }
    double getCGPA() { return cgpa; }
}

class Priorities {
    
    public List<Student> getStudents(List<String> events) {
        PriorityQueue<Student> pq = 
            new PriorityQueue<Student>(1000, new Comparator<Student>() {
                @Override
                public int compare(Student a, Student b) {
                    if (a.getCGPA() == b.getCGPA()) {
                        if (a.getName().equals(b.getName())) {
                            return a.getId() - b.getId();
                        }
                        return a.getName().compareTo(b.getName());
                    }
                    return b.getCGPA() - a.getCGPA() > 0 ? 1 : -1;
                }
            });

        for (String e : events) {
            String[] parts = e.split(" ");
            if (parts[0].equals("ENTER")) {
                Student s = new Student(
                    Integer.parseInt(parts[3]), 
                    parts[1], 
                    Double.parseDouble(parts[2]));
                pq.add(s);
            } else {
                pq.poll();
            }
        }
        List<Student> result = new ArrayList<Student>();
        for (;;) {
            Student s = pq.poll();
            if (s == null) {
                break;    
            }
            result.add(s);
        }
        return result;
    }
}


