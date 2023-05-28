package api.schoolAPI.repository;
import api.schoolAPI.model.Courses;
import org.springframework.data.mongodb.repository.MongoRepository;
public interface CourseRepository extends MongoRepository<Courses,Integer>{
}
