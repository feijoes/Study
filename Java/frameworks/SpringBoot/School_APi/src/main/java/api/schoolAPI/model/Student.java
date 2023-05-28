package api.schoolAPI.model;

import com.fasterxml.jackson.annotation.JsonProperty;
import lombok.Getter;
import lombok.NonNull;
import lombok.Setter;
import lombok.ToString;
import org.springframework.data.annotation.Id;
import org.springframework.data.mongodb.core.mapping.Document;

import java.util.List;
import java.util.UUID;

@Getter
@Setter
@ToString
@Document(collection = "Students")
public class Student {
    @Id
    private String id;
    private String username;
    private String email;
    private int age;
    private List<String> courses;

    public Student(@JsonProperty("username") String username,@JsonProperty("email") String email, @JsonProperty("age") int age,@JsonProperty("courses") List<String> courses){
        this.courses = courses;
        this.age = age;
        this.email = email;

        this.id = String.valueOf(UUID.randomUUID());
        this.username = username;
    }



}


