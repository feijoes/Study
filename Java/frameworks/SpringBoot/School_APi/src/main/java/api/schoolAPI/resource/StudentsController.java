package api.schoolAPI.resource;
import api.schoolAPI.model.Courses;
import api.schoolAPI.model.Student;
import api.schoolAPI.repository.CourseRepository;
import api.schoolAPI.repository.StudentsRepository;
import com.fasterxml.jackson.annotation.JsonProperty;
import com.fasterxml.jackson.annotation.JsonValue;
import org.jetbrains.annotations.NotNull;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

@RestController
@RequestMapping(path = "api/students")
public class StudentsController {
    @Autowired
    private StudentsRepository repository;
    @Autowired
    private CourseRepository courseRepository;
    @PostMapping
    public Student createStudent(@RequestBody Student student){
        repository.save(student);
        return student;
    }

    @GetMapping
    public List<Student> getAllStudents(){
            return repository.findAll();
    }
    @GetMapping("{id}")
    public Object getStudent(@PathVariable String id){

        Optional<Student> student;
        student = repository.findById(id);
        if(!student.isPresent()){
            return "No such user with id "+id;
        }
        return student;
    }
    @DeleteMapping("{id}")
    public String deleteStudent(@PathVariable String id){
        repository.deleteById(id);
        return "Student delete";
    }
    @PatchMapping("{id}")
    public String updateStudent(@PathVariable String id, @RequestBody Student newupdateStudent){
        newupdateStudent.setId(id);
        Optional<Student> student = repository.findById(id);
        if (newupdateStudent.getAge() == 0) newupdateStudent.setAge(student.get().getAge());
        if (newupdateStudent.getEmail() == null) newupdateStudent.setEmail(student.get().getEmail());
        if (newupdateStudent.getUsername() == null) newupdateStudent.setUsername(student.get().getUsername());
        if (newupdateStudent.getCourses() == null){
            newupdateStudent.setCourses(student.get().getCourses());
        } else {
            System.out.println(courseRepository.findAll());
            newupdateStudent.setCourses((List<String>)courseRepository.findAll().stream().filter(course -> newupdateStudent.getCourses().contains(course.getName())).map(c->c.getId()).collect(Collectors.toList()));
        }
        repository.save(newupdateStudent);
        return "User update";
    }

}
