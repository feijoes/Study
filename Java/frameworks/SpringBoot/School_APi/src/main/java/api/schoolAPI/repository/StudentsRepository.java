package api.schoolAPI.repository;

import api.schoolAPI.model.Student;
import org.springframework.data.mongodb.repository.MongoRepository;

import java.util.Optional;

public interface StudentsRepository extends MongoRepository<Student,Integer> {
    void deleteById(String id);
    Optional<Student> findById(String id);
}
