package api.schoolAPI.resource;
import api.schoolAPI.model.Courses;
import api.schoolAPI.model.Student;
import api.schoolAPI.repository.CourseRepository;
import api.schoolAPI.repository.StudentsRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;
import java.util.Optional;

@RestController
@RequestMapping(path = "api/courses")
public class CoursesController {
    @Autowired
    private CourseRepository repository;
    @PostMapping
    public Courses createStudent(@RequestBody Courses course){
        repository.save(course);
        return course;
    }
}
